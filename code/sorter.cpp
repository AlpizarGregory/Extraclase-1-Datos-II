#include "sorter.h"



sorter::sorter(const std::string &oldLocation, const std::string &newLocation) {
    unsortedPath = oldLocation;
    sortedPath = newLocation;
    sizeOfArray = sorter::dataCounter();
    pages = pagesCounter();
}

int sorter::dataCounter() {
    std::ifstream file;
    file.open(unsortedPath);
    int counter = 0;

    while (file.good() && counter < 1536) {
        std::string line;
        std::getline(file, line, ',');
        if (line != ""){
            counter ++;
        }

    }

    file.close();

    return counter;

}

void sorter::execute() {
    std::ifstream file;
    int unsortedArray[sorter::sizeOfArray];
    int sortedArray [sorter::sizeOfArray];
    file.open(unsortedPath);
    int index = 0;

    while (file.good() && index < sizeOfArray) {
        std::string line;
        std::getline(file, line, ',');
        int intNum = atoi(line.c_str());
        if (intNum != NULL){
            unsortedArray[index] = intNum;
            sortedArray[index] = intNum;
        }
        index++;


    }

    file.close();

    selectionSort(sortedArray);
}

void sorter::selectionSort(int sortedArray[]) {
    int low;
    int temp;
    for (int i = 0; i < (sizeOfArray - 1); ++i) {
        low = i;
        for (int j = i+1; j < sizeOfArray; ++j) {
            if (sortedArray[j] < sortedArray[low]) {
                low = j;
            }
        }
        temp = sortedArray[low];
        sortedArray[low] = sortedArray[i];
        sortedArray[i] = temp;

    }

    newCSVFile(sortedArray);
}

void sorter::newCSVFile(int sortedArray[]) {
    std::ofstream file;
    file.open(sortedPath, std::ios_base::app);
    for (int i = 0; i < sizeOfArray; ++i) {
        file << sortedArray[i] << ",";
    }

    file.close();
}

int sorter::pagesCounter() {
    int temp1 = sizeOfArray / 256;
    int temp2 = temp1 * 256;
    if (temp2 < sizeOfArray) {
        return temp1 + 1;
    } else {
        return temp1;
    }
}