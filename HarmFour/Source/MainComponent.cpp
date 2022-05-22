#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //Scalable Interface
    double ratio = 5.0 / 3.0;
    setSize(900, 900 / ratio);
    
    //INPUT VOLUME
    in_volume.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    in_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    in_volume.setRange(-12.0, 3.0, 0.1);
    in_volume.setTextValueSuffix(" dB");
    addAndMakeVisible(in_volume);
    in_volume.getProperties().set ("gain", true);
    in_volume.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/in_volume", (float) in_volume.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    in_label.setText("INPUT VOLUME", juce::dontSendNotification);
    addAndMakeVisible(in_label);
    
    //OUTPUT VOLUME
    out_volume.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    out_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    out_volume.setRange(-12.0, 3.0, 0.1);
    out_volume.setTextValueSuffix(" dB");
    addAndMakeVisible(out_volume);
    out_volume.getProperties().set ("gain", true);
    out_volume.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/out_volume", (float) out_volume.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    out_label.setText("MASTER OUTPUT", juce::dontSendNotification);
    addAndMakeVisible(out_label);
    
    //HARMONIZER VOLUME 1
    harm1_volume.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical );
    //harm1_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    harm1_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm1_volume.setRange(-12.0, 3.0, 0.1);
    harm1_volume.setTextValueSuffix(" dB");
    addAndMakeVisible(harm1_volume);
    harm1_volume.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm1_volume", (float) harm1_volume.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER VOLUME 2
    harm2_volume.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical );
    //harm2_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    harm2_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm2_volume.setRange(-12.0, 3.0, 0.1);
    harm2_volume.setTextValueSuffix(" dB");
    addAndMakeVisible(harm2_volume);
    harm2_volume.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm2_volume", (float) harm2_volume.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER VOLUME 3
    harm3_volume.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical );
    //harm3_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    harm3_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm3_volume.setRange(-12.0, 3.0, 0.1);
    harm3_volume.setTextValueSuffix(" dB");
    addAndMakeVisible(harm3_volume);
    harm3_volume.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm3_volume", (float) harm3_volume.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER VOLUME 4
    harm4_volume.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical );
    //harm4_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    harm4_volume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm4_volume.setRange(-12.0, 3.0, 0.1);
    harm4_volume.setTextValueSuffix(" dB");
    addAndMakeVisible(harm4_volume);
    harm4_volume.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm4_volume", (float) harm4_volume.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PAN 1
    harm1_pan.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    harm1_pan.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm1_pan.setRange(-1.0, 1.0, 0.5);
    addAndMakeVisible(harm1_pan);
    harm1_pan.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm1_pan", (float) harm1_pan.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PAN 2
    harm2_pan.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    harm2_pan.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm2_pan.setRange(-1.0, 1.0, 0.5);
    addAndMakeVisible(harm2_pan);
    harm2_pan.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm2_pan", (float) harm2_pan.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PAN 3
    harm3_pan.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    harm3_pan.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm3_pan.setRange(-1.0, 1.0, 0.5);
    addAndMakeVisible(harm3_pan);
    harm3_pan.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm3_pan", (float) harm3_pan.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PAN 4
    harm4_pan.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    harm4_pan.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm4_pan.setRange(-1.0, 1.0, 0.5);
    addAndMakeVisible(harm4_pan);
    harm4_pan.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm4_pan", (float) harm4_pan.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER DELAY 1
    harm1_delay.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm1_delay.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm1_delay.setRange(0, 500, 1);
    harm1_delay.getProperties().set ("milliseconds", true);
    addAndMakeVisible(harm1_delay);
    harm1_delay.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm1_delay", (float) harm1_delay.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER DELAY 2
    harm2_delay.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm2_delay.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm2_delay.setRange(0, 500, 1);
    harm2_delay.getProperties().set ("milliseconds", true);
    addAndMakeVisible(harm2_delay);
    harm2_delay.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm2_delay", (float) harm2_delay.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER DELAY 3
    harm3_delay.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm3_delay.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm3_delay.setRange(0, 500, 1);
    harm3_delay.getProperties().set ("milliseconds", true);
    addAndMakeVisible(harm3_delay);
    harm3_delay.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm3_delay", (float) harm3_delay.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER DELAY 4
    harm4_delay.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm4_delay.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm4_delay.setRange(0, 500, 1);
    harm4_delay.getProperties().set ("milliseconds", true);
    addAndMakeVisible(harm4_delay);
    harm4_delay.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm4_delay", (float) harm4_delay.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PITCH SHIFTER 1
    harm1_shift.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm1_shift.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm1_shift.setRange(-12, 12, 1);
    addAndMakeVisible(harm1_shift);
    harm1_shift.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm1_shift", (float) harm1_shift.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PITCH SHIFTER 2
    harm2_shift.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm2_shift.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm2_shift.setRange(-12, 12, 1);
    addAndMakeVisible(harm2_shift);
    harm2_shift.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm2_shift", (float) harm2_shift.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PITCH SHIFTER 3
    harm3_shift.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm3_shift.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm3_shift.setRange(-12, 12, 1);
    addAndMakeVisible(harm3_shift);
    harm3_shift.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm3_shift", (float) harm3_shift.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //HARMONIZER PITCH SHIFTER 4
    harm4_shift.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    harm4_shift.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    harm4_shift.setRange(-12, 12, 1);
    addAndMakeVisible(harm4_shift);
    harm4_shift.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/harm4_shift", (float) harm4_shift.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    ///HARMONIZER TOGGLE BUTTON 1
    harm1_enable.setColour(juce::TextButton::buttonOnColourId, juce::Colours::orangered);
    harm1_enable.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    harm1_enable.setClickingTogglesState(true);
    addAndMakeVisible(harm1_enable);
    harm1_enable.onClick = [this]
    {
        if (harm1_enable.getToggleState()) {
            if (!sender.send("/juce/harm1_enable", 0)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }
        else {
            if (!sender.send("/juce/harm1_enable", 1)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }

    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    
    ///HARMONIZER TOGGLE BUTTON 2
    harm2_enable.setColour(juce::TextButton::buttonOnColourId, juce::Colours::orangered);
    harm2_enable.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    harm2_enable.setClickingTogglesState(true);
    addAndMakeVisible(harm2_enable);
    harm2_enable.onClick = [this]
    {
        if (harm2_enable.getToggleState()) {
            if (!sender.send("/juce/harm2_enable", 0)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }
        else {
            if (!sender.send("/juce/harm2_enable", 1)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }

    };

    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    ///HARMONIZER TOGGLE BUTTON 3
    harm3_enable.setColour(juce::TextButton::buttonOnColourId, juce::Colours::orangered);
    harm3_enable.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    harm3_enable.setClickingTogglesState(true);
    addAndMakeVisible(harm3_enable);
    harm3_enable.onClick = [this]
    {
        if (harm3_enable.getToggleState()) {
            if (!sender.send("/juce/harm3_enable", 0)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }
        else {
            if (!sender.send("/juce/harm3_enable", 1)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }

    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    ///HARMONIZER TOGGLE BUTTON 4
    harm4_enable.setColour(juce::TextButton::buttonOnColourId, juce::Colours::orangered);
    harm4_enable.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    harm4_enable.setClickingTogglesState(true);
    addAndMakeVisible(harm4_enable);
    harm4_enable.onClick = [this]
    {
        if (harm4_enable.getToggleState()) {
            if (!sender.send("/juce/harm4_enable", 0)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }
        else {
            if (!sender.send("/juce/harm4_enable", 1)) {
                showConnectionErrorMessage("Error: could not send OSC message.");
            }
        }

    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //REVERB - MIX
    reverb1.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    reverb1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    reverb1.setRange(0, 1, 0.01);
    reverb1.getProperties().set ("percentage", true);
    addAndMakeVisible(reverb1);
    reverb1.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/rev_DW", (float) reverb1.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //REVERB - ROOM SIZE
    reverb2.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    reverb2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    reverb2.setRange(0, 1, 0.01);
    reverb2.getProperties().set ("percentage", true);
    addAndMakeVisible(reverb2);
    reverb2.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/rev_room", (float) reverb2.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //REVERB - HF DAMP
    reverb3.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    reverb3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    reverb3.setRange(0, 1, 0.01);
    reverb3.getProperties().set ("percentage", true);
    addAndMakeVisible(reverb3);
    reverb3.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/rev_damp", (float) reverb3.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //DELAY - MIX
    delay1.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    delay1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    delay1.setRange(0, 1, 0.01);
    delay1.getProperties().set ("percentage", true);
    addAndMakeVisible(delay1);
    delay1.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/delay_mix", (float) delay1.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //DELAY - TIME
    delay2.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    delay2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    delay2.setRange(0, 400, 1);
    delay2.getProperties().set ("milliseconds", true);
    addAndMakeVisible(delay2);
    delay2.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/delay_time", (float) delay2.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");
    
    //DELAY - DECAY
    delay3.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    delay3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    delay3.setRange(0, 4, 0.1);
    delay3.getProperties().set ("seconds", true);
    addAndMakeVisible(delay3);
    delay3.onValueChange = [this]
    {
        // create and send an OSC message with an address and a float value:
        if (! sender.send ("/juce/delay_decay", (float) delay3.getValue()))
            showConnectionErrorMessage ("Error: could not send OSC message.");
    };
    // specify here where to send OSC messages to: host URL and UDP port number
    if (! sender.connect ("127.0.0.1",57120))
        showConnectionErrorMessage ("Error: could not connect to UDP port 57120.");


    //RANDOM BUTTON
    arpeggios.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    arpeggios.setClickingTogglesState(false);
    addAndMakeVisible(arpeggios);
    arpeggios.onClick = [this]
    {
        harm1_delay.setValue(0, juce::sendNotification);
        harm2_delay.setValue(std::rand() % 50 + 100, juce::sendNotification);
        harm3_delay.setValue(std::rand() % 50 + 300, juce::sendNotification);
        harm4_delay.setValue(std::rand() % 50 + 460, juce::sendNotification);

        harm1_shift.setValue(0, juce::sendNotification);
        harm2_shift.setValue(std::rand()%4 +2, juce::sendNotification);
        harm3_shift.setValue(std::rand() %3 + 6, juce::sendNotification);
        harm4_shift.setValue(std::rand() %2 + 8, juce::sendNotification);

        arpeggios.setColour(juce::TextButton::buttonColourId, juce::Colour(std::rand()%255, std::rand() % 255, std::rand() % 255));
        wallofvoice.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    };

    reset_arp.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    reset_arp.setClickingTogglesState(false);
    addAndMakeVisible(reset_arp);
    reset_arp.onClick = [this]
    {
        harm1_delay.setValue(0, juce::sendNotification);
        harm2_delay.setValue(0, juce::sendNotification);
        harm3_delay.setValue(0, juce::sendNotification);
        harm4_delay.setValue(0, juce::sendNotification);

        harm1_shift.setValue(0, juce::sendNotification);
        harm2_shift.setValue(0, juce::sendNotification);
        harm3_shift.setValue(0, juce::sendNotification);
        harm4_shift.setValue(0, juce::sendNotification);
        arpeggios.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
        wallofvoice.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
        
    };

    wallofvoice.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
    wallofvoice.setClickingTogglesState(false);
    addAndMakeVisible(wallofvoice);
    wallofvoice.onClick = [this]
    {
        harm1_delay.setValue(0, juce::sendNotification);
        harm2_delay.setValue(20, juce::sendNotification);
        harm3_delay.setValue(30, juce::sendNotification);
        harm4_delay.setValue(45, juce::sendNotification);

        harm1_shift.setValue(0, juce::sendNotification);
        harm2_shift.setValue(1, juce::sendNotification);
        harm3_shift.setValue(-1, juce::sendNotification);
        harm4_shift.setValue(5, juce::sendNotification);
        arpeggios.setColour(juce::TextButton::buttonColourId, juce::Colour(32, 32, 32));
        wallofvoice.setColour(juce::TextButton::buttonColourId, juce::Colours::darkorange);
    };


    // specify here on which UDP port number to receive incoming OSC messages
    if (!connect(57122))                       // [3]
        showConnectionErrorMessage("Error: could not connect to UDP port 57122.");

    // tell the component to listen for OSC messages matching this address:
    addListener(this, "/syntien/basic/2/2dslider1");
     
    ////LABELS
    //HARMONIZER MUTE LABEL
    h_label1.setText("MUTE", juce::dontSendNotification);
    h_label1.getProperties().set ("vertical", true);
    addAndMakeVisible(h_label1);
    //HARMONIZER SHIFT LABEL
    h_label2.setText("SHIFT", juce::dontSendNotification);
    h_label2.getProperties().set ("vertical", true);
    addAndMakeVisible(h_label2);
    //HARMONIZER SHIFT VOLUMES LABEL
    h_label3.setText("VOLUME", juce::dontSendNotification);
    h_label3.getProperties().set ("vertical", true);
    addAndMakeVisible(h_label3);
    //HARMONIZER PAN LABEL
    h_label4.setText("PAN", juce::dontSendNotification);
    h_label4.getProperties().set ("vertical", true);
    addAndMakeVisible(h_label4);
    //HARMONIZER DELAY LABEL
    h_label5.setText("DELAY\nTIME", juce::dontSendNotification);
    h_label5.getProperties().set ("vertical", true);
    addAndMakeVisible(h_label5);
    //REVERB
    reverb_label.setText("REVERB", juce::dontSendNotification);
    addAndMakeVisible(reverb_label);
    rev1_label.setText("MIX", juce::dontSendNotification);
    addAndMakeVisible(rev1_label);
    rev2_label.setText("ROOM", juce::dontSendNotification);
    addAndMakeVisible(rev2_label);
    rev3_label.setText("HF DAMP", juce::dontSendNotification);
    addAndMakeVisible(rev3_label);
    //DELAY
    delay_label.setText("DELAY", juce::dontSendNotification);
    addAndMakeVisible(delay_label);
    del1_label.setText("MIX", juce::dontSendNotification);
    addAndMakeVisible(del1_label);
    del2_label.setText("TIME", juce::dontSendNotification);
    addAndMakeVisible(del2_label);
    del3_label.setText("DECAY", juce::dontSendNotification);
    addAndMakeVisible(del3_label);
    //PRESETS
    random_label.setText("ARPEGGIOS", juce::dontSendNotification);
    addAndMakeVisible(random_label);
    preset_label.setText("SPACER", juce::dontSendNotification);
    addAndMakeVisible(preset_label);
    reset_label.setText("RESET", juce::dontSendNotification);
    addAndMakeVisible(reset_label);
    //COLORS
    auto color1 = juce::Colours::aquamarine;
    harm1_pan.setColour (juce::Slider::thumbColourId, color1);
    harm1_delay.setColour (juce::Slider::rotarySliderFillColourId, color1);
    harm1_shift.setColour (juce::Slider::rotarySliderFillColourId, color1);
    harm1_volume.setColour (juce::Slider::rotarySliderFillColourId, color1);
    
    auto color2 = juce::Colours::aqua;
    harm2_pan.setColour (juce::Slider::thumbColourId, color2);
    harm2_delay.setColour (juce::Slider::rotarySliderFillColourId, color2);
    harm2_shift.setColour (juce::Slider::rotarySliderFillColourId, color2);
    harm2_volume.setColour (juce::Slider::rotarySliderFillColourId, color2);
    
    auto color3 = juce::Colours::azure;
    harm3_pan.setColour (juce::Slider::thumbColourId, color3);
    harm3_delay.setColour (juce::Slider::rotarySliderFillColourId, color3);
    harm3_shift.setColour (juce::Slider::rotarySliderFillColourId, color3);
    harm3_volume.setColour (juce::Slider::rotarySliderFillColourId, color3);
    
    auto color4 = juce::Colours::coral;
    harm4_pan.setColour (juce::Slider::thumbColourId, color4);
    harm4_delay.setColour (juce::Slider::rotarySliderFillColourId, color4);
    harm4_shift.setColour (juce::Slider::rotarySliderFillColourId, color4);
    harm4_volume.setColour (juce::Slider::rotarySliderFillColourId, color4);
    
    auto color5 = juce::Colours::yellowgreen;
    reverb1.setColour (juce::Slider::rotarySliderFillColourId, color5);
    reverb2.setColour (juce::Slider::rotarySliderFillColourId, color5);
    reverb3.setColour (juce::Slider::rotarySliderFillColourId, color5);
    
    auto color6 = juce::Colours::plum;
    delay1.setColour (juce::Slider::rotarySliderFillColourId, color6);
    delay2.setColour (juce::Slider::rotarySliderFillColourId, color6);
    delay3.setColour (juce::Slider::rotarySliderFillColourId, color6);
    
    //TRACKPAD
    addAndMakeVisible (trackpad);
    track1_label.setText("PITCH", juce::dontSendNotification);
    track1_label.getProperties().set ("vertical", true);
    addAndMakeVisible(track1_label);
    track2_label.setText("FORMANTS PITCH", juce::dontSendNotification);
    addAndMakeVisible(track2_label);
    
    //LOOKS
    harm1_enable.setLookAndFeel(&customLookAndFeel);
    harm1_delay.setLookAndFeel(&customLookAndFeel);
    harm1_shift.setLookAndFeel(&customLookAndFeel);
    harm1_volume.setLookAndFeel(&sliderLookAndFeel);
    
    harm2_enable.setLookAndFeel(&customLookAndFeel);
    harm2_delay.setLookAndFeel(&customLookAndFeel);
    harm2_shift.setLookAndFeel(&customLookAndFeel);
    harm2_volume.setLookAndFeel(&sliderLookAndFeel);

    harm3_enable.setLookAndFeel(&customLookAndFeel);
    harm3_delay.setLookAndFeel(&customLookAndFeel);
    harm3_shift.setLookAndFeel(&customLookAndFeel);
    harm3_volume.setLookAndFeel(&sliderLookAndFeel);

    harm4_enable.setLookAndFeel(&customLookAndFeel);
    harm4_delay.setLookAndFeel(&customLookAndFeel);
    harm4_shift.setLookAndFeel(&customLookAndFeel);
    harm4_volume.setLookAndFeel(&sliderLookAndFeel);

    in_volume.setLookAndFeel(&customLookAndFeel);
    in_label.setLookAndFeel(&customLookAndFeel);
    out_volume.setLookAndFeel(&customLookAndFeel);
    out_label.setLookAndFeel(&customLookAndFeel);
    
    reverb1.setLookAndFeel(&customLookAndFeel);
    reverb2.setLookAndFeel(&customLookAndFeel);
    reverb3.setLookAndFeel(&customLookAndFeel);
    reverb_label.setLookAndFeel(&customLookAndFeel);
    rev1_label.setLookAndFeel(&customLookAndFeel);
    rev2_label.setLookAndFeel(&customLookAndFeel);
    rev3_label.setLookAndFeel(&customLookAndFeel);
    
    delay1.setLookAndFeel(&customLookAndFeel);
    delay2.setLookAndFeel(&customLookAndFeel);
    delay3.setLookAndFeel(&customLookAndFeel);
    delay_label.setLookAndFeel(&customLookAndFeel);
    del1_label.setLookAndFeel(&customLookAndFeel);
    del2_label.setLookAndFeel(&customLookAndFeel);
    del3_label.setLookAndFeel(&customLookAndFeel);

    h_label1.setLookAndFeel(&customLookAndFeel);
    h_label2.setLookAndFeel(&customLookAndFeel);
    h_label3.setLookAndFeel(&customLookAndFeel);
    h_label4.setLookAndFeel(&customLookAndFeel);
    h_label5.setLookAndFeel(&customLookAndFeel);
    
    track1_label.setLookAndFeel(&customLookAndFeel);
    track2_label.setLookAndFeel(&customLookAndFeel);

    arpeggios.setLookAndFeel(&customLookAndFeel);
    random_label.setLookAndFeel(&customLookAndFeel);

    reset_arp.setLookAndFeel(&customLookAndFeel);
    reset_label.setLookAndFeel(&customLookAndFeel);

    wallofvoice.setLookAndFeel(&customLookAndFeel);
    preset_label.setLookAndFeel(&customLookAndFeel);

}

MainComponent::~MainComponent()
{
    harm1_enable.setLookAndFeel(nullptr);
    harm1_delay.setLookAndFeel(nullptr);
    harm1_shift.setLookAndFeel(nullptr);
    harm1_volume.setLookAndFeel(nullptr);

    harm2_enable.setLookAndFeel(nullptr);
    harm2_delay.setLookAndFeel(nullptr);
    harm2_shift.setLookAndFeel(nullptr);
    harm2_volume.setLookAndFeel(nullptr);

    harm3_enable.setLookAndFeel(nullptr);
    harm3_delay.setLookAndFeel(nullptr);
    harm3_shift.setLookAndFeel(nullptr);
    harm3_volume.setLookAndFeel(nullptr);

    harm4_enable.setLookAndFeel(nullptr);
    harm4_delay.setLookAndFeel(nullptr);
    harm4_shift.setLookAndFeel(nullptr);
    harm4_volume.setLookAndFeel(nullptr);

    in_volume.setLookAndFeel(nullptr);
    out_volume.setLookAndFeel(nullptr);
    in_label.setLookAndFeel(nullptr);
    out_label.setLookAndFeel(nullptr);
    
    reverb1.setLookAndFeel(nullptr);
    reverb2.setLookAndFeel(nullptr);
    reverb3.setLookAndFeel(nullptr);
    reverb_label.setLookAndFeel(nullptr);
    rev1_label.setLookAndFeel(nullptr);
    rev2_label.setLookAndFeel(nullptr);
    rev3_label.setLookAndFeel(nullptr);
    
    delay1.setLookAndFeel(nullptr);
    delay2.setLookAndFeel(nullptr);
    delay3.setLookAndFeel(nullptr);
    delay_label.setLookAndFeel(nullptr);
    del1_label.setLookAndFeel(nullptr);
    del2_label.setLookAndFeel(nullptr);
    del3_label.setLookAndFeel(nullptr);
    
    track1_label.setLookAndFeel(nullptr);
    track2_label.setLookAndFeel(nullptr);
    
    h_label1.setLookAndFeel(nullptr);
    h_label2.setLookAndFeel(nullptr);
    h_label3.setLookAndFeel(nullptr);
    h_label4.setLookAndFeel(nullptr);
    h_label5.setLookAndFeel(nullptr);

    arpeggios.setLookAndFeel(nullptr);
    random_label.setLookAndFeel(nullptr);

    reset_arp.setLookAndFeel(nullptr);
    reset_label.setLookAndFeel(nullptr);

    wallofvoice.setLookAndFeel(nullptr);
    preset_label.setLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colour(60,60,60));
}

void MainComponent::resized()
{
    //Get the dimension of the window
    auto width = getWidth();
    auto height = getHeight();
    auto centerX = width / 2;
    auto centerY = height / 2;
    // Input/Output knob diameter
    const float gainDiam = width * 0.10;
    // Harmonizer volume sliders dimensions
    const float slider_w = width * 0.06;
    const float slider_h = height * 0.5;
    // Pan
    const float sPan = width *0.07;
    // Shift knobs
    const float diam = width * 0.05;
    //Delay knobs
    const float dDiam = width * 0.05;
    //Trackpad
    const float trackWidth = width/3;
    const float trackHeight = height/3;
    
    // Buttons
    const float buttSize = width * 0.03;
    //Labels
    float textBoxWidth = width / 7;
    float textBoxHeight = textBoxWidth / 5;
    const float fontscaler = width / 59;
    
    //TRACKPAD
    trackpad.setBounds (centerX - trackWidth/2 + width/4, centerY - trackHeight/2 + height/4, trackWidth, trackHeight);
    track2_label.setBounds(centerX - textBoxWidth / 2 + width/4, centerY - textBoxHeight/2 + height*0.45 , textBoxWidth, textBoxHeight);
    track2_label.setFont(juce::Font(fontscaler, juce::Font::bold));
    track2_label.setJustificationType(20);
    
    //INPUT VOLUME
    /*in_volume.setBounds(centerX - gainDiam / 2 - width / 2.5, centerY - gainDiam/2 - height * 0.33 , gainDiam, gainDiam);
    in_label.setBounds(centerX - textBoxWidth / 2 - width / 2.5, centerY - textBoxHeight/2 - height * 0.45 , textBoxWidth, textBoxHeight);
    in_label.setFont(juce::Font(fontscaler, juce::Font::bold));
    in_label.setJustificationType(12);*/
    
    //OUTPUT VOLUME
    out_volume.setBounds(centerX - gainDiam / 2 + width / 2.5, centerY - gainDiam/2 - height*0.33 , gainDiam, gainDiam);
    out_label.setBounds(centerX - textBoxWidth / 2 + width / 2.5, centerY - textBoxHeight/2 - height * 0.45 , textBoxWidth, textBoxHeight);
    out_label.setFont(juce::Font(fontscaler, juce::Font::bold));
    out_label.setJustificationType(12);
    
    //HARMONIZER VOLUMES
    harm1_volume.setBounds(centerX - slider_w / 2/3 - width / 2 + width * 0.1, centerY - slider_h/2 - height * 0.16 , slider_w, slider_h);
    harm2_volume.setBounds(centerX - slider_w / 2/3 - width / 2 + width * 0.2, centerY - slider_h/2 - height * 0.16 , slider_w, slider_h);
    harm3_volume.setBounds(centerX - slider_w / 2/3 - width / 2 + width * 0.3, centerY - slider_h/2 - height * 0.16 , slider_w, slider_h);
    harm4_volume.setBounds(centerX - slider_w / 2/3 - width / 2 + width * 0.4, centerY - slider_h/2 - height * 0.16 , slider_w, slider_h);
    
    //HARMONIZER PANS
    harm1_pan.setBounds(centerX - slider_w / 2 - width / 2 + width * 0.1, centerY - slider_h/2/5 + height * 0.11 , slider_w, slider_h/5);
    harm2_pan.setBounds(centerX - slider_w / 2 - width / 2 + width * 0.2, centerY - slider_h/2/5 + height * 0.11 , slider_w, slider_h/5);
    harm3_pan.setBounds(centerX - slider_w / 2 - width / 2 + width * 0.3, centerY - slider_h/2/5 + height * 0.11 , slider_w, slider_h/5);
    harm4_pan.setBounds(centerX - slider_w / 2 - width / 2 + width * 0.4, centerY - slider_h/2/5 + height * 0.11 , slider_w, slider_h/5);
    
    //HARMONIZER DELAYS
    harm1_delay.setBounds(centerX - diam / 2 - width / 2 + width * 0.1, centerY - diam/2 + height * 0.21 , diam, diam);
    harm2_delay.setBounds(centerX - diam / 2 - width / 2 + width * 0.2, centerY - diam/2 + height * 0.21 , diam, diam);
    harm3_delay.setBounds(centerX - diam / 2 - width / 2 + width * 0.3, centerY - diam/2 + height * 0.21 , diam, diam);
    harm4_delay.setBounds(centerX - diam / 2 - width / 2 + width * 0.4, centerY - diam/2 + height * 0.21 , diam, diam);
 
    //PRESETS
    arpeggios.setBounds(centerX - buttSize / 2, centerY - diam / 2 + height * 0.2, buttSize, buttSize);
    random_label.setBounds(centerX - textBoxWidth / 2, centerY - textBoxHeight / 2 + height * 0.15, textBoxWidth, textBoxHeight);
    random_label.setFont(juce::Font(fontscaler*0.7, juce::Font::bold));
    random_label.setJustificationType(12);
    wallofvoice.setBounds(centerX - buttSize / 2, centerY - diam / 2 + height * 0.30, buttSize, buttSize);
    preset_label.setBounds(centerX - textBoxWidth / 2, centerY - textBoxHeight / 2 + height * 0.25, textBoxWidth, textBoxHeight);
    preset_label.setFont(juce::Font(fontscaler*0.7, juce::Font::bold));
    preset_label.setJustificationType(12);
    reset_arp.setBounds(centerX - buttSize / 2, centerY - diam / 2 + height * 0.40, buttSize, buttSize);
    reset_label.setBounds(centerX - textBoxWidth / 2, centerY - textBoxHeight / 2 + height * 0.35, textBoxWidth, textBoxHeight);
    reset_label.setFont(juce::Font(fontscaler*0.7, juce::Font::bold));
    reset_label.setJustificationType(12);
    
    //HARMONIZER PITCH SHIFTERS
    harm1_shift.setBounds(centerX - diam / 2 - width / 2 + width * 0.1, centerY - diam/2 + height * 0.33 , diam, diam);
    harm2_shift.setBounds(centerX - diam / 2 - width / 2 + width * 0.2, centerY - diam/2 + height * 0.33 , diam, diam);
    harm3_shift.setBounds(centerX - diam / 2 - width / 2 + width * 0.3, centerY - diam/2 + height * 0.33 , diam, diam);
    harm4_shift.setBounds(centerX - diam / 2 - width / 2 + width * 0.4, centerY - diam/2 + height * 0.33 , diam, diam);
    
    //HARMONIZER BUTTONS
    harm1_enable.setBounds(centerX - buttSize / 2 - width / 2 + width * 0.1, centerY - buttSize/2 + height * 0.43 , buttSize, buttSize);
    harm2_enable.setBounds(centerX - buttSize / 2 - width / 2 + width * 0.2, centerY - buttSize/2 + height * 0.43 , buttSize, buttSize);
    harm3_enable.setBounds(centerX - buttSize / 2 - width / 2 + width * 0.3, centerY - buttSize/2 + height * 0.43 , buttSize, buttSize);
    harm4_enable.setBounds(centerX - buttSize / 2 - width / 2 + width * 0.4, centerY - buttSize/2 + height * 0.43 , buttSize, buttSize);
    
    //REVERB
    
    reverb_label.setBounds(centerX - textBoxWidth / 2 + width * 0.18, centerY - textBoxHeight/2 - height * 0.35 , textBoxWidth, textBoxHeight);
    reverb_label.setFont(juce::Font(fontscaler, juce::Font::bold));
    reverb_label.setJustificationType(12);
    reverb1.setBounds(centerX - diam / 2 + width * 0.1, centerY - diam/2 - height * 0.25 , diam, diam);
    reverb2.setBounds(centerX - diam / 2 + width * 0.18 , centerY - diam/2 - height * 0.25 , diam, diam);
    reverb3.setBounds(centerX - diam / 2 + width * 0.26 , centerY - diam/2 - height * 0.25 , diam, diam);
    rev1_label.setBounds(centerX - textBoxWidth / 2 + width * 0.1, centerY - textBoxHeight/2 - height * 0.3 , textBoxWidth, textBoxHeight);
    rev1_label.setFont(juce::Font(fontscaler*0.6, juce::Font::bold));
    rev1_label.setJustificationType(12);
    rev2_label.setBounds(centerX - textBoxWidth / 2 + width * 0.18, centerY - textBoxHeight/2 - height * 0.3 , textBoxWidth, textBoxHeight);
    rev2_label.setFont(juce::Font(fontscaler*0.6, juce::Font::bold));
    rev2_label.setJustificationType(12);
    rev3_label.setBounds(centerX - textBoxWidth / 2 + width * 0.26, centerY - textBoxHeight/2 - height * 0.3 , textBoxWidth, textBoxHeight);
    rev3_label.setFont(juce::Font(fontscaler*0.6, juce::Font::bold));
    rev3_label.setJustificationType(12);
    
    //DELAY
    
    delay_label.setBounds(centerX - textBoxWidth / 2 + width * 0.18, centerY - textBoxHeight/2 - height * 0.13 , textBoxWidth, textBoxHeight);
    delay_label.setFont(juce::Font(fontscaler, juce::Font::bold));
    delay_label.setJustificationType(12);
    delay1.setBounds(centerX - diam / 2 + width * 0.1, centerY - diam/2 - height * 0.03 , diam, diam);
    delay2.setBounds(centerX - diam / 2 + width * 0.18 , centerY - diam/2 - height * 0.03 , diam, diam);
    delay3.setBounds(centerX - diam / 2 + width * 0.26 , centerY - diam/2 - height * 0.03 , diam, diam);
    del1_label.setBounds(centerX - textBoxWidth / 2 + width * 0.1, centerY - textBoxHeight/2 - height * 0.08 , textBoxWidth, textBoxHeight);
    del1_label.setFont(juce::Font(fontscaler*0.6, juce::Font::bold));
    del1_label.setJustificationType(12);
    del2_label.setBounds(centerX - textBoxWidth / 2 + width * 0.18, centerY - textBoxHeight/2 - height * 0.08 , textBoxWidth, textBoxHeight);
    del2_label.setFont(juce::Font(fontscaler*0.6, juce::Font::bold));
    del2_label.setJustificationType(12);
    del3_label.setBounds(centerX - textBoxWidth / 2 + width * 0.26, centerY - textBoxHeight/2 - height * 0.08 , textBoxWidth, textBoxHeight);
    del3_label.setFont(juce::Font(fontscaler*0.6, juce::Font::bold));
    del3_label.setJustificationType(12);

    
    //VERTICAL LABELS
    textBoxHeight = textBoxHeight * 3;
    textBoxWidth = textBoxWidth / 1.2;
    //mute
    h_label1.setBounds(centerX - textBoxWidth / 2 - width / 2 + width * 0.01, centerY - textBoxHeight/2 + height * 0.43 , textBoxWidth, textBoxHeight);
    h_label1.setFont(juce::Font(fontscaler, juce::Font::bold));
    h_label1.setJustificationType(20);
    //shift
    h_label2.setBounds(centerX - textBoxWidth / 2 - width / 2 + width * 0.01, centerY - textBoxHeight/2 + height * 0.32 , textBoxWidth, textBoxHeight);
    h_label2.setFont(juce::Font(fontscaler, juce::Font::bold));
    h_label2.setJustificationType(20);
    //volume
    h_label3.setBounds(centerX - textBoxWidth / 2 - width / 2 + width * 0.01, centerY - textBoxHeight/2 - height * 0.16 , textBoxWidth, textBoxHeight);
    h_label3.setFont(juce::Font(fontscaler, juce::Font::bold));
    h_label3.setJustificationType(20);
    //pan
    h_label4.setBounds(centerX - textBoxWidth / 2 - width / 2 + width * 0.01, centerY - textBoxHeight/2 + height * 0.11 , textBoxWidth, textBoxHeight);
    h_label4.setFont(juce::Font(fontscaler, juce::Font::bold));
    h_label4.setJustificationType(20);
    //delay time
    h_label5.setBounds(centerX - textBoxWidth / 2 - width / 2 + width * 0.018, centerY - textBoxHeight/2 + height * 0.21 , textBoxWidth, textBoxHeight);
    h_label5.setFont(juce::Font(fontscaler, juce::Font::bold));
    h_label5.setJustificationType(20);
    //track
    track1_label.setBounds(centerX - textBoxWidth / 2 + width *0.085, centerY - textBoxHeight/2 + height/3.5 , textBoxWidth/2.2, textBoxHeight/2);
    track1_label.setFont(juce::Font(fontscaler, juce::Font::bold));
    track1_label.setJustificationType(20);
    
}
void TrackPadComponent::paint(juce::Graphics& g){

    MainComponent component;

    g.fillAll (juce::Colour(32, 32, 32));
    float xPos = TrackPadComponent::getX();
    float yPos = TrackPadComponent::getY();
    float width = TrackPadComponent::getWidth();
    float height = TrackPadComponent::getHeight();
    auto lineThickness = juce::jmin (15.0f, (float) juce::jmin (width, height) * 0.45f) * 0.1f;
    auto bounds = TrackPadComponent::getLocalBounds().toFloat();
    g.setColour(juce::Colours::grey);
    g.drawRect (bounds, lineThickness);
    g.drawLine(0, height/2, width, height/2,lineThickness);
    g.drawLine(width/2, 0, width/2, height,lineThickness);
    juce::Path p;
    auto xy = TrackPadComponent::getMouseXYRelative();
    float x {bounds.getWidth()/2};
    float y {bounds.getHeight()/2};

    if (oscReceiving) {
        x = x_message * 300;
        y = mapY(y_message) * 180;
    }
    
    else if (isDragged) {
        x = (int)xy.getX();
        y = (int)xy.getY();
    }

    /*
    if(isDragged){
        x = (int) xy.getX();
        y = (int) xy.getY();
    }*/

    /*
    if(isInDeadZone){
        x = bounds.getWidth()/2;
        y = bounds.getHeight()/2;
    }*/
    

    oscReceiving = false;
      
    
    p.addEllipse(x-width/13/2, y-width/13/2, width/13, width/13);
    g.setColour(juce::Colours::salmon);
    g.fillPath(p);

    DBG("Y " << x_message);
}

void TrackPadComponent::mouseDrag(const juce::MouseEvent &event)
{
    auto xy = TrackPadComponent::getMouseXYRelative();
    float width = TrackPadComponent::getWidth();
    float height = TrackPadComponent::getHeight();
    float mx = ((float)xy.getX() - width / 2) / width * 2;
    float my = ((float)-xy.getY() + height / 2) / height * 2;
    bool dead_zone {mx<=0.05 && mx>=-0.05 && my<=0.05 && my>=-0.05};

    if(mx <= 1.0f && mx>= -1.0f && my <= 1.0f && my>= -1.0f){
        isDragged = true;
        isInDeadZone = false;
        repaint();
        juce::OSCSender sender;
        sender.connect ("127.0.0.1",57120);
        sender.send ("/juce/trackpad_x", (float)std::pow(2,mx));
        sender.send ("/juce/trackpad_y", (float)std::pow(2, my));
    }
    
}
void TrackPadComponent::mouseUp (const juce::MouseEvent &event){
    isDragged = false;
}

float TrackPadComponent::mapY(float y_val) {

    float start1 = 1;
    float stop1 = 0;
    float start2 = 0;
    float stop2 = 1;

    float outgoing =
        start2 + (stop2 - start2) * ((y_val - start1) / (stop1 - start1));

    return outgoing;
}

