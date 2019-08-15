#include <stdio.h>
#include <string.h>
#include "ABB.h"
#define MAX 50

struct no
{
	int chave;
	char conteudo;
	No *esq;
	No *dir;
};

No *criaNo(int chave, char conteudo)
{
	No* novo;
	novo = NULL;
	novo = (No*)malloc(sizeof(No));
	novo->chave = chave;
	novo->conteudo = conteudo;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

void liberaNo(No *no)
{
	if (no != NULL)
	{
		liberaNo(no->esq);
		liberaNo(no->dir);
		free(no);
	}
	no = NULL;
}

int chaveNo(No *no)
{
	if (no != NULL)
	{
		return no->chave;
	}
	return NULL;
}

char conteudoNo(No *no)
{
	if (no != NULL)
	{
		return no->conteudo;
	}
	return NULL;
}

void insereNo(No *raiz, No *no)
{
	No *y, *x;
	y = NULL;
	x = raiz;
	while (x != NULL)
	{
		y = x;
		if (no->chave < x->chave)
		{
			x = x->esq;
		}
		else
		{
			x = x->dir;
		}
	}
	if (y == NULL)
	{
		raiz = no;
	}
	else if (no->chave < y->chave)
	{
		y->esq = no;
	}
	else
	{
		y->dir = no;
	}
}

No *buscaNo(No *raiz, int chave)
{
	if (raiz == NULL || raiz->chave == chave)
	{
		return raiz;
	}
    if (raiz->chave > chave)
    {
		return buscaNo(raiz->esq, chave);
    }
    else
    {
		return buscaNo(raiz->dir, chave);
	}
}

No *removeNo(No *raiz, int chave)
{
	No *filho, *n_raiz;
	if (!raiz)
	{
		return NULL;
	}
	if (raiz->chave == chave)
	{
		if (raiz->dir) 
		{
			n_raiz = raiz->dir;
			filho = raiz->dir;
			while(filho->esq)
			{
				filho = filho->esq;
			}
			filho->esq = raiz->esq;
			free(raiz);
			return n_raiz;
		} 
		else
		{
			n_raiz = raiz->esq;
			free(raiz);
			return n_raiz;
		}

	} 
	else if (chave > raiz->chave)
	{
		raiz->dir = removeNo(raiz->dir, chave);
	}
	else
	{
		raiz->esq = removeNo(raiz->esq, chave);
	}
	return raiz;
}

int altura(No *raiz)
{
	int u, v;
    if (raiz == NULL)
    {
		return -1;
	} 
    u = altura(raiz->esq);
    v = altura(raiz->dir);
    if (u > v)
    {
		return u+1;
	}
    else
    {
		return v+1;
	}
}

int numero(No *raiz)
{
	if (raiz = NULL)
	{
		return 0;
	}
	return numero(raiz->esq) + numero(raiz->dir) + 1;
}

char *preOrdem(No *no)
{
	char aux[MAX];
	if (no == NULL)
	{
		return NULL;
	}
	strcat(aux, no->conteudo); 
    preOrdem(no->esq);
    preOrdem(no->dir);
}

char *ordem(No *no)
{
	char aux[MAX];
	if (no == NULL)
	{
		return NULL;
	}
    preOrdem(no->esq);
    strcat(aux, no->conteudo); 
    preOrdem(no->dir); 
}

char *posOrdem(No *no)
{
	char aux[MAX];
	if (no == NULL)
	{
		return NULL;
	}
    posOrdem(no->esq);
    posOrdem(no->dir);
    strcat(aux, no->conteudo); 
}
