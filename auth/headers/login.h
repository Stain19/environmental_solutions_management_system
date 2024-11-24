#ifndef LOGIN_H
#define LOGIN_H

#include <stdbool.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Function declarations
void hashearSenha(const char* senha, char* senhaHasheada);
bool validarCredenciais(const char* nomeUsuario, const char* senha);
void exibirTelaLogin();
void recarregarTelaLogin();
void limparTelaLogin();
void exibirMensagemErro(const char* mensagem);
void limparMensagemErro();
void iniciarLogin();

#endif
