/* Integrantes */
    //Elián Roventini Andrade
    //Gabriel Souza Recouso
    //Vinícius Luiz Ventura Ribeiro
    //Vinicius Matheus Martins

#include "aluno.h"

/* Funções iniciais e 
    Funções para auxiliar as funções de manipulação de lista */
void cadastrar_aluno(lst_ptr l) { //Função para cadastrar um aluno
    
    taluno aluno; //Cria uma variável da struct tipo aluno
    
    bool matriculaRepetida = false; //Cria uma variável para auxiliar ao saber se a matrícula é repetida
    printf("\n\nNovo Aluno:\n");
    do {
        printf("Matricula: ");
        scanf("%d", &aluno.mat); //Armazena o valor digitado na variável para matrícula da struct aluno
        if (matriculaRepetida = matricula_existente(l, aluno)) { //Utiliza a função de verificar se a matrícula já existe, e aproveita para atribuir na variável 
            printf("Matricula ja' existente! Insira uma matricula diferente\n");
        }
    }while (matriculaRepetida); //Enquanto a matrícula for repetida, continua o laço
    
    printf("Nome: ");
    scanf(" %60[^\n]", aluno.nome); //Armazena o valor digitado na variável para nome da struct aluno, já transformando em maísculo
    printf("Curso: ");
    scanf("%d", &aluno.curso); //Armazena o valor digitado na variável para curso da struct aluno
    printf("Idade: ");
    scanf("%d", &aluno.idade); //Armazena o valor digitado na variável para idade da struct aluno

    dlst_ins(l, aluno); //Insere os dados na lista
}

void remover_aluno(lst_ptr l) { //Função para remover um aluno da lista
    taluno aluno; //Cria a struct aluno
    printf("Digite a matricula do aluno a ser removido: ");
    scanf("%d", &aluno.mat); //Armazena o valor digitado na variável para matrícula da struct aluno

    if (matricula_existente(l, aluno)) { //Verifica se a matrícula já existe. Caso exista, entra no if
        int resposta; //Variável para saber se o usuário tem certeza que deseja excluir o aluno
        aluno = get_aluno(l, aluno); //Pega os dados do aluno através da matrícula e devolve os dados, armazenando na struct aluno
        /*------------------------------------------------------*/
        // Mostra os dados do aluno na tela
        printf("\n\n\tDados do Aluno\n");
        printf("-----------------------------------------\n");
        printf("Matricula Nome                Curso Idade\n");
        printf("-----------------------------------------\n");
        printf("%09d %-20.20s %4d %4d\n", aluno.mat, aluno.nome, aluno.curso, aluno.idade); //Os dados em específico são mostrados por essa linha
        printf("-----------------------------------------\n\n");
        /*------------------------------------------------------*/

        /*------------------------------------------------------*/
        // Confirmação de exclusão do aluno
        printf("Tem certeza que deseja excluir esse aluno?\n");
        printf("<1> Para Sim\n");
        printf("<2> Para Nao\n");
        scanf("%d", &resposta); //Pega o valor digitado
        if (resposta == 1) { //Se ele realmente deseja excluir, entra no if
            if (dlst_rem(l, aluno)) //Remove o aluno da lista, caso consiga, retorna uma mensagem de sucesso
                printf("Aluno removido com sucesso!\n");
            else //Caso contrário, retorna uma mensagem de erro
                printf("Erro: Falha ao remover aluno.\n");
        }
        /*------------------------------------------------------*/
    }else { //Caso contrário, retorna uma mensagem de erro
        printf("Erro: Impossivel exclusao, matricula inexistente.\n");
    }
}

void procurar_aluno(lst_ptr l) { //Função para procurar um aluno na lista
    taluno aluno; //Cria a struct do tipo aluno
    printf("Digite o nome do aluno que deseja procurar: ");
    scanf(" %60[^\n]", aluno.nome); //Armazena o valor digitado na variável para nome da struct aluno
    strupr(aluno.nome); //strupr Utilizado para deixar os nomes em letra maisculas, para não ocorrer problemas de letra maísculas e minúsculas
    lst_ptr p = l->prox; //Cria uma lista auxiliar, armazenando o próximo nó no atual dessa nova lista
    bool flag = true; //Inicia a flag como verdadeiro
    int count = 0; //Utilizado para verificar se algum nome foi encontrado
    while (p != l) { //Enquanto não chegar no fim da lista
        char nome[61]; //Cria uma variável para armazenar o nome, para não ocorrer alteração do nome na lista
        strcpy(nome, p->dado.nome); //Copia o nome do aluno que está no nó atual
        strupr(nome);
        if (strcmp((strtok(nome, " ")), aluno.nome) == 0) {
            //strcmp Utilizado para verificar se o nome digitado e o primeiro nome do aluno do nó atual são iguais
            //strtok Utilizado para separar os nomes do aluno (caso seja composto) utilizando o delimitador espaço
            //Não causa problemas caso só tenha um nome armazenado do nó
            if(flag) { //Se a flag for verdadeira, printa o início da mensagem , para uma visibilidade melhor dos nomes
                printf("\n\nAluno(s) encontrado(s) com o mesmo nome\n");
                printf("-----------------------------------------\n");
                flag = false; //Faz com que a flag fique falsa novamente, para não entrar de novo neste if
            }
            printf("%s\n", p->dado.nome); //Printa o nome encontrado no nó que seja igual ao nome digitado
            count++;
        }
        p = p->prox; //Vai para o próximo nó da lista
    }
    if (count == 0) { //Se igual a zero, nenhum aluno inicia com o nome digitado
        printf("-----------------------------------------\n");
        printf("Nenhum aluno que comece com esse nome foi encontrado\n");
    }
    printf("-----------------------------------------\n"); //Printado para uma melhor visibilidade dos nomes, para indicar o final

}

void printar_alunos(lst_ptr l, int tipo) { //Função para printar os alunos
    if (!dlst_isempty(l)) { //Caso a lista NÃO esteja vazia, entra no if
        printf("\nDigite o curso:\n");
        printf("<0> Ciencia da Computacao\n");
        printf("<1> Sistemas de Informacao\n");
        int curso;
        scanf("%d", &curso); //Armazena o curso selecionado

        //variável tipo recebida como parâmetro da função para saber se é crescente {0} ou decrescente {1}
        if (tipo == 0) //Printa de forma crescente
            dlst_print_asc(l, curso);
        else if(tipo == 1) //Printa de forma decrescente
            dlst_print_desc(l, curso);
    }else { //Caso a lista esteja vazia, printa uma mensagem que não existem alunos na lista
        printf("Nao existem alunos cadastrados ainda!\n");
    }
}

/* Funções para a manipulação de lista */

void dlst_init(lst_ptr * l) { //Função que inicializa a lista
    if((*l = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) { //Verifica se existe como alocar memória, caso não seja possível, retorna mensagem de erro
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    (*l)->prox = (*l)->ant = *l; //Inicializa com a lista apontando tanto o próximo quanto o anterior para o mesmo nó, conhecido como nó cabeça
}

void dlst_ins(lst_ptr l, taluno aluno) { //Função para inserir um aluno na lista (inserir um nó na lista)
    lst_ptr n, p; //Cria duas novas listas, para auxilio da manipulação
    if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) { //Verifica se existe como alocar memória, caso não seja possível, retorna mensagem de erro
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    strupr(aluno.nome);
    n->dado = aluno; //Atribue a struct aluno (com seus dados) no valor de dado da lista
    p = l; //Faz com que a lista nova "p" aponte para o mesmo endereço que a lista "l" aponta

    
    while (p->prox != l && (strcmp(aluno.nome, p->prox->dado.nome) > 0)) { 
        //Enquanto o próximo nó não é o último da lista, continua
            //Além disso, verifica também se o nome do aluno da struct aluno é maior que o nome do aluno do nó atual (Para já deixar ordenado de forma alfabética de A-Z)
        p = p->prox; //Vai para o próximo nó da lista, atribuindo ao atual
    }
    n->prox = p->prox; //Atribue o endereço do próximo nó de "p" para a "variável" da lista "n"
    n->ant = p; //Atribue para a "variável" da lista "n" o nó atual (endereço)
    p->prox->ant = n; //Atribue o endereço de "n" para a "variável" anterior do próximo nó de "p"
    p->prox = n; //Atribue para a "variável" próximo de "p" o endereço do nó "n"
}

bool dlst_rem(lst_ptr l, taluno aluno) { //Função para excluir um aluno da lista (remover um nó da lista)
    lst_ptr p = l->prox; //Cria uma lista "p", atribuindo o próximo nó da lista "l" (ou seja, o primeiro nó "real", pois o primeiro é o nó cabeça)
    while (p != l && aluno.mat != p->dado.mat) {
        //Enquanto o próximo nó não é o último da lista, continua
            //E se a matrícula do aluno for diferente da matrícula do aluno do nó atual, continua no while
        p = p->prox; //Vai para o próximo nó da lista
    }
    if (p != l && aluno.mat == p->dado.mat) { //Se o nó não for o último E a matrícula da struct aluno for igual a matrícula do nó atual da lista, entra no if
        p->prox->ant = p->ant; //Atribue o endereço da "variável" anterior do nó de "p" para a "variável" anterior do nó próximo
        p->ant->prox = p->prox; //Atribue o endereço da "variável" próximo do nó de "p" para a "variável" próximo do nó anterior
        free(p); //Livra o nó atual
        return true; //Retorna verdadeiro, pois foi possível remover da lista
    }
    return false; //Retorna falso, pois não foi possível remover da lista
}

void dlst_print_asc(lst_ptr l, int curso) { //Função para printar de forma crescente os alunos
    if (verificar_aluno_curso(l, curso)) { //Verifica se existe algum aluno com esse curso selecionado
        lst_ptr p = l->prox; //Cria uma lista "p" atribuindo o próximo nó da lista
        /*------------------------------------------------------*/
        // Mostra os dados do(s) aluno(s) do curso em específico na tela
        printf("\n\n\tAlunos Cadastrados\n");
        printf("-----------------------------------------\n");
        printf("Matricula Nome                Curso Idade\n");
        printf("-----------------------------------------\n");
        while (p != l) { //Enquanto não for o último nó
            if (p->dado.curso == curso) { //Se o curso do aluno atual for igual ao curso escolhido, printa os dados do aluno
                printf("%09d %-20.20s %4d %4d\n", p->dado.mat, p->dado.nome, p->dado.curso, p->dado.idade);
            }
            p = p->prox; //Vai para o próximo da lista
        }
        printf("-----------------------------------------\n");
        /*------------------------------------------------------*/
    }else { //Exibe uma mensagem falando que não existem alunos com o curso selecionado
        printf("Nao existem alunos do curso selecionado\n");
    }
}

void dlst_print_desc(lst_ptr l, int curso) {
    if (verificar_aluno_curso(l, curso)) { //Verifica se existe algum aluno com esse curso selecionado
        lst_ptr p = l->ant; //Cria uma lista "p" atribuindo o nó anterior do nó cabeça, consequentemente o último da lista
        /*------------------------------------------------------*/
        // Mostra os dados do(s) aluno(s) do curso em específico na tela
        printf("\n\n\tAlunos Cadastrados\n");
        printf("-----------------------------------------\n");
        printf("Matricula Nome                Curso Idade\n");
        printf("-----------------------------------------\n");
        while (p != l) { //Enquanto não for o primeiro nó
            if (p->dado.curso == curso) { //Se o curso do aluno atual for igual ao curso escolhido, printa os dados do aluno
                printf("%09d %-20.20s %4d %4d\n", p->dado.mat, p->dado.nome, p->dado.curso, p->dado.idade);
            }
            p = p->ant; //Vai para o anterior da lista
        }
        printf("-----------------------------------------\n");
        /*------------------------------------------------------*/
    }else { //Exibe uma mensagem falando que não existem alunos com o curso selecionado
        printf("Nao existem alunos do curso selecionado\n");
    }
}

bool dlst_isempty(lst_ptr l) { //Função para saber se a lista está vazia
    return (l->prox == l && l->ant == l); //Verifica se a "variável" próximo e anterior apontam para o nó atual (no caso, seria o nó cabeça), e retorna True ou False 
}

/* Funções para auxílio do algoritmo */

bool matricula_existente(lst_ptr l, taluno aluno) { //Função para verificar se a matrícula do aluno existe
    lst_ptr p = l->prox; //Cria uma lista "p" com o nó apontando para o próximo nó de "l"
    while (p != l) { //Enquanto não for o último nó (nó cabeça), continua
        if (p->dado.mat == aluno.mat) { //Se a matrícula do nó atual for igual a matrícula do aluno, retorna Verdadeiro
            return true;
        }
        p = p->prox; //Vai para o próximo da lista
    }
    return false; //Se não encontrar a matrícula na lista, retorna Falso
}

taluno get_aluno(lst_ptr l, taluno aluno) { //Pega os dados do aluno
    lst_ptr p = l->prox; //Cria uma lista "p" com o nó apontando para o próximo nó de "l"
    while (p != l) { //Enquanto não for o último nó (nó cabeça), continua
        if (p->dado.mat == aluno.mat) { //Se a matrícula do nó atual for igual a matrícula do aluno, entra no if
            return p->dado; //Retorna a struct do dado (aluno) atual
        }
        p = p->prox; //Vai para o próximo da lista
    }
}

bool verificar_aluno_curso(lst_ptr l, int curso) { //Função para verificar se existe algum aluno com o curso em específico
    lst_ptr p = l->prox; //Cria uma lista "p" com o nó apontando para o próximo nó de "l"
    while (p != l) { //Enquanto não for o último nó (nó cabeça), continua
        if (p->dado.curso == curso) { //Se o curso do nó atual for igual ao curso passado por parâmetro, entra no if
            return true; //Retorna verdadeiro, pois existe ao menos um aluno com esse curso
        }
        p = p->prox; //Vai para o próximo da lista
    }
    return false; //Retorna falso, pois não existe nenhum aluno com esse curso
}

/* Funções para manipulação do arquivo */

void salvar_dados(lst_ptr l) { //Função para salvar os dados no arquivo
    FILE * arq; //Cria uma variável de tipo arquivo
    if ((arq = fopen(NOME_ARQ, "w+b")) == NULL) { //Tenta abrir o arquivo de forma "w+b", caso não consiga, entra no if
        printf("\nErro nao foi possivel abrir o arquivo %s!\n", NOME_ARQ); //Exibe uma mensagem de erro
        return; //Retorna nada para continuar o programa
    }

    lst_ptr p = l->prox; //Cria uma lista "p" com o nó apontando para o próximo nó de "l"
    while (p != l) { //Enquanto não for o último nó (nó cabeça), continua
        fwrite(&p->dado, sizeof(taluno), 1, arq); //Escreve no arquivo cada struct de aluno existente na lista, passado para o arquivo em binário
        p = p->prox; //Vai para o próximo da lista
    }
    
    fclose(arq); //Fecha o arquivo
}

void abrir_arquivo_dados(lst_ptr l) { //Função para abrir o arquivo e pegar os dados armazenados
    FILE * arq; //Cria uma variável de tipo arquivo
    taluno aluno; //Cria uma variável de tipo aluno
    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) { //Tenta abrir o arquivo de forma "rb", se não conseguir, entra no if
        return; //Retorna nada para continuar o programa
    }

    while (fread(&aluno, sizeof(taluno), 1, arq) > 0) { //Tenta ler os dados armazenados um por um do arquivo binário. Caso consiga, entra no if
        dlst_ins(l, aluno); //Chama a função para inserir os dados da strcut aluno na lista
    }
    fclose(arq); //Fecha o arquivo
}