#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Aluno_Pilha.h"
#include "Pilha.h"
#define MAX 100

struct aluno 
{
	int matricula;
	char nome[51];
	char curso[31];
};

struct pilha
{
	int tamanho;
	int quantidade;
	int topo;
	Aluno* vetor[MAX];
};

Pilha *nova(int tamanho)
{
	Pilha *pilha;
	pilha = NULL;
	if (tamanho > 0 && tamanho < MAX)
	{
		pilha = (Pilha*)malloc(sizeof(Pilha));
		if (pilha != NULL)
		{
			pilha->tamanho = tamanho;
			pilha->quantidade = 0;
			int i;
			for (i=0; i<MAX; i++)
			{
				pilha->vetor[i] = NULL;
			}
			pilha->topo = -1;
		}
	}
	return pilha;
}

void destroi(Pilha *pilha)
{
	if (pilha != NULL)
	{
		int i;
		if(pilha->quantidade > 0) 
		{
			for (i=0; i<pilha->quantidade; i++) 
			{
				libera(pilha->vetor[i]);
			}
		}
		free(pilha);
		pilha = NULL;
	}
}

int push(Pilha *pilha, Aluno *aluno)
{
	if(pilha != NULL && aluno != NULL && pilha->quantidade < pilha->tamanho)
	{
		pilha->vetor[pilha->quantidade] = (Aluno *) malloc(size());
		if(pilha->vetor[pilha->quantidade] != NULL)
		{
			int matricula;
			char nome[50];
			char curso[30];
			acessa(aluno, &matricula, nome, curso);
			atribui(pilha->vetor[pilha->quantidade], matricula, nome, curso);
			pilha->quantidade++;
			pilha->topo++;
			return 1;
		}
	}
	return 0;
}

Aluno* pop(Pilha *pilha)
{
	Aluno* aux;
	aux = NULL;
	if (pilha != NULL && pilha->quantidade > 0)
	{
		int mat;
		char nome[50];
		char curso[30];
		acessa(pilha->vetor[pilha->topo], &mat, nome, curso);
		atribui(aux, mat, nome, curso);
		libera(pilha->vetor[pilha->topo]);
		pilha->topo--;
		pilha->quantidade--;
	}
	return aux;
}

Aluno *top(Pilha *pilha)
{
	Aluno* aux;
	aux = NULL;
	if (pilha != NULL && pilha->quantidade > 0)
	{
		int matricula;
		char nome[50];
		char curso[30];
		acessa(pilha->vetor[pilha->topo], &matricula, nome, curso);
		atribui(aux, matricula, nome, curso);
	}
	return aux;
}

int cheia(Pilha *pilha)
{
	return pilha->quantidade == pilha->tamanho;
}

int tamanho(Pilha *pilha)
{
	return pilha->quantidade;
}
