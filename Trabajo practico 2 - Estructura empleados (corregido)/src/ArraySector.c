/*
 * ArraySector.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArraySector.h"
#include "ArrayEmployees.h"

/*
* \brief To indicate which position in the array is empty,
* \param list Sector* Pointer to array of Sector
* \param len int Array length
* \param position int returns empty position:
* \return int Return (-1) if Error [There is no empty positions] - (0) if Ok
*
*/

//To indicate that all position in the array are empty
int initSector(Sector list[], int len)
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

int harcodedSectors(Sector list[], int len, int qty)
{
	int i;
	int count=0;

	Sector auxiliarList[]={
			{1,"IT",0},
			{2,"Finance",0},
			{3,"Client Services",0},
	};

	if(qty<4 && qty<=len)
	{
		for(i=0;i < qty; i++)
		{
			list[i]=auxiliarList[i];
			count++;
		}
	}
	return count;
}
//Print sectors by console
void printAllSector(Sector list[], int len)
{
	int i;
	printf("\nID      SECTOR\n");
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			printf("%d %15s\n",list[i].id,list[i].sectorName);
		}
	}
}
