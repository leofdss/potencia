#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define pi 3.14159265359

typedef struct fp FatorPotencia;
struct fp
{
    float valor;
    int atrasado;
};

typedef struct pc PotenciaComplexa;
struct pc
{
    float ativa;    // W potencia consumida
    float reativa;  // VAR (L)
    float aparente; // VA
    float angulo;   //
};

typedef struct m Motor;
struct m
{
    float potencia;    // Potencia em HP
    float frequencia;  // Hz
    float tensao;      // V RMS
    float capacitor;   // uF
    float rendimento;  // %
    float corrente[2]; // A
    FatorPotencia fatorPotencia;
    PotenciaComplexa potenciaComplexa;
};

Motor dados()
{
    Motor motor;

    printf("---------------Correção de fator de potência par 1---------------\n\n");

    printf("Qual a potencia do motor? (HP) \n");
    scanf("%f", &motor.potencia);

    printf("Qual o fator de potencia do motor? \n");
    scanf("%f", &motor.fatorPotencia.valor);

    printf("1 para fator de potencia atrasado e um 0 para adiantado \n");
    scanf("%i", &motor.fatorPotencia.atrasado);

    printf("Qual e a tensao do motor? (V RMS)\n");
    scanf("%f", &motor.tensao);

    printf("Qual a frequencia? (Hz)\n");
    scanf("%f", &motor.frequencia);

    printf("Qual o eficiencia do motor? (%)\n");
    scanf("%f", &motor.rendimento);

    return motor;
}

Motor processamentoDados(Motor motor)
{
    int sinal, sinal2;

    if (motor.fatorPotencia.atrasado = 1)
        sinal = 1;
    else
        sinal = -1;

    motor.potenciaComplexa.angulo = sinal * (180 / pi) * acos(motor.fatorPotencia.valor);

    motor.potenciaComplexa.ativa = motor.potencia * 746 / (motor.rendimento / 100);
    motor.potenciaComplexa.aparente = motor.potenciaComplexa.ativa / motor.fatorPotencia.valor;
    motor.potenciaComplexa.reativa = motor.potenciaComplexa.ativa * tan(motor.potenciaComplexa.angulo * (pi / 180));

    motor.capacitor = pow(10, 6) * motor.potenciaComplexa.ativa *
                      (tan(motor.potenciaComplexa.angulo * (pi / 180))) /
                      (2 * pi * motor.frequencia * pow(motor.tensao, 2));

    motor.corrente[0] = motor.potenciaComplexa.ativa / (motor.tensao * motor.fatorPotencia.valor);
    motor.corrente[1] = -1 * motor.potenciaComplexa.angulo;

    return motor;
}

void print(Motor motor)
{
    system("clear");
    printf("---------------resultado---------------\n\n");
    printf("Potencia consumida: %.2f W\n", motor.potenciaComplexa.ativa);
    printf("Angulo: %.2f̣°\n", motor.potenciaComplexa.angulo);
    printf("Potencia aparente: %.2f VA\n", motor.potenciaComplexa.aparente);
    printf("Potencia reativa %.2f VAR (L)\n", motor.potenciaComplexa.reativa);
    printf("Corrente: %.2f L %.2f A\n",motor.corrente[0], motor.corrente[1]);
    printf("Capacitor: %.2f uF\n", motor.capacitor);
}

int main()
{
    Motor motor = dados();
    motor = processamentoDados(motor);
    print(motor);
    return 0;
};
