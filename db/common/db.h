#ifndef DB_H
#define DB_H

#include <sqlite3.h>

#define MAX_LENGTH 100

typedef enum {
    NORTE,
    NORDESTE,
    CENTRO_OESTE,
    SUDESTE,
    SUL
} RegiaoBrasil;

typedef enum {
    ACRE,
    ALAGOAS,
    AMAPA,
    AMAZONAS,
    BAHIA,
    CEARA,
    DISTRITO_FEDERAL,
    ESPIRITO_SANTO,
    GOIAS,
    MARANHAO,
    MATO_GROSSO,
    MATO_GROSSO_DO_SUL,
    MINAS_GERAIS,
    PARA,
    PARAIBA,
    PARANA,
    PERNAMBUCO,
    PIAUI,
    RIO_DE_JANEIRO,
    RIO_GRANDE_DO_NORTE,
    RIO_GRANDE_DO_SUL,
    RONDONIA,
    RORAIMA,
    SANTA_CATARINA,
    SAO_PAULO,
    SERGIPE,
    TOCANTINS
} EstadoBrasil;

const char* obterSiglaEstado(EstadoBrasil estado);
int validarSiglaEstado(const char* sigla);

typedef struct
{
    char nomeResponsavel[MAX_LENGTH];
    char nomeEmpresa[MAX_LENGTH];
    char cnpj[MAX_LENGTH];
    char razaoSocial[MAX_LENGTH];
    char nomeFantasia[MAX_LENGTH];
    char telefone[MAX_LENGTH];
    char rua[MAX_LENGTH];
    char numero[MAX_LENGTH];
    char bairro[MAX_LENGTH];
    char cidade[MAX_LENGTH];
    char estado[MAX_LENGTH];
    char cep[MAX_LENGTH];
    char email[MAX_LENGTH];
    char dataAbertura[MAX_LENGTH];
} Industria;

typedef struct
{
    char nomeUsuario[MAX_LENGTH];
    char senhaHasheada[MAX_LENGTH];
} Usuario;

typedef struct
{
    int id;
    int industriaId;
    float quantidadeResiduo;
    float valorEstimadoCusto;
    char dataSemestre[MAX_LENGTH];
} InsumoTratado;

void limparConsole();
sqlite3* inicializarBancoDados(const char* nomeBanco);
int criarTabelaUsuarios(sqlite3 *db);
int inserirUsuario(sqlite3 *db, const char* nomeUsuario, const char* senhaHasheada);
int consultarUsuario(sqlite3 *db, const char* nomeUsuario, const char* senhaHasheada);
int criarTabelaIndustrias(sqlite3 *db);
int inserirIndustria(sqlite3 *db, Industria *industria);
int atualizarIndustria(sqlite3 *db, Industria *industria);
int deletarIndustria(sqlite3 *db, const char* cnpj);
int listarIndustrias(sqlite3 *db);
int criarTabelaDeInsumosTratados(sqlite3 *db);
int inserirInsumoTratado(sqlite3 *db, InsumoTratado *insumoTratado);
int listarInsumosTratadosPorIdDaIndustria(sqlite3 *db);
int consultarEmpresasPorEstado(sqlite3 *db);
int consultarRankingIndustriaPorInsumos(sqlite3 *db);
int consultarCustoTotalPorEmpresa(sqlite3 *db);
int consultarTotalInsumosPorEmpresa(sqlite3 *db);
void fecharConexaoDb(sqlite3* db);

#endif // DB_H
