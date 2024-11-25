#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>
#include <openssl/sha.h>
#include <unistd.h>

#include "../db/common/db.h"
#include "./headers/login.h"

// Função para hashear a senha usando SHA-256
void hashearSenha(const char *senha, char *senhaHasheada)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)senha, strlen(senha), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(senhaHasheada + (i * 2), "%02x", hash[i]);
    }
    senhaHasheada[SHA256_DIGEST_LENGTH * 2] = '\0';
}
/**
 * @file login.c
 * @brief Função para validar credenciais verificando contra um arquivo.
 *
 * Esta função lê um arquivo contendo credenciais válidas e compara com as
 * credenciais fornecidas pelo usuário para verificar se são válidas.
 *
 * @param nomeUsuario O nome de usuário fornecido pelo usuário.
 * @param senha A senha fornecida pelo usuário.
 * @return Retorna true se as credenciais forem válidas, caso contrário, retorna false.
 */
bool validarCredenciais(const char *nomeUsuario, const char *senha, sqlite3 *db)
{
    char senhaHasheada[SHA256_DIGEST_LENGTH * 2 + 1];
    hashearSenha(senha, senhaHasheada);

    int rc = consultarUsuario(db, nomeUsuario, senhaHasheada);

    return rc == SQLITE_OK;
}

/**
 * @brief Exibe a tela de login.
 *
 * Esta função exibe a mensagem de boas-vindas e solicita ao usuário que insira seu nome de usuário e senha.
 */
void exibirTelaLogin()
{
    printf("=====================================\n");
    printf("  Bem-vindo ao Sistema de Gestão Ambiental\n");
    printf("=====================================\n");
    sleep(3);
    limparTelaLogin();
    printf("Login \n");
    printf("Por favor, insira seu nome de usuário e senha.\n");
}

/**
 * @brief Recarrega a tela de login.
 *
 * Esta função exibe uma mensagem indicando que a tela de login está sendo recarregada.
 */
void recarregarTelaLogin()
{
    printf("Recarregando Tela de Login...\n");
    limparMensagemErro();
}

/**
 * @brief Fecha a tela de login.
 *
 * Esta função limpa o console, apagando todas as informações exibidas.
 */
void limparTelaLogin()
{
// Código para limpar o console no Windows
#ifdef _WIN32
    system("cls");
// Código para limpar o console no Unix/Linux/Mac
#else
    system("clear");
#endif
}

/**
 * @brief Exibe uma mensagem de erro.
 *
 * Esta função exibe uma mensagem de erro fornecida como parâmetro.
 *
 * @param mensagem A mensagem de erro a ser exibida.
 */
void exibirMensagemErro(const char *mensagem)
{
    limparTelaLogin();
    printf("Erro: %s\n", mensagem);
    printf("Pressione enter para continuar...\n");
    getchar();
}

/**
 * @brief Limpa a mensagem de erro.
 *
 * Esta função apaga todas as mensagens de erro do console.
 */
void limparMensagemErro()
{
// Código para limpar o console no Windows
#ifdef _WIN32
    system("cls");
// Código para limpar o console no Unix/Linux/Mac
#else
    system("clear");
#endif
}

/**
 * @brief Função para iniciar o processo de login do usuário.
 *
 * Esta função exibe a tela de login e solicita que o usuário insira seu nome de usuário e senha.
 * As credenciais são validadas e, se forem corretas, o login é considerado bem-sucedido.
 * Caso contrário, uma mensagem de erro é exibida e o usuário tem a opção de tentar novamente ou encerrar o programa.
 *
 * @note A função assume que as constantes MAX_USERNAME_LENGTH e MAX_PASSWORD_LENGTH estão definidas.
 * @note A função assume que as funções exibirTelaLogin(), validarCredenciais(), exibirMensagemErro(), limparMensagemErro() e recarregarTelaLogin() estão implementadas.
 */
void iniciarLogin(bool *terminarPrograma, sqlite3*db)
{
    char nomeUsuario[MAX_USERNAME_LENGTH];
    char senha[MAX_PASSWORD_LENGTH];
    bool credenciaisValidas = false;

    while (!credenciaisValidas)
    {
        exibirTelaLogin();

        printf("Nome de usuário: ");
        scanf("%s", nomeUsuario);

        if (strlen(nomeUsuario) >= MAX_USERNAME_LENGTH)
        {
            exibirMensagemErro("Nome de usuário excede o tamanho máximo permitido.");
            continue;
        }

        printf("Senha: ");
        scanf("%s", senha);

        if (strlen(senha) >= MAX_PASSWORD_LENGTH)
        {
            exibirMensagemErro("Senha excede o tamanho máximo permitido.");
            continue;
        }

        if (validarCredenciais(nomeUsuario, senha, db))
        {
            printf("Login bem-sucedido!\n");
            credenciaisValidas = true;
        }
        else
        {
            limparMensagemErro();
            exibirMensagemErro("Nome de usuário ou senha inválidos.");
            printf("Deseja tentar novamente? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            if (resposta == 'n' || resposta == 'N')
            {
                printf("Encerrando o programa...\n");
                *terminarPrograma = true;
                break;
            }
            recarregarTelaLogin();
        }
    }
}