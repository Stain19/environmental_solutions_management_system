#ifndef TELA_MENU_INDUSTRIAS_H
#define TELA_MENU_INDUSTRIAS_H

#include <stdio.h>
#include <stdbool.h>
#include <sqlite3.h>

/**
 * @brief Exibe o menu de indústrias e executa a função correspondente à escolha do usuário.
 *
 * Esta função exibe um menu com opções para adicionar, listar, atualizar e deletar indústrias.
 * A escolha do usuário é lida e a função correspondente é executada.
 *
 * @param db Ponteiro para a conexão do banco de dados SQLite.
 * @return int Retorna 0 após a execução do menu.
 */
int exibirMenuIndustria(sqlite3 *db);

#endif // TELA_MENU_INDUSTRIAS_H