#pragma once
#include <cmath>

inline float linear_interp(float a, float b, float t){
  return a + (b - a) * t;
}

inline float exponential_map(float t, float min_value, float max_value){
  return min_value * std::pow(max_value/min_value, t);
}

inline float soft_clip(float x){
  return std::tanh(x);
}

inline float asymmetric_clip(float x, float pos_drive, float neg_drive){
  return x >= 0.0f ? std::tanh(x * pos_drive) : std::tanh(x * neg_drive);
}