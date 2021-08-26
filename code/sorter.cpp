#include "sorter.h"



sorter::sorter(const std::string &oldLocation, const std::string &newLocation) {
    unsortedPath = oldLocation;
    sortedPath = newLocation;
    sizeOfArray = 0;
    sizeOfFile = sorter::dataCounter(2,0,0);
    pages = pagesCounter();
}

int sorter::setArraySize(int page1, int page2) {
    sizeOfArray = dataCounter(1, page1, page2);
}

int sorter::dataCounter(int sizeOption, int page1, int page2) {
    std::ifstream file;
    file.open(unsortedPath);
    int counter4Ints = 0;
    int counter4Pages = 0;

    if (sizeOption == 1) {
        int firstPage = page1 * 256;
        int secondPage = page2 * 256;
        while (file.good()) {
            std::string line;
            std::getline(file, line, ',');
            if (line != "" && counter4Pages>=firstPage && counter4Pages<secondPage && counter4Ints<1536){
                counter4Ints ++;
            }
            counter4Pages ++;
        }
    } else {
        while (file.good()) {
            std::string line;
            std::getline(file, line, ',');
            if (line != ""){
                counter4Ints ++;
            }
        }
    }


    file.close();


    return counter4Ints;

}

void sorter::execute() {
    for (int i = 0; i < pages; ++i) {
        std::ifstream file;
        setArraySize(i, i+2);
        int unsortedArray[sizeOfArray];
        file.open(unsortedPath);
        int actualPage = i * 256;
        int counter4Ints = 0;
        int counter4Pages = 0;

        while (file.good()) {
            std::string line;
            std::getline(file, line, ',');
            int intNum = atoi(line.c_str());
            if (intNum != NULL && counter4Pages>=actualPage && counter4Pages<(actualPage+sizeOfArray)){
                unsortedArray[counter4Ints] = intNum;
                counter4Ints++;
            }
            counter4Pages++;
        }

        file.close();

        selectionSort(unsortedArray, i);


    }
}

void sorter::selectionSort(int sortedArray[], int index) {
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

    newCSVFile(sortedArray, index);
}

void sorter::newCSVFile(int sortedArray[], int index) {
    std::ofstream file;
    file.open(sortedPath, std::ios_base::app);
    if (index == 0) {
        for (int i = 0; i < sizeOfArray; ++i) {
            file << sortedArray[i] << ",";
        }
    } else {
        for (int i = 256; i < sizeOfArray; ++i) {
            file << sortedArray[i] << ",";
        }
    }

    file.close();
}

int sorter::pagesCounter() {
    int temp1 = sizeOfFile / 256;
    int temp2 = temp1 * 256;
    if (temp2 < sizeOfFile) {
        return temp1 + 1;
    } else {
        return temp1;
    }
}