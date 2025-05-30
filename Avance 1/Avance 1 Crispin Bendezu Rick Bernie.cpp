// Commit: Se agregó la estructura Proceso y las variables globales necesarias para el gestor de procesos.
// Integrante: Rick

#include<iostream>
#include<cstring>
using namespace std;

struct Proceso {
    int id;
    char nombre[30];
    int prioridad;
    Proceso* sig;
};

Proceso* cabeza = NULL;

void insertarProceso() {
    Proceso* nuevo = new Proceso;
    cout<<"Ingrese ID del proceso: ";
    cin>>nuevo->id;
    cout<<"Ingrese nombre del proceso: ";
    cin.ignore();
    cin.getline(nuevo->nombre, 30);
    cout<<"Ingrese prioridad: ";
    cin>>nuevo->prioridad;
    nuevo->sig = NULL;

    if (cabeza == NULL) {
        cabeza = nuevo;
    } else {
        Proceso* aux = cabeza;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    cout<<"Proceso creado exitosamente."<<endl;
}

void eliminarProceso() {

}

void listarProcesos() {

}

void modificarPrioridad() {

}

void GestorDeProcesos() {
    int op;
    do {
        cout<<"\n=== GESTOR DE PROCESOS ===\n";
        cout<<"1. Crear nuevo proceso\n";
		cout<<"2. Eliminar proceso\n";
		cout<<"3. Listar procesos\n";
		cout<<"4. Cambiar prioridad\n";
		cout<<"5. Volver al menu\n";
        cout<<"Seleccione una opcion: ";
        cin>>op;
        switch (op) {
            case 1: 
				insertarProceso(); 
				break;
            case 2: 
				eliminarProceso(); 
				break;
            case 3: 
				listarProcesos(); 
				break;
            case 4: 
				modificarPrioridad(); 
				break;
            case 5: 
				break;
            default: 
				cout<<"Opcion invalida.\n";
        }
    } while (op != 5);
}

void encolarProceso() {}

void desencolarProceso() {}

void mostrarCola() {}

void PlanificadorCPU() {
    int op;
    do {
        cout<<"\n=== PLANIFICADOR DE CPU ===\n";
        cout<<"1. Encolar proceso\n";
		cout<<"2. Ejecutar siguiente\n";
		cout<<"3. Ver cola\n";
		cout<<"4. Volver al menu\n";
        cout<<"Seleccione una opcion: ";
        cin>>op;
        switch (op) {
            case 1:
            	encolarProceso(); 
				break;
            case 2:
				desencolarProceso(); 
				break;
            case 3:
				mostrarCola();
				break;
            case 4: 
				break;
            default: 
				cout<<"Opcion invalida.\n";
        }
    } while (op != 4);
}

void pushMemoria() {}

void popMemoria() {}

void verMemoria() {}

void GestorDeMemoria() {
    int op;
    do {
        cout<<"\n=== GESTOR DE MEMORIA ===\n";
        cout<<"1. Asignar memoria (push)\n";
		cout<<"2. Liberar memoria (pop)\n";
		cout<<"3. Ver estado de memoria\n";
		cout<<"4. Volver al menu\n";
        cout<<"Seleccione una opcion: ";
        cin>>op;
        switch (op) {
            case 1:
				pushMemoria();
				break;
            case 2:
				popMemoria();
				break;
            case 3:
				verMemoria();
				break;
            case 4:
				break;
            default:
				cout<<"Opcion invalida.\n";
        }
    } while (op != 4);
}

int main() {
    int opcion;
    do {
        cout<<"===== MENU PRINCIPAL =====\n";
        cout<<"1. Gestor de Procesos\n";
        cout<<"2. Planificador de CPU\n";
        cout<<"3. Gestor de Memoria\n";
        cout<<"4. Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch (opcion) {
            case 1:
				GestorDeProcesos(); 
				break;
            case 2:
				PlanificadorCPU(); 
				break;
            case 3: 
				GestorDeMemoria(); 
				break;
            case 4:
				cout<<"Saliendo del sistema..."<<endl; 
				break;
            default: 
				cout<<"Opcion invalida. Intente nuevamente."<<endl;
        }

        if (opcion != 4) {
            cout<<"\nPresione ENTER para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (opcion != 4);

    cout<<"Fin del programa."<<endl;
    return 0;
}

