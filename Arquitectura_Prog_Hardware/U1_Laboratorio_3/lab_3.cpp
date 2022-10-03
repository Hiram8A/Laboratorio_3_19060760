/*------------------------------------------------------||
|| FileName:        lab_3.cpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         TECNM - Campus Chihuahua 			||
|| Description:     Implementación Métodos Clase ADC	||
||														||
|| Authors:         Hiram Ochoa Sáenz					||
|| # de Control:	19060760							||
|| Updated:         02/10/2022							||
|| Version:         2.1									||
||------------------------------------------------------*/

#include "lab_3.hpp"

using namespace std;

/*--------------------------------------------------------------|
|					Init Var Static - Clase ADC					|
|--------------------------------------------------------------*/
unsigned int ADC::res = 0;
float ADC::hertz = 0;

/*--------------------------------------------------------------|
|						Métodos Clase ADC 						|
|--------------------------------------------------------------*/
void ADC::resol(int _rs) {res = _rs;}

void ADC::frecu(float _hz) {hertz = _hz;}

void ADC::capture(float _v) {vin = _v;}

float ADC:: getf () {return hertz;}

unsigned int ADC::conv()
{	
	//Conversion del ADC
	vout = (vin*pow(2,res)-1)/3.3;
	// Salida Digital = [vin*(2^(res)) – 1] / ViFS
	// res 	= Es el número de Bits que tiene el Convertidor Analógico Digital
	// vin	= Voltaje Entrada
	// ViFS = Voltaje a la entrada del convertidor ADC para obtener una
	// 		  conversión máxima (Todas las salidas serán iguales a “1”)
	return vout;
}
