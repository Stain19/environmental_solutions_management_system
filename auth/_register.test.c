#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include <openssl/sha.h>
#include "../db/common/db.h"
#include "./headers/login.h"

void adicionarUsuario(const char* nomeUsuario, const char* senha) {
    sqlite3 *db = inicializarBancoDados("sistema.db");
    if (db == NULL) {
        printf("Não foi possível abrir o banco de dados.\n");
        return;
    }

    char senhaHasheada[SHA256_DIGEST_LENGTH * 2 + 1];
    hashearSenha(senha, senhaHasheada);

    int rc = inserirUsuario(db, nomeUsuario, senhaHasheada);
    if (rc != SQLITE_OK) {
        printf("Erro ao inserir usuário no banco de dados.\n");
    } else {
        printf("Usuário %s adicionado com sucesso.\n", nomeUsuario);
    }

    fecharConexaoDb(db);
}


int main() {
    // Inicializa o banco de dados
    sqlite3 *db = inicializarBancoDados("sistema.db");
    if (db == NULL) {
        return 1;
    }

    // Cria a tabela de usuários
    if (criarTabelaUsuarios(db) != SQLITE_OK) {
        sqlite3_close(db);
        return 1;
    }

    if(criarTabelaIndustrias(db) != SQLITE_OK) {
        sqlite3_close(db);
        return 1;
    }

    if(criarTabelaDeInsumosTratados(db) != SQLITE_OK) {
        sqlite3_close(db);
        return 1;
    }

    // Insere um usuário de exemplo
    if (inserirUsuario(db, "admin", "5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8") != SQLITE_OK) {
        sqlite3_close(db);
        return 1;
    }

    // Consulta o usuário inserido
    consultarUsuario(db, "admin", "5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8");

    // Fecha o banco de dados
    sqlite3_close(db);

    return 0;
}