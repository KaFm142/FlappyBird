#include "Pipes.h"

// Constructor
Pipes::Pipes() { gapY = 0; }

// Destructor
Pipes::~Pipes() {}

// Set and get function
int Pipes::getGapY() { return gapY; }

void Pipes::setGapY(int gap) { gapY = gap; }