#include <iostream>
#include "matriz.hpp"


matriz::matriz(int m, int n){
    rows = m; col = n;
    mat = new fracao*[m];
    for(int i=0; i<m; i++){
        mat[i] = new fracao[n];
    }
}

void matriz::matIrredutivel(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<col; j++){
            mat[i][j].irredutivel(); 
        }
    }
}

void matriz::rowIrredutivel(int i){
    i--;
    if(i< 0 || i >=rows){
        return;
    }
    for(int j=0; j<col; j++){
        mat[i][j].irredutivel();
    }
}

void matriz::colIrredutivel(int j){
    j--;
    if(j<0 || j>=col){
        return;
    }
    for(int i=0; i<rows; i++){
        mat[i][j].irredutivel();
    }
}

void matriz::scanMatriz(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<col; j++){
            cin >> mat[i][j].numerador >> mat[i][j].denominador;
            
        }
    }
}

void matriz::printMatriz(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<col; j++){
            if(mat[i][j].denominador == 1){
                cout << mat[i][j].numerador << " ";
                continue;
            }
            cout << mat[i][j].numerador << "/" << mat[i][j].denominador << " ";
                
        }
        cout << "\n";
    }
}

void matriz::sumRows(int a, int b){
    a--, b--;
    if(a < 0 || a>=rows || b < 0 || b>=rows){
        cout << "Entrada de linhas invalidas.\n";
        return;
    }
        
    for(int j=0; j<col; j++){
        mat[a][j].soma(mat[b][j]);
    }
    rowIrredutivel(a);
}

void matriz::subtractRows(int a, int b){
    a--, b--;
    if(a < 0 || a>=rows || b < 0 || b>=rows){
        cout << "Entrada de linhas invalidas.\n";
        return;
    }

    for(int j=0; j<col; j++){
        mat[a][j].subtrai(mat[b][j]);
    }
    rowIrredutivel(a);
}

void matriz::multiplyRows(int a, int b){
    a--, b--;
    if(a < 0 || a>=rows || b < 0 || b>=rows){
        cout << "Entrada de linhas invalidas.\n";
        return;
    }

    for(int j=0; j<col; j++){
        mat[a][j].multiplica(mat[b][j]);
    }
    rowIrredutivel(a);
}

void matriz::divideRows(int a, int b){
    a--, b--;
    if(a < 0 || a>=rows || b < 0 || b>=rows){
        cout << "Entrada de linhas invalidas.\n";
        return;
    }

    for(int j=0; j<col; j++){
        mat[a][j].divide(mat[b][j]);
    }
    rowIrredutivel(a);
}

void matriz::multiplyRowByInt(int a, int k){
    a--;
    if(a < 0 || a>=rows){
        cout << "Entrada de linhas invalidas.\n";
        return;
    }
        
    for(int j=0; j<col; j++){
        mat[a][j].multiplicaPorInt(k);
    }
    rowIrredutivel(a);
}

void matriz::divideRowByInt(int a, int k){
    a--;
    if(a < 0 || a>=rows){
        cout << "Entrada de linhas invalidas.\n";
        return;
    }
    if(k==0){
        cout << "Nao e possivel dividir por zero.\n";
        return;
    }

    for(int j=0; j<col; j++){
        mat[a][j].dividePorInt(k);
    }
    rowIrredutivel(a);
}

void matriz::multiplyRowByFraction(int i, int a, int b){
    i--;
    if(i<0 || i>=rows){
        return;
    }

    fracao f(a, b);

    for(int j=0; j<col; j++){
        mat[i][j] = mat[i][j].multiplica(f);
        
    }
    rowIrredutivel(i);
}

void matriz::sumCols(int j1, int j2){
    j1--, j2--;
    if(j1 < 0 || j1>=col || j2 < 0 || j2 >= col){
        cout << "Entrada de colunas invalidas.\n";
        return;
    }
        
    for(int i=0; i<rows; i++){
        mat[i][j1].soma(mat[i][j2]);
    }
    rowIrredutivel(j1);
}

void matriz::multiplyColByFraction(int j, int a, int b){
    j--;
    if(j<0 || j>=rows){
        return; 
    }

    fracao f(a,b);

    for(int i=0; i<rows; i++){
        mat[i][j] = mat[i][j].multiplica(f);
    }
    colIrredutivel(j);
}

void matriz::divideRowByFraction(int i, int a, int b){
    i--;
    if(i<0 || i>rows){
        return;
    }

    fracao f(a, b);

    for(int j=0; j<col; j++){
        mat[i][j] = mat[i][j].divide(f);
    }
    rowIrredutivel(i);
}

void matriz::matReceive(int i, int j, int num, int den){
    i--; j--;
    if(i<0 || i>=rows || j<0 || j>=col){
        return;
    }

    mat[i][j].numerador = num;
    mat[i][j].denominador = den;
    mat[i][j].irredutivel();
}

void matriz::matReceive(int i, int j, int num){
    i--; j--;
    if(i<0 || i>=rows || j<0 || j>=col){
        return;
    }

    mat[i][j].numerador = num;
    mat[i][j].denominador = 1;
    mat[i][j].irredutivel();
}

matriz multiplyMat(matriz a, matriz b){
    if(a.col != b.rows){
        cout << "Nao e possivel multiplicar essas duas matrizes.\n";
        matriz c(1, 1);
        return c;
    }

    matriz c(a.rows, b.col);
    for(int i=0; i<a.rows; i++){
        for(int j=0; j<b.col; j++){
            for(int k = 0; k<a.col; k++){
                c.mat[i][j].soma(a.mat[i][k].multiplica(b.mat[k][j]));
            }
        }
    }
    c.matIrredutivel();
    return c;
}