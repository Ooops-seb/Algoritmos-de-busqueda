/*Algoritmos de busqueda
Nombre: Erik Villarreal
Fecha: 24 de diciembre 2022*/

#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int> &Vector, int origin, int vect_length);
int place(vector<int> &Vector, int origin, int vect_length);
void read(vector<int> &Vector, int vect_length);
void show(vector<int> &Vector);
void menu();
void Opcion1(vector<int> &Vector);
void Opcion2(vector<int> &Vector);
int Busqueda_Lineal(vector<int> &Vector, int dato_busqueda);
int Busqueda_Binaria(vector<int> &Vector, int dato_busqueda);

int iteraciones = 0;

int main(){
    int vect_length;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|                     Ingreso de datos                  |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << endl << "Ingrese el numero de datos para el vector: ";
    cin >> vect_length;
    vector<int> vec;
    read(vec, vect_length);
    int op;
    bool salida=false;
    do{
        menu();
        cout<<"Ingrese una opcion: ";
        cin>>op;
        switch (op)
        {
            case 1:
                iteraciones = 0;
                Opcion1(vec);
                system("pause");
                break;
            case 2:
                iteraciones = 0;
                Opcion2(vec);
                system("pause");
                break;
            case 3:
                show(vec);
                system("pause");
                break;
            case 4:
                cout<<endl<<"Saliendo del programa..."<<endl;
                salida=true;
                break;
            default:
                cout<<"***OPCION INVALIDA - INGRESE NUEVAMENTE***"<<endl;
                system("pause");
                break;
        }
    }while(!salida);
    
    return 0;
}
void read(vector<int> &Vector, int vect_length){
    for(int i=0; i<vect_length; i++){
        int dato;
        cout << "Elemento [" << i+1 << "]: ";
        cin >> dato;
        Vector.push_back(dato);
    }
}
void show(vector<int> &Vector){
    cout << "VECTOR INGRESADO" << endl;
    for(int i=0; i<Vector.size(); i++){
        cout << "Elemento [" << i+1 << "]: " << Vector[i] << endl;
    }
}
void menu(){
    system("cls");
    cout << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|                  Algoritmos de Busqueda               |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "| 1. Busqueda Lineal        | 2. Busqueda Binaria       |" << endl;
    cout << "| 3. Visualizar vector      | 4. SALIR                  |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
}
void Opcion1(vector<int> &Vector){
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|                      Busqueda Lineal                  |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    int dato;
    cout << "Ingrese dato a buscar: ";
    cin >> dato;
    vector<int> auxVector;
    for(int i=0; i<Vector.size(); i++){
        int aux = Vector.at(i);
        auxVector.push_back(aux);
    }
    int indice = Busqueda_Lineal(auxVector, dato);
    cout << "Se realizaron " << iteraciones << " iteraciones de busqueda." << endl;
    if(indice != -9999)
        cout << "El dato " << dato << ", se encuentra en la posicion: " << indice << endl;
    else
        cout << "El dato no existe en el vector!" << endl;
}
void Opcion2(vector<int> &Vector){
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|                      Busqueda Binaria                 |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    int dato;
    cout << "Ingrese dato a buscar: ";
    cin >> dato;
    vector<int> auxVector;
    for(int i=0; i<Vector.size(); i++){
        int aux = Vector.at(i);
        auxVector.push_back(aux);
    }
    QuickSort(auxVector, 0, auxVector.size()-1);
    int indice = Busqueda_Binaria(auxVector, dato);
    cout << "Se realizaron " << iteraciones << " iteraciones de busqueda." << endl;
    if(indice != -9999)
        cout << "En un vector ordenado, el dato " << dato << ", se encuentra en la posicion: " << indice << endl;
    else
        cout << "El dato no existe en el vector!" << endl;
}
int Busqueda_Lineal(vector<int> &Vector, int dato_busqueda){
    for(int i=0; i<Vector.size(); i++){
        iteraciones++;
        if(Vector.at(i) == dato_busqueda){
            return i;
        }
    }
    return -9999;
}
int Busqueda_Binaria(vector<int> &Vector, int dato_busqueda){
    int mid;
    int izq = 0;
    int der = Vector.size() - 1;
    while(izq <= der){
        iteraciones++;
        mid = izq + (der - izq)/2;
        if(Vector.at(mid) == dato_busqueda){
            return mid;
        }
        else{
            if(dato_busqueda < Vector.at(mid))
                der = mid-1;
            else if(dato_busqueda > Vector.at(mid))
                izq = mid+1;
        }
    }
    return -9999;
}
void QuickSort(vector<int> &Vector, int origin, int vect_length){
    int pivote;
    if(origin < vect_length){
        pivote = place(Vector, origin, vect_length);
        QuickSort(Vector, origin, pivote-1);
        QuickSort(Vector, pivote+1, vect_length);
    }
}
int place(vector<int> &Vector, int origin, int vect_length){
    int pivote, valor_pivote;
    int temp;
    pivote = origin;
    valor_pivote = Vector[pivote];
    for(int i = origin+1; i<=vect_length; i++){
        if(Vector[i] < valor_pivote){
            pivote++;
            temp = Vector[i];
            Vector[i] = Vector[pivote];
            Vector[pivote] = temp;
        }
    }
    temp = Vector[origin];
    Vector[origin] = Vector[pivote];
    Vector[pivote] = temp;
    return pivote;
}