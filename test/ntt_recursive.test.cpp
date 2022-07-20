#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../math/number_theoretic_transform.cpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> A(n), B(m);
    for (int i = 0; i < n; i++)
        std::cin >> A[i];
    for (int i = 0; i < m; i++)
        std::cin >> B[i];

    NumberTheoreticTransform ntt;
    std::vector<mint> C = ntt.multiply(A, B);
    for (int i = 0; i < n + m - 1; i++) {
        std::cout << C[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}