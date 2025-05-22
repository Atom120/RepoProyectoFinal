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

    void habilidades(Enemigo& objetivo);

    void eleccionJugador(Personaje& jugador, Enemigo& enemigo);

    void atacar(Enemigo& objetivo);

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

    int calcularDanioConCritico(int min, int max, int probCritico, bool& fueCritico) {
        int critico = AleatorizarEstadisticas(1, 100);
        int danio = AleatorizarEstadisticas(min, max);

        if (critico >= probCritico) {
            fueCritico = true;
            danio *= 2;//No se guarda para siempre pq recibe un dato externo cada vez y este danio se guarda localmente
            cout << "¡CRÍTICO!\n";
        }
        else {
            fueCritico = false;
        }

        if (danio < 0) danio = 0;
        return danio;
    }


    void pedirNombre() {
        std::cout << "Ingrese el nombre del peleador" << std::endl;
        std::cin >> nombre;
        system("cls");
    }

    void MostrarStatsAliado(Aliados aliado) {
        std::cout << "\n---- Estado actual del " << nombre << "----" << std::endl;
        std::cout << "Vida: " << vida << std::endl;
        std::cout << "Defensa: " << defensa << std::endl;
        std::cout << "Ataque: " << ataque << std::endl;
        std::cout << "Velocidad: " << velocidad << std::endl << std::endl;

    }

    void atacarAliados(Enemigo& objetivo);

    //elecciones
    void eleccionAliadoMago(Aliados& _aliados, Enemigo& enemigo);
    void eleccionAliadoTanque(Aliados& _aliados, Enemigo& enemigo);
    void eleccionAliadoAsesino(Aliados& _aliados, Enemigo& enemigo);
    void eleccionAliadoSupport(Aliados& _aliados, Enemigo& enemigo);

    //Habilidades
    void habilidadesMago(Enemigo& objetivo);
    void habilidadesTanque(Enemigo& objetivo);
    void habilidadesAsesino(Enemigo& objetivo);
    void habilidadesSupport(Enemigo& objetivo);

    //getters y setters
    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }

    int getDefensa() { return defensa; }
    int setDefensa(int _defensa) { defensa = _defensa; }

    int getVelocidad() { return velocidad; }
    int setVelocidad(int _velocidad) { velocidad = _velocidad; }

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

class Jugador
{
private:
    string nombreJugador;
    int oroJugador;



public:
    Jugador() //constructor
    {
        nombreJugador = "Lonki";   //nombre de el jugador al entrar en la tienda
        oroJugador = 200;   //cantidad de oro con la que empezamos       
    }
    void funcMostrarInfoJugador()
    {
        cout << "Nombre: " << nombreJugador << endl << "Oro inicial: " << oroJugador << endl;
    }

    int getoroJugador()
    {
        return oroJugador;
    }

    int setRestaroroJugador(int paramCantidadoro)
    {
        oroJugador -= paramCantidadoro;
        return oroJugador;
    }

};
//Pocion --> Objeto
class Pocion
{
private:
    int cantidadPocion;
    int precioPocion;
    int nivelPocion;
    string descripcionEfectoPocion;
    string nombrePocion;

public:
    //Constructor pocion
    Pocion(int _cantidadPocion, int _precioPocion, int _nivelPocion, string _descripcionEfectoPocion, string _nombrePocion)
    {
        cantidadPocion = _cantidadPocion;
        precioPocion = _precioPocion;
        nivelPocion = _nivelPocion;
        descripcionEfectoPocion = _descripcionEfectoPocion;
        nombrePocion = _nombrePocion;
    }

    void funcMostrarInfoPocion()
    {
        cout << "Nombre: " << nombrePocion << ", Precio: " << precioPocion << endl << "Descripcion: " << descripcionEfectoPocion << endl << "Nivel: " << nivelPocion << endl;
    }

    string getNombrePocion()//para poder recuperar el nombre de la pocion
    {
        return nombrePocion;
    }

    int getprecioPocion()
    {
        return precioPocion;
    }


};

//Tienda --> objeto
class Tienda
{
private:
    vector<Pocion> listaPociones;

public:
    //Constructor de tienda
    Tienda()
    {
        //Constructor pocion(int _cantidadPocion, int _precioPocion, int _nivelPocion, string _descripcionEfectoPocion, string _nombrePocion)
        listaPociones.push_back(Pocion(3, 50, 2, "Restaura 50 puntos de vida ", "Pocion de vida"));
        listaPociones.push_back(Pocion(8, 100, 5, "Restaura 40 puntos de mana ", "Pocion de mana"));
        listaPociones.push_back(Pocion(2, 150, 10, "Restaura 100 puntos de vida ", "Elixir mayor de vida"));
        listaPociones.push_back(Pocion(5, 200, 15, "Restaura 80 puntos de mana ", "Elixir mayor de mana"));

    }

    void funcMostrarMenu()
    {
        cout << "-----Bienvenido a la tienda de pociones-----" << endl;
        cout << "Seleccione un numero del menu" << endl << endl;
        for (size_t i = 0; i < listaPociones.size(); i++)// listaPociones.size() (Recorre posiciones del num de vectores)
        {
            cout << i + 1 << ".- ";
            listaPociones[i].funcMostrarInfoPocion();
        }
        cout << listaPociones.size() + 1 << ".-Salir de menu";

    }

    int funcComprarPocion(Jugador paramJugador)//parametros de jugador
    {
        int opcionSeleccionada;

        do
        {
            funcMostrarMenu();
            cout << endl;
            cin >> opcionSeleccionada;

            switch (opcionSeleccionada)
            {
            case 1:
            case 2:
            case 3:
            case 4: {
                int pocionListaPociones = opcionSeleccionada - 1;
                Pocion pocionSeleccionada = listaPociones[pocionListaPociones];//Para que busque pocion selecciono el jugador

                if (paramJugador.getoroJugador() >= pocionSeleccionada.getprecioPocion())//Compara el oro que tiene el jugador con el precio de la pocion que selecciono
                {
                    paramJugador.setRestaroroJugador(pocionSeleccionada.getprecioPocion());//Se llama a la pocion seleccionada llmando al precio para saber cuanto restarle
                    cout << endl << "Haz comprado: " << pocionSeleccionada.getNombrePocion() << endl;//Le muestra que pocion selecciono
                    cout << "Te queda: " << paramJugador.getoroJugador() << endl << endl;//Llama al get de oror para saber cuanto le queda al jugaor
                    break;
                }
                else
                {
                    if (paramJugador.getoroJugador() < pocionSeleccionada.getprecioPocion())
                    {
                        cout << "No te alcanza" << endl << endl;
                        cout << "Te queda: " << paramJugador.getoroJugador() << endl << endl;
                    }
                    else
                    {
                        cout << "No tienes dinero" << endl << endl;
                    }
                }

            }

                  break;
            default:
                if (listaPociones.size() + 1 == opcionSeleccionada)
                {
                    break;
                }
                else
                {
                    cout << "Error en algo" << endl << endl;
                }

            }

        } while (opcionSeleccionada != listaPociones.size() + 1);

        return 0;
    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////
//Aliados

//Elecciones
void Aliados::eleccionAliadoMago(Aliados& _aliados, Enemigo& enemigo)
{
    int opcion;

    cout << "Es el turno de " << _aliados.getNombre() << endl;

    std::cout << "\n--- Elige una acción ---\n";
    std::cout << "1. Atacar\n";
    std::cout << "2. Usar habilidad\n";
    std::cout << "3. Defender (en desarrollo)\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        _aliados.atacarAliados(enemigo);
        break;
    case 2:
        std::cout << _aliados.getNombre() << "\n";
        habilidadesMago(enemigo);
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
void Aliados::eleccionAliadoTanque(Aliados& _aliados, Enemigo& enemigo){
    int opcion;

    cout << "Es el turno de " << _aliados.getNombre() << endl;

    std::cout << "\n--- Elige una acción ---\n";
    std::cout << "1. Atacar\n";
    std::cout << "2. Usar habilidad\n";
    std::cout << "3. Defender (en desarrollo)\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        _aliados.atacarAliados(enemigo);
        break;
    case 2:
        std::cout << _aliados.getNombre() << "\n";
        habilidadesMago(enemigo);
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
void Aliados::eleccionAliadoAsesino(Aliados& _aliados, Enemigo& enemigo)
{
    int opcion;

    cout << "Es el turno de " << _aliados.getNombre() << endl;

    std::cout << "\n--- Elige una acción ---\n";
    std::cout << "1. Atacar\n";
    std::cout << "2. Usar habilidad\n";
    std::cout << "3. Defender (en desarrollo)\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        _aliados.atacarAliados(enemigo);
        break;
    case 2:
        std::cout << _aliados.getNombre() << "\n";
        habilidadesAsesino(enemigo);
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
void Aliados::eleccionAliadoSupport(Aliados& _aliados, Enemigo& enemigo)
{
    int opcion;

    cout << "Es el turno de " << _aliados.getNombre() << endl;

    std::cout << "\n--- Elige una acción ---\n";
    std::cout << "1. Atacar\n";
    std::cout << "2. Usar habilidad\n";
    std::cout << "3. Defender (en desarrollo)\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        _aliados.atacarAliados(enemigo);
        break;
    case 2:
        std::cout << _aliados.getNombre() << "\n";
        habilidadesMago(enemigo);
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

//atacar
void Aliados::atacarAliados(Enemigo& objetivo)
{
    int critico = AleatorizarEstadisticas(1, 100);
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;

    bool esCritico = false;

    cout << "\n---- Daño Aliados ----\n\n";

    if (critico >= 95) {
        danio * 2;
        std::cout << "DAÑO CRÍTICO: " << danio << std::endl << endl;
        esCritico = true;
    }

    objetivo.setVida(objetivo.getVida() - danio);
    if (esCritico)
        std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " ¡Daño Crítico!\n" << std::endl;
    else
        std::cout << nombre << ": ataca a " << objetivo.getNombre() << " causando " << danio << " daño.\n" << std::endl;
}

//Habilidades
void Aliados::habilidadesMago(Enemigo& objetivo)
{
    int opcion;
    int danioBase = ataque - objetivo.getDefensa();
    if (danioBase < 0) danioBase = 0;

    do {
        cout << "\n¿Qué habilidad quiere usar el Mago?\n";
        cout << "1. Destructor atómico de los reyes del inframundo interpolados sin fines de lucro\n";
        cout << "2. Bola de fuego estelar\n";
        cout << "3. Chanclazo\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: {
            int danioMagico = static_cast<int>(danioBase * 1.5);//static_cast Es un conversor de una variable a otra en este caso a int porque getVida solo recibe enteros
            objetivo.setVida(objetivo.getVida() - danioMagico);
            cout << "¡Se lanza el hechizo Destructor atómico de los reyes del inframundo interpolados sin fines de lucro!\n";
            cout << objetivo.getNombre() << " recibe " << danioMagico << " de daño mágico.\n";
            break;
        }

        case 2: {
            int danioMagico = static_cast<int>(danioBase * 1.7);
            objetivo.setVida(objetivo.getVida() - danioMagico);
            cout << "¡Bola de fuego estelar lanzada!\n";
            cout << objetivo.getNombre() << " recibe " << danioMagico << " de daño mágico.\n";
            break;
        }

        case 3: {
            int danioMagico = danioBase * 2;
            objetivo.setVida(objetivo.getVida() - danioMagico);
            cout << "¡Chanclazo infernal ejecutado!\n";
            cout << objetivo.getNombre() << " recibe " << danioMagico << " de daño mágico.\n";
            break;
        }

        default:
            cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }

    } while (opcion < 1 || opcion > 3);
}

void Aliados::habilidadesTanque(Enemigo& objetivo)
{
    int opcion;
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;

    cout << "Que habilidad quiere usar?";
    cout << "1. Destructor atomico de los reyes del inframundo interpolados sin fines de lucro";
    cout << "2. Bola de fuego estelar";
    cout << "3. Chanclazo";
    cin >> opcion;
    do
    {
        switch (opcion)
        {
        case 1:
            objetivo.setVida(objetivo.getVida() - 10);

            cout << "Se lanza el hehcizo Destructor atomico de los reyes del inframundo interpolados sin fines de lucro";
            cout << nombre << " recibe " << danio << objetivo.getNombre();
            break;

        case 2:

            objetivo.setVida(objetivo.getVida() - AleatorizarEstadisticas(45, 55));

            cout << "Bola de fuego estelar";
            cout << nombre << " recibe " << danio << objetivo.getNombre();
            break;

        case 3:

            objetivo.setVida(objetivo.getVida() - AleatorizarEstadisticas(99, 100));

            cout << "Chanclazo";
            cout << nombre << " recibe " << danio << objetivo.getNombre();
            break;

        default:

            cout << "Opcion no valida";
            break;
        }
    } while (opcion == 1 || opcion == 2 || opcion == 3);
}

void Aliados::habilidadesAsesino(Enemigo& objetivo)
{
    int velA = velocidad;
    int opcion;

    cout << "\n¿Qué habilidad quiere usar el Asesino?\n";
    cout << "1. Golpe Sombrío (Alto daño crítico)\n";
    cout << "2. Doble Corte (Dos golpes rápidos)\n";
    cout << "3. Desvanecer (Aumenta velocidad)\n";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
        //El static_cast Es un conversor de una variable a otra. 
        //aqui danio al multiplicar 1.5 es float y al ponerle eso la hace un entero

        bool critico;
        int danio = calcularDanioConCritico(60, 80, 60, critico);
        danio = static_cast<int>(danio * 1.5);
        objetivo.setVida(objetivo.getVida() - danio);

        if (critico)//si no pones nada asume q es true
            cout << "Asesino realiza un ¡GOLPE PODEROSISIMO!\n";
        else
            cout << "Asesino realiza un golpe poderoso.\n";

        cout << "Daño total: " << danio << "\n";
        break;
    }
    case 2:
    {
        bool critico1, critico2;
        int golpe1 = calcularDanioConCritico(20, 80, 90, critico1);
        int golpe2 = calcularDanioConCritico(20, 80, 90, critico2);
        int danioTotal = golpe1 + golpe2;

        objetivo.setVida(objetivo.getVida() - danioTotal);
        cout << "El Asesino realiza un Doble Corte!\n";
                                         //Este es un operador ternario, si critico es tru cumple la primera si no la segunda. solo srive en cout
        cout << "Corte 1: " << golpe1 << (critico1 ? " (CRÍTICO)\n" : "\n");//condición ? valor_si_verdadero : valor_si_falso;

        cout << "Corte 2: " << golpe2 << (critico2 ? " (CRÍTICO)\n" : "\n");

        cout << "Daño Total: " << danioTotal << "\n";
        break;
    }
    case 3:
    {
        int aumento = AleatorizarEstadisticas(1, 10);
        velA += aumento;
        velocidad = velA;
        cout << "El Asesino se desvanece. ¡Su velocidad aumenta durante el combate!\n";
        cout << "Su velocidad ahora es de: " << velA << "\n";
        break;
    }
    default:
        cout << "Opción no válida.\n";
        break;
    }

}

void Aliados::habilidadesSupport(Enemigo& objetivo)
{
    int opcion;
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;

    cout << "Que habilidad quiere usar?";
    cout << "1. Healing";
    cout << "2. Bola de fuego estelar";
    cout << "3. Chanclazo";
    cin >> opcion;
    do
    {
        switch (opcion)
        {
        case 1:
            objetivo.setVida(objetivo.getVida() - 10);

            cout << "Se lanza el hehcizo Destructor atomico de los reyes del inframundo interpolados sin fines de lucro";
            cout << nombre << " recibe " << danio << objetivo.getNombre();
            break;

        case 2:

            objetivo.setVida(objetivo.getVida() - AleatorizarEstadisticas(45, 55));

            cout << "Bola de fuego estelar";
            cout << nombre << " recibe " << danio << objetivo.getNombre();
            break;

        case 3:

            objetivo.setVida(objetivo.getVida() - AleatorizarEstadisticas(99, 100));

            cout << "Chanclazo";
            cout << nombre << " recibe " << danio << objetivo.getNombre();
            break;

        default:

            cout << "Opcion no valida";
            break;
        }
    } while (opcion == 1 || opcion == 2 || opcion == 3);
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
        danio * 2;
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

    do {
        std::cout << "\n¿Qué desea hacer?\n";
        std::cout << "1. Atacar\n";
        std::cout << "2. Habilidad\n";
        std::cout << "3. Defender\n";
        cout << "\n¡No ingrese letras o se rompe!\n";
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            jugador.atacar(enemigo);
            break;
        case 2:
            std::cout << jugador.getNombre() << endl;
            jugador.habilidades(enemigo);
            break;
        case 3:
            std::cout << jugador.getNombre() << " se defiende (no implementado).\n";
            break;
        default:
            std::cout << "\n\nOpción no válida. Intente de nuevo\n\n";
            break;
        }

        system("pause");
        system("cls");
    } while (opcion < 1 || opcion > 3);

    system("cls");
}

void Personaje::habilidades(Enemigo& objetivo){
    int opcion;
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;
    system("cls");

    do {
        cout << "\n¿Qué habilidad quiere usar?\n";
        cout << "1. Destructor atómico\n";
        cout << "2. Bola de fuego estelar\n";
        cout << "3. Chanclazo\n";
        cout << "\n¡No ingrese letras o se rompe:!\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            objetivo.setVida(objetivo.getVida() - 10);
            cout << "Se lanza el hechizo Destructor atómico.\n";
            break;

        case 2:
            objetivo.setVida(objetivo.getVida() - AleatorizarEstadisticas(45, 55));
            cout << "Bola de fuego estelar lanzada.\n";
            break;

        case 3:
            objetivo.setVida(objetivo.getVida() - AleatorizarEstadisticas(99, 100));
            cout << "¡Chanclazo certero!\n";
            break;

        default:
            cout << "\n\nOpción no válida. Intente de nuevo\n\n";
            break;
        }
        system("pause");
        system("cls");
    } while (opcion < 1 || opcion > 3);  // Solo repite si la opción NO es válida

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

        jugador.MostrarStats();
        enemigo.MostrarStats();


        if (ordenTurno == "Jugador") 
        {//Turno de los aliados
                //jugador
                jugador.eleccionJugador(jugador, enemigo);
                enemigo.MostrarStats();
                //Mago
                AliadoM.MostrarStatsAliado(AliadoM);
                AliadoM.eleccionAliadoMago(AliadoM, enemigo);
                enemigo.MostrarStats();
                //Tanque
                AliadoT.MostrarStatsAliado(AliadoT);
                AliadoT.eleccionAliadoTanque(AliadoT, enemigo);
                enemigo.MostrarStats();
                //Asesino
                AliadoA.MostrarStatsAliado(AliadoA);
                AliadoA.eleccionAliadoAsesino(AliadoA, enemigo);
                enemigo.MostrarStats();
                //Support
                AliadoS.MostrarStatsAliado(AliadoS);
                AliadoS.eleccionAliadoSupport(AliadoS, enemigo);
                enemigo.MostrarStats();
                //Enemigo ataca
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);

        }
        else
        {//Turno enemigos
                enemigo.atacarEnemigo(jugador, AliadoM, AliadoT, AliadoA, AliadoS);
                //jugador
                jugador.eleccionJugador(jugador, enemigo);
                enemigo.MostrarStats();
                //Mago
                AliadoM.MostrarStatsAliado(AliadoM);
                AliadoM.eleccionAliadoMago(AliadoM, enemigo);
                enemigo.MostrarStats();
                //Tanque
                AliadoT.MostrarStatsAliado(AliadoT);
                AliadoT.eleccionAliadoTanque(AliadoT, enemigo);
                enemigo.MostrarStats();
                //Asesino
                AliadoA.MostrarStatsAliado(AliadoA);
                AliadoA.eleccionAliadoAsesino(AliadoA, enemigo);
                enemigo.MostrarStats();
                //Support
                AliadoS.MostrarStatsAliado(AliadoS);
                AliadoS.eleccionAliadoSupport(AliadoS, enemigo);
                enemigo.MostrarStats();

        }
        system("pause");
        system("cls");

    } while (jugador.getVida() > 0 && enemigo.getVida() > 0);

    desicionCombate();

    return 0;
}
