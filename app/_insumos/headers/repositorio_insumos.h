#ifndef REPOSITORIO_INSUMOS_H
#define REPOSITORIO_INSUMOS_H
#include <stdio.h>
#include <stdbool.h>
#include <sqlite3.h>

/**
 * @brief Adiciona um insumo ao banco de dados.
 * 
 * Esta função insere um novo insumo na tabela do banco de dados SQLite fornecido.
 * 
 * @param db Ponteiro para o banco de dados SQLite onde o insumo será adicionado.
 */
void adicionarInsumo_db(sqlite3 *db);

/**
 * @brief Lista todos os insumos do banco de dados.
 * 
 * Esta função recupera e exibe todos os insumos armazenados na tabela do banco de dados SQLite fornecido.
 * 
 * @param db Ponteiro para o banco de dados SQLite de onde os insumos serão listados.
 */
void listarInsumosTratadosPorCNPJ(sqlite3 *db);

/**
 * @brief Atualiza um insumo no banco de dados.
 * 
 * Esta função atualiza as informações de um insumo existente na tabela do banco de dados SQLite fornecido.
 * 
 * @param db Ponteiro para o banco de dados SQLite onde o insumo será atualizado.
 */
void atualizarInsumo_db(sqlite3 *db);

/**
 * @brief Deleta um insumo do banco de dados.
 * 
 * Esta função remove um insumo da tabela do banco de dados SQLite fornecido.
 * 
 * @param db Ponteiro para o banco de dados SQLite de onde o insumo será deletado.
 */
void deletarInsumo_db(sqlite3 *db);

#endif // REPOSITORIO_INSUMOS_H