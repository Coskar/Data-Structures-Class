#ifndef INTCOMPARER_H
#define INTCOMPARER_H

#include "Comparer.h"

// IntComparer inherits from Comparer<int> and so provides the
// ability to compare two integers.
class IntComparer : public Comparer<int> {
public:
   int Compare(const int& a, const int& b) override {
      if (a < b) {
         return -1;
      }
      else if (a > b) {
         return 1;
      }
      return 0;
   }
};

#endif