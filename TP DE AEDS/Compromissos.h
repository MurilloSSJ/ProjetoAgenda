#ifndef COMPROMISSOS_H_INCLUDED
#define COMPROMISSOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Datas.h"
//INICIALIZA O TAD COMPROMISSOS
typedef struct
{
    int identificador;
    Data data;
    int minutos,horas;
    int duracao;
    char descricao[100];
    int prioridade;
}Compromissos;

//ESCOPO DE FUNÇÕES
void Inicia_compromissos(Compromissos* compromissos_PTR,int identificador,int dia,int mes,int ano,int hora,int minutos,int duracao,char descricao[],int prioridade);
void new_prioridade(Compromissos * comprimissos_PTR,int nova_prioridade);
int retorna_prioridade(Compromissos * compromissos_PTR);
int tem_conflito(Compromissos *compromissos_ptr,Compromissos *compromissos_ptr2);
void mostra_compromisso(Compromissos * compromissos_ptr);
int VerificaID(Compromissos *CompromissoPTR1,int idCompromisso);

#endif // COMPROMISSOS_H_INCLUDED
