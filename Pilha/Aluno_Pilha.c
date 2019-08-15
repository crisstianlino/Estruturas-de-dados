#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Aluno_Pilha.h"

struct aluno {
	int matricula;
	char nome[51];
	char curso[31];
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

int size() {
	return sizeof(Aluno);
}

