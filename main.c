#include "potencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265359

int main()
{
    Potencia potencia;

    potencia = scanfPotencia();

    potencia = capacitor(potencia);

    printf("Capacitor: %lf", potencia.capacitor);

    return 0;
}
