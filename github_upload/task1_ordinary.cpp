#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 5000;
const int ITERATIONS = 10;

int main() {
    double* matrix = new double[N * N];
    double* vector = new double[N];
    double* result = new double[N];

    for (int i = 0; i < N * N; i++) matrix[i] = 1.0;
    for (int i = 0; i < N; i++) {
        vector[i] = 1.0;
        result[i] = 0.0;
    }

    auto start = high_resolution_clock::now();

    for (int iter = 0; iter < ITERATIONS; iter++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                //平凡算法：按列访问，导致内存地址在大范围内跳跃
                result[j] += matrix[i * N + j] * vector[i];
            }
        }
    }

    auto end = high_resolution_clock::now();
    duration<double, std::milli> time = (end - start) / ITERATIONS;
    
    cout << "Result check sum: " << result[0] << endl;
    cout << "Average Time: " << time.count() << " ms" << endl;

    delete[] matrix;
    delete[] vector;
    delete[] result;
    return 0;
}