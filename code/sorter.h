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

     int dataCounter(int sizeOption, int page1, int page2);
     void selectionSort(int unsortedArray[], int index);
     void newCSVFile(int sortedArray[], int index);
     int pagesCounter();
     int setArraySize(int page1, int page2);

public:
    sorter(const std::string &oldLocation, const std::string &newLocation);
    void execute();

};


#endif
