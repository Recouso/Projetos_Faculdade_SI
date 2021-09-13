/* Integrantes */
    //Elián Roventini Andrade
    //Gabriel Souza Recouso
    //Vinícius Luiz Ventura Ribeiro
    //Vinicius Matheus Martins

#ifndef _ALUNO_H
#define _ALUNO_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NOME_ARQ "alunos.dat"

typedef enum {
    CIENCIA_DA_COMPUTACAO,
    SISTEMAS_DE_INFORMACAO } tcurso;
typedef struct {
    int mat; // matrícula do aluno
    char nome[61]; // nome do aluno
    tcurso curso; // nome do curso
    int idade; // idade do aluno
} taluno;

typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_ptr ant;
    taluno dado;
    lst_ptr prox;
};

/* Objetivo das funções */
    /* a) Incluir um novo aluno: o programa deve solicitar o número de matrícula, o nome,
    curso e a idade do aluno e incluir na lista. O programa não deve permitir o cadastro de
    dois ou mais alunos com o mesmo número de matrícula; */

    /* b) Remover um aluno: o programa deve solicitar o número de matrícula do aluno, caso
    exista um aluno com a matrícula informada, exibir seus dados, e pedir uma
    confirmação da exclusão. Caso a matrícula não seja encontrada, o programa deve
    exibir uma mensagem de erro; */

    /* c) Procurar um aluno: o programa deve solicitar o nome do aluno e listar todos os alunos
    cujo nome comece com o nome informado pelo usuário; */

    /* d) Listar os alunos de um curso em ordem alfabética crescente: o programa deve solicitar
    o curso e listar, no formato de uma tabela, todos os alunos deste curso em ordem
    alfabética crescente; */

    /* e) Listar os alunos de um curso em ordem alfabética decrescente: o programa deve
    solicitar o curso e listar, no formato de uma tabela, todos os alunos deste curso em
    ordem alfabética decrescente. */

/* Funções iniciais e  Funções para auxiliar as funções de manipulação de lista */
    /* Função para cadastrar um aluno */
    void cadastrar_aluno(lst_ptr);

    /* Função para remover um aluno da lista */
    void remover_aluno(lst_ptr);

    /* Função para procurar um aluno na lista */
    void procurar_aluno(lst_ptr);

    /* Função para printar os alunos */
    void printar_alunos(lst_ptr, int);

    /* Função para printar os alunos */
    void printar_alunos(lst_ptr, int);

/* Funções para a manipulação de lista */
    /* Função que inicializa a lista */
    void dlst_init(lst_ptr *);

    /* Função que insere um novo nó na lista ordenada */
    void dlst_ins(lst_ptr, taluno);

    /* Função que remove um nó da lista ordenada */
    bool dlst_rem(lst_ptr, taluno);

    /* Função que imprime a lista em ordem ascendente */
    void dlst_print_asc(lst_ptr, int);

    /* Função que imprime a lista em ordem descendente */
    void dlst_print_desc(lst_ptr, int);

    /* Função que verifica se a lista está vazia */
    bool dlst_isempty(lst_ptr);

/* Funções para auxílio do algoritmo */
    /* Função para verificar se a matrícula do aluno existe */
    bool matricula_existente(lst_ptr, taluno);

    /* Pega os dados do aluno */
    taluno get_aluno(lst_ptr, taluno);

    /* Função para verificar se existe algum aluno com o curso em específico */
    bool verificar_aluno_curso(lst_ptr, int);

/* Funções para manipulação do arquivo */
    /* Função para salvar os dados no arquivo */
    void salvar_dados(lst_ptr);

    /* Função para abrir o arquivo e pegar os dados armazenados */
    void abrir_arquivo_dados(lst_ptr l);

#endif