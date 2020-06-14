#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn_funciones.h"
#include "LinkedList.h"

Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee = NULL;

	pEmployee = employee_new();

	if(pEmployee != NULL)
	{
		pEmployee->id = atoi(idStr);
		strncpy(pEmployee->nombre,nombreStr,128);
		pEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
		pEmployee->sueldo = atoi(sueldoStr);
	}
	return pEmployee;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0 )
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if( this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(this->nombre,nombre,128);
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->nombre,128);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0 )
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if( this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo > 0 )
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if( this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
Employee* employee_newParametrosBin(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldoStr)
{
	Employee* pEmployee = NULL;

	pEmployee = employee_new();

	if(pEmployee != NULL)
	{
		pEmployee->id = idStr;
		strncpy(pEmployee->nombre,nombreStr,128);
		pEmployee->horasTrabajadas = horasTrabajadasStr;
		pEmployee->sueldo = sueldoStr;
	}
	return pEmployee;
}
int imprimirEmpleado(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		printf("\nID:  %d  Nombre: %s  Horas: %d Salario: %d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
		retorno = 0;
	}
	return retorno;
}
int imprimirEmpleados(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int i;
	int retorno = -1;
	printf("\n**************LISTA EMPLEADOS**************\n\n");
	for(i = 0; i< ll_len(pArrayListEmployee);i++)
	{
		auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
		if(auxEmployee != NULL)
		{
			printf("ID:  %d  Nombre: %s  Horas: %d Salario: %d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
			retorno = 0;
		}
	}
	return retorno;
}

int create_employee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char auxNombre[128];
	int auxHoras;
	int auxSalario;
	int auxId = ll_len(pArrayListEmployee)+1;
	Employee* auxEmpleado = employee_new();
	printf("\n**************ALTA EMPLEADOS**************\n\n");
	if( auxEmpleado != NULL)
	{
		fflush(stdin);
		if(!utn_getAChar(auxNombre,"\nIngrese el nombre del empleado: ","\nError, intente de nuevo\n", 3, 128) &&
		!utn_getNumeroInt(&auxHoras,"\nIngrese la cantidad de horas: ","\nError, intente de nuevo\n",0, 1000,3)&&
		!utn_getNumeroInt(&auxSalario,"\nIngrese el salario del empleado: ","\nError, intente de nuevo\n",1, 100000,3))
		{
			//printf("%d %s %d %d",auxId,auxNombre,auxHoras,auxSalario);
			if(!employee_setId(auxEmpleado,auxId) &&
			!employee_setNombre(auxEmpleado,auxNombre) &&
			!employee_setHorasTrabajadas(auxEmpleado,auxHoras) &&
			!employee_setSueldo(auxEmpleado,auxSalario))
			{
				ll_add(pArrayListEmployee,auxEmpleado);
				imprimirEmpleado(auxEmpleado);
				//printf("%d %s %d %d",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int edit_employee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	//int index;
	int opcion;
	char auxNombre[128];
	int auxHoras;
	int auxSalario;
	char respuesta;
	Employee* auxEmployee;

	printf("\n**************MODIFICAR EMPLEADO**************\n");
	if(!utn_getNumeroInt(&auxId,"\nIngrese el ID del empleado: ","\nError, intente de nuevo\n",1,3000,3)&&
			auxId <=ll_len(pArrayListEmployee))
	{
		for(int i = 0; i< ll_len(pArrayListEmployee);i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			if(auxEmployee->id == auxId)
			{
				imprimirEmpleado(auxEmployee);
			}
		}
		if(!utn_getNumeroInt(&opcion,"\n1) Modificar Nombre\n"
				"2) Modificar horas\n"
				"3) Modificar Sueldo\n"
				"Opcion: ","\nError, intente de nuevo\n",1,3,3))
		{
			switch(opcion)
			{
				case 1:
					if(!utn_getAChar(auxNombre,"\nIngrese el nombre: ","\nError, intente de nuevo\n", 3, 128)&&
						!utn_getAnswer(&respuesta, "\nDesea guardar los cambios? (s/n) :", "\nError, intente de nuevo\n",3) &&
					    respuesta == 's')
					{
						employee_setNombre(auxEmployee,auxNombre);
						retorno = 0;
						printf("\nModificado con exito\n");
					}
					break;
				case 2:
					if(!utn_getNumeroInt(&auxHoras,"\nIngrese las horas: ","\nError, intente de nuevo\n",1,1000,3) &&
						!utn_getAnswer(&respuesta, "\nDesea guardar los cambios? (s/n) :", "\nError, intente de nuevo\n",3) &&
						respuesta == 's')
					{
						employee_setHorasTrabajadas(auxEmployee,auxHoras);
						printf("\nModificado con exito\n");
						retorno = 0;
					}
					break;
				case 3:
					if(!utn_getNumeroInt(&auxSalario,"\nIngrese el salario: ","\nError, intente de nuevo\n",1000,10000,3) &&
						!utn_getAnswer(&respuesta, "\nDesea guardar los cambios? (s/n) :", "\nError, intente de nuevo\n",3) &&
						respuesta == 's')
					{
						employee_setSueldo(auxEmployee,auxSalario);
						printf("\nModificado con exito\n");
						retorno = 0;
					}
					break;
			}
		}
		else
			printf("\nOperacion cancelada\n");
	}
	else
		printf("\nNo se encontro un cliente con ese ID\n");
	return retorno;
}
int delete_employee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	char respuesta;
	Employee* auxEmployee;
	printf("\n**************MODIFICAR EMPLEADO**************\n");
		if(!utn_getNumeroInt(&auxId,"\nIngrese el ID del empleado: ","\nError, intente de nuevo\n",1,3000,3)&&
				auxId <=ll_len(pArrayListEmployee))
		{
				for(int i = 0; i< ll_len(pArrayListEmployee);i++)
				{
					auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
					if(auxEmployee->id == auxId)
					{
						imprimirEmpleado(auxEmployee);
						if(!utn_getAnswer(&respuesta, "\nDesea eliminar? (s/n) :", "\nError, intente de nuevo\n",3) &&
							respuesta =='s')
						{
							ll_remove(pArrayListEmployee,i);
							retorno = 0;
						}
					}
				}
		}
	return retorno;
}
