#ifndef NODO_LOCUTOR_H
#define NODO_LOCUTOR_H

#include <iostream>
#include <string>

using namespace std;

namespace EIF201 {

    struct NodoLocutor {
        string       nombre;
        NodoLocutor* siguiente; // en la lista circular, el último apunta al primero

        NodoLocutor(const string& n)
            : nombre(n), siguiente(nullptr) {
            cout << "[NodoLocutor creado: " << n << "]" << endl;
        }

        ~NodoLocutor() {
            cout << "[NodoLocutor destruido: " << nombre << "]" << endl;
        }
    };

} // namespace EIF201

#endif // NODO_LOCUTOR_H

