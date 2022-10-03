/*
	Header Implementación Métodos Clase ADC
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
	//Resolución = ViFS / [2(res) – 1]
	// res = es el número de bits que tiene el Convertidor Analógico Digital
	// ViFS = es el voltaje que hay que poner a la entrada del convertidor ADC para
	// 		  obtener una conversión máxima (todas las salidas serán iguales a “1”
	return vout;
}
