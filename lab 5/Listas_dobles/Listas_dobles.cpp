#include "HistorialDoble.h"
#include "RotacionCircular.h"
using namespace EIF201;

int main() {

    // MÓDULO A – HistorialDoble
    cout << "\nMODULO A: HistorialDobl" << endl;
    {
        HistorialDoble h;

        // Inserción
        h.insertarAlFinal("rock1");
        h.insertarAlFinal("pop7");
        h.insertarAlFinal("jazz3");
        h.insertarAlInicio("clas5");
        h.insertarEnPosicion("folk2", 2);
        h.insertarAntesDe("jazz3", "bosa1");
        h.insertarDespuesDe("pop7", "soul4");
        h.imprimirCronologico();
        // Esperado: clas5 <-> rock1 <-> folk2 <-> pop7 <-> soul4 <-> bosa1 <-> jazz3
        h.imprimirInverso();
        // Esperado: jazz3 <-> bosa1 <-> soul4 <-> pop7 <-> folk2 <-> rock1 <-> clas5

        // Búsqueda
        cout << "Posicion jazz3:      " << h.obtenerPosicion("jazz3") << endl; // 6
        cout << "Cancion en pos 0:    " << h.obtenerEnPosicion(0) << endl; // clas5
        cout << "jazz3 existe:        " << (h.existeCancion("jazz3") ? "si" : "no") << endl; // si
        cout << "Pos desde final pop7: " << h.obtenerPosicionDesdeElFinal("pop7") << endl; // 3

        // Eliminación
        h.eliminarPrimera("bosa1");
        h.eliminarCabeza();
        h.eliminarCola();
        h.eliminarEnPosicion(1);
        h.eliminarUltima("pop7");
        h.imprimirCronologico();
        // Esperado: rock1 <-> soul4
        cout << "Cantidad: " << h.getCantidad() << endl; // 2
    } // destructor libera rock1 y soul4


    // MÓDULO B – RotacionCircular
    cout << "\nMODULO B: RotacionCircular" << endl;
    {
        RotacionCircular r;

        // Inserción
        r.insertarAlFinal("Maria");
        r.insertarAlFinal("Carlos");
        r.insertarAlFinal("Adriana");
        r.insertarAlInicio("Diego");
        r.insertarDespuesDe("Carlos", "Elena");
        r.imprimirRotacion();
        // Esperado: Diego -> Maria -> Carlos -> Elena -> Adriana -> (inicio)

        // Buqueda
        cout << "Carlos existe:    " << (r.existeLocutor("Carlos") ? "si" : "no") << endl; // si
        cout << "Posicion Carlos:  " << r.obtenerPosicion("Carlos") << endl; // 2
        cout << "Turno actual:     " << r.turnoActual() << endl; // Diego

        // Rotación
        r.simularTurnos(7);
        // Esperado: Maria, Carlos, Elena, Adriana, Diego, Maria, Carlos

        // Eliminación
        r.eliminarLocutor("Carlos");
        r.eliminarTurnoActual();
        r.imprimirRotacion();
        // Rotacion actualizada sin Carlos ni el locutor activo al momento
        cout << "Cantidad: " << r.getCantidad() << endl;

        // Caso extremo: lista con un solo locutor
        r.eliminarLocutor("Adriana");
        while (!r.estaVacia()) r.eliminarTurnoActual();
        cout << "Vacia: " << (r.estaVacia() ? "si" : "no") << endl; // si
        cout << "Siguiente vacia: '" << r.siguiente() << "'" << endl; // ''
    }

    return 0;
}