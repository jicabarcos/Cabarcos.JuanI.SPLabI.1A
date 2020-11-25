#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funcionesAdicionales.h"
#include "bicicletas.h"
#include "utn.h"

int menuDeOpciones(int tipoDeMenu){

    int eleccion;

    if(tipoDeMenu == 0){

        printf(" *** MENU PRINCIPAL ***\n\n");
        printf(">> 1) Cargar archivo\n");
        printf(">> 2) Imprimir lista\n");
        printf(">> 3) Asignar tiempos\n");
        printf(">> 4) Filtrar por tipo\n");
        printf(">> 5) Mostrar posiciones\n");
        printf(">> 6) Guardar posiciones\n");
        printf(">> 7) Salir\n\n");
        getValidInt("Elija la opcion deseada: ", "Debe ser un entero del 1 al 7, vuelva a ingresar. ", &eleccion, 1, 7, 5);

    }
    return eleccion;

}

void* randomizer(void* elemento){

    int aleatorio;
    //eBicicleta* auxBici;

    if(elemento != NULL){

        aleatorio = rand()%(71)+50;
        //auxBici = (eBicicleta*) elemento;
        bici_setTiempo(elemento, aleatorio);
        //auxBici->tiempo = aleatorio;

    }
    return elemento;

}

int buscarBMX(void* elemento){

    int ok = 0;
    char auxTipo[50];

    if(elemento != NULL){

        bici_getTipo(elemento, auxTipo);
        if(strcmp(auxTipo, "BMX") == 0){

            ok = 1;

        }

    }
    return ok;

}

int buscarPlayera(void* elemento){

    int ok = 0;
    char auxTipo[50];

    if(elemento != NULL){

        bici_getTipo(elemento, auxTipo);
        if(strcmp(auxTipo, "PLAYERA") == 0){

            ok = 1;

        }

    }
    return ok;

}

int buscarMTB(void* elemento){

    int ok = 0;
    char auxTipo[50];

    if(elemento != NULL){

        bici_getTipo(elemento, auxTipo);
        if(strcmp(auxTipo, "MTB") == 0){

            ok = 1;

        }

    }
    return ok;

}

int buscarPaseo(void* elemento){

    int ok = 0;
    char auxTipo[50];

    if(elemento != NULL){

        bici_getTipo(elemento, auxTipo);
        if(strcmp(auxTipo, "PASEO") == 0){

            ok = 1;

        }

    }
    return ok;

}
