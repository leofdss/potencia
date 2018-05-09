#include "potencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265359


Potencia convertPolar(Potencia potencia){
    float angulo, modulo;
    angulo = atan(potencia.retangular[1] / potencia.retangular[0]);
    modulo = sqrt(pow(potencia.retangular[0],2) + pow(potencia.retangular[1],2));
    potencia.polar[0] = modulo;
    potencia.polar[1] = angulo;
    return potencia;
}
Potencia convertRetangular(Potencia potencia){
    float real, imaginario;
    real = potencia.polar[0] * cos(potencia.polar[1]);
    imaginario = potencia.polar[0] * sin(potencia.polar[1]);
    potencia.retangular[0] = real;
    potencia.retangular[1] = imaginario;
    return potencia;
}
void printPotencia(Potencia potencia){
}

Potencia scanfPotencia(){

    Potencia potencia;
    double d;

    printf("Qual a potencia do motor? (HP) \n");
    scanf("%lf", &potencia.potenciaMotor);

    printf("Qual o fator de potencia do motor? \n");
    scanf("%lf", &potencia.fp);

    printf("0 para atrasado e um 1 para adiantado \n");
    scanf("%lf", &potencia.adiantado);

    printf("Qual e o potencial eletrico do motor? \n");
    scanf("%lf", &potencia.tensao);

    printf("Qual a frequencia? \n");
    scanf("%lf", &potencia.frequencia);

    printf("Qual o rendimento do motor? (%)\n");
    scanf("%lf", &potencia.rendimento);

    return potencia;
}

Potencia capacitor(Potencia potencia){
    double c, xc;

    if(potencia.adiantado == 1){
        potencia.polar[1] = -1 * acos(potencia.fp);
    }else{
        potencia.polar[1] = acos(potencia.fp);
    }

    potencia.retangular[0] = potencia.potenciaMotor * 746 / (potencia.rendimento / 100);

    potencia.retangular[1] = potencia.retangular[0] * tan(potencia.polar[1]);

    potencia.polar[0] = sqrt(pow(potencia.retangular[0],2) + pow(potencia.retangular[1],2));

    potencia.corrente = potencia.retangular[0] / potencia.tensao;

    xc = pow(potencia.tensao, 2) / potencia.retangular[1];

    c = 1 / (2 * pi * potencia.frequencia * xc);

    potencia.capacitor = c;

    return potencia;
}
