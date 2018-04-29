#include "potencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265359

void convertPolar(Potencia *potencia){
    float angulo, modulo;
    angulo = atan(potencia->retangular[1] / potencia->retangular[0]);
    modulo = sqrt(pow(potencia->retangular[0],2) + pow(potencia->retangular[1],2));
    potencia->polar[0] = modulo;
    potencia->polar[1] = angulo;
}
void convertRetangular(Potencia *potencia){
    float real, imaginario;
    real = potencia->polar[0] * cos(potencia->polar[1]);
    imaginario = potencia->polar[0] * sin(potencia->polar[1]);
    potencia->retangular[0] = real;
    potencia->retangular[1] = imaginario;
}
void printPotencia(Potencia *potencia){}

Potencia *scanfPotencia(){
    Potencia *potencia;
    printf("Qual a potencia ativa do motor?\n");
    scanf("%f\n", &potencia->retangular[0]);
    prinf("Qual o fator de potencia do motor?\n");
    scanf("%f\n", &potencia->fp);
    printf("Qual e o potencial eletrico do motor?\n");
    scanf("%f\n", &potencia->tensao);
    prinf("0 para atrasado e um 1 para adiantado");
    printf("Qual a frequencia?\n");
    scanf("%f\n", &potencia->frequencia);
    printf("Qual o rendimento do motor?\n");
    scanf("%f/n", &potencia->rendimento);

    potencia->polar[1] = acos(potencia->fp);
    potencia->retangular[1] = potencia->retangular[0] * tan(potencia->polar[1]);
    potencia->polar[0] = sqrt(pow(potencia->retangular[0],2) + pow(potencia->retangular[1],2));
    potencia->corrente = potencia->retangular[0] / potencia->tensao;

    return potencia;
}

void correcao(Potencia *potencia){
    float c;
    c = potencia->retangular[1] / (2 * pi * pow(potencia->tensao,2));
    potencia->capacitor = c;
}
