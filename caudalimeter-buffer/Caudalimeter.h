#ifndef Caudalimeter_h
#define Caudalimeter_h

typedef void(*TickCallback)();

class Caudalimeter {
public:
  Caudalimeter(const unsigned int pin);
  void begin(const TickCallback tickCalback);
  void tick();
  unsigned long getTickCount();

private:
  unsigned int _pin;
  unsigned long _tickCount;
};

#endif