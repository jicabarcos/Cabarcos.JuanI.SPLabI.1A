#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "LinkedList.h"
#include "bicicletas.h"

int parser_BicicletaFromText(FILE* pFile , LinkedList* pArrayList){

    int error = 1;
    int r;
    eBicicleta* auxBici;
    char idStr[20];
    char nombreStr[20];
    char tipoStr[20];
    char tiempoStr[20];

    if(pFile != NULL && pArrayList != NULL){

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, tipoStr, tiempoStr);
        do{

            r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, tipoStr, tiempoStr);
            if(r == 4){

                auxBici = bici_nuevaParam(idStr, nombreStr, tipoStr, tiempoStr);
                if(auxBici != NULL){

                    ll_add(pArrayList, auxBici);

                }

            }

        }while(!feof(pFile));
        error = 0;

    }
    return error;

}

int parser_textFromBicicleta(FILE* pFile, LinkedList* pArrayList){

    int error = 1;
    eBicicleta* auxBici;
    int cantidadDeBicis;
    int auxId;
    char auxNombre[50];
    char auxTipo[50];
    int auxTiempo;

    if(pFile != NULL && pArrayList != NULL){

        cantidadDeBicis = ll_len(pArrayList);
        fprintf(pFile, "id_bike,nombre,tipo,tiempo\n");
        for(int i = 0; i < cantidadDeBicis; i++){

            auxBici = (eBicicleta*) ll_get(pArrayList, i);
            if(auxBici != NULL){

                bici_getId(auxBici, &auxId);
                bici_getNombre(auxBici, auxNombre);
                bici_getTipo(auxBici, auxTipo);
                bici_getTiempo(auxBici, &auxTiempo);
                fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxNombre, auxTipo, auxTiempo);

            }

        }
        error = 0;

    }
    return error;

}
