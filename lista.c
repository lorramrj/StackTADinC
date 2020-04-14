#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
	void *info;
	struct no *prox;
};

struct lista {
	int tam;
	No *ini;
	No *fin;
	No *corr;
};

Lista* lst_cria(void)
{
	Lista* list = (Lista*) malloc(sizeof(Lista));
	if (list == NULL)
	{
		printf("Insufficient Memory.\n");
		return NULL;
	}

	list->tam = 0;
	list->ini = NULL;
	list->fin = NULL;
	list->corr = NULL;
	return list;
}

int lst_vazia(Lista *lst)
{
	if (lst->tam)
		return 0;
	return 1;
}

void lst_insIni(Lista *lst, void *val)
{
	No *no = (No*) malloc(sizeof(No));
	if (no == NULL)
		exit(1);

	no->info = val;
	no->prox = lst->ini;

	lst->ini = no;

	lst->tam++;
	if(lst->tam == 1) 
	{
		lst->fin = lst->ini;
	}

}

void lst_insFin(Lista *lst, void *val)
{
	int* teste = NULL;
	No* no = (No *) malloc(sizeof(No));

	if (no == NULL)
		exit(1);
	
	no->info = val;
    no->prox = NULL;

	if(lst->tam == 0)
	{
		lst->fin = lst->ini = no;
	}

	else
	{
		lst->fin->prox = no;
		lst->fin= lst->fin->prox;
	}

	lst->tam++;
}

void* lst_retIni(Lista *lst)
{
	No *aux = NULL;

	if(lst_vazia(lst))
	{
		return NULL;
	}

	if(lst->tam == 1)
	{
		aux = lst->ini;
		lst->ini = lst->fin = lst->corr = NULL;
		lst->tam--;
		
		return aux->info;
	}

	aux = lst->ini;

	lst->ini = lst->ini->prox;
	lst->tam--;

	return aux->info;
}

void* lst_retFin(Lista *lst)
{
	No *p  = NULL;
	No *aux = NULL;

	if(lst_vazia(lst))
	{
		return NULL;
	}

	if(lst->tam == 1)
	{
		lst->ini = lst->fin = lst->corr = NULL;
		lst->tam--;
		
		return aux->info;
	}

	p = lst->ini;
	while(p->prox != lst->fin)
	 p=p->prox;

	aux = lst->fin;

    lst->fin = p;
	lst->fin->prox=NULL;	
	lst->tam--;

	return aux->info;
}

void lst_posIni(Lista *lst)
{
	lst->corr = lst->ini;
}

void* lst_prox(Lista *lst)
{
	No *aux = lst->corr;

	if(aux == NULL)
		return NULL;

	lst->corr = lst->corr->prox;
	return aux->info;
}

void lst_libera(Lista* lst)
{
	No* p = lst->ini;
	No* aux = NULL;

	while(p != NULL)
	{
		aux = p;
		p = p->prox;

		free(aux->info);
		free(aux);
	}

	free(lst);
}


