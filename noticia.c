#include "noticia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id = 0;

Noticia* criarNoticia(char* data, char* titulo, char* conteudo, char* fonte, Classificacao classificacao){
    Noticia* novaNoticia = (Noticia*)malloc(sizeof(Noticia));
    if(novaNoticia == NULL){
        printf("Nao foi possivel alocar memoria para a noticia.\n");
        return NULL;
    }else{
        novaNoticia->id = id;
        id++;
        strncpy(novaNoticia->data, data, sizeof(novaNoticia->data) - 1);
        strncpy(novaNoticia->titulo, titulo, sizeof(novaNoticia->titulo) - 1);
        strncpy(novaNoticia->conteudo, conteudo, sizeof(novaNoticia->conteudo) - 1);
        strncpy(novaNoticia->fonte, fonte, sizeof(novaNoticia->fonte) - 1);
        novaNoticia->classificacao = classificacao;
        return novaNoticia;
    }
}

void imprimirNoticia(Noticia* noticia){
    if(noticia != NULL){
        printf("ID: %d\n", noticia->id);
        printf("Data: %s\n", noticia->data);
        printf("Titulo: %s\n", noticia->titulo);
        printf("Conteudo: %s\n", noticia->conteudo);
        printf("Fonte: %s\n", noticia->fonte);
        printf("Classificacao: ");
        switch (noticia->classificacao) {
            case EmAnalise:
                printf("Em Analise\n");
                break;
            case Confiavel:
                printf("Confiavel\n");
                break;
            case Suspeita:
                printf("Suspeita\n");
                break;
        }
    }
}
void liberarNoticia(Noticia* noticia){
    free(noticia);
}