/*
 * Reports.c
 *
 *  Created on: 28 may. 2020
 *      Author: Nahu
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"

/** \brief Menu employee
 */
void menu()
{
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");
}
/** \brief Menu sort employees
 */
void menu_sort()
{
	printf("1. Ordenar por ID\n");
	printf("2. Ordenar por nombre\n");
	printf("3. Ordenar por horas\n");
	printf("4. Ordenar por sueldo\n");
}
/** \brief menu type of order
 *
 */
void menu_sort_orden()
{
	printf("1. Menor a mayor / A - Z \n");
	printf("0. Mayor a menor / Z - A\n");
}

//***************************************************************************

/** \brief Ordenar empleados por nombre
 *
 * \param void*pEmployee1 for casting employee pointer
 * \param void*pEmployee2 for casting employee pointer
 * \return int [0] no changes; [1] name1 is longer than name2; [-1] name1 is shorter than name2
 *
 */
int employee_ordenarPorNombre(void* pEmployee1, void* pEmployee2)
{
	int retorno = 0;

	if(strcmp(((Employee*)pEmployee1)->nombre,((Employee*)pEmployee2)->nombre) > 0)
	{
		retorno = 1;
	}
	if(strcmp(((Employee*)pEmployee1)->nombre,((Employee*)pEmployee2)->nombre) < 0)
	{
		retorno = -1;
	}
	return retorno;
}

/** \brief Ordenar empleados por ID
 *
 * \param void*pEmployee1 for casting employee pointer
 * \param void*pEmployee2 for casting employee pointer
 * \return int [0] no changes; [1] name1 is longer than name2; [-1] name1 is shorter than name2
 *
 */

int employee_ordenarPorId(void* pEmployee1, void* pEmployee2)
{
	int retorno = 0;

	if((((Employee*)pEmployee1)->id > ((Employee*)pEmployee2)->id))
	{
		retorno = 1;
	}
	if((((Employee*)pEmployee1)->id < ((Employee*)pEmployee2)->id))
	{
		retorno = -1;
	}
	return retorno;
}
/** \brief Ordenar empleados por sueldo
 *
 * \param void*pEmployee1 for casting employee pointer
 * \param void*pEmployee2 for casting employee pointer
 * \return int [0] no changes; [1] sueldo1 is greater than sueldo2; [-1] sueldo1 is shorter than sueldo2
 *
 */

int employee_ordenarPorSueldo(void* pEmployee1, void* pEmployee2)
{
	int retorno = 0;

	if((((Employee*)pEmployee1)->sueldo > ((Employee*)pEmployee2)->sueldo))
	{
		retorno = 1;
	}
	if((((Employee*)pEmployee1)->sueldo < ((Employee*)pEmployee2)->sueldo))
	{
		retorno = -1;
	}
	return retorno;
}

/** \brief Ordenar empleados por horas trabajadas
 *
 * \param void*pEmployee1 for casting employee pointer
 * \param void*pEmployee2 for casting employee pointer
 * \return int [0] no changes; [1] hours1 is greater than hours2; [-1] hours1 is shorter than hours2
 *
 */
int employee_ordenarPorHorasTrabajadas(void* pEmployee1, void* pEmployee2)
{
	int retorno = 0;

	if((((Employee*)pEmployee1)->horasTrabajadas > ((Employee*)pEmployee2)->horasTrabajadas))
	{
		retorno = 1;
	}
	if((((Employee*)pEmployee1)->horasTrabajadas < ((Employee*)pEmployee2)->horasTrabajadas))
	{
		retorno = -1;
	}
	return retorno;
}

