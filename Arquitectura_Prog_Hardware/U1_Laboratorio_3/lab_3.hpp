/*
	Header Declaración Clase y Creación Objetos ADC
	Autor:      	       Hiram Ochoa Saenz
					       Version 1.0
*/

#pragma once
#include <iostream>
#include <locale.h>			// Teclado Local

class ADC
{
	private:
		static unsigned int res;		// Resolución 8 10 12
		static  float hertz;			// Frecuencia de Muestreo
		float vin;						// Voltaje de Entrada a convertir [0V - 3.3V]
		unsigned int vout;				// Salida Digital en Bits (Según la Resolución)
	
	public:
		Channel();					//Constructor por defecto
	
	//Setters
		static void resol (int);
		static void frecu(float);
		
		void capture (float);

    //Getters		
		static float getf();
		unsigned int conv();
};
