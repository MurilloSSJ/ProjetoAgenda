#ifndef DATAS_H_INCLUDED
#define DATAS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
typedef struct{
    int dia,mes,ano;
}Data;

void IniciaCalendario(Data * data,int dia,int mes, int ano);
void imprime_data(Data*data);

#endif // DATAS_H_INCLUDED
