// Commit: Se agregó las funciones pushMemoria y popMemoria al módulo del Gestor de Memoria.
// Integrante: Shadi

#include <iostream>
#include <cstring>
using namespace std;

struct Proceso {
    int id;
    char nombre[30];
    int prioridad;
    Proceso* sig;
};

Proceso* cabeza = NULL;

struct NodoCola {
    int idProceso;
    char nombre[30];
    NodoCola* sig;
};

NodoCola* frente = NULL;
NodoCola* final = NULL;

struct NodoPila {
    int bloqueMemoria;
    NodoPila* sig;
};

NodoPila* cima = NULL;

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
    int id;
    cout<<"Ingrese ID del proceso a eliminar: ";
    cin>>id;

    Proceso* actual = cabeza;
    Proceso* anterior = NULL;

    while (actual != NULL && actual->id != id) {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual == NULL) {
        cout<<"Proceso no encontrado."<<endl;
    } else {
        if (anterior == NULL) {
            cabeza = actual->sig;
        } else {
            anterior->sig = actual->sig;
        }
        delete actual;
        cout<<"Proceso eliminado correctamente."<<endl;
    }
}

void listarProcesos() {
    Proceso* aux = cabeza;
    if (aux == NULL) {
        cout<<"No hay procesos registrados."<<endl;
        return;
    }
    cout<<"=== LISTA DE PROCESOS ==="<<endl;
    while (aux != NULL) {
        cout<<"ID: "<<aux->id<<", Nombre: "<<aux->nombre<<", Prioridad: "<<aux->prioridad<<endl;
        aux = aux->sig;
    }
}

void modificarPrioridad() {
    int id;
    cout<<"Ingrese ID del proceso a modificar: ";
    cin>>id;

    Proceso* aux = cabeza;
    while (aux != NULL && aux->id != id) {
        aux = aux->sig;
    }

    if (aux == NULL) {
        cout<<"Proceso no encontrado."<<endl;
    } else {
        cout<<"Prioridad actual: "<<aux->prioridad<<endl;
        cout<<"Ingrese nueva prioridad: ";
        cin>>aux->prioridad;
        cout<<"Prioridad modificada correctamente."<<endl;
    }
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

void encolarProceso() {
    NodoCola* nuevo = new NodoCola;
    cout<<"Ingrese ID del proceso: ";
    cin>>nuevo->idProceso;
    cout<<"Ingrese nombre del proceso: ";
    cin.ignore();
    cin.getline(nuevo->nombre, 30);
    nuevo->sig = NULL;

    if (frente == NULL) {
        frente = final = nuevo;
    } else {
        final->sig = nuevo;
        final = nuevo;
    }
    cout<<"Proceso encolado correctamente."<<endl;
}

void desencolarProceso() {
    if (frente == NULL) {
        cout<<"No hay procesos en cola."<<endl;
    } else {
        NodoCola* temp = frente;
        frente = frente->sig;
        cout<<"Ejecutando proceso: "<<temp->nombre<<endl;
        delete temp;
    }
}

void mostrarCola() {
    NodoCola* aux = frente;
    if (aux == NULL) {
        cout<<"Cola vacia."<<endl;
        return;
    }
    cout<<"=== COLA DE PROCESOS ===\n";
    while (aux != NULL) {
        cout<<"ID: "<<aux->idProceso<<", Nombre: "<<aux->nombre<<endl;
        aux = aux->sig;
    }
}

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

void pushMemoria() {
    NodoPila* nuevo = new NodoPila;
    cout<<"Ingrese numero de bloque de memoria a asignar: ";
    cin>>nuevo->bloqueMemoria;
    nuevo->sig = cima;
    cima = nuevo;
    cout<<"Bloque de memoria asignado."<<endl;
}

void popMemoria() {
    if (cima == NULL) {
        cout<<"No hay bloques de memoria asignados."<<endl;
    } else {
        NodoPila* temp = cima;
        cima = cima->sig;
        cout<<"Bloque de memoria liberado: "<<temp->bloqueMemoria<<endl;
        delete temp;
    }
}

void verMemoria() {

}

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

