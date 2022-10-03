/*
	Header Implementaci�n M�todos Clase ADC
	Autor:      	       Hiram Ochoa Saenz
					       Version 1.0
*/

#include "lab_3.hpp"
#include <iostream>
#include <cmath>

using namespace std;

// Init Var Static - Clase ADC
unsigned int ADC::res = 0;
float ADC::hertz = 0;

// Metodos clase ADC
void ADC::resol(int _rs) {res = _rs;}

void ADC::frecu(float _hz) {hertz = _hz;}

void ADC::capture(float _v) {vin = _v;}

float ADC:: getf () {return hertz;}

unsigned int ADC::conv()
{	
	//Conversion del ADC
	vout = (vin*pow(2,res)-1)/3.3;
	//Resoluci�n = ViFS / [2(res) � 1]
	// res = es el n�mero de bits que tiene el Convertidor Anal�gico Digital
	// ViFS = es el voltaje que hay que poner a la entrada del convertidor ADC para
	// 		  obtener una conversi�n m�xima (todas las salidas ser�n iguales a �1�
	return vout;
}
