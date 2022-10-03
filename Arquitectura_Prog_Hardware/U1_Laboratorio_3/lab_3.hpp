/*------------------------------------------------------||
|| FileName:        lab_3.cpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         TECNM - Campus Chihuahua 			||
|| Description:     Encabezado de Declaraci�n de		|| 
||					Clase y Creaci�n Objetos ADC		||
||														||
|| Authors:         Hiram Ochoa S�enz					||
|| # de Control:	19060760							||
|| Updated:         02/10/2022							||
|| Version:         2.0									||
||------------------------------------------------------*/

#pragma once
#include <iostream>						// Biblioteca Operaciones de Entrada/Salida
#include <locale.h>						// Teclado Local
#include <cmath>						//	Biblioteca de Operaciones Matem�ticas B�sicas

class ADC
{
	private:
		static unsigned int res;		// Resoluci�n 8 10 12
		static  float hertz;			// Frecuencia de Muestreo
		float vin;						// Voltaje de Entrada a Vonvertir [0V - 3.3V]
		unsigned int vout;				// Salida Digital en Bits (Seg�n la Resoluci�n)
	
	public:
		Channel();						//Constructor por Defecto
	/*--------------------------------------------------------------|
	|								Setters 						|
	|--------------------------------------------------------------*/
		void capture (float);
		static void resol (int);
		static void frecu(float);
	/*--------------------------------------------------------------|
	|								Getters 						|
	|--------------------------------------------------------------*/		
		static float getf();
		unsigned int conv();
};
