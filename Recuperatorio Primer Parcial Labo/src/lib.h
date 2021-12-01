/*
 * lib.h
 *
 *  Created on: Dec 1, 2021
 *      Author: Seether
 */

#ifndef LIB_H_
#define LIB_H_
typedef struct
{
	int id;
	int dni;
	char nombre[20];
	char apellido[20];
	int isEmpty;
}eCliente;

typedef struct
{
	int id;
	int idCliente;
	char equipo[20];
	int estado;
	char operador[20];
	int tiempoEstimado;
	int tiempoReal;
	int isEmpty;
}eAlquiler;

int inicializarClientes(eCliente* listaClientes, int tam);
int buscarLibre(eCliente* listaClientes, int tam);
int altaCliente(eCliente* listaClientes, int tam, int* siguienteID);
int buscarClientePorId(eCliente* listaClientes, int tam, int id);
void mostrarCliente(eCliente miCliente, int tam);
int mostrarClientes(eCliente* listaClientes, int tam);
int modificarCliente(eCliente* listaClientes, int tam);
int bajaCliente(eCliente* listaClientes, int tam);

int nuevoAlquiler(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquieres, int tamAlquiler, int* siguienteIDAlquiler);
int inicializarAlquiler(eAlquiler* listaAlquileres, int tam);
int buscarAlquilerLibre(eAlquiler* listaAlquileres, int tam);
void mostrarAlquiler(eAlquiler miAlquiler, int tam);
int mostrarAlquileres(eAlquiler* listaAlquileres, int tam);
int finAlquiler(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler);
int menuInformes(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler);

int masEquipos(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler);
int promedioRealAlquileres(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler);
#endif /* LIB_H_ */
