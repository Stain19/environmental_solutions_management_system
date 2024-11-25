#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sqlite3.h>

#include "../_industrias/headers/repository_industrias.h"
#include "../../db/common/db.h"

#define MAX_LENGTH 100

void adicionarIndustria_db(sqlite3 *db)
{
    Industria industria;

    printf("Nome do Responsável: ");
    scanf(" %[^\n]", industria.nomeResponsavel);
    printf("Nome da Empresa: ");
    scanf(" %[^\n]", industria.nomeEmpresa);
    printf("CNPJ: ");
    scanf(" %[^\n]", industria.cnpj);
    printf("Razão Social: ");
    scanf(" %[^\n]", industria.razaoSocial);
    printf("Nome Fantasia: ");
    scanf(" %[^\n]", industria.nomeFantasia);
    printf("Telefone: ");
    scanf(" %[^\n]", industria.telefone);
    printf("Rua: ");
    scanf(" %[^\n]", industria.rua);
    printf("Número: ");
    scanf(" %[^\n]", industria.numero);
    printf("Bairro: ");
    scanf(" %[^\n]", industria.bairro);
    printf("Cidade: ");
    scanf(" %[^\n]", industria.cidade);
    printf("Estado(Apenas Sigla): ");
    scanf(" %[^\n]", industria.estado);
    printf("CEP: ");
    scanf(" %[^\n]", industria.cep);
    printf("Email: ");
    scanf(" %[^\n]", industria.email);
    printf("Data de Abertura: ");
    scanf(" %[^\n]", industria.dataAbertura);

    if (inserirIndustria(db, &industria) == SQLITE_OK)
    {
        limparConsole();
        printf("Indústria adicionada com sucesso!\n");
    }
    else
    {
        printf("Erro ao adicionar indústria.\n");
        sleep(3);
        limparConsole();
    }
    sleep(3);
    limparConsole();
}

void listarIndustrias_db(sqlite3 *db)
{
    limparConsole();
    printf("Lista de Indústrias:\n");

    int status = listarIndustrias(db);
    if (status != SQLITE_OK)
    {
        printf("Erro ao listar indústrias.\n");
    }

    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
    getchar();
    limparConsole();
}

void atualizarIndustria_db(sqlite3 *db)
{
    Industria industria;
    char cnpj[MAX_LENGTH];

    printf("Digite o CNPJ da indústria a ser atualizada: ");
    scanf(" %[^\n]", cnpj);

    printf("Digite os novos dados da indústria:\n");
    printf("Nome do Responsável: ");
    scanf(" %[^\n]", industria.nomeResponsavel);
    printf("Nome da Empresa: ");
    scanf(" %[^\n]", industria.nomeEmpresa);
    printf("Razão Social: ");
    scanf(" %[^\n]", industria.razaoSocial);
    printf("Nome Fantasia: ");
    scanf(" %[^\n]", industria.nomeFantasia);
    printf("Telefone: ");
    scanf(" %[^\n]", industria.telefone);
    printf("Rua: ");
    scanf(" %[^\n]", industria.rua);
    printf("Número: ");
    scanf(" %[^\n]", industria.numero);
    printf("Bairro: ");
    scanf(" %[^\n]", industria.bairro);
    printf("Cidade: ");
    scanf(" %[^\n]", industria.cidade);
    printf("Estado: ");
    scanf(" %[^\n]", industria.estado);
    printf("CEP: ");
    scanf(" %[^\n]", industria.cep);
    printf("Email: ");
    scanf(" %[^\n]", industria.email);
    printf("Data de Abertura: ");
    scanf(" %[^\n]", industria.dataAbertura);

    strcpy(industria.cnpj, cnpj);

    if (atualizarIndustria(db, &industria) == SQLITE_OK)
    {
        limparConsole();
        printf("Indústria atualizada com sucesso!\n");
    }
    else
    {
        limparConsole();
        printf("Erro ao atualizar indústria.\n");
    }
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
    getchar();
}

void deletarIndustria_db(sqlite3 *db)
{
    char cnpj[MAX_LENGTH];

    printf("Digite o CNPJ da indústria a ser deletada: ");
    scanf(" %[^\n]", cnpj);

    if (deletarIndustria(db, cnpj) == SQLITE_OK)
    {
        limparConsole();
        printf("Indústria deletada com sucesso!\n");
    }
    else
    {
        limparConsole();
        printf("Erro ao deletar indústria.\n");
    }
    sleep(3);
    limparConsole();
}
