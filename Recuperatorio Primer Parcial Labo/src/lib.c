/*
 * lib.c
 *
 *  Created on: Dec 1, 2021
 *      Author: Seether
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "lib.h"

#define VACIO 0
#define OCUPADO 1
#define TAMCLI 100
#define TAMALQ 100

#define AMOLADORA 1
#define MEZCLADORA 1
#define TALADRO 1

#define ALQUILADO 1
#define FINALIZADO 0

int inicializarClientes(eCliente* listaClientes, int tam)
{
    int ret = 0;
    int i;

    if(listaClientes != NULL && tam > 0)
    {
        for(i=1; i<tam; i++)
        {
        	listaClientes[i].isEmpty = VACIO;
        }
        ret = 1;
    }
    return ret;
}

int buscarLibre(eCliente* listaClientes, int tam)
{
    int index = -1;
    int i;

    if(listaClientes != NULL && tam > 0)
    {
        for(i=1; i<tam; i++)
        {
            if(listaClientes[i].isEmpty == VACIO)
            {
            	index = i;
                break;
            }
        }
    }
    return index;
}

int altaCliente(eCliente* listaClientes, int tam, int* siguienteID)
{
	int ret = 0;
	int index;
	int dni;
	char nombre[20];
	char apellido[20];

	if(listaClientes != NULL && tam > 0)
	{
		index = buscarLibre(listaClientes, tam);

		if(index != -1)
		{
			//ID//
			printf("El cliente a ingresar tendra el id: %d\n", *siguienteID);
			listaClientes[index].id = *siguienteID;
			(*siguienteID)++;

			//DNI//
			printf("Ingrese el DNI (mayor a 1000000): ");
			if(validarEntero(&dni, 1000000, 100000000))
			{
				listaClientes[index].dni = dni;
			}

			//NOMBRE//
			if(getNombre(nombre, 20, 3, "Ingrese el nombre del cliente: ", "Error, ingrese un nombre valido.\n"))
			{
				strcpy(listaClientes[index].nombre, nombre);
			}

			//APELLIDO//
			if(getNombre(apellido, 20, 3, "Ingrese el apellido del cliente: ", "Error, ingrese un apellido valido.\n"))
			{
				strcpy(listaClientes[index].apellido, apellido);
			}

			//ISEMPTY//
			listaClientes[index].isEmpty = OCUPADO;
			ret = 1;
		}
	}
	return ret;
}

int buscarClientePorId(eCliente* listaClientes, int tam, int id)
{
	int index = -1;
	int i;

	for(i=1; i<tam; i++)
	{
		if(listaClientes[i].isEmpty == OCUPADO)
		{
			if(listaClientes[i].id == id)
			{
				index = id;
				break;
			}
		}
		else
		{
			index = -1;
		}
	}

	return index;
}

void mostrarCliente(eCliente miCliente, int tam)
{
    printf("%d   %8d     %-10s %-10s\n", miCliente.id, miCliente.dni, miCliente.nombre, miCliente.apellido);
}

int mostrarClientes(eCliente* listaClientes, int tam)
{
	int ret = 0;
	int i;

	if(listaClientes != NULL && tam > 0)
	{
		printf("ID     DNI       NOMBRE    APELLIDO\n");
		printf("**************************************************************************\n");
		for(i=1;i<tam;i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO)
			{
				mostrarCliente(listaClientes[i], tam);
			}
		}
	}

	return ret;
}

int modificarCliente(eCliente* listaClientes, int tam)
{
	int ret = 0;
	int opcion;
	int index;
	int idIngresado;
	char nombre[20];
	char apellido[20];

	mostrarClientes(listaClientes, tam);

	printf("Ingrese el ID que quiere modificar: ");
	fflush(stdin);
	validarEntero(&idIngresado, 1, 100);

	index = buscarClientePorId(listaClientes, tam, idIngresado);

	if(index == idIngresado)
	{
		do
		{
		system("cls");
		printf("\n************* MENU MODIFICACIONES *************\n\n");
		printf("1- MODIFICAR NOMBRE\n");
		printf("2- MODIFICAR APELLIDO\n");
		printf("3- SALIR\n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				if(getNombre(nombre, 20, 3, "Ingrese el nuevo nombre: ", "Error, ingrese un nombre valido"))
				{
					strcpy(listaClientes[index].nombre, nombre);
					ret = 1;
					printf("El nombre ha sido modificado con exito.\n");
				}
			break;

			case 2:
				if(getNombre(apellido, 20, 3, "Ingrese el nuevo apellido: ", "Error, ingrese un apellido valido"))
				{
					strcpy(listaClientes[index].apellido, apellido);
					ret = 1;
					printf("El apellido ha sido modificado con exito.\n");
				}
			break;

			case 3:
				printf("Ha salido con exito.\n");
				ret = 1;
			break;

			default:
				printf("Error, ingrese una opcion valida\n");
			break;
		}

		}while(opcion != 3);
	}
	else
	{
		printf("Error, el ID ingresado no pertenece a ningun cliente.\n");
		system("pause");
	}


	return ret;
}

int bajaCliente(eCliente* listaClientes, int tam)
{
	int ret = 0;
	int idIngresado;
	int indice;

	if(listaClientes != NULL && tam > 0)
	{
		mostrarClientes(listaClientes, tam);

		printf("Ingrese el ID del cliente a dar de baja: ");
		if(validarEntero(&idIngresado, 1, 100))
		{
			indice = buscarClientePorId(listaClientes, tam, idIngresado);
			if(indice != -1)
			{
				listaClientes[indice].isEmpty = VACIO;
				ret = 1;
			}
			else
			{
				printf("Error, no hay ningun cliente con el ID ingresado.\n");
			}
		}
	}
	return ret;
}

int inicializarAlquiler(eAlquiler* listaAlquileres, int tam)
{
    int ret = 0;
    int i;

    if(listaAlquileres != NULL && tam > 0)
    {
        for(i=1; i<tam; i++)
        {
        	listaAlquileres[i].isEmpty = VACIO;
        }
        ret = 1;
    }
    return ret;
}

int buscarAlquilerLibre(eAlquiler* listaAlquileres, int tam)
{
    int index = -1;
    int i;

    if(listaAlquileres != NULL && tam > 0)
    {
        for(i=1; i<tam; i++)
        {
            if(listaAlquileres[i].isEmpty == VACIO)
            {
            	index = i;
                break;
            }
        }
    }
    return index;
}

int nuevoAlquiler(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler, int* siguienteIDAlquiler)
{
	int ret = 0;
	int idIngresado;
	int index;
	int indexAlquiler;
	int equipo;
	int tiempoEstimado;

	mostrarClientes(listaClientes, tamCliente);

	if(listaClientes != NULL && tamCliente > 0 && listaAlquileres != NULL && tamAlquiler > 0)
	{
		indexAlquiler = buscarAlquilerLibre(listaAlquileres, tamAlquiler);

		if(indexAlquiler != -1)
		{
			printf("Ingrese el ID del cliente: ");
			if(validarEntero(&idIngresado, 1, 100))
			{
				index = buscarClientePorId(listaClientes, tamCliente, idIngresado);
			}

			if(index == idIngresado)
			{
				//ID//
				printf("El alquiler a ingresar tendra el id: %d\n", *siguienteIDAlquiler);
				listaAlquileres[indexAlquiler].id = *siguienteIDAlquiler;
				(*siguienteIDAlquiler)++;

				//ID CLIENTE//
				listaAlquileres[indexAlquiler].idCliente = idIngresado;

				//EQUIPO//
				printf("\nLISTA EQUIPOS:\n"
						"1- AMOLADORA\n"
						"2- MEZCLADORA\n"
						"3- TALADRO\n");

				printf("Ingrese el ID del equipo:");
				if(validarEntero(&equipo, 1, 3))
				{
					if(equipo == 1)
					{
						strcpy(listaAlquileres[indexAlquiler].equipo, "AMOLADORA");
					}
					else if(equipo == 2)
					{
						strcpy(listaAlquileres[indexAlquiler].equipo, "MEZCLADORA");
					}
					else if(equipo == 3)
					{
						strcpy(listaAlquileres[indexAlquiler].equipo, "TALADRO");
					}
				}

				//TIEMPO ESTIMADO//
				printf("Ingrese el tiempo estimado (en dias): ");
				if(validarEntero(&tiempoEstimado, 1, 200))
				{
					listaAlquileres[indexAlquiler].tiempoEstimado = tiempoEstimado;
				}

				//OPERADOR//
				strcpy(listaAlquileres[indexAlquiler].operador, listaClientes[index].apellido);

				//ESTADO//
				listaAlquileres[indexAlquiler].estado = ALQUILADO;
				ret = 1;

				//ISEMPTY//
				listaAlquileres[indexAlquiler].isEmpty = OCUPADO;
			}
			else
			{
				printf("Error, no hay ningun cliente con el ID ingresado.\n");
				system("pause");
			}
		}

	}
	return ret;
}

void mostrarAlquiler(eAlquiler miAlquiler, int tam)
{
    printf("%d\t %-10s\t %d\t     %d\t          %-10s  %2d         %2d         %2d\n", miAlquiler.id, miAlquiler.equipo, miAlquiler.estado, miAlquiler.idCliente, miAlquiler.operador, miAlquiler.tiempoEstimado, miAlquiler.tiempoReal, miAlquiler.estado);
}

int mostrarAlquileres(eAlquiler* listaAlquileres, int tam)
{
	int ret = 0;
	int i;

	if(listaAlquileres != NULL && tam > 0)
	{
		printf("ID       EQUIPO         ESTADO    ID_CLIENTE      OPERADOR   TIEMPO_E   TIEMPO_R   ESTADO\n");
		printf("*******************************************************************************************\n");
		for(i=1;i<tam;i++)
		{
			if(listaAlquileres[i].isEmpty == OCUPADO)
			{
				mostrarAlquiler(listaAlquileres[i], tam);
			}
		}
	}

	return ret;
}

int buscarAlquilerPorId(eAlquiler* listaAlquileres, int tam, int id)
{
	int index = -1;
	int i;

	for(i=1; i<tam; i++)
	{
		if(listaAlquileres[i].isEmpty == OCUPADO)
		{
			if(listaAlquileres[i].id == id)
			{
				index = id;
				break;
			}
		}
		else
		{
			index = -1;
		}
	}

	return index;
}

int finAlquiler(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler)
{
	int ret = 0;
	int idIngresado;
	int index;
	int tiempoFinal;

	mostrarAlquileres(listaAlquileres, tamAlquiler);

	printf("\nIngrese el ID a finalizar: ");
	validarEntero(&idIngresado, 1, 100);

	index = buscarAlquilerPorId(listaAlquileres, tamAlquiler, idIngresado);

	if(index == idIngresado)
	{
		//Tiempo Final//
		printf("Ingrese el tiempo real del alquiler (en dias): ");
		validarEntero(&tiempoFinal, 1, 200);
		listaAlquileres[index].tiempoReal = tiempoFinal;

		//Estado//
		listaAlquileres[index].estado = FINALIZADO;
		ret = 1;
	}

	return ret;
}

int menuInformes(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler)
{
	int ret = 0;
	int opcion;

	do
	    {
			system("cls");
			printf("\n*************MENU*************\n\n");
			printf("1- EL NOMBRE Y APELLIDO DEL ASOCIADO CON MAS ALQUILERES\n");
			printf("2- EL O LOS EQUIPO/S MAS ALQUILADO/S Y SU CANTIDAD\n");
			printf("3- EL TIEMPO PROMEDIO REAL DE ALQUILER DE LOS EQUIPOS\n");
			printf("4- TODOS LOS CLIENTES CON SUS ALQUILERES\n");
			printf("7- SALIR\n\n");
			scanf("%d", &opcion);

	        switch(opcion)
	        {
	        	case 1:
	        		printf("Sin realizar.\n");
	        	break;

	        	case 2:
	        		masEquipos(listaClientes, tamCliente, listaAlquileres, tamAlquiler);
	        		system("pause");
	        	break;

	        	case 3:
	        		promedioRealAlquileres(listaClientes, tamCliente, listaAlquileres, tamAlquiler);
	        		system("pause");
	        	break;

	        	case 4:
	        		mostrarAlquileres(listaAlquileres, tamAlquiler);
	        		system("pause");
	        	break;
	        }
	    }while(opcion != 7);

	return ret;
}

/*int masAlquileres(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler)
{
	int ret = 0;
	int i;
	int contadorAlquiler = 0;

	for(i=0;i<tamAlquiler;i++)
	{
		if(listaAlquileres[i].isEmpty==OCUPADO)
		{
			if(listaAlquileres[i].idCliente)
			{

			}
		}
	}


	return ret;
}*/

int masEquipos(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler)
{
	int ret = 0;
	int i;
	int contAmoladora = 0;
	int contMezcladora = 0;
	int contTaladro = 0;

	for(i=0;i<tamAlquiler;i++)
	{
		if(listaAlquileres[i].isEmpty == OCUPADO)
		{
			if(strcmp(listaAlquileres[i].equipo, "AMOLADORA") >0)
			{
				contAmoladora++;
			}
			if(strcmp(listaAlquileres[i].equipo, "MEZCLADORA") >0)
			{
				contMezcladora++;
			}
			if(strcmp(listaAlquileres[i].equipo, "TALADRO") >0)
			{
				contTaladro++;
			}
		}
	}

	if(contTaladro > contMezcladora && contTaladro > contAmoladora)
	{
		printf("El equipo mas alquilado es el TALADRO con %d alquilados", contTaladro);
		ret = 1;
	}
	else if(contMezcladora > contTaladro && contMezcladora > contAmoladora)
	{
		printf("El equipo mas alquilado es la MEZCLADORA con %d alquilados", contMezcladora);
		ret = 1;
	}
	else if(contAmoladora > contTaladro && contAmoladora > contMezcladora)
	{
		printf("El equipo mas alquilado es la AMOLADORA con %d alquilados", contAmoladora);
		ret = 1;
	}

	return ret;
}

int promedioRealAlquileres(eCliente* listaClientes, int tamCliente, eAlquiler* listaAlquileres, int tamAlquiler)
{
	int ret = 0;
	int i;
	int acumuladorTiempoReal = 0;
	int contadorTiempo = 0;
	float promedio;

	for(i=0;i<tamAlquiler;i++)
	{
		if(listaAlquileres[i].isEmpty == OCUPADO)
		{
			if(listaAlquileres[i].tiempoReal > 0)
			{
				acumuladorTiempoReal = acumuladorTiempoReal + listaAlquileres[i].tiempoReal;
				contadorTiempo++;
			}
		}
	}

	promedio = (float)acumuladorTiempoReal / contadorTiempo;

	printf("El promedio del tiempo real de alquileres es de: %.2f", promedio);
	ret = 1;


	return ret;
}
