#include "sorter.h"



sorter::sorter(const std::string &oldLocation, const std::string &newLocation) {
    unsortedPath = oldLocation;
    sortedPath = newLocation;
    sizeOfArray = 0;
    sizeOfFile = sorter::dataCounter(2,0,0);
    pages = pagesCounter();
    standardArray[0] = 0;
    littlestInt = -1;
    lastPos = 0;
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
        file.open(unsortedPath);
        //        int actualPage = i;
        int counter4Ints = 0;
//        int counter4Pages = 0;
        while (file.good() && counter4Ints<256) {
            std::string line;
            std::getline(file, line, ',');
            int intNum = atoi(line.c_str());
            if (intNum != NULL && counter4Ints<256 && intNum>littlestInt) {
                standardArray[counter4Ints] = intNum;
                counter4Ints++;


            }

            lastPos++;
//            counter4Pages++;
        }

//        file.close();
        for (int j = 0; j < pages; ++j) {


//            file.open(unsortedPath);

//            int index = 0;
            int arrayLenght = counter4Ints;
            while (file.good() && arrayLenght<512) {
                std::string line;
                std::getline(file, line, ',');
                int intNum = atoi(line.c_str());
//                if (intNum != NULL && index>=lastPos) {
                if (intNum != NULL) {
                    if (arrayLenght<512 && intNum>littlestInt){
                        standardArray[arrayLenght] = intNum;
                        arrayLenght++;
                    }
//                    lastPos++;

                }
//                index++;
//                counter4Pages++;
            }

            sizeOfArray = arrayLenght;
            selectionSort(arrayLenght);
//            file.close();

        }
        file.close();
        printf("%d, ", littlestInt);
        littlestInt = standardArray[sizeOfArray-1];
//        printf("\n%d, %d, %d, %d", standardArray[counter4Ints-4],standardArray[counter4Ints-3],standardArray[counter4Ints-2],standardArray[counter4Ints-1]);

        newCSVFile(sizeOfArray);

    }
    //    for (int i = 0; i < pages; ++i) {
    //        std::ifstream file;
    //        setArraySize(i, i+1);
    ////        int unsortedArray[sizeOfArray];
    //        file.open(unsortedPath);
    //        int actualPage = i * 256;
    //        int counter4Ints = 0;
    //        int counter4Pages = 0;
    //
    //        while (file.good()) {
    //            std::string line;
    //            std::getline(file, line, ',');
    //            int intNum = atoi(line.c_str());
    //            if (intNum != NULL && counter4Pages<sizeOfFile && counter4Ints<256 && intNum>littlestInt) {
    //                standardArray[counter4Ints] = intNum;
    //                counter4Ints++;
    //            }
    ////
    //            counter4Pages++;
    //        }
    //
    //        file.close();
    //        int referenceSize = counter4Ints;
    //
    //        for (int j = 0; j < pages; ++j) {
    //            if (j!=i) {
    //                std::ifstream file;
    //                setArraySize(j, j+1);
    //                file.open(unsortedPath);
    //                int comparisonPage = j * 256;
    //                counter4Ints = 0;
    //                counter4Ints = referenceSize;
    //                counter4Pages = 0;
    //
    //                while (file.good()) {
    //                    std::string line;
    //                    std::getline(file, line, ',');
    //                    int intNum = atoi(line.c_str());
    //                    if (intNum != NULL && counter4Pages>=comparisonPage && counter4Pages<(comparisonPage+sizeOfArray) && intNum>littlestInt){
    //                        standardArray[counter4Ints] = intNum;
    //                        counter4Ints++;
    //                    }
    //                    counter4Pages++;
    //                }
    //
    //                file.close();
    //                sizeOfArray = 0;
    //                sizeOfArray = counter4Ints;
    //                selectionSort();
    //            }
    //            if (j == pages-1) {
    //                newCSVFile();
    //                littlestInt = 0;
    //                littlestInt = standardArray[sizeOfArray-1];
    //                printf("%d vs %d with size %d, ", littlestInt, standardArray[sizeOfArray-1], sizeOfArray);
    //            }
    //        }
    //
    //
    //
    //
    //    }
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

    //    newCSVFile();
}

void sorter::newCSVFile(int sizeOfArr) {
    std::ofstream file;
    file.open(sortedPath, std::ios_base::app);
    //    if (index == 0) {
    for (int i = 0; i < sizeOfArr; ++i) {
        file << standardArray[i] << ",";
    }
    //    } else {
    //        for (int i = 256; i < sizeOfArray; ++i) {
    //            file << sortedArray[i] << ",";
    //        }
    //    }

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