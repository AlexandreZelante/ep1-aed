#include "ep.h"

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("00");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("0000000");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("0000000");
}



typedef struct {
    NO* inicio;
} LISTA;

void inicializarLista(LISTA *l) {
    l->inicio = NULL;
}

NO* buscaSeqOrd(char ltr, LISTA l) {
    NO* p = l.inicio;

    while(p) {
        if(p->letra == ltr) {
            return(p);
        }

        p = p->prox;
    }

    return(NULL);
}

NO* ultimoElemLista(LISTA l) {
    NO* p = l.inicio;

    if(p) {
        while(p->prox) {
            p = p->prox;
        }
    }

    return(p);
}

// Anexar novo elemento ao final da lista, duplicado ou não
void anexarElemLista(char ltr, LISTA *l) {
    NO* novo;
    NO* ant;

    ant = ultimoElemLista(*l);
    novo = (NO *) malloc(sizeof(NO));

    novo->letra = ltr;
    novo->prox = NULL;

    if(!ant) {
        l->inicio = novo;
    } else {
        ant->prox = novo;
    }
}

void destruirLista (LISTA *l) {
    NO* atual;
    NO* prox;
    atual = l->inicio;
    while (atual) {
        prox = atual->prox; // guarda próxima posição
        free(atual); // libera memória apontada por atual
        atual = prox;
    }
    l->inicio = NULL; // ajusta início da lista (vazia)
}

void exibirLista(LISTA l) {
    NO* p = l.inicio;

    while (p) {
        printf("%c ",p->letra);
        p = p->prox;
    }
}

void inverterLista(LISTA *l) {
    NO* p = l->inicio;

    while (p->prox != NULL) {
        p = p->prox;
    }
}

void inverteElementos (NO* e, NO* ant){
    if(e->prox!=NULL) {
        inverteElementos(e->prox, e);
    }
    e->prox = ant;
}

void inverter (LISTA* p){

    NO* ultimo = p->inicio;

    while(ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }


    inverteElementos(p->inicio, NULL);

    //Inverte inicio com fim
    NO* aux = p->inicio;
    p->inicio = ultimo;
}


// o EP consiste em implementar esta funcao
NO* codificar(NO* frase) {
    LISTA vogais;
    inicializarLista(&vogais);
    anexarElemLista('A', &vogais);
    anexarElemLista('E', &vogais);
    anexarElemLista('I', &vogais);
    anexarElemLista('O', &vogais);
    anexarElemLista('U', &vogais);

    LISTA naovogais;
    inicializarLista(&naovogais);

    LISTA resposta;
    inicializarLista(&resposta);

    bool processando = false;

    NO* resp = resposta.inicio; // já veio

    while(frase) {
        printf("Processando %c\n", frase->letra);

        NO* buscado = buscaSeqOrd(frase->letra, vogais);
        NO* buscadoProx = NULL;

        if(frase->prox) {
            NO* buscadoProx = buscaSeqOrd(frase->prox->letra, vogais);
        }

        if(buscado) {
            printf("vogal\n");
            anexarElemLista(frase->letra, &resposta);
        } else {
            printf("nao vogal\n");

            if(!processando) {
                processando = true;
            }

            anexarElemLista(frase->letra, &naovogais);

            if(!frase->prox || buscadoProx) {
                inverter(&naovogais);
                // inverter array temporária
                // anexar array temporaria na final
                // zerar array temporaria
                processando = false;
            }
        }

        frase = frase->prox;
    }

    // rotina de codificacao passo 1
    // sua rotina de codificacao aqui (o exemplo cria apenas um elemento X)
    resp = (NO*) malloc(sizeof(NO));
    resp->letra = 'X';
    resp->prox = NULL;

    // passo 2 de codificação (inverter lista resposta)

    return resp; // já veio

}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------


int main() {

	NO* p = NULL;
    char i = 'I';



    LISTA l;
    inicializarLista(&l);
    anexarElemLista('I', &l);
    anexarElemLista('G', &l);
    anexarElemLista('O', &l);
    anexarElemLista('R', &l);
    //exibirLista(l);

    LISTA t;
    inicializarLista(&t);
    anexarElemLista('E', &t);
    anexarElemLista('S', &t);
    anexarElemLista('T', &t);
    anexarElemLista('R', &t);
    anexarElemLista('U', &t);
    anexarElemLista('T', &t);
    anexarElemLista('U', &t);
    anexarElemLista('R', &t);
    anexarElemLista('A', &t);
    anexarElemLista('S', &t);
    exibirLista(t);
    inverter(&t);
    exibirLista(t);

	// aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista apontada por p

	// o EP sera testado com chamadas deste tipo
	NO* teste = NULL;
	//teste = codificar(l.inicio);

	// e aqui precisaria percorrer a lista teste para ver se ficou correta etc.

}

// por favor nao inclua nenhum c�digo abaixo da fun��o main()
