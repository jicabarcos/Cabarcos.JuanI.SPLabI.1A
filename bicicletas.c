#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bicicletas.h"
#include "utn.h"
#include "Controller.h"
#include "funcionesAdicionales.h"

eBicicleta* bici_nueva(){

    eBicicleta* nuevaBici = NULL;

    nuevaBici = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(nuevaBici != NULL){

        bici_setId(nuevaBici, 0);
        bici_setNombre(nuevaBici, " ");
        bici_setTipo(nuevaBici, 0);
        bici_setTiempo(nuevaBici, 0);

    }
    return nuevaBici;

}

eBicicleta* bici_nuevaParam(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr){

    eBicicleta* nuevaBici = bici_nueva();
    int id;
    int tiempo;

    if(idStr != NULL && nombreStr != NULL && tipoStr != NULL && tiempoStr != NULL){

        id = atoi(idStr);
        tiempo = atoi(tiempoStr);

        if(!bici_setId(nuevaBici, id) &&
           !bici_setNombre(nuevaBici, nombreStr) &&
           !bici_setTipo(nuevaBici, tipoStr) &&
           !bici_setTiempo(nuevaBici, tiempo)){

            free(nuevaBici);
            nuevaBici = NULL;

        }

    }
    return nuevaBici;

}

int bici_setId(eBicicleta* this, int id){

    int error = 1;

    if(this != NULL && id > 0){

        this->id_bike = id;
        error = 0;

    }
    return error;

}

int bici_getId(eBicicleta* this, int* id){

    int error = 1;

    if(this != NULL && id != NULL){

        *id = this->id_bike;
        error = 0;

    }
    return error;

}

int bici_setNombre(eBicicleta* this, char* nombre){

    int error = 1;

    if(this != NULL && nombre != NULL){

        strcpy(this->nombre, nombre);
        error = 0;

    }
    return error;

}

int bici_getNombre(eBicicleta* this, char* nombre){

    int error = 1;

    if(this != NULL && nombre != NULL){

        strcpy(nombre, this->nombre);
        error = 0;

    }
    return error;

}

int bici_setTipo(eBicicleta* this, char* tipo){

    int error = 1;

    if(this != NULL && tipo > 0){

        strcpy(this->tipo, tipo);
        error = 0;

    }
    return error;

}

int bici_getTipo(eBicicleta* this, char* tipo){

    int error = 1;

    if(this != NULL && tipo != NULL){

        strcpy(tipo, this->tipo);
        error = 0;

    }
    return error;

}

int bici_setTiempo(eBicicleta* this, int tiempo){

    int error = 1;

    if(this != NULL && tiempo > 0){

        this->tiempo = tiempo;
        error = 0;

    }
    return error;

}

int bici_getTiempo(eBicicleta* this, int* tiempo){

    int error = 1;

    if(this != NULL && tiempo != NULL){

        *tiempo = this->tiempo;
        error = 0;

    }
    return error;

}

void bici_listBicis(LinkedList* lista){

    int auxId;
    char auxNombre[50];
    char auxTipo[50];
    int auxTiempo;
    int cantidadDeBicis;
    eBicicleta* auxBici = NULL;
    cantidadDeBicis = ll_len(lista);

    if(lista != NULL){

        auxBici = bici_nueva();
        if(auxBici != NULL){

            for(int i = 0; i < cantidadDeBicis; i++){

                auxBici = (eBicicleta*) ll_get(lista, i);
                bici_getId(auxBici, &auxId);
                bici_getNombre(auxBici, auxNombre);
                bici_getTipo(auxBici, auxTipo);
                bici_getTiempo(auxBici, &auxTiempo);
                printf("%d   %s   %s   %d\n", auxId, auxNombre, auxTipo, auxTiempo);

            }

        }

    }

}

LinkedList* bici_asignarTiempos(LinkedList* lista){

    LinkedList* nuevaLista;

    if(lista != NULL){

        nuevaLista = ll_map(lista, randomizer);

    }
    return nuevaLista;

}

int bici_filtrarBicis(LinkedList* lista){

    int error = 1;
    int cantidadDeBicis;
    eBicicleta* auxBici = NULL;
    LinkedList* listaBMX = ll_newLinkedList();
    LinkedList* listaPlayera = ll_newLinkedList();
    LinkedList* listaMTB = ll_newLinkedList();
    LinkedList* listaPaseo = ll_newLinkedList();


    if(lista != NULL){

        cantidadDeBicis = ll_len(lista);
        auxBici = bici_nueva();
        if(auxBici != NULL){

            for(int i = 0; i < cantidadDeBicis; i++){

                auxBici = (eBicicleta*) ll_get(lista, i);

                listaBMX = ll_filter(lista, buscarBMX); // ACA ROMPE
                controller_saveAsText("bmx.csv", listaBMX);

                listaPlayera = ll_filter(lista, buscarPlayera);
                controller_saveAsText("playera.csv", listaPlayera);

                listaMTB = ll_filter(lista, buscarMTB);
                controller_saveAsText("mtb.csv", listaMTB);

                listaPaseo = ll_filter(lista, buscarPaseo);
                controller_saveAsText("paseo.csv", listaPaseo);



            }
            error = 0;

        }

    }

    return error;

}

int bici_ordenarBicis(LinkedList* lista){

    int error = 1;

    if(lista != NULL){

        ll_sort(lista, bici_criterioDeOrden, 1);
        error = 0;

    }
    return error;

}

int bici_criterioDeOrden(void* elementoA, void* elementoB){

    int retorno;
    eBicicleta* biciA = (eBicicleta*) elementoA;
    eBicicleta* biciB = (eBicicleta*) elementoB;

    if(strcmp(biciA->tipo,biciB->tipo) == 0){

        retorno = (biciA->tiempo) - (biciB->tiempo);

    }
    retorno = strcmp(biciA->tipo, biciB->tipo);
    return retorno;

}
