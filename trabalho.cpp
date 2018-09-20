#include "ep.h"

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("20");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("10723795");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("10687509");
}

// Typedef da lista
typedef struct {
    NO* inicio; // Primeiro nó da lista
} LISTA;


// Inicializar uma nova lista
void inicializar(LISTA *l) {
    l->inicio = NULL; // Primeiro nó é nulo
}

// Buscar nó na lista, por letra
NO* buscar(char letra, LISTA l) {
    NO* atual = l.inicio; // Pega o primeiro nó da lista

    while(atual) { // Executa enquanto houver nó a ser processado
        if(atual->letra == letra) { // Verifica se a letra do nó processado é a que está sendo buscada
            return(atual); // Retorna o nó encontrado
        } else { // Caso não seja,
            atual = atual->prox; // Altera o nó a ser processado para o próximo
        }
    }

    // Caso a busca não seja encontrado um nó com essa letra,
    return(NULL); // Retorna NULL
}

// Encontrar último nó da lista
NO* ultimo(LISTA *l) {
    NO* atual = l->inicio; // Pega o primeiro nó da lista

    if(atual) { // Verifica existência do nó
        while(atual->prox) { // Executa enquanto houver próximo nó
            atual = atual->prox; // Altera o nó a ser processado para o próximo
        }
    }

    // Quando não houver mais próximo nó,
    return(atual); // Retorna o último nó processado
}

// Anexar novo nó ao final da lista
void anexar(char letra, LISTA *l) {
    NO* novo; // Declara variável para armazenar o novo nó
    NO* ant; // Declara variável para armazenar o nó anterior

    ant = ultimo(l); // Pega o último nó da lista
    novo = (NO*) malloc(sizeof(NO)); // Aloca memória para o nó a ser anexado

    novo->letra = letra; // Altera a letra do novo nó para a desejada
    novo->prox = NULL; // Altera o próximo nó do novo nó para NULL

    if(ant) { // Verifica existência de um nó anterior
        ant->prox = novo; // Liga o novo nó ao novo anterior
    } else { // Caso contrário, é o primeiro nó da lista
        l->inicio = novo; // Declara o novo nó como primeiro nó da lista
    }
}

// Destruir uma lista existente
void destruir(LISTA *l) {
    NO* atual; // Declara variável para armazenar o nó sendo processado
    NO* prox; // Declara variável para armazenar o próximo nó

    atual = l->inicio; // Inicia o processamento pelo primeiro nó da lista

    while(atual) { // Executa enquanto houver nó a ser processado
        prox = atual->prox; // Altera o próximo nó a ser processado para o próximo do atual
        free(atual); // Libera memória utilizada pelo nó
        atual = prox; // Altera o nó a ser processado pelo próximo do antigo atual
    }

    l->inicio = NULL; // Reinicializa a lista
}

// Exibir os elementos de uma lista
void exibir(LISTA l) {
    NO* atual = l.inicio; // Pega o primeiro nó da lista

    while(atual) { // Executa enquanto houver nó a ser processado
        printf("%c", atual->letra); // Exibe a letra do nó
        atual = atual->prox; // Altera o nó a ser processado para o próximo
    }
}

// Exibir os elementos de uma lista - RECEBENDO UM NÓ
void percorrerLista(NO* atual) {
    while(atual) { // Executa enquanto houver nó a ser processado
        printf("%c", atual->letra); // Exibe a letra do nó
        atual = atual->prox; // Altera o nó a ser processado para o próximo
    }
}

// Inverter dois elementos
void inverterElementos(NO* no, NO* ant) {
    if(no->prox) { // Verifica se há um próximo nó
        inverterElementos(no->prox, no); // Executa a inversão de elementos recursivamente
    }

    no->prox = ant; // Inverte o próximo elemento com o elemento anterior
}

// Inverter uma lista
void inverter(LISTA* l) {
    // Executa a função de inversão de elementos, passando o inicial e seu antecessor (NULL)
    NO* temp = ultimo(l);
    inverterElementos(l->inicio, NULL);

    l->inicio = temp; // Inverte o nó inicial com o último
}


// o EP consiste em implementar esta funcao
NO* codificar(NO* frase) {

    // Declara uma variável para armazenar o nó que está sendo processado
    NO* atual = frase;

    // Cria uma nova lista para armazenar as letras vogais, e as insere na mesma
    LISTA vogais;
    inicializar(&vogais);
    anexar('A', &vogais);
    anexar('E', &vogais);
    anexar('I', &vogais);
    anexar('O', &vogais);
    anexar('U', &vogais);
    anexar('a', &vogais);
    anexar('e', &vogais);
    anexar('i', &vogais);
    anexar('o', &vogais);
    anexar('u', &vogais);

    // Cria uma lista auxiliar para armazenar sequencias de não-vogais que ainda não foram invertidas
    // e anexadas à lista de resposta
    LISTA naovogais;
    inicializar(&naovogais);

    // Cria uma lista que conterá a resposta final, já codificada
    LISTA resposta;
    inicializar(&resposta);

    // Primeira etapa de codificação
    while(atual) { // Executa enquanto houver nó a ser processado
        // Declara variável com o valor retornado pela busca da letra do nó na lista de vogais (nó ou NULL)
        NO* buscado = buscar(atual->letra, vogais);
        // Declara uma variável para armazenar o próximo elemento do buscado, caso exista
        NO* buscadoProx = NULL;

        if(atual->prox) { // Verifica se há um próximo nó
            // Insere o valor retornado pela busca da letra do próximo nó na lista de vogais (nó ou NULL)
            buscadoProx = buscar(atual->prox->letra, vogais);
        }

        if(buscado) { // Verifica se a letra do nó foi encontrada na lista de vogais (logo, é uma vogal)
            anexar(atual->letra, &resposta); // Anexa a letra na lista de resposta, sem alterações
        } else { // Caso contrário, trata-se de uma consoante
            // Anexa a letra na lista temporária de não vogais, para ser invertida futuramente
            anexar(atual->letra, &naovogais);

            // Verifica se não há mais uma próxima letra (logo, chegou ao final da lista), ou se a próxima
            // letra foi encontrada na lista de vogais (logo, terminou a sequência atual de não vogais)
            if(buscadoProx || !atual->prox) {
                inverter(&naovogais); // Inverte a lista de não vogais

                NO* naovogal = naovogais.inicio;

                while(naovogal) {
                    anexar(naovogal->letra, &resposta);
                    naovogal = naovogal->prox;
                }

                // Reinicializa a lista de não vogais, para que uma possível próxima sequência seja processada
                destruir(&naovogais);
            }
        }

        atual = atual->prox; // Altera o nó a ser processado para o próximo
    }

    // Segunda etapa de codificação
    inverter(&resposta); // Inverte a lista de resposta

    // Declara a variável a ser retornada para o usuário, contendo o nó inicial da lista de resposta
    NO* resp = resposta.inicio;
    return resp; // Retorna o nó inicial da lista de resposta

}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {

    // aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista apontada por p

	LISTA t;
    inicializar(&t);
    anexar('E', &t);
    anexar('S', &t);
    anexar('T', &t);
    anexar('R', &t);
    anexar('U', &t);
    anexar('T', &t);
    anexar('U', &t);
    anexar('R', &t);
    anexar('A', &t);
    anexar('S', &t);
    anexar(' ', &t);
    anexar('D', &t);
    anexar('E', &t);
    anexar(' ', &t);
    anexar('D', &t);
    anexar('A', &t);
    anexar('D', &t);
    anexar('O', &t);
    anexar('S', &t);
    anexar(' ', &t);
    anexar('E', &t);
    anexar(' ', &t);
    anexar('M', &t);
    anexar('U', &t);
    anexar('I', &t);
    anexar('T', &t);
    anexar('O', &t);
    anexar(' ', &t);
    anexar('L', &t);
    anexar('E', &t);
    anexar('G', &t);
    anexar('A', &t);
    anexar('L', &t);
    anexar('.', &t);

    NO* p = t.inicio;

    NO* teste = NULL;
    teste = codificar(p);
}

// por favor nao inclua nenhum código abaixo da função main()
