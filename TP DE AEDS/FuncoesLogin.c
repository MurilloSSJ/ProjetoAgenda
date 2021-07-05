#include "FuncoesLogin.h"
void AgendarCompromisso(Agenda *AgendaPTR){
    int identificador,dia,mes,anoCompromisso,minutos,horas,duracao,prioridade;
    char descricao[100];
    printf("Dia: \n");
    scanf(" %d",&dia);
    printf("Mes: \n");
    scanf(" %d",&mes);
    printf("Ano: \n");
    scanf(" %d",&anoCompromisso);
    printf("Hora do Compromisso: \n");
    scanf(" %d",&horas);
    printf("Minutos: \n");
    scanf(" %d",&minutos);
    printf("Duracao: \n");
    scanf(" %d",&duracao);
    printf("Descricao: \n");
    scanf(" %[^\n]50",&descricao);
    printf("Nivel de Prioridade: \n");
    scanf(" %d",&prioridade);
    Inserir(AgendaPTR,dia,mes,anoCompromisso,minutos,horas,duracao,descricao,prioridade);
}
void AgendarCompromissoArquivo(Agenda *AgendaPTR,listaProfessores *listaProfessoresPTR,FILE* arquivo,int idProfessor){
    int dia,mes,anoCompromisso,minutos,horas,duracao,prioridade;
    char descricao[100];
    AgendaPTR = loginProfessor(idProfessor,listaProfessoresPTR);
    fscanf(arquivo,"%d",&prioridade);
    fscanf(arquivo,"%d",&dia);
    fscanf(arquivo,"%d",&mes);
    fscanf(arquivo,"%d",&anoCompromisso);
    fscanf(arquivo,"%d",&horas);
    fscanf(arquivo,"%d",&minutos);
    fscanf(arquivo,"%d",&duracao);
    fgetc(arquivo);
    fscanf(arquivo,"%[^\n]100",descricao);
    //PEGAR O LOGIN PRECISAMOS DO AGENDA PTR
    Inserir(AgendaPTR,dia,mes,anoCompromisso,minutos,horas,duracao,descricao,prioridade);

}

void VerCompromissos(Agenda *AgendaPTR){
    imprimeLista(AgendaPTR);
}
void DeterminarPrioridade(Agenda *AgendaPTR){
    int idCompromisso,novaPrioridade;
    printf("Digite o Identificador do compromisso que vai alterar: \n");
    scanf(" %d",&idCompromisso);
    printf("Digite o Novo valor de prioridade: \n");
    scanf(" %d",&novaPrioridade);
    AlterarPrioridade(AgendaPTR,novaPrioridade,idCompromisso);
}
void RemoverCompromisso(Agenda *AgendaPTR){
    int idCompromisso;
    printf("Id do Compromisso que quer remover: \n");
    scanf(" %d",&idCompromisso);
    removerCompromisso(AgendaPTR,idCompromisso);
}
void RetornaPrioridade(Agenda *AgendaPTR){
    int idCompromisso;
    printf("Id do Compromisso que quer ver prioridade: \n");
    scanf(" %d",&idCompromisso);
    Compromissos CompromissoPTR;
    CompromissoPTR = ProcurarCompromisso(AgendaPTR,idCompromisso);
    printf("Prioridade: %d\n",CompromissoPTR.prioridade);
}
void RetornarQuantidadeCompromissos(Agenda *AgendaPTR){
    printf("Voce possui %d compromissos\n",retornaQNTCompromissos(AgendaPTR));
}
void RecuperarDataCompromissos(Agenda *AgendaPTR){
    int dia,mes,ano;
    printf("Dia: \n");
    scanf(" %d",&dia);
    printf("Mes: \n");
    scanf(" %d",&mes);
    printf("Ano: \n");
    scanf(" %d",&ano);
    recuperarAgenda(AgendaPTR,ano,mes,dia);
}
