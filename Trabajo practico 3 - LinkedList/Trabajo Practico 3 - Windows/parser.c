#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
	char id[10];
	char nombre[128];
	char horasTrabajadas[10];
	char sueldo[10];
	int index = 0;
	int retorno = -1;

	do
	{	//index == 0 porque tiene titulo
		if(index == 0)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			index = 1;
		}
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
		{
			//printf("%s-%s-%s-%s\n",id,nombre,horasTrabajadas,sueldo);
			if (index != 0)
				pEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			index++;
			if(pEmpleado != NULL && index != 0)
			{
				ll_add(pArrayListEmployee,(Employee*)pEmpleado);
				retorno = 0;
			}

		}
		else
			break;
	}while(feof(pFile)==0);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee pEmpleado;
	Employee* auxEmpleado;
	int retorno = -1;
	int endOf = 1;
	int index = 0;
	do{
		if( index == 0)
		{
			fread(&pEmpleado,sizeof(Employee),1,pFile);
			index++;
		}
		endOf = fread(&pEmpleado,sizeof(Employee),1,pFile);
		//printf("End of file: %d",endOf);
		if(endOf == 1)
		{
			auxEmpleado = employee_newParametrosBin(pEmpleado.id,pEmpleado.nombre,pEmpleado.horasTrabajadas,pEmpleado.sueldo);
			ll_add(pArrayListEmployee,(Employee*)auxEmpleado);
			index++;
			retorno = 0;
		}
	}while(endOf != 0);

    return retorno;
}
