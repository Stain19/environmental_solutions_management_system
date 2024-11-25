/**
 * @file tela-menu-insumos.h
 * @brief Arquivo de cabeçalho para as funções da tela do Menu de Insumos.
 *
 * Este arquivo contém as declarações de funções para gerenciar o Menu de Insumos
 * no aplicativo, incluindo a exibição do menu, adição de insumos ao banco de dados,
 * e listagem de insumos tratados por CNPJ.
 */
#ifndef TELA_MENU_INSUMOS_H
#define TELA_MENU_INSUMOS_H

#include <stdio.h>
#include <stdbool.h>
#include <sqlite3.h>

/**
 * @brief Exibe o Menu de Insumos.
 *
 * Esta função exibe o Menu de Insumos e lida com as interações do usuário.
 *
 * @param db Um ponteiro para a conexão com o banco de dados SQLite.
 * @return Um inteiro indicando o sucesso ou falha da operação.
 */
int exibirMenuInsumos(sqlite3 *db);

#endif // TELA_MENU_INSUMOS_H