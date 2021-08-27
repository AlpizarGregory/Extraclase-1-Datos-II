#ifndef EXTRACLASE_1_DATOS_II_SORTER_H
#define EXTRACLASE_1_DATOS_II_SORTER_H


#include <fstream>


class sorter {
private:
    std::string unsortedPath;
    std::string sortedPath;
    int sizeOfArray;
    int sizeOfFile;
    int pages;
    int standardArray[512];
    int littlestInt;
    int lastPos;

    int dataCounter();
    void selectionSort(int counter4Ints);
    void newCSVFile(int sizeOfArr);
    int pagesCounter();

public:
    sorter(const std::string &oldLocation, const std::string &newLocation);
    void execute();

};


#endif
