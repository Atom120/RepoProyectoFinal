// CombateP00.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Sebastián Selvas García

#include <iostream>
#include <stdlib.h>   // para usar rand
#include <locale.h>   // Para poder cambiar el idioma y usar ñ
#include <time.h>

using namespace std;
// --- Declaración adelantada necesaria ---
class Enemigo;

class Personaje {
private:
    int vida;
    int defensa;
    int ataque;
    int ataqueRecibido;
    int critico;

public:
    std::string nombre;

    Personaje() {
        vida = AleatorizarEstadisticas(150, 200);
        defensa = AleatorizarEstadisticas(5, 20);
        ataque = AleatorizarEstadisticas(50, 100);
    }

    Personaje(int Vmin_, int Vmax_, int Dmin_, int Dmax_, int Amin_, int Amax_) {//Se va ausar para el equipo
        vida = AleatorizarEstadisticas(Vmin_, Vmax_);
        defensa = AleatorizarEstadisticas(Dmin_, Dmax_);
        ataque = AleatorizarEstadisticas(Amin_, Amax_);
    }

    int AleatorizarEstadisticas(int _minimo, int _maximo) {
        return _minimo + rand() % (_maximo - _minimo + 1);
    }

    void pedirNombre() {
        std::cout << "Ingrese el nombre del peleador" << std::endl;
        std::cin >> nombre;
        system("cls");
    }

    void MostrarStats() {
        std::cout << "\n---- Estado actual del jugador ----" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Vida: " << vida << std::endl;
        std::cout << "Defensa: " << defensa << std::endl;
        std::cout << "Ataque: " << ataque << std::endl;
    }

    void atacar(Enemigo& objetivo);//Porotipo declarado en Enemigo. Si la declaramos aun no conoce al objetivo

    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }
    int getDefensa() { return defensa; }
    std::string getNombre() { return nombre; }
};

// --- Clase Enemigo completa ---
class Enemigo {
private:
    int vida;
    int defensa;
    int ataque;

public:
    std::string nombre;

    Enemigo() {
        vida = AleatorizarEstadisticas(150, 200);
        defensa = AleatorizarEstadisticas(5, 20);
        ataque = AleatorizarEstadisticas(50, 55);
    }

    Enemigo(int Vmin_, int Vmax_,int Dmin_, int Dmax_,int Amin_, int Amax_) {//Se va ausar para el equipo
        vida = AleatorizarEstadisticas(Vmin_, Vmax_);
        defensa = AleatorizarEstadisticas(Dmin_, Dmax_);
        ataque = AleatorizarEstadisticas(Amin_, Amax_);
    }

    int AleatorizarEstadisticas(int _minimo, int _maximo) {
        return _minimo + rand() % (_maximo - _minimo + 1);
    }

    void pedirNombre() {
        std::cout << "Ingrese el nombre del peleador" << std::endl;
        std::cin >> nombre;
        system("cls");
    }

    void MostrarStats() {
        std::cout << "\n---- Estado actual del enemigo ----" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Vida: " << vida << std::endl;
        std::cout << "Defensa: " << defensa << std::endl;
        std::cout << "Ataque: " << ataque << std::endl << std::endl;
    }

    void atacar(Personaje& objetivo) {

        int critico = AleatorizarEstadisticas(1, 100);
        int danio = ataque - objetivo.getDefensa();
        if (danio < 0) danio = 0;

        bool esCritico = false;

        if (critico >= 95) {
            danio *= 2;
            std::cout << "DAÑO CRÍTICO: " << danio << std::endl << endl;
            esCritico = true;
        }

        objetivo.setVida(objetivo.getVida() - danio);
        if (esCritico)
        {
            std::cout << nombre << " ha atacado a " << objetivo.getNombre()
                << " causando " << danio << " ¡Daño Critico!.\n" << endl;
        }
        else {
            std::cout << nombre << " ha atacado a " << objetivo.getNombre()
                << " causando " << danio << " daño.\n" << endl;
        }
    }

    void elecciónJugador()
    {
        int opcion;

        switch (opcion)
        {
        case 1:


            break;

        default:
            break;
        }

    }

    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }
    int getDefensa() { return defensa; }
    std::string getNombre() { return nombre; }
};

// --- Implementación de ataque después de definir Enemigo ---
void Personaje::atacar(Enemigo& objetivo) {

     int critico = AleatorizarEstadisticas(1, 100);
     int danio = ataque - objetivo.getDefensa();
     if (danio < 0) danio = 0;

     bool esCritico = false;

     if (critico >= 95) {
        danio *= 2;
        std::cout << "DAÑO CRÍTICO: " << danio << std::endl << endl;
        esCritico = true;
     }

     objetivo.setVida(objetivo.getVida() - danio);
     if (esCritico)
     {
         std::cout << nombre << " ha atacado a " << objetivo.getNombre()
             << " causando " << danio << " ¡Daño Critico!.\n" << endl;
     }
     else {
         std::cout << nombre << " ha atacado a " << objetivo.getNombre()
             << " causando " << danio << " daño.\n" << endl;
     }
}

int main() {
    srand(time(0)); // Inicializar la semilla aleatoria solo una vez
    std::locale::global(std::locale("es_ES.UTF-8")); // Para ñ y acentos

    Personaje jugador;
    Enemigo enemigo;

    jugador.pedirNombre();
    enemigo.pedirNombre();

    int i = 0;
    do {
        i += 1;
        std::cout << "----Turno " << i << "----" << std::endl;

        jugador.MostrarStats();
        enemigo.MostrarStats();
        jugador.atacar(enemigo);
        enemigo.atacar(jugador);

        system("pause");
        system("cls");

      
    } while (jugador.getVida() > 0 && enemigo.getVida() > 0);

    std::cout << std::endl << "¡Fin del combate!";

    if (jugador.getVida() <= 0 && enemigo.getVida() > 0) {
        std::cout << "\n¡" << enemigo.nombre << " ha ganado el combate!" << std::endl;
    }
    else if (enemigo.getVida() <= 0 && jugador.getVida() > 0) {
        std::cout << "\n¡" << jugador.nombre << " ha ganado el combate!" << std::endl;
    }
    else {
        std::cout << "\n¡Empate! Ambos han caído." << std::endl;
    }


    return 0;
}
