#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "SortedNumberList.h"
using namespace std;

void PrintList(SortedNumberList& list);
vector<string> SpaceSplit(string source);

int main(int argc, char *argv[]) {
   // Read the line of input numbers
   string inputLine;
   getline(cin, inputLine);

   // Split on space character
   vector<string> terms = SpaceSplit(inputLine);

   // Insert each value and show the sorted list's contents after each insertion
   SortedNumberList list;
   for (auto term : terms) {
      double number = stod(term);
      cout << "List after inserting " << number << ": " << endl;
      list.Insert(number);
      PrintList(list);
   }

   /*
   // Read the input line with numbers to remove
   getline(cin, inputLine);
   terms = SpaceSplit(inputLine);

   // Remove each value
   for (auto term : terms) {
      double number = stod(term);
      cout << "List after removing " << number << ": " << endl;
      list.Remove(number);
      PrintList(list);
   }
   */

   return 0;
}

// Prints the SortedNumberList's contents, in order from head to tail
void PrintList(SortedNumberList& list) {
   Node* node = list.head;
   while (node) {
      cout << node->GetData() << " ";
      node = node->GetNext();
   }
   cout << endl;
}

// Splits a string at each space character, adding each substring to the vector
vector<string> SpaceSplit(string source) {
   vector<string> result;
   size_t start = 0;
   for (size_t i = 0; i < source.length(); i++) {
      if (' ' == source[i]) {
         result.push_back(source.substr(start, i - start));
         start = i + 1;
      }
   }
   result.push_back(source.substr(start));
   return result;
}
