#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Aluno_Pilha_Encadeada.h"
#include "Pilha_Encadeada.h"

struct aluno 
{
	int matricula;
	char nome[51];
	char curso[31];
	Aluno *prox;
	Aluno *ant;
};

struct pilha
{
	int tamanho;
	int quantidade;
	Aluno *topo;
	Aluno *proximo;
};

Pilha *nova(int tamanho)
{
	Pilha *pilha;
	pilha = NULL;
	if (tamanho > 0)
	{
		pilha = (Pilha*)malloc(sizeof(Pilha));
		if (pilha != NULL)
		{
			pilha->tamanho = tamanho;
			pilha->quantidade = 0;
			pilha->proximo = NULL;
			pilha->topo = NULL;
		}
	}
	return pilha;
}

void destroi(Pilha *pilha)
{
	if (pilha != NULL)
	{
		Aluno* aux;
		while (pilha->proximo != NULL)
		{
			aux = pilha->proximo->prox;
			libera(pilha->proximo);
			pilha->proximo = aux;
		}
		free(pilha);
	}
}

int push(Pilha *pilha, Aluno *aluno)
{
	if(pilha != NULL && aluno != NULL && pilha->quantidade < pilha->tamanho)
	{
		aluno->ant = pilha->topo;
		pilha->topo = aluno;
		pilha->topo->prox = NULL;
		pilha->quantidade++;
		if (pilha->proximo == NULL)
		{
			pilha->proximo = aluno;
		}
		return 1;
	}
	return 0;
}

Aluno* pop(Pilha *pilha)
{
	Aluno* aux;
	Aluno *aux2;
	aux = NULL;
	if (pilha != NULL && pilha->quantidade > 0)
	{
		int mat;
		char nome[50];
		char curso[30];
		acessa(pilha->topo, &mat, nome, curso);
		atribui(aux, mat, nome, curso);
		aux2 = pilha->topo->ant;
		libera(pilha->topo);
		pilha->topo = aux2;
		pilha->topo->prox = NULL;
		pilha->quantidade--;
	}
	return aux;
}

Aluno *top(Pilha *pilha)
{
	if (pilha != NULL && pilha->quantidade > 0)
	{
		return pilha->topo;
	}
}

int cheia(Pilha *pilha)
{
	return pilha->quantidade == pilha->tamanho;
}

int tamanho(Pilha *pilha)
{
	return pilha->quantidade;
}
