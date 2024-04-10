#ifndef COMPARER_H
#define COMPARER_H

// Comparer is an abstract base that can compare two items with the Compare() 
// function. The Compare() function compares items a and b and returns an 
// integer:
// - greater than 0 if a > b,
// - less than 0 if a < b, or
// - equal to 0 if a == b
template <typename T>
class Comparer {
public:
   virtual int Compare(const T& a, const T& b) = 0;
};

#endif