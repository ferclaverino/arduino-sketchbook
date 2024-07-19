#ifndef CircularBuffer_h
#define CircularBuffer_h

class CircularBuffer {
public:
  CircularBuffer(const unsigned int size);
  void push(const unsigned long);
  const unsigned long getFirst();
  const unsigned long getLast();

private:
  unsigned int _size;
  unsigned long _data[100];
  unsigned int _firstIndex = 0;
  unsigned int _lastIndex = 0;
  bool _hasToMoveFirstIndex = false;

  void moveLastIndex();
  void moveFirstIndex();
};

#endif