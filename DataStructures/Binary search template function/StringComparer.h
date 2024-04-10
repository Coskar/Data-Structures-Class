#ifndef STRINGCOMPARER_H
#define STRINGCOMPARER_H

#include <string>
#include "Comparer.h"

// StringComparer inherits from Comparer<std::string> and so provides the 
// ability to compare two std::string objects.
class StringComparer : public Comparer<std::string> {
public:
   int Compare(const std::string& a, const std::string& b) override {
      return a.compare(b);
   }
};

#endif