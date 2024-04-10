#include <algorithm>
#ifndef NATURALMERGESORTER_H
#define NATURALMERGESORTER_H

class NaturalMergeSorter {
public:
   virtual int GetSortedRunLength(int* array, int arrayLength, int startIndex) {
        // Check if startIndex is out of bounds
      if (startIndex < 0 || startIndex >= arrayLength) {
         return 0;
      }

      int runLength = 1; // Initialize run length to 1

      // Increment run length while the next element is greater than the current
      while (startIndex + runLength < arrayLength && array[startIndex + runLength] >= array[startIndex + runLength - 1]) {
         runLength++;
      }

      return runLength;
   }
   
   
   virtual void NaturalMergeSort(int* array, int arrayLength) {
      int i = 0;

      while (i < arrayLength) {
         // Get the length of the first sorted run starting at i
         int firstRunLength = GetSortedRunLength(array, arrayLength, i);

         // Return if the first run's length equals the array length
         if (firstRunLength == arrayLength) {
            return;
         }

         // If the first run ends at the array's end, reassign i=0 and repeat step 2
         if (i + firstRunLength == arrayLength) {
            i = 0;
            continue;
         }

         // Get the length of the second sorted run starting immediately after the first
         int secondRunLength = GetSortedRunLength(array, arrayLength, i + firstRunLength);

         // Merge the two runs
         Merge(array, i, i + firstRunLength - 1, std::min(i + firstRunLength + secondRunLength - 1, arrayLength - 1));

         // Reassign i with the first index after the second run or 0 if the second run ends at the array's end
         i = (i + firstRunLength + secondRunLength == arrayLength) ? 0 : i + firstRunLength + secondRunLength;
      }
   }
   
   virtual void Merge(int* numbers, int leftFirst, int leftLast,
      int rightLast) {
      int mergedSize = rightLast - leftFirst + 1;
      int* mergedNumbers = new int[mergedSize];
      int mergePos = 0;
      int leftPos = leftFirst;
      int rightPos = leftLast + 1;
         
      // Add smallest element from left or right partition to merged numbers
      while (leftPos <= leftLast && rightPos <= rightLast) {
         if (numbers[leftPos] <= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            leftPos++;
         }
         else {
            mergedNumbers[mergePos] = numbers[rightPos];
            rightPos++;
         }
         mergePos++;
      }
         
      // If left partition isn't empty, add remaining elements to mergedNumbers
      while (leftPos <= leftLast) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
         mergePos++;
      }
      
      // If right partition isn't empty, add remaining elements to mergedNumbers
      while (rightPos <= rightLast) {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
         mergePos++;
      }
      
      // Copy merged numbers back to numbers
      for (mergePos = 0; mergePos < mergedSize; mergePos++) {
         numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
      }
      
      // Free temporary array
      delete[] mergedNumbers;
   }
};

#endif