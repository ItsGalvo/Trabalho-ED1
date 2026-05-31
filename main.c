#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noticia.h"
#include "listacabcau.h"
#include "listaencadeada.h"

void main(){
    Lista cabCau;
    NoEncadeada *listaEncad = NULL;
    int opcao;
    criarListaCabCau(&cabCau);
    criarListaEncad(&listaEncad); 

    do{
        printf("----------------MENU------------------\n");
        printf("1 - Adicionar nova noticia\n");
        printf("2 - Remover noticia pendente por id\n");
        printf("3 - Remover noticia verificada por palavra-chave\n");
        printf("4 - Buscar noticias pendentes por palavra-chave\n");
        printf("5 - Imprimir as noticias\n");
        printf("6 - Classificar noticias\n");
        printf("7 - Imprimir quantidade de noticias por categoria\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                char data[11], novotitulo[200], novoconteudo[1000], novafonte[100];
                printf("Digite a data da noticia(DD/MM/AAAA): ");
                scanf(" %[^\n]", data);
                printf("Digite o titulo da noticia: ");
                scanf(" %[^\n]", novotitulo);
                printf("Digite o conteúdo da noticia: ");
                scanf(" %[^\n]", novoconteudo);
                printf("Digite a fonte da noticia: ");
                scanf(" %[^\n]", novafonte);
                Noticia *noticia = criarNoticia(data, novotitulo, novoconteudo, novafonte, EmAnalise);
                inserirInicioCabCau(&cabCau, *noticia);
                free(noticia);
                break;
            case 2:
                int id;
                printf("Digite o ID da noticia a ser removida: ");
                scanf("%d", &id);
                removerNoticiaPorIdCabCau(&cabCau, id);
                break;
            case 3:
                char palavra[100];
                printf("Digite a palavra-chave para remover noticias verificadas: ");
                scanf(" %[^\n]", palavra);
                removerPorPalavraChaveEncad(&listaEncad, palavra);
                break;
            case 4:
                char busca[100];
                printf("Digite a palavra-chave para buscar noticias pendentes: ");
                scanf(" %[^\n]", busca);
                buscarNoticiasPorPalavraChaveCabCau(&cabCau, busca);
                break;
            case 5:
                int tipo;
                printf("Imprimir noticias: 1 - Pendentes, 2 - Verificadas, 3 - Ambas: ");
                scanf("%d", &tipo);
                if(tipo == 1){
                    imprimirListaCabCau(&cabCau);
                }else if(tipo == 2){
                    imprimirNoticiasEncad(listaEncad);
                }else if(tipo == 3){
                    imprimirListaCabCau(&cabCau);
                    imprimirNoticiasEncad(listaEncad);
                }else{
                    printf("Opcao invalida!\n");
                }
                break;
            case 6:{
                NoCabCau* p = cabCau.cab->prox;
                while(p != cabCau.cau){
                    NoCabCau* proximo = p->prox;
                    imprimirNoticia(&p->info);
                    int classificacao;
                    do {
                        printf("Classifique a noticia (1 - Confiavel, 2 - Suspeita): ");
                        scanf("%d", &classificacao);
                    } while (classificacao < 1 || classificacao > 2);
                    
                    inserirFimEncad(&listaEncad, p->info);
                    removerNoticiaPorIdCabCau(&cabCau, p->info.id);
                    p = proximo;
                }
                break;
            }
            case 7:
                qtdConfiaveisEncad(listaEncad);
                quantidadeNoticiasPendentes(&cabCau);
                qtdSuspeitasEncad(listaEncad);
                break;
            case 8:
                liberarListaCabCau(&cabCau);
                liberarListaEncad(&listaEncad);
                printf("Saindo...\n");
                break;
        }
    }while(opcao != 8);
}