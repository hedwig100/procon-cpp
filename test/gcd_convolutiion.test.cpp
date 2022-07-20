#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include <bits/stdc++.h>
using namespace std;

#include "../math/mint.cpp"
#include "../math/zeta.cpp"

int main() {
    int n;
    cin >> n;
    vector<mint> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> B[i];

    ZetaDiv<mint> zeta;
    auto C = zeta.convolve(A, B);
    for (int i = 1; i <= n; i++)
        cout << C[i] << ' ';
    cout << '\n';
}