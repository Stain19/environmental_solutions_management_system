# Relatório de Desenvolvimento

## Objetivo Geral
Desenvolver um sistema desktop em Linguagem C para gerenciar todas as tarefas de cadastro e relatórios de uma startup de soluções ambientais, seguindo as melhores práticas de engenharia de software e as diretrizes estabelecidas no documento de solicitação.

## Objetivos Específicos
- **Aplicação de Conhecimentos**: Implementação de algoritmos e estruturas de dados adquiridos nas disciplinas de Linguagem e Técnicas de Programação e Engenharia de Software I, utilizando princípios de modularidade e reutilização de código.
- **Trabalho em Equipe**: Colaboração entre os membros através de metodologias ágeis, facilitando a integração de funcionalidades e a comunicação eficaz dentro do time.
- **Identificação de Necessidades**: Análise detalhada dos requisitos funcionais e não funcionais para propor soluções técnicas eficazes, utilizando técnicas de elicitação de requisitos.
- **Pesquisa e Metodologias**: Utilização de metodologias ágeis, como Scrum, para o desenvolvimento iterativo e incremental do sistema, garantindo flexibilidade e adaptabilidade às mudanças.
- **Desenvolvimento de Algoritmos**: Criação de fluxogramas e algoritmos eficientes para as funcionalidades do sistema, aplicando princípios de design orientado a objetos quando aplicável.
- **Ferramentas Computacionais**: Utilização de ferramentas como GitHub para versionamento de código, facilitando o controle de versões e a colaboração, e Mermaid para criação de diagramas de arquitetura e fluxo.
- **Fase de Testes**: Implementação de testes unitários e de integração para assegurar a qualidade e funcionalidade do sistema, utilizando frameworks de teste adequados.
- **Normas ABNT**: Aplicação das normas da ABNT na documentação e estrutura do projeto, garantindo a padronização e a conformidade com os requisitos acadêmicos.

## Contextualização do Caso
A startup de soluções ambientais necessita de um sistema eficiente para cadastrar, mapear e gerenciar indústrias que precisam tratar resíduos ambientais. O sistema desenvolvido permite o cadastro detalhado das indústrias, atualização mensal das quantidades de resíduos tratados e geração de relatórios personalizados e globais. Esta solução atende às exigências de benefícios fiscais e mapeamento governamental, alinhando-se com as práticas de compliance e sustentabilidade ambiental. A arquitetura do sistema segue padrões de design modular, facilitando futuras expansões e manutenções.

## Atividades Desenvolvidas
- **Tela de Login**: Implementação da autenticação dos usuários no sistema (`tela-menu-insumos.c`), utilizando técnicas de segurança para proteção de dados sensíveis.
- **Menu Principal**: Criação de menus interativos para acesso às diferentes funcionalidades, como gerenciamento de indústrias e insumos, aplicando princípios de usabilidade e design centrado no usuário.
- **Gerenciamento de Indústrias**: Funcionalidades de adicionar, listar, atualizar e deletar indústrias no banco de dados (`repositorio_industrias.c`), utilizando padrões de repositório para separação de responsabilidades.
- **Gestão de Insumos**: Implementação de cadastro e listagem de insumos tratados por CNPJ (`repositorio_insumos.c`), aplicando validações de dados e integridade referencial.
- **Geração de Relatórios**: Desenvolvimento de relatórios financeiros e de produção, com opção de exportação em formatos TXT, XLS ou CSV (`tela-menu-relatorios.c`), utilizando bibliotecas para manipulação de arquivos e visualização de dados.
- **Criptografia de Dados**: Implementação de criptografia simples para informações sensíveis dos usuários, em conformidade com a LGPD, garantindo a segurança e privacidade dos dados.
- **Documentação**: Criação de documentação técnica utilizando LaTeX, seguindo as normas ABNT (`main.tex`), assegurando clareza e detalhamento das funcionalidades e arquitetura do sistema.
- **Diagramas de Caso de Uso**: Elaboração de diagramas para representar as interações do sistema (`diagrama-caso-de-uso.md`), facilitando o entendimento das funcionalidades para stakeholders e desenvolvedores.

## Relacionamento com as Disciplinas
- **Linguagem e Técnicas de Programação**: Desenvolvimento do algoritmo e lógica de programação utilizada nas funcionalidades do sistema, aplicando conceitos de estruturas de dados e algoritmos eficientes.
- **Engenharia de Software I**: Aplicação de metodologias de desenvolvimento de software, incluindo versionamento, testes, documentação e padrões de design, promovendo a qualidade e a manutenção do sistema.