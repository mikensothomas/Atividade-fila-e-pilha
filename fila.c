#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id_cliente;
    int prioridade;
} Cliente;

void inicializarFila(Cliente **fila, int tamanho) {
    *fila = (Cliente*)malloc(tamanho* sizeof(Cliente));
}

void adicionarCliente(Cliente *fila, int *final, Cliente novo_cliente) {
    fila[*final] = novo_cliente;
    (*final)++;
}

void atenderClientes(Cliente *filaP, int *finalP, Cliente *filaNP, int *finalNP) {
    if (*finalP > 0) {
        printf("Atender cliente prioritario: %d\n", filaP[0].id_cliente);
        for (int i = 0; i < (*finalP - 1); i++) {
            filaP[i] = filaP[i + 1];
        }
        (*finalP)--;
    } else if (*finalNP > 0) {
        printf("Atender cliente não prioritario: %d\n", filaNP[0].id_cliente);
        for (int i = 0; i < (*finalNP - 1); i++) {
            filaNP[i] = filaNP[i + 1];
        }
        (*finalNP)--;
    } else {
        printf("Nenhum cliente aguardando.\n");
    }
}

void imprimirClientes(Cliente *filaP, int finalP, Cliente *filaNP, int finalNP) {
    printf("Clientes Prioritários: ");
    for (int i = 0; i < finalP; i++) {
        printf("%d ", filaP[i].id_cliente);
    }

    printf("\nClientes Não Prioritários: ");
    for (int i = 0; i < finalNP; i++) {
        printf("%d ", filaNP[i].id_cliente);
    }

    printf("\n");
}

int main() {
    Cliente *filaP, *filaNP;
    int tamanhoFila = 100;
    int finalP = 0;
    int finalNP = 0;
    int opcao, prioritario, nPrioritario;

    inicializarFila(&filaP, tamanhoFila);
    inicializarFila(&filaNP, tamanhoFila);

    do {
        printf("\nMENU:\n\n");
        printf("\t0 - Sair\n\t1 - AdicionarP\n\t2 - AdcionarNP\n\t3 - Atender\n\t4 - Imprimir\n\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Adicionar cliente prioritario: ");
            scanf("%d", &prioritario);
            Cliente novoP = {prioritario, 1};
            adicionarCliente(filaP, &finalP, novoP);
            break;
        case 2:
            printf("Adicionar cliente não prioritario: ");
            scanf("%d", &nPrioritario);
            Cliente novoNP = {nPrioritario, 0};
            adicionarCliente(filaNP, &finalNP, novoNP);
            break;
        case 3:
            printf("Atender cliente\n");
            atenderClientes(filaP, &finalP, filaNP, &finalNP);
            break;
        case 4:
            imprimirClientes(filaP, finalP, filaNP, finalNP);
            break;
        default:
            printf("Valor inválido, tente novamente\n");
        }
    } while (opcao);

    free(filaP);
    free(filaNP);

    return 0;
}
