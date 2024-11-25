#include <sqlite3.h>
#include <stdio.h>

#include "../db/common/db.h"

int adicionarConstraintUnicidade(sqlite3 *db) {
    char *err_msg = 0;
    int rc;

    // Iniciar uma transação
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao iniciar transação: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    // Criar uma nova tabela com a constraint de unicidade
    const char *sql_create_new_table = 
        "CREATE TABLE IF NOT EXISTS Industrias_new ("
        "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NomeResponsavel TEXT NOT NULL, "
        "NomeEmpresa TEXT NOT NULL, "
        "CNPJ TEXT NOT NULL UNIQUE, "
        "RazaoSocial TEXT NOT NULL, "
        "NomeFantasia TEXT NOT NULL, "
        "Telefone TEXT NOT NULL, "
        "Rua TEXT NOT NULL, "
        "Numero TEXT NOT NULL, "
        "Bairro TEXT NOT NULL, "
        "Cidade TEXT NOT NULL, "
        "Estado TEXT NOT NULL, "
        "CEP TEXT NOT NULL, "
        "Email TEXT NOT NULL, "
        "DataAbertura TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql_create_new_table, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao criar nova tabela: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_exec(db, "ROLLBACK;", 0, 0, 0);
        return rc;
    }

    // Copiar os dados da tabela antiga para a nova tabela
    const char *sql_copy_data = 
        "INSERT INTO Industrias_new (Id, NomeResponsavel, NomeEmpresa, CNPJ, RazaoSocial, NomeFantasia, Telefone, Rua, Numero, Bairro, Cidade, Estado, CEP, Email, DataAbertura) "
        "SELECT Id, NomeResponsavel, NomeEmpresa, CNPJ, RazaoSocial, NomeFantasia, Telefone, Rua, Numero, Bairro, Cidade, Estado, CEP, Email, DataAbertura FROM Industrias;";

    rc = sqlite3_exec(db, sql_copy_data, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao copiar dados para nova tabela: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_exec(db, "ROLLBACK;", 0, 0, 0);
        return rc;
    }

    // Renomear a tabela antiga
    const char *sql_rename_old_table = "ALTER TABLE Industrias RENAME TO Industrias_old;";
    rc = sqlite3_exec(db, sql_rename_old_table, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao renomear tabela antiga: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_exec(db, "ROLLBACK;", 0, 0, 0);
        return rc;
    }

    // Renomear a nova tabela para o nome original
    const char *sql_rename_new_table = "ALTER TABLE Industrias_new RENAME TO Industrias;";
    rc = sqlite3_exec(db, sql_rename_new_table, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao renomear nova tabela: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_exec(db, "ROLLBACK;", 0, 0, 0);
        return rc;
    }

    // Finalizar a transação
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao finalizar transação: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int main() {
    sqlite3 *db = inicializarBancoDados("sistema.db");
    if (db == NULL) {
        return 1;
    }

    int rc = adicionarConstraintUnicidade(db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao adicionar constraint de unicidade.\n");
        sqlite3_close(db);
        return 1;
    }

    printf("Constraint de unicidade adicionada com sucesso.\n");

    sqlite3_close(db);
    return 0;
}