#ifndef NOTICIA_H
#define NOTICIA_H

typedef enum classificacao{
    EmAnalise,
    Confiavel,
    Suspeita
} Classificacao;

typedef struct noticia{
    int id;
    char data[11];
    char titulo[200];
    char conteudo[1000];
    char fonte[100];
    Classificacao classificacao;
} Noticia;

Noticia* criarNoticia(char* data, char* titulo, char* conteudo, char* fonte, Classificacao classificacao);
void imprimirNoticia(Noticia *n);
void liberarNoticia(Noticia *n);

#endif