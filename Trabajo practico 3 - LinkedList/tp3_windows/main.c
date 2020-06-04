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
    Employee* empleados;

    setbuf(stdout,NULL);

    empleados=NULL;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	menu();
    	utn_getNumeroInt(&option,"Opcion :", "\nError, por favor reintente\n",1,10,3);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:

                 break;
            case 3:
                empleados=employee_new();
                employee_setId(empleados,idEmpleados);
                idEmpleados++;
                 break;
            case 4:

                 break;
            case 5:

                 break;
            case 6:

                 break;
            case 7:

                 break;
            case 8:

                 break;
            case 9:

                 break;
        }
    }while(option != 10);
    return 0;
}
