#include <bits/stdc++.h>
#define tam 3

using namespace std;

int copia[tam][8];// 8 porque es el numero mayor de graficas, no me gusta dejar numeros pero ok

void copiar(int a[][tam], int, int, int cont){   // Para copiar la primera fila, a una fial del vector copia

    for(int j = 0; j<tam; ++j){
        copia[j][cont] = a[j][0];
    }
}

bool evaluarcopia(int a[][3], int , int, int cont){   //analiza cada resultado en si es igual a uno ya obtenido
bool copis = true;

    int conti = 0;
    for(int i = 0; i <cont; i++){
        for(int j = 0; j <tam ; j++){
            if(a[j][0] == copia[j][i]){
                conti++;
            }
            if(conti == tam){   // hace un contador y si ese contador es igual al tama�o de filas de la matriz 3x3 pues dice false, para decir que ya est�
                copis = false;
            }
        }
        conti = 0;
    }

return copis;
}



bool verificador(int a[][tam], int, int){
    bool val= true; // el que hace que repita o no
    int sumf[tam] = {0}; //sumar cada fila por separado
    int sumc[tam] = {0}; // sumar cada columna por separado
    int sumad1;
    int sumad2;
    sumad1 = a[0][0] +a[1][1] +a[2][2] ;
    sumad2 = a[0][2] +a[1][1] +a[2][0] ;
for(int i = 0; i <tam; ++i){           // evalua las columnas, y las suma
    for(int j = 0; j <tam ; j++){

        sumc[i] +=a[i][j];  // suma de columnas
    }
}

for(int i = 0; i <tam; ++i){           // evalua las columnas, y las suma
    for(int j = 0; j <tam ; j++){

        sumf[i] += a[j][i];  // suma de columnas

    }
}


if (sumf[0] != sumf[1] || sumf[0] != sumf[2] || sumf[1] != sumf[2]){ // condiciones
    val = false;
}
if (sumc[0] != sumc[1] || sumc[0] != sumc[2] || sumc[1] != sumc[2]){ // condiciones
    val = false;
}
if(sumad1 != sumc[0] || sumad2 != sumf[2]){  // condiciones
    val = false;
}

   return val;
}
//////////////

void cuadrado(int a[tam][tam], int, int){  // escribir el cuadrado


cout<<"|-----------------|"<<endl;
cout<<"|"<<a[0][0]<<"|"<<a[1][0]<<"|"<<a[2][0]<<"|"<<endl;
cout<<"|"<<a[0][1]<<"|"<<a[1][1]<<"|"<<a[2][1]<<"|"<<endl;
cout<<"|"<<a[0][2]<<"|"<<a[1][2]<<"|"<<a[2][2]<<"|"<<endl;

}
bool ver(int a, int m[tam][tam], int, int){ // para que no repita numeros aleatorios y optimice, tris

bool ma = true;

for(int i = 0; i <tam; i++){
    for(int j = 0 ; j<tam; ++j){
        if(a== m[i][j]){
            ma = false;
        }
    }
}
return ma;
}

int main() {
    /////////////////////////// inicializo la copia
    for(int nol = 0; nol < 8 ; nol++){
    for(int ala = 0; ala<3; ala++){
        copia[ala][nol] = 0;
    }}
//cuadro magico
int cont = 0; // contador para no repetir las matrices
int aux = 0;  // auxiliar para el random, ahcerlo mas facil
srand(time(NULL));
int a[tam][tam]={(0,0,0),(0,0,0),(0,0,0)};
do{
  /*  for(int nol = 0; nol < 8 ; nol++){
    for(int ala = 0; ala<3; ala++){
        cout<< copia[ala][nol]<<" ";
    }cout<<endl;

    }*/
do{
    do{
    for(int i = 0; i <tam; i++){   //reinicio el arreglo pa q busque de nuevo :p
    for(int j = 0; j<tam ; ++j){
        a[i][j] = 0;
    }
    a[1][1] = 5;
}
for(int j = 0; j<tam;++j){
   for(int i = 0; i <tam; ++i){
    do{
        aux = rand()%9 +1;  // es al random
    }while(!ver(aux,a,tam,tam));// pa que busque aleatorios entre 1 y 9 que no se repitan
        a[j][i] = aux;
        a[1][1] = 5;  // puedo quitarlo o no, pero creo que todos tienen 5 en el centro
   }
}
//cuadrado(a,3,3);
}while(!evaluarcopia(a,tam,tam,cont));

}while(!verificador(a,tam,tam));   // este es que no salga hasta que forme un cuadrado

cout<< "EL cuadrado magico es: "<<endl;
cuadrado(a,tam,tam);
copiar(a,tam,tam,cont);

cont ++;
}while(cont<=7);         // donde se ve todo

   return 0;
}
