#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "potencia.h"

int main()
{
    Motor motor;
    motor = dados();
    motor = processamentoDados(motor);
    print(motor);
    return 0;
};
