#include "Aluno_Fila_Encadeada.h"

typedef struct fila Fila;

Fila *nova(int tamanho);

void destroi(Fila *fila);

int adiciona(Fila *fila, Aluno *aluno);

int retira(Fila *fila);

Aluno *busca(Fila *fila, int matricula);

int cheia(Fila *fila);
