#ifndef SEARCHER_H
#define SEARCHER_H

#include "Comparer.h"

template <typename T>
class Searcher {
public:
   // Returns the index of the key in the sorted array, or -1 if the key is not
   // found
   static int BinarySearch(T* array, int arraySize, const T& key,
      Comparer<T>& comparer) {
      // Your code here (remove placeholder line below)
      return -1;
   }
};

#endif
