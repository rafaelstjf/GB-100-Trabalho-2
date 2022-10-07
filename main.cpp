#include <iostream>
#include <cstdlib>
#include <chrono>

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
void move_branches(double* mat_a, double* mat_b, unsigned int n){
    
    for(unsigned int i = 0; i < n; i++){
        if(i==0)
            {mat_b[i] = 0.0;}
        else if(i == n-1)
            {mat_b[i] = mat_a[i] + 1.0;}
        else
           { mat_b[i] = 0.25*(mat_a[i-1] + 2.0*mat_a[i] + mat_a[i+1]);}
    }
}
void move_branches_opt(double* mat_a, double* mat_b, unsigned int n){
    unsigned int i = 0;
    mat_b[i] = 0.0;
    for(i = 1; i < n-1; i++){
        mat_b[i] = 0.25*(mat_a[i-1] + 2.0*mat_a[i] + mat_a[i+1]);
    }
    mat_b[n-1] = mat_a[n-1] + 1.0; 
}
int main(int argc, char* argv[]){
    unsigned int m = 10000, n = 10000;
    cout << "Experimento - Move branches out of loop" << endl;
    double time_all = 0.0;
    for(unsigned int i = 0; i < EXEC_EXPERIMENTO; i++){
        double* mat_a = create_matrix(m, m);
        double* mat_b = create_matrix(m, m);
        auto start = chrono::system_clock::now();
        move_branches(mat_a, mat_b, m*m);
        auto end = chrono::system_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
        time_all+=elapsed.count();
        delete[] mat_a;
        delete[] mat_b;
    }
    cout << "Tempo médio de execução: " << time_all/(EXEC_EXPERIMENTO*1.0) << endl;
    cout << "Experimento - Move branches out of loop OTIMIZADO" << endl;
    time_all = 0.0;
    for(unsigned int i = 0; i < EXEC_EXPERIMENTO; i++){
        double* mat_a = create_matrix(m, m);
        double* mat_b = create_matrix(m, m);
        auto start = chrono::system_clock::now();
        move_branches_opt(mat_a, mat_b, m*m);
        auto end = chrono::system_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
        time_all+=elapsed.count();
        delete[] mat_a;
        delete[] mat_b;
    }
    cout << "Tempo médio de execução: " << time_all/(EXEC_EXPERIMENTO*1.0) << endl;
    return 0;
}