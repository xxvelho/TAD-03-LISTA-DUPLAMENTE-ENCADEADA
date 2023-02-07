//Aluno: Elivelton Botelho Pinheiro
//Visual Studio Code
//Windows 11 Home 22H2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

typedef struct _aluno_{
    int id;
    char nome[30];
    float nota;
}Aluno;

void inserirAluno(DLList *meuCofo);
void removerAluno(DLList *meuCofo);
void pesquisarAluno(DLList *meuCofo);
int cmpId(void *a, void *b);
int cmpNome(void *a, void *b);
int cmpNota(void *a, void *b);

int main(void) {
    int aux = 0, opcao = 0, id, resultado;
    char nome[30];
    float nota;
    Aluno *temp;
    DLList *meuCofo;

    meuCofo = dllCreate();

    while(1){
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Pesquisar\n");
        printf("4 - Listar\n");
        printf("5 - Limpar\n");
        printf("6 - Destruir\n:::");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                inserirAluno(meuCofo);
                break;
            case 2:
                removerAluno(meuCofo);
                break;
            case 3:
                pesquisarAluno(meuCofo);
                break;
            case 4:
                temp = (Aluno*) dllGetFirst(meuCofo);
                if(temp != NULL){
                    while(temp != NULL){
                        printf("ID: %d NOME: %s NOTA: %.2f\n", temp->id, temp->nome, temp->nota);
                        temp = (Aluno*) dllGetNext(meuCofo);
                    }  
                }else{
                    printf("Esta colecao esta vazia.\n");
                }
                break;
            case 5:
                do{
                    temp = dllRemoveFirst(meuCofo);
                }while(temp != NULL);
              
                if(temp == NULL){
                    printf("A colecao foi limpa!\n");
                }else{
                    printf("Nao foi possivel limpar!\n");
                }
                break;
            case 6:
                resultado = dllDestroy(meuCofo);
                if (resultado){
                    printf("Colecao excluida com sucesso!\n");
                    return 0;
                }
                else{
                    printf("Primeiro limpe a Colecao antes de excluir!\n");
                }
                break;
            default:
                break;
        }
    }
}

void inserirAluno(DLList *meuCofo){
    int id;
    char nome[30];
    float nota;
    int resultado;

    printf("Insira a ID do Aluno: ");
    scanf("%d", &id);
    printf("Insira o Nome do Aluno: ");
    scanf("%s", nome);
    printf("Insira a Nota do Aluno: ");
    scanf("%f", &nota);

    Aluno *aluno = malloc(sizeof(Aluno));
    
    if(meuCofo != NULL){
        aluno->id=id;
        strcpy(aluno->nome, nome);
        aluno->nota=nota;
        resultado = dllInsertAsLast(meuCofo, aluno);
        if (resultado){
            printf("Aluno inserido com Sucesso!\n");
        }
        else{
            printf("A colecao esta cheia! Por favor, exclua para poder inserir.\n");
        }
    }
}
void removerAluno(DLList *meuCofo){
    int id;
    char nome[30];
    float nota;
    int opcao;
    void * resultado;
    while(1){
        printf("Por qual atributo voce deseja remover o Aluno?\n");
        printf("1 - Remover por ID\n");
        printf("2 - Remover por Nome\n");
        printf("3 - Remover por Nota\n");
        scanf("%d", &opcao);

    switch (opcao){
        case 1:
            printf("Insira o ID do Aluno: ");
            scanf("%d", &id);
            resultado = dllRemove(meuCofo, &id, cmpId);
            if(resultado != NULL){
                printf("Removido com Sucesso!\n");
            }
            else{
                printf("Aluno nao Removido! Tente novamente.\n");
            }
            return;
            break;
        case 2:
            printf("Insira o Nome do Aluno: ");
            scanf("%s", nome);
            
            resultado = dllRemove(meuCofo, nome, cmpNome);
            if(resultado != NULL){
                printf("Removido com Sucesso!\n");
            }
            else{
                printf("Aluno nao Removido! Tente novamente.\n");
            }
            return;
            break;
        case 3:
            printf("Insira a Nota do Aluno:");
            scanf("%f", &nota);
            resultado = dllRemove(meuCofo, &nota, cmpNota);
            if(resultado != NULL){
                printf("Removido com Sucesso!\n");
            }
            else{
                printf("Aluno nao Removido! Tente novamente.\n");
            }
            return;
            break;
        default:
            printf("Insira uma opcao valida!\n");
            break;
        
        }
    }
}
void pesquisarAluno(DLList *meuCofo){
    int id;
    char nome[30];
    float nota;
    int opcao;
    Aluno * resultado;
    while(1){
        printf("Por qual atributo voce deseja pesquisar o Aluno?\n");
        printf("1 - Pesquisar por ID\n");
        printf("2 - Pesquisar por Nome\n");
        printf("3 - Pesquisar por Nota\n");
        scanf("%d", &opcao);

    switch (opcao){
        case 1:
            printf("Insira o ID do Aluno: ");
            scanf("%d", &id);
            resultado = (Aluno *) dllQuery(meuCofo, &id, cmpId);
            if(resultado != NULL){
                printf("Aluno Encontrado com Sucesso!\n");
                printf("ID: %d\n", resultado->id);
                printf("Nome: %s\n", resultado->nome);
                printf("Nota: %.2f\n", resultado->nota);
            }
            else{
                printf("Aluno nao Encontrado! Tente novamente.\n");
            }
            return;
            break;
        case 2:
            printf("Insira o Nome do Aluno: ");
            scanf("%s", nome);
            resultado = dllQuery(meuCofo, nome, cmpNome);
            if(resultado != NULL){
                printf("Aluno Encontrado com Sucesso!\n");
                printf("ID: %d\n", resultado->id);
                printf("Nome: %s\n", resultado->nome);
                printf("Nota: %.2f\n", resultado->nota);
            }
            else{
                printf("Aluno nao Encontrado! Tente novamente.\n");
            }
            return;
            break;
        case 3:
            printf("Insira a Nota do Aluno: ");
            scanf("%f", &nota);
            resultado = dllQuery(meuCofo, &nota, cmpNota);
            if(resultado != NULL){
                printf("Aluno Encontrado com Sucesso!\n");
                printf("ID: %d\n", resultado->id);
                printf("Nome: %s\n", resultado->nome);
                printf("Nota: %.2f\n", resultado->nota);
            }
            else{
                printf("Aluno nao Encontrado! Tente novamente.\n");
            }
            return;
            break;
        default:
            printf("Insira uma opcao valida!");
            break;
        }
    }

}

int cmpId(void *a, void *b){
    Aluno *aluno= (Aluno*) a;
    int *id = (int*) b;
    
    if((int) aluno->id == (int) *id){
        return TRUE;
    }
    return FALSE;
}
int cmpNome(void *a, void *b){
    Aluno *aluno= (Aluno*) a;
    char *nome = (char*) b;
    
    if(! strcmp( aluno->nome, nome)){  //compara duas strings   abc abc 0 == false  ! false false = true
        return TRUE;
    }
    return FALSE;
}
int cmpNota(void *a, void *b){
    Aluno *aluno= (Aluno*) a;
    float *nota = (float*) b;

    if((float) aluno->nota == (float) *nota){ 
        return TRUE;
    }
    return FALSE;
}
