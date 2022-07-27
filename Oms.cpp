#include<bits/stdc++.h>
using namespace std;

void leerdatos(float *v, int n){ //lee las personas
    for(int i=0;i<n; i++){ // un for para que lea a una por una
    cout<<"\nPersona "<<i+1<<" : ";
    cin>>v[i];
    if(v[i]<80 || v[i]>100){ // manda mensaje si fue o no descartado
        cout<<"Dato descartado\n";
        v[i] =0;}else{cout<<"Dato valido"<<endl;} // valid
        cout<<endl;
}
}
float promedio(vector<float> v,int cont){// calcula promedio , es mejor ahcerlo por aparte
float suma = 0;
    for(int i = 0; i<cont; i++){
        suma+=v[i];
    }
return suma/cont;
}

float desviacion_tipica(vector<float> v, float p, int n){ //desviacion tipica usamos la formula
float dt; // un dt para la desviacion tipica
for(int i=0; i<n; i++){
    dt += pow((v[i]-p),2) ; // elevamos con la fucnio pow
}
return sqrt(dt/n); //retorna un valor que es el de la desviasion ñejeje
}
int main(){
    int c=0; // int c para no contar las personas permitidas
 vector<float> t; // creamos un vector t para los datos permitidos
 int personas = 0; //numero personas
 cout<<"Digite el numero de personas"<<endl;
 cin>>personas; // digitas el numero de personas

float vp[personas]; // valores por persona , creamos un vector asi
cout<<"\nDigite los datos: "<<endl;

leerdatos(vp,personas); //como vimmos lee los datos, cuando no son validos los deja en 0

for(int i=0; i <personas;i++){ // pone los valores validos en otro vector
    if(vp[i]!=0){
        t.push_back(vp[i]); // si es distinto de 0 , es decir, si es valido, hace un push_back a la funcion t en la posicion i, un vector deinamico ñejeje
        c++; // el contador suma para hacer el promedio bien
    }
}
cout<<"Datos validos: "<<endl; // los datos validos
int k=1;  //un contador para que se vea wonito
for(auto i : t){  // un for each para leer los elementos del vector
    cout<<"- persona valida "<<k<<" : "<< i<<endl;
    k++;
}

cout<<"Desviacion tipica: "<<desviacion_tipica(t,promedio(t,c),c)<<endl; // le desviacion la pone en pantalla y sha
cout<<"-------------------------------"<<endl;

}
