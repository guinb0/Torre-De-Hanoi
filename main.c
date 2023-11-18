#include <stdio.h>
#include <stdlib.h>

// Estrutura da Pilha
typedef struct Pilha
{
    int *array;
    int top;
    unsigned capacity;
} Pilha;

// Função para criar uma pilha vazia com capacidade 
Pilha *criar(unsigned capacity)
{
    Pilha *stack = (Pilha *)malloc(sizeof(Pilha));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Função para verificar se a pilha está cheia
int isFull(Pilha *stack)
{
    return (stack->top == stack->capacity - 1);
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha *stack)
{
    return (stack->top == -1);
}
