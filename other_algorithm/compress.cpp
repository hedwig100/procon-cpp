#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Compress {
  private:
    int n;
    vector<T> A;
    map<T, int> val_to_id;

  public:
    Compress(const vector<T> &_A) : A(_A) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        n = (int)A.size();
        for (int i = 0; i < n; i++)
            val_to_id[A[i]] = i;
    }

    int operator()(T val) {
        return val_to_id[val];
    }

    T operator[](int id) {
        return A[id];
    }

    int size() {
        return n;
    }
};
