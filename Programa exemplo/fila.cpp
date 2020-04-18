#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<locale.h>
#include<time.h>
#include "TADfila.h"

char menu(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t      SIMULACAO FILA ESCRITORIO            \n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t\t====================================\n");

    return toupper(getch());
}

int main(){

    TpFila fila;
    TpPessoa pessoa, processo;

    char op;
    int ut, qtdePessoas = 0, contadorPessoas, somatorioTempEspera;
    float mediaTempoAtendimento;

    op = menu();
    while(op == 13){

        //desenhos fixos
        system("cls");
        desenhaDescricao();
        desenhaFuncionario(1, 12, 97);
        desenhaRecepcao();
        desenhaPlacaProx(23, 90);
        desenhaPlacaAtendFinal(23, 40);
        desenhaPlacaInformacoes(23, 3);

        //inicializacoes
        FILE *ptr = fopen("Pessoas.txt", "r"); //cria um ponteiro que ira acessar as linhas do arquivo "Pessoas"
        Inicializar(fila); //Inicializa as variaveis da fila
        ut = 1;
        processo.tempoAtendimento = 0;
        qtdePessoas = contadorPessoas = mediaTempoAtendimento = somatorioTempEspera = 0;


        while( !feof(ptr) || !FilaVazia(fila.inicio, fila.fim) ){  // enquanto não for o fim do arquivo ou a fila nao estiver vazia, ou seja só para quando as 2 condições forem falsas (fim do ponteiro e fila vazia)

            textcolor(6);
            gotoxy(7, 25);
            printf("UT -> %d", ut);
            gotoxy(7, 26);
            printf("Qtde pessoas na fila -> %d", qtdePessoas);
            gotoxy(7, 27);
            printf("Qtde pessoas no total -> %d", contadorPessoas);
            gotoxy(7, 28);
            if(contadorPessoas > 0)
                printf("Media tempo Atendim. -> %.2f", (float)somatorioTempEspera/contadorPessoas);
            textcolor(15);

            //Insercao
            if(ut % 3 == 0 && !feof(ptr)){  // alguem entra na fila de 3 em 3 ut ( a cada 3 iteracoes do laço)

                fscanf(ptr, "%[^;];%d\n", &pessoa.nome, &pessoa.tempoAtendimento);  //le a primeira linha do arquivo e grava os dados nas variaveis

                somatorioTempEspera += pessoa.tempoAtendimento;
                qtdePessoas++;
                contadorPessoas++;

                desenhaPessoaAnimacaoEntrando(3, 12, qtdePessoas);
                Inserir(fila, pessoa);  //insere a pessoa na fila

            }

            //Exclusao (pessoa sai da fila para ser atendida)
            if(processo.tempoAtendimento == 0 && !FilaVazia(fila.inicio, fila.fim)){

                processo = Retirar(fila);

                limpaLinha(92, 25);
                textcolor(2);
                gotoxy(92, 25);
                printf(" Em atendi. -> %s", processo.nome);
                gotoxy(92, 27);
                printf(" Tempo Atendimento -> %d", processo.tempoAtendimento);
                textcolor(15);
                apagaFuncionario(7, 97);
                desenhaFuncionario(1, 12, 97);
            }

            if(processo.tempoAtendimento > 0){

                processo.tempoAtendimento --;

                if(processo.tempoAtendimento == 0){
                    qtdePessoas --;
                    gotoxy(49, 26);
                    printf("                                   ");
                    gotoxy(49, 26);textcolor(4);
                    printf("Atendimento finalizado: %s\n", processo.nome);textcolor(15);
                    apagaPessoa(76, 12);
                    desenhaPessoaAnimacaoSaindo(81, 15);
                    desenhaFuncionario(0, 7, 97);Sleep(500);
                }
            }


            ut++;
            Sleep(750);
        }


        fclose(ptr); //fecha o ponteiro
        op = menu();
    }

    return 1;
}
