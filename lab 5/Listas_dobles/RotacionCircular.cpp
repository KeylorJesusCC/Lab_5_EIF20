#include "RotacionCircular.h"

namespace EIF201 {


    RotacionCircular::RotacionCircular()
        : cola(nullptr), cantidad(0) {
    }

    NodoLocutor* RotacionCircular::getCabeza() const {
        return (cola != nullptr) ? cola->siguiente : nullptr;
    }

    RotacionCircular::~RotacionCircular() {
        if (cola == nullptr) {
            return;
        }
        NodoLocutor* cabeza = cola->siguiente;
        cola->siguiente = nullptr; // Romper el ciclo antes de liberar memoria

        NodoLocutor* actual = cabeza;
        while (actual != nullptr) {
            NodoLocutor* temp = actual->siguiente;
            delete actual;
            actual = temp;
        }
        cola = nullptr;
        cout << "[RotacionCircular destruida]" << endl;
    }

    void RotacionCircular::insertarAlFinal(const string& nombre) {
        NodoLocutor* nuevo = new NodoLocutor(nombre);
        if (cola == nullptr) {
            nuevo->siguiente = nuevo; // el nodo se apunta a sí mismo
            cola = nuevo;
        }
        else {
            nuevo->siguiente = cola->siguiente; // nuevo->sig = cabeza
            cola->siguiente = nuevo;            // la vieja cola ahora apunta al nuevo
            cola = nuevo;                       // nuevo es la nueva cola
        }
        cantidad++;
    }

    void RotacionCircular::insertarAlInicio(const string& nombre) {
        NodoLocutor* nuevo = new NodoLocutor(nombre);
        if (cola == nullptr) {
            nuevo->siguiente = nuevo;
            cola = nuevo;
        }
        else {
            nuevo->siguiente = cola->siguiente; // nuevo->sig = vieja cabeza
            cola->siguiente = nuevo;            // cola ahora apunta al nuevo (nueva cabeza)
            // cola no cambia: solo cambió quién es la cabeza
        }
        cantidad++;
    }


    bool RotacionCircular::insertarDespuesDe(const string& referencia, const string& nuevo_nombre) {
        if (cola == nullptr) { return false; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        do {
            if (actual->nombre == referencia) {
                NodoLocutor* nuevo = new NodoLocutor(nuevo_nombre);
                nuevo->siguiente = actual->siguiente;
                actual->siguiente = nuevo;
                if (actual == cola) cola = nuevo; // si era la cola, el nuevo es la nueva cola
                cantidad++;
                return true;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return false;
    }

    bool RotacionCircular::existeLocutor(const string& nombre) const
    {
            if (cola == nullptr) {
                return false;
            }

            // Obtenemos el punto de inicio (la cabeza)
            NodoLocutor* cabeza = getCabeza();
            NodoLocutor* actual = cabeza;

            // Recorremos la lista circular
            do {
                if (actual->nombre == nombre) {
                    return true;
                }
                actual = actual->siguiente;
            } while (actual != cabeza); // El ciclo termina cuando volvemos al inicio

            // Si terminamos el recorrido sin exito, el locutor no está en la rotacin
        return false;
    }

    int RotacionCircular::obtenerPosicion(const string& nombre) const {
        if (cola == nullptr) { return -1; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        int pos = 0;
        do {
            if (actual->nombre == nombre) { return pos; }
            actual = actual->siguiente;
            pos++;
        } while (actual != cabeza);
        return -1;
    }

    string RotacionCircular::turnoActual() const {
        if (cola == nullptr) { return ""; }
        return getCabeza()->nombre;
    }

    bool RotacionCircular::eliminarLocutor(const string& nombre) {
        if (cola == nullptr) { return false; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        NodoLocutor* previo = cola; // el recorrido circular comienza con previo = cola
        do {
            if (actual->nombre == nombre) {
                if (actual == cola && actual == cabeza) {
                    // único nodo en la lista
                    cola = nullptr;
                }
                else {
                    previo->siguiente = actual->siguiente; // saltar al actual
                    if (actual == cola) cola = previo;     // si era la cola, actualizar
                }
                delete actual;
                actual = nullptr;
                cantidad--;
                return true;
            }
            previo = actual;
            actual = actual->siguiente;
        } while (actual != cabeza);
        return false;
    }

    bool RotacionCircular::eliminarTurnoActual() {
        if (cola == nullptr) { return false; }
        // La cabeza es quien tiene el turno actual
        return eliminarLocutor(getCabeza()->nombre);
    }


    string RotacionCircular::siguiente() {
        if (cola == nullptr) { return ""; }

        cola = cola->siguiente;
        NodoLocutor* actual = getCabeza();//para que identifique quien trien el turno

        actual->turnosAsignados++;

        return actual->nombre;
    }

    void RotacionCircular::simularTurnos(int n) {
        if (cola == nullptr) { cout << "Sin locutores en rotacion." << endl; return; }
        for (int i = 1; i <= n; i++) {
            cout << "Turno " << i << ": " << siguiente() << endl;
        }
    }

    void RotacionCircular::imprimirRotacion() const {
        if (cola == nullptr) { cout << "Rotacion vacia." << endl; return; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        cout << "Rotacion: ";
        do {
            cout << actual->nombre;
            actual = actual->siguiente;
            if (actual != cabeza) { cout << " -> "; }
        } while (actual != cabeza);
        cout << " -> (inicio)" << endl;
    }

    int  RotacionCircular::getCantidad() const { return cantidad; }
    bool RotacionCircular::estaVacia()  const { return cola == nullptr; }


  
    void RotacionCircular::imprimirEstadisticas() const {
        if (cola == nullptr) {
            cout << "No hay locutores para mostrar estadisticas." << endl;
            return;
        }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        cout << "--- Estadisticas de Turnos ---" << endl;
        do {
            cout << "Locutor: " << actual->nombre
                << " | Turnos: " << actual->turnosAsignados << endl;
            actual = actual->siguiente;
        } while (actual != cabeza);
    }
   

    string RotacionCircular::locutorMasActivo() const {//camvios
        if (cola == nullptr) return "";

        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        NodoLocutor* masActivo = cabeza;

        do {
            if (actual->turnosAsignados > masActivo->turnosAsignados) {
                masActivo = actual;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);

        return masActivo->nombre;
    }





} // namespace EIF201