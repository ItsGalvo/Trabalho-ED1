#include <stdio.h>
#include <stdlib.h>
#include "listacabcau.h"
#include <string.h>

void criarListaCabCau(Lista* l){
    l->cab = (NoCabCau*) malloc(sizeof(NoCabCau));
    l->cau = (NoCabCau*) malloc(sizeof(NoCabCau));
    if(l->cab == NULL || l->cau == NULL){
        printf("Falha ao alocar sentinelas da lista.\n");
        return;
    }
    l->cab->prox = l->cau;
    l->cab->ant = NULL;
    l->cau->prox = NULL;
    l->cau->ant = l->cab;
    l->tamanho = 0;
}

int estaVaziaCabCau(Lista* l){
    return (l->cab->prox == l->cau);
}

void inserirInicioCabCau(Lista* l, Noticia v){
    NoCabCau* novo = (NoCabCau*)malloc(sizeof(NoCabCau));
    if(novo != NULL){
        novo->info = v;
        novo->prox = l->cab->prox;
        novo->ant = l->cab;
        if(l->cab->prox != NULL)
            l->cab->prox->ant = novo;
        l->cab->prox = novo;
        l->tamanho++;
    }else{
        printf("Nao foi possivel alocar espaco!\n");
    }
}


void imprimirListaCabCau(Lista* l){
    if(!estaVaziaCabCau(l)){
        NoCabCau* p;
        
        for(p=l->cab->prox; p!=l->cau; p=p->prox){
            imprimirNoticia(&p->info);
        }
        printf("\n");
    }else{
        printf("Esta Vazio!\n");
    }
}

void removerElementoCabCau(Lista* l){
    if(!estaVaziaCabCau(l)){
        NoCabCau* p;
        p=l->cab->prox;
        l->cab->prox=p->prox;
        free(p);
    }else{
        printf("Esta Vazio!\n");
    }
}

void removerNoticiaPorIdCabCau(Lista *l, int id){
    if(!estaVaziaCabCau(l)){
        NoCabCau* p;
        NoCabCau* ant = l->cab;
        for(p = l->cab->prox; p != l->cau; p = p->prox){
            if(p->info.id == id){
                ant->prox = p->prox;
                if(p->prox != NULL)
                    p->prox->ant = ant;
                free(p);
                l->tamanho--;
                printf("Noticia com ID %d removida com sucesso.\n", id);
                return;
            }
            ant = p;
        }
        printf("Noticia com ID %d nao encontrada.\n", id);
    }else{
        printf("Esta Vazio!\n");
    }
}

void buscarNoticiasPorPalavraChaveCabCau(Lista* l, char* palavra){
    if(!estaVaziaCabCau(l)){
        NoCabCau* p;
        for(p=l->cab->prox; p!=l->cau; p=p->prox){
            if(strstr(p->info.titulo, palavra) != NULL || strstr(p->info.conteudo, palavra) != NULL){
                imprimirNoticia(&p->info);
            }
        }
    }else{
        printf("Esta Vazio!\n");
    }
}
int quantidadeNoticiasPendentes(Lista* l){
    int count = 0;
    if(!estaVaziaCabCau(l)){
        NoCabCau* p;
        for(p=l->cab->prox; p!=l->cau; p=p->prox){
            count++;
        }
    }
    return count;
}

void imprimirTodasNoticiasCabCau(Lista* l){
    if(!estaVaziaCabCau(l)){
        NoCabCau* p;
        for(p=l->cab->prox; p!=l->cau; p=p->prox){
            imprimirNoticia(&p->info);
        }
    }
}

void liberarListaCabCau(Lista* l){
    if(l->cab == NULL || l->cau == NULL) return;
    NoCabCau* p = l->cab->prox;
    NoCabCau* temp;
    while(p != NULL && p != l->cau){
        temp = p->prox;
        free(p);
        p = temp;
    }
    l->cab->prox = l->cau;
    l->cau->ant = l->cab;
    l->tamanho = 0;
}