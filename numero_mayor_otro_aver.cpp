#include<bits/stdc++.h>

using namespace std;

void comp(int tam,int *v, bool a){      //  para entender el orden sin reordenar el vector //
int cont = 0;  // tenmos un contador
int ord = 1;  // y un ordenador inicializado en 1 debido a que el numero menor
int rep = 0;
for(int i=0; i<tam;i++){
    for(int j = 0;j<tam;j++){   // llamo la segunda

       if(i!=j && v[i]==v[j]){  // para cuando son iguales , yq eu no sea el mimso, por eso las restricciones
            cont++; // entonces cuenta
            rep++;  // encontrar cuantas repeticiones hay
        }
        if(a == false){  // false para menor a mayor
        if(v[i]<v[j]){  // para cuando es menor cuente
         cont ++;    // aqui cuenta
        }
        if(cont== tam-ord && j==tam-1){ // el contador los organiza, de menor a mayor, asi si el contador es grande, digamos, para 10 numeros
                                      //el menor equivale a 9, si se repite, el siguiente a 8, asi sucesivamente
              cout<<v[i]<<" "; // auqi lo imprime en pantalla
            for(int n =0;n<rep;n++){ // para repetir el numero la cantidad de veces encontrado
              cout<<v[i]<<" "; // las veces que se repitio lo imprime
            }
            cont = 0; // el contador crece
            ord ++;   //pasar al siguiente
            i=0; // y se reinicia el for
        }
        if(i==tam-1 && j == tam-1 && ord<tam){ // a veces omite numeros debido a que su rango es menor por numeros repetidos, asi que cuando eso pasa evalua de nuevo con un ord menor
            ord++; // añade el orden, es decir si la i que evalua es igual al tamaño y la j igual, es decir los evalua todos, pero el oden aun no llega al tamaño es porque hay repetidos
            i=0; // repite el for
        }
        }
        else{ // para cuando a es verdadero es de mayor a menor
       if(v[i]>v[j]){  // para cuando es mayor cuente
         cont ++;
        }
        if(cont== tam-ord && j==tam-1){ // el contador los organiza, de menor a mayor
            cout<<v[i]<<" ";
            for(int n =0;n<rep;n++){
              cout<<v[i]<<" "; // misma logia que se uso para sacar los menores, solo que ordenados al revez
            }
            cont = 0; // cuenta
            ord ++; // el orden aumenta
            i=0; // repite el for


        }
        if(i==tam-1 && j == tam-1 && ord<tam){ // igual que el anterior, si el for se completa y el oden no avanza es porque hay repteidos y necesito que los analice de nuevo
            ord++; // aumenta el orden para buscar en un orden superior, ya que el repetido ocupa su lugar
            i=0;
        }
        }
    }
    rep=0; //reiniciar el repetir para cada reinicio del arreglo, y el contador igual para el numero
    cont = 0;
}
}

int main(){

    int tam = 0;

    cout<<"Digite la cantidad de n�meros a evaluar"<<endl;  // la cantidad de numeros que quiere evaluar los lee
    cin>>tam;

    int v[tam];  // pone esa canidad en el vector

    cout<<"Digite los numeros: "<<endl; //necesito que me cuente un vector so, pongo un for un std::cin >> ;
    for(int i = 0; i< tam; i++){
        cin>>v[i];
    }
// para ordenar de Menor a Mayor
   cout<<"\nOrden de Menor a Mayor: ";

    comp(tam,v,false); // llamo a la funcion con false para el Menor
    cout<<"\nOrden de Mayor a Menor: ";
    comp(tam,v,true); // llamo a la funcion con true para los mayores

    cout<<"\nEl vector original es: "; // Como el vector no fue tocado, que era lo que se pedia, puedo ponerlo aqui
    for(int i = 0; i<tam ;i++){
        cout<<v[i]<<" ";
    }

    cout<<"\nEl tam�o es de: "<<tam<<endl; // y finalizo con el tamaño del vector


}
