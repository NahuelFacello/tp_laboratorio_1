/*
 * Reports.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "ArraySector.h"

float totalSalaries(Employee list[],int len)
{
	int i;
	float salariesSum=0;

	for(i=0; i < len; i++)
	{
		if(list[i].isEmpty==0)
		{
			salariesSum+=list[i].salary;
		}
	}
	return salariesSum;
}
int activeEmployees(Employee list[],int len)
{
	int active=0;
	int i;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==0)
		{
			active++;
		}
	}
	return active;
}
float averageSalaries(Employee list[],int len)
{
	float average;
	float salariesSum;
	int acEmployees;

	salariesSum=totalSalaries(list,len);
	acEmployees=activeEmployees(list,len);

	average=(float)salariesSum/acEmployees;

	return average;
}

int employeesAboveAverageSalary(Employee list[],int len, Sector sectorList[], int sectorLen, float average)
{
	int reply=-1;
	int i;


	if( (list!=NULL) && (len >0)  && (sectorList!= NULL) && (sectorLen>0) )
	{
		reply=0;

		printf("\nID         NAME       LASTNAME      SALARY            SECTOR\n");
		for(i=0; i < len; i++)
		{
			if(list[i].salary > average && list[i].isEmpty==0)
			{
				printEmployee(list,len, i,sectorList,sectorLen);
			}
		}
	}
	return reply;
}
