#pragma once
#include <juce_dsp/processors/juce_IIRFilter.h>
#include "juce_audio_basics/utilities/juce_Decibels.h"

class Biquad{
public:
  void prepare(double sr){
    sample_rate = sr;
    filter.reset();
  }

  void set_filter_coefficients(float hz, float q = 0.704f){
    *filter.coefficients = *juce::dsp::IIR::Coefficients<float>::makeHighPass(
        sample_rate, hz, q);
    *filter.coefficients = *juce::dsp::IIR::Coefficients<float>::makeLowPass(
        sample_rate, hz, q);
  }

  void set_peak(float hz, float q, float gain_db){
    *filter.coefficients = *juce::dsp::IIR::Coefficients<float>::makePeakFilter(
            sample_rate, hz, q, juce::Decibels::decibelsToGain(gain_db));
  }
  void process(float sample){
    filter.processSample(sample);
  }

  void reset(){
    filter.reset();
  }

private:
  double sample_rate = 44100.;
  juce::dsp::IIR::Filter<float> filter;
};