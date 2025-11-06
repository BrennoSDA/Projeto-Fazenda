//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Máximo de plantações para rotação
#define MAX 100

/* Sugestão de futura implementaão
typedef enum {
    ANUAL,      // Completa o ciclo em 1 ano (Soja)
    BIENAL,     // Completa o ciclo em 2 anos (Cenoura)
    PERENE      // Vive por muitos anos (Laranja)
} CicloVida; */

//Definindo os tipos de plantação
typedef enum{
    Leguminosas,    // Definido para 0
    Cereal,         // Definido para 1
    Hortaliça,      // Definido para 2
    Frutifera,      // Definido para 3
    Outro           // Definido para 4
} categoriaPlanta;

//Struct para data
typedef struct {
 int dia;
 int mes;
 int ano;
}data;


//Definindo os dados de plantação
typedef struct{
    int cod;
    char cultivo [40];
    bool irrigado;
    categoriaPlanta tipo;
    data data_plantio;
    data colheita;
    float produtividade;
}plantacao;

//lista que será armazenada o plantio
typedef struct {
    plantacao elem[MAX];
    int primeiro;
    int ultimo;
}plantio;

//Funções para o projeto

// 1. Criar plantio vazio
void criar_plantio_vazio(plantio *p){
    p -> primeiro = 0;
    p -> ultimo = p -> primeiro;
} /* atribuindo o valor de 0 para ambos */

// 2. Verificando se plantio está vazio
int verifica_plantio_vazio (plantio p){
    if (p.primeiro = p.ultimo){
        return 1;
    }else{
        return 0;
    }
}

// 3. Verificando se plantio está cheio
int verifica_pantio_cheio(plantio p){
    if (p.ultimo = MAX){
        return 1;
    }else{
        return 0;
    }
}
