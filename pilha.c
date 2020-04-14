#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

struct pilha {
     Lista* lst;
};Pilha* pilha_cria(void) {   Pilha* pilha = (Pilha *) malloc(sizeof(Pilha));   if(pilha==NULL) {
		printf("Memory allocation error.\n");
		exit(1);
   }   pilha->lst = lst_cria();	   return pilha;}int pilha_vazia(Pilha *p){  return lst_vazia(p->lst);}void pilha_push(Pilha* p, void *v){	lst_insIni(p->lst, v);}void *pilha_pop(Pilha* p){	return lst_retIni(p->lst);}void pilha_libera(Pilha *p){	lst_libera(p->lst);	free(p);}