#include <iostream>
#include <vector>

using namespace std;

/*
1. a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva
una matriz cuadrada con valores como en los siguientes ejemplos para n=2 y n=3:
*/

// Función para crear una matriz cuadrada con valores consecutivos
vector<vector<int>> create_matrix(int n){

    // Declaración de la matriz, inicializada con ceros
    vector<vector<int>> matrix(n, vector<int>(n));
    int each_number = 1; // esta variable va a ir aumentando de a 1
    
    // Llenamos la matriz con valores consecutivos
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++){
            matrix[i][j] = each_number;
            each_number++; 
        }
    }

    return matrix;
}

/*
b. Proveer un código que imprima el contenido de la matriz, utilizando un único ciclo
for, desde el mayor valor al menor, es decir, para el ejemplo de Para 𝑀2:
Nota: recuerde que se deben imprimir los índices de la matriz
*/

// Función para imprimir la matriz 
void print_matrix(const vector<vector<int>> &matrix , int n){

    //Recorremos la matriz de mayor a menor
    for (int i = n*n-1; i >= 0; i--){
        int row = i/n;
        int col = i%n;
        cout << "M[" << row << "][" << col << "] = " << matrix[row][col] << endl;
    }
}

int main(){
    int n;
    cout << "Ingrese un valor entero positivo mayor a uno: ";
    cin >> n;
    //Verificamos que n sea correcto
    if (n <= 1){
        cout << "El valor ingresado no es válido.\n";
        return 1;
    }
    // Creamos la matriz y la imprimimos
    vector<vector<int>> matrix = create_matrix(n);
    print_matrix(matrix, n);
    return 0;
}
