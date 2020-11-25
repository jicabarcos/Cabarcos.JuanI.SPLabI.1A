#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "funcionesAdicionales.h"
#include "LinkedList.h"
#include "controller.h"
#include "bicicletas.h"

int main()
{
    srand(time(NULL));
    LinkedList* listaParticipantes = ll_newLinkedList();
    int eleccionMenu;
    int flagCargarDatos = 0;
    int flagTiempos = 0;

    if(listaParticipantes != NULL){

        printf("Inicializando programa...\n\n");
        system("pause");
        do{

            system("cls");
            eleccionMenu = menuDeOpciones(0);
            switch(eleccionMenu){

                case 1:

                    if(!controller_loadFromText("bicicletas.csv", listaParticipantes)){

                        system("cls");
                        printf("Datos cargados con exito!\n\n");
                        flagCargarDatos = 1;
                        system("pause");

                    }
                    else{

                        system("cls");
                        printf("Error al cargar los datos\n\n");
                        system("pause");

                    }
                    break;

                case 2:

                    if(flagCargarDatos){

                        system("cls");
                        printf("*** LISTADO DE PARTICIPANTES ***\n\n");
                        controller_listBicis(listaParticipantes);
                        system("pause");

                    }
                    else{

                        system("cls");
                        printf("Antes de listar los participantes, debe cargar los datos!\n\n");
                        system("pause");

                    }
                    break;

                case 3:

                    if(flagCargarDatos){

                        system("cls");
                        if(!controller_asignarTiempos(listaParticipantes)){

                            printf("Tiempos asignados con exito!\n\n");
                            flagTiempos = 1;

                        }
                        else{

                            printf("Error al asignar tiempos\n\n");

                        }
                        system("pause");

                    }
                    else{

                        system("cls");
                        printf("Antes de asignar tiempos, debe cargar los datos!\n\n");
                        system("pause");

                    }
                    break;

                case 4:

                    if(flagCargarDatos){

                        system("cls");
                        if(!controller_filtrarBicis(listaParticipantes)){

                            printf("Participantes filtrados con exito!\n\n");

                        }
                        else{

                            printf("Error al filtrar participantes\n\n");

                        }
                        system("pause");
                    }
                    else{

                        system("cls");
                        printf("Antes de filtrar por tipo, debe cargar los datos!\n\n");
                        system("pause");

                    }

                case 5:

                    if(flagCargarDatos){

                        system("cls");
                        if(!controller_ordenarBicis(listaParticipantes)){

                            printf("Participantes ordenados con exito!\n\n");
                            printf("*** LISTADO ORDENADO DE PARTICIPANTES ***\n\n");
                            controller_listBicis(listaParticipantes);

                        }
                        else{

                            printf("Error al ordenar los participantes\n\n");

                        }
                        system("pause");

                    }
                    else{

                        system("cls");
                        printf("Antes de ordenar, debe cargar los datos!\n\n");
                        system("pause");

                    }
                    break;

                case 6:

                    if(flagCargarDatos && flagTiempos){

                        system("cls");
                        if(!controller_saveAsText("bicicletas_TiempoYOrden.csv", listaParticipantes)){

                            printf("Archivo guardado con exito!\n\n");

                        }
                        else{

                            printf("Error al intentar guardar archivo\n\n");

                        }
                        system("pause");

                    }
                    else{

                        system("cls");
                        printf("Antes de guardar, debe cargar los datos y asignar los tiempos!\n\n");
                        system("pause");

                    }

                    break;

                case 7:

                    break;











            }


        }while(eleccionMenu != 7);

        system("cls");
        printf("Gracias por utilizar el programa, hasta la proxima!!!\n\n");

    }
    return 0;
}
