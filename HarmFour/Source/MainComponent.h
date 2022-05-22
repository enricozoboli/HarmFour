#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class CustomLookAndFeel : public juce::LookAndFeel_V4
{
public:

    //KNOBS
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        float diameter = juce::jmin(width, height)/3*2;
        float radius = diameter / 2;
        float centerX = x + width / 2;
        float centerY = y + height / 3;
        float rx = centerX - radius;
        float ry = centerY - radius;
        float fontSize = width/5;
        if (slider.getProperties().contains ("gain"))
        {
            rotaryStartAngle = (-rotaryStartAngle * 1.035);
            
        }
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - std::abs(rotaryStartAngle)));

        //Updating Variable according to sliderPos
        float vardiamter = diameter * sliderPos;
        float varradius = vardiamter / 2;
        float varRx = centerX - varradius;
        float VarRy = centerY - varradius;

        //Inside Circle
        juce::Rectangle<float> knobArea(rx, ry, diameter, diameter);
        //g.setColour(juce::Colours::darkcyan);
        g.setColour (slider.findColour (juce::Slider::rotarySliderFillColourId));
        g.fillEllipse(knobArea);

        ///PATH TICK
        juce::Path knobTick;
        g.setColour(slider.findColour (juce::Slider::backgroundColourId));
        if (slider.getProperties().contains ("gain"))
            g.setColour(juce::Colours::antiquewhite);
        knobTick.addRectangle(0-1.5f, -radius, 3.0f, radius * 0.6);
        g.fillPath(knobTick, juce::AffineTransform::rotation(angle).translated(centerX, centerY));
        //LABEL
        g.setColour(juce::Colours::antiquewhite);
        g.setFont(fontSize);
        if (slider.getProperties().contains ("gain"))
        {
            g.drawText(juce::String(slider.getValue())+" dB", x, y+width/3*2, width, height/3, juce::Justification::centredBottom);
            
        }else if (slider.getProperties().contains ("milliseconds")){
            g.drawText(juce::String(slider.getValue())+" ms", x, y+width/3*2, width, height/3, juce::Justification::centredBottom);
        }else if (slider.getProperties().contains ("percentage")){
            g.drawText(juce::String(slider.getValue()*100)+" %", x, y+width/3*2, width, height/3, juce::Justification::centredBottom);
        }else if (slider.getProperties().contains ("seconds")){
            g.drawText(juce::String(slider.getValue())+" s", x, y+width/3*2, width, height/3, juce::Justification::centredBottom);
        }else
        g.drawText(juce::String(slider.getValue()), x, y+width/3*2, width, height/3, juce::Justification::centredBottom);
        
        
        
    }

    void drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPos,
        float minSliderPos,
        float maxSliderPos,
        const juce::Slider::SliderStyle style, juce::Slider& slider) override
    {
        if (slider.isBar())
        {
            g.setColour(juce::Colours::firebrick);
            g.fillRect(slider.isHorizontal() ? juce::Rectangle<float>(static_cast<float> (x), (float)y + 0.5f, sliderPos - (float)x, (float)height - 1.0f)
                : juce::Rectangle<float>((float)x + 0.5f, sliderPos, (float)width - 1.0f, (float)y + ((float)height - sliderPos)));
        }
       
    }

    //LABELS
    void drawLabel(juce::Graphics& g, juce::Label& label) override
    {
        g.fillAll(label.findColour(juce::Label::backgroundColourId));

        if (!label.isBeingEdited())
        {
            if (label.getProperties().contains ("vertical"))
                {
                    auto bounds = label.getLocalBounds();
                    auto midX = bounds.getWidth()/2;
                    auto midY = bounds.getHeight()/2;
                    juce::AffineTransform t = juce::AffineTransform::rotation(-juce::MathConstants<float>::halfPi, midX, midY);
                    g.addTransform(t);
                }
            auto alpha = label.isEnabled() ? 1.0f : 0.5f;
            const juce::Font font(getLabelFont(label));

            g.setColour(label.findColour(juce::Label::textColourId).withMultipliedAlpha(alpha));
            //g.setColour(juce::Colours::darkred);
            g.setFont(font);
            auto textArea = getLabelBorderSize(label).subtractedFrom(label.getLocalBounds());
            g.drawFittedText(label.getText(), textArea, label.getJustificationType(),
                    juce::jmax(1, (int)((float)textArea.getHeight() / font.getHeight())),
                    label.getMinimumHorizontalScale());
            g.setColour(label.findColour(juce::Label::backgroundColourId).withMultipliedAlpha(alpha));

        }

        else if (label.isEnabled())
        {
            g.setColour(label.findColour(juce::Label::backgroundColourId));
        }

        g.drawRect(label.getLocalBounds());
    }

    //COMBOBOX
    void drawComboBox(juce::Graphics& g, int width, int height, bool,
        int, int, int, int, juce::ComboBox& box) override
    {
        auto cornerSize = box.findParentComponentOfClass<juce::ChoicePropertyComponent>() != nullptr ? 0.0f : 3.0f;
        juce::Rectangle<int> boxBounds(0, 0, width, height);

        g.setColour(juce::Colour(32, 32, 32));
        g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);

        g.setColour(juce::Colour(0, 0, 0));
        g.drawRoundedRectangle(boxBounds.toFloat().reduced(0.5f, 0.5f), cornerSize, 1.0f);

        juce::Rectangle<int> arrowZone(width - 30, 0, 20, height);
        juce::Path path;
        path.startNewSubPath((float)arrowZone.getX() + 3.0f, (float)arrowZone.getCentreY() - 2.0f);
        path.lineTo((float)arrowZone.getCentreX(), (float)arrowZone.getCentreY() + 3.0f);
        path.lineTo((float)arrowZone.getRight() - 3.0f, (float)arrowZone.getCentreY() - 2.0f);

        g.setColour(box.findColour(juce::ComboBox::arrowColourId).withAlpha((box.isEnabled() ? 0.9f : 0.2f)));
        g.strokePath(path, juce::PathStrokeType(2.0f));
    }

    //COMBOBOX MENU
    void drawPopupMenuItem(juce::Graphics& g, const juce::Rectangle<int>& area,
        const bool isSeparator, const bool isActive,
        const bool isHighlighted, const bool isTicked,
        const bool hasSubMenu, const juce::String& text,
        const juce::String& shortcutKeyText,
        const juce::Drawable* icon, const juce::Colour* const textColourToUse) override
    {
        if (isSeparator)
        {
            auto r = area.reduced(5, 0);
            r.removeFromTop(juce::roundToInt(((float)r.getHeight() * 0.5f) - 0.5f));

            g.setColour(juce::Colour(32, 32, 32));
            g.fillRect(r.removeFromTop(1));
        }
        else
        {
            /*auto textColour = (textColourToUse == nullptr ? findColour(juce::PopupMenu::textColourId)
                : *textColourToUse);*/
            auto textColour = juce::Colour(32, 32, 32);

            auto r = area.reduced(1);

            if (isHighlighted && isActive)
            {
                g.setColour(juce::Colour(32, 32, 32));
                g.fillRect(r);

                g.setColour(findColour(juce::PopupMenu::highlightedTextColourId));
            }
            else
            {
                g.setColour(juce::Colour(32, 32, 32));
            }

            r.reduce(juce::jmin(5, area.getWidth() / 20), 0);

            auto font = getPopupMenuFont();

            auto maxFontHeight = (float)r.getHeight() / 1.3f;

            if (font.getHeight() > maxFontHeight)
                font.setHeight(maxFontHeight);

            g.setFont(font);

            auto iconArea = r.removeFromLeft(juce::roundToInt(maxFontHeight)).toFloat();

            if (icon != nullptr)
            {
                icon->drawWithin(g, iconArea, juce::RectanglePlacement::centred | juce::RectanglePlacement::onlyReduceInSize, 1.0f);
                r.removeFromLeft(juce::roundToInt(maxFontHeight * 0.5f));
            }

            if (hasSubMenu)
            {
                auto arrowH = 0.6f * getPopupMenuFont().getAscent();

                auto x = static_cast<float> (r.removeFromRight((int)arrowH).getX());
                auto halfH = static_cast<float> (r.getCentreY());

                juce::Path path;
                path.startNewSubPath(x, halfH - arrowH * 0.5f);
                path.lineTo(x + arrowH * 0.6f, halfH);
                path.lineTo(x, halfH + arrowH * 0.5f);

                g.strokePath(path, juce::PathStrokeType(2.0f));
            }

            r.removeFromRight(3);
            g.drawFittedText(text, r, juce::Justification::centredLeft, 1);

            if (shortcutKeyText.isNotEmpty())
            {
                auto f2 = font;
                f2.setHeight(f2.getHeight() * 0.75f);
                f2.setHorizontalScale(0.95f);
                g.setFont(f2);

                g.drawText(shortcutKeyText, r, juce::Justification::centredRight, true);
            }
        }
    }
};

class SliderLookAndFeel    : public juce::LookAndFeel_V4
{
    public:
    void drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
                               float sliderPos, float minSliderPos, float maxSliderPos,
                               const juce::Slider::SliderStyle style, juce::Slider& slider) override
        {
            auto sWidth = width / 3;
            auto offset = height / 15;
            minSliderPos = minSliderPos - offset;
            
            g.setColour(slider.findColour (juce::Slider::backgroundColourId));
            g.fillRect(x, y+offset, sWidth,height-offset*2);
            slider.setColour(juce::Slider::textBoxOutlineColourId, slider.findColour (juce::Slider::backgroundColourId).withAlpha(0.0f));
            if (style == juce::Slider::LinearBar || style == juce::Slider::LinearBarVertical)
            {
                juce::Path p;

                if (style == juce::Slider::LinearBarVertical && sliderPos<height-2*offset)
                    p.addRectangle ((float) x, offset + sliderPos, (float) sWidth + 1.0f,1.0f+ (float) height - sliderPos - 2 * offset);
                
                auto baseColour = (slider.findColour (juce::Slider::rotarySliderFillColourId));

                g.setColour (baseColour);
                g.fillPath (p);
                g.setColour (baseColour);

                auto lineThickness = juce::jmin (15.0f, (float) juce::jmin (width, height) * 0.45f) * 0.1f;
                auto bounds = slider.getLocalBounds().toFloat();
                bounds.setSize(bounds.getWidth()/3+lineThickness, bounds.getHeight()-2*offset);
                bounds.setX(bounds.getX());
                bounds.setY(bounds.getY()+offset);
                g.drawRect (bounds, lineThickness);
                g.setColour(slider.findColour (juce::Slider::backgroundColourId));
                juce::Rectangle<float> tick (x+1.0f, y+((float)height)/15*4-lineThickness*0.5, sWidth-1.0f, lineThickness);
                g.fillRect(tick);
                g.setColour(juce::Colours::antiquewhite);
                juce::Rectangle<float> tick2 (x+1.0f+ sWidth, y+((float)height)/15*4-lineThickness*0.5, sWidth/3, lineThickness);
                g.fillRect(tick2);
                g.setFont((float) width/5.4);
                g.drawText("0 dB",x+width/3, y+((float)height)/30*7, width/3*2, width/3, juce::Justification::right);
                g.drawText("+3 dB",x+width/3, y+((float)height)/30*1, width/3*2, width/3, juce::Justification::right);
                g.drawText("-12 dB",x+width/3, y+ (float) height/10*9-lineThickness, width/3*2, width/3, juce::Justification::right);
                
            }
            else
            {
                drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
                drawLinearSliderThumb      (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
            }
        }

        void drawLinearSliderBackground (juce::Graphics& g, int x, int y, int width, int height,
                                         float /*sliderPos*/,
                                         float /*minSliderPos*/,
                                         float /*maxSliderPos*/,
                                         const juce::Slider::SliderStyle /*style*/, juce::Slider& slider) override
        {
            auto sliderRadius = (float) width/9;
            juce::Path on, off;

            if (slider.isHorizontal())
            {
                auto iy = (float) y + (float) height * 0.5f - sliderRadius * 0.5f;
                juce::Rectangle<float> r ((float) x - sliderRadius * 0.5f, iy, (float) width + sliderRadius, sliderRadius);
                auto onW = r.getWidth() * ((float) slider.valueToProportionOfLength (slider.getValue()));

                on.addRectangle (r.removeFromLeft (onW));
                off.addRectangle (r);
            }
            else
            {
                auto ix = (float) x + (float) width * 0.5f - sliderRadius * 0.5f;
                juce::Rectangle<float> r (ix, (float) y - sliderRadius * 0.5f, sliderRadius, (float) height + sliderRadius);
                auto onH = r.getHeight() * ((float) slider.valueToProportionOfLength (slider.getValue()));

                on.addRectangle (r.removeFromBottom (onH));
                off.addRectangle (r);
            }

            g.setColour (slider.findColour (juce::Slider::rotarySliderFillColourId));
            g.fillPath (on);

            g.setColour (slider.findColour (juce::Slider::trackColourId));
            g.fillPath (off);
        }
};

class TrackPadComponent    : public juce::Component
{
public:
    TrackPadComponent(){}
    void paint (juce::Graphics&) override;
    void mouseDrag (const juce::MouseEvent &event) override;
    void mouseUp (const juce::MouseEvent &event) override;
    bool isDragged {false};
    bool isInDeadZone {true};
    float x_message;
    float y_message;
    bool oscReceiving {false};

    float mapY(float y_val);
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackPadComponent)
};


class MainComponent  : public juce::Component,
                       private juce::OSCReceiver, 
                       private juce::OSCReceiver::ListenerWithOSCAddress<juce::OSCReceiver::MessageLoopCallback>

{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

 

private:
    //==============================================================================
    // Your private member variables go here...
    //Sliders
    juce::Slider harm1_shift;
    juce::Slider harm2_shift;
    juce::Slider harm3_shift;
    juce::Slider harm4_shift;
    juce::Slider harm1_pan;
    juce::Slider harm2_pan;
    juce::Slider harm3_pan;
    juce::Slider harm4_pan;
    juce::Slider harm1_volume;
    juce::Slider harm2_volume;
    juce::Slider harm3_volume;
    juce::Slider harm4_volume;
    juce::TextButton harm1_enable;
    juce::TextButton harm2_enable;
    juce::TextButton harm3_enable;
    juce::TextButton harm4_enable;
    juce::Slider harm1_delay;
    juce::Slider harm2_delay;
    juce::Slider harm3_delay;
    juce::Slider harm4_delay;
    
    juce::Slider in_volume;
    juce::Slider out_volume;
    
    juce::Slider reverb1;
    juce::Slider reverb2;
    juce::Slider reverb3;
    
    juce::Slider delay1;
    juce::Slider delay2;
    juce::Slider delay3;
    
    juce::Label h_label1;
    juce::Label h_label2;
    juce::Label h_label3;
    juce::Label h_label4;
    juce::Label h_label5;
    juce::Label in_label;
    juce::Label out_label;
    juce::Label reverb_label;
    juce::Label rev1_label;
    juce::Label rev2_label;
    juce::Label rev3_label;
    juce::Label delay_label;
    juce::Label del1_label;
    juce::Label del2_label;
    juce::Label del3_label;
    juce::Label track1_label;
    juce::Label track2_label;
    juce::Label random_label;
    juce::Label preset_label;
    juce::Label reset_label;

    juce::TextButton arpeggios;
    juce::TextButton reset_arp;
    juce::TextButton wallofvoice;
    
    TrackPadComponent trackpad;

    
    
    
    juce::OSCSender sender;

    CustomLookAndFeel customLookAndFeel;
    SliderLookAndFeel sliderLookAndFeel;

    void showConnectionErrorMessage (const juce::String& messageText)
        {
            juce::AlertWindow::showMessageBoxAsync (juce::AlertWindow::WarningIcon,
                                                    "Connection error",
                                                    messageText,
                                                    "OK");
        }

    void oscMessageReceived(const juce::OSCMessage& message) override
    {
        
        juce::OSCSender sender;
        sender.connect("127.0.0.1", 57120);
        sender.send("/juce/trackpad_x", message[0].getFloat32()*2);
        sender.send("/juce/trackpad_y", message[1].getFloat32()*2);

        trackpad.oscReceiving = true;

        trackpad.x_message = message[0].getFloat32();
        trackpad.y_message = message[1].getFloat32();

       
        trackpad.repaint();

    }


    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
