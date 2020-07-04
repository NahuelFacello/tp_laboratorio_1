/*
 * Reports.h
 *
 *  Created on: 28 may. 2020
 *      Author: Nahu
 */

#ifndef REPORTS_H_
#define REPORTS_H_

void menu();
void menu_sort();
void menu_sort_orden();

int employee_ordenarPorNombre(void* pEmployee1, void* pEmployee2);
int employee_ordenarPorId(void* pEmployee1, void* pEmployee2);
int employee_ordenarPorSueldo(void* pEmployee1, void* pEmployee2);
int employee_ordenarPorHorasTrabajadas(void* pEmployee1, void* pEmployee2);

#endif /* REPORTS_H_ */
