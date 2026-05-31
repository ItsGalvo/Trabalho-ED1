#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "noticia.h"

typedef struct noencadeada {
    Noticia info;
    struct noencadeada *prox;
} NoEncadeada;

void criarListaEncad(NoEncadeada** l);
int estaVaziaEncad(NoEncadeada* l);
void inserirInicioEncad(NoEncadeada** l, Noticia v);
void inserirFimEncad(NoEncadeada** l, Noticia v);
void imprimirNoticiasEncad(NoEncadeada* l);
void removerElementoEncad(NoEncadeada** l);
void inserirNovaNoticiaEncad(NoEncadeada** l);
void removerPorPalavraChaveEncad(NoEncadeada** l, char* palavra);
void qtdConfiaveisEncad(NoEncadeada* l);
void qtdSuspeitasEncad(NoEncadeada* l);
void liberarListaEncad(NoEncadeada** l);
#endif