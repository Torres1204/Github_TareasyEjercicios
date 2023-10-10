#include <iostream>

#define N_FILAS 2
#define N_COLUS 3

void imprimir_matriz(float **matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void llenar_matriz(float **matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            std::cout << "Ingresa el elemento (" << i+1 <<", " << j+1 << "): ";
            std::cin >> matriz[i][j];
        }
    }
}

// Funcion para sumar dos matrices
void suma_matrices(float **matriz1, float **matriz2, float **resultado, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Funcion para restar dos matrices
void resta_matrices(float **matriz1, float **matriz2, float **resultado, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

// Funcion para multiplicar dos matrices
void multiplicar_matrices(float **matriz1, float **matriz2, float **resultado, int filas1, int columnas1, int columnas2)
{
    for (int i = 0; i < filas1; i++)
    {
        for (int j = 0; j < columnas2; j++)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas1; k++)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main()
{
    float **matriz1;
    float **matriz2;
    float **resultado;

    matriz1 = new float*[N_FILAS];
    matriz2 = new float*[N_FILAS];
    resultado = new float*[N_FILAS];

    for (int i = 0; i < N_FILAS; i++)
    {
        matriz1[i] = new float[N_COLUS];
        matriz2[i] = new float[N_COLUS];
        resultado[i] = new float[N_COLUS];
    }

    std::cout << "-----------CALCULADORA DE MATRICES-----------" << std::endl;
    std::cout << "\nIngresa los elementos de la primera matriz:" << std::endl;
    llenar_matriz(matriz1, N_FILAS, N_COLUS);

    std::cout << "\nIngresa los elementos de la segunda matriz:" << std::endl;
    llenar_matriz(matriz2, N_FILAS, N_COLUS);

    // Realizar operaciones
    suma_matrices(matriz1, matriz2, resultado, N_FILAS, N_COLUS);
    std::cout << "\nSuma de matrices:" << std::endl;
    imprimir_matriz(resultado, N_FILAS, N_COLUS);

    resta_matrices(matriz1, matriz2, resultado, N_FILAS, N_COLUS);
    std::cout << "\nResta de matrices:" << std::endl;
    imprimir_matriz(resultado, N_FILAS, N_COLUS);

    // Para multiplicar, el n�mero de columnas de la matriz 1 debe ser igual al n�mero de filas de la matriz 2.
    if (N_COLUS == N_FILAS)
    {
        multiplicar_matrices(matriz1, matriz2, resultado, N_FILAS, N_COLUS, N_COLUS);
        std::cout << "\nMultiplicacion de matrices:" << std::endl;
        imprimir_matriz(resultado, N_FILAS, N_COLUS);
    }
    else
    {
        std::cout << "\nNo se puede realizar la multiplicacion de matrices debido a dimensiones incorrectas." << std::endl;
    }

    for (int i = 0; i < N_FILAS; i++)
    {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] resultado[i];
    }

    delete[] matriz1;
    delete[] matriz2;
    delete[] resultado;

    return 0;
}

