#include <iostream>
#include "fracao.hpp"
using namespace std;

int mdc(int a, int b){
    while(b!=0){
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int mmc(int a, int b){
    return abs(a*b)/mdc(a, b);
}




fracao::fracao(){
    numerador = 0;
    denominador = 1;
}

fracao::fracao(long long int a, long long int b){
    numerador = a;
    denominador = b;
    if(denominador == 0){
        cout << "Erro, denominador nao pode ser zero.\n Trocando valor do denominador por 1.";
        denominador = 1;   
    }
}
    
void fracao::irredutivel(){
    int d = mdc(numerador, denominador);
    numerador /= d;
    denominador /= d;
    if(denominador < 0){
        numerador*=-1;
        denominador*=-1;
    }
}

void fracao::soma(fracao f){
    int m = mmc(denominador, f.denominador);

    f.numerador *= m/f.denominador;
    numerador *= m/denominador;
    denominador = m;
    numerador += f.numerador;
}

fracao fracao::multiplica(fracao f){
    long long int num, den;
    num = numerador * f.numerador;
    den = denominador * f.denominador;
    if(den<0){
        num *= -1;
        den *= -1;
    }

    fracao g(f.numerador*numerador, f.denominador*denominador);
   
    g.irredutivel();
    return g;
}

void fracao::multiplicaPorInt(int k){
    numerador *= k;
    irredutivel();
}

void fracao::subtrai(fracao f){
    int m = mmc(denominador, f.denominador);

    f.numerador *= m/f.denominador;
    numerador *= m/denominador;
    denominador = m;
    numerador -= f.numerador;
}

fracao fracao::divide(fracao f){
    int num = numerador;
    int den = denominador;

    num *= f.denominador;
    den *= f.numerador;

    
    if(den<0){
        numerador *= -1;
        denominador *= -1;
    }

    fracao g(num, den);

    g.irredutivel();
    return g;
}

void fracao::dividePorInt(int k){
    denominador *= k;
    irredutivel();
}