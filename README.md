# Laboratorios-de-Propulsi-n-por-Reacci-n-SputniK
Programación II
Prof. Marcel Molina
Práctica 4
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
Ejemplo del archivo de entrada 
6 8 
0 3 4 20 15 0 6 8 
5 13 6 8 2 0 2 3 
2 6 2 2 3 0 10 0 
0 0 4 15 4 1 1 20 
0 0 7 2 6 9 10 4 
5 0 6 10 6 4 8 0 
Ejemplo del archivo de salida
