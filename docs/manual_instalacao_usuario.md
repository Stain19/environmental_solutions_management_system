# Manual de Instalação e Uso do Software

## Introdução
Este manual fornece instruções detalhadas sobre como instalar e utilizar o software desenvolvido para gerenciar as tarefas de cadastro e relatórios de uma startup de soluções ambientais.

## Requisitos do Sistema
- Sistema Operacional: Windows, macOS ou Linux
- Compilador C: GCC ou equivalente
- Bibliotecas Necessárias: `libsqlite3-dev`, `libssl-dev`

## Instalação

### Passo 1: Navegar para o Diretório do Projeto

```bash
cd caminho/do/diretorio/baixado
```

### Passo 2: Compilar o Código
```bash
gcc -o startup_ambiental main.c db.c login.c tela-principal.c tela-menu-relatorios.c repositorio_industrias.c repositorio_insumos.c -lsqlite3 -lssl -lcrypto
```

### Passo 3: Executar o Programa
```bash
./startup_ambiental
```

## Uso do Software

### Tela de Login
1. **Usuário**: Insira seu nome de usuário.
2. **Senha**: Insira sua senha.
3. Clique em **Login** para acessar o sistema.

### Menu Principal
Após o login, você verá o menu principal com as seguintes opções:
- **Gerenciamento de Indústrias**
- **Gestão de Insumos**
- **Relatórios**

### Gerenciamento de Indústrias
1. **Adicionar Indústria**: Preencha os dados da indústria e clique em **Salvar**.
2. **Listar Indústrias**: Visualize a lista de indústrias cadastradas.
3. **Atualizar Indústria**: Selecione uma indústria e atualize as informações necessárias.
4. **Deletar Indústria**: Selecione uma indústria e clique em **Deletar**.

### Gestão de Insumos
1. **Adicionar Insumo**: Preencha os dados do insumo e clique em **Salvar**.
2. **Listar Insumos por CNPJ**: Insira o CNPJ e visualize os insumos cadastrados.

### Relatórios
1. **Relatórios Globais**: Gere relatórios com dados agregados.
2. **Relatórios por Empresa**: Gere relatórios específicos para cada empresa.

### Exportação de Relatórios
Os relatórios podem ser exportados nos formatos TXT, XLS ou CSV. Selecione o formato desejado e clique em **Exportar**.

## Segurança e Privacidade
O software implementa criptografia simples para proteger informações sensíveis dos usuários, em conformidade com a LGPD.
