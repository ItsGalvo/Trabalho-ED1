#ifndef LISTA_CAB_CAU_H
#define LISTA_CAB_CAU_H
#include "noticia.h"

typedef struct NoCabCau {
    Noticia info;
    struct NoCabCau *prox;
    struct NoCabCau *ant;
} NoCabCau;

typedef struct {
    NoCabCau *cab;
    NoCabCau *cau;
    int tamanho;
} Lista;

void criarListaCabCau(Lista* l);
int estaVaziaCabCau(Lista* l);
void inserirInicioCabCau(Lista* l, Noticia v);
void inserirFimCabCau(Lista* l, Noticia v);
void imprimirListaCabCau(Lista* l);
void removerElementoCabCau(Lista* l);
void removerNoticiaPorIdCabCau(Lista *l, int id);
void buscarNoticiasPorPalavraChaveCabCau(Lista* l, char* palavra);
void imprimirTodasNoticiasCabCau(Lista* l);
int quantidadeNoticiasPendentes(Lista* l);
void liberarListaCabCau(Lista* l);
#endif
