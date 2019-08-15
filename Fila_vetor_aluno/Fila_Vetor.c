#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila_Vetor.h"
#include "Aluno_Fila_Vetor.h"

struct aluno
{
	int matricula;
	char nome;
	char curso;
};

struct fila
{
	int tam;
	int nalunos;
	int inicio;
	int fim;
	Aluno **fi;
};

Fila* nova(int tamanho)
{
	Fila* f;
	Aluno *a;
	if (tamanho <= 0)
	{
		printf("Tamanho invalido");
		exit(1);
	}
	a = (Aluno*)malloc(tamanho*sizeof(Aluno));
	if (a == NULL)
	{
		printf("Memoria insuficente.\n");
		exit(1);
	}
	f->fi = a;
	f->nalunos = 0;
	f->inicio = 0;
	f->fim = -1;
	return f;
}
void destroi(Fila *fila)
{
	free(fila);
}
int adiciona(Fila *fila, Aluno *aluno)
{
	if (cheia(fila) == 1)
	{
		printf("Fila cheia.\n");
		return 0;
		exit(1);
	}
	if (fila->fim == fila->tam - 1)
	{
		fila->fim = -1;
	}
	fila->fim++;
	fila->fi[fila->fim] = aluno;
	fila->nalunos++;
	return 1;
}
int remove(Fila *fila)
{
	if (fila->nalunos == 0)
	{
		printf("Fila vazia.\n");
		return 0;
	}
	else
	{
		if (fila->inicio == fila->tam - 1)
		{
			fila->inicio = 0;
		}
		fila->inicio++;
		fila->nalunos--;
		return 1;
	}
}
Aluno* busca(Fila *fila, int matricula)
{
	int i,ok;
	ok = 0;
	for (i=0;i<fila->tam;i++)
	{
		if (fila->fi[i]->matricula == matricula)
		{
			return fila->fi[i];
			ok = 1;
		}
	}
	if (ok == 0)
	{
		return NULL;
	}
	
}
int cheia(Fila *fila)
{
	if (fila->nalunos == fila->tam)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
