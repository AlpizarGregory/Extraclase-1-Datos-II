#include <iostream>
#include "sorter.h"

using namespace std;


int main() {
    string unsortedFile = "unsortedInts.csv";
    string sortedFile = "sortedInts.csv";
    sorter newSorter(unsortedFile, sortedFile);
    newSorter.execute();

    return 0;
}
