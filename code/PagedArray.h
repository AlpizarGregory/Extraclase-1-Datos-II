#ifndef EXTRACLASE_1_DATOS_II_PAGEDARRAY_H
#define EXTRACLASE_1_DATOS_II_PAGEDARRAY_H

#include <fstream>

class PagedArray {
private:
    int& operator[](int pageNum);

public:
    PagedArray();
    int * getArray(int number);

};


#endif
