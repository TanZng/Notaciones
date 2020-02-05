#ifndef POSFIJA_H
#define POSFIJA_H

#include <string>

#include "pila_ligada.h"

std::string in2pos(std::string infija);

int evaluar(std::string posfija);


bool esNumero( char p ){
    bool regresar = false;
    if (p == '0' or p == '1' or p == '2' or p == '3' or p == '4' or
        p == '5' or p == '6' or p == '7' or p == '8' or p == '9')
        regresar = true;
    return regresar;
}

bool esOperador( char p ){
    bool regresar = false;
    if ( p=='*' or p=='/' or p=='+' or p=='-')
        regresar = true;
    return  regresar;
}

void casoA( int token, std::string &salida ){
    salida += token;
    salida += " ";
}

void casoB( int token, Pila<char> &pila){
    pila.push(token);
}

void casoC( Pila<char> &pila, std::string &salida ){
    while( pila.top() != '('){
        if( esOperador( pila.top() ) ){
            salida += pila.top();
            salida += " ";
        }
        pila.pop();
    }
    pila.pop();
}

void casoD( char p, Pila<char> &pilaops, std::string &salida){
    if( pilaops.top() == p or pilaops.top() == '*'){
        while( pilaops.top() == p or pilaops.top() == '*' or pilaops.top() == '/' ){
            salida += pilaops.top();
            salida += " ";
            pilaops.pop();
        }
    }
    pilaops.push(p);
}

std::string in2pos( std::string infija ) {
    std::string salida = "";
    Pila<char> pilaops;

    for( int i = 0; i < infija.length(); i++){
        if ( esNumero(infija[i]) ){
            casoA( infija[i], salida);
        }
        else if ( infija[i] == '(' ){
            casoB( infija[i], pilaops);
        }
        else if ( infija[i] == ')'  ){
            casoC( pilaops, salida );
        }
        else if ( esOperador( infija[i] ) ){
            casoD( infija[i], pilaops, salida );
        }
    }

    return salida;
}

void realizarOperaciones( Pila<int> &pilaoperandos, char p){
    //El primer pop es el segundo operando(b)y el segundo pop es el primero (a)
    // a + b
    int res;
    int b = pilaoperandos.top();
    pilaoperandos.pop();
    int a = pilaoperandos.top();
    pilaoperandos.pop();

    switch(p) //donde opción es la variable a comparar
    {
        case '+': res = a + b;
            break;
        case '-': res = a - b;
            break;
        case '*': res = a * b;
            break;
        case '/': res = a / b;
            break;
    }
    pilaoperandos.push(res);
}

int evaluar(std::string posfija) {
    Pila<int> pilaoperandos;
    for ( int i = 0; i < posfija.length(); i++){
        if ( esNumero(posfija[i]) ){
            pilaoperandos.push(posfija[i] - '0');
        }
        else if ( esOperador(posfija[i])){
            realizarOperaciones( pilaoperandos, posfija[i]);
        }
    }
    return pilaoperandos.top();
}

#endif
