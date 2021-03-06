#pragma once
#include "Scrabble.h"
#include <fstream>
#include <iostream>

class ScrabbleMD
{
protected:
    /*
        PROPIEDADES
    */
    Scrabble* root;
    Scrabble* ultimoDerecho;
    Scrabble* ultimoAbajo;

public:
    ScrabbleMD();
    Scrabble* BuscarFila(int posicionY);
    Scrabble* BuscarColumna(int posicionX);
    Scrabble* BuscarLetra(int posicionX, int posicionY);
    Scrabble* AgregarFila(Scrabble* scrabble, Scrabble* scrabbleFila);
    Scrabble* AgregarColumna(Scrabble* scrabble, Scrabble* scrabbleColumna);
    Scrabble* CrearFila(int posicionY);
    Scrabble* CrearColumna(int posicionX);
    void Agregar(string dato, int puntos, int posicionX, int posicionY, bool esDoble, bool esTriple);
    void Eliminar(int posicionX, int posicionY);
    void GenerarGrafico(string nombre);
};

