#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "libraries/dm.h"

/* ############################ Constantes ############################ */

#define NUMERO_PARTICIPANTES 5000 // Numero maximo de inscrições dos Participantes
#define NUMERO_ATIVIDAES  200 // Numero maximo das atividades
#define NUMERO_INSCRICOES 10000 // Numero maximo de inscrições


/* ############################ Estruturas ############################ */

typedef struct {
    unsigned int id; // %u <<- Ao contrario do int que é %d
    char nome[81];
    char escola[7];
    char nif[10];
    char email[120];
    char telefone[10];

} t_estudante;

typedef struct {

    unsigned int id;
    char associacao_estudantes[50];
    char designacao[100];
    char data[10];
    char hora[10];
    char local[50];
    char tipo[50];
    float preco;

} t_atividades;

typedef struct {

    unsigned int id;
    int id_estudante;
    int id_atividade;
    float pagamento;
    char data[10];
    char hora[10];

} t_inscricoes;

/* ############################ Prototipos ############################ */

void anular_estudante(t_estudante alunos[], int);

int ler_opcao();

int encontrar_nif(t_estudante alunos[], int, unsigned int);

unsigned int pedir_nif();

/* ####### Estudantes ####### */

int ler_estudantes(t_estudante alunos[], int);

void atualizar_estudante(t_estudante alunos[], int);

int remover_estudante(t_estudante alunos[], int, int);

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
    unsigned int nif = 0;
    int indice_remover = 0;

    char confirmar = ' ';

    setlocale(LC_ALL, "Portuguese");

    do {
        fflush(stdin);
        switch (menu_principal()) { // Vai receber o valor vindo da função main e vai pegar nesse valor e "testa-lo" no switch
            case 1:
                // Caso seja escolhida a opção de gestão dos estudantes
                // system("cls");
                switch (menu_estudantes()) {
                    case 0:
                        //Confirmar Saida
                        break;
                    case 1:
                        numero_estudante = ler_estudantes(alunos, numero_estudante); // Vamos receber o valor quue a função retorna atualizando assim o numero de quantos estudantes foram inseridos
                        break;
                    case 2:
                        mostrar_dados_estudante(alunos, numero_estudante);
                        break;
                    case 3:
                        //Atualizar estudantes
                        atualizar_estudante(alunos, numero_estudante);
                        break;
                    case 4:
                        //Remover estudantes
                        nif = pedir_nif(); // Vai pedir ao utilizador o NIF
                        indice_remover = encontrar_nif(alunos, numero_estudante, nif); // Vai percorrer os estudantes a procura do NIF inserido e devolver o indice onde foi encontrado
                        numero_estudante = remover_estudante(alunos, numero_estudante, indice_remover); // Vai remover o estudante com o NIF inserido e encontrado anteriormente
                        break;
                }
                break;

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
                break;

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
                break;

            case 4:
                estatistica();
                break;
            case 0:
                confirmar = confirmar_saida();
                break;
        }

    } while(tolower(confirmar) != 's');


    return 0;
}


/* ############################ Funções ############################ */

void anular_estudante(t_estudante alunos[], int numero_estudante){

    alunos[numero_estudante].id = 0;
    strcpy(alunos[numero_estudante].nome, '\0');
    strcpy(alunos[numero_estudante].escola, '\0');
    strcpy(alunos[numero_estudante].email, '\0');
    strcpy(alunos[numero_estudante].nif, '\0');
    strcpy(alunos[numero_estudante].telefone, '\0');
}

int ler_opcao(){ // Esta função vai ler uma opção listada nos menu's e vai dar return a opção desejada

    int opcao = 0;

    printf("Insira uma opção: ");
    scanf(" %d", &opcao);

    return opcao;
}

unsigned int pedir_nif(){ // Esta função vai servir para pedir o NIF para ser utilizado no remover e atualizar estudante.

    unsigned int nif = 0;

    printf("Insira o NIF do estudante que quer eliminar: ");
    scanf(" %u", &nif);

    return nif;

}

int encontrar_nif(t_estudante alunos[], int numero_estudante, unsigned int nif){ // Esta função vai encontrar o NIF dos estudantes que existem, caso não encontre vai retornar o valor -1

    char nif_char[10];
    int index = -1;

    sprintf(nif_char, "%u", nif);

    for(int contador = 0; contador <= numero_estudante; contador++){
        if(strcmp(alunos[contador].nif, nif_char) == 0){
            index = contador;
        }
    }

    return index;
}


/* ####### Estudantes ####### */

/* Ler Estudante */

int ler_estudantes(t_estudante alunos[], int numero_estudantes){

    alunos[numero_estudantes].id = numero_estudantes + 1;

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

    return (numero_estudantes + 1);
}

/* Mostrar Dados dos Estudantes */

void mostrar_dados_estudante(t_estudante alunos[], int numero_estudantes){
    for(int contador = 0; contador <= numero_estudantes; contador++){
        if(alunos[contador].id > 0){
            printf("\t* [%u]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s] *\n", alunos[contador].id, alunos[contador].nome, alunos[contador].escola, alunos[contador].nif, alunos[contador].email, alunos[contador].telefone);
        } else if(alunos[contador].id <= 0 && numero_estudantes <= 0){
            printf("\n\n** Não existem dados dos estudantes. **\n\n");
        }
    }
    system("pause");
}

/* Atualizar dados dos estudantes */

void atualizar_estudante(t_estudante alunos[], int numero_estudantes){

    int indice_estudante;
    unsigned int nif;

    nif = pedir_nif();

    indice_estudante = encontrar_nif(alunos, numero_estudantes, nif);

    if(indice_estudante >= 0){
        printf("\nInsira os novos valores para o estudante, %s\n", alunos[indice_estudante].nome);
        ler_estudantes(alunos, indice_estudante);
    } else {
        printf("\n **Não foi encontrado o aluno com esse email** \n");
    }
}

int remover_estudante(t_estudante alunos[], int numero_estudante, int indice_remover){

    char string_vazia[10] = { ' ' };

    for(int contador = indice_remover; contador <= numero_estudante; contador++) {
        if(strcmp(string_vazia, alunos[contador + 1].nif) == 0){
            anular_estudante(alunos, contador);
        } else {
            alunos[contador].id = alunos[contador + 1].id;
            strcpy(alunos[contador].nome, alunos[contador + 1].nome);
            strcpy(alunos[contador].escola, alunos[contador + 1].escola);
            strcpy(alunos[contador].email, alunos[contador+ 1].email);
            strcpy(alunos[contador].nif, alunos[contador + 1].nif);
            strcpy(alunos[contador].telefone, alunos[contador + 1].telefone);
        }
    }

    return (numero_estudante - 1);
}

/* ####### Atividades ####### */

int ler_atividade(t_atividades atividades[], int numero_atividades){

    printf("Insira a associação de estudantes: ");
    scanf(" %[^\n]s", atividades[numero_atividades].associacao_estudantes);

    return numero_atividades + 1;

}


/* ####### Inscrições ####### */



/* ####### Menu's ####### */

int menu_principal(){

    printf("########## Menu Principal ##########\n\n");
    printf("[1] - Gestão dos dados dos estudantes\n");
    printf("[2] - Gestão dos dados das atividade\n");
    printf("[3] - Gestão dos dados das inscrições\n");
    printf("[4] - Consultar as estatísticas\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();

}

int menu_estudantes(){

    printf("########## Menu Estudante ##########\n\n");
    printf("[1] - Registar novo estudante\n");
    printf("[2] - Ver dados dos Estudantes\n");
    printf("[3] - Atualizar estudante\n");
    printf("[4] - Remover Estudante\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();
}

int menu_atividades(){

    printf("########## Menu Estudante ##########\n\n");
    printf("[1] - Registar nova atividade\n");
    printf("[2] - Atualizar atividade\n");
    printf("[3] - Remover atividade\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();
}

int menu_inscricoes(){

    printf("########## Menu Estudante ##########\n\n");
    printf("[1] - Registar nova inscrição\n");
    printf("[2] - Atualizar inscrição\n");
    printf("[3] - Remover inscrição\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();
}

/* ####### Estatistica ####### */

void estatistica(){

    printf("Bom Dia.");

}


/* ####### Saida ####### */

char  confirmar_saida(){

    char confirmar = ' ';

    do {

        printf("Deseja mesmo sair?");
        scanf(" %c", &confirmar);

    } while(tolower(confirmar) != 's' || tolower(confirmar) != 'n');

    return confirmar;
}

/* ####### End File ####### */