#include <stdio.h>
#define NMAX 10

void input(int *a, int *n, int *flag);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int flag = 0;
    input(data, &n, &flag);
    if (flag == 1) {
        printf("n/a");
    } else {
        squaring(data, n);
        output(data, n);
    }

    return 0;
}

void input(int *a, int *n, int *flag) {
    int z;
    if (scanf("%d.%d", n, &z) != 1 || *n <= 0 || *n > NMAX) {
        *flag = 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d.%d", p, &z) != 1) {
            *flag = 1;
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", *(a + i));
    }
    printf("%d", *(a + n - 1));
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        *(a + i) = *(a + i) * *(a + i);
    }
}
