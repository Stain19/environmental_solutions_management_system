#include "./headers/tela-menu-industrias.h"
#include "../_industrias/headers/repository_industrias.h"

int exibirMenuIndustria(sqlite3 *db)
{
    bool flag_finalizar = false;
    while (!flag_finalizar)
    {
        int escolha;
        printf("\nMenu de Indústrias:\n");
        printf("1. Adicionar Indústria\n");
        printf("2. Listar Indústrias\n");
        printf("3. Atualizar Indústria\n");
        printf("4. Deletar Indústria\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            adicionarIndustria_db(db);
            break;
        case 2:
            listarIndustrias_db(db);
            break;
        case 3:
            atualizarIndustria_db(db);
            break;
        case 4:
            deletarIndustria_db(db);
            break;
        case 5:
            flag_finalizar = true;
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }
    return 0;
}
