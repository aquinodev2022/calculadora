#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char operador;
    int quantidade, i;
    float num, resultado = 0;
    char continuar;
    char nomePessoa[50]; // Ajuste o tamanho conforme necessário
    setlocale(LC_ALL, "Portuguese_Brazil");

    do {
        clearScreen(); // Limpa a tela

        printf("Digite seu nome: ");
        fgets(nomePessoa, sizeof(nomePessoa), stdin);
        // Remover a quebra de linha do final, se houver
        nomePessoa[strcspn(nomePessoa, "\n")] = 0;
        clearScreen();

        // Solicita ao usuário que entre com a quantidade de números
        printf("--------------- Calculadora ---------------\n");
        printf("\nOlá, seja bem vindo %s!\n", nomePessoa);

        printf("\nDigite a quantidade de numeros que voce ira calcular: ");
        while (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
            printf("Entrada invalida. Digite um numero inteiro positivo: ");
            while (getchar() != '\n'); // Limpa o buffer
        }

        // Solicita ao usuário que entre com a operação desejada
        printf("Digite uma operacao (+, -, *, /): ");
        scanf(" %c", &operador); // Nota o espaço antes de %c para limpar o buffer

        // Solicita ao usuário que entre com os números, um por um
        for (i = 0; i < quantidade; i++) {
            printf("Digite o numero %d: ", i + 1);
            while (scanf("%f", &num) != 1) {
                printf("Entrada invalida. Digite um numero: ");
                while (getchar() != '\n'); // Limpa o buffer
            }

            if (i == 0) {
                resultado = num;
            } else {
                switch (operador) {
                    case '+':
                        resultado += num;
                        break;
                    case '-':
                        resultado -= num;
                        break;
                    case '*':
                        resultado *= num;
                        break;
                    case '/':
                        if (num != 0) {
                            resultado /= num;
                        } else {
                            printf("Erro! Divisao por zero nao permitida.\n");
                            i--; // Pede o número novamente
                        }
                        break;
                    default:
                        printf("Operador invalido.\n");
                        i = quantidade; // Sai do loop
                }
            }
        }

        // Exibe o resultado final
        if (operador == '+' || operador == '-' || operador == '*' || operador == '/') {
            printf("Resultado: %.2f\n", resultado);
        }

        // Pergunta ao usuário se deseja continuar
        printf("Deseja realizar outra operacao? (s/n): ");
        scanf(" %c", &continuar); // Nota o espaço antes de %c para limpar o buffer

    } while (continuar == 's' || continuar == 'S');

    printf("Encerrando a calculadora.\n");

    return 0;
}
