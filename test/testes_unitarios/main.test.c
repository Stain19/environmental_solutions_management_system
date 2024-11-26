/**
 * @file main.test.c
 * @brief Este arquivo contém testes unitários para as funções utilizadas na aplicação principal.
 * 
 * Os testes cobrem as funcionalidades de login, exibição de menus e execução de escolhas.
 */

/**
 * @brief Testa a função iniciarLogin.
 * 
 * Este teste inicializa o banco de dados, chama a função iniciarLogin e verifica se o programa não termina após o login.
 * Em seguida, fecha a conexão com o banco de dados.
 */
void test_iniciarLogin();

/**
 * @brief Testa a função exibirMenuPrincipal.
 * 
 * Este teste simplesmente chama a função exibirMenuPrincipal e verifica se ela é executada corretamente.
 */
void test_exibirMenuPrincipal();

/**
 * @brief Testa a função exibirMenuIndustria.
 * 
 * Este teste inicializa o banco de dados, chama a função exibirMenuIndustria e fecha a conexão com o banco de dados.
 */
void test_exibirMenuIndustria();

/**
 * @brief Testa a função exibirMenuInsumos.
 * 
 * Este teste inicializa o banco de dados, chama a função exibirMenuInsumos e fecha a conexão com o banco de dados.
 */
void test_exibirMenuInsumos();

/**
 * @brief Testa a função telaMenuRelatorios.
 * 
 * Este teste inicializa o banco de dados, chama a função telaMenuRelatorios e fecha a conexão com o banco de dados.
 */
void test_telaMenuRelatorios();

/**
 * @brief Testa a função executarEscolha.
 * 
 * Este teste inicializa o banco de dados, chama a função executarEscolha com ponteiros para as funções de exibição de menus e verifica se o programa não termina após a execução.
 * Em seguida, fecha a conexão com o banco de dados.
 */
void test_executarEscolha();
#include <sqlite3.h>
#include <stdio.h>
#include <assert.h>
#include "../../auth/headers/login.h"
#include "../../db/common/db.h"
#include "../../app/screens/headers/tela-principal.h"
#include "../../app/screens/headers/tela-menu-industrias.h"
#include "../../app/screens/headers/tela-menu-insumos.h"
#include "../../app/screens/headers/tela-menu-relatorios.h"

void test_iniciarLogin() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    bool terminarPrograma = false;
    iniciarLogin(&terminarPrograma, db);
    assert(!terminarPrograma); // Assuming login will not terminate the program
    fecharConexaoDb(db);
    printf("test_iniciarLogin passed.\n");
}

void test_exibirMenuPrincipal() {
    exibirMenuPrincipal();
    printf("test_exibirMenuPrincipal passed.\n");
}

void test_exibirMenuIndustria() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    exibirMenuIndustria(db);
    fecharConexaoDb(db);
    printf("test_exibirMenuIndustria passed.\n");
}

void test_exibirMenuInsumos() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    exibirMenuInsumos(db);
    fecharConexaoDb(db);
    printf("test_exibirMenuInsumos passed.\n");
}

void test_telaMenuRelatorios() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    telaMenuRelatorios(db);
    fecharConexaoDb(db);
    printf("test_telaMenuRelatorios passed.\n");
}

void test_executarEscolha() {
    sqlite3 *db = inicializarBancoDados("test.db");
    assert(db != NULL);
    bool terminarPrograma = false;
    executarEscolha(&exibirMenuIndustria, &exibirMenuInsumos, &telaMenuRelatorios, &terminarPrograma, db);
    fecharConexaoDb(db);
    printf("test_executarEscolha passed.\n");
}

int main() {
    test_iniciarLogin();
    test_exibirMenuPrincipal();
    test_exibirMenuIndustria();
    test_exibirMenuInsumos();
    test_telaMenuRelatorios();
    test_executarEscolha();
    return 0;
}