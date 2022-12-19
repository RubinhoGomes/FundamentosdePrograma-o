//
// Created by Ruben.
//

#include "../libraries//dm.h"

int verificar_ficheiro(char* file){

    if(fopen(file, "r+")){
        return 1;
    } else {
        return -1;
    }
}

int abrir_ficheiro(FILE* file){



}