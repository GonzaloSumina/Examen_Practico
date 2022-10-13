#include <iostream>
#include <time.h>
#include <string>
void funcion_01(int m[10][10]);
void funcion_02(int m[10][10]);
void funcion_03(int (&m)[10][10]);
void funcion_04(int (&m)[10][10]);
void funcion_05(int m[10][10],int , int , int , int , int , int );
void funcion_06(int (&m)[10][10], int , int );
void funcion_07(int (&m)[10][10]);
void funcion_08(int (&m)[10][10]);
int main(){
	std::system("cls");
	srand(time(NULL));
	int option;
	bool Menu=true;
	int matriz[10][10];
	std::string fila_="\033[33m----------------------------------------------\033[m";
    std::string columna_="\033[33m | \033[m";
    std::cout << fila_ << std::endl;
    std::cout << columna_ << "Universidad Catolica San Pablo          " << columna_ << std::endl;
    std::cout << columna_ << "Curso de Ciencia de la Computacion 1    " << columna_ << std::endl;
    std::cout << columna_ << "Docente: Manuel Eduardo Loaiza Fernandez" << columna_<< std::endl;
    std::cout << columna_ << "Creado por:                             " << columna_<< std::endl;
    std::cout << columna_ << "- Gonzalo Sumina Quispe                 " << columna_<< std::endl;
    std::cout << columna_ << "- Juan Palo Alejandro                   " << columna_<< std::endl;
    std::cout << fila_ << std::endl;
	while(Menu){
		std::cout<<"Seleccione una opcion (1-8).\n";
		std::cout<<"(1)\tInicializar elementos de la matriz con valores \n\taleatorios del 0 al 99.\n";
		std::cout<<"(2)\tImprimir matriz.\n";
		std::cout<<"(3)\tCambiar valor en una posicion de la matriz.\n";
		std::cout<<"(4)\tConvertir los valores de la diagonal en 0.\n";
		std::cout<<"(5)\tBuscar 3 numeros del 0 al 99 y saber la cantidad \n\tde veces que los numeros aparecen en la matriz.\n";
		std::cout<<"(6)\tReemplazar un numero del 0 al 99 dentro de la matriz \n\tpor un numero del 100 al 200.\n";
		std::cout<<"(7)\tEncontrar numeros multiplos de 5 y multiplicarlos por 10,\n\t reemplazando al numero inicial.\n";
		std::cout<<"(8)\tInvertir la matriz.\n";
		std::cout<<"(9)\tSalir.\n";
		std::cin>>option;
		if (option==1){
			funcion_01(matriz);
		}
		else if (option==2){
			funcion_02(matriz);
		}
		else if (option==3){
			funcion_03(matriz);
		}
		else if (option==4){
			funcion_04(matriz);
		}
		else if (option==5){
			int num1, num2, num3, cant_num1=0, cant_num2=0, cant_num3=0;
			for (int i=0; i<3; ++i){
				switch(i){
					case 0:
					std::cout<<"numero 1: ";
					std::cin>>num1;
					if (num1<100 && num1>=0){
						break;
					}
					else{
						std::cout<<"Debe ser del 0 al 99\n";
						--i;
						break;
					}
					case 1: 
					std::cout<<"numero 2: ";
					std::cin>>num2; 
					if (num2<100 && num2>=0){
						break;
					}
					else{
						std::cout<<"Debe ser del 0 al 99\n";
						--i;
						break;
					}
					case 2:
					std::cout<<"numero 3: ";
					std::cin>>num3;
					if (num3<100 && num3>=0){
						break;
					}
					else{
						std::cout<<"Debe ser del 0 al 99\n";
						--i;
						break;
					}
				}
			}
			funcion_05(matriz, num1, num2, num3, cant_num1, cant_num2, cant_num3);
		}
		else if (option==6){
			int num, new_num;
			for (int i=0; i<2; ++i){
				switch(i){
					case 0:
					std::cout<<"numero: ";
					std::cin>>num;
					if (num<100 && num>=0){
						break;
					}
					else{
						std::cout<<"Debe ser del 0 al 99\n";
						--i;
						break;
					}
					case 1:
					std::cout<<"nuevo numero: ";
					std::cin>>new_num;
					if (new_num<=200 && new_num>=100){
						break;
					}
					else{
						std::cout<<"Debe ser del 100 al 200\n";
						--i;
						break;
					}
				}
			}
			funcion_06(matriz, num, new_num);
		}
		else if (option==7){
			funcion_07(matriz);
		}
		else if (option==8){
			funcion_08(matriz);
		}
		else if (option==9){
			Menu=false;
		}
	}
	return 0;
}
void funcion_01(int m[10][10]){
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			m[i][j]=rand()%99;
		}
	}
	return;
}
void funcion_02(int m[10][10]){
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			std::cout<<m[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
	return;
}
void funcion_03(int (&m)[10][10]){
	int fila, columna, new_num;
	std::cout<<"fila: ";
	std::cin>>fila;
	std::cout<<"columna: ";
	std::cin>>columna;
	std::cout<<"nuevo valor: ";
	std::cin>>new_num;
	m[fila][columna]=new_num;
	return;
}
void funcion_04(int (&m)[10][10]){
	int i=0;
	while(i<10){
		m[i][i]=0;
		++i;
	}
	return;
}
void funcion_05(int m[10][10],int num1, int num2, int num3, int cant_num1, int cant_num2, int cant_num3){
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			if (m[i][j]==num1){
				++cant_num1;
			}
			else if (m[i][j]==num2){
				++cant_num2;
			}
			else if (m[i][j]==num3){
				++cant_num3;
			}
		}	
	}
	std::cout<<"Cantidad de numero"<<num1<<": "<<cant_num1;
	std::cout<<"\n"; 
	std::cout<<"Cantidad de numero"<<num2<<": "<<cant_num2;
	std::cout<<"\n"; 
	std::cout<<"Cantidad de numero"<<num3<<": "<<cant_num3;
	std::cout<<"\n"; 
	return;
}
void funcion_06(int (&m)[10][10], int num1, int num2){
	bool encontro=false;
	for (int i=0; i<10; ++i){
		for (int j=0; j<10; ++j){
			if (m[i][j]==num1){
				m[i][j]=num2;
				encontro=true;
			}
		}
	}
	if (encontro==false){
		std::cout<<"Ese numero no existe en la matriz.\n";
	}
	return;
}
void funcion_07(int (&m)[10][10]){
	for (int i=0; i<10; ++i){
		for (int j=0; j<10; ++j){
			if (m[i][j]&5==0){
				m[i][j]=m[i][j]*10;
			}
		}
	}
	return;
}
void funcion_08(int (&m)[10][10]){
	int temp;
	for (int i=0; i<10; ++i){
		for (int j=0; j<10; ++j){
			if (i<=j){
				temp=m[i][j];
				m[i][j]=m[j][i];
				m[j][i]=temp;
			}
		}
	}
	return;
}
