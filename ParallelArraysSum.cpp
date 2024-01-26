// ParallelArraysSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
#include <iostream>

#define N 20000
#define chunk 5000
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{

    # ifdef _OPENMP
        std::cout << "OMP Disponible" << std::endl;
    # endif

    float a[N], b[N], c[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = rand();
        b[i] = rand();
    }

    int i;
    int pedazos = chunk;
    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    std::cout << "N: " << N << std::endl;
    std::cout << "Chunk: " << chunk << std::endl;
    std::cout << "Show: " << mostrar << std::endl;

    std::cout << "Primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float* d)
{
    for (int i = 0; i < mostrar; i++)
    {
        std::cout << d[i] << " - ";
    }
    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu