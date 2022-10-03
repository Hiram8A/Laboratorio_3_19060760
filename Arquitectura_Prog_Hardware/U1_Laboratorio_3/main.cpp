/*
	Header main
	Autor:      	       Hiram Ochoa Saenz
					       Version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include "lab_3.hpp"

using namespace std;

short i,bits,cant;
float frequence,voltage;

/*------------------------------------------------------|
|				Prototipo de Funciones					|
|------------------------------------------------------*/
void info(void);

int main()
{	
	info();
	setlocale(LC_ALL, "");
	printf("|-----------------------------------------------------------------|\n");
	printf("|                   Convertidor ADC                               |\n");
	printf("|-----------------------------------------------------------------|\n");
	
	cout<<"Introduce el numero de canales que deseas utilizar: ";
	cin>>cant;
	cout<<"\n"<<endl;
	
	do					//Validacion de datos
	{
		cout<<"Introduce la Resolución [8, 10, 12 (Bits)]:  ";
		cin>>bits;
		cout<<"\n"<<endl;
		fflush(stdin);
		
		if(!(bits == 8||bits == 10||bits == 12))
			cout<<"Resolución no permitida"<<endl;	
		
	}while(!(bits == 8||bits == 10||bits == 12));

	ADC::resol(bits);
	cout<<"Introduce la Frecuencia de Muestreo [Hz]:  ";
	cin>>frequence;
	cout<<"\n"<<endl;
	
	ADC::resol(bits);
	ADC::frecu(frequence);
	ADC canales [cant];		//Creacion de objetos segun los canales a usar
	
	for(i=0;i<cant;i++)
	{
		cout<<"Introduce el Valor a Leer del Canal "<<i+1<<": ";
		fflush(stdin);
		
							//Validacion de datos
		do					
		{
			cin>>voltage;	//Lectura del voltaje de cada canal
			cout<<"\n"<<endl;
			
			// Condicion de Finalizacion
			if(voltage>3.3) 
			cout<<"Voltaje mayor a 3.3, vuelva a Intentarlo"<<"\n"<<endl;	
		}
		
		while(voltage>3.3);
		canales[i].capture(voltage);
	}
	
	getchar();
	printf("|-----------------------------------------------------------------|\n");
	printf("|             Presione cualquier tecla para continuar             |\n");
	printf("|-----------------------------------------------------------------|\n");
	getchar();
	system("cls");
	
	printf("|-----------------------------------------------------------------|\n");
	printf("|             Valores Digitales Obtenidos del ADC                 |\n");
	printf("|-----------------------------------------------------------------|\n");
	
	for(i=0;i<cant;i++)		//Ciclo for para la impresion de datos
	{
		cout<<"\n"<<"El Valor Digital del Canal AN"<<i;
		cout<<" [Frec. Muestreo = "<<ADC::getf();
		cout<<" Hz]"<<": "<<canales[i].conv()<<"\n"<<endl;
	}
	
	printf("|-----------------------------------------------------------------|\n");
	printf("|             Presione cualquier tecla para salir                 |\n");
	printf("|-----------------------------------------------------------------|\n");
	getchar();
	return 0;
}

void info(void)
	{
		setlocale(LC_ALL, "");
		printf("|-----------------------------------------------------------------|\n");
	  	printf("|                   TECNM - Campus Chihuahua                      |\n");
	  	printf("|                                                                 |\n");
		printf("|               Instituto Tecnológico de Chihuahua                |\n");
		printf("|                                                                 |\n");
		printf("|         Arquitectura de Programación para Control de Hardware   |\n");
		printf("|                                                                 |\n");
		printf("|                  Laboratorio 3 -  Configuración ADC             |\n");
		printf("|                                                                 |\n");
		printf("|                      Alumno: Hiram Ochoa Sáenz                  |\n");
		printf("|                                                                 |\n");
		printf("|                      Número de Control: 19060760                |\n");
		printf("|                                                                 |\n");
		printf("|                  Docente: M.C. Alfredo Chacón                   |\n");
		printf("|                                                                 |\n");
		printf("|-----------------------------------------------------------------|\n");
		printf("|             Presione cualquier tecla para continuar             |\n");
		printf("|-----------------------------------------------------------------|\n");
		getchar();
		system("cls");
	}
