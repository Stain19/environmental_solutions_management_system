#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <unistd.h>

#include "../../db/common/db.h"

#define MAX_LENGTH 100

void adicionarInsumo_db(sqlite3 *db)
{
    InsumoTratado insumoTratado;
    char dataSemestre[MAX_LENGTH];

    char cnpj[MAX_LENGTH];
    printf("CNPJ da Indústria: ");
    scanf(" %[^\n]", cnpj);

    sqlite3_stmt *stmt;
    const char *sql = "SELECT Id FROM Industrias WHERE CNPJ = ?;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, cnpj, -1, SQLITE_STATIC);

    insumoTratado.industriaId = -1;
    if ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        insumoTratado.industriaId = sqlite3_column_int(stmt, 0);
    }
    sqlite3_finalize(stmt);

    if (insumoTratado.industriaId == -1)
    {
        limparConsole();
        printf("Indústria não encontrada.\n");
        sleep(3);
        limparConsole();
        return;
    }

    printf("Quantidade de Resíduo: ");
    scanf("%f", &insumoTratado.quantidadeResiduo);
    printf("Valor Estimado de Custo: ");
    scanf("%f", &insumoTratado.valorEstimadoCusto);
    printf("Data do Semestre: ");
    scanf(" %[^\n]", insumoTratado.dataSemestre);



    if (inserirInsumoTratado(db, &insumoTratado) == SQLITE_OK)
    {
        limparConsole();
        printf("Insumo tratado adicionado com sucesso!\n");
    }
    else
    {
        limparConsole();
        printf("Erro ao adicionar insumo tratado.\n");
    }
    sleep(3);
    limparConsole();
}

void listarInsumosTratadosPorCNPJ(sqlite3 *db)
{
    char cnpj[MAX_LENGTH];
    printf("Digite o CNPJ da indústria: ");
    scanf(" %[^\n]", cnpj);

    sqlite3_stmt *stmt;
    const char *sql = "SELECT InsumosTratados.* FROM InsumosTratados "
                      "JOIN Industrias ON InsumosTratados.IndustriaId = Industrias.Id "
                      "WHERE Industrias.CNPJ = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, cnpj, -1, SQLITE_STATIC);

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        printf("ID: %d\n", sqlite3_column_int(stmt, 0));
        printf("ID da Indústria: %d\n", sqlite3_column_int(stmt, 1));
        printf("Quantidade de Resíduo: %.2f\n", sqlite3_column_double(stmt, 2));
        printf("Valor Estimado de Custo: %.2f\n", sqlite3_column_double(stmt, 3));
        printf("Data do Semestre: %s\n", sqlite3_column_text(stmt, 4));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
    getchar();
    limparConsole();
}
// void listarInsumoTratadosPorCNPJ(sqlite3 *db)
// {
//     char cnpj[MAX_LENGTH];
//     float quantidadeResiduo, valorEstimadoCusto;
//     char dataSemestre[MAX_LENGTH];

//     printf("CNPJ da Indústria: ");
//     scanf(" %[^\n]", cnpj);
//     printf("Quantidade de Resíduo: ");
//     scanf("%f", &quantidadeResiduo);
//     printf("Valor Estimado de Custo: ");
//     scanf("%f", &valorEstimadoCusto);
//     printf("Data do Semestre: ");
//     scanf(" %[^\n]", dataSemestre);

//     sqlite3_stmt *stmt;
//     const char *sql = "SELECT Id FROM Industrias WHERE CNPJ = ?;";
//     int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
//     if (rc != SQLITE_OK)
//     {
//         fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
//         return;
//     }

//     sqlite3_bind_text(stmt, 1, cnpj, -1, SQLITE_STATIC);

//     int industriaId = -1;
//     if ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
//     {
//         industriaId = sqlite3_column_int(stmt, 0);
//     }
//     sqlite3_finalize(stmt);

//     if (industriaId == -1)
//     {
//         limparConsole();
//         printf("Indústria não encontrada.\n");
//         sleep(3);
//         limparConsole();
//         return;
//     }

//     if (inserirInsumoTratado(db, industriaId, quantidadeResiduo, valorEstimadoCusto, dataSemestre) == SQLITE_OK)
//     {
//         limparConsole();
//         printf("Insumo tratado adicionado com sucesso!\n");
//     }
//     else
//     {
//         limparConsole();
//         printf("Erro ao adicionar insumo tratado.\n");
//     }
//     sleep(3);
//     limparConsole();
// }