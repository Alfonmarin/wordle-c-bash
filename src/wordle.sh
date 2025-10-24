#!/bin/bash

construir() {
    # compilar archivos fuente y crear objetos
    gcc -c -Wall -Wextra -Werror -ansi -pedantic -I../lib/include *.c
    
    if [ $? -eq 0 ]; then

        gcc *.o -L../lib -lwordle -o wordle

        if [ $? -eq 0 ]; then

            return 0
        else
            echo "error al linkar objetos. Compilación fallida."
            return 1
        fi
    else
        echo "Error al compilar archivos fuente. Compilación fallida."
        return 1
    fi
}

jugar() {
    if [ -x "./wordle" ]; then

        export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib

        ./wordle ../data/dicES5.dat fich_log j
        return $?
    else
        echo "Construye primero el ejecutable"
        return 1
    fi
}

probar() {
    if [ -x "./wordle" ]; then

        export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib


        ./wordle ../data/dicTest.dat fich_log t
        return $?
    else
        echo "Construye primero el ejecutable"
        return 1
    fi
}


limpiar() {
    # Elimino el ejecutable si existe
    if [ -f "./wordle" ]; then
        rm -f ./wordle

    else
        echo "No se encontro el ejecutable"
    fi

    # Eliminar todos los archivos objeto 
    rm -f ./*.o
    echo "Archivos objeto eliminados"


    return 0
}



if [ $# -eq 1 ]; then
    if [ "$1" == "construir" ]; then
        construir
        exit $?
    elif [ "$1" == "jugar" ]; then
        jugar
        exit $?
    elif [ "$1" == "probar" ]; then
        probar
        exit $?
    elif [ "$1" == "limpiar" ]; then
        limpiar
        exit $?
    else

        exit 1
    fi
else
    echo "Número incorrecto de argumentos"
    exit 1
fi
