#include "CaudalimeterSampler.h"

CaudalimeterSampler::CaudalimeterSampler(Caudalimeter* caudalimeter, const unsigned int bufferSize, const unsigned int sampleRateInMillis) {
  _waitForSample = new Wait(sampleRateInMillis);
  _buffer = new CircularBuffer(bufferSize);
  _caudalimeter = caudalimeter;
}

void CaudalimeterSampler::sample() {
  if (_waitForSample->done()) {
    _buffer->push(_caudalimeter->getTickCount());
    _frequency = _buffer->getLast() - _buffer->getFirst();
  }
}

const unsigned int CaudalimeterSampler::getFrequency() {
  return _frequency;
}

