#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

// LOAD - SAVE
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayList);

// OTRAS
void controller_listBicis(LinkedList* pArrayList);
int controller_asignarTiempos(LinkedList* pArrayList);
int controller_filtrarBicis(LinkedList* pArrayList);
int controller_ordenarBicis(LinkedList* pArrayList);
