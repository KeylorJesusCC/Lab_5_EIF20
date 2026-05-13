#ifndef NODO_HISTORIAL
#define NODO_HISTORIAL

#include <iostream>
#include <string>

namespace EIF201 {

	using namespace std;
	struct NodoHistorial
	{
		string cancion; //identificador de la cacion
		NodoHistorial* siguiente; //apunta al nodo sucesor
		NodoHistorial* anterior; //apunta al nodo predecesor

		//constructor; inicializa el dato y ambos punteros en null ptr
		NodoHistorial(const string& c)
			:cancion(c), siguiente(nullptr), anterior(nullptr){cout << "[NodoHistoria creado: "<< c << "]" << endl;}

		~NodoHistorial() { cout << "[NodoHistorial creado: " << cancion << "]" << endl; }
	};
} //namespace EIF201
#endif //NODO_HISTORIAL_H