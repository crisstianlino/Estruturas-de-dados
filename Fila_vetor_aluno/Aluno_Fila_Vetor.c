#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno_Fila_Vetor.h"

struct aluno
{
	int matricula;
	char nome;
	char curso;
};

Aluno *novo(int matricula, char *nome, char *curso)
{
	Aluno* a;
	if (matricula < 0 || strlen(nome) > 50 || strlen(curso) > 30)
	{
		printf("Dados invalidos.\n");
		exit(1);
	}
	a = (Aluno*)malloc(sizeof(Aluno));
	if (a == NULL)
	{
		printf("Memoria insuficiente.\n");
		exit(1);
	}
	a->matricula = matricula;
	a->nome = nome;
	a->curso = curso;
	return a;
}

void libera(Aluno *aluno)
{
	free(aluno);
}

void acessa(Aluno *aluno, int *matricula, char *nome, char *curso)
{
	*matricula = aluno->matricula;
	*nome = aluno->nome;
	*curso = aluno->curso;
}

void atribui(Aluno *aluno, int matricula, char *nome, char *curso)
{
	if (matricula < 0 || strlen(nome) > 50 || strlen(curso) > 30)
	{
		printf("Dados invalidos.\n");
		exit(1);
	}
	aluno->matricula = matricula;
	aluno->nome = nome;
	aluno->curso = curso;
}
