#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

const int N = 100000000; 
const int ITERATIONS = 20;

int main() {
    double* data = new double[N];
    for (int i = 0; i < N; i++) data[i] = 1.0; 

    double sum1 = 0.0;
    auto start = high_resolution_clock::now();
    
    for (int iter = 0; iter < ITERATIONS; iter++) {
        sum1 = 0.0;
        for (int i = 0; i < N; i++) {
            //指令依赖：第 i+1 次加法必须等第 i 次结果
            sum1 += data[i]; 
        }
    }
    
    auto end = high_resolution_clock::now();
    duration<double, std::milli> time = (end - start) / ITERATIONS;
    
    cout << "Final Result: " << sum1 << endl;
    cout << "Naive Sum Average Time: " << time.count() << " ms" << endl;

    delete[] data;
    return 0;
}