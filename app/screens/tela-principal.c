#include <stdio.h>
#include <stdbool.h>
#include <sqlite3.h>
#include "./headers/tela-principal.h"


/**
 * @brief Exibe o menu principal do sistema.
 */
void exibirMenuPrincipal() {

    printf("\n");
    printf("=====================================\n");
    printf("           Menu Principal            \n");
    printf("=====================================\n");
    printf("1. Menu de Indústrias\n");
    printf("2. Menu de Insumos tratados\n");
    printf("3. Relatórios\n");
    printf("4. Encerrar Programa\n");
    printf("=====================================\n");
}

/**
 * @brief Obtém a escolha do usuário a partir do menu principal.
 * 
 * @return int A opção escolhida pelo usuário.
 */
int obterEscolhaUsuario() {
    int escolha;
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    return escolha;
}


/**
 * @brief Executa uma função com base na escolha do usuário.
 *
 * Esta função chama uma das três funções passadas como parâmetros com base na escolha do usuário.
 * Se a escolha for 4, a função retorna true, indicando que a execução deve ser encerrada.
 * Se a escolha for inválida, uma mensagem de erro é exibida e a função retorna false.
 *
 * @param func1 Ponteiro para a primeira função a ser executada.
 * @param func2 Ponteiro para a segunda função a ser executada.
 * @param func3 Ponteiro para a terceira função a ser executada.
 * @return true se a escolha do usuário for 4, indicando que a execução deve ser encerrada.
 * @return false se a escolha do usuário for diferente de 4.
 */
bool executarEscolha(int (*func1)(), int (*func2)(), int (*func3)(), bool* terminarPrograma,sqlite3* db) {
    int escolha = obterEscolhaUsuario();
    switch (escolha) {
        case 1:
            func1(db);
            break;
        case 2:
            func2(db);
            break;
        case 3:
            func3(db);
            break;
        case 4:
            *terminarPrograma = true;
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
    }
}