#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"

/*
 * Função parse_expressao
 * ----------------------
 * Recebe uma string contendo uma expressão em Notação Polonesa Reversa (RPN),
 * separada por espaços (exemplo: "3 4 + 2 * 7 /").
 *
 * A função percorre a string, separa cada "token" (número ou operador),
 * e imprime o que encontrou.
 */
void parse_expressao(const char linha[]) {
    // Criamos uma cópia da string porque strtok modifica a original
    char buf[256];
    strncpy(buf, linha, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0'; // garante finalização com '\0'

    Stack *s = create_stack();
    if (s == NULL) {
        printf("Erro ao alocar memória para pilha.\n");
        return;
    }

    // strtok vai quebrar a string usando " " (espaço) como delimitador
    char *tok = strtok(buf, " ");
    while (tok != NULL) {
        /*
         * Se o primeiro caractere do token é um dígito (0–9),
         * assumimos que é um número inteiro.
         */
        if (isdigit(tok[0])) {
            int valor = atoi(tok); // converte string → inteiro
            // printf("Número encontrado: %d\n", valor);
            push(s, valor);
        } else {
            /*
             * Caso contrário, consideramos o token um operador.
             * Aqui aceitamos símbolos como +, -, *, /.
             */
            // printf("Operador encontrado: %c\n", tok[0]);
            int n1, n2;

            pop(s, &n2);
            pop(s, &n1);

            switch(tok[0]) {
                case '+': push(s, n1 + n2); break;
                case '-': push(s, n1 - n2); break;
                case '*': push(s, n1 * n2); break;
                case '/': 
                    if (n2 == 0) {
                        printf("ERRO: divisão por zero.\n");
                        free_stack(s);
                        return;
                    }
                    push(s, n1 / n2); 
                    break;
            }
        }

        // Pega o próximo token (ou NULL se acabou)
        tok = strtok(NULL, " ");
    }

    int resultado;
    peek(s, &resultado);
    printf("%d\n", resultado);
    free_stack(s);

}

int main() {
    char linha[256];

    // printf("Digite a expressão em RPN (exemplo: 3 4 + 2 * 7 /):\n");

    // Lê a linha completa do usuário
    if (fgets(linha, sizeof(linha), stdin) == NULL) {
        printf("Erro ao ler entrada.\n");
        return 1;
    }

    // Remove o '\n' que fgets pode deixar no final
    linha[strcspn(linha, "\n")] = '\0';

    // Chama o parser para processar a string
    parse_expressao(linha);

    return 0;
}
