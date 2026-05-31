#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"
#include <string.h>

void criarListaEncad(NoEncadeada** l){
    *l = NULL;
}

int estaVaziaEncad(NoEncadeada* l){
    return (l == NULL);
}

void inserirInicioEncad(NoEncadeada** l, Noticia v){
    NoEncadeada* novo = (NoEncadeada*)malloc(sizeof(NoEncadeada));
    if(novo != NULL){
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    }else{
        printf("Nao foi possivel alocar espaco!");
    }
}

void inserirFimEncad(NoEncadeada** l, Noticia v){
    NoEncadeada* novo = (NoEncadeada*)malloc(sizeof(NoEncadeada));
    if(novo != NULL){
        novo->info = v;
        novo->prox = NULL;
        if(*l == NULL){
            *l = novo;
        }else{
            NoEncadeada* p = *l;
            while(p->prox != NULL){
                p = p->prox;
            }
            p->prox = novo;
        }
    }else{
        printf("Nao foi possivel alocar espaco!");
    }
}

void imprimirNoticiasEncad(NoEncadeada* l){
    if(!estaVaziaEncad(l)){
        NoEncadeada* p = l;
        for(p=l; p!=NULL; p=p->prox){
            imprimirNoticia(&p->info);
        }
    }else{
        printf("Esta Vazio!\n");
    }
}

void removerElementoEncad(NoEncadeada** l){
    if(!estaVaziaEncad(*l)){
        NoEncadeada* p = *l;
        *l = (*l)->prox;
        free(p);
    }else{
        printf("Esta Vazio!\n");
    }
}

void inserirNovaNoticiaEncad(NoEncadeada** l){
    char data[11], titulo[200], conteudo[1000], fonte[100];
    Classificacao classificacao;
    
    printf("Digite a data da notícia (DD/MM/AAAA): ");
    scanf(" %[^\n]", data);
    printf("Digite o titulo da noticia: ");
    scanf(" %[^\n]", titulo);
    printf("Digite o conteudo da noticia: ");
    scanf(" %[^\n]", conteudo);
    printf("Digite a fonte da noticia: ");
    scanf(" %[^\n]", fonte);
    
    int opcao;
    do {
        printf("Classifique a noticia (1 - Confiavel, 2 - Suspeita): ");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 2);
    
    classificacao = (opcao == 1) ? Confiavel : Suspeita;
    
    Noticia* novaNoticia = criarNoticia(data, titulo, conteudo, fonte, classificacao);
    if(novaNoticia != NULL){
        inserirFimEncad(l, *novaNoticia);
        free(novaNoticia);
    }
}

void removerPorPalavraChaveEncad(NoEncadeada** l, char* palavra){
    if(!estaVaziaEncad(*l)){
        NoEncadeada* p = *l;
        NoEncadeada* ant = NULL;
        for(p=*l; p!=NULL; p=p->prox){
            if(strstr(p->info.titulo, palavra) != NULL || strstr(p->info.conteudo, palavra) != NULL){
                if(ant == NULL){
                    *l = p->prox;
                    printf("Noticia com a palavra-chave '%s' removida.\n", palavra);

                }else{
                    ant->prox = p->prox;
                }
                free(p);
                return;
            }
            ant = p;
            p = p->prox;
        }
        printf("Noticia com a palavra-chave '%s' nao encontrada.\n", palavra);
    }else{
        printf("Esta Vazio!\n");
    }
}

void qtdConfiaveisEncad(NoEncadeada* l){
    int qtd = 0;
    if(!estaVaziaEncad(l)){
        NoEncadeada* p = l;
        for(p=l; p!=NULL; p=p->prox){
            if(p->info.classificacao == Confiavel){
                qtd++;
            }
        }
    }
    printf("Quantidade de noticias confiaveis: %d\n", qtd);
}

void qtdSuspeitasEncad(NoEncadeada* l){
    int qtd = 0;
    if(!estaVaziaEncad(l)){
        NoEncadeada* p = l;
        for(p=l; p!=NULL; p=p->prox){
            if(p->info.classificacao == Suspeita){
                qtd++;
            }
        }
    }
    printf("Quantidade de noticias suspeitas: %d\n", qtd);
}

void liberarListaEncad(NoEncadeada** l){
    NoEncadeada* p = *l;
    for(p=*l; p!=NULL; p=p->prox){
        NoEncadeada* temp = p;
        p = p->prox;
        free(temp);
    }
    *l = NULL;
}

