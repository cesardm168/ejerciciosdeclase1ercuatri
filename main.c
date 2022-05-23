/*
 ============================================================================
 Name        : borrador.c
 Author      : cesar davila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/// @fn int menu(despliega el menu de la aplicacion)
/// @brief se declara opcion variable a retorna
/// @pre se utilizan varios print para mostrar el menu al usuario
/// @return opcion la cual se va a utilizar para seleccionar las opciones del  menu
int menu();

/// @fn int numerosPositivos(funcion para saber si son numeros positivos mayores a 0)
/// @brief declaramos variable a
/// @param verifica  el numero ingresado es mayor a 0 y no es negativo
/// @return retorna la verificacion del numero
void  numeroPositivo(int);


/** \brief
 *
 * \param precio int
 * \param Km int
 * \param debito int*
 * \param credito int*
 * \param bitcoin float*
 * \param precioKm float*
 * \return int
 *
 */
void  costosDeVuelo(int precio, int Km, float *debito, float *credito, float *bitcoin,float *precioKm);
//int  costosDeVuelo2(int precio, int Km, int *debito, int *credito, float *bitcoin,float *precioKm);

/** \brief
 *
 * \param debito int
 * \param credito int
 * \param bitcoin float
 * \param precioKm float
 * \return int
 *
 */
int informarCostos(int debito, int credito, float bitcoin, float precioKm);

int main(void) {
	//setbuf(stdout, NULL);

	//int opcion;
	char salir = 'n';
	int kilometros;
	int precioAerolineas;
	int precioLatam;
	float debito;
	float credito;
	float bitcoin;
	float precioKm;
	float debito2;
	float credito2;
	float bitcoin2;
	float precioKm2;
	int diferenciaPrecio = 0;

	do {

		switch (menu()) {

		case 1:
			printf("Ingrese los Kilometros: ");
			fflush(stdin);
			scanf("%d", &kilometros);
			numeroPositivo(kilometros);
			break;

		case 2:
			printf("Precio vuelo Aerolíneas:  ");
			fflush(stdin);
			scanf("%d", &precioAerolineas);
			numeroPositivo(precioAerolineas);

			printf("Precio vuelo Latam:  ");
			fflush(stdin);
			scanf("%d", &precioLatam);
			numeroPositivo(precioLatam);
			break;

		case 3:
			costosDeVuelo(precioAerolineas, kilometros, &debito, &credito,	&bitcoin, &precioKm);
			costosDeVuelo(precioLatam, kilometros, &debito2, &credito2,	&bitcoin2, &precioKm2);
			diferenciaPrecio = precioAerolineas - precioLatam;
			printf("costos Calculados\n");
			break;

		case 4:
			printf("Aerolíneas:\n\n");
			informarCostos(debito, credito, bitcoin, precioKm);
			printf("Latam:\n ");
			informarCostos(debito2, credito2, bitcoin2, precioKm2);
			printf("La diferencia de precio es : %d\n", diferenciaPrecio);
			break;

		case 5:

			printf("Aerolíneas:\n\n");
			costosDeVuelo(162965, 7090, &debito, &credito, &bitcoin, &precioKm);
			informarCostos(debito, credito, bitcoin, precioKm);
			printf("Latam:\n\n ");
			costosDeVuelo(159339, 7090, &debito, &credito, &bitcoin, &precioKm);
			informarCostos(debito, credito, bitcoin, precioKm);

			printf("La diferencia de precio es : %d\n", 162965 - 159339);
			break;

		case 6:

			printf("Confirma Salida: s ó n\n");
			fflush(stdin);
			scanf("%c", &salir);
			break;
		default:
			printf("Opcion Invalida\n");
		}
		system("pause");
	} while (salir != 's');
	return EXIT_SUCCESS;
}

int menu() {
	int opcion;
	printf("\n\n\n***  Menu de Opciones  ***\n\n");
	printf("1- Ingresar Kilometros\n");
	printf("2- Ingresar Precios de Vuelos \n");
	printf("3- Calcular todos los costos \n");
	printf("4- Informar Resultados\n");
	printf("5- Carga Forzada de Datos\n");
	printf("6- Salir \n\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	//system(cls);
	return opcion;
}

void numeroPositivo(int a) {

	while (a == 0 || a < 0) {
		printf("ERROR, Ingrese un valor adecuados: positivo y mayor a 0: ");
		fflush(stdin);
		scanf("%d", &a);
	}

//	return a;
}

void costosDeVuelo(int precio, int km, float* debito, float* credito, float* bitcoin, float* precioKm) {

	*debito = precio * 0.90; //descuento debito
	*credito = precio * 1.25;//interes credito
	*bitcoin = (float) precio / 4517428.09;//bitcoin a precio de hoy 12/04 4,517,428.09
	*precioKm = (float) precio / km;


}


int informarCostos(int debito, int credito, float bitcoin, float precioKm) {

	printf("a) Precio con tarjeta de débito: %d\n", debito);
	printf("b) Precio con tarjeta de crédito: %d\n", credito);
	printf("c) Precio pagando con bitcoin : %.7f\n", bitcoin);
	printf("d) Precio unitario: %.2f\n", precioKm);

	return 0;
}

