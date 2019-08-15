#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno_Fila_Encadeada.h"

struct aluno
{
	int matricula;
	char nome[51];
	char curso[31];
};

int verifica(int matricula, char *nome, char *curso)
{
	if (matricula <= 0 || strlen(nome) > 50 || strlen(curso) > 30 || nome == NULL || curso == NULL)
	{
		return 0;
	}
	return 1;
}
Aluno *novo(int matricula, char *nome, char *curso)
{
	Aluno* a;
	a = NULL;
	if (verifica(matricula,nome,curso))
	{
		a = (Aluno*)malloc(sizeof(Aluno));
		if (a!=NULL)
		{
			a->matricula = matricula;
			strcpy(a->nome[51], nome);
			strcpy(a->curso[31], curso);
		}
	}
		return a;
}

void libera(Aluno *aluno)
{
	if (aluno != NULL)
	{
		free(aluno);
	}
}

void acessa(Aluno *aluno, int *matricula, char *nome, char *curso)
{
	if(aluno != NULL && nome != NULL && curso != NULL) 
	{
		*matricula = aluno->matricula;
		strcpy(nome, aluno->nome);
		strcpy(curso, aluno->curso);
	}
}

void atribui(Aluno *aluno, int matricula, char *nome, char *curso)
{
	if (aluno != NULL && verifica(matricula, nome, curso))
	{
		aluno->matricula = matricula;
		strcpy(aluno->nome, nome);
		strcpy(aluno->curso, curso);
	}
}

int size()
{
	return sizeof(Aluno);
}
