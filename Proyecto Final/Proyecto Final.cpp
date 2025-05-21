// CombateP00.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Sebastián Selvas García

#include <iostream>
#include <stdlib.h>   // para usar rand
#include <locale.h>   // Para poder cambiar el idioma y usar ñ
#include <time.h>
#include <vector>

using namespace std;


// --- Declaración adelantada necesaria ---
class Enemigo;
class Aliados;  // 👈 Esto le dice al compilador que Aliados existirá


class Personaje {
protected:

    int vida;
    int defensa;
    int ataque;
    int velocidad;
    int peso;

public:
    std::string nombre;

    Personaje() {
        vida = AleatorizarEstadisticas(150, 200);
        defensa = AleatorizarEstadisticas(5, 20);
        ataque = AleatorizarEstadisticas(50, 100);
        velocidad = AleatorizarEstadisticas(10, 30);
    }

    int AleatorizarEstadisticas(int _minimo, int _maximo) {//Me ayudo mi compañero Jorge
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
        std::cout << "Velocidad: " << velocidad << std::endl << std::endl;

    }

    void hablidiades()
    {
        int opcion;

        cout << "Que habilidad quiere usar?";
        cin >> opcion;
    }

    void eleccionJugador(Personaje& jugador, Enemigo& enemigo);

    void atacar(Enemigo& objetivo);

    int getPeso() { return peso; }
    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }
    int getDefensa() { return defensa; }
    int getVelocidad() { return velocidad; }
    std::string getNombre() { return nombre; }

};

class Aliados:Personaje
{
private:
    string Nombre;
    int vida;
    int defensa;
    int ataque;
    int velocidad;
    int peso;

public:
    std::string nombre;

    Aliados(string _nombre, int Vmin_, int Vmax_, int Dmin_, int Dmax_, int Amin_, int Amax_,int velmin, int velmax) {
        nombre = _nombre;
        vida = AleatorizarEstadisticas(Vmin_, Vmax_);
        defensa = AleatorizarEstadisticas(Dmin_, Dmax_);
        ataque = AleatorizarEstadisticas(Amin_, Amax_);
        velocidad = AleatorizarEstadisticas(velmin, velmax);
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
        std::cout << "Velocidad: " << velocidad << std::endl << std::endl;

    }

    void hablidiades()
    {
        int opcion;

        cout << "Que habilidad quiere usar?";
        cin >> opcion;
    }

    void atacarAliados(Enemigo& objetivo);

    void eleccionAliados(Aliados& _aliados, Enemigo& enemigo);

    int getPeso() { return peso; }
    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }
    int getDefensa() { return defensa; }
    int getVelocidad() { return velocidad; }
    std::string getNombre() { return nombre; }

};

class Enemigo {
private:
    int vida;
    int defensa;
    int ataque;
    int velocidad;
    //string nomEnemigo;
    vector<string> nomEnemigoPosible = { "Esqueleto", "Pepsi", "Soda" };

public:
    std::string nombre;

    Enemigo() {
        vida = AleatorizarEstadisticas(250, 300);
        defensa = AleatorizarEstadisticas(5, 20);
        ataque = AleatorizarEstadisticas(50, 55);
        velocidad = AleatorizarEstadisticas(20, 25);

        nombre = nomEnemigoPosible[rand() % nomEnemigoPosible.size()];
    }

    Enemigo(int Vmin_, int Vmax_, int Dmin_, int Dmax_, int Amin_, int Amax_) {
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
        std::cout << "Ataque: " << ataque << std::endl;
        std::cout << "Velocidad: " << velocidad << std::endl << std::endl;

    }

    void atacarEnemigo(Personaje& objetivo, Aliados& _aliadoMago, Aliados& _aliadoTanque, Aliados& _aliadoAsesino, Aliados& _aliadoSupport) {

        vector<Aliados> Vivos;

        int critico = AleatorizarEstadisticas(1, 100);
        int tamanioLista = AleatorizarEstadisticas(0, Vivos.size() + 1);
        Vivos.push_back(_aliadoMago);//0
        Vivos.push_back(_aliadoTanque);//1
        Vivos.push_back(_aliadoAsesino);//2
        Vivos.push_back(_aliadoSupport);//3


        bool esCritico = false;

        if (Vivos.size() == 0)//.size() solo me dice la cantidad de la lista. Si no hay nadie en la lsita se ataca al jugador
        {
            int danio = ataque - objetivo.getDefensa();
            if (danio < 0) danio = 0;

            cout << "\n---- Daño Enemigos ----\n\n";

            if (critico >= 95) {
                danio *= 2;
                std::cout << "DAÑO CRÍTICO: " << danio << std::endl << endl;
                esCritico = true;
            }

            objetivo.setVida(objetivo.getVida() - danio);
            if (esCritico)
                std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " ¡Daño Crítico!\n" << std::endl;
            else
                std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " daño.\n" << std::endl;
        }
        else
        {
            if (tamanioLista == 0)//Mago
            {
                int danioAliado = ataque - _aliadoMago.getDefensa();
                if (danioAliado < 0) danioAliado = 0;

                cout << "\n---- Daño Enemigos ----\n\n";

                if (critico >= 95)
                {
                    danioAliado *= 2;
                    std::cout << "DAÑO CRÍTICO: " << danioAliado << std::endl << endl;
                    esCritico = true;
                }

                _aliadoMago.setVida(_aliadoMago.getVida() - danioAliado);
                if (esCritico)
                    std::cout << nombre << ": ataca a " << _aliadoMago.getNombre() << " causando " << danioAliado << " ¡Daño Crítico!\n" << std::endl;
                else
                    std::cout << nombre << ": ataca a " << _aliadoMago.getNombre() << " causando " << danioAliado << " daño.\n" << std::endl;
            }
            else if (tamanioLista == 1)//Tanque
            {
                int danioAliado = ataque - _aliadoTanque.getDefensa();
                if (danioAliado < 0) danioAliado = 0;

                cout << "\n---- Daño Enemigos ----\n\n";

                if (critico >= 95)
                {
                    danioAliado *= 2;
                    std::cout << "DAÑO CRÍTICO: " << danioAliado << std::endl << endl;
                    esCritico = true;
                }

                _aliadoTanque.setVida(_aliadoTanque.getVida() - danioAliado);
                if (esCritico)
                    std::cout << nombre << ": ataca a " << _aliadoTanque.getNombre() << " causando " << danioAliado << " ¡Daño Crítico!\n" << std::endl;
                else
                    std::cout << nombre << ": ataca a " << _aliadoTanque.getNombre() << " causando " << danioAliado << " daño.\n" << std::endl;
            }
            else if (tamanioLista == 2)//Asesino
            {
                int danioAliado = ataque - _aliadoAsesino.getDefensa();
                if (danioAliado < 0) danioAliado = 0;

                cout << "\n---- Daño Enemigos ----\n\n";

                if (critico >= 95)
                {
                    danioAliado *= 2;
                    std::cout << "DAÑO CRÍTICO: " << danioAliado << std::endl << endl;
                    esCritico = true;
                }

                _aliadoAsesino.setVida(_aliadoAsesino.getVida() - danioAliado);
                if (esCritico)
                    std::cout << nombre << ": ataca a " << _aliadoAsesino.getNombre() << " causando " << danioAliado << " ¡Daño Crítico!\n" << std::endl;
                else
                    std::cout << nombre << ": ataca a " << _aliadoAsesino.getNombre() << " causando " << danioAliado << " daño.\n" << std::endl;
            }
            else if (tamanioLista - 1 == 3)//Support
            {
                int danioAliado = ataque - _aliadoSupport.getDefensa();
                if (danioAliado < 0) danioAliado = 0;

                cout << "\n---- Daño Enemigos ----\n\n";

                if (critico >= 95)
                {
                    danioAliado *= 2;
                    std::cout << "DAÑO CRÍTICO: " << danioAliado << std::endl << endl;
                    esCritico = true;
                }

                _aliadoSupport.setVida(_aliadoSupport.getVida() - danioAliado);
                if (esCritico)
                    std::cout << nombre << ": ataca a " << _aliadoSupport.getNombre() << " causando " << danioAliado << " ¡Daño Crítico!\n" << std::endl;
                else
                    std::cout << nombre << ": ataca a " << _aliadoSupport.getNombre() << " causando " << danioAliado << " daño.\n" << std::endl;
            }
        }
    };

    string getEnemigo() const {
        return nombre;
    }

    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }
    int getDefensa() { return defensa; }
    int getVelocidad() { return velocidad; }
    std::string getNombre() { return nombre; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//Aliados

void Aliados::eleccionAliados(Aliados& _aliados, Enemigo& enemigo)
{
    int opcion;

    cout << "Es el turno de " << _aliados.getNombre() << endl;

    std::cout << "\n--- Elige una acción ---\n";
    std::cout << "1. Atacar\n";
    std::cout << "2. Usar habilidad (en desarrollo)\n";
    std::cout << "3. Defender (en desarrollo)\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        _aliados.atacarAliados(enemigo);
        break;
    case 2:
        std::cout << _aliados.getNombre() << " intenta usar una habilidad especial (no implementada).\n";
        break;
    case 3:
        std::cout << _aliados.getNombre() << " se defiende (no implementado).\n";
        break;
    default:
        std::cout << "Opción no válida. Pierdes el turno.\n";
        break;
    }
    system("pause");
    system("cls");
}

void Aliados::atacarAliados(Enemigo& objetivo)
{
    int critico = AleatorizarEstadisticas(1, 100);
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;

    bool esCritico = false;

    cout << "\n---- Daño Aliados ----\n\n";

    if (critico >= 95) {
        danio *= 2;
        std::cout << "DAÑO CRÍTICO: " << danio << std::endl << endl;
        esCritico = true;
    }

    objetivo.setVida(objetivo.getVida() - danio);
    if (esCritico)
        std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " ¡Daño Crítico!\n" << std::endl;
    else
        std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " daño.\n" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//Personaje

void Personaje::atacar(Enemigo& objetivo) {
    int critico = AleatorizarEstadisticas(1, 100);
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;

    bool esCritico = false;
    Personaje jugador;

    cout << "\n---- Daño" << jugador.getNombre() << "----\n\n";

    if (critico >= 95) {
        danio *= 2;
        std::cout << "DAÑO CRÍTICO: " << danio << std::endl << endl;
        esCritico = true;
    }

    objetivo.setVida(objetivo.getVida() - danio);
    if (esCritico)
        std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " ¡Daño Crítico!\n" << std::endl;
    else
        std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " daño.\n" << std::endl;
}

void Personaje::eleccionJugador(Personaje& jugador, Enemigo& enemigo) {
    int opcion;

    std::cout << "\n--- Elige una acción ---\n";
    std::cout << "1. Atacar\n";
    std::cout << "2. Usar habilidad (en desarrollo)\n";
    std::cout << "3. Defender (en desarrollo)\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        jugador.atacar(enemigo);
        break;
    case 2:
        std::cout << jugador.getNombre() << " intenta usar una habilidad especial (no implementada).\n";
        break;
    case 3:
        std::cout << jugador.getNombre() << " se defiende (no implementado).\n";
        break;
    default:
        std::cout << "Opción no válida. Pierdes el turno.\n";
        break;
    }
    system("pause");
    system("cls");
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//Turnos

string turnoEquipo()
{
    Personaje jugador;
    Enemigo enemigo;

    string ordenTurno = "";

    int velJ1 = jugador.getVelocidad();
    int velJ2 = enemigo.getVelocidad();

    if (velJ1 > velJ2)
    {
        ordenTurno = "Jugador";
    }
    else
    {
        ordenTurno = "Enemigo";
    }

    return ordenTurno;

}


string turnoAliados(Personaje& _jugador, Aliados _aliadosM, Aliados _aliadosT, Aliados _aliadosA, Aliados _aliadosS)
{
    //Llamar vector de aliados


    string ordenTurnoAliados = "";

    int  velJ1 = _jugador.getVelocidad();
    int velM1 = _aliadosM.getVelocidad();
    int velT1 = _aliadosT.getVelocidad();
    int velA1 = _aliadosA.getVelocidad();
    int velS1 = _aliadosS.getVelocidad();

    //jugador
    if (velJ1 >= velM1)
    {
        ordenTurnoAliados = "Juagdor";
    }
    else if(velJ1 >= velT1)
    {
        ordenTurnoAliados = "Juagdor";
    }
    else if (velJ1 >= velA1)
    {
        ordenTurnoAliados = "Juagdor";
    }
    else if (velJ1 >= velS1)
    {
        ordenTurnoAliados = "Juagdor";
    }//Mago
    else if (velM1 >= velJ1)
    {
        ordenTurnoAliados = "Mago";
    }
    else if (velM1 >= velA1)
    {
        ordenTurnoAliados = "Mago";
    }
    else if (velM1 >= velT1)
    {
        ordenTurnoAliados = "Mago";
    }
    else if (velM1 >= velS1)
    {
        ordenTurnoAliados = "Mago";
    }//Tanque
    else if (velT1 >= velJ1)
    {
        ordenTurnoAliados = "Tanque";
    }
    else if (velT1 >= velA1)
    {
        ordenTurnoAliados = "Tanque";
    }
    else if (velT1 >= velM1)
    {
        ordenTurnoAliados = "Tanque";
    }
    else if (velT1 >= velS1)
    {
        ordenTurnoAliados = "Tanque";
    }//Asesino
    else if (velA1 >= velJ1)
    {
        ordenTurnoAliados = "Asesino";
    }
    else if (velA1 >= velM1)
    {
        ordenTurnoAliados = "Asesino";
    }
    else if (velA1 >= velT1)
    {
        ordenTurnoAliados = "Asesino";
    }
    else if (velA1 >= velS1)
    {
        ordenTurnoAliados = "Asesino";
    }//Support
    else if (velS1 >= velJ1)
    {
        ordenTurnoAliados = "Support";
    }
    else if (velS1 >= velA1)
    {
        ordenTurnoAliados = "Support";
    }
    else if (velS1 >= velT1)
    {
        ordenTurnoAliados = "Support";
    }
    else if (velS1 >= velM1)
    {
        ordenTurnoAliados = "Support";
    }

    return ordenTurnoAliados;

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void desicionCombate()
{

    Personaje jugador;
    Enemigo enemigo;

    std::cout << "\n\n¡Fin del combate!\n";

    if (jugador.getVida() <= 0 && enemigo.getVida() > 0)
        std::cout << enemigo.getNombre() << " ha ganado el combate.\n";

    else if (enemigo.getVida() <= 0 && jugador.getVida() > 0)
        std::cout << jugador.getNombre() << " ha ganado el combate.\n";

    else
        std::cout << "Empate. Ambos han caído.\n";
}



int main() {

    srand(time(0));
    std::locale::global(std::locale("es_ES.UTF-8"));

    //string _nombre, int Vmin_, int Vmax_, int Dmin_, int Dmax_, int Amin_, int Amax_,int velmin, int velmax
    //nombre, vida, Defensa, Atacque, Velocidad
    Aliados AliadoM("Mago", 100,120, 20,25, 55,60, 5,30);
    Aliados AliadoT("Tanque", 180,220, 50,60, 50,55, 5,30);
    Aliados AliadoA("Asesino", 180,220, 50,60, 50,55, 5,30);
    Aliados AliadoS("Support", 180,220, 50,60, 50,55, 5,30);
    Personaje jugador;
    Enemigo enemigo;

    jugador.pedirNombre();
   
    int i = 0;
    do {
        std::cout << "---- Turno " << ++i << " ----" << std::endl;

        string ordenTurno = turnoEquipo();
        string ordenAliados = turnoAliados(jugador, AliadoM, AliadoT, AliadoA, AliadoS);

        jugador.MostrarStats();
        enemigo.MostrarStats();


        if (ordenTurno == "Jugador") 
        {//Turno de los aliados
            if (ordenAliados == "Jugador") {
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);

                //Esto era para poder ordenarlos por velocidad cada uno, que tomaran accion en ese orden
                //jugador

                /*
                if (ordenAliados == "Mago")
                {//Mago
                    
                    AliadoM.eleccionAliados(AliadoM, enemigo);
                    if (ordenAliados == "Tanque")
                    {//Mago-tanque
                        AliadoT.eleccionAliados(AliadoT, enemigo);
                        if (ordenAliados == "Asesino")
                        {
                            AliadoA.eleccionAliados(AliadoA, enemigo);
                            AliadoS.eleccionAliados(AliadoS, enemigo);
                        }
                        else if (ordenAliados == "Support")
                        {
                            AliadoS.eleccionAliados(AliadoS, enemigo);
                            AliadoA.eleccionAliados(AliadoA, enemigo);
                        }
                    }
                    else if (ordenAliados == "Asesino")
                    {//Mago_asesino
                        AliadoA.eleccionAliados(AliadoA, enemigo);
                        if (ordenAliados == "Tanque")
                        {
                            AliadoS.eleccionAliados(AliadoS, enemigo);
                            AliadoT.eleccionAliados(AliadoT, enemigo);
                        }
                        else if (ordenAliados == "Support")
                        {
                            AliadoS.eleccionAliados(AliadoS, enemigo);
                            AliadoT.eleccionAliados(AliadoT, enemigo);
                        }
                       
                    }
                    else if (ordenAliados == "Support")
                    {//Mago-support
                        AliadoS.eleccionAliados(AliadoS, enemigo);
                        if (ordenAliados == "Tanque")
                        {
                            AliadoT.eleccionAliados(AliadoT, enemigo);
                            AliadoA.eleccionAliados(AliadoA, enemigo);
                        }
                        else if (ordenAliados == "Asesino")
                        {
                            AliadoA.eleccionAliados(AliadoA, enemigo);
                            AliadoT.eleccionAliados(AliadoT, enemigo);
                        }

                    }
                   
                }
                else if (ordenAliados == "Tanque")
                {//Tanque
                    AliadoT.eleccionAliados(AliadoT, enemigo);
                    AliadoA.eleccionAliados(AliadoA, enemigo);
                    AliadoS.eleccionAliados(AliadoS, enemigo);
                    AliadoM.eleccionAliados(AliadoM, enemigo);
                }
                else if (ordenAliados == "Asesino")
                {
                    AliadoS.eleccionAliados(AliadoS, enemigo);
                    AliadoT.eleccionAliados(AliadoT, enemigo);
                    AliadoA.eleccionAliados(AliadoA, enemigo);
                    AliadoM.eleccionAliados(AliadoM, enemigo);
                }
                else if (ordenAliados == "Support")
                {
                    AliadoS.eleccionAliados(AliadoS, enemigo);
                    AliadoT.eleccionAliados(AliadoT, enemigo);
                    AliadoA.eleccionAliados(AliadoA, enemigo);
                    AliadoM.eleccionAliados(AliadoM, enemigo);
                }
                */
            }
            else if(ordenAliados == "Mago")
            {
                AliadoM.eleccionAliados(AliadoM, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
            }
            else if (ordenAliados == "Tanque")
            {
                AliadoT.eleccionAliados(AliadoT, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
            }
            else if (ordenAliados == "Asesnio")
            {
                AliadoA.eleccionAliados(AliadoA, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
            }
            else if (ordenAliados == "Support")
            {
                AliadoS.eleccionAliados(AliadoS, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
            }

        }
        else
        {//Turno enemigos
            if (ordenAliados == "Jugador") {
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
            }
            else if (ordenAliados == "Mago")
            {
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
            }
            else if (ordenAliados == "Tanque")
            {
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
            }
            else if (ordenAliados == "Asesnio")
            {
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
                AliadoA.eleccionAliados(AliadoA, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoS.eleccionAliados(AliadoS, enemigo);
            }
            else if (ordenAliados == "Support")
            {
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
                AliadoS.eleccionAliados(AliadoS, enemigo);
                jugador.eleccionJugador(jugador, enemigo);
                AliadoM.eleccionAliados(AliadoM, enemigo);
                AliadoT.eleccionAliados(AliadoT, enemigo);
                AliadoA.eleccionAliados(AliadoA, enemigo);
            }
           
        }
        system("pause");
        system("cls");

    } while (jugador.getVida() > 0 && enemigo.getVida() > 0);

    desicionCombate();

    return 0;
}
