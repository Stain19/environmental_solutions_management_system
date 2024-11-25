#include <stdio.h>
#include <unistd.h>
#include <sqlite3.h>

#include "../../auth/headers/login.h"
#include "../screens/headers/tela-principal.h"
#include "../screens/headers/tela-menu-industrias.h"
#include "../screens/headers/tela-menu-insumos.h"
#include "../screens/headers/tela-menu-relatorios.h"
#include "../../db/common/db.h"

int main()
{
    sqlite3 *db = inicializarBancoDados("sistema.db");
    if (db == NULL)
    {
        return 1;
    }
    bool terminarPrograma = false;
    iniciarLogin(&terminarPrograma, db);

    sleep(3);
    limparTelaLogin();

    while (!terminarPrograma)
    {
        limparTelaLogin();
        exibirMenuPrincipal();
        executarEscolha(&exibirMenuIndustria, &exibirMenuInsumos, &telaMenuRelatorios, &terminarPrograma, db);
    }
    return 0;
}