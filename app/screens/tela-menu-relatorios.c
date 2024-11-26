#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "./headers/tela-menu-relatorios.h"
#include "../../db/common/db.h"

void limparConsole_relatorios() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void esperarTecla() {
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
    getchar();
}

int telaMenuRelatorios(sqlite3 *db) {
    int opcao;

    do {
        limparConsole();
        printf("Menu de Relatórios\n");
        printf("1. Relatórios Globais\n");
        printf("2. Relatórios por Empresa\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                telaRelatoriosGlobais(db);
                break;
            case 2:
                telaRelatoriosPorEmpresa(db);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

void telaRelatoriosGlobais(sqlite3 *db) {
    int opcao;

    do {
        limparConsole();
        printf("Relatórios Globais\n");
        printf("1. Gerar relatório de empresas por estado e seus custos estimados nos últimos 6 meses\n");
        printf("2. Ranking de indústrias que menos produziram insumos tratados nos últimos 6 meses\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                limparConsole();
                printf("Gerando relatório de empresas por estado e seus custos estimados nos últimos 6 meses...\n");
                consultarEmpresasPorEstado(db);
                esperarTecla();
                break;
            case 2:
                limparConsole();
                printf("Gerando ranking de indústrias que menos produziram insumos tratados nos últimos 6 meses...\n");
                consultarRankingIndustriaPorInsumos(db);
                esperarTecla();
                break;
            case 3:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
}

void telaRelatoriosPorEmpresa(sqlite3 *db) {
    int opcao;

    do {
        limparConsole();
        printf("Relatórios por Empresa\n");
        printf("1. Custo total nos últimos 6 meses\n");
        printf("2. Total de insumos tratados nos últimos 6 meses\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                limparConsole();
                printf("Gerando relatório de custo total nos últimos 6 meses...\n");
                consultarCustoTotalPorEmpresa(db);
                esperarTecla();
                break;
            case 2:
                limparConsole();
                printf("Gerando relatório de total de insumos tratados nos últimos 6 meses...\n");
                consultarTotalInsumosPorEmpresa(db);
                esperarTecla();
                break;
            case 3:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
}