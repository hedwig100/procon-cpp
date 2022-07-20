#include <bits/stdc++.h>
using namespace std;
#include "../math/mint.cpp"

using Matrix = vector<vector<mint>>;

Matrix mat_mul(Matrix &A, Matrix &B) {
    Matrix ans(A.size(), vector<mint>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return ans;
}

Matrix mat_pow(Matrix &A, long long N) {
    Matrix ans(A.size(), vector<mint>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
        ans[i][i] = 1;
    Matrix X = A;
    while (N > 0) {
        if (N & 1) ans = mat_mul(ans, X);
        N >>= 1;
        X = mat_mul(X, X);
    }
    return ans;
}
