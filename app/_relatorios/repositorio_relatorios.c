#include <stdio.h>
#include <sqlite3.h>
#include "../../db/common/db.h"

void gerarRelatorioEmpresasPorEstado(sqlite3 *db) {
    consultarEmpresasPorEstado(db);
}

void gerarRankingIndustriaPorInsumos(sqlite3 *db) {
    consultarRankingIndustriaPorInsumos(db);
}

void gerarRelatorioCustoTotalPorEmpresa(sqlite3 *db) {
    consultarCustoTotalPorEmpresa(db);
}

void gerarRelatorioTotalInsumosPorEmpresa(sqlite3 *db) {
    consultarTotalInsumosPorEmpresa(db);
}