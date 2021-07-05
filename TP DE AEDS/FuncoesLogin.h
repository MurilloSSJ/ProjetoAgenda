#ifndef FUNCOESLOGIN_H_INCLUDED
#define FUNCOESLOGIN_H_INCLUDED

#include "FuncoesRegistroAutenticacao.h"
void AgendarCompromisso(Agenda *AgendaPTR);
void VerCompromissos(Agenda *AgendaPTR);
void DeterminarPrioridade(Agenda *AgendaPTR);
void RemoverCompromisso(Agenda *AgendaPTR);
void RetornaPrioridade(Agenda *AgendaPTR);
void RetornarQuantidadeCompromissos(Agenda *AgendaPTR);
void RecuperarDataCompromissos(Agenda *AgendaPTR);
void AgendarCompromissoArquivo(Agenda *AgendaPTR,listaProfessores *listaProfessoresPTR,FILE* arquivo,int idProfessor);
#endif // FUNCOESLOGIN_H_INCLUDED
