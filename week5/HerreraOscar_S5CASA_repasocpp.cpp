#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
//8) Haga una función que reciba dos variables una flotante llamada mivarflotante y una entera llamada mivarentera y retorne la variable flotante dividida por la variable entera.    
float funcion_1(float mivarflotante, int mivarentera) {
    return mivarflotante / mivarentera;
}

//10) Haga una función que retorne el mínimo del arreglo de números aleatorios antes creado
int min_array(int array[],int longi){
   int min=array[0];
   for (int i = 1; i < longi; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

//11) Haga una función que reciba el arreglo de números aleatorios antes creado, imprima los números impares y pare de imprimir al encontrar un número mayor a 800
int par_array(int array[],int longi){
    for (int i = 0; i < longi; i++)
    {
        if (array[i]>800)
        {
            break;
        }else if (array[i]%2==0)
        {
            std::cout<<"\n"<<array[i];
        }
    }
    return 0;
}

int main(){
// 1) Inicializar dos variables globales (con valores escogidos por ustedes), una entera y otra flotante.
int En = 5;
float Fl= 3.14;
// 2) Imprimir los valores de las variables en un mensaje: "la primera tiene un valor de XX y la segunda variable tiene un valor de YY"
std :: cout << "la primera tiene un valor de " << En <<" y la segunda variable tiene un valor de \n"<<Fl; 
// 3) Calcular el valor de la segunda variable dividida por la primera e imprimir : "El resultado es ZZ"
float z= Fl/En;
std :: cout << "El resultado es =" << z;
// 4) Crear un arreglo con 300 números enteros aleatorios entre 0 y 900. 
int N=300;
int Array[N];
srand(time(0));
for (int i = 0; i < N; i++)
{
    Array[i]=rand()%901;
}
//5) Hacer una iteración para recorrer dicho arreglo e imprimir todos sus elementos.
int longi = sizeof(Array)/sizeof(Array[0]);;
for (int i = 0; i < longi; ++i) {
        std::cout <<"\n"<< Array[i] << " elemento numero: " <<i;}
//6) Imprimir el quinto elemento del arreglo
std::cout <<"\n Quinto elemeto del Array " << Array[300];
//7) Obtener la longitud del arreglo e imprimir: "la longitud del arreglo es XX" (use la función size(), mire cppreference)

std::cout <<"\n la longitud del arreglo es: " << longi;
//9) Llame su función desde la función main e imprima lo que retorna su función para mivarflotante=17.5 y mivarentera=5.
float mivarflotante=17.5;
int mivarentera=5;
float resultado=funcion_1(mivarflotante,mivarentera);
std :: cout<<resultado;
//10) Haga una función que retorne el mínimo del arreglo de números aleatorios antes creado
std :: cout <<min_array(Array,longi);
//11) Haga una función que reciba el arreglo de números aleatorios antes creado, imprima los números impares y pare de imprimir al encontrar un número mayor a 800
par_array(Array,longi);

return 0;}

