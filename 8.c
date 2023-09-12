#include <stdio.h>
#include <stdlib.h>

/*Dados dos arreglos unidimensionales A, B de n y m valores respectivamente, que representan los elementos de un conjunto, se pide mostrar:
a. La unión.
b. La diferencia.
c. La intersección.
*/
int cargar(int[], int);
int unionVectores(int[], int);
void imprimir(int[], int);
void unionArrays(int[], int[], int[], int, int);
void diferenciaArrays(int[], int[], int);
void interArray(int[], int[], int[], int);

void main(){
    int n = 8; int m = 8; int k = 0;
    k = n + m;
    int firstArray[n]; int secondArray[m]; int unionArray[k];
    int diferenciaArray[k];int intersecArrays[k];

    cargar(firstArray, n);
    cargar(secondArray, m);

    printf("Union de vectores\n");
    unionArrays(firstArray, secondArray, unionArray, n, k);

    printf("\nArray con diferencias\n");
    diferenciaArrays(unionArray, diferenciaArray, k);

    printf("\nArray con Interseccion\n");
    interArray(firstArray, secondArray, intersecArrays, n);
}

void interArray(int first[],int second[],int third[], int n){
    int intersec = 0;
    int cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(first[i] == second[j]){
                intersec = 1;
                break;
            }
        }
        if(intersec == 1){
            third[cont] = first[i];
            cont++;
        }
        intersec = 0;
    }
    imprimir(third,cont);
}

void diferenciaArrays(int unionArray[],int diferenciaArray[],int tamanio){
    int repetido = 0;
    int contador = 0;
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            if(unionArray[i] == unionArray[j] && i != j){
                repetido = 1;
                break;
            }
        }
        if(repetido != 1){
            diferenciaArray[contador] = unionArray[i];
            contador++;
        }
        repetido = 0;
    }
    imprimir(diferenciaArray,contador);
}

void unionArrays(int first[],int second[],int third[],int n,int k){
    for(int i = 0; i < k; i++){
        third[i] = first[i];
    }
    for(int j = 0; j < k-n; j++){
        third[j+n] = second[j];
    }
    imprimir(third, k);
}

int cargar(int array[], int tamanio){
    int numero = 0;

    for(int i = 0; i < tamanio;i++){
        numero=rand() % 20 + 1;
        array[i] = numero;
    }
    return array[8];
}

void imprimir(int vector[],int length){
    for(int i = 0; i < length; i++){
        printf("%d -", vector[i]);
    }
}
