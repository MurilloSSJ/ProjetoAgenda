#ifndef FUNCOESREGISTROAUTENTICACAO_H_INCLUDED
#define FUNCOESREGISTROAUTENTICACAO_H_INCLUDED

#include "ListaDeAgendas.h"
#include <stdio.h>
void RegistraProfessor(listaProfessores *listaProfessoresPTR);
Agenda* UserLogin(listaProfessores  *listaProfessoresPTR);
int RegistraProfessorArquivo(listaProfessores  *listaProfessoresPTR, FILE* arquivo);

#endif // FUNCOESREGISTROAUTENTICACAO_H_INCLUDED
