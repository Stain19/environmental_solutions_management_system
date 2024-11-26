#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include <stdio.h>

#include "./common/db.h"

const char* obterSiglaEstado(EstadoBrasil estado) {
    switch (estado) {
        case ACRE: return "AC";
        case ALAGOAS: return "AL";
        case AMAPA: return "AP";
        case AMAZONAS: return "AM";
        case BAHIA: return "BA";
        case CEARA: return "CE";
        case DISTRITO_FEDERAL: return "DF";
        case ESPIRITO_SANTO: return "ES";
        case GOIAS: return "GO";
        case MARANHAO: return "MA";
        case MATO_GROSSO: return "MT";
        case MATO_GROSSO_DO_SUL: return "MS";
        case MINAS_GERAIS: return "MG";
        case PARA: return "PA";
        case PARAIBA: return "PB";
        case PARANA: return "PR";
        case PERNAMBUCO: return "PE";
        case PIAUI: return "PI";
        case RIO_DE_JANEIRO: return "RJ";
        case RIO_GRANDE_DO_NORTE: return "RN";
        case RIO_GRANDE_DO_SUL: return "RS";
        case RONDONIA: return "RO";
        case RORAIMA: return "RR";
        case SANTA_CATARINA: return "SC";
        case SAO_PAULO: return "SP";
        case SERGIPE: return "SE";
        case TOCANTINS: return "TO";
        default: return NULL;
    }
}

int validarSiglaEstado(const char* sigla) {
    const char* siglas[] = {
        "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"
    };
    for (int i = 0; i < sizeof(siglas) / sizeof(siglas[0]); i++) {
        if (strcmp(sigla, siglas[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void limparConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

sqlite3 *inicializarBancoDados(const char *nomeBanco)
{
    sqlite3 *db;
    char caminhoBanco[256];
    snprintf(caminhoBanco, sizeof(caminhoBanco), "./db/%s", nomeBanco);

    int rc = sqlite3_open(caminhoBanco, &db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Não foi possível abrir o banco de dados: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    return db;
}



int criarTabelaUsuarios(sqlite3 *db)
{
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS Usuarios("
                      "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "NomeUsuario TEXT NOT NULL, "
                      "SenhaHasheada TEXT NOT NULL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao criar tabela: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int inserirUsuario(sqlite3 *db, const char *nomeUsuario, const char *senhaHasheada)
{
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Usuarios (NomeUsuario, SenhaHasheada) VALUES ('%s', '%s');", nomeUsuario, senhaHasheada);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao inserir usuário: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int consultarUsuario(sqlite3 *db, const char *nomeUsuario, const char *senhaHasheada)
{
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Usuarios WHERE NomeUsuario = ? AND SenhaHasheada = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    sqlite3_bind_text(stmt, 1, nomeUsuario, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senhaHasheada, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        printf("Usuário encontrado: %s\n", sqlite3_column_text(stmt, 1));
        sqlite3_finalize(stmt);
        return SQLITE_OK;
    }
    else
    {
        printf("Usuário não encontrado.\n");
        sqlite3_finalize(stmt);
        return SQLITE_NOTFOUND;
    }
}

int criarTabelaIndustrias(sqlite3 *db)
{
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS Industrias("
                      "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "NomeResponsavel TEXT NOT NULL, "
                      "NomeEmpresa TEXT NOT NULL, "
                      "CNPJ TEXT NOT NULL, "
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

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao criar tabela: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int criarTabelaDeInsumosTratados(sqlite3 *db){
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS InsumosTratados("
                      "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "IndustriaId INTEGER NOT NULL, "
                      "QuantidadeResiduo REAL NOT NULL, "
                      "ValorEstimadoCusto REAL NOT NULL, "
                      "DataSemestre TEXT NOT NULL, "
                      "FOREIGN KEY(IndustriaId) REFERENCES Industrias(Id));";

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao criar tabela: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int inserirInsumoTratado(sqlite3 *db, InsumoTratado *insumoTratado)
{
    char *err_msg = 0;
    char sql[1024];
    snprintf(sql, sizeof(sql), "INSERT INTO InsumosTratados (IndustriaId, QuantidadeResiduo, ValorEstimadoCusto, DataSemestre) VALUES (%d, %f, %f, '%s');",
             insumoTratado->industriaId, insumoTratado->quantidadeResiduo, insumoTratado->valorEstimadoCusto, insumoTratado->dataSemestre);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao inserir insumo tratado: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int listarInsumosTratadosPorIdDaIndustria(sqlite3 *db){
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM InsumosTratados WHERE IndustriaId = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    int industriaId;
    printf("Digite o ID da indústria: ");
    scanf("%d", &industriaId);

    sqlite3_bind_int(stmt, 1, industriaId);

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        printf("ID: %d\n", sqlite3_column_int(stmt, 0));
        printf("ID da Indústria: %d\n", sqlite3_column_int(stmt, 1));
        printf("Quantidade de Resíduo: %.2f\n", sqlite3_column_double(stmt, 2));
        printf("Valor Estimado de Custo: %.2f\n", sqlite3_column_double(stmt, 3));
        printf("Data do Semestre: %s\n", sqlite3_column_text(stmt, 4));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}



int inserirIndustria(sqlite3 *db, Industria *industria)
{
    if (!validarSiglaEstado(industria->estado))
    {
        fprintf(stderr, "Erro: Sigla do estado inválida.\n");
        return SQLITE_ERROR;
    }

    char *err_msg = 0;
    char sql[1024];
    snprintf(sql, sizeof(sql), "INSERT INTO Industrias (NomeResponsavel, NomeEmpresa, CNPJ, RazaoSocial, NomeFantasia, Telefone, Rua, Numero, Bairro, Cidade, Estado, CEP, Email, DataAbertura) VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s');",
             industria->nomeResponsavel, industria->nomeEmpresa, industria->cnpj, industria->razaoSocial, industria->nomeFantasia, industria->telefone, industria->rua, industria->numero, industria->bairro, industria->cidade, industria->estado, industria->cep, industria->email, industria->dataAbertura);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao inserir indústria: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int atualizarIndustria(sqlite3 *db, Industria *industria)
{
    char *err_msg = 0;
    char sql[1024];
    snprintf(sql, sizeof(sql), "UPDATE Industrias SET NomeResponsavel = '%s', NomeEmpresa = '%s', RazaoSocial = '%s', NomeFantasia = '%s', Telefone = '%s', Rua = '%s', Numero = '%s', Bairro = '%s', Cidade = '%s', Estado = '%s', CEP = '%s', Email = '%s', DataAbertura = '%s' WHERE CNPJ = '%s';",
             industria->nomeResponsavel, industria->nomeEmpresa, industria->razaoSocial, industria->nomeFantasia, industria->telefone, industria->rua, industria->numero, industria->bairro, industria->cidade, industria->estado, industria->cep, industria->email, industria->dataAbertura, industria->cnpj);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao atualizar indústria: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int deletarIndustria(sqlite3 *db, const char *cnpj)
{
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM Industrias WHERE CNPJ = '%s';", cnpj);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao deletar indústria: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int listarIndustrias(sqlite3 *db)
{
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Industrias;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        printf("Nome do Responsável: %s\n", sqlite3_column_text(stmt, 1));
        printf("Nome da Empresa: %s\n", sqlite3_column_text(stmt, 2));
        printf("CNPJ: %s\n", sqlite3_column_text(stmt, 3));
        printf("Razão Social: %s\n", sqlite3_column_text(stmt, 4));
        printf("Nome Fantasia: %s\n", sqlite3_column_text(stmt, 5));
        printf("Telefone: %s\n", sqlite3_column_text(stmt, 6));
        printf("Rua: %s\n", sqlite3_column_text(stmt, 7));
        printf("Número: %s\n", sqlite3_column_text(stmt, 8));
        printf("Bairro: %s\n", sqlite3_column_text(stmt, 9));
        printf("Cidade: %s\n", sqlite3_column_text(stmt, 10));
        printf("Estado: %s\n", sqlite3_column_text(stmt, 11));
        printf("CEP: %s\n", sqlite3_column_text(stmt, 12));
        printf("Email: %s\n", sqlite3_column_text(stmt, 13));
        printf("Data de Abertura: %s\n", sqlite3_column_text(stmt, 14));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}

int consultarEmpresasPorEstado(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT Estado, SUM(ValorEstimadoCusto) AS CustoTotal "
                      "FROM Industrias "
                      "JOIN InsumosTratados ON Industrias.Id = InsumosTratados.IndustriaId "
                      "GROUP BY Estado;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("Estado: %s\n", sqlite3_column_text(stmt, 0));
        printf("Custo Total: %.2f\n", sqlite3_column_double(stmt, 1));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}

int consultarRankingIndustriaPorInsumos(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT NomeEmpresa, SUM(QuantidadeResiduo) AS TotalResiduos "
                      "FROM Industrias "
                      "JOIN InsumosTratados ON Industrias.Id = InsumosTratados.IndustriaId "
                      "GROUP BY NomeEmpresa "
                      "ORDER BY TotalResiduos ASC;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("Nome da Empresa: %s\n", sqlite3_column_text(stmt, 0));
        printf("Total de Resíduos: %.2f\n", sqlite3_column_double(stmt, 1));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}

int consultarCustoTotalPorEmpresa(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT NomeEmpresa, SUM(ValorEstimadoCusto) AS CustoTotal "
                      "FROM Industrias "
                      "JOIN InsumosTratados ON Industrias.Id = InsumosTratados.IndustriaId "
                      "GROUP BY NomeEmpresa;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("Nome da Empresa: %s\n", sqlite3_column_text(stmt, 0));
        printf("Custo Total: %.2f\n", sqlite3_column_double(stmt, 1));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}

int consultarTotalInsumosPorEmpresa(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT NomeEmpresa, SUM(QuantidadeResiduo) AS TotalResiduos "
                      "FROM Industrias "
                      "JOIN InsumosTratados ON Industrias.Id = InsumosTratados.IndustriaId "
                      "GROUP BY NomeEmpresa;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("Nome da Empresa: %s\n", sqlite3_column_text(stmt, 0));
        printf("Total de Resíduos: %.2f\n", sqlite3_column_double(stmt, 1));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}

void fecharConexaoDb(sqlite3 *db)
{
    sqlite3_close(db);
}