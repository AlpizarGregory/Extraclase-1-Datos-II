#include "sorter.h"



sorter::sorter(const std::string &oldLocation, const std::string &newLocation) {
    unsortedPath = oldLocation;
    sortedPath = newLocation;
    sizeOfArray = 0;
    sizeOfFile = sorter::dataCounter();
    pages = pagesCounter();
    standardArray[0] = 0;
    littlestInt = -1;
    lastPos = 0;
}

int sorter::dataCounter() {
    std::ifstream file;
    file.open(unsortedPath);
    int counter4Ints = 0;
    int counter4Pages = 0;

    while (file.good()) {
        std::string line;
        std::getline(file, line, ',');
        if (line != ""){
            counter4Ints ++;
        }
    }

    file.close();

    return counter4Ints;

}

void sorter::execute() {
    for (int i = 0; i < pages; ++i) {
        std::ifstream file;
        file.open(unsortedPath);
        int counter4Ints = 0;

        while (file.good() && counter4Ints<256) {
            std::string line;
            std::getline(file, line, ',');
            int intNum = atoi(line.c_str());
            if (intNum != NULL && counter4Ints<256 && intNum>littlestInt) {
                standardArray[counter4Ints] = intNum;
                counter4Ints++;

            }

            lastPos++;

        }


        for (int j = 0; j < pages; ++j) {

            int arrayLenght = counter4Ints;
            while (file.good() && arrayLenght<512) {
                std::string line;
                std::getline(file, line, ',');
                int intNum = atoi(line.c_str());

                if (intNum != NULL && arrayLenght<512 && intNum>littlestInt) {
                    standardArray[arrayLenght] = intNum;
                    arrayLenght++;

                }
            }

            sizeOfArray = arrayLenght;
            selectionSort(arrayLenght);

        }
        file.close();
        printf("%d, ", littlestInt);
        littlestInt = standardArray[sizeOfArray-1];

        newCSVFile(sizeOfArray);

    }
}

void sorter::selectionSort(int counter4Ints) {
    int low;
    int temp;
    for (int i = 0; i < (counter4Ints - 1); ++i) {
        low = i;
        for (int j = i+1; j < counter4Ints; ++j) {
            if (standardArray[j] < standardArray[low]) {
                low = j;
            }
        }
        temp = standardArray[low];
        standardArray[low] = standardArray[i];
        standardArray[i] = temp;

    }

}

void sorter::newCSVFile(int sizeOfArr) {
    std::ofstream file;
    file.open(sortedPath, std::ios_base::app);
    for (int i = 0; i < sizeOfArr; ++i) {
        file << standardArray[i] << ",";
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