s.boot;
Server.default.options.inDevice_("Microfono MacBook Pro");

NetAddr("127.0.0.1", 57120);

Quarks.gui;

s.meter;

//Shifter Definition
(
SynthDef.new(\shifterPRO,{
	arg pitchRotary = 1.0, pitchPad = 1.0, formantRotary= 1.0, formantPad = 1.0, timeDispersion = 10.0, outBus =0, amp =1, panPos=0, outAmp = 1, effectBus, delaytime = 0, reverbOut = 0, delayOut = 0, mixDelay = 0, mixReverb=0;
	var pitchshift, sig, in, delay, comp;

	in = SoundIn.ar(0);

	pitchshift = PitchShiftPA.ar(in,
		freq:Pitch.kr(in)[0],
		pitchRatio:pitchRotary*pitchPad,
		formantRatio:formantRotary*formantPad,
		minFreq: 10,
		maxFormantRatio: 10,
		grainsPeriod: 2,
		timeDispersion:timeDispersion);

	//Delay the whole signal
	delay = CombN.ar(pitchshift, delaytime: delaytime, maxdelaytime:0.5, decaytime: 0);

	comp = Limiter.ar(delay, 0.1);

	sig = comp * outAmp*(1-mixDelay)*(1-mixReverb);

	//Panning
	sig = Pan2.ar(comp, panPos, amp);

	//MainOut
	Out.ar([0,1], sig);

	//Reverb
	Out.ar(reverbOut, sig);

    //Delay
    Out.ar(delayOut, sig);

}).add
)

//Reverb Effect Definition
(
SynthDef(\Reverb,{
	arg inBus = 0, mix = 0.0, room= 0.0, damp= 0.0, mul=1.0, add=0.0, outBus = 0, outAmp=1;
	var reverb;
	var input = In.ar(inBus,2);
	reverb = FreeVerb.ar(in:input, mix: 1.0, room: room, damp: damp, mul: mul);

	Out.ar([0,1], reverb*mix*outAmp);

}).add
)

//Delay Effect Definition
(
SynthDef(\Delay,{
	arg inBus = 0, delaytime= 0, decaytime= 0, outAmp = 1, mix =0;
	var delay;
	var input = In.ar(inBus,2);

	delay = CombN.ar(input, delaytime: delaytime, maxdelaytime:0.4, decaytime:decaytime);

	//Diffusion Delay
	delay = FreeVerb.ar(in:delay, mix: 0.1, room: 0.4);

	Out.ar([0,1], delay*mix*outAmp);

}).add
)

//Groups and Busses
(
~reverb_bus = Bus.audio(s,2);
~delay_bus = Bus.audio(s,2);

~source_group = Group.new;

~reverb_group = Group.after(~source_group);

~delay_group = Group.after(~source_group);
)


//START THE HARMONIZER
(
var harm1,harm2, harm3, harm4, reverb, delay, comp;
reverb = Synth.new(\Reverb,[\inBus, ~reverb_bus], ~reverb_group);
delay =  Synth.new(\Delay,[\inBus, ~delay_bus], ~delay_group);


harm1 = Synth(\shifterPRO, [\reverbOut,~reverb_bus, \delayOut,~delay_bus], ~source_group);
harm2 = Synth(\shifterPRO, [\reverbOut,~reverb_bus, \delayOut,~delay_bus], ~source_group);
harm3 = Synth(\shifterPRO, [\reverbOut,~reverb_bus, \delayOut,~delay_bus], ~source_group);
harm4 = Synth(\shifterPRO, [\reverbOut,~reverb_bus, \delayOut,~delay_bus], ~source_group);



//GLOBAL

OSCdef.new('outAmp',
	{arg msg;
		var outAmp;
		outAmp = msg[1];
		outAmp = outAmp.dbamp;
		~source_group.set(\outAmp, outAmp);
		reverb.set(\outAmp, outAmp);
		delay.set(\outAmp, outAmp);
		postln(outAmp);

},
	"/juce/out_volume"
);

OSCdef.new('pitchPad',
	{arg msg;
		var pitchPad;
		pitchPad = msg[1];
		~source_group.set(\pitchPad, pitchPad);
		postln(pitchPad);

},
	"/juce/trackpad_x"
);

OSCdef.new('formantPad',
	{arg msg;
		var formantPad;
		formantPad = msg[1];
		~source_group.set(\formantPad, formantPad);
		postln(formantPad);



},
	"/juce/trackpad_y"
);


////REVERB////
OSCdef.new('reverbmix',
	{arg msg;
		var mix;
		mix = msg[1];
		reverb.set(\mix, mix);
		~source_group.set(\mixReverb, mix);
		postln(mix);
},
	"/juce/rev_DW"
);

OSCdef.new('room',
	{arg msg;
		var room;
		room = msg[1];
		reverb.set(\room, room);
		postln(room);

},
	"/juce/rev_room"
);

OSCdef.new('damping',
	{arg msg;
		var damp;
		damp = msg[1];
		reverb.set(\damp, damp);
		postln(damp);

},
	"/juce/rev_damp"
);



////DELAY////
OSCdef.new('time',
	{arg msg;
		var time;
		time = msg[1];
		delay.set(\delaytime, time*0.001);
		postln(time);

},
	"/juce/delay_time"
);

OSCdef.new('decay',
	{arg msg;
		var decay;
		decay = msg[1];
		delay.set(\decaytime, decay);
		postln(decay);

},
	"/juce/delay_decay"
);

OSCdef.new('delaymix',
	{arg msg;
		var mix;
		mix = msg[1];
		delay.set(\mix, mix);
		~source_group.set(\mixDelay, mix);
		postln(mix);

},
	"/juce/delay_mix"
);




//FIRST HARMONIC
OSCdef.new('harm1_shift',
	{arg msg;
		var pitchratio;
		pitchratio = msg[1];
		pitchratio = 2**(pitchratio/12);
		harm1.set(\pitchRotary, pitchratio);
		harm1.set(\formantRotary, pitchratio);
		postln(pitchratio);

},
	"/juce/harm1_shift"

);
OSCdef.new('harm1_delay',
	{arg msg;
		var delaytime;
		delaytime = msg[1];
		harm1.set(\delaytime, delaytime*0.001);
		postln(delaytime);

},
	"/juce/harm1_delay"

);
OSCdef.new('harm1_volume',
	{arg msg;
		var volume;
		volume = msg[1];
		volume = volume.dbamp;
		harm1.set(\amp, volume);
		postln(volume);

},
	"/juce/harm1_volume"

);

OSCdef.new('harm1_enable',
	{arg msg;
		var enable;
		enable = msg[1];
		harm1.set(\amp, enable);
		postln(enable);

},
	"/juce/harm1_enable"
);


OSCdef.new('harm1_pan',
	{arg msg;
		var panPos;
		panPos = msg[1];
		harm1.set(\panPos, panPos);
		postln(panPos);

},
	"/juce/harm1_pan"
);








//////////////////////////////////////////////////////////////////////////////////////////////

//SECOND HARMONIC
OSCdef.new('harm2_shift',
	{arg msg;
		var pitchratio;
		pitchratio = msg[1];
		pitchratio = 2**(pitchratio/12);
		harm2.set(\pitchRotary, pitchratio);
		harm2.set(\formantRotary, pitchratio);
		postln(pitchratio);

},
	"/juce/harm2_shift"

);
OSCdef.new('harm2_delay',
	{arg msg;
		var delaytime;
		delaytime = msg[1];
		harm2.set(\delaytime, delaytime*0.001);
		postln(delaytime);

},
	"/juce/harm2_delay"

);
OSCdef.new('harm2_volume',
	{arg msg;
		var volume;
		volume = msg[1];
		volume = volume.dbamp;
		harm2.set(\amp, volume);
		postln(volume);

},
	"/juce/harm2_volume"

);

OSCdef.new('harm2_enable',
	{arg msg;
		var enable;
		enable = msg[1];
		harm2.set(\amp, enable);
		postln(enable);

},
	"/juce/harm2_enable"
);


OSCdef.new('harm2_pan',
	{arg msg;
		var panPos;
		panPos = msg[1];
		harm2.set(\panPos, panPos);
		postln(panPos);

},
	"/juce/harm2_pan"
);



/////////////////////////////////////////////////////////////////

//THIRD HARMONIC
OSCdef.new('harm3_shift',
	{arg msg;
		var pitchratio;
		pitchratio = msg[1];
		pitchratio = 2**(pitchratio/12);
		harm3.set(\pitchRotary, pitchratio);
		harm3.set(\formantRotary, pitchratio);
		postln(pitchratio);

},
	"/juce/harm3_shift"

);
OSCdef.new('harm3_delay',
	{arg msg;
		var delaytime;
		delaytime = msg[1];
		harm3.set(\delaytime, delaytime*0.001);
		postln(delaytime);

},
	"/juce/harm3_delay"

);
OSCdef.new('harm3_volume',
	{arg msg;
		var volume;
		volume = msg[1];
		volume = volume.dbamp;
		harm3.set(\amp, volume);
		postln(volume);

},
	"/juce/harm3_volume"

);

OSCdef.new('harm3_enable',
	{arg msg;
		var enable;
		enable = msg[1];
		harm3.set(\amp, enable);
		postln(enable);

},
	"/juce/harm3_enable"
);

OSCdef.new('harm3_pan',
	{arg msg;
		var panPos;
		panPos = msg[1];
		harm3.set(\panPos, panPos);
		postln(panPos);

},
	"/juce/harm3_pan"
);

////////////////////////////////////////////////////////////////////////

//FOURTH HARMONIC
OSCdef.new('harm4_shift',
	{arg msg;
		var pitchratio;
		pitchratio = msg[1];
		pitchratio = 2**(pitchratio/12);
		harm4.set(\pitchRotary, pitchratio);
		harm4.set(\formantRotary, pitchratio);
		postln(pitchratio);

},
	"/juce/harm4_shift"

);
OSCdef.new('harm4_delay',
	{arg msg;
		var delaytime;
		delaytime = msg[1];
		harm4.set(\delaytime, delaytime*0.001);
		postln(delaytime);

},
	"/juce/harm4_delay"

);
OSCdef.new('harm4_volume',
	{arg msg;
		var volume;
		volume = msg[1];
		volume = volume.dbamp;
		harm4.set(\amp, volume);
		postln(volume);

},
	"/juce/harm4_volume"

);

OSCdef.new('harm4_enable',
	{arg msg;
		var enable;
		enable = msg[1];
		harm4.set(\amp, enable);
		postln(enable);

},
	"/juce/harm4_enable"
);

OSCdef.new('harm4_pan',
	{arg msg;
		var panPos;
		panPos = msg[1];
		harm4.set(\panPos, panPos);
		postln(panPos);

},
	"/juce/harm4_pan"
);

)