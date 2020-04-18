/*
 ============================================================================
 Name        : Trabajo practico 1 - Calculadora
 Author      : Nahuel Facello - 1E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_funciones.h"


int main()
{
	int variableA=0;
	int variableB=0;
	int suma;
	int resta;
	int multiplicacion;
	int opcion;
	int respuestaMenu;
	float division;
	int factorialA;
	int factorialB;
	int respuestaFactorialA;
	int respuestaFactorialB;


	setbuf(stdout, NULL);
	do
	{
		printf("\n1.Ingresar 1er operando (A=%d)\n2.Ingresar 2do operando (B=%d)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",variableA,variableB);
		respuestaMenu = utn_getNumeroInt(&opcion,"","\nNo es una opcion valida\n",1,5,3);
		if(respuestaMenu==0)// Significa que respuesta ==0
		{
				switch(opcion)
				{
					case 1:
						utn_getNumeroCalculadora(&variableA,"Ingrese un valor para la  variable A\n");
						break;
					case 2:
						utn_getNumeroCalculadora(&variableB,"Ingrese un valor para la  variable B\n");
						break;
					case 3:
						utn_suma(&suma,variableA,variableB);
						utn_resta(&resta,variableA,variableB);
						utn_multiplicacion(&multiplicacion,variableA,variableB);
						utn_division(&division,variableA,variableB);
						respuestaFactorialA=utn_factorial(&factorialA,variableA);
						respuestaFactorialB=utn_factorial(&factorialB,variableB);
						break;
					case 4:
						printf("\na. La suma de A+B es : %d",suma);
						printf("\nb. La resta de A-B es : %d",resta);
						printf("\nc. La multilplicacion de AxB es : %d",multiplicacion);
						if(variableB==0)
							{
								printf("\nd. No se puede dividir por 0");
							}
						else{
							printf("\nd. La division de A/B es : %.2f",division);
						}
						if(respuestaFactorialA==-1)
						{
							printf("\ne. No se puede realizar el factorial de A!");
						}else
						{
							printf("\ne. El factorial de A! es %d",factorialA);
						}
						if(respuestaFactorialB==-1)
						{
							printf(" y no se pude realizar el factorial de B!\n");
						}else
						{
							printf(" y el factorial de B! es %d\n",factorialB);
						}

						system("pause");
						break;
				}
		}
		system("cls");
	}while(opcion !=5);
	system("pause");
}
