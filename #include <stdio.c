#include <stdio.h>

int main() {
    int matA[10][10], matB[10][10];
    int a[100][3], b[100][3], sum[200][3], at[200][3];
    int r, c, i, j, n = 0, m = 0, k;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matA[i][j]);
        }
    }
    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matB[i][j]);
        }
    }
    a[0][0] = r;
    a[0][1] = c;
    n = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (matA[i][j] != 0) {
                n++;
                a[n][0] = i;
                a[n][1] = j;
                a[n][2] = matA[i][j];
            }
        }
    }
    a[0][2] = n;

        b[0][0] = r;
    b[0][1] = c;
    m = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (matB[i][j] != 0) {
                m++;
                b[m][0] = i;
                b[m][1] = j;
                b[m][2] = matB[i][j];
            }
        }
    }
    b[0][2] = m;
    i = 1; j = 1; k = 1;
    sum[0][0] = r;
    sum[0][1] = c;
        while (i <= n && j <= m) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        }
        else {
            int val = a[i][2] + b[j][2];
            if (val != 0) {
                sum[k][0] = a[i][0];
                sum[k][1] = a[i][1];
                sum[k][2] = val;
                k++;
            }
            i++; j++;
        }
    }

      while (i <= n) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= m) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;

    
    printf("\nSum Matrix (tuple form):\nRow Col Val\n");
    for (i = 0; i <= sum[0][2]; i++) {
        printf("%d\t%d\t%d\n", sum[i][0], sum[i][1], sum[i][2]);
    }
    at[0][0] = sum[0][1];
    at[0][1] = sum[0][0];
    at[0][2] = sum[0][2];

    k = 1;
    for (i = 0; i < sum[0][1]; i++) {
        for (j = 1; j <= sum[0][2]; j++) {
            if (sum[j][1] == i) {
                at[k][0] = sum[j][1];
                at[k][1] = sum[j][0];
                at[k][2] = sum[j][2];
                k++;
            }
        }
    }
    printf("\nTranspose of Sum Matrix (tuple form):\nRow Col Val\n");
    for (i = 0; i <= at[0][2]; i++) {
        printf("%d\t%d\t%d\n", at[i][0], at[i][1], at[i][2]);
    }

    return 0;
}



	
