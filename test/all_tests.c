#include <sqlite3.h>
#include <stdio.h>
#include <assert.h>
#include "../../auth/headers/login.h"
#include "../../db/common/db.h"
#include "../../app/screens/headers/tela-principal.h"
#include "../../app/screens/headers/tela-menu-industrias.h"
#include "../../app/screens/headers/tela-menu-insumos.h"
#include "../../app/screens/headers/tela-menu-relatorios.h"

// Declarações das funções de teste de db.test.c
void test_inicializarBancoDados();
void test_criarTabelaUsuarios();
void test_inserirUsuario();
void test_consultarUsuario();
void test_criarTabelaIndustrias();
void test_inserirIndustria();
void test_listarIndustrias();
void test_criarTabelaDeInsumosTratados();
void test_inserirInsumoTratado();
void test_listarInsumosTratadosPorIdDaIndustria();
void test_consultarEmpresasPorEstado();
void test_consultarRankingIndustriaPorInsumos();
void test_consultarCustoTotalPorEmpresa();
void test_consultarTotalInsumosPorEmpresa();

// Declarações das funções de teste de main.test.c
void test_iniciarLogin();
void test_exibirMenuPrincipal();
void test_exibirMenuIndustria();
void test_exibirMenuInsumos();
void test_telaMenuRelatorios();
void test_executarEscolha();

int main() {
    // Chamadas das funções de teste de db.test.c
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

    // Chamadas das funções de teste de main.test.c
    test_iniciarLogin();
    test_exibirMenuPrincipal();
    test_exibirMenuIndustria();
    test_exibirMenuInsumos();
    test_telaMenuRelatorios();
    test_executarEscolha();

    printf("Todos os testes passaram.\n");
    return 0;
}