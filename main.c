#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include "libraries/dm.h"

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

void atualizar_estudante(t_estudante alunos[], int);

int remover_estudante(t_estudante alunos[], int);

void mostrar_dados_estudante(t_estudante alunos[], int);

/* ####### Atividades ####### */

int ler_atividade(t_atividades atividades[], int);

void atualizar_atividade(t_atividades atividades[], int);

int remover_atividade(t_atividades atividades[], int);

void mostrar_dados_atividade(t_atividades atividades[], int);

/* ####### Inscrições ####### */

int ler_inscricao(t_inscricoes inscricoes[], int);

void atualizar_inscricao(t_inscricoes inscricoes[], int);

int remover_inscricao(t_inscricoes inscricoes[], int);

void mostrar_dados_inscricao(t_inscricoes inscricoes[], int);

/*  ####### Menu #######  */

int menu_principal();

int menu_estudantes();

int menu_atividades();

int menu_inscricoes();

/* ####### Estatistica ####### */

void estatistica();

/* ####### Saida ####### */

char confirmar_saida();

/* ############################ Main ############################ */

int main(){

    t_estudante alunos[NUMERO_PARTICIPANTES];
    t_atividades atividades[NUMERO_ATIVIDAES];
    t_inscricoes inscricoes[NUMERO_INSCRICOES];

    int numero_estudante = 0;
    int numero_atividades = 0;
    int numero_inscricoes = 0;

    setlocale(LC_ALL, "portuguese");

    switch (menu_principal()) { // Vai receber o valor vindo da função main e vai pegar nesse valor e "testa-lo" no switch
        case 1:
            // Caso seja escolhida a opção de gestão dos estudantes
            switch (menu_estudantes()) {
                case 0:
                    //Confirmar Saida
                    break;
                case 1:
                    ler_estudantes(alunos, numero_estudante);
                    break;
                case 2:
                    //Atualizar estudantes
                    printf("Numero 2");
                    break;
                case 3:
                    //Remover estudantes
                    printf("Numero 3");
                    break;
            }

        case 2:
            // Caso seja escolhida a opção de gestão das atividades
            switch (menu_atividades()) {
                case 0:
                    //Confirmar Saida
                    break;
                case 1:
                    // Ler atividade
                    break;
                case 2:
                    //Atualizar Atividade
                    printf("Numero 2");
                    break;
                case 3:
                    //Remover Atividade
                    printf("Numero 3");
                    break;
            }

        case 3:
            // Caso seja escolhida a opção de gestão das inscrições
            switch (menu_inscricoes()) {
                case 0:
                    //Confirmar Saida
                    break;
                case 1:
                    //Ler Inscrições
                    break;
                case 2:
                    //Atualizar Inscrições
                    printf("Numero 2");
                    break;
                case 3:
                    //Remover Inscrições
                    printf("Numero 3");
                    break;
            }

        case 4:
            estatistica();
            break;
        case 0:
            confirmar_saida();
            break;
    }


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



/* ####### Menu's ####### */

int menu_principal(){

    int opcao = 0;

    printf("########## Menu Principal ##########\n\n");
    printf("[1] - Gestão dos dados dos estudantes\n");
    printf("[2] - Gestão dos dados das atividade\n");
    printf("[3] - Gestão dos dados das inscrições\n");
    printf("[4] - Consultar as estatísticas\n");
    printf("[0] - Sair\n\n");
    printf("Insira uma opção: ");
    scanf(" %d", &opcao);

    return opcao;

}


int menu_estudantes(){

    int opcao = 0;

    printf("########## Menu Estudante ##########\n\n");
    printf("[1] - Registar novo estudante\n");
    printf("[2] - Atualizar estudante\n");
    printf("[3] - Remover Estudante\n");
    printf("[0] - Sair\n\n");
    printf("Insira uma opção: ");
    scanf(" %d", &opcao);

    return opcao;
}

int menu_atividades(){

    int opcao = 0;

    printf("########## Menu Estudante ##########\n\n");
    printf("[1] - Registar nova atividade\n");
    printf("[2] - Atualizar atividade\n");
    printf("[3] - Remover atividade\n");
    printf("[0] - Sair\n\n");
    printf("Insira uma opção: ");
    scanf(" %d", &opcao);

    return opcao;
}

int menu_inscricoes(){

    int opcao = 0;

    printf("########## Menu Estudante ##########\n\n");
    printf("[1] - Registar nova inscrição\n");
    printf("[2] - Atualizar inscrição\n");
    printf("[3] - Remover inscrição\n");
    printf("[0] - Sair\n\n");
    printf("Insira uma opção: ");
    scanf(" %d", &opcao);

    return opcao;
}


/* ####### Saida ####### */

char  confirmar_saida(){

    char confirmar;

    do {

        printf("Deseja mesmo sair?");
        scanf(" %c", &confirmar);

    } while(tolower(confirmar) != 's' || tolower(confirmar) != 'n');

    return confirmar;
}

/* ####### End File ####### */