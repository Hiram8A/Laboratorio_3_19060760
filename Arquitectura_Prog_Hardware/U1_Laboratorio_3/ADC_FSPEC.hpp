/*------------------------------------------------------||
|| FileName:        ADC_FSPEC.hpp						||
|| Program version: Dev-C++ 5.11						||
|| School:         	TECNM - Campus Chihuahua 			||
|| Description:     Clase Heradada para					||
||					Frecuencia Especificada				||
||														||
|| Authors:         Hiram Ochoa Sáenz					||
|| # de Control:	19060760							||
|| Updated:         04/10/2022							||
|| Version:         3.0									||
||------------------------------------------------------*/

#include "lab_3.hpp"
#include <iostream>

using namespace std;

class ADC_FSPEC : public ADC		// Clase Heredada para Frecuencia Especificada
{ 
	public:
	/*--------------------------------------------------------------|
	|								Setter ADC_FMANUAL				|
	|--------------------------------------------------------------*/		
		void setf(float);
};

								// Polimorfismo 2
	void ADC_FSPEC::setf(float _hz){
		ADC::setf(_hz);
	}
