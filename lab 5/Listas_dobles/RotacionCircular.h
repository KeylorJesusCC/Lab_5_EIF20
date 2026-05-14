#ifndef ROTACION_CIRCULAR_H
#define ROTACION_CIRCULAR_H

#include "NodoLocutor.h"

namespace EIF201 {

    class RotacionCircular {
    private:
        NodoLocutor* cola; // invariante: cola->siguiente == cabeza (si no es nullptr)
        int          cantidad;

        // Método auxiliar privado: retorna la cabeza de forma segura
        NodoLocutor* getCabeza() const;

    public:
        RotacionCircular();
        ~RotacionCircular();

        // Inserción
        // Incorpora un locutor al final de la rotación (antes de la cabeza)
        void insertarAlFinal(const string& nombre);

        // Incorpora un locutor al inicio (se convierte en la nueva cabeza)
        void insertarAlInicio(const string& nombre);

        // Inserta un nuevo locutor justo después del locutor de referencia.
        // Retorna false si la referencia no existe.
        bool insertarDespuesDe(const string& referencia, const string& nuevo_nombre);

        // Busqueda
        // Verifica si un locutor está en la rotación.
        bool existeLocutor(const string& nombre) const;// la implementamos nosotros

        // Retorna la posición (0-indexed desde la cabeza). -1 si no existe.
        int obtenerPosicion(const string& nombre) const;

        // Retorna el nombre del locutor que tiene el turno actual (cabeza).
        string turnoActual() const;

        // eliminación
        // Elimina un locutor de la rotación por nombre.
        bool eliminarLocutor(const string& nombre);

        // Elimina al locutor que tiene el turno actual (la cabeza).
        bool eliminarTurnoActual();

        // Rotación y recorrido
        // Avanza al siguiente turno y retorna el nombre del nuevo turno activo.
        string siguiente();

        // Simula n turnos imprimiendo qué locutor corresponde a cada uno.
        void simularTurnos(int n);

        // Imprime la rotación completa empezando desde la cabeza.
        void imprimirRotacion() const;

        int getCantidad() const;
        bool estaVacia()  const;
    
        void imprimirEstadisticas() const;//camvio
        string locutorMasActivo() const;//camvio
    };

} // namespace EIF201

#endif // ROTACION_CIRCULAR_H
