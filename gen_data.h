#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <functional>
using namespace std;

const unsigned SEED_BASE = 20240601;

inline std::vector<double> makeDataset(int k, int n = 1000000) {
    std::mt19937 rng(SEED_BASE + k);
    std::uniform_int_distribution<int> dist(0, 999999);   
    std::vector<double> a(n);
    for (auto &x : a) x = dist(rng) / 1000.0;
 
    if (k == 1) std::sort(a.begin(), a.end());                       
    else if (k == 2) std::sort(a.begin(), a.end(), std::greater<>()); 
    return a;
}
 