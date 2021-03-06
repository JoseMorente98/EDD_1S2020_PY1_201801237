#include "ApartadoLD.h"
#include <iostream>
#include <windows.h>

int ApartadoLD::longitudDoble = 0;
int ApartadoLD::longitudTriple = 0;
ApartadoLD* ApartadoLD::instancia = NULL;

ApartadoLD::ApartadoLD()
{
	this->primero = NULL;
	this->ultimo = NULL;
	this->primeroTriple = NULL;
	this->ultimoTriple = NULL;
}

ApartadoLD* ApartadoLD::Instancia()
{
	if (instancia == NULL)
	{
		instancia = new ApartadoLD();
	}
	return instancia;
}

void ApartadoLD::AgregarDoble(int posicionX, int posicionY, bool esDoble, bool esTriple)
{
	Apartado* apartado = new Apartado(posicionX, posicionY, esDoble, esTriple);

	if (primero == NULL) {
		primero = apartado;
		primero->setSiguiente(NULL);
		primero->setAnterior(NULL);
		ultimo = primero;
	}
	else {
		ultimo->setSiguiente(apartado);
		apartado->setSiguiente(NULL);
		apartado->setAnterior(ultimo);
		ultimo = apartado;
	}
	this->longitudDoble++;
}

void ApartadoLD::AgregarTriple(int posicionX, int posicionY, bool esDoble, bool esTriple)
{
	Apartado* apartado = new Apartado(posicionX, posicionY, esDoble, esTriple);

	if (primeroTriple == NULL) {
		primeroTriple = apartado;
		primeroTriple->setSiguiente(NULL);
		primeroTriple->setAnterior(NULL);
		ultimoTriple = primeroTriple;
	}
	else {
		ultimoTriple->setSiguiente(apartado);
		apartado->setSiguiente(NULL);
		apartado->setAnterior(ultimoTriple);
		ultimoTriple = apartado;
	}
	this->longitudTriple++;
}

bool ApartadoLD::ValidarDoble(int posicionX, int posicionY)
{
	Apartado* temp;
	temp = primero;
	while (temp != NULL)
	{
		if (temp->getPosicionX() == posicionX && temp->getPosicionY() == posicionY) {
			return true;
		}
		temp = temp->getSiguiente();
	}
	return false;
}

bool ApartadoLD::ValidarTriple(int posicionX, int posicionY)
{
	Apartado* temp;
	temp = primeroTriple;
	while (temp != NULL)
	{
		if (temp->getPosicionX() == posicionX && temp->getPosicionY() == posicionY) {
			return true;
		}
		temp = temp->getSiguiente();
	}
	return false;
}

void ApartadoLD::LimpiarDoble()
{
	this->primero = NULL;
}

void ApartadoLD::LimpiarTriple()
{
	this->primeroTriple = NULL;
}

void ApartadoLD::MostrarDoble()
{
	if (primero != NULL) {
		Apartado* temp = primero;
		while (temp != NULL)
		{
			std::cout << "Coordenadas: (" << temp->getPosicionX() << "," << temp->getPosicionY() << ")\n";
			temp = temp->getSiguiente();
		}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "La lista se encuentra vac�a. \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	}
}
void ApartadoLD::MostrarTriple()
{
	if (primero != NULL) {
		Apartado* temp = primeroTriple;
		while (temp != NULL)
		{
			std::cout << "Coordenadas: (" << temp->getPosicionX() << "," << temp->getPosicionY() << ")\n";
			temp = temp->getSiguiente();
		}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "La lista se encuentra vac�a. \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	}
}

int ApartadoLD::getMatriz() const
{
	return matriz;
}

void ApartadoLD::setMatriz(int matriz)
{
	this->matriz = matriz;
}
