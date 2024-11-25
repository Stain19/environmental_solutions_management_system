/**
 * @file crud.h
 * @brief Arquivo de cabeçalho para operações CRUD na tabela 'industria' em um banco de dados SQLite.
 */

#ifndef REPOSITORY_INDUSTRIAS_H
#define REPOSITORY_INDUSTRIAS_H

#include <sqlite3.h>

/**
 * @brief Limpa a tela do console.
 */
void limparConsole();

/**
 * @brief Adiciona um novo registro de 'industria' ao banco de dados.
 * 
 * @param db Ponteiro para a conexão do banco de dados SQLite.
 */
void adicionarIndustria_db(sqlite3 *db);

/**
 * @brief Lista todos os registros de 'industria' do banco de dados.
 * 
 * @param db Ponteiro para a conexão do banco de dados SQLite.
 */
void listarIndustrias_db(sqlite3 *db);

/**
 * @brief Atualiza um registro existente de 'industria' no banco de dados.
 * 
 * @param db Ponteiro para a conexão do banco de dados SQLite.
 */
void atualizarIndustria_db(sqlite3 *db);

/**
 * @brief Deleta um registro de 'industria' do banco de dados.
 * 
 * @param db Ponteiro para a conexão do banco de dados SQLite.
 */
void deletarIndustria_db(sqlite3 *db);

#endif // REPOSITORY_INDUSTRIAS_H