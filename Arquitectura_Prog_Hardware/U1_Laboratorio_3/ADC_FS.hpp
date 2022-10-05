/*------------------------------------------------------||
|| FileName:        ADC_FS.hpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         	TECNM - Campus Chihuahua 			||
|| Description:     Clase Heradada para Calcular FS		||
||														||
|| Authors:         Hiram Ochoa Sáenz					||
|| # de Control:	19060760							||
|| Updated:         04/10/2022							||
|| Version:         3.0									||
||------------------------------------------------------*/

#include "lab_3.hpp"
#include <iostream>

using namespace std;

class ADC_FS : public ADC	// Clase Heradada para Calcular FS = f_osc/ack.
{							// Frec. Muestreo Manual Calculada
	public:
	/*--------------------------------------------------------------|
	|								Setter ADC_FS					|
	|--------------------------------------------------------------*/	
		void setf(float);
};
			
								// Polimorfismo 1
	void ADC_FS::setf(float s){
		float _hz;
		
		_hz = 8/s;			// Fs = f_osc / ack -- Fosc 8 MHz
		ADC::setf(_hz);
	}
