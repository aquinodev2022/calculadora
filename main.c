#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char operacaoMatematica;
    int quantidadeNumeros, indice;
    float numeroCalcular, resultadoCalculo = 0;
    char continuarOperacao;
    char nomePessoa[50];
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("Digite seu nome: ");
    // Captura o nome digitado pelo usuário
    fgets(nomePessoa, sizeof(nomePessoa), stdin);
    // Remove a quebra de linha do final
    nomePessoa[strcspn(nomePessoa, "\n")] = 0;
    limparTerminal();

    // Loop principal
    do {
        limparTerminal(); // Limpa o terminal quando o usuário deseja continuar com outra operação
        printf("--------------- Calculadora ---------------\n");
        printf("\nOlá, %s. Seja bem vindo!\n", nomePessoa);
        printf("\nDigite a quantidade de números que você irá calcular: ");

        // verifica se é um número e se é número positivo
        while (scanf("%d", &quantidadeNumeros) != 1 || quantidadeNumeros <= 0) {
            printf("\nEntrada inválida. Digite um número inteiro positivo: ");
            while (getchar() != '\n'); // limpa o buffer de entrada para descartar caractere inválido
        }

        printf("\nDigite uma operação (+, -, *, /): ");
        scanf(" %c", &operacaoMatematica);

        // Verificação se a operação é válida
        while (operacaoMatematica != '+' && operacaoMatematica != '-' && operacaoMatematica != '*' && operacaoMatematica != '/') {
            printf("\nOperação inválida! Digite uma operação válida (+, -, *, /): ");
            while (getchar() != '\n'); // limpa o buffer de entrada para descartar caractere inválido
            scanf(" %c", &operacaoMatematica);
        }

        printf("\n-------------------------------------------\n");

        // Solicitação dos números ao usuário
        for (indice = 0; indice < quantidadeNumeros; indice++) {
            printf("Digite o número %d: ", indice + 1);
            while (scanf("%f", &numeroCalcular) != 1) {
                printf("Entrada inválida. Digite um número: ");
                while (getchar() != '\n'); // limpa o buffer de entrada para descartar caractere inválido
            }

            // Operações matemática de acordo com a escolha do usuário
            if (indice == 0) {
                resultadoCalculo = numeroCalcular; // Resultado é o primeiro número digitado
            } else {
                switch (operacaoMatematica) {
                    case '+':
                        resultadoCalculo += numeroCalcular;
                        break;
                    case '-':
                        resultadoCalculo -= numeroCalcular;
                        break;
                    case '*':
                        resultadoCalculo *= numeroCalcular;
                        break;
                    case '/':
                        if (numeroCalcular != 0) { // Só realiza a divisão se o divisor for diferente de zero
                            resultadoCalculo /= numeroCalcular;
                        } else {
                            printf("Erro! Divisão por zero não permitida.\n");
                            indice--; // Loop solicita novamente um número válido
                        }
                        break;
                }
            }
        }

        // Exibe o resultado da operação
        if (operacaoMatematica == '+' || operacaoMatematica == '-' || operacaoMatematica == '*' || operacaoMatematica == '/') {
            printf("\nResultado: %.2f\n", resultadoCalculo);
        }

        do {
            printf("\nDeseja realizar outra operação? (s/n): ");
            scanf(" %c", &continuarOperacao);

            while (getchar() != '\n'); // limpa o buffer de entrada para descartar caractere inválido

            if (continuarOperacao != 's' && continuarOperacao != 'S' && continuarOperacao != 'n' && continuarOperacao != 'N') {
                printf("\nResposta inválida! Digite 's' para Sim ou 'n' para Não.\n");
            }
            // Caso o usuário digite errado, solicita novamente se ele deseja continuar a operação
        } while (continuarOperacao != 's' && continuarOperacao != 'S' && continuarOperacao != 'n' && continuarOperacao != 'N');

    } while (continuarOperacao == 's' || continuarOperacao == 'S'); // Loop principal reiniciado

    printf("\nEncerrando a calculadora...\n"); // Caso não queira continuar, fim do programa

    return 0;
}