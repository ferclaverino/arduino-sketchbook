#ifndef Wait_h
#define Wait_h

class Wait {
public:
  Wait(const unsigned int waitTimeInmillis);
  const bool done();

private:
  unsigned int _waitTimeInmillis;
  unsigned long _lastTimestamp;
};

#endif