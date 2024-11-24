#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "./headers/login.h"

void adicionarUsuario(const char* nomeUsuario, const char* senha) {
    FILE* arquivo = fopen("usuarios.txt", "a");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo de dados do usuário.\n");
        return;
    }

    char senhaHasheada[SHA256_DIGEST_LENGTH * 2 + 1];
    hashearSenha(senha, senhaHasheada);

    fprintf(arquivo, "%s %s\n", nomeUsuario, senhaHasheada);
    fclose(arquivo);
}

int main() {
    // Credenciais dos usuários
    const char* usuarios[][2] = {
        {"admin", "password"},
        {"funcionario", "123456"},
        {"usuario1", "senha1"},
        {"usuario2", "senha2"}
    };

    // Adiciona os usuários ao arquivo
    for (int i = 0; i < 4; i++) {
        adicionarUsuario(usuarios[i][0], usuarios[i][1]);
    }

    printf("Usuários adicionados com sucesso.\n");
    return 0;
}