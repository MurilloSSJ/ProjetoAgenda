#include <stdio.h>
#include <string.h>
#include "FuncoesLogin.h"
void main(){
    /*************
    * VARIAVEIS *
    *************/
    listaProfessores *listaProfessoresPTR = (listaProfessores*) malloc(sizeof(listaProfessores));
    criarListaProfessores(listaProfessoresPTR);
    Agenda *AgendaPTR = (Agenda*) malloc(sizeof(Agenda));
    int opcaoMenuPrincipal=1,opcaoMenuLogin;
    int idProfessorArquivo;
    int qnt_professores,qnt_compromissos;


    printf("Ola! Bem-vindo ao Sistema de Agendas dos Professores\n");
    while(opcaoMenuPrincipal!=0){
        printf("1-Registrar Novo Professor\n2-Login\n3-Registro Por Arquivo\n0-Encerrar Programa\n");//APRESENTA OPÇÕES DO MENU
        scanf("%d",&opcaoMenuPrincipal);
        if(opcaoMenuPrincipal==0)
            break;
        switch (opcaoMenuPrincipal)
        {
        case 1:
            RegistraProfessor(listaProfessoresPTR);
            break;
        case 2:
            AgendaPTR = UserLogin(listaProfessoresPTR);
            if(AgendaPTR!=NULL){
                printf("Ola %s, bem-vindo a sua agenda\n",AgendaPTR->nome_professor);
                opcaoMenuLogin=1;
                while(opcaoMenuLogin != 0){
                printf("1-Agendar novo compromisso\n2-Ver Compromissos agendados\n3-Determinar nova prioridade para um compromisso\n");
                printf("4-Remover um compromisso\n5-Retorna prioridade de um compromisso\n6-Retorna quantidade de compromissos\n");
                printf("7-Recuperar Agenda\n");
                printf("0-LogOut\n");
                scanf(" %d",&opcaoMenuLogin);
                if(opcaoMenuLogin==0)
                    break;
                switch (opcaoMenuLogin)
                {
                    case 1:
                        AgendarCompromisso(AgendaPTR);
                        break;
                    case 2:
                        VerCompromissos(AgendaPTR);
                        break;
                    case 3:
                        DeterminarPrioridade(AgendaPTR);
                        break;
                    case 4:
                        RemoverCompromisso(AgendaPTR);
                        break;
                    case 5:
                        RetornaPrioridade(AgendaPTR);
                        break;
                    case 6:
                        RetornarQuantidadeCompromissos(AgendaPTR);
                        break;
                    case 7:
                        RecuperarDataCompromissos(AgendaPTR);
                        break;
                    default:
                        printf("Erro! Tecla nao reconhecida\n");
                        break;
                    }
                }
            }
            else{
                printf("ID nao cadastrado, tente novamente!\n");
            }
            break;
        case 3:
            printf("Lendo Arquivo\n");
            char nomeArquivo[100];
            printf("Nome do arquivo:");
            scanf("%s", &nomeArquivo);
            FILE *arquivo = fopen(nomeArquivo,"r");
            if(arquivo != NULL){
                fscanf(arquivo,"%d",&qnt_professores);
                for(int i=1;i<=qnt_professores;i++){
                    fscanf(arquivo,"%d",&qnt_compromissos);
                    idProfessorArquivo = RegistraProfessorArquivo(listaProfessoresPTR,arquivo);
                    //PRECISA PEGAR O AGENDA PTR PARA INSERIR O COMPROMISSO
                    for(int j=1;j<=qnt_compromissos;j++){
                        AgendarCompromissoArquivo(AgendaPTR,listaProfessoresPTR,arquivo,idProfessorArquivo);
                    }
                }

            }
            break;
        default:
            printf("Tecla não reconhecida\n");
            break;
        }
    }
}
