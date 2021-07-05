#include "Datas.h"
#include <stdlib.h>
#include <stdio.h>
void IniciaCalendario(Data * data,int dia,int mes, int ano){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void imprime_data(Data*data){
    printf("Data %d/%d/%d\n",data->dia,(*data).mes,(*data).ano);
}
