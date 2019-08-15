#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Aluno_Pilha_Encadeada.h"

struct aluno {
	int matricula;
	char nome[51];
	char curso[31];
	Aluno *prox;
	Aluno *ant;
};

int check(int matricula, char *nome, char *curso) {
	if(matricula >= 0) {
		if(nome != NULL && strlen(nome) <= 50) {
			if(curso != NULL && strlen(curso) <= 30) {
				return 1;
			}
		}
	}
	return 0;
}

Aluno *novo(int matricula, char *nome, char *curso) {
	Aluno *novo = NULL;
	if(check(matricula, nome, curso)) {
		novo = (Aluno *) malloc(sizeof(Aluno));
		if(novo != NULL) {
			novo->matricula = matricula;
			strcpy(novo->nome, nome);
			strcpy(novo->curso, curso);
			novo->prox = NULL;
			novo->ant = NULL;
		}
	}

	return novo;
}

void libera(Aluno *aluno) {
	if(aluno != NULL) {
		aluno->matricula = -1;
		strcpy(aluno->nome, "");
		strcpy(aluno->curso, "");
		free(aluno);
	}
}

void acessa(Aluno *aluno, int *matricula, char *nome, char *curso) {
	if(aluno != NULL && nome != NULL && curso !=NULL) {
		*matricula = aluno->matricula;
		strcpy(nome, aluno->nome);
		strcpy(curso, aluno->curso);
	}
}

void atribui(Aluno *aluno, int matricula, char *nome, char *curso) {
	if(aluno != NULL && check(matricula, nome, curso)) {
		aluno->matricula = matricula;
		strcpy(aluno->nome, nome);
		strcpy(aluno->curso, curso);
	}
}

Aluno *proximo(Aluno *aluno)
{
	if (aluno != NULL)
	{
		return aluno->prox;
	}
	return NULL;
}

void addproximo(Aluno *aluno, Aluno *proximo)
{
	if (aluno != NULL && proximo != NULL)
	{
		atribui(proximo,aluno->matricula,aluno->nome,aluno->curso);
	}
}

int size() {
	return sizeof(Aluno);
}
