#ifndef CaudalimeterSampler_h
#define CaudalimeterSampler_h

#include "Wait.h"
#include "CircularBuffer.h"
#include "Caudalimeter.h"

class CaudalimeterSampler {
public:
  CaudalimeterSampler(Caudalimeter* caudalimeter, const unsigned int bufferSize, const unsigned int sampleRateInMillis);
  void sample();
  const unsigned int getFrequency();

private:
  Wait* _waitForSample;
  CircularBuffer* _buffer;
  Caudalimeter* _caudalimeter;
  unsigned long _frequency;
};

#endif