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


#define true 1
#define false 0
#define pi 3.14159265359


Motor dados();
Motor processamentoDados(Motor motor);
void print(Motor motor);