/* Integrantes */
    //Elián Roventini Andrade
    //Gabriel Souza Recouso
    //Vinícius Luiz Ventura Ribeiro
    //Vinicius Matheus Martins

#include "aluno.h"

int main() {
    lst_ptr l; //Cria uma lista
    int op; //Cria uma variável para o loop

    dlst_init(&l); //Inicializando a lista

    abrir_arquivo_dados(l); //Abre o arquivo alunos.dat, caso exista dados, ele gera a lista a partir deles

    do {
        printf("\n\nCADASTRO DE ALUNOS\n");
        printf("<1> Cadastrar um aluno\n");
        printf("<2> Remover um aluno\n");
        printf("<3> Procurar aluno\n");
        printf("<4> Listar os alunos de um curso com forma crescente [A-Z]\n");
        printf("<5> Listar os alunos de um curso com forma decrescente [Z-A]\n");
        printf("<0> Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                cadastrar_aluno(l); //Função para cadastrar aluno na lista
                break;
            case 2:
                remover_aluno(l); //Função para remover aluno da lista
                break;
            case 3:
                procurar_aluno(l); //Função para procurar o(s) aluno(s) na lista
                break;
            case 4:
                printar_alunos(l, 0); //Printa os alunos de forma crescente de um curso específico
                break;
            case 5:
                printar_alunos(l, 1); //Printa os alunos de forma decrescente de um curso específico
                break;
            case 0:
                salvar_dados(l); //Antes de fechar o programa, salva os dados da lista para o arquivo
                break;
            default:
                printf("\nOpcao invalida!\n"); //Mensagem de erro caso o usuário selecione uma opção que não exista 
        }
    } while (op != 0); //Enquanto for diferente de 0 (sair), continua no laço
    
    return 0;
}