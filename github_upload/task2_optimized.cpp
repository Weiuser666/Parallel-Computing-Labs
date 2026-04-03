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

    double total_sum = 0.0;
    auto start = high_resolution_clock::now();
    
    for (int iter = 0; iter < ITERATIONS; iter++) {
        double s1 = 0.0, s2 = 0.0;
        for (int i = 0; i < N; i += 2) {
            //优化算法，两行指令没有数据依赖
            s1 += data[i];
            s2 += data[i + 1];
        }
        total_sum = s1 + s2;
    }
    
    auto end = high_resolution_clock::now();
    duration<double, std::milli> time = (end - start) / ITERATIONS;
    
    cout << "Final Result: " << total_sum << endl;
    cout << "Optimized Sum Average Time: " << time.count() << " ms" << endl;

    delete[] data;
    return 0;
}