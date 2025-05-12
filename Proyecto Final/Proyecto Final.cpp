// Sistema de combate por turnos en C++ estándar
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

// Clase que representa un personaje en el combate
class Personaje {
public:
    // Atributos: nombre, vida (HP) y ataque (daño fijo)
    string nombre;
    int vida;
    int ataque;
    int ataqueCritico;

    // Constructor que inicializa los atributos del personaje
    Personaje(string n, int v, int a) : nombre(n), vida(v), ataque(a) {}

    // Verifica si el personaje sigue vivo
    bool estaVivo() {
        return vida > 0;
    }

    int ataque(Personaje &Danio)
    {
        ataqueCritico= rand() % 100;
    }


    // Función para atacar a otro personaje
    void atacar(Personaje& objetivo) { //Personaje se llama a si mismo para poder saber que información. Es el Consultor.  
        //Objetivo es el nombre para poder usarlo(La variable tipo personaje)
        // & Se usa para hacer una refrencia directa. Para poder modificarlo afuera de la clase
        
        // Mostrar mensaje del ataque
        cout << nombre << " ataca a " << objetivo.nombre << " causando " << ataque << " de daño.\n";

        // Restar el ataque a la vida del objetivo
        objetivo.vida -= ataque;

        // Prevenir que la vida quede en negativo
        if (objetivo.vida < 0) objetivo.vida = 0;

        // Mostrar vida restante del objetivo
        cout << objetivo.nombre << " ahora tiene " << objetivo.vida << " de vida.\n\n";
    }

};

int main() {
    // Inicializar generador aleatorio con la hora actual
    srand(time(0));

    // Crear los personajes usando el constructor
    Personaje jugador("Jugador", 100, 20);
    Personaje enemigo("Enemigo", 80, 15);

    int turno = 1;

    cout << "¡Comienza el combate!\n\n";

    // Bucle que continúa mientras ambos personajes estén vivos
    while (jugador.estaVivo() && enemigo.estaVivo()) {
        cout << "Turno " << turno << ":\n";

        // Turno del jugador
        jugador.atacar(enemigo);
        if (!enemigo.estaVivo()) break;  // Salir si el enemigo muere

        // Turno del enemigo
        enemigo.atacar(jugador);
        if (!jugador.estaVivo()) break;  // Salir si el jugador muere

        turno++;
        system("Pause");
        cout << "\n";
    }

    system("Pause");

    // Mostrar resultado final
    cout << "Fin del combate.\n";
    if (jugador.estaVivo()) {
        cout << jugador.nombre << " ha ganado.\n";
    }
    else {
        cout << enemigo.nombre << " ha ganado.\n";
    }

    return 0;
}
