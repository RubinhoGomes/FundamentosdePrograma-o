#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "/libraries/dm.h"

/* ############################ Constantes ############################ */

#define NUMERO_PARTICIPANTES 5000 // Numero maximo de inscrições dos Participantes
#define NUMERO_ATIVIDAES  200 // Numero maximo das atividades
#define NUMERO_INSCRICOES 10000 // Numero maximo de inscrições


/* ############################ Estruturas ############################ */

typedef struct {
    int id;
    char nome[81];
    char escola[7];
    char nif[10];
    char email[120];
    char telefone[10];

} t_estudante;

typedef struct {

    int id;
    char associacao_estudantes[50];
    char designacao[100];
    char data[10];
    char hora[10];
    char local[50];
    char tipo[50];
    float preco;

} t_atividades;

typedef struct {

    int id;
    int id_estudante;
    int id_atividade;
    float pagamento;
    char data[10];
    char hora[10];

} t_inscricoes;

/* ############################ Prototipos ############################ */

/* ####### Estudantes ####### */

int ler_estudantes(t_estudante alunos[], int);

void mostrar_dados_estudante(t_estudante alunos[], int);

/* ####### Atividades ####### */

int ler_atividade(t_atividades atividades[], int);

void mostrar_dados_atividade(t_atividades atividades[], int);

/* ####### Inscrições ####### */

int ler_inscricao(t_inscricoes inscricoes[], int);

void mostrar_dados_inscricao(t_inscricoes inscricoes[], int);

/* ############################ Main ############################ */

int main(){

    t_estudante alunos[NUMERO_PARTICIPANTES];
    t_atividades atividades[NUMERO_ATIVIDAES];
    t_inscricoes inscricoes[NUMERO_INSCRICOES];

    int numero_estudante = 0;
    int numero_atividades = 0;
    int numero_inscricoes = 0;


    numero_estudante = ler_estudantes(alunos, numero_estudante);

    mostrar_dados_estudante(alunos, numero_estudante);

    return 0;
}


/* ############################ Funções ############################ */

/* ####### Estudantes ####### */

int ler_estudantes(t_estudante alunos[], int numero_estudantes){

    printf("Insira o seu nome: ");
    scanf(" %[^\n]s", alunos[numero_estudantes].nome);
    printf("Insira a sua escola: ");
    scanf(" %[^\n]s", alunos[numero_estudantes].escola);
    printf("Insira o seu nif: ");
    scanf(" %[^\n]s", alunos[numero_estudantes].nif);
    printf("Insira o seu email: ");
    scanf(" %[^\n]s", alunos[numero_estudantes].email);
    printf("Insira o seu telefone: ");
    scanf(" %[^\n]s", alunos[numero_estudantes].telefone);

    return numero_estudantes + 1;
}

void mostrar_dados_estudante(t_estudante alunos[], int numero_estudantes){

    for(int contador = 0; contador <= numero_estudantes; contador++){
        printf("%s\n", alunos[contador].nome);
    }
}


/* ####### Atividades ####### */









/* ####### Inscrições ####### */



/* ####### End File ####### */