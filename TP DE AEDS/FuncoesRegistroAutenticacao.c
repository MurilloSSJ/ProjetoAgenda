#include "FuncoesRegistroAutenticacao.h"
#include <stdio.h>
#include <string.h>
void RegistraProfessor(listaProfessores  *listaProfessoresPTR){
    int idProfessor,anoAgenda;
    char nomeProfessor[50];
        printf("Digite o ID do professor: \n");
        scanf(" %d",&idProfessor);
        if(PesquisaID(listaProfessoresPTR,idProfessor)==1)
            printf("Ja cadastrado, faca login\n");
        else{
            printf("Nome do professor: \n");
            scanf(" %[^\n]50",&nomeProfessor);
            printf("Ano da agenda: \n");
            scanf(" %d",&anoAgenda);
            InserirProfessor(listaProfessoresPTR,idProfessor,nomeProfessor,anoAgenda);
            printf("Registro bem sucedido!\n");
            }
}
Agenda* UserLogin(listaProfessores  *listaProfessoresPTR){
    int idProfessor;
    printf("Digite o ID do professor: \n");
    scanf("%d",&idProfessor);
    return loginProfessor(idProfessor,listaProfessoresPTR);


}
int RegistraProfessorArquivo(listaProfessores  *listaProfessoresPTR, FILE* arquivo){
    int idProfessor,anoAgenda;
    char nomeProfessor[50];
        fscanf(arquivo, "%d",&idProfessor);
        fgetc(arquivo); // serve para resolver problema de fim de linha da leitura do int acima
        fscanf(arquivo,"%[^\n]50",nomeProfessor);
        fscanf(arquivo,"%d",&anoAgenda);
        InserirProfessor(listaProfessoresPTR,idProfessor,nomeProfessor,anoAgenda);
        printf("Registro bem sucedido!\n");
        return idProfessor;
}
