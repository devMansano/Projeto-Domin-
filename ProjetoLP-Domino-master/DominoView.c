#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoView.h"
#include "DominoModel.h"

void imprimirPecasOrganizadas(Tipo_pecas pc) {
    for (int j = 0; j < 28; j++) {
        if (pc.pecas[j].face2 == 6) {
            printf("[%d|%d]\n", pc.pecas[j].face1, pc.pecas[j].face2);
        }
        else {
            printf("[%d|%d]", pc.pecas[j].face1, pc.pecas[j].face2);
        }
    }
}

void imprimirPecas(Tipo_pecas pc) {
    for (int i = 0; i < N; i++)
    {
        printf("[%d|%d]\n", pc.pecas[i].face1, pc.pecas[i].face2);
    }
}

int menu() {

    int op;
    do
    {
        printf("(1) Iniciar Jogo\n");
        printf("(2) Carregar Jogo\n");
        printf("(3) Continuar Jogo\n");
        printf("(4) Regras\n");
        printf("(5) Sair\n");
        printf("Selecione sua opcao: \n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 5);

    return op;
}

int menuIniciarJogo() {
    
    int op;

    do
    {
        printf("INICIAR JOGO:\n\nQuantos jogadores?\n");
        printf("1 Jogador\n2 Jogadores\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 2);

    return op;
}

void imprimirMao(Tipo_Jogadores mao, int op) {

    if (op == 1)
    {
        printf("\n\nMao Jogador 1:\n ");
        for (int i = 0; i < retornarQtdJogador1(); i++)
        {   
            if (mao.jogadores[0].pecas[i].face1 != -1)
            {
                printf("(%d) [%d|%d] ", i+1, mao.jogadores[0].pecas[i].face1, mao.jogadores[0].pecas[i].face2);
            }
           
        }
    }
    else if (op == 2)
    {
        printf("\n\nMao Jogador 2:\n ");
        for (int i = 0; i < retornarQtdJogador2(); i++)
        {
            if (mao.jogadores[1].pecas[i].face1 != -1)
            {
                printf("(%d) [%d|%d] ", i+1, mao.jogadores[1].pecas[i].face1, mao.jogadores[1].pecas[i].face2);
            }
        }
    }
    
}

void imprirPcOrganizado(Tipo_pecas pc) {
    for (int i = 0; i < 27; i++)
    {
        if (pc.pecas[i].face1 != -1)
        {
            printf("[%d|%d]\n", pc.pecas[i].face1, pc.pecas[i].face2);
        }
    }

}

int menuInGame() {
    int op;

    do{
        printf("\n(1) Distribuir Pecas\n");
        printf("(2) Mostrar Mesa\n");
        printf("(3) Mostrar Mao\n");
        printf("(4) Comprar Pecas\n");
        printf("(5) Finalizar o Jogo\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 5);

    return op;
}

int menuComprarPecas() {
    int op = 0;

    do
    {
        printf("Qual jogador ira comprar?\n(1) Jogador 1\n(2) Jogador 2\n(3)Deixar de Comprar\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 3);

    return op;
}

void desenharMesa(Tipo_Mesa pecasDesenhada) {

    for (int i = 0; i < 56; i++)
    {
        if (pecasDesenhada.mesa[i].face1 != -1)
        {
            printf("[%d|%d]", pecasDesenhada.mesa[i].face1, pecasDesenhada.mesa[i].face2);
        }
    }
    
}

int menuMesa() {
    int op;

    printf("Qual jogador ira colocar na mesa?\n");
    scanf_s("%d", &op);

    return op;
}

int pecaDescartada() {
    
    int op;

    printf("Qual peca?\n");
    scanf_s("%d", &op);

    return op;
}

int posPecaNaMesa() {
    int op;

    printf("Qual a posicao?\n(1) Antes\n(2) Depois\n");
    scanf_s("%d", &op);

    return op;
}

void imprimirErro() {
    printf("ERRO: POSICAO INVALIDA\n");
}

void mostrarRegras() {
    printf("As regras do jogo sao bem simples: cada jogador pega sete pecas e pode comprar sempre que precisar de uma peca para poder jogar e quantas vezes for necessario. Da inicio ao jogo o jogador que tirar a pedra seis-seis. Caso nenhum jogador a possua, inicia o jogo aquele que tiver a peca com os numeros repetidos mais altos, ou seja, cinco-cinco, quatro-quatro, etc. O jogo acontece no sentido anti-horario e os jogadores devem colocar pecas que tenham os mesmos numeros das pecas que se encontram na ponta do jogo. O jogador que comeca a partida leva vantagem. Este e um conceito importante para a estrategia do domino, pois o jogador que comeca, normalmente, e o que leva a vantagem durante a partida.\n\nCada jogador, no seu turno, deve colocar uma das suas pecas em uma das 2 extremidades abertas, de forma que os pontos de um dos lados coincida com os pontos da extremidade onde esta sendo colocada. As dobradas sao colocadas de maneira transversal para facilitar sua localizacao. Quando o jogador coloca sua peca sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador.\n\nSe um jogador nao puder jogar, devera comprar do monte tantas pecas  como  forem necessarias. Se nao houver pecas no monte, passara o turno ao seguinte jogador.\n\n");
}

void mostrarVencedor() {
    printf("O grande vencedor e o jogador: %d\n", vverificarVencedor());
}