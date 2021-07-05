#include "Compromissos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/***********************
 * INICIA COMPROMISSOS *
 ***********************/
void Inicia_compromissos(Compromissos* compromissos_PTR,int identificador,int dia,int mes,int ano,int hora,int minutos,int duracao,char descricao[],int prioridade){
    Data data;
    IniciaCalendario(&data,dia,mes,ano);
    (*compromissos_PTR).identificador = identificador;
    (*compromissos_PTR).data = data;
    (*compromissos_PTR).horas = hora;
    (*compromissos_PTR).minutos = minutos;
    (*compromissos_PTR).duracao = duracao;
    strcpy((*compromissos_PTR).descricao,descricao);
    (*compromissos_PTR).prioridade = prioridade;
}

/**************************************
 * DEFINE UM NOVO VALOR DE PRIORIDADE *
 **************************************/
void new_prioridade(Compromissos * comprimissos_PTR,int nova_prioridade){
    (*comprimissos_PTR).prioridade = nova_prioridade;

}

/*******************************
 * RETORNA VALOR DE PRIORIDADE *
 *******************************/
int retorna_prioridade(Compromissos * compromissos_PTR){
    return((*compromissos_PTR).prioridade);
}

/****************************************
 * INFORMA CONFLITOS ENTRE COMPROMISSOS *
 ****************************************/
int tem_conflito(Compromissos *compromissos_ptr,Compromissos *compromissos_ptr2){
    int retorno=0,i,j;
    if((*compromissos_ptr).data.ano != (*compromissos_ptr2).data.ano || (*compromissos_ptr).data.mes != (*compromissos_ptr2).data.mes || (*compromissos_ptr).data.dia != (*compromissos_ptr2).data.dia){
        return 0;
    }
    else{
        int hora_inicial_cmp1 = (*compromissos_ptr).horas , minuto_inicial_cmp1 = (*compromissos_ptr).minutos;
        int hora_inicial_cmp2 = (*compromissos_ptr2).horas , minuto_inicial_cmp2 = (*compromissos_ptr2).minutos;
        //Compromisso já inserido na agenda
        int inicial1 = hora_inicial_cmp1*60 + minuto_inicial_cmp1;
        int final1 = inicial1 + compromissos_ptr2->duracao;

        //Compromisso que quero inserir na agenda
        int inicial2 = hora_inicial_cmp2*60 + minuto_inicial_cmp2;
        int final2 = inicial2 + compromissos_ptr2->duracao;

        //Se o compromisso começar no mesmo horario
        if (inicial1==inicial2)
            return 1;
        if (inicial1<inicial2){
            if ((final2>inicial1) && (inicial2<final1))
                return 1;
        }

        if (inicial1>inicial2){
            if (final2>inicial1)
                return 1;
        }
    }
    return 0;
}

/***********************
 * IMPRIME COMPROMISSO *
 ***********************/
void mostra_compromisso(Compromissos * compromissos_ptr){
    printf("Identificador: %d\n",(*compromissos_ptr).identificador);
    printf("Nivel de prioridade: %d\n",(*compromissos_ptr).prioridade);
    //CHAMA A FUNÇÃO IMPRIME DATA, DEFINIDA EM Datas.c
    imprime_data(&(*compromissos_ptr).data);
    printf("Horario: %d:%d\n",(*compromissos_ptr).horas,(*compromissos_ptr).minutos);
    printf("Duracao: %d minutos\n",(*compromissos_ptr).duracao);
    printf("Descricao: %s\n",(*compromissos_ptr).descricao);
    printf("\n");
}

int VerificaID(Compromissos *CompromissoPTR1,int idCompromisso){
    if(CompromissoPTR1->identificador==idCompromisso)
        return 1;
    else
        return 0;
}
