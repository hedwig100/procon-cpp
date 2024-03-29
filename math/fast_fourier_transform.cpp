#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "../template/const.hpp"
#include "./mint.cpp"

class FastFourierTransform {
  private:
    inline static void fft(vector<complex<double>> &F) {
        int degree = F.size();
        if (degree == 1) return;
        vector<complex<double>> even, odd;
        for (int i = 0; i < degree / 2; i++) {
            even.push_back(F[i << 1]);
            odd.push_back(F[i << 1 | 1]);
        }
        fft(even);
        fft(odd);
        complex<double> x = 1, zeta = polar(1.0, 2 * PI / degree);
        for (int i = 0; i < degree; i++) {
            F[i] = even[i % (degree / 2)] + x * odd[i % (degree / 2)];
            x *= zeta;
        }
    }

    inline static void ifft(vector<complex<double>> &F) {
        int degree = F.size();
        if (degree == 1) return;
        vector<complex<double>> even, odd;
        for (int i = 0; i < degree / 2; i++) {
            even.push_back(F[i << 1]);
            odd.push_back(F[i << 1 | 1]);
        }
        ifft(even);
        ifft(odd);
        complex<double> x = 1, zeta = polar(1.0, -2 * PI / degree);
        for (int i = 0; i < degree; i++) {
            F[i] = even[i % (degree / 2)] + x * odd[i % (degree / 2)];
            x *= zeta;
        }
    }

  public:
    template <class T>
    inline static vector<double> multiply(vector<T> F, vector<T> G) {
        int degree = 1;
        while (degree < F.size() + G.size() - 1)
            degree *= 2;
        vector<complex<double>> nF(degree, 0), nG(degree, 0);
        for (int i = 0; i < F.size(); i++)
            nF[i] = F[i];
        for (int i = 0; i < G.size(); i++)
            nG[i] = G[i];
        fft(nF);
        fft(nG);
        for (int i = 0; i < degree; i++) {
            nF[i] *= nG[i];
        }
        ifft(nF);
        vector<double> ret(degree);
        for (int i = 0; i < degree; i++) {
            ret[i] = nF[i].real() / degree;
        }
        return ret;
    }
};

//非再帰できたはやい

class FastFourierTransform {
  private:
    inline static void fft(vector<complex<double>> &F, bool inverse, int bit_len) {
        int degree = F.size();
        for (int i = 0; i < degree; i++) {
            int j = 0;
            for (int k = 0; k < bit_len; k++)
                j |= (i >> k & 1) << (bit_len - k - 1);
            if (i < j) swap(F[i], F[j]);
        }
        for (int b = 1; b < degree; b <<= 1) {
            complex<double> x = 1, zeta = polar(1.0, PI / b * (inverse ? 1 : -1));
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < degree; k += (b << 1)) {
                    complex<double> s = F[j + k], t = F[j + k + b] * x;
                    F[j + k]     = s + t;
                    F[j + k + b] = s - t;
                }
                x *= zeta;
            }
        }
        if (inverse) {
            for (int i = 0; i < degree; i++)
                F[i] /= degree;
        }
    }

  public:
    template <class T>
    inline static vector<long long> multiply(vector<T> &F, vector<T> &G) {
        int s      = F.size() + G.size() - 1;
        int degree = 1, bit_len = 0;
        while (degree < s)
            degree <<= 1, bit_len++;
        vector<complex<double>> nF(degree, 0), nG(degree, 0);
        for (int i = 0; i < F.size(); i++)
            nF[i] = F[i];
        for (int i = 0; i < G.size(); i++)
            nG[i] = G[i];
        fft(nF, false, bit_len);
        fft(nG, false, bit_len);
        for (int i = 0; i < degree; i++)
            nF[i] *= nG[i];
        fft(nF, true, bit_len);
        vector<long long> ret(s);
        for (int i = 0; i < s; i++)
            ret[i] = (long long)(nF[i].real() + 0.5);
        return ret;
    }
};

struct NumberTheoreticalTransform {
    const int premitive_root = 3; // primitive root of 998244353
    const int MOD            = 998244353;
    NumberTheoreticalTransform() {}
    inline void ntt(vector<mint> &F, bool inverse, int bit_len) {
        int degree = F.size();
        for (int i = 0; i < degree; i++) {
            int j = 0;
            for (int k = 0; k < bit_len; k++)
                j |= (i >> k & 1) << (bit_len - k - 1);
            if (i < j) swap(F[i], F[j]);
        }
        for (int b = 1; b < degree; b <<= 1) {
            mint x = 1, zeta = mint(premitive_root).pow((MOD - 1) / (b << 1));
            if (inverse) zeta = zeta.inverse();
            for (int j = 0; j < b; ++j) {
                for (int k = 0; k < degree; k += (b << 1)) {
                    mint s = F[j + k], t = F[j + k + b] * x;
                    F[j + k]     = s + t;
                    F[j + k + b] = s - t;
                }
                x *= zeta;
            }
        }
        if (inverse) {
            mint inv = mint(degree).inverse();
            for (int i = 0; i < degree; i++)
                F[i] *= inv;
        }
    }
    inline vector<mint> multiply(vector<mint> &F, vector<mint> &G) {
        int s      = F.size() + G.size() - 1;
        int degree = 1, bit_len = 0;
        while (degree < s)
            degree <<= 1, bit_len++;
        vector<mint> nF(degree, 0), nG(degree, 0);
        for (int i = 0; i < F.size(); i++)
            nF[i] = F[i];
        for (int i = 0; i < G.size(); i++)
            nG[i] = G[i];
        ntt(nF, false, bit_len);
        ntt(nG, false, bit_len);
        for (int i = 0; i < degree; i++)
            nF[i] *= nG[i];
        ntt(nF, true, bit_len);
        return nF;
    }
} ntt;
