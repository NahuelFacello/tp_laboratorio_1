/*
 * ArrayEmployees.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "ArraySector.h"
#include "utn_funciones.h"
/*
* \brief To indicate which position in the array is empty,
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param position int returns empty position:
* \return int Return (-1) if Error [There is no empty positions] - (0) if Ok
*
*/
static int searchEmptyPosition(Employee list[],int len, int* position)
{
	int reply=-1;
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==1)
		{
			*position=i;
			reply=0;
			break;
		}
	}
	return reply;
}
// print only one employee by index

void printEmployee(Employee list[],int len, int i,Sector sectorList[],int sectorLen)
{
	int j;
	char auxSector[21];
	for(j=0; j < sectorLen; j++)
	{
		if(list[i].sector==sectorList[j].id)
		{
			fflush(stdin);
			strncpy(auxSector,sectorList[j].sectorName,21);
		}
	}
	printf("%d %12s %12s  %12.2f %15s\n",
						list[i].id,list[i].name,list[i].lastName,list[i].salary,auxSector);
}

int harcodedEmployees(Employee list[], int len, int qty)
{
	int i;
	int count=0;

	Employee auxiliarList[]={
			{2000,"Juan","Martinez",17000,1,0},
			{2001,"Martina","Juarez",16000,2,0},
			{2002,"Maria Rosa","Pampa",22300.25,3,0},
			{2003,"Alejo","Salguero",55450.2,1,0},
			{2004,"Rosa","Gimenez",62250.4,2,0},
			{2005,"Juan Martin","Arrayanes",72000.2,3,0},
			{2006,"Micaela","Rosas",63500.2,1,0},
			{2007,"Guillermo","Rodriguez",89500.5,2,0},
			{2008,"Mariano","Martinez",16300.3,3,0},
			{2009,"Yasmin","Garabatos",18900.2,1,0}
	};

	if(qty<11 && qty<=len)
	{
		for(i=0;i < qty; i++)
		{
			list[i]=auxiliarList[i];
			count++;
		}
	}
	return count;
}

//To indicate that all position in the array are empty
int initEmployee(Employee list[], int len)
{
	int reply=-1;
	int i;
	if(list!=NULL && len>0)
	{
		reply=0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=1;
		}
	}
	return reply;
}

//add in a existing list of employees the values received as parameters
int addEmployee(Employee list[],int len,int id, char name[], char lastName[], float salary, int sector)
{
	int reply=-1;
	int emptyPosition;

	if(list!=NULL && len>0 && id!=0&& name!= NULL && lastName!= NULL && salary>-1 && sector>-1)
	{
		if(!searchEmptyPosition(list,len,&emptyPosition))
		{
			list[emptyPosition].id=id;
			strncpy(list[emptyPosition].name,name,21);
			strncpy(list[emptyPosition].lastName,lastName,21);
			list[emptyPosition].salary=salary;
			list[emptyPosition].sector=sector;
			list[emptyPosition].isEmpty=0;
			reply=0;
		}
	}
	return reply;
}

//find an Employee by Id en returns the index position in array
int findEmployeeById(Employee list[],int len, int id)
{
	int index=-1;
	int i;

	if(list!=NULL && len>0 && id>-1)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}

//Remove a Employee by Id
int removeEmployee(Employee list[],int len, int id)
{
	int reply=-1;
	int i;

	if(list!=NULL && len >0 && id>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				list[i].isEmpty=1;
				reply=0;
				break;
			}
		}
	}
	return reply;
}
// Sort the elements in the array of employees, the argument order indicate UP or DOWN order

int sortEmployees(Employee list[],int len, int order)
{
	int reply=-1;
	int i,j;
	Employee aux;

	if(list!= NULL && len >0 && (order==1 || order==0))
	{
		reply=0;
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(strcmp(list[i].lastName,list[j].lastName)<0 && order==1)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else if(strcmp(list[i].lastName,list[j].lastName)>0 && order==0)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
			}
		}
	}

	return reply;
}

//Print employees by console
int printEmployees(Employee list[],int len,Sector sectorList[], int sectorLen)
{
	int i;
	printf("\n******************** ACTIVE EMPLOYEES **********************\n\n");
	printf("ID         NAME       LASTNAME      SALARY            SECTOR\n\n");
	for(i=0; i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			printEmployee(list,len,i,sectorList,sectorLen);
		}
	}
	return 0;
}

int deleteEmployee(Employee list[],int len,Sector sectorList[],int sectorLen)
{
	int reply=-1;
	int i;
	char answer;
	int employeeId;
	int flag=0;
	int aux;

	printf("\n***************** DELETE EMPLOYEE ***************\n\n");

	utn_getNumeroInt(&employeeId,"\nPlease, enter ID number :", "\nError, try again\n",2000, 3000 ,3);
	for(i=0;i<len;i++)
	{
		if(list[i].id==employeeId && list[i].isEmpty==0)
		{
			flag=1;
			printf("\nID         NAME       LASTNAME      SALARY            SECTOR\n");
			printEmployee(list, len,i,sectorList, sectorLen);
			aux=i;
		}
	}
	if(flag==0)
	{
		printf("\nInvalid ID number\n");
	}
	else
	{
		fflush(stdin);
		utn_getAnswer(&answer, "\nDo you want to delete this employee? y/n", "\nError, try again\n", 3);
		if(answer=='y')
		{
			list[aux].isEmpty=1;
			reply=0;
			printf("\nSuccessfully removed\n\n");
		}else
		{
			printf("\nOperation cancelled\n\n");
		}

	}
	system("\npause");
	system("cls");
	return reply;
}

int modifyEmploee(Employee list[], int len,Sector sectorList[],int sectorLen)
{
	int reply=-1;
	int i;
	char answer;
	int option=0;
	int employeeId;
	int flag=0;
	int aux;
	char name[21];
	char lastName[21];
	float salary;
	int idSector;


	printf("\n***************** MODIFY EMPLOYEE ***************\n");

	utn_getNumeroInt(&employeeId,"\nPlease, enter ID number :", "\nError, try again\n",2000, 3000 ,3);
	for(i=0;i<len;i++)
	{
		if(list[i].id==employeeId && list[i].isEmpty==0)
		{
			flag=1;
			printf("\nID         NAME       LASTNAME      SALARY            SECTOR\n");
			printEmployee(list, len,i,sectorList, sectorLen);
			aux=i;
			break;
		}
	}
	if(!flag)
	{
		printf("\nThat employee does not exist\n");
	}
	else
	{

		utn_getNumeroInt(&option,"\n1) Modify name\n2) Modify last name\n3) Modify salary\n4) Modify sector\nOption: ", "\nError, try again\n",1, 4 ,3);
		switch(option)
		{
			case 1:
				utn_getAChar(name, "\nPlease, enter name: ", "\nError, try again\n", 3, 21);
			  break;

			case 2:
				utn_getAChar(lastName, "\nPlease, enter last name: ", "\nError, try again\n", 3, 21);
			  break;

			case 3:
				utn_getNumeroFloat(&salary, "\n Please, enter salary: ", "\nError, try again\n",1000, 1000000,3);
			  break;

			case 4:
				printAllSector(sectorList, sectorLen);
				utn_getNumeroInt(&idSector,"\nPlease, enter ID sector: ", "\nError, try again\n",1,3,3);
			  break;
		}

		fflush(stdin);
		utn_getAnswer(&answer, "\nSave changes? y/n: ", "\nError, try again\n", 3);
		if(answer=='y')
		{
			switch(option)
			{
				case 1:
					strncpy(list[aux].name,name,21);
				  break;

				case 2:
					strncpy(list[aux].lastName,lastName,21);
				  break;

				case 3:
					list[aux].salary=salary;
				  break;

				case 4:
					list[aux].sector=idSector;
				  break;
			}
			reply=0;
			printf("\nSuccessfully modified\n\n");
		}else
		{
			printf("\nOperation cancelled\n\n");
		}
	}

	system("pause");
	system("cls");
	return reply;
}

int newEmployee(Employee list[],int len,Sector sectorList[],int sectorLen, int id)
{
	int reply=-1;
	char name[21];
	char lastName[21];
	float salary;
	int sector;
	char answer;

	fflush(stdin);
	printf("\n***************** NEW EMPLOYEE ***************\n");
	utn_getAChar(name, "\nPlease, enter name: ", "\nError, try again\n", 3, 21);
	utn_getAChar(lastName, "\nPlease, enter last name: ", "\nError, try again\n", 3, 21);
	utn_getNumeroFloat(&salary, "\n Please, enter salary: ", "\nError, try again\n",1000, 1000000,3);
	printAllSector(sectorList, sectorLen);
	fflush(stdin);
	utn_getNumeroInt(&sector,"\nPlease, enter ID sector: ", "\nError, try again\n",1,3,3);

	utn_getAnswer(&answer, "\nSave changes? y/n: ", "\nError, try again\n", 3);
	if(answer=='y')
	{
		addEmployee(list, len, id, name, lastName,salary, sector);
		reply=0;
	}
	else
	{
		printf("\nAction cancelled ");
	}

	return reply;
}
