#include <stdio.h> 
#include <math.h>

#define NMAX 30

void input(int *, int *, int *);
int max(int *, int);
int min(int *, int);
double mean(int *, int);
double variance(int *, int);
int check(int *, int);

int main(void) {
   int n, data[NMAX], flag;

   flag = 0;
   input(data, &n, &flag);
   if (flag == 1) {
       printf("n/a");
   } else {
       printf("%i", check(data, n));
   }

   return (0);
}

void input(int *a, int *n, int *flag) {
    int z;
    if (scanf("%d.%d", n, &z) != 1) {
        *flag = 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d.%d", p, &z) != 1) {
            *flag = 1;
        }
    }
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

double deviation(int *a, int n) {
    return (mean(a, n) + (3 * sqrt(variance(a, n))));
}

int check(int *a, int n) {
    int res = *a;
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0 && *(a + i) != 0) {
            printf("%i >= %lf && %i <= %lf\n", *(a + 1), mean(a, n), *(a + 1), deviation(a, n));
            if (((double)*(a + i) >= mean(a, n)) && ((double)*(a + i) <= deviation(a, n))) {
                return (*(a + 1));
            }
        }
    }
    return (0);
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/



