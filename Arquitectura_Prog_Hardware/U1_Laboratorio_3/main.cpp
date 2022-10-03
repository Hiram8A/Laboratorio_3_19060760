/*------------------------------------------------------||
|| FileName:        main.cpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         TECNM - Campus Chihuahua 			||
|| Description:     Lab_3 - Simulaci�n de Configuraci�n	||
||					de un Convertidor ADC				||
||														||
|| Authors:         Hiram Ochoa S�enz					||
|| # de Control:	19060760							||
|| Updated:         02/10/2022							||
|| Version:         2.0									||
||------------------------------------------------------*/

#include "lab_3.hpp"

using namespace std;

short i,bits,cant,num;
float frequence,voltage;

/*------------------------------------------------------|
|				Prototipo de Funciones					|
|------------------------------------------------------*/
void info(void);
void cleanbuffin(void);

int main()
{	
	info();
	setlocale(LC_ALL, "");
	printf("|-----------------------------------------------------------------|\n");
	printf("|                   Convertidor ADC                               |\n");
	printf("|-----------------------------------------------------------------|\n");
	
	do 												//Validacion de Datos # Canales [AN1-AN32]
	{
		    cout<<"Introduce el N�mero de Canales a Utilizar: ";
		    cin>>cant;
		    num=cant;
		    cout<<endl;
		    cleanbuffin();
			//short num =scanf("%d",&cant);
		    
		    if(!(num>=1 && num<32))
		    	cout<<" Error, Introduzca el # de Canales [1-32] "<<"\n"<<endl;
		    /*}
		    if(num==1 && (cant<1 || cant>32)){
		      	cout<<" Error, Introduzca el # de canales [1-32]: "<<"\n"<<endl;
			}*/
			
	}while(cant<1 || cant>32);
	   
	/* Otra Forma de Validacion de Datos # Canales [AN1-AN32]
	cout<<"Introduce el numero de canales que deseas utilizar: ";
	cin>>cant;
	cout<<"\n"<<endl;
	cleanbuffin();
	
	if((cant>=1 && cant<=32)){}
	
	else{
		cout<<"Error, el # Canales es incorrecto"<<endl;
		getchar();
		return 1;	
	}*/
	
	do												//Validacion de datos
	{
		cout<<"Introduce la Resoluci�n [8, 10, 12 (Bits)]:  ";
		cin>>bits;
		cout<<"\n"<<endl;
		cleanbuffin();
		
		if(!(bits == 8||bits == 10||bits == 12))
			cout<<"Resoluci�n no permitida"<<endl;	
		
	}while(!(bits == 8||bits == 10||bits == 12));

	ADC::resol(bits);
	cout<<"Introduce la Frecuencia de Muestreo [Hz]:  ";
	cin>>frequence;
	cout<<"\n"<<endl;
	
	ADC::resol(bits);
	ADC::frecu(frequence);
	ADC canales [cant];								//Creaci�n de objetos seg�n los canales a usar
	
	for(i=0;i<cant;i++)
	{
		cout<<"Introduce el Valor a Leer del Canal "<<i+1<<": ";
		cleanbuffin();
							
							
		do											//Validacion de Datos
		{
			cin>>voltage;							//Lectura del Voltaje de cada Canal
			cout<<"\n"<<endl;
			
			if(voltage>3.3)							// Condici�n de Finalizaci�n 
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
	
	for(i=0;i<cant;i++)								//Ciclo de Impresi�n de Datos
	{
		cout<<"\n"<<"El Valor Digital del Canal AN"<<i+1;
		cout<<" [Frec. Muestreo = "<<ADC::getf();
		cout<<" Hz]"<<": "<<canales[i].conv()<<"\n"<<endl;
	}
	
	printf("|-----------------------------------------------------------------|\n");
	printf("|             Presione cualquier tecla para salir                 |\n");
	printf("|-----------------------------------------------------------------|\n");
	getchar();
	return 0;
}
