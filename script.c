#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DESCRICAO 100
#define MAX_MARCA 50
#define MAX_SITE 100
#define MAX_TELEFONE 15
#define MAX_UF 3
#define MAX_PRODUTOS 100

typedef struct
{
    char descricao[MAX_DESCRICAO];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    char marca[MAX_MARCA];
    char site[MAX_SITE];
    char telefone[MAX_TELEFONE];
    char uf[MAX_UF];
} Produto;

/* Função que lista as marcas */
void listaMarcas(Produto produtos[], int numProdutos)
{
    if (numProdutos == 0)
    {
        printf("\t\033[31m*NENHUM PRODUTO REGISTRADO*\033[0m\n");
        sleep(3);
        system("cls");
    }
    else
    {
        printf("\n\033[94m------ MARCAS DISPONÍVEIS: ------\033[0m\n\n");
        for (int i = 0; i < numProdutos; i++)
        {
            printf("- %s\n", produtos[i].marca);
            sleep(2);
            system("cls");
        }
        printf("\n");
    }
}

/* Função que lista os produtos */
void listaProdutos(Produto produtos[], int numProdutos)
{
    if (numProdutos == 0)
    {
        printf("\n\t\033[31m*NENHUM PRODUTO REGISTRADO*\033[0m\n");
        sleep(3);
        system("cls");
    }
    else
    {
        printf("\n\033[94m------ Produtos disponíveis: ------\033[0m\n\n");
        for (int i = 0; i < numProdutos; i++)
        {
            printf("\n\033[93mProduto %d:\033[0m\n", i + 1);
            printf("\033[93mDescrição:\033[0m %s\n", produtos[i].descricao);
            printf("\033[93mPeso (em gramas):\033[0m %.2f\n", produtos[i].peso);
            printf("\033[93mValor de compra:\033[0m %.2f\n", produtos[i].valorCompra);
            printf("\033[93mValor de venda:\033[0m %.2f\n", produtos[i].valorVenda);
            printf("\033[93mValor do lucro:\033[0m %.2f\n", produtos[i].valorLucro);
            printf("\033[93mPercentual do lucro:\033[0m %.2f%%\n", produtos[i].percentualLucro);
            printf("\033[93mMarca:\033[0m %s\n", produtos[i].marca);
            printf("\033[93mSite:\033[0m %s\n", produtos[i].site);
            printf("\033[93mTelefone:\033[0m %s\n", produtos[i].telefone);
            printf("\033[93mUF:\033[0m %s\n\n", produtos[i].uf);
        }
        if (numProdutos > 1)
        {
            sleep(5);
            system("cls");
        }
        else
        {
            sleep(3);
            system("cls");
        }
    }
}

/* Função que lista os produtos por estado */
void listaProdutosEstado(Produto produtos[], int numProdutos, char estado[])
{
    printf("\n\033[94m------ PRODUTOS REGISTRADOS NO ESTADO %s: ------\033[0m\n\n", estado);
    int produtosEncontrados = 0;
    for (int i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].uf, estado) == 0)
        {
            printf("- %s\n", produtos[i].descricao);
            produtosEncontrados = 1;
            sleep(2);
            system("cls");
        }
    }
    if (!produtosEncontrados)
    {
        printf("\n\t\033[31m*NENHUM PRODUTO REGISTRADO DESSE ESTADO*\033[0m\n");
        sleep(2);
        system("cls");
    }
    printf("\n");
}

/* Função que lista os produtos de uma determinada marca */
void listaProdutosMarca(Produto produtos[], int numProdutos, char marca[])
{
    printf("\n\033[94m------ PRODUTOS DA MARCA %s: ------\033[0m\n\n", marca);
    int produtosEncontrados = 0;
    for (int i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].marca, marca) == 0)
        {
            printf("- %s\n", produtos[i].descricao);
            produtosEncontrados = 1;
            sleep(2);
            system("cls");
        }
    }
    if (!produtosEncontrados)
    {
        printf("\t\033[31m*NENHUM PRODUTO REGISTRADO DESSA MARCA*\033[0m\n");
        sleep(2);
        system("cls");
    }
    printf("\n");
}

/* Função que mostra o estado do produto mais caro na lista */
void estadoProdutoMaisCaro(Produto produtos[], int numProdutos)
{
    float maxValor = 0.0;
    printf("\033[94m------ ESTADO(S) COM PRODUTO MAIS CARO: ------\033[0m\n\n");
    int estadosEncontrados = 0;
    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda > maxValor)
        {
            maxValor = produtos[i].valorVenda;
        }
    }
    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda == maxValor)
        {
            printf("- %s\n", produtos[i].uf);
            estadosEncontrados = 1;
            sleep(2);
            system("cls");
        }
    }
    if (!estadosEncontrados)
    {
        printf("\n\t\033[31m*NENHUM PRODUTO REGISTRADO*\033[0m\n");
        sleep(2);
        system("cls");
    }
    printf("\n");
}

/* Função mostra o fabricante do produto mais barato na lista */
void fabricanteProdutoMaisBarato(Produto produtos[], int numProdutos)
{
    float minValor = produtos[0].valorVenda;
    printf("\033[94m------ FABRICANTE(S) COM PRODUTO MAIS BARATO: ------\033[0m\n\n");
    int fabricantesEncontrados = 0;
    for (int i = 1; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda < minValor)
        {
            minValor = produtos[i].valorVenda;
        }
    }
    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda == minValor)
        {
            printf("- %s\n", produtos[i].marca);
            fabricantesEncontrados = 1;
            sleep(2);
            system("cls");
        }
    }
    if (!fabricantesEncontrados)
    {
        printf("\n\t\033[31m*NENHUM PRODUTO REGISTRADO*\033[0m\n");
        sleep(2);
        system("cls");
    }
    printf("\n");
}

/* Função que compara os valores para ordenar em ordem crescente dos valores */
int comparaValor(const void *a, const void *b)
{
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;
    return (produtoA->valorVenda - produtoB->valorVenda);
}

/* Função que lista os produtos em ordem crescente de valor */
void listaProdutosOrdemCrescenteValor(Produto produtos[], int numProdutos)
{
    printf("\033[94m------ PRODUTOS EM ORDEM CRESCENTE DE VALOR: ------\033[0m\n\n");
    qsort(produtos, numProdutos, sizeof(Produto), comparaValor);
    if (numProdutos == 0)
    {
        printf("\n\t\033[31m*NENHUM PRODUTO REGISTRADO*\033[0m\n");
        sleep(2);
        system("cls");
    }
    for (int i = 0; i < numProdutos; i++)
    {
        printf("- %s: %.2f\n", produtos[i].descricao, produtos[i].valorVenda);
        sleep(2);
        system("cls");
    }
    printf("\n");
}

/* Função de comparação para ordenação em ordem crescente de lucro */
int comparaLucro(const void *a, const void *b)
{
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;
    return (produtoA->valorLucro - produtoB->valorLucro);
}

/* Função que lista os produtos em ordem crescente de lucro */
void listaProdutosOrdemCrescenteLucro(Produto produtos[], int numProdutos)
{
    printf("\033[94m------ PRODUTOS EM ORDEM CRESCENTE DE LUCRO: ------\033[0m\n\n");
    qsort(produtos, numProdutos, sizeof(Produto), comparaLucro);
    if (numProdutos == 0)
    {
        printf("\n\t\033[31m*NENHUM PRODUTO REGISTRADO*\033[0m\n");
        sleep(2);
        system("cls");
    }

    for (int i = 0; i < numProdutos; i++)
    {
        printf("- %s: %.2f\n", produtos[i].descricao, produtos[i].valorLucro);
        sleep(2);
        system("cls");
    }
    printf("\n");
}

/* Função que descarta entradas indesejadas para não conflitar os scanfs */
void limpa_linha()
{
    scanf("%*[^\n]"); /* Lê todos os caracteres "indesejados" e descarta os mesmos, exceto o '\n' */
    scanf("%*c");     /* Lê o caractere '\n' e descarta o mesmo, limpando assim o stdin */
}

/* Main que chama a struct e declara o switch */
int main()
{
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    int opcao;

/* imprime o menu enquanto a opção desejada for != 0 */
    do
    {
        printf("\033[33m------ MENU: ------\033[0m\n\n");
        printf("\033[93m1. Adicionar produto\033[0m\n");
        printf("\033[93m2. Listar todas as marcas\033[0m\n");
        printf("\033[93m3. Listar todos os produtos\033[0m\n");
        printf("\033[93m4. Listar produtos de um determinado estado\033[0m\n");
        printf("\033[93m5. Listar produtos de uma determinada marca\033[0m\n");
        printf("\033[93m6. Apresentar o(s) estado(s) onde está registrado o produto mais caro\033[0m\n");
        printf("\033[93m7. Apresentar o(s) fabricante(s) onde está registrado o produto mais barato\033[0m\n");
        printf("\033[93m8. Listar todos os produtos em ordem crescente de valor\033[0m\n");
        printf("\033[93m9. Listar todos os produtos em ordem crescente de maior valor ''valor do lucro''\033[0m\n");
        printf("\033[93m0. Sair\033[0m\n\n");
        printf("\033[33mESCOLHA UMA OPÇÃO: \033[0m");
        scanf("%d", &opcao);
        system("cls");

        /* Switch fazendo a seleção do menu */
        switch (opcao)
        {
        case 1:
            printf("\n\033[33m------ INFORMAÇÕES DO PRODUTO: ------\033[0m\n");
            if (numProdutos < MAX_PRODUTOS)
            {
                printf("\n\033[93mDescrição: \033[0m");
                scanf(" %[^\n]", produtos[numProdutos].descricao);
                limpa_linha();
                printf("\033[93mPeso em gramas: \033[0m");
                scanf("%f", &produtos[numProdutos].peso);
                limpa_linha();
                printf("\033[93mValor de compra: \033[0m");
                scanf("%f", &produtos[numProdutos].valorCompra);
                limpa_linha();
                printf("\033[93mValor de venda: \033[0m");
                scanf("%f", &produtos[numProdutos].valorVenda);
                limpa_linha();
                produtos[numProdutos].valorLucro = produtos[numProdutos].valorVenda - produtos[numProdutos].valorCompra;
                produtos[numProdutos].percentualLucro = (produtos[numProdutos].valorLucro / produtos[numProdutos].valorCompra) * 100;
                printf("\n\033[33m------ INFORMAÇÕES DO FABRICANTE: ------\033[0m\n");
                printf("\n\033[93mMarca: \033[0m");
                scanf(" %[^\n]", produtos[numProdutos].marca);
                limpa_linha();
                printf("\033[93mSite: \033[0m");
                scanf(" %[^\n]", produtos[numProdutos].site);
                limpa_linha();
                printf("\033[93mTelefone: \033[0m");
                scanf(" %[^\n]", produtos[numProdutos].telefone);
                limpa_linha();
                printf("\033[93mUF: \033[0m");
                scanf(" %[^\n]", produtos[numProdutos].uf);
                limpa_linha();
                numProdutos++;
                printf("\n\033[92m*PRODUTO ADICIONADO COM SUCESSO!*\033[0m\n");
                sleep(2);
                system("cls");
            }
            else
            {
                printf("\n*\033[31mLIMITE MÁXIMO DE PRODUTOS ATINGIDO!*\033[0m\n");
            }
            break;
        case 2:
            listaMarcas(produtos, numProdutos);
            break;
        case 3:
            listaProdutos(produtos, numProdutos);
            break;
        case 4:
            printf("\033[94m------ LISTA DE PRODUTOS DE UM DETERMINADO ESTADO: ------\033[0m\n");
            printf("\n\033[93mINFORME O ESTADO: \033[0m");
            char estado[MAX_UF];
            scanf(" %[^\n]", estado);
            sleep(2);
            system("cls");
            limpa_linha();
            listaProdutosEstado(produtos, numProdutos, estado);
            break;
        case 5:
            printf("\033[94m------ LISTA DE PRODUTOS DE UMA DETERMINADA MARCA ------\033[0m\n");
            printf("\n\033[93mINFORME A MARCA: \033[0m");
            char marca[MAX_MARCA];
            scanf(" %[^\n]", marca);
            limpa_linha();
            listaProdutosMarca(produtos, numProdutos, marca);
            break;
        case 6:
            estadoProdutoMaisCaro(produtos, numProdutos);
            break;
        case 7:
            fabricanteProdutoMaisBarato(produtos, numProdutos);
            break;
        case 8:
            listaProdutosOrdemCrescenteValor(produtos, numProdutos);
            break;
        case 9:
            listaProdutosOrdemCrescenteLucro(produtos, numProdutos);
            break;
        case 0:
            printf("\033[92m*PROGRAMA ENCERRADO!*\033[0m\n");
            break;
        default:
            printf("\033[91m*OPÇÃO INVÁLIDA!*\033[0m\n");
            sleep(2);
            system("cls");
            break;
        }
    } while (opcao != 0);

    return 0;
}