#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cassert>

#define EXEC_EXPERIMENTO 5

using namespace std;
/**
 * @brief Cria uma matriz de dimensao nxm com valores aleatórios entre 0 e MAX_VALUE
 * 
 * @param m: Número de linhas
 * @param n: Número de colunas
 * @return double**: Retorna a matriz criada
 */
double* create_matrix(unsigned int m, unsigned int n){
    double* matrix  = new double[n*m];
    for(unsigned int i = 0; i < m; i++){
        for(unsigned int j = 0; j < n; j++){
            matrix[i*n + j] = i*n + j;
        }
    }
    return matrix;

}
/**
 * @brief Cria um vetor de dimensao mx1 com valores aleatórios entre 0 e MAX_VALUE
 * 
 * @param m: Número de linhas do vetor
 * @return double*: Retorna o vetor criado 
 */
double* create_vector(unsigned int m){
    double* vector = new double[m];
    for(unsigned int i = 0; i < m; i++){
        vector[i] = i;
    }
    return vector;

}
void move_branches(double* a, double* b, unsigned int n){
    
    for(unsigned int i = 0; i < n; i++){
        if(i==0)
            {b[i] = 0.0;}
        else if(i == n-1)
            {b[i] = a[i] + 1.0;}
        else
           { b[i] = 0.25*(a[i-1] + 2.0*a[i] + a[i+1]);}
    }
}
int main(int argc, char* argv[]){
    unsigned int n = atoi(argv[1]);
    cout << "Experimento - Move branches out of loop" << endl;
    double time_all = 0.0;
    for(unsigned int i = 0; i < EXEC_EXPERIMENTO; i++){
        double* a = create_vector(n);
        double* b = create_vector(n);
        auto start = chrono::system_clock::now();
        move_branches(a, b, n);
        auto end = chrono::system_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
        time_all+=elapsed.count();
        delete[] a;
        delete[] b;
    }
    cout << "Tempo médio de execução: " << time_all/(EXEC_EXPERIMENTO*1.0) << endl;
    return 0;
}