/*
 ============================================================================
 Name        : tp2-laboratorio1.c
 Author      : Nahuel Facello
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "ArraySector.h"
#include "Reports.h"
#include "utn_funciones.h"

#define QTY_EMPLOYEES 1000
#define QTY_SECTORS 3

int menu();

int main() {

	Employee employeeList[QTY_EMPLOYEES];
	Sector sectorList[QTY_SECTORS];
	float salaries;
	int employeesss;
	float average;
	int id=2000;
	int option;
	int aActiveEmployees;
	int sort;

	setbuf(stdout,NULL);

	initEmployee(employeeList, QTY_EMPLOYEES);
	initSector(sectorList, QTY_SECTORS);
	harcodedSectors(sectorList,QTY_SECTORS, 3);
	id+=harcodedEmployees(employeeList, QTY_EMPLOYEES, 10);

	do{
		option=menu();
		switch(option)
		{
			case 1:
				if(!newEmployee(employeeList,QTY_EMPLOYEES,sectorList,QTY_SECTORS,id))
					id++;
			  break;
			case 2:
				aActiveEmployees=activeEmployees(employeeList,QTY_EMPLOYEES);
				if(aActiveEmployees==0)
				{
					printf("\nError, employee system is empty\n");
				}
				else
				{
					modifyEmploee(employeeList, QTY_EMPLOYEES,sectorList,QTY_SECTORS);
				}
			   break;
			case 3:
				aActiveEmployees=activeEmployees(employeeList,QTY_EMPLOYEES);
				if(aActiveEmployees==0)
				{
					printf("\nError, employee system is empty\n");
					break;
				}
				else
				{
					deleteEmployee(employeeList,QTY_EMPLOYEES,sectorList,QTY_SECTORS);
				}
			  break;
			case 4:
				aActiveEmployees=activeEmployees(employeeList,QTY_EMPLOYEES);
				if(aActiveEmployees==0)
				{
					printf("\nError, employee system is empty\n");
				}
				else
				{
					utn_getNumeroInt(&sort,"\nSort employees from Z-A (1) or from A-Z (2)\n "
							"Option: ","Error, please, try again\n", 1,2,3);
					sortEmployees(employeeList,QTY_EMPLOYEES,sort);
					printEmployees(employeeList,QTY_EMPLOYEES,sectorList, QTY_SECTORS);
					salaries= totalSalaries(employeeList,QTY_EMPLOYEES);
					average= averageSalaries(employeeList,QTY_EMPLOYEES);
					employeesss= activeEmployees(employeeList,QTY_EMPLOYEES);
					printf("\nTotal salaries: $ %.2f",salaries);
					printf("\nActive employees:  %d",employeesss);
					printf("\nAverage Salary: $ %.2f",average);
					fflush(stdin);
					printf("\nEmployees above average salary:\n");
					employeesAboveAverageSalary(employeeList,QTY_EMPLOYEES, sectorList , QTY_SECTORS,average);
				}
			  break;
			case 5:
				aActiveEmployees=activeEmployees(employeeList,QTY_EMPLOYEES);
				if(aActiveEmployees==0)
				{
					printf("\nError, employee system is empty\n");
					break;
				}
				else
				{
					printEmployees(employeeList,QTY_EMPLOYEES,sectorList, QTY_SECTORS);
					system("pause");
					system("cls");
				}
			 break;
		}
	}while(option!=6);

	return 0;
}

int menu()
{
	int option=-1;

	utn_getNumeroInt(&option,
			"\n1) Create new employee\n"
			"2) Modify employee\n"
			"3) Delete employee\n"
			"4) Reports\n"
			"5) Show employees\n"
			"6) Exit\n"
			"Option: ","Error, please, try again\n", 1,6, 3);
	return option;
}
