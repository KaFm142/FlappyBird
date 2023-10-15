#ifndef PIPES_H
#define PIPE_H

#include "Obstancles.h"

class Pipes : public Obstancles {
 private:
  const int gapWidth = 135;
  int gapY;

 public:
  Pipes();
  ~Pipes();

  int getGapY();
  void setGapY(int gap);
};

#endif