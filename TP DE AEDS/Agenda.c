#include "Agenda.h"
#include <string.h>
void criarAgenda(Agenda *AgendaPTR,int id_professor,char nome[],int anoAgenda){
    AgendaPTR->ano = anoAgenda;
    AgendaPTR->id_professor = id_professor;
    AgendaPTR->idCompromisso = 1;
    strcpy(AgendaPTR->nome_professor,nome);
    AgendaPTR->quantidadeCompromissos=0;
    AgendaPTR->primeiro = (celulaAgenda *) malloc(sizeof(celulaAgenda));
    AgendaPTR->ultimo = AgendaPTR->primeiro;
    AgendaPTR->ultimo->proximo = NULL;
}

void Inserir(Agenda *Agenda_PTR,int dia,int mes,int anoCompromisso,int minutos,int horas,int duracao,char descricao[100],int prioridade){
    Compromissos CompromissoPTR;
    Inicia_compromissos(&CompromissoPTR,Agenda_PTR->idCompromisso,dia, mes,anoCompromisso,horas,minutos,duracao,descricao,prioridade);
    if(temConflitoAgenda(Agenda_PTR,&CompromissoPTR)==0){
        Agenda_PTR->quantidadeCompromissos++;
        Agenda_PTR->ultimo->proximo = (celulaAgenda *) malloc(sizeof(celulaAgenda));
        Agenda_PTR->ultimo = Agenda_PTR->ultimo->proximo;
        Agenda_PTR->ultimo->compromisso = CompromissoPTR;
        Agenda_PTR->ultimo->proximo = NULL;
        printf("Compromisso inserido com sucesso! Identificador: %d\n",Agenda_PTR->idCompromisso);
        Agenda_PTR->idCompromisso+=1;
    }
    else{
        printf("Nao foi possivel inserir, compromisso em conflito!\n");
    }
}
void imprimeLista(Agenda *AgendaPTR){
    if(retornaQNTCompromissos(AgendaPTR)!=0){
        celulaAgenda *compromissoAtual;
        int i;
        for(i=5;i>=0;i--){
            compromissoAtual = AgendaPTR->primeiro->proximo;
            while(compromissoAtual!=NULL){
                if(compromissoAtual->compromisso.prioridade == i){
                    mostra_compromisso(&(compromissoAtual->compromisso));
                }
                compromissoAtual = compromissoAtual->proximo;
            }
        }
    }
    else{
        printf("Lista vazia!\n");
    }
}
int retornaQNTCompromissos(Agenda *AgendaPTR){
    return AgendaPTR->quantidadeCompromissos;
}

void removerCompromisso(Agenda *AgendaPTR,int id_compromisso){
    AgendaPTR->quantidadeCompromissos--;
    celulaAgenda *aux = AgendaPTR->primeiro->proximo;
    celulaAgenda *sentinela = AgendaPTR->primeiro;
    int flag = 0;
    while(aux != NULL){
        if (VerificaID(&(aux->compromisso),id_compromisso)==1){
            printf("Removido com sucesso!\n");
            sentinela->proximo = aux->proximo;
            free(aux);
            flag = 1;
        }else{
            aux = aux->proximo;
            sentinela = sentinela->proximo;
        }
     }
     if (!flag)
        printf("Item %d nao encontrado\n",id_compromisso);
}

int recuperarAgenda(Agenda *AgendaPTR, int ano, int mes,int dia){
    printf("Nome do Professor: %s\n",AgendaPTR->nome_professor);
    printf("Ano: %d\n",AgendaPTR->ano);
    celulaAgenda *aux = AgendaPTR->primeiro->proximo;
    int contador=0;
    while(aux != NULL){
        if ((aux -> compromisso.data.ano > ano)||(aux->compromisso.data.ano == ano && aux->compromisso.data.mes > mes) || (aux->compromisso.data.ano == ano && aux->compromisso.data.mes == mes && aux->compromisso.data.dia>=dia)){
            contador+=1;
            printf("%d/%d/%d\t%s\n",aux->compromisso.data.dia,aux->compromisso.data.mes,aux->compromisso.data.ano,aux->compromisso.descricao);
            aux = aux -> proximo;

        }else{
            aux = aux -> proximo;
        }
    }
        return contador;
     printf("Numero de Compromissos: %d\n",contador);
}

Compromissos ProcurarCompromisso(Agenda *AgendaPTR,int id_compromisso){
    celulaAgenda *aux = AgendaPTR->primeiro->proximo;
    int flag =0;
    while(aux!=NULL){
        if(VerificaID(&(aux->compromisso),id_compromisso)==1){
            flag=1;
            return aux->compromisso;
            break;
        }
        else{
            aux = aux->proximo;
        }
    }
    if(!flag){
        printf("Item não achado, confira o id e tente novamente!\n");
    }
}
void AlterarPrioridade(Agenda *AgendaPTR,int nova_prioridade,int id_compromisso){
    celulaAgenda *aux = AgendaPTR->primeiro->proximo;
    int flag =0;
    while(aux!=NULL){
        if(VerificaID(&(aux->compromisso),id_compromisso)==1){
            flag=1;
             new_prioridade(&(aux->compromisso),nova_prioridade);
            break;
        }
        else{
            aux = aux->proximo;
        }
    }
    if(!flag)
        printf("Item não achado, confira o id e tente novamente!\n");
}
int verificaIdCompromisso(Agenda *AgendaPTR,int id_compromisso){
    celulaAgenda *aux = AgendaPTR->primeiro->proximo;
    int flag =0;
    while (aux!=NULL)
    {
        if (aux->compromisso.identificador == id_compromisso)
        {
            flag = 1;
            return 1;
        }
        else
        {
            aux = aux->proximo;
        }
    }
    return 0;

}
int temConflitoAgenda(Agenda *AgendaPTR,Compromissos *compromissos_ptr2){
    celulaAgenda *aux = AgendaPTR->primeiro->proximo;
    int flag =0;
    while(aux!=NULL){
        if(tem_conflito(&(aux->compromisso),compromissos_ptr2)==1){
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}
void imprimeTad(Agenda *AgendaPTR){
    printf("ID: %d\tNome: %s\tAno da Agenda:%d\n",AgendaPTR->id_professor,AgendaPTR->nome_professor,AgendaPTR->ano);
}
int verificaIDProfessor(Agenda *AgendaPTR,int id){
    if((AgendaPTR)->id_professor == id){
        return 1;
    }
    else{
        return 0;
    }
}
