#define MAXFILA 30

struct TpPessoa{
    char nome[25];
    int tempoAtendimento;
};
struct TpFila{
    int inicio, fim;
    TpPessoa fila[MAXFILA];
};

void Inicializar(TpFila &F){
    F.inicio = 0;
    F.fim = -1;
}

void Inserir(TpFila &F, TpPessoa pessoa){
    F.fila[++F.fim] = pessoa;
}
TpPessoa Retirar(TpFila &F){
    return F.fila[F.inicio++];
}

TpPessoa ElementoInicio(TpFila F){
    return F.fila[F.inicio];
}
TpPessoa ElementoFinal(TpFila F){
    return F.fila[F.fim];
}

char FilaVazia(int inicio, int fim){
    return inicio > fim;
}
char FilaCheia(int inicio, int fim){
    return (inicio == 0 && fim == MAXFILA-1);
}

void MostrarFila(TpFila F){
    while(!FilaVazia(F.inicio, F.fim))
        printf("\t%c", Retirar(F));
}


//desenhos
void desenhaRecepcao(){
    int i, coluna=90, linha=6;

    textcolor(9);
    gotoxy(coluna, linha);
    printf(" _________");
    for(i = 1; i<15; i++){
        gotoxy(coluna, linha+i);
        printf("|");
    }
    gotoxy(coluna, linha+i);
    printf("|_________");
    textcolor(15);

}

void apagaPessoa(int x, int y){
    int i = x, j = y;
    gotoxy(i, j);
    printf(" ");
    gotoxy(i-1, j+1);
    printf(" ");
    gotoxy(i, j+1);
    printf(" ");
    gotoxy(i+1, j+1);
    printf(" ");
    gotoxy(i-1, j+2);
    printf(" ");
    gotoxy(i+1, j+2);
    printf(" ");
}

void apagaFuncionario(int linha, int coluna){
    for(int i=0; i<8; i++){
            gotoxy(coluna, linha+i);
            printf("                  \n");
    }
}

void desenhaDescricao(){
    textcolor(8);
    gotoxy(8, 1);
    printf("==========================================================================================================");
    gotoxy(42, 2);
    printf("SIMULACAO DE UMA FILA DE ESCRITORIO               ");
    gotoxy(8, 3);
    printf("==========================================================================================================");
    textcolor(15);
}

void desenhaFuncionario(int flag, int linha, int coluna){
    char funcionarioAnimacao[][100] = {
                                            " __________",
                                            "|          |",
                                            "| PROXIMO  |",
                                            "|          |",
                                            "| _________|",
                                            "(\\__/) ||",
                                            "(o-o ) ||",
                                            "/    \\//"
                                            };
    char funcionario[][100] = {
                                            "(\\__/) ",
                                            "(o-o )",
                                            "/    \\"
                                            };

    textcolor(14);
    if(flag == 1){
        for(int i=0; i<3; i++){
                gotoxy(coluna, linha+i);
            printf("%s\n", funcionario[i]);
        }
    }
    else{
        for(int i=0; i<8; i++){
            gotoxy(coluna, linha+i);
            printf("%s\n", funcionarioAnimacao[i]);
        }
    }
    textcolor(15);
}

void desenhaPessoaAnimacaoEntrando(int x, int y, int qtdePessoas){
    int i, j = y, parada;

    parada = qtdePessoas * 5;

    for(i = x; i < 81 - parada; i++){
        gotoxy(i, j);
        printf("o");
        gotoxy(i-1, j+1);
        printf("/");
        gotoxy(i, j+1);
        printf("|");
        gotoxy(i+1, j+1);
        printf("\\");
        gotoxy(i-1, j+2);
        if(i % 2 != 0){
            gotoxy(i, j+2);
            printf("|");
        }
        else
            printf("/");
        gotoxy(i+1, j+2);
        if(i % 2 == 0)
            printf("\\");
        else{
            gotoxy(i, j+2);
            printf("|");
        }
        Sleep(50);

        apagaPessoa(i, j);

    }
    gotoxy(i, j);
    printf("o");
    gotoxy(i-1, j+1);
    printf("/");
    gotoxy(i, j+1);
    printf("|");
    gotoxy(i+1, j+1);
    printf("\\");
    gotoxy(i-1, j+2);
    printf("/");
    gotoxy(i+1, j+2);
    printf("\\");
}

void desenhaPessoaAnimacaoSaindo(int coluna, int linha){
    int i, j = linha;
    for(i = coluna; i>3; i--){
        gotoxy(i, j);
        printf("o");
        gotoxy(i-1, j+1);
        printf("/");
        gotoxy(i, j+1);
        printf("|");
        gotoxy(i+1, j+1);
        printf("\\");
        gotoxy(i-1, j+2);
        if(i % 2 != 0){
            gotoxy(i, j+2);
            printf("|");
        }
        else
            printf("/");
        gotoxy(i+1, j+2);
        if(i % 2 == 0)
            printf("\\");
        else{
            gotoxy(i, j+2);
            printf("|");
        }
        Sleep(50);

        apagaPessoa(i, j);

    }

}

void desenhaPlacaProx(int linha, int coluna){
    int i;
    char placa [][50] = {
                        " __________________________",
                        "|                          |",
                        "|                          |",
                        "|                          |",
                        "|                          |",
                        "|                          |",
                        "|__________________________|"
                        };
    textcolor(3);
    for(i = 0; i<7; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", placa[i]);
    }
    textcolor(15);
}

void desenhaPlacaAtendFinal(int linha, int coluna){
    int i;
    char placa [][50] = {
                        " ______________________________________________",
                        "|                                              |",
                        "|                                              |",
                        "|                                              |",
                        "|                                              |",
                        "|                                              |",
                        "|______________________________________________|"
                        };
    textcolor(3);
    for(i = 0; i<7; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", placa[i]);
    }
    textcolor(15);
}

void desenhaPlacaInformacoes(int linha, int coluna){
    int i;
    char placa [][50] = {
                        " _________________________________",
                        "|                                 |",
                        "|                                 |",
                        "|                                 |",
                        "|                                 |",
                        "|                                 |",
                        "|_________________________________|"
                        };
    textcolor(3);
    for(i = 0; i<7; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", placa[i]);
    }
    textcolor(15);
}

void limpaLinha(int x, int y){
    int i;
    for(i=0; i< 25; i++){
        gotoxy(x+i, y);
        printf(" ");
    }
}
