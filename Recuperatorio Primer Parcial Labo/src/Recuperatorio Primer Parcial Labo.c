/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int siguienteID = 1;
	int siguienteIDAlquiler = 1;
	int flagAlta = 0;
	int flagAlquiler = 0;

	eCliente listaClientes[TAMCLI] =
	{
			{0,4002301,"Manuel","Gomez",OCUPADO},
			{1,2202705,"Eusebio","Silva",OCUPADO},
			{2,8012905,"Julian","Alvarez",OCUPADO},
			{3,7702202,"Martin","Palermo",OCUPADO},
			{4,1502006,"Ricky","Centurion",OCUPADO},
	};
	eAlquiler listaAlquileres[TAMALQ] =
	{
			{0,2,"AMOLADORA",1,"Silva",20,50,1},
			{1,1,"MEZCLADORA",1,"Gomez",15,20,1},
			{2,4,"TALADRO",1,"Palermo",10,10,1},
			{3,5,"TALADRO",1,"Centurion",30,29,1},
			{4,1,"TALADRO",1,"Gomez",7,7,1},
			{5,3,"MEZCLADORA",1,"Alvarez",35,30,1}
	};

	//inicializarClientes(listaClientes, TAMCLI);
	//inicializarAlquiler(listaAlquileres, TAMALQ);

    do
    {
		system("cls");
		printf("\n*************MENU*************\n\n");
		printf("1- ALTA CLIENTE\n");
		printf("2- MODIFICAR DATOS CLIENTE\n");
		printf("3- BAJA DEL CLIENTE\n");
		printf("4- NUEVO ALQUILER\n");
		printf("5- FIN DEL ALQUILER\n");
		printf("6- INFORMAR\n");
		printf("7- SALIR\n\n");
		scanf("%d", &opcion);

        switch(opcion)
        {
        	case 1:
        		if(altaCliente(listaClientes, TAMCLI, &siguienteID))
        		{
        			printf("Cliente dado de alta con exito.\n");
        			flagAlta = 1;
        		}
        		else
        		{
        			printf("Hubo un error al dar de alta el cliente.\n");
        		}
        		system("pause");
        	break;

        	case 2:
        		if(flagAlta)
        		{
        			if(modificarCliente(listaClientes, TAMCLI))
        			{
        				printf("Se ha modificado con exito al cliente.\n");
        			}
        			else
        			{
        				printf("No se ha modificado nada o hubo un error.\n");
        			}
        		}
        		else
        		{
        			printf("Error, no hay clientes dados de alta.\n");
        		}
        		system("pause");
        	break;

        	case 3:
        		if(flagAlta)
        		{
        			if(bajaCliente(listaClientes, TAMCLI))
        			{
        				printf("Empleado dado de baja con exito.\n");
        			}
        			else
        			{
        				printf("Hubo un error al dar de baja el empleado.\n");
        			}
        		}
        		else
        		{
        			printf("Error, no hay clientes dados de alta.\n");
        		}
        		system("pause");
        	break;

        	case 4:
        		if(flagAlta)
        		{
        			if(flagAlquiler)
        			{
						if(nuevoAlquiler(listaClientes, TAMCLI, listaAlquileres, TAMALQ, &siguienteIDAlquiler))
						{
							printf("Alquiler dado de alta con exito.\n");
						}
						else
						{
							printf("Hubo un error al dar de alta el alquiler.\n");
						}
        			}
        			else
        			{
        				printf("No hay alquileres cargados.\n");
        			}
        		}
        		else
        		{
        			printf("Error, no hay clientes dados de alta.\n");
        		}
        		system("pause");
        	break;

        	case 5:
        		if(flagAlta)
        		{
        			if(finAlquiler(listaClientes, TAMCLI, listaAlquileres, TAMALQ))
        			{
        				printf("Alquiler finalizado con exito.\n");
        			}
        			else
        			{
        				printf("Hubo un error al finalizar el alquiler.\n");
        			}
        		}
        		else
        		{
        			printf("Error, no hay clientes dados de alta.\n");
        		}
        		system("pause");
        	break;

        	case 6:
        		menuInformes(listaClientes, TAMCLI, listaAlquileres, TAMALQ);
        	break;
        }
    }while(opcion != 7);
	return EXIT_SUCCESS;
}

