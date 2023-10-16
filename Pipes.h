// This class represent pipes

#ifndef PIPES_H
#define PIPE_H

#include "Obstancles.h"

class Pipes : public Obstancles {
 private:
 // Gap width and the start Y point of the gap; 
  const int gapWidth = 135;
  int gapY;

 public:
 // COntructor and destructor
  Pipes();
  ~Pipes();

//  Set and get function
  int getGapY();
  void setGapY(int gap);
};

#endif