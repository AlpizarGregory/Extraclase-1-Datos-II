#include <iostream>
#include <fstream>
#include "sorter.h"

#include <iomanip>

using namespace std;


int main() {
    string unsortedFile = "D:\\OneDrive - Estudiantes ITCR\\TEC\\2021 II Semestre\\Algoritmos y Estructuras de Datos II\\Extraclase 1\\Extraclase-1-Datos-II\\data\\unsortedInts.csv";
    string sortedFile = "D:\\OneDrive - Estudiantes ITCR\\TEC\\2021 II Semestre\\Algoritmos y Estructuras de Datos II\\Extraclase 1\\Extraclase-1-Datos-II\\data\\sortedInts.csv";
    sorter newSorter(unsortedFile, sortedFile);
    newSorter.execute();

}
