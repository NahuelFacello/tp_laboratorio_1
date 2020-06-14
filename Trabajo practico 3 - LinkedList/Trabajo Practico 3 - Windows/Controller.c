#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_funciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno = -1;
	int retornoParser = -1;
	if( path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{

			retornoParser= parser_EmployeeFromText(pFile,pArrayListEmployee);
			if(retornoParser == 0)
			{
				printf("\nLeido exitoso\n");
				retorno = 0;
			}
			else
				printf("\n Error en la lectura\n");
			//printf("\nRetorno parser: %d\n",retornoParser);
			fclose(pFile);

		}
		else
		{
			printf("El archivo no pudo ser leido\n");
		}
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno = -1;
	if( path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
			{
				printf("\nLeido exitoso\n");
				retorno = 0;
			}
			else
				printf("\n Error en la lectura\n");
			//printf("\nRetorno parser: %d\n",retornoParser);
			fclose(pFile);
		}
		else
		{
			printf("El archivo no pudo ser leido\n");
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(!ll_len(pArrayListEmployee))
	{
		printf("\nDebe importar data de empleados primero\n");
	}
	else if(pArrayListEmployee != NULL && !create_employee(pArrayListEmployee))
	{
		retorno = 0;
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
	{
		if(!edit_employee(pArrayListEmployee))
		{
			retorno =0;
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(pArrayListEmployee != NULL && !delete_employee(pArrayListEmployee))
	{
		printf("\nEliminado con exito\n");
		retorno = 0;
	}
	else
		printf("\nOperacion cancelada\n");
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(!imprimirEmpleados(pArrayListEmployee))
		retorno = 0;

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int i;
	char auxNombre[128];
	int auxHoras;
	int auxSalario;
	Employee* auxEmployee;
	FILE* pNewFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pNewFile = fopen("newFile.csv","w+");
		//rewind((FILE*)path);
		rewind(pNewFile);
		for(i = 0; i<ll_len(pArrayListEmployee); i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(auxEmployee,&auxId);
			employee_getNombre(auxEmployee,auxNombre);
			employee_getHorasTrabajadas(auxEmployee,&auxHoras);
			employee_getSueldo(auxEmployee,&auxSalario);
			fprintf(pNewFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSalario);
			retorno =0;
		}
		fclose(pNewFile);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee* auxEmployee;
	FILE* pNewFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pNewFile = fopen("newFileBinary.csv","w+b");
		//rewind((FILE*)path);
		rewind(pNewFile);
		for(i = 0; i<ll_len(pArrayListEmployee); i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			/*empleado.id= auxEmployee->id;
			strcpy(empleado.nombre,auxEmployee->nombre);
			empleado.horasTrabajadas= auxEmployee->horasTrabajadas;
			empleado.sueldo= auxEmployee->sueldo;*/
			fwrite(auxEmployee,sizeof(Employee),1,pNewFile);
			retorno =0;
		}
		fclose(pNewFile);
	}
    return retorno;
}

