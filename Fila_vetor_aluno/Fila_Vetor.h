#include "Aluno_Fila_Vetor.h"

typedef struct fila Fila;

Fila* nova(int tamanho);

void destroi(Fila *fila);

int adiciona(Fila *fila, Aluno *aluno);

int remove(Fila *fila);

Aluno *busca(Fila *fila, int matricula);

int cheia(Fila *fila);
