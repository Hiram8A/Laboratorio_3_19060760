/*------------------------------------------------------||
|| FileName:        lab_3.hpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         	TECNM - Campus Chihuahua 			||
|| Description:     Encabezado de Declaración de		|| 
||					Clase y Creación Objetos ADC		||
||														||
|| Authors:         Hiram Ochoa Sáenz					||
|| # de Control:	19060760							||
|| Updated:         02/10/2022							||
|| Version:         3.1									||
||------------------------------------------------------*/

#pragma once
#include <iostream>						// Biblioteca Operaciones de Entrada/Salida
#include <locale.h>						// Teclado Local
#include <cmath>						//	Biblioteca de Operaciones Matemáticas Básicas

//using namespace std;

class ADC
{
	private:
		static unsigned int res;		// Resolución 8 10 12
		float vin;						// Voltaje de Entrada a Vonvertir [0V - 3.3V]
		unsigned int vout;				// Salida Digital en Bits (Según la Resolución)
		float hertz;					// Frecuencia de Muestreo
		short int nam;
	
	public:
		Channel(){};					//Constructor por Defecto
		
	/*--------------------------------------------------------------|
	|								Setters 						|
	|--------------------------------------------------------------*/
		void setnam(short int);
		void capture (float);
		static void resol (int);
		//static void frecu(float);
		
		virtual void setf(float);

	/*--------------------------------------------------------------|
	|								Getters 						|
	|--------------------------------------------------------------*/		
		float getf();
		unsigned int conv();
		short int getnam();
};
