#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayList){

    int error = 1;
    FILE* f = fopen(path, "r");

    if(f != NULL && pArrayList != NULL){

        if(!(parser_BicicletaFromText(f, pArrayList))){

            error = 0;

        }

    }
    fclose(f);
    return error;

}

void controller_listBicis(LinkedList* pArrayList){

    eBicicleta* auxBici = bici_nueva();

    if(pArrayList != NULL && auxBici != NULL){

        bici_listBicis(pArrayList);

    }

}

int controller_asignarTiempos(LinkedList* pArrayList){

    int error = 1;

    if(pArrayList != NULL){

        bici_asignarTiempos(pArrayList);
        error = 0;

    }
    return error;

}

int controller_saveAsText(char* path , LinkedList* pArrayList){

    int error = 1;
    FILE* f = fopen(path, "w");

    if(f != NULL && pArrayList != NULL){

        if(!(parser_textFromBicicleta(f, pArrayList))){

            error = 0;

        }

    }
    fclose(f);
    return error;

}

int controller_filtrarBicis(LinkedList* pArrayList){

    int error = 1;

    if(pArrayList != NULL){

        if(!bici_filtrarBicis(pArrayList)){

            error = 0;

        }

    }
    return error;

}

int controller_ordenarBicis(LinkedList* pArrayList){

    int error = 1;

    if(pArrayList != NULL){

        if(!bici_ordenarBicis(pArrayList)){

            error = 0;

        }

    }
    return error;

}
