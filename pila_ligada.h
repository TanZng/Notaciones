#include <string>

#include "nodo.h"


class RuntimeException {
public:
    RuntimeException(const std::string& err) {
        errorMsg = "Error: " + err + "\n";
    }
    
    std::string getMessage() const {
        return errorMsg;
    }
    
private:
    std::string errorMsg;
};


class StackEmptyException : public RuntimeException {
public:
    StackEmptyException(const std::string& err)
    : RuntimeException(err) { }
};


class StackFullException : public RuntimeException {
public:
    StackFullException(const std::string& err)
    : RuntimeException(err) { }
};


template <typename E>
class Pila {
public:
    Pila();
    ~Pila();
    void push(E x) throw(StackFullException);
    void pop() throw(StackEmptyException);
    E top() const throw(StackEmptyException);
    bool esVacia() const;
    int tamaño() const;
    std::string aTexto() const;
    void invertir();
    void push(Pila<E> &s) throw(StackFullException);
    void pop(int k) throw(StackEmptyException);

private:
    Nodo<E> *tope;
    int numElementos;
};


template <typename E>
Pila<E>::Pila() {
    tope = NULL;
    numElementos = 0;
}


template <typename E>
Pila<E>::~Pila() {
    while (!esVacia())
        pop();
}


template <typename E>
void Pila<E>::push(E x) throw(StackFullException){
    Nodo<E>* nuevo = new Nodo<E>();
    nuevo->elemento = x;
    nuevo->siguiente = tope;
    tope = nuevo;
    numElementos += 1;
}


template <typename E>
void Pila<E>::pop() throw(StackEmptyException) {
    if (esVacia())
        throw StackEmptyException("Eliminando de una pila vacía");
    Nodo<E> *p = tope;
    tope = p->siguiente;
    delete p;
    numElementos -= 1;
}


template <typename E>
E Pila<E>::top() const throw(StackEmptyException) {
    if (esVacia())
        throw StackEmptyException("Solicitando el tope de una pila vacía");
    return tope->elemento;
}


template <typename E>
bool Pila<E>::esVacia() const {
    return (tope == NULL);
}


template <typename E>
int Pila<E>::tamaño() const {
    return numElementos;
}


template <typename E>
std::string Pila<E>::aTexto() const {
    std::string pila = "[";
    Nodo<E> *p = tope;
    while (p != NULL) {
        pila += std::to_string(p->elemento) + ", ";
        p = p->siguiente;
    }
    if (!esVacia())
        pila += "\b\b";
    pila += "]";
    return pila;
}


template <typename E>
void Pila<E>::invertir() {
    if (!esVacia()) {
        Nodo<E>* p = tope;
        tope = NULL;
        while (p != NULL) {
            Nodo<E>* aux = p;
            p = p->siguiente;
            aux->siguiente = tope;
            tope = aux;
        }
    }
}


template <typename E>
void Pila<E>::pop(int k) throw(StackEmptyException) {
    if (esVacia())
        throw StackEmptyException("Eliminando de una pila vacía");
    while (k > 0 && !esVacia()) {
        Nodo<E> *p = tope;
        tope = p->siguiente;
        delete p;
        numElementos -= 1;
        k--;
    }
}


template <typename E>
void Pila<E>::push(Pila<E> &s) throw(StackFullException){
    if (!s.esVacia()) {
        Pila<E> aux;
        while (!s.esVacia()) {
            aux.push(s.top());
            s.pop();
        }
        while (!aux.esVacia()) {
            push(aux.top());
            aux.pop();
        }
    }
}
