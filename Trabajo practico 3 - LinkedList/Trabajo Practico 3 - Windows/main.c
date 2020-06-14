#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Reports.h"
#include "utn_funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int idEmpleados=1;
    //int debug;

    setbuf(stdout,NULL);


    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	menu();
    	utn_getNumeroInt(&option,"Opcion :", "\nError, por favor reintente\n",1,10,3);
        switch(option)
        {
            case 1:
               controller_loadFromText("data.csv",listaEmpleados);
                idEmpleados+=ll_len(listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("newFileBinary.csv",listaEmpleados);
            	idEmpleados+=ll_len(listaEmpleados);
                 break;
            case 3:
            	if(!controller_addEmployee(listaEmpleados))
            		printf("\nAlta exitosa\n");
            	else
            		printf("\nNo se realizo el alta\n");
                 break;
            case 4:
            	controller_editEmployee(listaEmpleados);
                 break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
                 break;
            case 6:
            	if(controller_ListEmployee(listaEmpleados) != 0)
            		printf("\nNo se puede imprimir\n");
                 break;
            case 7:

                 break;
            case 8:
            	if(!controller_saveAsText("data.csv",listaEmpleados))
            		printf("\nGuardado con exito\n");
            	else
            		printf("\nError al guardar\n");

                 break;
            case 9:
            	if(controller_saveAsBinary("data.csv",listaEmpleados))
            		printf("\nGuardado con exito\n");
				else
					printf("\nError al guardar\n");

                 break;
            case 10:
            	free(listaEmpleados);
                  break;
        }
        system("pause");
        system("cls");
    }while(option != 10);
    return 0;
}
