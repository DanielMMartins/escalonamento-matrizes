
#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include "fracao.hpp"
using namespace std;

struct matriz{
    fracao** mat;
    int rows, col;

    matriz(int m, int n);

    void matIrredutivel();
    void rowIrredutivel(int i);
    void colIrredutivel(int j);

    void scanMatriz();
    void printMatriz();
    
    void sumRows(int a, int b);
    void subtractRows(int a, int b);
    void multiplyRows(int a, int b);
    void divideRows(int a, int b);
    
    void multiplyRowByInt(int a, int k);
    void divideRowByInt(int a, int k);
    
    void multiplyRowByFraction(int i, int a, int b);
    void divideRowByFraction(int i, int a, int b);

    void sumCols(int j1, int j2);

    void multiplyColByFraction(int j, int a, int b);

    void matReceive(int i, int j, int num, int den);
    void matReceive(int i, int j, int num);
};

matriz multiplyMat(matriz a, matriz b);

#endif