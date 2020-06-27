/*
 * ArrayEmployees.h
 *
 *  Created on: 14 may. 2020
 *      Author: Nahu
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "ArraySector.h"

typedef struct Employee{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/*
* \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployee(Employee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee list[],int len,int id, char name[], char lastName[], float salary, int sector);

/** \brief find an Employee by Id en returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int findEmployeeById(Employee list[],int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int removeEmployee(Employee list[],int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee list[],int len, int order);

/** \brief print the content of employees array
* \param list Employee*
* \param length int
* \param list Sector*
* \param sector lenght int
* \return int
*
*/
int printEmployees(Employee list[],int len,Sector sectorList[],int sectorLen);

/** \brief hardcoding a Employee array up to 10
* \param list Employee*
* \param length int
* \param qty int (limit=10)
* \return count int = qty
*
*/
int harcodedEmployees(Employee list[], int len, int qty);

/** \brief delete in logic form the employee by ID
* \param list Employee*
* \param length int
* \param list Sector*
* \param sector lenght int
* \return int
*
*/
int deleteEmployee(Employee list[],int len,Sector sectorList[],int sectorLen);

/** \brief modify a Employee array by id
* \param list Employee*
* \param length int
* \param list Sector*
* \param sector lenght int
* \return int [0] id OK [-1] if Error
*
*/
int modifyEmploee(Employee list[], int len,Sector sectorList[],int sectorLen);
/*
* \brief print only one employee by index
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param i int index
*
*/
void printEmployee(Employee list[],int len, int i,Sector sectorList[],int sectorLen);
/*
* \brief create a new employee in a Employee array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param i int index
* \param id int autoincremental idNumber
* return int [0] if OK or [-1] if ERROR
*
*/
int newEmployee(Employee list[],int len,Sector sectorList[],int sectorLen, int id);
#endif /* ARRAYEMPLOYEES_H_ */
