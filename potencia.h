#define TRUE 1
#define FALSE 0

typedef struct p Potencia;

struct p{
    double polar[2];
    double retangular[2];
    double potenciaMotor;
    double fp;
    int adiantado;
    double tensao;
    double frequencia;
    double rendimento;
    double capacitor;
    double corrente;
};

Potencia potencia(Potencia potencia);

Potencia convertPolar(Potencia potencia);
Potencia convertRetangular(Potencia potencia);
void printPotencia(Potencia potencia);
Potencia scanfPotencia();

Potencia capacitor(Potencia potencia);
