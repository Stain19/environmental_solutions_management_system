#ifndef TELA_MENU_RELATORIOS_H
#define TELA_MENU_RELATORIOS_H

#include <sqlite3.h>

/**
 * @brief Exibe o menu de relatórios.
 *
 * Esta função exibe o menu principal de relatórios e lida com as interações do usuário.
 */
int telaMenuRelatorios(sqlite3 *db);

/**
 * @brief Exibe o menu de relatórios globais.
 *
 * Esta função exibe o menu de relatórios globais e lida com as interações do usuário.
 */
void telaRelatoriosGlobais();

/**
 * @brief Exibe o menu de relatórios por empresa.
 *
 * Esta função exibe o menu de relatórios por empresa e lida com as interações do usuário.
 */
void telaRelatoriosPorEmpresa();

#endif // TELA_MENU_RELATORIOS_H