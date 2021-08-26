#include "PagedArray.h"
#include <ctime>

PagedArray::PagedArray() {
//    firstNumPos = pageNum * 256;
//    lastNumPos = (pageNum + 1) * 256;
}

int& PagedArray::operator[](int pageNum) {
    int firstNumPos = pageNum * 256;
    int lastNumPos = (pageNum + 1) * 256;
}

int * PagedArray::getArray(int number) {
    int newArray[number];
    for (int i = 0; i < number; ++i) {
        newArray[i] = i*2;
        printf("%d", i*2);
    }
    printf("End of PagedArray");
    return newArray;
}