#include <iostream>
#define tam 50 // definimos un tamaño predeterminado de almacenamiento para crear una funcion

using namespace std;

void mostrar(float a[][tam],int , int, int t){   // Para mostrar las matrices

    cout<<"Su matriz es : "<<endl;

    for(int i = 0; i< t; i++){    //filas
     for (int j = 0; j<t; j++){  //columnas
        cout<<"|"<<a[i][j]<<"|";

    if(j == t-1) // para que salte y se ve wonito
        cout<<endl;
  }
    }

}
void inicializar(float a[][tam], int, int,int t){ // inicializa las matrices creadas en solo 0
    for (int i = 0; i<tam ; ++i){ // un for que recorra la matriz esa y evaluna no se la coma jsjsjs // se que es la placenta pero aja
            for (int j = 0; j< tam; ++j){
            a[i][j] = 0;
            }
    }

}

void setdatos(float a[][tam], int , int, int t){  // creamos una funcino que lee los datos para rednir
int i = 0;
for(i; i< t; i++){    //filas
  for (int j = 0; j<t; j++){  //columnas
    cin>>a[i][j]; // los lee
    if(j == t-1) // salta la linea para que no se vea taaaan feo, o sea, se ve feo, pero meh, no es tanto
        cout<<"---"<<endl;
  }
}
}

void Suma(float a[][tam],float b[][tam], int, int, int t){ // usamos un arreglo char para leer la operacion

  cout<<"La suma es : "<<endl;
    for(int i = 0; i< t; i++){    //filas
      for (int j = 0; j<t; j++){  //columnas
        cout<<"| "<<a[i][j] + b[i][j]<< " |"; // aqui sumamos normalito
          if(j == t-1)
              cout<<endl;
      }
    }
}
void Resta(float a[][tam],float b[][tam], int, int, int t){ // usamos un arreglo char para leer la operacion

  cout<<"La Resta es : "<<endl;
    for(int i = 0; i< t; i++){    //filas
      for (int j = 0; j<t; j++){  //columnas
        cout<<"| "<<a[i][j] - b[i][j]<< " |"; // restamos normalito
          if(j == t-1)
              cout<<endl;
      }
    }
}
void Producto(float a[][tam],float b[][tam], int, int, int t){ // usamos un arreglo char para leer la operacion
cout<<"El producto es: "<<endl;

float multi[tam][tam]; // matriz multiplicacion
int cont = 0; // un contador
inicializar(multi,tam,tam,t); // la inicialiamos

  cout<<"La Multiplicacion es : "<<endl;

    //for(int aux = 0 ; aux < t; aux++){

    for(int i = 0; i < t ; i++){ // bueno un for para que me reocorra las filas
            do{

        for(int j = 0; j< t; j++)
        {
            multi[i][cont] += (a[i][j]*b[j][cont]); // uso el concepto de multplicar filas por las columnas, como se hace en las matrices y lo guiardo en la multi
        }
            cont ++;
          }while(cont<t); //este do hace que el contador no se pase de las t, es decir, que cuente las columnas hasta que multiplique todas y ahi si pueda cambiar de fila
            cont=0;
  //  }
    }

mostrar(multi,tam,tam,t); // la muestrea

}

void inversa(float a[][tam], int, int, int t){ // leemos la matriz, sus enteros y el "tamaño"

float inversa[tam][tam]; // creamos una funcion inversa
float aux,aux2; // dos auxialares
//int j = 0;int k = 0; --> no es necesario creo, lo quite anoche, :c
inicializar(inversa,tam,tam,t); //inicializamos la inversa

for(int  i = 0; i < t; i++){  // la hacemos identidad
    inversa[i][i] = 1;
}

for(int i = 0 ; i<t; i++){ // para buscar la digaonal
 aux = a[i][i];
 for(int j = 0; j<t; j++){ // para armar la inversa
    if(aux == 0){
            cout<<" No existe Su inversa ñejeje "<<endl; // como no se puede dividir en 0 pues lo quito y returno al main ñejeje
       return;
    }
    a[i][j] /= aux; // aqui divido
    inversa[i][j] /= aux; // y hago lo mismo a la inversa,
 }

 for(int k = 0; k<t; k++){
    if(i!=k){           //no ando en la diagonal ñejej
        aux2 = a[k][i]; // como no ando ahi  uso el auxiliar dos

        for(int j =0;j<t;++j){ // y aqui ahora resto ese auxiliar, como no ando en la digaonla puedo hacerlo sin que halla compliaciones en la digaonal
            a[k][j] -=(aux2*a[i][j]);
            inversa[k][j] -=(aux2*inversa[i][j]); // lo que le hago a la normal, le hago a la inversa
        }
    }
 }
}

mostrar(inversa,tam,tam,t); // aqui muestro la inversa

}


int main(){

  int t;
  cout<<"ingrese el tamanio de las matrices"<<endl;
 cin>>t;

  float matriz[tam][tam];  // el tamaño de las matrices ya estan definidas
  float matrizcopia[tam][tam]; // el tamaño de las matrices ya estan definidas

  // inicializamos
  inicializar(matriz,tam,tam,t);
  inicializar(matrizcopia,tam,tam,t);
  //

cout<<"Digite la matriz uno"<<endl;   // ingresamos la matriz uno
setdatos(matriz,tam,tam,t);  //mostramos
mostrar(matriz,tam,tam,t);    //leemos
cout<<"Digite la matriz dos"<<endl; // ingresamos la matriz dos
setdatos(matrizcopia,tam,tam,t);  // leemos
mostrar(matrizcopia,tam,tam,t);   // mostramos
// donde pondremos la suma:
Suma(matriz,matrizcopia,tam,tam,t); // damos la suma
Resta(matriz,matrizcopia,tam,tam,t);
Producto(matriz,matrizcopia,tam,tam,t); // damos la multiplicacion.


cout<<"-- inversa --"<<endl;
cout<<endl;
cout<<"la maitriz inversa de la M1 es: "<<endl;
inversa(matriz,tam,tam,t); // llamo a la inversa
cout<<"La matriz inversa de la M2 es: "<<endl;
inversa(matrizcopia,tam,tam,t); // llamo a la inversa
cout<<"-----------------"<<endl;
  return 0;
}
