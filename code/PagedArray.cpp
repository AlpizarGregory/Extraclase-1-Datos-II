#include "PagedArray.h"

PagedArray::PagedArray() {
//    firstNumPos = pageNum * 256;
//    lastNumPos = (pageNum + 1) * 256;
}

int& PagedArray::operator[](int pageNum) {
    int firstNumPos = pageNum * 256;
    int lastNumPos = (pageNum + 1) * 256;
}