#include <bits/stdc++.h>
#define tam 3  // Tamaño del arreglo

using namespace std;

bool verificador(int a[][tam], int, int){ //Verifica que la suma de cada una de las filas y las columnas (tambien las diagonales den igual)
    bool val= true; // el que hace que repita o no
    int sumf[tam] = {0}; //sumar cada fila por separado
    int sumc[tam] = {0}; // sumar cada columna por separado
    int sumad1; // Suma de la digaonal 1
    int sumad2; // Suma de la diagonal 2
    sumad1 = a[0][0] +a[1][1] +a[2][2] ;
    sumad2 = a[0][2] +a[1][1] +a[2][0] ;

for(int i = 0; i <tam; ++i){           // evalua las columnas, y las suma
    for(int j = 0; j <tam ; j++){

        sumc[i] +=a[i][j];  // suma de columnas
    }
}

for(int i = 0; i <tam; ++i){           // evalua las filas, y las suma
    for(int j = 0; j <tam ; j++){

        sumf[i] += a[j][i];  // suma de columnas

    }
}


if (sumf[0] != sumf[1] || sumf[0] != sumf[2] || sumf[1] != sumf[2]){ // condiciones, asi la suma es distinta, el val es falso y hace que vuelva a evaluar en el main
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

void cuadrado(int a[tam][tam], int, int){  // Genera el cuadrado

cout<<"|-----------------|"<<endl; //el techito
for(int i = 0; i < tam ; ++i){ // para leer las filas
    for(int j = 0; j< tam; ++j){ // para leer las columnas
        cout<<"|"<<a[j][i]<<"|";  // escribe
        if(j == tam-1){ // una condicion para que cada que llegue a la ultima columna, salte a la otra fila y tenga un orden
            cout<<endl;
        }
    }
}


}
bool ver(int a, int m[tam][tam], int, int){ // para que no repita numeros aleatorios, y no genere algo tipo, 5 5 5 5 5 5 5 5 5 5 5

bool ma = true;  // esto evalua si es o no repetido

for(int i = 0; i <tam; i++){  // aqui evalua las filas
    for(int j = 0 ; j<tam; ++j){  // evalua las columnas
        if(a== m[i][j]){  // coloca las condiciones, si es igual a alguna columan el entero añadido (en este caso a), returna falso
            ma = false;
        }
    }
}
return ma; // retorna el valor de ma
}


int main() { // main
//cuadro magico
int aux = 0; // un auxiliar de aleatorio y
srand(time(NULL)); // para generar un numero aleatoreo
int a[tam][tam]={(0,0,0),(0,0,0),(0,0,0)};
do{
    for(int i = 0; i <tam; i++){   //reinicio el arreglo pa q busque de nuevo :p
    for(int j = 0; j<tam ; ++j){  // inicializa el arreglo en filas y columnas
        a[i][j] = 0;
    }
}
for(int j = 0; j<tam;++j){ // un for para las gilas
   for(int i = 0; i <tam; ++i){ // otro para las columnas
    do{
        aux = rand()%9 +1;  // es al random
    }while(ver(aux,a,tam,tam)== false);// pa que busque aleatorios entre 1 y 9 que no se repitan
        a[j][i] = aux;
      //  a[1][1] = 5;  // puedo quitarlo o no, pero creo que todos tienen 5 en el centro (poner o no)

   }
}

}while(!verificador(a,tam,tam));   // este es que no salga hasta que forme un cuadrado

cout<< "EL cuadrado magico es: "<<endl;
cuadrado(a,tam,tam);          // donde se ve todo

   return 0;
}
