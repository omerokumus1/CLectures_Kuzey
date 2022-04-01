#include <stdio.h>

int f(int, int);

//void f2(int *A, int n) {
//    int i, j, t, cur, next;
//    for (i = 0; i < n - 1; i++) {
//        for (j = 0; j < n - i - 1; j++) // i = 0 -> jmax = 4, i = 1 -> jmax = 3
//        {
//            cur = A[j];
//            next = A[j + 1];
//            if (cur < next) {
//                t = A[j];
//                A[j] = A[j + 1];
//                A[j + 1] = t;
//            }
//            for (int i = 0; i < 5; ++i) {
//                printf("%d, ", A[i]);
//            }
//            printf("\n");
//        }
//        printf("j: %d\n", j);
//    }
//}

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


    // 2014 soruları

    // 36. soru
    /*
        1   2   3   4   1
        5   6   7   8   5
        9   10  11  12  9

     i = 0
        b[0][0] = 0

        0   2   3   4   1
        0   2   3   1   4
        0   2   1   3   4
        0   1   2   3   4
        1   0   2   3   4 ***

    i = 1
        b[1][0] = 1

        1   6   7   8   5
        1   6   7   5   8
        1   6   5   7   8
        1   5   6   7   8 ***

    i = 2
        b[2][0] = 2

        2   10  11  12  9
        2   10  11  9   12
        2   10  9   11  12 ***

        1   0   2   3   4
        1   5   6   7   8
        2   10  9   11  12

        1 + 5 + 9 + 11 = 26
     */


    // 37. soru
    /*
     a = {1,2,3,4,5,6,7,8,9,10}

     1. iterasyon i = 0
     a[ i = a[i] ] = i*2;
        i = a[i] => i = a[0] => i = 1 => a[ i = a[i] ] -> a[1]
        a[ i = a[i] ] = i => a[1] = 1 -> a = {1,1,3,4,5,6,7,8,9,10}

     2. iterasyon i = 2
     a[ i = a[2] ] = i; => i = 3 => a[3] = 3; -> a = 1,1,3,3,5,6,7,8,9,10
     1 1 3 3 5 5 7 7 9 9
     5 7 9
     */

    // 38. soru
    /*
     * Ternary operator (conditional expression)
     *  x = (bool-expr) ? (if-true-value) : (else-value)
     *  x = (7 > 3) ? 1 : 0; -> x = 1
     *  x = (7 < 3) ? 1 : 0; -> x = 0

     a = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}

     i = 0
        a[0] += (j % 2) ? a[j] : -a[j]
        a[0] += a[9] - a[8] + a[7] ...
                a[0] = 9+0-1+2-3+4-5+6-7+8 = 13
        a[2] = 0-1+2-3+4-5+6+7 = 10
        a[4] = 0-1+2-3+4+5 = 7
        a[6] = 0-1+2+3 = 4
        a[8] = 0+1 = 1
        13-10+7-4+1
     */

    // 39. soru
    /*
     b = 0, a = 3829421
     b <= a%10 -> b = 1, (+1 *)
        a = 382942

     b = 1, a = 382942
     b <= a%10 -> b = 2, (+1 *)
        a = 38294
    a = 4 -> +1*, b = 4, a = 3829
    a = 9 -> +1*, b = 9, a = 382
    7+4=11 *

     */

    // 40. soru
    /*
     a = {2, 20, 201, 2014}

     i = 0
        a[0] >>= 1 -> a[0] = 2 >>= 1 -> a[0] = 1
            a = 1, 20, 201, 2014

        2 -> 1, +1
        20 -> 10 -> 5 -> 2 -> 1, +4
        201 100 50 25 12 6 3 1
        201: 2^7 = 128, 2^8 = 256, +7
        2014: 2^9 = 512, 2^10 = 1024, 2^11 = 2048, +10
     */

    // 41. soru
    /* (int*) malloc(20*sizeof(int));
     *      malloc = Memory ALLOCation
     *      malloc(20*sizeof(int)) -> 20 tane boşluk ayırır,
     *              her bir boşluk ise bir int değer alır
     *      malloc(20*sizeof(int)) -> 20 elemanlı int array
     *      malloc(10*sizeof(float)) -> 10 elemanlı float array
     *      malloc(5*sizeof(char)) -> 5 elemanlı char array

        a = {1,1,1,1,1,1,1...,1,1,1,} 20 tane 1
        s = 0+ 0*1+ 2*1+ 3*1 +...+19*1
        19*20/2 = 190



     */

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


