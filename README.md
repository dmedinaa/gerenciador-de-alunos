# Gerenciador Escolar em C

Este é um sistema de gerenciamento de alunos desenvolvido em **Linguagem C**. O projeto foi criado com o objetivo de aplicar conceitos fundamentais de estrutura de dados, manipulação de arquivos e validação de entrada de usuários.

## Funcionalidades

O sistema permite o gerenciamento completo do ciclo de vida de um aluno em uma instituição:

- **Cadastro de Alunos:** Adição de novos registros com atribuição automática de ID.
- **Validação de Dados:** - Nomes aceitam apenas letras e espaços (proteção contra números/símbolos).
    - Notas limitadas ao intervalo de 0.0 a 10.0.
- **Relatório Acadêmico:** Listagem de alunos com cálculo automático de status (Aprovado/Reprovado) baseado na média 6.0.
- **Edição e Remoção:** Possibilidade de alterar notas ou remover alunos do sistema.

## Tecnologias Utilizadas

- **Linguagem:** C 
- **Bibliotecas Reais:** - "stdio.h": Manipulação de entrada/saída e arquivos.
    - "string.h": Processamento de cadeias de caracteres.
    - "ctype.h": Validação de tipos de caracteres.

## Como Executar

1. Certifique-se de ter um compilador C instalado (como o GCC).
2. Clone este repositório ou baixe o arquivo ".c".
3. Abra o terminal na pasta do arquivo e compile:
   ```bash
   gcc gerenciador_escolar.c -o gerenciador
