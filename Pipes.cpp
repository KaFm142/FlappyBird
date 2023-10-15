#include "Pipes.h"

Pipes::Pipes() { gapY = 0; }

Pipes::~Pipes() {}

int Pipes::getGapY() { return gapY; }

void Pipes::setGapY(int gap) { gapY = gap; }