#include "ListaDeAgendas.h"
void criarListaProfessores(listaProfessores *listaProfessoresPTR){
    listaProfessoresPTR->cabeca = (celulaProfessores*) malloc(sizeof(celulaProfessores));
    listaProfessoresPTR->Ultimo = listaProfessoresPTR->cabeca;
    listaProfessoresPTR->Ultimo->proximo = NULL;
}
void InserirProfessor(listaProfessores*listaProfessoresPTR,int id_professor,char nome[],int anoAgenda){
    Agenda AgendaPTR;
    criarAgenda(&AgendaPTR,id_professor,nome,anoAgenda);
    if(listaProfessoresPTR->cabeca == listaProfessoresPTR->Ultimo){
        criarListaProfessores(listaProfessoresPTR);
    }
    listaProfessoresPTR->Ultimo->proximo = (celulaProfessores*) malloc(sizeof(celulaProfessores));
    listaProfessoresPTR->Ultimo = listaProfessoresPTR->Ultimo->proximo;
    listaProfessoresPTR->Ultimo->agenda = AgendaPTR;
    listaProfessoresPTR->Ultimo->proximo = NULL;
}

void imprimeProfessores(listaProfessores *listaProfessoresPTR){
    celulaProfessores *aux = listaProfessoresPTR->cabeca->proximo;
    while( aux != NULL){
        imprimeTad(&(aux->agenda));
        aux = (*aux).proximo;
    }
}


int PesquisaID(listaProfessores *listaProfessoresPTR,int id_professor){
    if(listaProfessoresPTR->cabeca != listaProfessoresPTR->Ultimo){
        celulaProfessores *aux = listaProfessoresPTR->cabeca->proximo;
        int flag = 0;
        while(aux != NULL){
            if (verificaIDProfessor(&(aux->agenda),id_professor)){
                return 1;
            }
            else{
                aux = aux -> proximo;
            }
        }
    }
        return 0;

}


Agenda* loginProfessor(int id_professor,listaProfessores *listaProfessoresPTR){
    celulaProfessores *aux = listaProfessoresPTR->cabeca->proximo;
    int flag = 0;
    while(aux != NULL){
        if (verificaIDProfessor(&(aux->agenda),id_professor)){
            flag = 1;
            return &(aux->agenda);
        }
        else{
            aux = aux->proximo;
        }
    }
    return NULL;
}
int VerificaListaVazia(listaProfessores *listaProfessoresPTR){
    if(listaProfessoresPTR->cabeca==listaProfessoresPTR->Ultimo)
        return 1;
    else
        return 0;
}
