/*
 * validaciones.h
 *
 *  Created on: Nov 20, 2021
 *      Author: Seether
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


int validarEntero(int* datoValidar, int minimo, int maximo);
int getString(char cadena[], int len, int intentos, char mensaje[], char mensajeError[]);
int getNombre(char nombre[], int len, int intentos, char mensaje[], char mensajeError[]);
int validarCaracter(char* datoValidar, char primeraOpcion, char segundaOpcion);

#endif /* VALIDACIONES_H_ */
