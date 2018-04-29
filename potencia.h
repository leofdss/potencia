#define TRUE 1
#define FALSE 0

typedef struct p Potencia;

struct p{
    float polar[2];
    float retangular[2];
    float fp;
    float tensao;
    float frequencia;
    float rendimento;
    float capacitor;
    float corrente;
};

void convertPolar(Potencia *potencia);
void convertRetangular(Potencia *potencia);
void printPotencia(Potencia *potencia);
Potencia *scanfPotencia();
void correcao(Potencia *potencia);
