#include <stdio.h>

void hanoi(int n, char origem, char auxiliar, char destino);

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');

    return 0;
}


void hanoi(int n, char origem, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mova o disco %d de %c para %c\n", n, origem, destino);
        return;
    }
    hanoi(n - 1, origem, destino, auxiliar);
    printf("Mova o disco %d de %c para %c\n", n, origem, destino);
    hanoi(n - 1, auxiliar, origem, destino);
}