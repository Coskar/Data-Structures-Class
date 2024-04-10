#include <iostream>
#include <string>
#include "Comparer.h"
#include "StringComparer.h"
#include "IntComparer.h"
#include "Searcher.h"
using namespace std;

// Implementation of PrintSearches is below main()
template <typename T>
void PrintSearches(T* sortedArray, int sortedArraySize, T* searchKeys,
   int searchKeysSize, Comparer<T>& comparer, int* expectedResults,
   bool keyInQuotes);

int main(int argc, char *argv[]) {
    // Perform sample searches with strings
    string sortedFruits[] = { "Apple", "Apricot", "Banana", "Blueberry", 
       "Cherry", "Grape", "Grapefruit", "Guava", "Lemon", "Lime", "Orange", 
       "Peach", "Pear", "Pineapple", "Raspberry", "Strawberry"
    };
    int sortedFruitsSize = sizeof(sortedFruits) / sizeof(sortedFruits[0]);
    string fruitSearches[] = { "Nectarine", "Mango", "Guava", "Strawberry", 
       "Kiwi", "Apple", "Raspberry", "Carrot", "Lemon", "Bread"
    };
    int fruitSearchesSize = sizeof(fruitSearches) / sizeof(fruitSearches[0]);
    int expectedFruitSearchResults[] = { -1, -1, 7, 15, -1, 0, 14, -1, 8, -1 };
    StringComparer stringComparer;
    PrintSearches(sortedFruits, sortedFruitsSize, fruitSearches,
      fruitSearchesSize, stringComparer, expectedFruitSearchResults, true);
    
   // Perform sample searches with integers
   int integers[] = {
      11, 21, 27, 34, 42, 58, 66, 71, 72, 85, 88, 91, 98
   };
   int integerSearches[] = {
       42, 23, 11, 19, 87, 98, 54, 66, 92, 1, 14, 21, 66, 87, 83
   };
   int expectedIntegerSearchResults[] = {
      4, -1, 0, -1, -1, 12, -1, 6, -1, -1, -1, 1, 6, -1, -1
   };
   IntComparer intComparer;
   PrintSearches(integers, sizeof(integers) / sizeof(integers[0]),
      integerSearches, sizeof(integerSearches) / sizeof(integerSearches[0]),
      intComparer, expectedIntegerSearchResults, false);
    
   return 0;
}

template <typename T>
void PrintSearches(T* sortedArray, int sortedArraySize, T* searchKeys,
   int searchKeysSize, Comparer<T>& comparer, int* expectedResults,
   bool keyInQuotes) {
   // If keyInQuotes is true, " characters surround the key in output
   // statements. Otherwise empty strings surround the key.
   string extra = keyInQuotes ? "\"" : "";
   
   // Iterate through array of search keys and search for each
   for (int i = 0; i < searchKeysSize; i++) {
      // Get the key to search for
      auto searchKey = searchKeys[i];
      
      // Peform the search
      int index = Searcher<T>::BinarySearch(sortedArray, sortedArraySize,
         searchKey, comparer);
      
      // Compare actual result against expceted
      int expected = expectedResults[i];
      if (index == expected) {
         cout << "PASS: Search for key " << extra << searchKey << extra;
         cout << " returned " << expected << "." << endl;
      }
      else {
         cout << "FAIL: Search for key " << extra << searchKey << extra;
         cout << " should have returned " << expected << ", but returned ";
         cout << index << "." << endl;
      }
   }
}