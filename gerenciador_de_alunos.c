#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 100

typedef struct {
    char nome[50];
    float nota;
    int ativo;
} Aluno;

int nome_valido(char nome[]) {
    if (strlen(nome) == 0) return 0; 
   for (size_t i = 0; i < strlen(nome); i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    Aluno escola[MAX_ALUNOS];   
    int opcao, i, id;

    
    for (i = 0; i < MAX_ALUNOS; i++) { //liberando memoria
        escola[i].ativo = 0;
        escola[i].nota = 0.0;
    }

    do {
        printf("\n    GERENCIADOR ESCOLAR    \n");
        printf("1. Ver situacao academica\n");
        printf("2. Adicionar/Alterar nota\n");
        printf("4. Adicionar aluno\n");
        printf("5. Remover aluno\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            opcao = -1; 
        }

        switch (opcao) {
            case 1:
                printf("\n    LISTA DE ALUNOS    \n");
                for (i = 0; i < MAX_ALUNOS; i++) {
                    if (escola[i].ativo == 1) {
                        printf("ID: %d | Nome: %-15s | Nota: %.1f | Status: %s\n",
                               i, escola[i].nome, escola[i].nota,
                               (escola[i].nota >= 6.0 ? "Aprovado" : "Reprovado"));
                    }
                }
                break;

            case 2:
                printf("digite o ID do aluno (0-99): ");
                scanf("%d", &id);
                if (id >= 0 && id < MAX_ALUNOS && escola[id].ativo == 1) {
                    float temp_nota;
                    printf("digite a nota para %s: ", escola[id].nome);
                    if (scanf("%f", &temp_nota) == 1 && temp_nota >= 0 && temp_nota <= 10) {
                        escola[id].nota = temp_nota;
                        printf("nota atualizada!\n");
                    } else {
                        printf("nota invalida! Digite apenas numeros de 0,0 a 10.0 \n");
                        while (getchar() != '\n');
                    }
                } else {
                    printf("ID invalido ou aluno inexistente.\n");
                }
                break;

            case 4:
                for (i = 0; i < MAX_ALUNOS; i++) {
                    if (!escola[i].ativo) {
                        int valido = 0;
                        while (!valido) {
                            printf("nome do aluno (apenas letras): ");
                            scanf(" %[^\n]s", escola[i].nome);

                            if (nome_valido(escola[i].nome)) {
                                valido = 1;
                            } else {
                                printf("use apenas letras e espaços!\n");
                            }
                        }
                        escola[i].nota = 0.0;
                        escola[i].ativo = 1;
                        printf("aluno cadastrado com sucesso no ID %d!\n", i);
                        break;
                    }
                }
                break;

            case 5:
                printf("ID do aluno para remover: ");
                scanf("%d", &id);
                if (id >= 0 && id < MAX_ALUNOS && escola[id].ativo == 1) {
                    escola[id].ativo = 0;
                    printf("aluno removido com sucesso.\n");
                } else {
                    printf("aluno nao encontrado.\n");
                }
                break;

            case 0:
                printf("sistema encerrado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}