#include <stdio.h>
#include "pagina.h"
#include "lista.h"
#define TAMNAME 30


//Le a lista de paginas presentes em index.txt
void leIndex(Lista* paginas, char* diretorio){
    char * indexn;
    strcpy(indexn, diretorio);
    strcat(indexn, "index.txt\0");
    FILE* index = fopen(indexn, "r");

    char nomePagina[TAMNAME];

    while(fscanf(index, "%s\n", nomePagina) == 1){
        Pagina* pagina = inicializaPagina(nomePagina);
        insereLista(paginas, pagina);
    }

    fclose(index);
}

void leStopWords(char * diretorio){
    char * stopwordsn;
    strcpy(stopwordsn, diretorio);
    strcat(stopwordsn, "stopwords.txt\0");
    FILE* stopwords = fopen(stopwordsn, "r");

    char aux[TAMNAME];
    int i=0;
    while(fscanf(stopwords, "%s\n", aux)){
        // incluir nova stopword na lista/vetor (a decidir a implementação)
        // obs danilo -> nao acho interessante implementar uma lista so pra isso aqui
        // sugestao danilo -> mudar a lista implementada pra uma lista genérica, ou usar alocação dinamica de vetor
        i++;    
    }

}

void leGrafo(char * diretorio){
    char * graphn;
    strcpy(graphn, diretorio);
    strcat(graphn, "stopwords.txt\0");
    FILE* graph = fopen(graphn, "r");

    char aux[TAMNAME];
    int qtdlig;
    while(fscanf(graph, "%s %d ", aux, qtdlig)){
        //me confirma a teora de implementar uma lista genérica com o conteúdo diferente
        
        char * vetlig[qtdlig];
        for(int i = 0; i < qtdlig; i++){
            fscanf(graph, "%s ", vetlig);

        }

        //insereListaGraph(aux/*nome da origem*/, vetlig/*vetor com todas ligacoes*/)
    }

}

int main(int argc, char* argv[]){
    Lista* paginas = inicializaLista();
    leIndex(paginas, argv[1]);
    imprimeLista(paginas);
    liberaLista(paginas);
    return 0;
}