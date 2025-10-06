#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *tmp1 = (int *)malloc(n1 * sizeof(int));
    int *tmp2 = (int *)malloc(n2 * sizeof(int));

    if (tmp1 == NULL || tmp2 == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    for (int i = 0; i < n1; i++) {
        tmp1[i] = v[l + i];
    }

    for (int i = 0; i < n2; i++) {
        tmp2[i] = v[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while ((i < n1) && (j < n2)) {
        if (tmp1[i] <= tmp2[j]) {
            v[k] = tmp1[i];
            i++;
        } else {
            v[k] = tmp2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = tmp1[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = tmp2[j];
        j++;
        k++;
    }

    printf("INTERCALACAO [%d,%d]: ", l, r);
    for (int i = l; i < r; i++) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[r]);

    free(tmp1);
    free(tmp2);
}

void merge_sort(int v[], int l, int r) {
    if (l >= r) {
        return;
    }
    printf("DIVISAO [%d,%d]\n", l, r);

    int m = (l + r) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);

    merge(v, l, m, r);
}

int main() {
    int n, *v;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));

    if (v == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    merge_sort(v, 0, n - 1);

    free(v);
    return 0;
}