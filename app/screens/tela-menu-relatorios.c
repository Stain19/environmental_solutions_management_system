#include <stdio.h>
#include <stdlib.h>

#include "./headers/tela-menu-relatorios.h"

int telaMenuRelatorios(sqlite3 *db) {
    int opcao;

    do {
        printf("Menu de Relatórios\n");
        printf("1. Relatórios Globais\n");
        printf("2. Relatórios por Empresa\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                telaRelatoriosGlobais();
                break;
            case 2:
                telaRelatoriosPorEmpresa();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void telaRelatoriosGlobais() {
    int opcao;

    do {
        printf("Relatórios Globais\n");
        printf("1. Gerar relatório de empresas por estado e seus custos estimados nos últimos 6 meses\n");
        printf("2. Ranking de indústrias que menos produziram insumos tratados nos últimos 6 meses\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Gerando relatório de empresas por estado e seus custos estimados nos últimos 6 meses...\n");
                // Implementar lógica para gerar relatório
                break;
            case 2:
                printf("Gerando ranking de indústrias que menos produziram insumos tratados nos últimos 6 meses...\n");
                // Implementar lógica para gerar ranking
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void telaRelatoriosPorEmpresa() {
    int opcao;

    do {
        printf("Relatórios por Empresa\n");
        printf("1. Custo total nos últimos 6 meses\n");
        printf("2. Total de insumos tratados nos últimos 6 meses\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Gerando relatório de custo total nos últimos 6 meses...\n");
                // Implementar lógica para gerar relatório de custo total
                break;
            case 2:
                printf("Gerando relatório de total de insumos tratados nos últimos 6 meses...\n");
                // Implementar lógica para gerar relatório de insumos tratados
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}