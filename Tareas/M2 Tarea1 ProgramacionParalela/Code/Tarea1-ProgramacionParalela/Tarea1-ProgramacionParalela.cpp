// Tarea1-ProgramacionParalela.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

#define N 2000
#define chunk  200
#define mostrar 20

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo\n";
    float a[N], b[N], c[N];
    int i;

    // LLenamos los arrays con numeros aleatorios
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 4) * 3.5;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    
    //Ejecutamos el ciclo para la suma    
    for(i=0; i < N; i++)
       c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

}

void imprimeArreglo(float* d)
{
    //Recivimos como parametro el arreglo d de tipo float
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}