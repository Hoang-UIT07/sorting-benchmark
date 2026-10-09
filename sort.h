
#pragma once
#include <vector>
#include <random>
using namespace std;
// QuickSort
void quickSort(vector<double>& a, int lo, int hi, mt19937& rng) {
    while (lo < hi) {
        double pivot = a[lo + rng() % (hi - lo + 1)];
        int i = lo, j = hi;
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) { swap(a[i], a[j]); i++; j--; }
        }
        if (j - lo < hi - i) { quickSort(a, lo, j, rng); lo = i; }
        else                 { quickSort(a, i, hi, rng); hi = j; }
    }
}

//  HeapSort 
void heapify(vector<double>& a, int n, int i) {
    while (true) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}
void heapSort(vector<double>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);   
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

//  MergeSort 
void mergeSortRec(vector<double>& a, vector<double>& tmp, int l, int r) { 
    if (r - l < 2) return;
    int m = (l + r) / 2;
    mergeSortRec(a, tmp, l, m);
    mergeSortRec(a, tmp, m, r);
    int i = l, j = m, k = l;
    while (i < m && j < r) tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i < m) tmp[k++] = a[i++];
    while (j < r) tmp[k++] = a[j++];
    for (int t = l; t < r; t++) a[t] = tmp[t];
}
void mergeSort(vector<double>& a) {
    vector<double> tmp(a.size());
    mergeSortRec(a, tmp, 0, a.size());
}