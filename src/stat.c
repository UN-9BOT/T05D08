#include <stdio.h>
#define NMAX 10

void input(int *a, int *n, int *flag);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX], flag;

    flag = 0;
    input(data, &n, &flag);
    if (flag == 1) {
        printf("n/a");
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    return 0;
}

void input(int *a, int *n, int *flag) {
    int z;
    if (scanf("%d.%d", n, &z) != 1 || *n <= 0 || *n > NMAX) {
        *flag = 1;
    }
    for (int *p = a; (p - a < *n) && (*flag == 0); p++) {
        if (scanf("%d.%d", p, &z) != 1) {
            *flag = 1;
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", *(a + i));
    }
    printf("%d\n", *(a + n - 1));
}

int max(int *a, int n) {
    int maxN = *a;
    for (int i = 0; i < n; i++) {
        if (*(a + i) > maxN) {
            maxN = *(a + i);
        }
    }
    return (maxN);
}

int min(int *a, int n) {
    int minN = *a;

    for (int i = 0; i < n; i++) {
        if (*(a + i) < minN) {
            minN = *(a + i);
        }
    }
    return (minN);
}

double mean(int *a, int n) {
    double res = 0;

    for (int i = 0; i < n; i++) {
        res += *(a + i);
    }
    return (res / n);
}

double variance(int *a, int n) {
    double res = 0;
    double meanS = mean(a, n);

    for (int i = 0; i < n; i++) {
        res += (*(a + i) - meanS) * (*(a + i) - meanS);
    }
    return (res / n);
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%i %i %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
