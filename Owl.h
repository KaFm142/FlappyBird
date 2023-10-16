// this class is the owl

#ifndef OWL_H
#define OWL_H

#include "Flyable.h"

class Owl : public Flyable {
 public:
  
  // class constructor and destructor
  Owl();
  ~Owl();
  // Faliing method
  void fall();
};

#endif