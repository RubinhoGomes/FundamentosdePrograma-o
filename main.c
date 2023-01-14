/* ## Projeto De Programação ##
 * Aplicação para a Associação de Estudantes
 * Made by Rúben Gomes & João Carreira
 */

/* ############################ Bibliotecas ############################ */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/* ############################ Constantes ############################ */

#define NUMERO_PARTICIPANTES 5000 // Numero maximo de inscrições dos Participantes
#define NUMERO_ATIVIDAES  200 // Numero maximo das atividades
#define NUMERO_INSCRICOES 10000 // Numero maximo de inscrições
#define FICHEIRO_ESTUDANTE "estudantes.dat" // Nome do Ficheiro para guardar os dados
#define FICHEIRO_ATIVIDADES "atividades.dat" // Nome do Ficheiro para guardar os dados
#define FICHEIRO_INSCRICOES "inscricoes.dat" // Nome do Ficheiro para guardar os dados

/* ############################ Estruturas ############################ */
// TODO alterar nif para Unsigned INT
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
    unsigned int id_estudante;
    unsigned int id_atividade;
    float pagamento;
    char data[10];
    char hora[10];

} t_inscricoes;

/* ############################ Prototipos ############################ */

/* ####### Estudantes ####### */

int ler_estudantes(t_estudante [], int);

void mostrar_dados_estudante(t_estudante [], int);


/* ####### Atividades ####### */

int ler_atividade(t_atividades [], int);

void mostrar_dados_atividade(t_atividades [], int);

/* ####### Inscrições ####### */

int ler_inscricao(t_inscricoes [], int);

void mostrar_dados_inscricao(t_inscricoes [], int);

/* ####### Ficheiros ####### */

void verificar_ficheiro(char []);

void criar_ficheiro(char []);

/* ## Estudantes ## */

void ler_f_estudantes(t_estudante [], int*);

void guardar_f_estudantes(t_estudante [], int*);

/* ## Atividades ## */
void ler_f_atividades(t_atividades [], int*);

void guardar_f_atividades(t_atividades [], int*);

/* ## Inscrições ## */
void ler_f_inscricoes(t_inscricoes [], int*);

void guardar_f_inscricoes(t_inscricoes [], int*);

/* ####### Extras ####### */

/* Estudante */

void atualizar_estudante(t_estudante alunos[], int, int);

int remover_estudante(t_estudante alunos[], int, int);

int ler_opcao();

int encontrar_nif(t_estudante alunos[], int, unsigned int);

unsigned int pedir_nif(char frase[]);

/* Atividades */
void atualizar_atividade(t_atividades atividades[], int);

int remover_atividade(t_atividades atividades[], int);

/* Inscrições */
void atualizar_inscricao(t_inscricoes inscricoes[], int);

int remover_inscricao(t_inscricoes inscricoes[], int);

/*  ####### Menu #######  */

int menu_principal();

int menu_estudantes();

int menu_atividades();

int menu_inscricoes();
// TODO: Fazer Menu Atividades Para vizualizarmos os vários valores das estatisticas
int menu_ver_atividades();

/* ####### Estatistica ####### */
// TODO: Fazer Estatisticas
void estatistica(t_atividades atividades[], int numero_atividades);

void atividades_realizadas(t_atividades [], int);

int percentagem_inscricoes(t_inscricoes [], int, t_estudante [], int);

int valor_total(t_inscricoes [], int, char [], char [], t_atividades [], int); // Inscrições -- Data -- Hora -- Atividades

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
    int indice_estudante = -1;

    char confirmar = ' ';

    setlocale(LC_ALL, "Portuguese");

    ler_f_estudantes(alunos, &numero_estudante);
    ler_f_atividades(atividades, &numero_atividades);
    ler_f_inscricoes(inscricoes, &numero_inscricoes);


    do {
        fflush(stdin);
        switch (menu_principal()) { // Vai receber o valor vindo da função main e vai pegar nesse valor e "testa-lo" no switch
            case 1:
                // Caso seja escolhida a opção de gestão dos estudantes
                // system("cls");
                switch (menu_estudantes()) {
                    case 0:
                        // Confirmar Saida
                        break;
                    case 1:
                        // Ler Estudante
                        numero_estudante = ler_estudantes(alunos, numero_estudante); // Vamos receber o valor quue a função retorna atualizando assim o numero de quantos estudantes foram inseridos
                        break;
                    case 2:
                        // Mostrar Dados
                        mostrar_dados_estudante(alunos, numero_estudante);
                        break;
                    /*case 3:
                        // Atualizar estudantes
                        nif = pedir_nif("que deseja atualiza");
                        indice_estudante = encontrar_nif(alunos, numero_estudante, nif);
                        atualizar_estudante(alunos, numero_estudante, indice_estudante);
                        break;
                    case 4:
                        // Remover estudantes
                        nif = pedir_nif("que deseja remover"); // Vai pedir ao utilizador o NIF
                        indice_estudante = encontrar_nif(alunos, numero_estudante, nif); // Vai percorrer os estudantes a procura do NIF inserido e devolver o indice onde foi encontrado
                        numero_estudante = remover_estudante(alunos, numero_estudante, indice_estudante); // Vai remover o estudante com o NIF inserido e encontrado anteriormente
                        break;*/
                    default:
                        printf("\n\nNao inseriu uma opcao valida\n\n");
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
                        numero_atividades = ler_atividade(atividades, numero_atividades);
                        break;
                    case 2:
                        // Mostrar Atividade
                        mostrar_dados_atividade(atividades, numero_atividades);
                        break;
                    /*case 3:
                        //Atualizar Atividade
                        printf("Numero 2");
                        break;
                    case 4:
                        //Remover Atividade
                        printf("Numero 3");
                        break;*/
                    default:
                        printf("\n\nNao inseriu uma opcao valida\n\n");
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
                        numero_inscricoes = ler_inscricao(inscricoes, numero_inscricoes);
                        break;
                    case 2:
                        //Mostrar Dados
                        mostrar_dados_inscricao(inscricoes, numero_inscricoes);
                        break;
                    /*case 3:
                        //Atualizar Inscrições
                        printf("Numero 3");
                        break;
                    case 4:
                        //Remover Inscrições
                        printf("Numero 4");
                        break;*/
                    default:
                        printf("\n\nNao inseriu uma opcao valida\n\n");
                        break;
                }
                break;

            case 4:
                estatistica(atividades, numero_atividades);
                break;
            case 0:
                confirmar = confirmar_saida();
                break;
            default:
                printf("\n\nNao inseriu uma opcao valida\n\n");
                break;
        }

    } while(tolower(confirmar) != 's');

    guardar_f_estudantes(alunos, &numero_estudante);
    guardar_f_atividades(atividades, &numero_atividades);
    guardar_f_inscricoes(inscricoes, &numero_inscricoes);

    return 0;
}

/* ############################ Funções ############################ */

/* ####### Estudantes ####### */
/**
 * Ler Estudante
 * @param alunos
 * @param numero_estudantes
 * @return int
 */

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

/**
 * Mostrar Dados dos Estudantes
 * @param alunos
 * @param numero_estudantes
 */

void mostrar_dados_estudante(t_estudante alunos[], int numero_estudantes){
    printf("\n");
    for(int contador = 0; contador <= numero_estudantes; contador++){
        if(alunos[contador].id > 0){
            printf("* [%u]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s] *\n", alunos[contador].id, alunos[contador].nome, alunos[contador].escola, alunos[contador].nif, alunos[contador].email, alunos[contador].telefone);
        } else if(alunos[contador].id <= 0 && numero_estudantes <= 0){
            printf("\n\n** Nao existem dados dos estudantes. **\n\n");
        }
    }
    system("pause");
}

/**
 * Ler as Atividades
 * @param atividades
 * @param numero_atividades
 * @return int
 */
int ler_atividade(t_atividades atividades[], int numero_atividades){

    atividades[numero_atividades].id = numero_atividades + 1;

    printf("Insira a desginacao da atividade: ");
    scanf(" %[^\n]s", atividades[numero_atividades].designacao);
    printf("Insira a data da atividade: ");
    scanf(" %[^\n]s", atividades[numero_atividades].data);
    printf("Insira a hora da atividade: ");
    scanf(" %[^\n]s", atividades[numero_atividades].hora);
    printf("Insira o genero da atividade: ");
    scanf(" %[^\n]s", atividades[numero_atividades].tipo);
    printf("Insira a associacao de estudantes promotora da atividade: ");
    scanf(" %[^\n]s", atividades[numero_atividades].associacao_estudantes);
    printf("Insira a localizacao: ");
    scanf(" %[^\n]s", atividades[numero_atividades].local);
    printf("Insira o preco da atividade: ");
    scanf(" %f", &atividades[numero_atividades].preco);

    return (numero_atividades + 1);
}

/**
 * Mostrar Atividades
 * @param atividades
 * @param numero_atividades
 */
void mostrar_dados_atividade(t_atividades atividades[], int numero_atividades){

    for(int contador = 0; contador < numero_atividades; contador++){
        if(atividades[contador].id > 0){
            printf("* [%u]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%f] *\n", atividades[contador].id, atividades[contador].designacao, atividades[contador].data, atividades[contador].hora, atividades[contador].tipo, atividades[contador].associacao_estudantes, atividades[contador].local, atividades[contador].preco);
        } else if(atividades[contador].id <= 0 && numero_atividades <= 0){
            printf("\n\n** Não existem dados das atividades. **\n\n");
        }
    }
    system("pause");
}

/**
 * Ler Inscrições
 * @param inscricoes
 * @param numero_inscricoes
 * @return int
 */
int ler_inscricao(t_inscricoes inscricoes[], int numero_inscricoes){

    inscricoes[numero_inscricoes].id = numero_inscricoes + 1;
    printf("Insira o id do estudante: ");
    scanf(" %u", &inscricoes[numero_inscricoes].id_estudante);
    printf("Insira o id do atividade: ");
    scanf(" %u", &inscricoes[numero_inscricoes].id_atividade);
    printf("Insira o preco: ");
    scanf(" %f", &inscricoes[numero_inscricoes].pagamento);
    printf("Insira a data da inscricao: ");
    scanf(" %[^\n]s", inscricoes[numero_inscricoes].data);
    printf("Insira a hora da inscricao: ");
    scanf(" %[^\n]s", inscricoes[numero_inscricoes].hora);

    return numero_inscricoes + 1;
}

/**
 * Mostrar dados inscrição
 * @param inscricoes
 * @param numero_inscricao
 */
void mostrar_dados_inscricao(t_inscricoes inscricoes[], int numero_inscricao){
    for(int contador = 0; contador < numero_inscricao; contador++){
        if(inscricoes[contador].id > 0){
            printf("* [%u]\t[%u]\t[%u]\t[%f]\t[%s]\t[%s] *\n", inscricoes[contador].id, inscricoes[contador].id_estudante, inscricoes[contador].id_atividade, inscricoes[contador].pagamento, inscricoes[contador].data, inscricoes[contador].hora);
        } else if(inscricoes[contador].id <= 0 && numero_inscricao <= 0){
            printf("\n\n** Não existem dados das inscricao. **\n\n");
        }
    }
    system("pause");
}

/* ####### Ficheiros ####### */
/**
 * Verifica se o ficheiro ja existe ou se precisa de ser criado
 * @param nome
 */
void verificar_ficheiro(char nome[]){
    FILE *ficheiro;

    ficheiro = fopen(nome, "rb");
    if(ficheiro == NULL){
        criar_ficheiro(nome);
    }
    fclose(ficheiro);
}

/**
 * Cria o ficheiro
 * @param nome
 */
void criar_ficheiro(char nome[]){
    FILE *ficheiro;

    ficheiro = fopen(nome, "r+b");
    fclose(ficheiro);
}

/* ## Estudante ## */

/**
 * Ler do ficheiro declarado no inicio do codigo, os valores guardados no ficheiro
 * @param alunos
 * @return int
 */
void ler_f_estudantes(t_estudante alunos[], int *numero_estudantes){
    FILE *ficheiro;

    verificar_ficheiro(FICHEIRO_ESTUDANTE);

    ficheiro = fopen(FICHEIRO_ESTUDANTE, "rb");
    fread(numero_estudantes, sizeof(int), 1, ficheiro);
    fread(alunos, sizeof(t_estudante), *numero_estudantes, ficheiro);
    fclose(ficheiro);
}

/**
 * Vai guardar todos os dados que estão na estrutura dos estudantes
 * @param alunos
 * @param numero_estudantes
 */
void guardar_f_estudantes(t_estudante alunos[], int *numero_estudantes){
    FILE *ficheiro;

    verificar_ficheiro(FICHEIRO_ESTUDANTE);

    ficheiro = fopen(FICHEIRO_ESTUDANTE, "wb");
    fwrite(numero_estudantes, sizeof(int), 1, ficheiro);
    fwrite(alunos, sizeof(t_estudante), *numero_estudantes, ficheiro);
    fclose(ficheiro);
}
/* ## Atividade ## */

/**
 * Ler do ficheiro declarado no inicio do codigo, os valores guardados no ficheiro
 * @param alunos
 * @return int
 */
void ler_f_atividades(t_atividades atividades[], int *numero_atividades){
    FILE *ficheiro;

    verificar_ficheiro(FICHEIRO_ATIVIDADES);

    ficheiro = fopen(FICHEIRO_ATIVIDADES, "rb");
    fread(numero_atividades, sizeof(int), 1, ficheiro);
    fread(atividades, sizeof(t_atividades), *numero_atividades, ficheiro);
    fclose(ficheiro);
}

/**
 * Vai guardar todos os dados que estão na estrutura dos estudantes
 * @param alunos
 * @param numero_estudantes
 */
void guardar_f_atividades(t_atividades atividades[], int *numero_atividades){
    FILE *ficheiro;

    verificar_ficheiro(FICHEIRO_ATIVIDADES);

    ficheiro = fopen(FICHEIRO_ATIVIDADES, "wb");
    fwrite(numero_atividades, sizeof(int), 1, ficheiro);
    fwrite(atividades, sizeof(t_atividades), *numero_atividades, ficheiro);
    fclose(ficheiro);
}
/* ## Inscrições ## */

/**
 * Ler do ficheiro declarado no inicio do codigo, os valores guardados no ficheiro
 * @param alunos
 * @return int
 */
void ler_f_inscricoes(t_inscricoes inscricoes[], int *numero_inscricoes){
    FILE *ficheiro;

    verificar_ficheiro(FICHEIRO_INSCRICOES);

    ficheiro = fopen(FICHEIRO_INSCRICOES, "rb");
    fread(numero_inscricoes, sizeof(int), 1, ficheiro);
    fread(inscricoes, sizeof(t_inscricoes), *numero_inscricoes, ficheiro);
    fclose(ficheiro);
}

/**
 * Vai guardar todos os dados que estão na estrutura dos estudantes
 * @param alunos
 * @param numero_estudantes
 */
void guardar_f_inscricoes(t_inscricoes inscricoes[], int *numero_inscricoes){
    FILE *ficheiro;

    verificar_ficheiro(FICHEIRO_INSCRICOES);

    ficheiro = fopen(FICHEIRO_INSCRICOES, "wb");
    fwrite(numero_inscricoes, sizeof(int), 1, ficheiro);
    fwrite(inscricoes, sizeof(t_inscricoes), *numero_inscricoes, ficheiro);
    fclose(ficheiro);
}

/* ####### Extras  ####### */

/* ## Estudante ## */

/**
 * Atualizar dados dos estudantes
 * @param alunos
 * @param numero_estudantes
 * @param indice_estudante
 */
void atualizar_estudante(t_estudante alunos[], int numero_estudantes, int indice_estudante){

    if(indice_estudante >= 0){
        printf("\nInsira os novos valores para o estudante, %s\n", alunos[indice_estudante].nome);
        ler_estudantes(alunos, indice_estudante);
    } else {
        printf("\n **Nao foi encontrado o aluno com esse email** \n");
    }
}

/**
 * Remover Estudante
 * @param alunos
 * @param numero_estudante
 * @param indice_remover
 * @return int
 */
int remover_estudante(t_estudante alunos[], int numero_estudante, int indice_remover){

    if(indice_remover >= 0){
        for(int contador = indice_remover; contador <= numero_estudante; contador++) {
            alunos[contador] = alunos[contador + 1];
        }
    }

    return (numero_estudante);
}

/**
 * Pedir NIF
 * Esta função vai servir para pedir o NIF para ser utilizado no remover e atualizar estudante.
 * @param frase
 * @return unsigned int
 */
unsigned int pedir_nif(char frase[]){

    unsigned int nif = 0;

    printf("Insira o NIF do estudante, %s: ", frase);
    scanf(" %u", &nif);

    return nif;

}

/**
 * Encontrar o NIF
 * Esta função vai encontrar o NIF dos estudantes que existem, caso não encontre vai retornar o valor -1
 * @param alunos
 * @param numero_estudante
 * @param nif
 * @return int
 */
int encontrar_nif(t_estudante alunos[], int numero_estudante, unsigned int nif){

    char nif_char[10];
    int index = -1;

    sprintf(nif_char, "%u", nif);

    for(int contador = 0; contador <= numero_estudante; contador++){
        if(strcmp(alunos[contador].nif, nif_char) == 0){
            index = contador;
        }
    }

    if(index < 0){
        printf("\n\nNIF nao encontrado\n\n");
    }

    return index;
}

/* ## Atividades ## */


/* ## Inscrições ## */


/* ####### Menu's ####### */

int ler_opcao(){ // Esta função vai ler uma opção listada nos menu's e vai dar return a opção desejada

    int opcao = 0;

    printf("Insira uma opcao: ");
    scanf(" %d", &opcao);

    return opcao;
}

int menu_principal(){

    printf("########## Menu Principal ##########\n\n");
    printf("[1] - Gestao dos dados dos Estudantes\n");
    printf("[2] - Gestao dos dados das Atividade\n");
    printf("[3] - Gestao dos dados das Inscricoes\n");
    printf("[4] - Consultar as Estatisticas\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();

}

int menu_estudantes(){

    printf("########## Menu Estudante ##########\n\n");
    printf("[1] - Registar Novo Estudante\n");
    printf("[2] - Ver Dados dos Estudantes\n");
    //printf("[3] - Atualizar Estudante\n");
    //printf("[4] - Remover Estudante\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();
}

int menu_atividades(){

    printf("########## Menu Atividades ##########\n\n");
    printf("[1] - Registar Nova Atividade\n");
    printf("[2] - Mostrar Atividades\n");
    //printf("[3] - Atualizar Atividade\n");
    //printf("[3] - Remover Atividade\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();
}

int menu_inscricoes(){

    printf("########## Menu Inscricao ##########\n\n");
    printf("[1] - Registar Nova Inscricao\n");
    printf("[2] - Mostrar Inscricoes\n");
    //printf("[3] - Atualizar Inscricao\n");
    //printf("[4] - Remover Inscricao\n");
    printf("[0] - Sair\n\n");

    return ler_opcao();
}

/* ####### Estatistica ####### */

void estatistica(t_atividades atividades[], int numero_atividades){

    atividades_realizadas(atividades, numero_atividades);

}

void atividades_realizadas(t_atividades atividades[], int numero_atividades){

    int ativ_reali_ae[5] = {0, 0, 0, 0, 0};

    for (int contador = 0; contador < numero_atividades; ++contador) {
        if(strcmp(atividades[contador].associacao_estudantes, "AE-ESTG") == 0){
            ativ_reali_ae[0] += 1;
        } else if(strcmp(atividades[contador].associacao_estudantes, "AE-ESECS") == 0){
            ativ_reali_ae[1] += 1;
        } else if(strcmp(atividades[contador].associacao_estudantes, "AE-ESSLEI") == 0){
            ativ_reali_ae[2] += 1;
        } else if(strcmp(atividades[contador].associacao_estudantes, "AE-ESAD") == 0){
            ativ_reali_ae[3] += 1;
        } else if(strcmp(atividades[contador].associacao_estudantes, "AE-ESTM") == 0){
            ativ_reali_ae[4] += 1;
        }
    }
    printf("AE-ESTG: %d\tAE-ESECS: %d\tAE-ESSLEI: %d\tAE-ESAD: %d\tAE-ESTM: %d\n\n", ativ_reali_ae[0], ativ_reali_ae[1], ativ_reali_ae[2], ativ_reali_ae[3], ativ_reali_ae[4]);
}

/* ####### Saida ####### */

char  confirmar_saida(){

    char confirmar = ' ';

    do {

        printf("Deseja mesmo sair? (S/N): ");
        scanf(" %c", &confirmar);

    } while(tolower(confirmar) != 's' && tolower(confirmar) != 'n');

    return confirmar;
}

/* ####### End File ####### */