/**
 * @file sorter.h
 * @version 1.0
 * @date 27/08/2021
 * @author AlpizarGregory
 * @title Lector y ordenador de números
 * @brief Lee, ordena y reescribe los números
 */

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

    /**
     * @brief Cuenta la cantidad de enteros en el archivo
     * @return Cantidad de enteros
     */
    int dataCounter();

    /**
     * @brief Ordena un arreglo de números
     * @param counter4Ints Indica el tamaño del arreglo
     */
    void selectionSort(int counter4Ints);

    /**
     * @brief Escribe los enteros ordenados en un nuevo archivo
     * @param sizeOfArr Indica la cantidad de enteros a escribir
     */
    void newCSVFile(int sizeOfArr);

    /**
     * @brief Determina la cantidad de páginas que posee el archivo
     * @return La cantidad de páginas
     */
    int pagesCounter();

public:

    /**
     * @brief Counstructor de la clase
     * @param oldLocation Dirección del archivo desordenado
     * @param newLocation Dirección del archivo ordenado
     */
    sorter(const std::string &oldLocation, const std::string &newLocation);

    /**
     * @brief Compara todas las páginas y llama a los demás métodos
     */
    void execute();

};


#endif
