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
    scanf("%d", n);
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            *flag = 1;
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        *(a + i) = *(a + i) * *(a + i);
    }
}
