#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; case_num++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int arr[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        for (int op = 0; op < m; ++op) {
            char operation;
            scanf(" %c", &operation);
            if (operation == 'S') {
                int D;
                scanf("%d", &D);
                for (int i = 0; i < n; ++i) {
                    arr[i] += D;
                }
            } else if (operation == 'M') {
                int D;
                scanf("%d", &D);
                for (int i = 0; i < n; ++i) {
                    arr[i] *= D;
                }
            } else if (operation == 'D') {
                int K;
                scanf("%d", &K);
                for (int i = 0; i < n; ++i) {
                    arr[i] /= K;
                }
            } else if (operation == 'P') {
                int Y, Z;
                scanf("%d %d", &Y, &Z);
                int tmp = arr[Y];
                arr[Y] = arr[Z];
                arr[Z] = tmp;
            } else if (operation == 'R') {
                for (int i = 0, j = n - 1; i < j; i++, j--) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }

        printf("Case %d:\n", case_num);
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
