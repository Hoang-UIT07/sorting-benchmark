#include <bits/stdc++.h>
#include "sort.h"
using namespace std;
using namespace chrono;
int main() {
    const char* names[] = {"QuickSort", "HeapSort", "MergeSort", "std::sort"};
    ifstream f("data.txt");
    if (!f) { cerr << "Khong mo duoc data.txt\n"; return 1; }
    int K, N;
    f >> K >> N;                             
    vector<vector<double>> data(K, vector<double>(N));
    for (int d = 0; d < K; d++)
        for (int i = 0; i < N; i++) f >> data[d][i];
    ofstream out("results.csv");
    out << "dataset,QuickSort,HeapSort,MergeSort,std::sort\n";
    mt19937 rng(2024);
    for (int d = 0; d < K; d++) {
        out << d + 1;
        for (int alg = 0; alg < 4; alg++) {
            vector<double> a = data[d];          
            auto t0 = steady_clock::now();
            if (alg == 0) quickSort(a, 0, N - 1, rng);
            else if (alg == 1) heapSort(a);
            else if (alg == 2) mergeSort(a);
            else sort(a.begin(), a.end());
            auto t1 = steady_clock::now();

            double ms = duration<double, milli>(t1 - t0).count();
            if (!is_sorted(a.begin(), a.end()))
                cerr << "LOI: " << names[alg] << " dataset " << d + 1 << "\n";
            out << "," << ms;
            cout << "Dataset " << d + 1 << " - " << names[alg] << ": " << ms << " ms\n";
        }
        out << "\n";
    }
}