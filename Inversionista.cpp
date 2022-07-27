#include<bits/stdc++.h>
using namespace std;

float incapi(float inominal, float p){  // aqui tenemos los numero de periodos capitalizables en un año
float i = (inominal/p); // formula para la i, que es inominal/los periodos

return i;
}
float periodo(int n, short int cap){ // la cantidad de periodos que hay
int N = n*cap;

return N;
}

float vf(float c, float i, float n){ // valor futuro
float vf1 =1;    // necesit que sea uno para que al multiplicara abajo no me genere solo 0
for(int p = 0; p<n;p++){ // un for para la formula de valor futuro (no me funcionaba el pow(,) :c )
    vf1= (i+1)*vf1;
}

return c*vf1; //retorna el valor futuro total, que es el monto por lo ya calculado
}

void menuf(float monto, float inominal, float n, float p){   // aqui vemos como es el "menu",

cout<<"------------------------------------------------------"<<endl;
cout<<"El monto inicial: "<<monto<<endl;
cout<<"Interes nominal de: "<<inominal<<"%."<<endl;
cout<<"El numero de anos : "<<n<<endl;
cout<<"La tasa de interes efectiva capitalizable : "<<incapi(inominal,p)<<endl;
cout<<"Periodos por anio: "<<p<<endl;
cout<<"La cantidad de periodos: "<<periodo(n,p)<<endl;
cout<<"El valor futuro es: "<<vf(monto,incapi(inominal,p),periodo(n,p))<<endl;
cout<<"------------------------------------------------------"<<endl;
}


int main(){



float p = 0; // periodo
float monto=0; //monto
float inominal=0; // interes nominal
int n = 0; // años
short int cap = 0;// capitalizar , un short porque es de escojer un valor reducido de opciones, (4 en total)
int escoi= 0; //
cout<<"\t\tBienvenido: \nIngrese su monto a ingresar \"en dolares\" : "<<endl;
cin>> monto;
do { // para no dar error
cout<<"Que interes nominal desea establecer?\n \n1)0.3%\n2)0.7%\n3)Usted lo elije"<<endl; // como no sabia como es el interes nominal, puse que pudiera escoger dos opciones,
cin>> escoi; // aqui escoje, y dependiendo de lo que escoja, un switch case da uno de los valores, si no, por predefinido elije 1
}while(escoi <1 || escoi>3);
switch(escoi){ // caso interes nominal
case 1:
    inominal = 0.03;
break;
case 2:
    inominal = 0.07;
break;
default:
    cout<<"Si no desea esas, cual desea?"<<endl;
    cin>>inominal; // si no lo elije el usuario
    inominal /= 100; // hacemos el escojido a porcentaje, entre 0 - 1 .
break;
}
cout<<"Cuantos anos desea mantenerse? : "<<endl; // cantidad de años
cin>> n; // los lee
cout<<"Ingresa Como desea capitalizar su dinero : "<<endl; // ingresa como desea capitalizar, hay 4 opciones
do{
      cout<<"\n1)Mensual.\n2)Trimestral.\n3)Semestral.\n4)Anual."<<endl;
      cin>>cap; // lee

}while(cap < 1||cap>4); // para no generar error al poner otra variable

switch(cap){ // casos para determinar la cantidad de periodos por año, depende de lo que elgio de como capitalizar
    case 1:
        p = 12/1; // por mes
    break;
    case 2:
        p = 12/3; // por trimestre
    break;
    case 3:
        p = 12/6; // por semestre
    break;
    case 4:  // por años
        p = 1;
    break;
    default: // el default es por el año
        p = 1;
        break;
}

menuf(monto,inominal,n,p); // da para el menu, y sha.

return 0;
}

// C es lo que quiere meter al banco
//interese nominal aval I
// N le pide los a�os y que quiere usar si semestral y la mamada, luego cuantos son capitalizables?
// N cantidad de periodos capitalizables
// banco ofrece: -Mensual - Trimestral -Semestral -Anual (capitalizable)
// i = I/P -> P es el numero de periodos que hay en un a�o(capitalizables)
//det: Valor futuro de la inversion
