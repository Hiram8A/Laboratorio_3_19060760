/*------------------------------------------------------||
|| FileName:        cleanbuffin.cpp						||
|| Program version: Dev-C++ 5.11						||
|| School:         	TECNM - Campus Chihuahua 			||
|| Description:     Funci�n clean Buffer de entrada		|| 
||					en sustitucion de fflush(stdin)		||
||														||
|| Authors:         Hiram Ochoa S�enz					||
|| # de Control:	19060760							||
|| Updated:         02/10/2022							||
|| Version:         3.1									||
||------------------------------------------------------*/

#include "lab_3.hpp"

void cleanbuffin(void){     
	int ch;
	while ((ch = fgetc(stdin)) != EOF)  /* Brinca o descarta todos los caracteres de stdin, */
	{                                   /* hasta que se encuentra con EOF, llegado al final del buffer.*/
	  if( ch == '\n' ) break;           /* o si encuentra un salto de linea */
	}
}
