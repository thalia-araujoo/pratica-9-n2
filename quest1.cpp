#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define t 3

void ordem_original(int v[], int tam);

void selection_sort(int v[], int ord[], int tam, int tipo);

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
   
    int mat[t], n1[t], n2[t], media[t], ordem[t];
    int coluna=1;
    int tipo=1, repetir=1;
   
    printf("Informe os dados dos alunos: \n");
   
    for(int i=0; i<t; i++){
        printf("Aluno %dº\n", i+1);
        printf("Matrícula: ");
        scanf("%d", &mat[i]);
       
        printf("Nota primeiro bimestre: ");
        scanf("%d", &n1[i]);
       
        printf("Nota segundo bimestre: ");
        scanf("%d", &n2[i]);
       
        media[i] = (n1[i]+ n2[i])/2;
       
        ordem[i] = i;
    }
   
    do{
   
        printf("Qual a coluna deseja ordenar?\n");
        printf("[1] N1  [2] N2  [3] Média: ");
        scanf("%d", &coluna);
       
        printf("Qual a ordem você deseja?\n");
        printf("[0] Matrícula  [1] Crescente [2] Decrescente: ");
        scanf("%d", &tipo);
       
        switch(coluna){
            case 1:
                selection_sort(n1, ordem, t, tipo);
                break;
            case 2:
                selection_sort(n2, ordem, t, tipo);
                break;
            case 3:
                selection_sort(media, ordem, t, tipo);
                break;
        }
       
        printf("Resultado ordenado: \n");
       
        printf("MAT\t\tN1\t\tN2\t\tMÉDIA\n");
        for(int i=0; i<t; i++){
            printf("%d\t\t%d\t\t%d\t\t%d\n",
            mat[ordem[i]],
            n1[ordem[i]],
            n2[ordem[i]],
            media[ordem[i]]);
        }
        printf("\n\nDeseja fazer outro filtro?\n");
        printf("[1] SIM        [0] NÃO: ")    ;
        scanf("%d", &repetir);
       
        system("cls");
       
    } while(repetir!=0);
   
    return 0;
}

void ordem_original(int v[], int tam){
    for(int i=0; i<tam; i++){
        v[i] = i;
    }    
}

void selection_sort(int v[], int ord[], int tam, int tipo){
    int min, i, aux;
   
    for(i=0; i<tam; i++){
        min = i;
        for(int j = (i+1); j<tam; j++){
            if(tipo==1){
                if(v[j] < v[min]){
                    min = j;
                }    
            } else if(tipo==2){
                if(v[j] > v[min]){
                    min = j;
                }    
            } else{
                ordem_original(ord, tam);
            }
           
        }
       
        if(i!= min){
            aux = ord[i];
            ord[i] = ord[min];
            ord[min] = aux;
        }
    }
}





	






