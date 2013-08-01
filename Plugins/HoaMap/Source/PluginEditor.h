/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINEDITOR_H_3539932E__
#define __PLUGINEDITOR_H_3539932E__

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "HoaMap.h"
#include "TextBoxSlider.h"
#include "ConfigComponent.h"

//==============================================================================
/**
*/
class HoaMapAudioProcessorEditor  :
public AudioProcessorEditor,
public ChangeListener,
public Timer,
public AudioProcessorListener,
public Button::Listener
{
public:
    HoaMapAudioProcessorEditor (HoaMapAudioProcessor* ownerFilter);
    ~HoaMapAudioProcessorEditor();
    
    void timerCallback();
    void changeListenerCallback (ChangeBroadcaster* source);
    void sliderValueChanged (Slider*);
    void buttonClicked (Button *button);
    void buttonStateChanged (Button *button);
    
    void mouseMove (const MouseEvent &event);
    void mouseDown (const MouseEvent &event);
    
    void audioProcessorParameterChanged (AudioProcessor *processor, int parameterIndex, float newValue);
    void audioProcessorChanged (AudioProcessor *processor);
    void audioProcessorParameterChangeGestureBegin (AudioProcessor *processor, int parameterIndex);
    void audioProcessorParameterChangeGestureEnd (AudioProcessor *processor, int parameterIndex);
    
    //==============================================================================
    // This is just a standard Juce paint method...
    void paint (Graphics& g);
    
    void checkAllProcessorValues();
    
private:
    Image bg;
    TextBoxSlider speakerOffset_Slider, speakerDistance_Slider;
    HoaMap theMap;
    Label nbSources_Label, nbSpeakers_Label;
    //ToggleButton* configButton;
    ConfigComponent* configPannel;
    
    bool cicm_link_over;
    
    int m_nbSources, m_nbSpeakers;
    
    HoaMapAudioProcessor* getProcessor() const
    {
        return static_cast <HoaMapAudioProcessor*> (getAudioProcessor());
    }
};


#endif  // __PLUGINEDITOR_H_3539932E__
