/*
 * ArraySector.h
 *
 */

#ifndef ARRAYSECTOR_H_
#define ARRAYSECTOR_H_

typedef struct Sector{
	int id;
	char sectorName[22];
	int isEmpty;
}Sector;

/*
* \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Sector* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initSector(Sector list[], int len);

/** \brief hardcoding a Sector array up to 3
* \param list Sector*
* \param length int
* \param qty int (limit=3)
* \return count int = qty
*
*/
int harcodedSectors(Sector list[], int len, int qty);

/** \brief print the content of sectors array
* \param list Sector*
* \param length int
*
*/
void printAllSector(Sector list[], int len);

#endif /* ARRAYSECTOR_H_ */
