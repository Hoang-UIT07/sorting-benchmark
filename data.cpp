    // make_data_file.cpp - Ghi 10 day du lieu ra 1 file text de lam minh chung.
// File "data.txt": dong 1 = "so_day so_phan_tu", dong 2..11 = day 1..10 (cac so cach nhau dau cach)
// Bien dich: g++ -O2 make_data_file.cpp -o make_data_file
#include <cstdio>
#include <iostream>
#include "gen_data.h"
using namespace std;

int main() {
    FILE *f = fopen("data.txt", "w");
    if (!f) { cerr << "Khong tao duoc data.txt\n"; return 1; }

    fprintf(f, "%d %d\n", 10, 1000000);
    for (int k = 1; k <= 10; k++) {
        vector<double> a = makeDataset(k);
        for (size_t i = 0; i < a.size(); i++)
            fprintf(f, i ? " %.3f" : "%.3f", a[i]);
        fputc('\n', f);
        cout << "Da ghi day " << k << "\n";
    }
    fclose(f);
}