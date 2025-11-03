#ifndef FRACAO_HPP
#define FRACAO_HPP

int mdc(int a, int b);
int mmc(int a, int b);

struct fracao{
    long long int numerador;
    long long int denominador;

    fracao();
    fracao(long long int a, long long int b);
    
    void irredutivel();
    void soma(fracao f);
    fracao multiplica(fracao f);
    void multiplicaPorInt(int k);
    void subtrai(fracao f);
    fracao divide(fracao f);
    void dividePorInt(int k);
};

#endif