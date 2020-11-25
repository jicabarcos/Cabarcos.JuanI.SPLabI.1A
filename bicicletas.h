#include "LinkedList.h"

#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct{

   int id_bike;
   char nombre[50];
   char tipo[50];
   int tiempo;

}eBicicleta;

#endif // BICICLETAS_H_INCLUDED

// CONSTRUCTORES
eBicicleta* bici_nueva();
eBicicleta* bici_nuevaParam(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr);

// SETTERS Y GETTERS
int bici_setId(eBicicleta* this, int id);
int bici_getId(eBicicleta* this, int* id);
int bici_setNombre(eBicicleta* this, char* nombre);
int bici_setNombre(eBicicleta* this, char* nombre);
int bici_setTipo(eBicicleta* this, char* tipo);
int bici_getTipo(eBicicleta* this, char* tipo);
int bici_setTiempo(eBicicleta* this, int tiempo);
int bici_getTiempo(eBicicleta* this, int* tiempo);

// OTRAS
void bici_listBicis(LinkedList* lista);
LinkedList* bici_asignarTiempos(LinkedList* lista);
int bici_filtrarBicis(LinkedList* lista);
int bici_criterioDeOrden(void* elementoA, void* elementoB);
