#include "Aluno_Pilha_Encadeada.h"

typedef struct pilha Pilha;

Pilha *nova(int tamanho);

void destroi(Pilha *pilha);

int push(Pilha *pilha, Aluno *aluno);

Aluno* pop(Pilha *pilha);

Aluno *top(Pilha *pilha);

int cheia(Pilha *pilha);

int tamanho(Pilha *pilha);
