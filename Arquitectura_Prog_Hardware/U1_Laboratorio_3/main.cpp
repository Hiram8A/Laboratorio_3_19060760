/*------------------------------------------------------||
|| FileName:        main.cpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         	TECNM - Campus Chihuahua 			||
|| Description:     Lab_3 - Simulación de Configuración	||
||						de un Convertidor ADC			||
||					   (Herencia & Polimorfismo)		|| 
||														||
|| Authors:         Hiram Ochoa Sáenz					||
|| # de Control:	19060760							||
|| Updated:         05/10/2022							||
|| Version:        	3.1									||
||------------------------------------------------------*/

#include "lab_3.hpp"
#include "ADC_FS.hpp"
#include "ADC_FSPEC.hpp"

using namespace std;

char opc;
short i,bits,cant,num,num_chann;
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
	
	do 												//Validación de Datos # Canales [AN1-AN32]
	{
	    cout<<"Introduce el Número de Canales a Utilizar: ";
	    cin>>cant;
	    num=cant;
	    cout<<endl;
	    cleanbuffin();
	    
	    if(!(num>=1 && num<32))
	    	cout<<" Error, Introduzca el # de Canales [1-32] "<<"\n"<<endl;
			
	}while(cant<1 || cant>32);
	   	
	cout<<"|-----------------------------------------------------------------|\n";
	cout<<"|             ¿Cómo deseas calcular la Frecuencia de Muestreo?    |\n";
	cout<<"|    Opc. 1 Forma Manual  (Fs = f_osc[8 MHZ] / ACK)               |\n";
	cout<<"|    Opc. 2 Forma Directa (Frecuencia Especificada)               |\n";
	cout<<"|-----------------------------------------------------------------|";
	cout<<"\n\n"<<"     Opc: ";
	cin>>opc;
	cout<<"|-----------------------------------------------------------------|"<<"\n"<<endl;
	
	// Validacion de Selección Calculo de Frecuencia de Muestreo
	if(!(opc == '1' || opc == '2')){
		getchar();
		cout<<"Opción Inválida, reinicie el programa"<<endl;
		return 0;
	}
	   	
	do												//Validación de Datos Resolución
	{
		cout<<"Introduce la Resolución [8, 10, 12 (Bits)]:  ";
		cin>>bits;
		cout<<"\n"<<endl;
		cleanbuffin();
		
		if(!(bits == 8||bits == 10||bits == 12))
			cout<<"Resolución no permitida"<<endl;	
		
	}while(!(bits == 8||bits == 10||bits == 12));

	ADC::resol(bits); 								// Resolución de los ADC
	
	// Selección del Tipo de Cálculo de Frecuencia de Muestreo 
	switch(opc){
	
	case '1':{
		
		ADC_FS chann[cant];						// Se Crea Arreglo Objetos ADC_FS (Frec. Muestreo Manual Calculada)
		cout<<"Introduce Factor ACK de la Frecuencia de Muestreo [2,4,8,16,32,64]: ";
		
			do									//Validación de Datos Factor ACK
			{
				cin>>frequence;
				cout<<endl;
				cleanbuffin();
				
				if (!(frequence == 2||frequence == 4||frequence == 8||frequence == 16||frequence == 32||frequence == 64))
				cout<<"Opción Inválida [Factor ACK Inválido] "<<endl;
			
			}while(!(frequence == 2||frequence == 4||frequence == 8||frequence == 16||frequence == 32||frequence == 64));
			
		for(i=0;i<cant;i++)
		{
			do
			{
				cout<<"Introduce el # Canal a Usar [1-32]: ";		//Elección de los canales a usar
			    cin>>num_chann;
			    chann[i].setnam(num_chann);
			    cout<<"\n"<<endl;
			    
			    if(!(num_chann>=1 || num_chann<32 ))				//Validación de Elección de Canal (1-32)
				cout<<"Canal Inexistente"<<endl;
					
			}while(num_chann<1 || num_chann>32 );
		} 
		
		for(i=0;i<cant;i++)
		{
			chann[i].setf(frequence);					// Método Polimorfico
			cout<<"Introduce el Valor a Leer del Canal [Orden respecto a la captura] "<<i+1<<": "; 
			cleanbuffin();
			
			do											//Validación de Datos
			{
				cin>>voltage;							//Lectura del Voltaje de cada Canal
				cout<<"\n"<<endl;
				
				if(voltage>3.3)							// Error
				cout<<"Voltaje mayor a 3.3, vuelva a Intentarlo"<<"\n"<<endl;	
			}
			
			while(voltage>3.3);
			chann[i].capture(voltage);
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
		
		for(i=0;i<cant;i++)								//Ciclo de Impresión de Datos
		{
			cout<<"\n"<<"El Valor Digital del Canal AN"<<chann[i].getnam();
			cout<<" [Frec. Muestreo = "<<chann[i].getf();
			cout<<" MHz]: "<<chann[i].conv()<<"\n"<<endl;
		}
		
		printf("|-----------------------------------------------------------------|\n");
		printf("|             Presione cualquier tecla para salir                 |\n");
		printf("|-----------------------------------------------------------------|\n");
		getchar();
		
	break;
	}
	
	case '2':{
	
		ADC_FSPEC channspec[cant]; // Se Crea Arreglo Objetos ADC_FSPEC (Frecuencia Especificada)
		cout<<"Introduce la Frecuencia de Muestreo [MHz]:  ";
		cin>>frequence;
		cout<<"\n"<<endl;
		
	
		for(i=0;i<cant;i++)
		{
			do
			{
				cout<<"Introduce el # Canal a Usar [1-32]: ";	//Elección de los canales a usar
			    cin>>num_chann;
			    channspec[i].setnam(num_chann);
			    cout<<"\n"<<endl;
			    
			    if(!(num_chann>=1 || num_chann<32 ))			//Validación de Elección de Canal (1-32)
				cout<<"Canal Inexistente"<<endl;
					
			}while(num_chann<1 || num_chann>32 );
		}
	
	for(i=0;i<cant;i++)
	{
		channspec[i].setf(frequence);							// Método Polimorfico
		cout<<"Introduce el Valor a Leer del Canal [Orden respecto a la captura] "<<i+1<<": ";
		cleanbuffin();
										
		do											//Validación de Datos
		{
			cin>>voltage;							//Lectura del Voltaje de cada Canal
			cout<<"\n"<<endl;
			
			if(voltage>3.3)							// Error
			cout<<"Voltaje mayor a 3.3, vuelva a Intentarlo"<<"\n"<<endl;	
		}
		
		while(voltage>3.3);
		channspec[i].capture(voltage);
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
	
	for(i=0;i<cant;i++)								//Ciclo de Impresión de Datos
	{
		cout<<"\n"<<"El Valor Digital del Canal AN"<<channspec[i].getnam();
		cout<<" [Frec. Muestreo = "<<channspec[i].getf();
		cout<<"MHz]: "<<channspec[i].conv()<<"\n"<<endl;
	}

	printf("|-----------------------------------------------------------------|\n");
	printf("|             Presione cualquier tecla para salir                 |\n");
	printf("|-----------------------------------------------------------------|\n");
	getchar();
	
	break;
	}
	
	default:{
		getchar();
		cout<<"Opción Inválida"<<endl;
		return 0;
	}
}		
	return 0;
}
