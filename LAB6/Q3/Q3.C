#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
    double real;
    double imag;
} Complex;

Complex c_add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex c_sub(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex c_mul(Complex a, Complex b) {
    return (Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

// Cooley-Tukey Radix-2 In-place FFT
void fft(Complex* a, int n, int invert) {
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            Complex temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        Complex wlen = {cos(ang), sin(ang)};
        for (int i = 0; i < n; i += len) {
            Complex w = {1.0, 0.0};
            for (int j = 0; j < len / 2; j++) {
                Complex u = a[i + j];
                Complex v = c_mul(a[i + j + len / 2], w);
                a[i + j] = c_add(u, v);
                a[i + j + len / 2] = c_sub(u, v);
                w = c_mul(w, wlen);
            }
        }
    }

    if (invert) {
        for (int i = 0; i < n; i++) {
            a[i].real /= n;
            a[i].imag /= n;
        }
    }
}

int next_pow2(int x) {
    int p = 1;
    while (p < x) p <<= 1;
    return p;
}

int main() {
    int m = 3; // Length of A
    int n = 5; // Length of B (n >= m)
    double A[] = {1.0, 2.0, 3.0};
    double B[] = {4.0, 5.0, 6.0, 7.0, 8.0};

    int out_len = m + n - 1;
    int N = next_pow2(out_len);

    Complex* fa = (Complex*)calloc(N, sizeof(Complex));
    Complex* fb = (Complex*)calloc(N, sizeof(Complex));

    for (int i = 0; i < m; i++) fa[i].real = A[i];
    for (int i = 0; i < n; i++) fb[i].real = B[i];

    // Compute FFT
    fft(fa, N, 0);
    fft(fb, N, 0);

    // Point-wise multiplication
    for (int i = 0; i < N; i++) {
        fa[i] = c_mul(fa[i], fb[i]);
    }

    // Inverse FFT
    fft(fa, N, 1);

    printf("Convolution Output C (size %d):\n", out_len);
    for (int i = 0; i < out_len; i++) {
        printf("C[%d] = %.2f\n", i, round(fa[i].real));
    }

    free(fa);
    free(fb);
    return 0;
}