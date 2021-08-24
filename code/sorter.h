#ifndef EXTRACLASE_1_DATOS_II_SORTER_H
#define EXTRACLASE_1_DATOS_II_SORTER_H


#include <fstream>


class sorter {
private:
     std::string unsortedPath;
     std::string sortedPath;
     int sizeOfArray;
     int sizeOfFile;
     int dataCounter(int sizeOption);
     int pages;
     void selectionSort(int unsortedArray[]);
     void newCSVFile(int sortedArray[]);
     int pagesCounter();

public:
    sorter(const std::string &oldLocation, const std::string &newLocation);
    void execute();


};


#endif
