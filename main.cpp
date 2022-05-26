#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include<stdlib.h>
#include<cmath>
#include<iomanip>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//abro archivo de lectura
	string nombreArchivo = "estrellas.in";
    ifstream archivo(nombreArchivo.c_str());
    string text;
    getline(archivo,text);//primera linea que me da dimensiones
    string espacios=" ";//delimitador para las separaciones
    //cout<<text<<endl;//muestro la linea
    vector<string> numeros{};//vector de cadenas para guardar la entrada
	//primera linea
    size_t pos = 0;//posiciono al inicio
    while ((pos = text.find(espacios)) != string::npos) {
        numeros.push_back(text.substr(0, pos));//parto buscando espacios
        text.erase(0, pos + espacios.length());
    }
    
//	cout<<"Filas " <<numeros[0]<<endl;//filas
//	cout<<"Columnas " <<numeros[1]<<endl;//Columnas
	//declaro lo que sera mi numero de fila y columnas ademas de armar una matriz
	int filas=stoi(numeros[0]),columnas=stoi(numeros[1]);
    int MD[filas+2][columnas+2];
    int num;
	double expresion=0.0,circundante=0;//para tomar en cuenta los decimales
    bool estrella=false;
	
    if(filas<10||columnas<10){// filas y columnas deben ser menores que 10 por enunciado
    
	    for(int fil=0; fil<=filas+1;fil++){//para leer cada linea del documento
	    num=0;
	    //leo y separo cada linea en sus cadenas
		    vector<string> numerosMD{};
			size_t pos = 0;
			if(fil>0){
				getline(archivo,text);
			    while ((pos = text.find(espacios)) != string::npos) {
			        numerosMD.push_back(text.substr(0, pos));
			        text.erase(0, pos + espacios.length());
			    }
			   
			}
			    	
			
			
		    
		    for(int col=0;col<=columnas+1;col++){//cargo el vector con todos los datos
		    	if(fil==0||col==0||fil==filas+1||col==columnas+1){//lleno los margenes laterales con cero para no salirme del mapa al calcular
		    		MD[fil][col]=0;	
				}
				else if(fil!=0||col!=0){
					
					MD[fil][col]=stoi(numerosMD[num]);	//lleno la matriz con los valores dados en cada linea
					num++;//me muevo un espacio para asignar el siguiente dato
				}
				
				//cout<<" "<<left<<setw(2)<<MD[fil][col];
				
			}
			
			//cout<<endl;
		}
		//cout<<"CIRCUNDANTES"<<endl;
		//crear archivo de escritura
		ofstream archivo;
		archivo.open("estrellas.out",ios::out);//abrir
		//verifico errores de apertura
		if(archivo.fail()){
			exit(1);//salida inmediata del programa
		}
		//
		char MatrizFinal[filas+2][columnas+2];//la que se imprimira en el archivo
		//calcular estrellas
		for(int i=0; i<=filas+1; i++){
			for(int j=0;j<=columnas+1;j++){
				if(i==0||j==0||i==filas+1||j==columnas+1){//para los bordes ahora seran numeros que indican la posición
			    	circundante=0;
			    	
			    	if(i==0&&j==0||i==0&&j==columnas+1||i==filas+1&&j==0||i==filas+1&&j==columnas+1){
			    		MatrizFinal[i][j]=32;
			    		archivo<<left<<setw(2)<<MatrizFinal[i][j];
					}else
					if(i==0||i==filas+1){
						MatrizFinal[i][j]=48+j;
						archivo<<left<<setw(2)<<MatrizFinal[i][j];
					}else
					if(j==0||j==columnas+1){
						MatrizFinal[i][j]=48+i;
						archivo<<left<<setw(2)<<MatrizFinal[i][j];
					}
			   	
				cout<<left<<setw(2)<<MatrizFinal[i][j];
				}else{//todos los valores de denro del borde
					circundante=(MD[i][j]+MD[i-1][j-1]+MD[i-1][j]+MD[i-1][j+1]+MD[i][j-1]+MD[i][j+1]+MD[i+1][j-1]+MD[i+1][j]+MD[i+1][j+1]);//calculo los circundantes /Universidad Nacional Experimental del Táchira Ingenieria Informatica Programacion 2 Profesor Marcel Molina Autor: José Alejandro Valduz Contreras Practica 4

					if(circundante<=180&&circundante>0){//180 es el maximo ya que cada intensidad debe llegar maximo a 20 y son 9 a sumar
						expresion=circundante/5;//me da el valor decimal
						if(expresion>10.0){
							//aqui seran las estrellas
							MatrizFinal[i][j]='*';
							archivo<<left<<setw(2)<<MatrizFinal[i][j];
							cout<<left<<setw(2)<<MatrizFinal[i][j];		
						}else{
							//estos seran espacios vacios
							MatrizFinal[i][j]=' ';
							archivo<<left<<setw(2)<<MatrizFinal[i][j];
							cout<<left<<setw(2)<<MatrizFinal[i][j];
						}
						
					}
				}
				
			}
			cout<<endl;
			archivo<<endl;
		}
		archivo.close();
	}else{
		cout<<"Los Rangos superan el Valor de la Matriz"<<endl;
	}
	    	
	
	getchar();
	return 0;
}
/*
Universidad Nacional Experimental del Táchira
Ingenieria Informatica
Programacion 2 Profesor Marcel Molina
Autor: José Alejandro Valduz Contreras
Practica 4
Problema 1
Estrellas

Archivo de entrada: estrellas.in, salida: estrellas.out

Trabajas para los Laboratorios de Propulsión por Reacción Sputnik. En este 
momento es necesario que escribas un programa que lea una matriz, la cual 
contiene una representación digitalizada de una fotografía del cielo. Cada 
elemento de la matriz representa la cantidad de luz que existe en 
determinada región de la imagen digitalizada. El rango de intensidad va de 
0 a 20. El programa permitirá localizar las regiones donde se ubica una 
estrella, partiendo de la siguiente información: 
Una estrella se encuentra en el área cubierta por el elemento i,j de la 
matriz si se cumple la siguiente condición: 
(MD(i,j) + suma de intensidades circundantes)/5 > 10.0 
Donde MD representa la matriz digitalizada. 

Entrada 
La primera línea son dos enteros menores que 10 que indican el número de 
filas y columnas de la matriz, las siguientes líneas contienen enteros que 
representan las intensidades de cada posición de la matriz, separados por 
un blanco. 

Salida 
La salida deseada es la matriz que contiene un asterisco en la posición 
donde está localizada una estrella, y un blanco donde no la hay. La matriz 
debe estar circundada por un borde que indique las coordenadas de cada 
estrella. La coordenada inicial es 1. Cada elemento de la matriz debe estar 
separado por un espacio en blanco. 
*/
