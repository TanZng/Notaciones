template <typename E>
class Nodo {
public:
    Nodo();
    E elemento;
    Nodo<E> *siguiente;
};


template <typename E>
Nodo<E>::Nodo() {
    siguiente = NULL;
}
