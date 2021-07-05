#ifndef LISTADEAGENDAS_H_INCLUDED
#define LISTADEAGENDAS_H_INCLUDED

#include "Agenda.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct celulaProfessores{
    Agenda agenda;
    struct celulaProfessores *proximo;
}celulaProfessores;

typedef struct{
    celulaProfessores *cabeca;
    celulaProfessores *Ultimo;
}listaProfessores;

void criarListaProfessores(listaProfessores *listaProfessoresPTR);
void InserirProfessor(listaProfessores*listaProfessoresPTR,int id_professor,char nome[],int anoAgenda);
void imprimeProfessores(listaProfessores *listaProfessoresPTR);
void removerProfessor(listaProfessores *listaProfessoresPTR,int id_professor);
int PesquisaID(listaProfessores *listaProfessoresPTR,int id_professor);
Agenda* loginProfessor(int id_professor,listaProfessores *listaProfessoresPTR);
int VerificaListaVazia(listaProfessores *listaProfessoresPTR);

#endif // LISTADEAGENDAS_H_INCLUDED
