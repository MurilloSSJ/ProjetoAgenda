#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include <stdio.h>
#include "Compromissos.h"
typedef struct celulaAgenda
{
    Compromissos compromisso;
    struct celulaAgenda *proximo;
}celulaAgenda;

typedef struct{
    int idCompromisso;
    int id_professor;
    char nome_professor[50];
    int ano;
    unsigned int quantidadeCompromissos;
    celulaAgenda *primeiro;
    celulaAgenda *ultimo;
}Agenda;

void criarAgenda(Agenda *AgendaPTR,int id_professor,char nome[],int anoAgenda);
void Inserir(Agenda *Agenda_PTR,int dia,int mes,int anoCompromisso,int minutos,int horas,int duracao,char descricao[100],int prioridade);
void imprimeLista(Agenda *AgendaPTR);
int retornaQNTCompromissos(Agenda *AgendaPTR);
void removerCompromisso(Agenda *AgendaPTR,int id_compromisso);
int recuperarAgenda(Agenda *AgendaPTR, int ano, int mes,int dia);
int contaCompromissos(Agenda *AgendaPTR,int ano, int mes, int dia);
Compromissos ProcurarCompromisso(Agenda *AgendaPTR,int id_compromisso);
int verificaIDProfessor(Agenda *AgendaPTR,int id);
int verificaIdCompromisso(Agenda *AgendaPTR,int id_compromisso);
int temConflitoAgenda(Agenda *AgendaPTR,Compromissos *compromissos_ptr2);
void AlterarPrioridade(Agenda *AgendaPTR,int nova_prioridade,int id_compromisso);
void imprimeTad(Agenda *AgendaPTR);

#endif // AGENDA_H_INCLUDED
