#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila_Encadeada.h"
#include "Aluno_Fila_Encadeada.h"

struct aluno
{
	int matricula;
	char nome;
	char curso;
};

struct fila
{
	int tamanho;
	Aluno* alunox;
	Fila *prox;
};

Fila *nova(int tamanho)
{
	Fila *f;
	f = NULL;
	if (tamanho <= 0)
	{
		return f;
	}
	f = (Fila*)malloc(sizeof(Fila));
	if (f != NULL)
	{
		f->alunox = NULL;
		f->tamanho = tamanho;
		f->prox = NULL;
	}
	return f;
}

void destroi(Fila *fila)
{
	while (fila != NULL)
	{
		fila == NULL;
		free(fila);
		fila = fila->prox;
	}
}

int adiciona(Fila *fila, Aluno *aluno)
{
	int i;
	Fila *x;
	if (cheia(fila) || fila == NULL || aluno == NULL)
	{
		return 0;
	}
	if (fila->alunox == NULL)
	{
		fila->alunox = aluno;
		return 1;
	}
	for (i=1;i==fila->tamanho;i++)
	{
		if (fila->prox == NULL)
		{
			x = nova(fila->tamanho);
			x->alunox = aluno;
			fila->prox = x;
			return 1;
		}
		fila = fila->prox;
	}
}

int retira(Fila *fila)
{
	if (fila == NULL)
	{
		return 0;
	}
	fila->alunox = NULL;
	if (fila->prox == NULL)
	{
		return 1;
	}
	fila = fila->prox;
	return 1;
}

Aluno *busca(Fila *fila, int matricula)
{
	Fila *x;
	x = fila;
	if (matricula > 0)
	{
		while (x != NULL)
		{
			if (x->alunox->matricula == matricula)
			{
				return x->alunox;
			}
			x = x->prox;
		}
	}
	return NULL;
}

int cheia(Fila *fila)
{
	int cont,i;
	cont = 0;
	Fila *x;
	x = fila;
	if (x == NULL || fila->alunox == NULL)
	{
		return 0;
	}
	for (i=1;i==fila->tamanho;i++)
	{
		if (x->alunox != NULL)
		{
			cont++;
		}
		x = x->prox;
	}
	if (cont == fila->tamanho)
	{
		return 1;
	}
	return 0;
}
