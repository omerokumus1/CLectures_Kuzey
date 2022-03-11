#include <stdio.h>

int f(int, int);

void f2(int *A, int n) {
    int i, j, t, cur, next;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) // i = 0 -> jmax = 4, i = 1 -> jmax = 3
        {
            cur = A[j];
            next = A[j + 1];
            if (cur < next) {
                t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
            for (int i = 0; i < 5; ++i) {
                printf("%d, ", A[i]);
            }
            printf("\n");
        }
        printf("j: %d\n", j);
    }
}

int main() {
    // C dilinde 0 hariç tüm sayılar true, 0 ise false olarak yorumlanır
//    if(2)
//        printf("%d\n", 2);
//    if(-2)
//        printf("%d\n", -2);
//    if(0)
//        printf("%d\n", 0);

    // Soru-36
//    char S[5] = "ABBA"; // \0
//    int i, j;
//    for (i = 10; i; i = i - 2) // i: 10, 8, 6, 4, 2|, 0..
//        // burada j++ veya ++j aynı işi yapar
//        for (j = i; j % 3; j++) // j % 3: 0, 1, 2
//            printf("%c\n", S[j % 4]); // B A A A B B


    // Soru 37
//    int i, j, N = 2;
//    for (i = 0; i <= N; i++)
//        for (j = i; j <= N; j++)
//            printf("A\n");

    // (N+1) N (N-1) (N-2) _ _ _ _ _ 1 -> (N+1)(N+2)/2
    // 1+2+3+4+...+n = n(n+1)/2



    // Soru 38
//    int b=5,c=6,d=7;
//    d = 2*b; // d = 10
//    b = d; // b = 10
//    c = 1+b/d;  // c = 2
//    d = d % c; // d = 0
//    printf("%d\n",b/c+d-b/2); // 5 + 0 - 5 = 0

    // Soru 39
//    printf("%d", f(5,2));


    // Soru 40
//    int arr[5] = {1,2,3,4,5};
//    f2(arr, 45);
//    for (int i = 0; i < 5; ++i) {
//        printf("%d, ", arr[i]);
//    }
//    printf("%p", arr);


/*
     * 3 4 5 6
     * t = A[j]; -> t = 3
     * A[j] = A[j+1]; -> 4 4 5 6
     * A[j+1] = t; -> 4 3 5 6
     */

    // Soru 41
//    int i, j, k;
//    int n = 4;
//    int s = 0;
//    for (i = 0; i < n; i++)
//        for (j = 0; j < i; j++)
//            for (k = 0; k < j; k++)
//                s = s + i + j + k;
//    printf("%d\n", s);

    /*
     * i = 2;   j = 0;  -
     *          j = 1;  s = 0 + 2 + 1 + 0 = 3
     * i = 3;   j = 0; -
     *          j = 1;  s = 3 + 3 + 1 + 0 = 7
     *          j = 2;  s = 7 + 3 + 2 + 0 = 12
     *                  s = 12 + 3 + 2 + 1 = 18
     */


    // Soru 42
    int A[5][5];
    int i, j, k;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            A[i][j] = i * 5 + j;
    /* A;
     * 0    1   2   3   4
     * 5    6   7   8   9
     * 10   11  12  13  14
     * 15   16  17  18  19
     * 20   21  22  23  24
     */
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            for (k = 0; i + k < 5 && j + k < 5; k++)
                A[i + k][j + k] += A[i][j]; // A00 += A00, A11 += A00, (0)
                                            // A01 += A01, A12 += A01 (1)
                                            // A02 += A02, A13 += A02 (2)
                                            // i = 1, k = 0, j = 2
                                            // i = 0, k = 1, j = 2
                                            // i = 3, j = 0, k = 0
                                            // A30 = A30
    /*
     * 0    2   4
     *      6   8   10
     *          12  14
     *              18  20
     *                  24
     */

    // B, D, A, C, B, E, E, B

    // 6 / 2 * 3 -> 9, 1
    return 0;
}

int f(int n, int m) {
    int i, r = 1;
    for (i = 0; i < m; i++) {
        r *= (n - i);
        r /= (i + 1);
    }
    return r;
}


