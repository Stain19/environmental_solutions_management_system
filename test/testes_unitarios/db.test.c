#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../../db/common/db.h"

void test_inicializarBancoDados() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    fecharConexaoDb(db);
    printf("test_inicializarBancoDados passed.\n");
}

void test_criarTabelaUsuarios() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    int rc = criarTabelaUsuarios(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_criarTabelaUsuarios passed.\n");
}

void test_inserirUsuario() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaUsuarios(db);
    int rc = inserirUsuario(db, "testuser", "testpassword");
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_inserirUsuario passed.\n");
}

void test_consultarUsuario() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaUsuarios(db);
    inserirUsuario(db, "testuser", "testpassword");
    int rc = consultarUsuario(db, "testuser", "testpassword");
    assert(rc == SQLITE_OK);
    rc = consultarUsuario(db, "nonexistent", "wrongpassword");
    assert(rc == SQLITE_NOTFOUND);
    fecharConexaoDb(db);
    printf("test_consultarUsuario passed.\n");
}

void test_criarTabelaIndustrias() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    int rc = criarTabelaIndustrias(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_criarTabelaIndustrias passed.\n");
}

void test_inserirIndustria() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    int rc = inserirIndustria(db, &industria);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_inserirIndustria passed.\n");
}

void test_listarIndustrias() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    inserirIndustria(db, &industria);
    int rc = listarIndustrias(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_listarIndustrias passed.\n");
}
void test_criarTabelaDeInsumosTratados() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    int rc = criarTabelaDeInsumosTratados(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_criarTabelaDeInsumosTratados passed.\n");
}

void test_inserirInsumoTratado() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    criarTabelaDeInsumosTratados(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    inserirIndustria(db, &industria);
    InsumoTratado insumoTratado = {
        .industriaId = 1,
        .quantidadeResiduo = 100.0,
        .valorEstimadoCusto = 500.0,
        .dataSemestre = "2023-01-01"
    };
    int rc = inserirInsumoTratado(db, &insumoTratado);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_inserirInsumoTratado passed.\n");
}

void test_listarInsumosTratadosPorIdDaIndustria() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    criarTabelaDeInsumosTratados(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    inserirIndustria(db, &industria);
    InsumoTratado insumoTratado = {
        .industriaId = 1,
        .quantidadeResiduo = 100.0,
        .valorEstimadoCusto = 500.0,
        .dataSemestre = "2023-01-01"
    };
    inserirInsumoTratado(db, &insumoTratado);
    int rc = listarInsumosTratadosPorIdDaIndustria(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_listarInsumosTratadosPorIdDaIndustria passed.\n");
}

void test_consultarEmpresasPorEstado() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    criarTabelaDeInsumosTratados(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    inserirIndustria(db, &industria);
    InsumoTratado insumoTratado = {
        .industriaId = 1,
        .quantidadeResiduo = 100.0,
        .valorEstimadoCusto = 500.0,
        .dataSemestre = "2023-01-01"
    };
    inserirInsumoTratado(db, &insumoTratado);
    int rc = consultarEmpresasPorEstado(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_consultarEmpresasPorEstado passed.\n");
}

void test_consultarRankingIndustriaPorInsumos() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    criarTabelaDeInsumosTratados(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    inserirIndustria(db, &industria);
    InsumoTratado insumoTratado = {
        .industriaId = 1,
        .quantidadeResiduo = 100.0,
        .valorEstimadoCusto = 500.0,
        .dataSemestre = "2023-01-01"
    };
    inserirInsumoTratado(db, &insumoTratado);
    int rc = consultarRankingIndustriaPorInsumos(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_consultarRankingIndustriaPorInsumos passed.\n");
}

void test_consultarCustoTotalPorEmpresa() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    criarTabelaDeInsumosTratados(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    inserirIndustria(db, &industria);
    InsumoTratado insumoTratado = {
        .industriaId = 1,
        .quantidadeResiduo = 100.0,
        .valorEstimadoCusto = 500.0,
        .dataSemestre = "2023-01-01"
    };
    inserirInsumoTratado(db, &insumoTratado);
    int rc = consultarCustoTotalPorEmpresa(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_consultarCustoTotalPorEmpresa passed.\n");
}

void test_consultarTotalInsumosPorEmpresa() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    criarTabelaIndustrias(db);
    criarTabelaDeInsumosTratados(db);
    Industria industria = {
        .nomeResponsavel = "Responsavel Teste",
        .nomeEmpresa = "Empresa Teste",
        .cnpj = "00.000.000/0000-00",
        .razaoSocial = "Razao Social Teste",
        .nomeFantasia = "Nome Fantasia Teste",
        .telefone = "0000-0000",
        .rua = "Rua Teste",
        .numero = "123",
        .bairro = "Bairro Teste",
        .cidade = "Cidade Teste",
        .estado = "SP",
        .cep = "00000-000",
        .email = "email@teste.com",
        .dataAbertura = "2023-01-01"
    };
    inserirIndustria(db, &industria);
    InsumoTratado insumoTratado = {
        .industriaId = 1,
        .quantidadeResiduo = 100.0,
        .valorEstimadoCusto = 500.0,
        .dataSemestre = "2023-01-01"
    };
    inserirInsumoTratado(db, &insumoTratado);
    int rc = consultarTotalInsumosPorEmpresa(db);
    assert(rc == SQLITE_OK);
    fecharConexaoDb(db);
    printf("test_consultarTotalInsumosPorEmpresa passed.\n");
}

int main() {
    test_inicializarBancoDados();
    test_criarTabelaUsuarios();
    test_inserirUsuario();
    test_consultarUsuario();
    test_criarTabelaIndustrias();
    test_inserirIndustria();
    test_listarIndustrias();
    test_criarTabelaDeInsumosTratados();
    test_inserirInsumoTratado();
    test_listarInsumosTratadosPorIdDaIndustria();
    test_consultarEmpresasPorEstado();
    test_consultarRankingIndustriaPorInsumos();
    test_consultarCustoTotalPorEmpresa();
    test_consultarTotalInsumosPorEmpresa();
    return 0;
}
