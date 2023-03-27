#include <stdio.h>

#define TAMANHO 3
#define CADASTRO_FEITO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_SUCESSO -6

typedef struct aluno {
  int matricula;
  char nome;
  char sexo;
  int datanasc;
  int ativo;
  int cpf;
} Aluno;

typedef struct prof {
  int matricula;
  char nome;
  char sexo;
  int datanasc;
  int ativo;
  int cpf;
} Prof;

typedef struct disc {
  int codigo;
  char nome;
  char semestre;
  int professor;
  int alunos[TAMANHO];
  int ativo;
} Disc;


//funções
int menuPrincipal();
int menuAluno();
int menuProf();
int menuDisc();

int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);
void listarAlunopsex(Aluno listaAluno[], int qtdAluno);

int cadastrarProf(Prof listaProf[], int qtdProf);
void listarProf(Prof listaProf[], int qtdProf);
int atualizarProf(Prof listaProf[], int qtdProf);
int excluirProf(Prof listaProf[], int qtdProf);
void listarProfpsex(Prof listaProf[], int qtdProf);

int cadastrarDisc(Disc listaDisc[], int qtdDisc);
void listarDisc(Disc listaDisc[], int qtdDisc);
int atualizarDisc(Disc listaDisc[], int qtdDisc);
int excluirDisc(Disc listaDisc[], int qtdDisc);

;

int main(void){

  Aluno listaAluno[TAMANHO];
  Prof listaProf[TAMANHO];
  Disc listaDisc[TAMANHO];
  int opcao;
  int qtdAluno = 0;
  int qtdProf = 0;
  int qtdDisc = 0;
  int qtdAludisc = 0;
  int sairPrincipal = 0;

  while (!sairPrincipal) {

    opcao = menuPrincipal();

    switch (opcao) {
      case 0: {
        sairPrincipal = 1;
        break;
      }
      case 1: {
        printf("Opções para alunos:\n");
        int sairAluno = 0;
        int opcaoAluno;
        while (!sairAluno) {
          opcaoAluno = menuAluno();
          switch (opcaoAluno) {
            case 0: {
              sairAluno = 1;
              break;
            }
            case 1: {
              int retorno = cadastrarAluno(listaAluno, qtdAluno);
    
              if (retorno == LISTA_CHEIA)
                printf("Lista de alunos cheia\n");
              else if (retorno == MATRICULA_INVALIDA)
                printf("Matrícula Inválida\n");
              else {
                printf("Cadastrado com sucesso\n");
                qtdAluno++;
              }
    
              break;
            }
            case 2: {
              listarAluno(listaAluno, qtdAluno);
              break;
            }
            case 3: {
              int retorno = atualizarAluno(listaAluno, qtdAluno);
              switch (retorno) {
                case MATRICULA_INVALIDA: {
                  printf("Matrícula Inválida\n");
                  break;
                }
                case MATRICULA_INEXISTENTE: {
                  printf("Matrícula inexistente\n");
                  break;
                }
                case ATUALIZACAO_SUCESSO: {
                  printf("Aluno atualizado com sucesso\n");
                  break;
                }
              }
              break;
            }
            case 4: {
              int retorno = excluirAluno(listaAluno, qtdAluno);
              switch (retorno) {
                case MATRICULA_INVALIDA: {
                  printf("Matrícula Inválida\n");
                  break;
                }
                case MATRICULA_INEXISTENTE: {
                  printf("Matrícula inexistente\n");
                  break;
                }
                case EXCLUSAO_SUCESSO: {
                  printf("Aluno excluido com sucesso\n");
                  qtdAluno--;
                  break;
                }
              }
              break;
            }
            case 5: {
              listarAlunopsex(listaAluno,qtdAluno);
              break;
            }
            default: {
              printf("Opção Inválida\n");
            }
          }
        }
        break;
      }
      case 2: {
        printf("Opções para Professores\n");
        int sairProf = 0;
        int opcaoProf;
        while (!sairProf) {
          opcaoProf = menuProf();
          switch (opcaoProf) {
            case 0: {
              sairProf = 1;
              break;
            }
            case 1: {
              int retorno = cadastrarProf(listaProf, qtdProf);
    
              if (retorno == LISTA_CHEIA)
                printf("Lista de Professores cheia\n");
              else if (retorno == MATRICULA_INVALIDA)
                printf("Matrícula Inválida\n");
              else {
                printf("Cadastrado com sucesso\n");
                qtdProf++;
              }
    
              break;
            }
            case 2: {
              listarProf(listaProf, qtdProf);
              break;
            }
            case 3: {
              int retorno = atualizarProf(listaProf, qtdProf);
              switch (retorno) {
                case MATRICULA_INVALIDA: {
                  printf("Matrícula Inválida\n");
                  break;
                }
                case MATRICULA_INEXISTENTE: {
                  printf("Matrícula inexistente\n");
                  break;
                }
                case ATUALIZACAO_SUCESSO: {
                  printf("Professor atualizado com sucesso\n");
                  break;
                }
              }
              break;
            }
            case 4: {
              int retorno = excluirProf(listaProf, qtdProf);
              switch (retorno) {
                case MATRICULA_INVALIDA: {
                  printf("Matrícula Inválida\n");
                  break;
                }
                case MATRICULA_INEXISTENTE: {
                  printf("Matrícula inexistente\n");
                  break;
                }
                case EXCLUSAO_SUCESSO: {
                  printf("Professor excluido com sucesso\n");
                  qtdProf--;
                  break;
                }
              }
              break;
            }
            case 5: {
              listarProfpsex(listaProf,qtdProf);
              break;
            }
            default: {
              printf("Opção Inválida\n");
            }
          }
        }
        break;
      }
      
      case 3: {
        printf("Opções Disciplina\n");
        int sairDisc = 0;
        int opcaoDisc;
        while (!sairDisc) {
          opcaoDisc = menuDisc();
          switch (opcaoDisc) {
            case 0: {
              sairDisc = 1;
              break;
            }
            case 1: {
              int retorno = cadastrarDisc(listaDisc, qtdDisc);
    
              if (retorno == LISTA_CHEIA)
                printf("Lista de discplinas cheia\n");
              else if (retorno == MATRICULA_INVALIDA)
                printf("Codigo Inválido\n");
              else {
                printf("Cadastrada com sucesso\n");
                qtdDisc++;
              }
              break;
            }

            case 2: {
              listarDisc(listaDisc, qtdDisc);
              break;
            }
            case 3: {
              int retorno = atualizarDisc(listaDisc, qtdDisc);
              switch (retorno) {
                case MATRICULA_INVALIDA: {
                  printf("Codigo Inválido\n");
                  break;
                }
                case MATRICULA_INEXISTENTE: {
                  printf("Codigo inexistente\n");
                  break;
                }
                case ATUALIZACAO_SUCESSO: {
                  printf("Disciplina atualizada com sucesso\n");
                  break;
                }
              }
              break;
            }
            case 4: {
              int retorno = excluirDisc(listaDisc, qtdDisc);
              switch (retorno) {
                case MATRICULA_INVALIDA: {
                  printf("Codigo Inválida\n");
                  break;
                }
                case MATRICULA_INEXISTENTE: {
                  printf("Codigo inexistente\n");
                  break;
                }
                case EXCLUSAO_SUCESSO: {
                  printf("Disciplina excluida com sucesso\n");
                  qtdProf--;
                  break;
                }
              }
              break;
            }
            default: {
              printf("Opção Inválida\n");
            }
          }
        }
        break;
      }
            
      default: {
        printf("Opção Inválida\n");
      }
    }
  }

  return 0;
}

// funções

int menuPrincipal(){
  int opcao;
  printf("Bem vindo ao Projeto Escola! Escolha uma opção:\n");
  printf("0 - Sair\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");

  scanf("%d", &opcao);

  return opcao;
}

int menuAluno(){
  int opcao;
  printf("0 - Voltar\n");
  printf("1 - Casdatrar Aluno\n");
  printf("2 - Listar todos os alunos\n");
  printf("3 - Atualizar Aluno\n");
  printf("4 - Excluir Aluno\n");
  printf("5 - Listar alunos por sexo\n");

  scanf("%d", &opcao);

  return opcao;
}

int cadastrarAluno(Aluno listaAluno[], int qtdAluno){
  printf("Casdatrar Aluno\n");
  if (qtdAluno >= TAMANHO) {
    return LISTA_CHEIA;
  } else {
    printf("Digite a matricula:\n");
    int matricula;
    scanf("%d", &matricula);
    printf("Digite o nome:\n");
    char nome;
    scanf("%s", &nome);
    printf("Digite o sexo (m ou f):\n");
    char sexo;
    scanf("%s", &sexo);
    printf("Digite a data de nascimento: (ddmmaa):\n");
    int datanasc;
    scanf("%d", &datanasc);
    printf("Digite o CPF:\n");
    int cpf;
    scanf("%d", &cpf);
    if (matricula < 0) {
      return MATRICULA_INVALIDA;
    }
    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].nome = nome;
    listaAluno[qtdAluno].sexo = sexo;
    listaAluno[qtdAluno].datanasc = datanasc;
    listaAluno[qtdAluno].cpf = cpf;
    listaAluno[qtdAluno].ativo = 1;
    return CADASTRO_FEITO;
  }
}

void listarAluno(Aluno listaAluno[], int qtdAluno){
  printf("Listar Aluno\n");
  if (qtdAluno == 0) {
    printf("Lista aluno vazia\n");
  } else {
     printf("Quantidade de alunos: %d\n", qtdAluno);
     printf("Lista de alunos:\n");
    for (int i = 0; i < qtdAluno; i++) {
      if (listaAluno[i].ativo == 1)
        printf("Nome: %c\n", listaAluno[i].nome);
        printf("Matrícula: %d\n", listaAluno[i].matricula);
    }
  }
}

int atualizarAluno(Aluno listaAluno[], int qtdAluno){

  printf("Atualizar Aluno\n");
  printf("Digite a matricula:\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdAluno; i++) {
      if (matricula == listaAluno[i].matricula && listaAluno[i].ativo) {
        printf("Digite a nova matricula\n");
        int novamatricula;
        scanf("%d", &novamatricula);
        if (novamatricula < 0) {
          return MATRICULA_INVALIDA;
        }
        listaAluno[i].matricula = novamatricula;
        achou = 1;
        break;
      }
    }
    if (achou)
      return ATUALIZACAO_SUCESSO;

    else
      return MATRICULA_INEXISTENTE;
  }
}

int excluirAluno(Aluno listaAluno[], int qtdAluno){
  printf("Excluir Aluno\n");
  printf("Digite a matricula:\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdAluno; i++) {
      if (matricula == listaAluno[i].matricula) {
        listaAluno[i].ativo = -1;
        for (int j = i; j < qtdAluno - 1; j++) {
          listaAluno[j].matricula = listaAluno[j + 1].matricula;
          listaAluno[j].nome = listaAluno[j + 1].nome;
          listaAluno[j].sexo = listaAluno[j + 1].sexo;
          listaAluno[j].datanasc = listaAluno[j + 1].datanasc;
          listaAluno[j].cpf = listaAluno[j + 1].cpf;
          listaAluno[j].ativo = listaAluno[j + 1].ativo;
        }
        achou = 1;
        break;
      }
    }
    if (achou)
      return EXCLUSAO_SUCESSO;
    else
      return MATRICULA_INEXISTENTE;
  }
}

void listarAlunopsex(Aluno listaAluno[], int qtdAluno){
  printf("Listar alunos por sexo\n");
    if (qtdAluno == 0) {
      printf("Lista de alunos vazia\n");
      } 
    else {
      printf("Digite o sexo dos alunos, m ou f:");
      char opcaosex;
      scanf("%s", &opcaosex);
      if (opcaosex == 'm') {
       for (int i = 0; i < qtdAluno; i++) { 
        if (listaAluno[i].sexo == 'm'){
          printf("Aluno do sexo masculino: %c", listaAluno[i].nome); 
          }
        }
      }
      else if (opcaosex == 'f') {
        for (int i = 0; i < qtdAluno; i++) { 
          if (listaAluno[i].sexo == 'f'){
          printf("Aluna do sexo feminino: %c", listaAluno[i].nome);
        }
      }  
    } 
    else {
          printf("Opção inválida");
    }
  }
}

int menuProf() {
  int opcao;
  printf("0 - Voltar\n");
  printf("1 - Casdatrar Professor\n");
  printf("2 - Listar Professor\n");
  printf("3 - Atualizar Professor\n");
  printf("4 - Excluir Professor\n");
  printf("5 - Listar professores por sexo\n");

  scanf("%d", &opcao);

  return opcao;
}

int cadastrarProf(Prof listaProf[], int qtdProf) {
  printf("Casdatrar Professor\n");
  if (qtdProf == TAMANHO) {
    return LISTA_CHEIA;
  } else {
    printf("Digite a matricula:\n");
    int matricula;
    scanf("%d", &matricula);
    printf("Digite o nome:\n");
    char nome;
    scanf("%s", &nome);
    printf("Digite o sexo (m ou f):\n");
    char sexo;
    scanf("%s", &sexo);
    printf("Digite a data de nascimento (ddmmaa):\n");
    int datanasc;
    scanf("%d", &datanasc);
    printf("Digite o CPF:\n");
    int cpf;
    scanf("%d", &cpf);
    if (matricula < 0) {
      return MATRICULA_INVALIDA;
    }
    listaProf[qtdProf].matricula = matricula;
    listaProf[qtdProf].nome = nome;
    listaProf[qtdProf].sexo = sexo;
    listaProf[qtdProf].datanasc = datanasc;
    listaProf[qtdProf].cpf = cpf;
    listaProf[qtdProf].ativo = 1;
    return CADASTRO_FEITO;
  }
}

void listarProf(Prof listaProf[], int qtdProf) {
  printf("Listar Professor\n");
  if (qtdProf == 0) {
    printf("Lista de Professores vazia\n");
  } else {
     printf("Quantidade de Professores: %d\n", qtdProf);
     printf("Lista de Professores:\n");
    for (int i = 0; i < qtdProf; i++) {
      if (listaProf[i].ativo == 1)
        printf("Nome: %c\n", listaProf[i].nome);
        printf("Matrícula: %d\n", listaProf[i].matricula);
    }
  }
}

int atualizarProf(Prof listaProf[], int qtdProf){

  printf("Atualizar Professor\n");
  printf("Digite a matricula:\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdProf; i++) {
      if (matricula == listaProf[i].matricula && listaProf[i].ativo) {
        printf("Digite a nova matricula\n");
        int novamatricula;
        scanf("%d", &novamatricula);
        if (novamatricula < 0) {
          return MATRICULA_INVALIDA;
        }
        listaProf[i].matricula = novamatricula;
        achou = 1;
        break;
      }
    }
    if (achou)
      return ATUALIZACAO_SUCESSO;

    else
      return MATRICULA_INEXISTENTE;
  }
}

int excluirProf(Prof listaProf[], int qtdProf){
  printf("Excluir Professor\n");
  printf("Digite a matricula:\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdProf; i++) {
      if (matricula == listaProf[i].matricula) {
        listaProf[i].ativo = -1;
        for (int j = i; j < qtdProf - 1; j++) {
          listaProf[j].matricula = listaProf[j + 1].matricula;
          listaProf[j].nome = listaProf[j + 1].nome;
          listaProf[j].sexo = listaProf[j + 1].sexo;
          listaProf[j].datanasc = listaProf[j + 1].datanasc;
          listaProf[j].cpf = listaProf[j + 1].cpf;
          listaProf[j].ativo = listaProf[j + 1].ativo;
        }
        achou = 1;
        break;
      }
    }
    if (achou)
      return EXCLUSAO_SUCESSO;
    else
      return MATRICULA_INEXISTENTE;
  }
}

void listarProfpsex(Prof listaProf[], int qtdProf){
  printf("Listar professores por sexo\n");
    if (qtdProf == 0) {
      printf("Lista de professores vazia\n");
      } 
    else {
      printf("Digite o sexo dos professores, m ou f:");
      char opcaosex;
      scanf("%s", &opcaosex);
      if (opcaosex == 'm') {
       for (int i = 0; i < qtdProf; i++) { 
        if (listaProf[i].sexo == 'm'){
          printf("Professor do sexo masculino: %c", listaProf[i].nome); 
          }
        }
      }
      else if (opcaosex == 'f') {
        for (int i = 0; i < qtdProf; i++) { 
          if (listaProf[i].sexo == 'f'){
          printf("Professora do sexo feminino: %c", listaProf[i].nome);
        }
      }  
    } 
    else {
          printf("Opção inválida");
    }
  }
}

int menuDisc(){
  int opcao;
  printf("0 - Voltar\n");
  printf("1 - Casdatrar Disciplina\n");
  printf("2 - Listar Disciplina\n");
  printf("3 - Atualizar Disciplina\n");
  printf("4 - Excluir Disciplina\n");

  scanf("%d", &opcao);

  return opcao;
}

int cadastrarDisc(Disc listaDisc[], int qtdDisc) {
  printf("Cadastrar Disciplina\n");
  if (qtdDisc >= TAMANHO) {
    return LISTA_CHEIA;
  } else {
    printf("Digite o codigo da discplina:\n");
    int codigo;
    scanf("%d", &codigo);
    printf("Digite o nome da discplina:\n");
    char nome;
    scanf("%s", &nome);
    printf("Digite o semestre:\n");
    char semestre;
    scanf("%s", &semestre);
    printf("Digite a matricula do professor:\n");
    int professor;
    scanf("%d", &professor);
    if (codigo < 0) {
      return MATRICULA_INVALIDA;
    }
    listaDisc[qtdDisc].codigo = codigo;
    listaDisc[qtdDisc].nome = nome;
    listaDisc[qtdDisc].semestre = semestre;
    listaDisc[qtdDisc].professor = professor;
    return CADASTRO_FEITO;
  }
}

void listarDisc(Disc listaDisc[], int qtdDisc) {
  printf("Listar Disciplinas\n");
  if (qtdDisc == 0) {
    printf("Lista de Disciplinas vazia\n");
  } else {
     printf("Quantidade de Disciplinas: %d\n", qtdDisc);
     printf("Lista de Disciplinas:\n");
    for (int i = 0; i < qtdDisc; i++) {
      if (listaDisc[i].ativo == 1)
        printf("Nome: %c\n", listaDisc[i].nome);
        printf("Codigo: %d\n", listaDisc[i].codigo);
    }
  }
}

int atualizarDisc(Disc listaDisc[], int qtdDisc){

  printf("Atualizar Disciplina\n");
  printf("Digite o codigo:\n");
  int codigo;
  scanf("%d", &codigo);
  int achou = 0;
  if (codigo < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdDisc; i++) {
      if (codigo == listaDisc[i].codigo && listaDisc[i].ativo) {
        printf("Digite a nova matricula\n");
        int novocodigo;
        scanf("%d", &novocodigo);
        if (novocodigo < 0) {
          return MATRICULA_INVALIDA;
        }
        listaDisc[i].codigo = novocodigo;
        achou = 1;
        break;
      }
    }
    if (achou)
      return ATUALIZACAO_SUCESSO;

    else
      return MATRICULA_INEXISTENTE;
  }
}

int excluirDisc(Disc listaDisc[], int qtdDisc){
  printf("Excluir Disciplina\n");
  printf("Digite o codigo:\n");
  int codigo;
  scanf("%d", &codigo);
  int achou = 0;
  if (codigo < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdDisc; i++) {
      if (codigo == listaDisc[i].codigo) {
        listaDisc[i].ativo = -1;
        for (int j = i; j < qtdDisc - 1; j++) {
          listaDisc[j].codigo = listaDisc[j + 1].codigo;
          listaDisc[j].nome = listaDisc[j + 1].nome;
          listaDisc[j].semestre = listaDisc[j + 1].semestre;
          listaDisc[j].professor = listaDisc[j + 1].professor;
          listaDisc[j].ativo = listaDisc[j + 1].ativo;
        }
        achou = 1;
        break;
      }
    }
    if (achou)
      return EXCLUSAO_SUCESSO;
    else
      return MATRICULA_INEXISTENTE;
  }
}