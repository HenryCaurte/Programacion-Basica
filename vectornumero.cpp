#include <bits/stdc++.h>
using namespace std;

int mostrarV(vector<int> a){ //mostramos el vector

    for (auto i : a){ // Un for each para poder buscar los elemenotos
        cout<<" "<<i; // lo leemos
    }
    cout<<endl;
}

int main() {
    vector<int> t; // creamos el vector t
    int n; // creamos la variable n para poder leer el tamaño deseado
    cout << "Tamabio del vector: ";
    cin>>n; // llemos el tamaño del vector

    for(int i=0;i<n;i++){ // usamos un for para leer los numeros desde 0 hasta el numero deseado
        int aux; // inicializamos aux que es donde pondremos los numero
        cin>>aux; // los leemos
    t.push_back(aux); // con t.push_back(aux) añadiremos un vector cada que escribe un numero, como un vector dinamico
    }


    cout<<"El vector es: ";
    mostrarV(t); // mostramos el vector
    cout<<"El vector ordenado es: ";
    sort(t.begin(), t.end()); // con la funcion sort miramos de menor a mayor, una funcion que reordena los numeros de menor a mayor
    mostrarV(t); // mostramos el vector
    cout<<"El vector inverso al ordenad o es: ";
    sort(t.rbegin(), t.rend()); // con la funcion sort, t t.rbegin ty t.rend ordenamos los numeros de mayor a menor
    mostrarV(t); // mostramos los numeros
    cout<<"el tamanio e:s "<<n<<endl; // les damos el tamaño owo
    return 0;
}
