#include "./headers/tela-menu-insumos.h"
#include "../_insumos/headers/repositorio_insumos.h"

int exibirMenuInsumos(sqlite3 *db)
{
    bool flag_finalizar = false;
    while (!flag_finalizar)
    {
        int escolha;
        printf("\nMenu de Insumos Tratados:\n");
        printf("1. Adicionar Insumo Tratado\n");
        printf("2. Listar Insumos Tratados por CNPJ\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            adicionarInsumo_db(db);
            break;
        case 2:
            listarInsumosTratadosPorCNPJ(db);
            break;
        case 3:
            flag_finalizar = true;
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }
    return 0;
}