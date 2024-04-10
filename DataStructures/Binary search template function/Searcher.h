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
      int left = 0;
      int right = arraySize - 1;

      while (left <= right) {
         int mid = left + (right - left) / 2;

         // Compare array[mid] with the key using the comparer
         int comparisonResult = comparer.Compare(array[mid], key);

         if (comparisonResult == 0) {
            // Key found
            return mid;
         } else if (comparisonResult < 0) {
            // If array[mid] < key, search the right half
            left = mid + 1;
         } else {
            // If array[mid] > key, search the left half
            right = mid - 1;
         }
      }
      return -1;
   }
};

#endif
