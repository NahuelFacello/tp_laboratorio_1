/*
 * Reports.h
 *
 */

#ifndef REPORTS_H_
#define REPORTS_H_

float totalSalaries(Employee list[],int len);
int activeEmployees(Employee list[],int len);
float averageSalaries(Employee list[],int len);
int employeesAboveAverageSalary(Employee list[],int len, Sector sectorList[], int sectorLen,float average);
#endif /* REPORTS_H_ */
