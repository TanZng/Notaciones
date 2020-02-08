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

void casoA( int token, std::string &salida){
    salida += token;
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
    while( pilaops.top() == p or pilaops.top() == '*' or pilaops.top() == '/' ){
        salida += pilaops.top();
        salida += " ";
        pilaops.pop();
    }
    pilaops.push(p);
}

std::string in2pos( std::string infija ) {
    std::string salida = "";
    Pila<char> pilaops;
    int i = 0;

    while( i < infija.length() ){
        if ( esNumero(infija[i]) ){
            while ( esNumero( infija[i] ) ){
                casoA( infija[i], salida);
                i ++;
            }
            i--;
            salida += ' ';
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
        i++;
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
    std::string numero;
    Pila<int> pilaoperandos;
    int i = 0;
    while ( i < posfija.length()){
        if ( esNumero(posfija[i]) ){
            numero = "";
            while( posfija[i] != ' ' ){
                numero += posfija[i];
                i ++;
            }
            int num = std::stoi(numero);
            pilaoperandos.push(num );
        }
        else if ( esOperador(posfija[i])){
            realizarOperaciones( pilaoperandos, posfija[i]);
        }
        i++;
    }
    return pilaoperandos.top();
}

#endif
