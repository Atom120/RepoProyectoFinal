// Proyecto Final.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Sebastián Selvas García

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Personaje
{
private:
    int vida;
    int defensa;
    int velocidad;
    int ataque;
    int ataqueEspecial;

public:
    Personaje()
    {
        vida = 100;
        defensa = 0;
        velocidad = 100;
        ataque = 0;
        ataqueEspecial = 0;
    }


    void Tanque()
    {
        vida = vida * 2;
        defensa = 30;
        velocidad = 100;
        ataque = 15;
        ataqueEspecial;
    }
};



class enemigo
{
private:
    std::string nombreEnemigo;
    vector<string> NombresPosiblesEnemigo = { "Orco", "Goblin", "Esqueleto", "Troll", "Bandido", "Lobo" };



};
class arma
{
private:
    int ataque;
public:
    arma()
    {
        ataque = 0;
    }
};

class aramadura
{

};

int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
