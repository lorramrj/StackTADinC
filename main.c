#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "vetor.h"

int main(void) {

          Pilha *p=pilha_cria();

          Vetor *v1=vet_cria(1.0f,1.0f);
          Vetor *v2=vet_cria(2.0f,2.0f);
          Vetor *v3=vet_cria(3.0f,3.0f);

          pilha_push(p,v3);
          pilha_push(p,v2);
		  pilha_push(p,v1);

          while(!pilha_vazia(p)) {
               Vetor *aux=(Vetor *) pilha_pop(p);
               char vet[20];
               puts(vet_format(aux,vet));
          }

          pilha_libera(p);

          return 0;
}
