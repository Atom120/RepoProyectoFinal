// CombateP00.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Sebastián Selvas García

#include <iostream>
#include <stdlib.h>   // para usar rand
#include <locale.h>   // Para poder cambiar el idioma y usar ñ
#include <time.h>
#include <vector>
#include <string>
#include <limits>

using namespace std;


// --- Declaración adelantada necesaria ---
class Enemigo;
class Aliados;  // 👈 Esto le dice al compilador que Aliados existirá
class Pocion;

class Personaje {
protected:

    int vidaMaxima;
    int vida;
    int defensa;
    int ataque;
    int velocidad;
    int oroJugador;
    vector<Pocion> listaObjetos;

public:
    std::string nombre;

    Personaje() {
        vida = AleatorizarEstadisticas(150, 200);
        vidaMaxima = vida;
        defensa = AleatorizarEstadisticas(5, 20);
        ataque = AleatorizarEstadisticas(50, 100);
        velocidad = AleatorizarEstadisticas(10, 30);
        oroJugador = AleatorizarEstadisticas(500, 600);
    }

    int AleatorizarEstadisticas(int _minimo, int _maximo) {//Me ayudo mi compañero Jorge
        return _minimo + rand() % (_maximo - _minimo + 1);
    }

    void pedirNombre() {
        std::cout << "Ingrese el nombre del peleador" << std::endl;
        std::cout << "NO INGRESE ESPACIOS\n" << std::endl;

        std::getline(cin, nombre);
        system("cls");
    }

    void MostrarStats() {
        std::cout << "\n---- Estado actual del jugador ----" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Vida: " << vida << " / " << vidaMaxima << std::endl;
        std::cout << "Defensa: " << defensa << std::endl;
        std::cout << "Ataque: " << ataque << std::endl;
        std::cout << "Velocidad: " << velocidad << std::endl << std::endl;
    }


    void sumarVida(int _curacion) {
        vida += _curacion;
        if (vida > vidaMaxima) {
            vida = vidaMaxima;
        }
    }



    void mostrarInventario();

    void agregarPocion(Pocion nuevaPocion);

    void mostrarOro();

    void habilidades(Enemigo& objetivo);

    void eleccionJugador(Personaje& jugador, Enemigo& enemigo);

    void atacar(Enemigo& objetivo);

    void eliminarPoción(vector<Pocion>& _listaObjetos);


    //Getter y setters
    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }

    void setDefensa(int _defensa) { defensa = _defensa; }
    int getDefensa() { return defensa; }

    int getAtaque() { return ataque; }
    void setAtaque(int _ataque) { ataque = _ataque; }

    int getVelocidad() { return velocidad; }
    std::string getNombre() { return nombre; }

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
            std::cout << "¡CRÍTICO!\n";
        }
        else {
            fueCritico = false;
        }

        if (danio < 0) danio = 0;
        return danio;
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
    void eleccionAliadoMago(Personaje& jugador, Enemigo& enemigo);
    void eleccionAliadoTanque(Aliados& _aliadoTanque, Aliados& _aliadoMago, Aliados& _aliadoAsesino, Aliados& _aliadoSupport, Personaje& jugador, Enemigo& enemigo);
    void eleccionAliadoAsesino(Personaje& jugador, Aliados& _aliados, Enemigo& enemigo);
    void eleccionAliadoSupport(Aliados& _aliadoMago, Aliados& _aliadoTanque, Aliados& _aliadoAsesino, Aliados& _aliadoSupport, Personaje& jugador, Enemigo& enemigo);

    //Habilidades
    void habilidadesMago(Enemigo& objetivo);
    void habilidadesTanque(Aliados& _aliadoMago, Aliados& _aliadoAsesino, Aliados& _aliadoSupport, Personaje& jugador,Enemigo& objetivo);
    void habilidadesAsesino(Enemigo& objetivo);
    void habilidadesSupport(Aliados& _aliadoMago, Aliados& _aliadoAsesino, Aliados& _aliadoTanque, Aliados& _aliadoSupport,Personaje& jugador, Enemigo& objetivo);

    //getters y setters
    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }

    int getDefensa() { return defensa; }
    void setDefensa(int _defensa) { defensa = _defensa; }

    int getAtaque() { return ataque; }
    void setAtaque(int _ataque) { ataque = _ataque; }

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

    Enemigo(int Vmin_, int Vmax_, int Dmin_, int Dmax_, int Amin_, int Amax_, int Velmin_, int Velmax_ ) {
        vida = AleatorizarEstadisticas(Vmin_, Vmax_);
        defensa = AleatorizarEstadisticas(Dmin_, Dmax_);
        ataque = AleatorizarEstadisticas(Amin_, Amax_);
        velocidad = AleatorizarEstadisticas(Velmin_, Velmax_);
        nombre = nomEnemigoPosible[rand() % nomEnemigoPosible.size()];
    }

    int AleatorizarEstadisticas(int _minimo, int _maximo) {
        return _minimo + rand() % (_maximo - _minimo + 1);
    }

    void MostrarStats() {
        std::cout << "\n---- Estado actual del enemigo ----" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Vida: " << vida << std::endl;
        std::cout << "Defensa: " << defensa << std::endl;
        std::cout << "Ataque: " << ataque << std::endl;
        std::cout << "Velocidad: " << velocidad << std::endl << std::endl;

    }

    void atacarEnemigo(Personaje& objetivo, Aliados& _aliadoMago, Aliados& _aliadoTanque,Aliados& _aliadoAsesino, Aliados& _aliadoSupport)
    {
        // Creamos un vector que contendrá a los aliados vivos
        vector<Aliados> Vivos;

        // Añadimos a todos los aliados al vector 
        if (_aliadoMago.getVida() > 0) Vivos.push_back(_aliadoMago);  // posición 0
        if (_aliadoTanque.getVida() > 0) Vivos.push_back(_aliadoTanque);  // posición 1
        if (_aliadoAsesino.getVida() > 0) Vivos.push_back(_aliadoAsesino); // posición 2
        if (_aliadoSupport.getVida() > 0) Vivos.push_back(_aliadoSupport);// posición 3
        
        // Variable booleana que nos dirá si se va a atacar a todos
        bool todos = false;

        // Variable para guardar si el ataque es crítico
        bool esCritico = false;

        // Generamos un número aleatorio del 1 al 100
        int numRandom = AleatorizarEstadisticas(1, 100);

        // Si el número aleatorio es 80 o más (20% de probabilidad), atacamos a todos
        if (numRandom >= 80) {
            todos = true; // 
        }

        // Si toca atacar a todos
        if (todos) {
            std::cout << "\n¡" << nombre << obtenerNombreAtaqueArea() << "\n\n";

            /*Manera panista tradicional
            for (int i = 0; i < Vivos.size(); ++i) {
                Aliados aliado = Vivos[i];
                ...
            } */

            // Recorremos a todos los aliados vivos con un bucle for-each
            for (Aliados& aliado : Vivos) { // Usamos referencia (&) para modificar al aliado real
                //“Para cada aliado dentro del vector Vivos, haz lo siguiente...”
                //Vivos dice el numero de veces que lo va a hacer respecto al numero de elementos en el lista osea 4

                // Calculamos el daño según su defensa
                int danio = ataque - aliado.getDefensa();
                if (danio < 0) danio = 0;

                // Posibilidad de crítico
                int critico = AleatorizarEstadisticas(1, 100);
                if (critico >= 95) {
                    danio *= 2;
                    esCritico = true;
                }

                // Aplicamos el daño
                aliado.setVida(aliado.getVida() - danio);

                // Mostramos el resultado del ataque
                std::cout << nombre << " ataca a " << aliado.getNombre()
                    << " causando " << danio << " de daño"
                    << (esCritico ? " ¡CRÍTICO!\n" : "\n");
            }
        }
        else {
            // Si no atacamos a todos, atacamos a uno aleatorio

            // Verificamos que la lista no esté vacía
            if (Vivos.empty()) {
                std::cout << nombre << " no encuentra a ningún aliado con vida. Ataca al jugador directamente.\n";
                int danio = ataque - objetivo.getDefensa();
                if (danio < 0) danio = 0;

                int critico = AleatorizarEstadisticas(1, 100);
                if (critico >= 95) {
                    danio *= 2;
                    esCritico = true;
                }

                objetivo.setVida(objetivo.getVida() - danio);

                std::cout << nombre << " ataca a " << objetivo.getNombre() << " con " << obtenerNombreAtaque()
                    << " causando " << danio << " de daño"
                    << (esCritico ? " ¡CRÍTICO!\n" : "\n");
            }
            else {
                // Elegimos una posición aleatoria del vector (de 0 hasta Vivos.size() - 1) del 0 al 3
                int posicion = AleatorizarEstadisticas(0, Vivos.size() - 1);

                // Obtenemos al aliado que se encuentra en esa posición
                Aliados& elegido = Vivos[posicion];

                // Calculamos daño
                int danio = ataque - elegido.getDefensa();
                if (danio < 0) danio = 0;

                int critico = AleatorizarEstadisticas(1, 100);
                if (critico >= 95) {
                    danio *= 2;
                    esCritico = true;
                }

                elegido.setVida(elegido.getVida() - danio);

                std::cout << nombre << " ataca a " << elegido.getNombre() << " con " << obtenerNombreAtaque()
                    << " causando " << danio << " de daño"
                    << (esCritico ? " ¡CRÍTICO!\n" : "\n");

                std::cout << nombre << " ataca a " << elegido.getNombre()
                    << " causando " << danio << " de daño"
                    << (esCritico ? " ¡CRÍTICO!\n" : "\n");
            }
        }

    }

   /* void atacarEnemigo(Personaje& objetivo, Aliados& _aliadoMago, Aliados& _aliadoTanque, Aliados& _aliadoAsesino, Aliados& _aliadoSupport) {

        vector<Aliados> Vivos;
        Vivos.push_back(_aliadoMago);//0
        Vivos.push_back(_aliadoTanque);//1
        Vivos.push_back(_aliadoAsesino);//2
        Vivos.push_back(_aliadoSupport);//3

        int critico = AleatorizarEstadisticas(1, 100);
        int tamanioLista = AleatorizarEstadisticas(0, Vivos.size() + 1);

        bool todos;
        bool esCritico = false;

        int numRandom = AleatorizarEstadisticas(1, 100);
        if (numRandom >= 80) { todos = true; }

        if (todos == true)
        {
            int danio = ataque - objetivo.getDefensa();
            int danioAliado = ataque - _aliadoMago.getDefensa();
            int danioAliado = ataque - _aliadoTanque.getDefensa();
            int danioAliado = ataque - _aliadoAsesino.getDefensa();
            int danioAliado = ataque - _aliadoSupport.getDefensa();
            if (danio < 0) danio = 0;
            if (danioAliado < 0) danioAliado = 0;
        }
        else
        {
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
        }
        
    };*/

    string getEnemigo() const {
        return nombre;
    }

    // Devuelve el nombre del ataque individual según el nombre del enemigo
    string obtenerNombreAtaque() const {
        if (nombre == "Esqueleto") return "Golpe Óseo";
        else if (nombre == "Pepsi") return "Chorro de Gas Carbónico";
        else if (nombre == "Soda") return "Explosión de Burbujas";
        else return "Ataque Desconocido";
    }

    // Devuelve el nombre del ataque en área según el nombre del enemigo
    string obtenerNombreAtaqueArea() const {
        if (nombre == "Esqueleto") return "Tormenta de Huesos";
        else if (nombre == "Pepsi") return "Erupción Gaseosa";
        else if (nombre == "Soda") return "Burbujeo Explosivo";
        else return "Ataque en Área Desconocido";
    }


    int getVida() { return vida; }
    void setVida(int _vida) { vida = _vida; }

    int getDefensa() { return defensa; }
    void setDefensa(int _defensa) { defensa = _defensa; }

    int getVelocidad() { return velocidad; }
    std::string getNombre() { return nombre; }


};

//Pocion --> Objeto
class Pocion
{
private:
    int saludRecuperada;
    int precioPocion;
    int nivelPocion;
    string descripcionEfectoPocion;
    string nombrePocion;

public:
    //Constructor pocion
    Pocion(int _saludRecuperada, int _precioPocion, int _nivelPocion, string _descripcionEfectoPocion, string _nombrePocion)
    {
        saludRecuperada = _saludRecuperada;
        precioPocion = _precioPocion;
        nivelPocion = _nivelPocion;
        descripcionEfectoPocion = _descripcionEfectoPocion;
        nombrePocion = _nombrePocion;
    }

    void funcMostrarInfoPocion()
    {
        std::cout << "Nombre: " << nombrePocion << ", Precio: " << precioPocion << endl << "Descripcion: " << descripcionEfectoPocion << endl << "Nivel: " << nivelPocion << endl;
    }

    string getNombrePocion()//para poder recuperar el nombre de la pocion
    {
        return nombrePocion;
    }

    int getprecioPocion()
    {
        return precioPocion;
    }

    int getSaludPocion()
    {
        return saludRecuperada;
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
        listaPociones.push_back(Pocion(1, 50, 1, "Restaura 50 puntos de vida ", "Pocion de vida"));
        listaPociones.push_back(Pocion(1, 100, 2, "Restaura 40 puntos de vida ", "Pocion mayor"));
        listaPociones.push_back(Pocion(1, 150, 3, "Restaura 100 puntos de vida ", "Elixir menor de vida"));
        listaPociones.push_back(Pocion(1, 200, 4, "Restaura 80 puntos de vida ", "Elixir mayor de vida"));

    }

    void funcMostrarMenu(Personaje& jugador)
    {
        std::cout << "-----Bienvenido a la tienda de pociones-----" << endl;
        std::cout << "Seleccione un numero del menu" << endl;
        std::cout << "En combate solo puedes usar tus primeras tres pociones" << endl << endl;
        jugador.mostrarOro();
        for (size_t i = 0; i < listaPociones.size(); i++)// listaPociones.size() (Recorre posiciones del num de vectores)
        {
            std::cout << i + 1 << ".- ";
            listaPociones[i].funcMostrarInfoPocion();
        }
        std::cout << listaPociones.size() + 1 << ".-Salir de menu";

    }

    int funcComprarPocion(Personaje& paramJugador)//parametros de jugador
    {
        int opcionSeleccionada;

        do
        {
            funcMostrarMenu(paramJugador);
            std::cout << endl;
            cin >> opcionSeleccionada;


            if (std::cin.fail()) {
                std::cout << "Error: La entrada no es un número válido.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
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
                    std:: cout << endl << "Haz comprado: " << pocionSeleccionada.getNombrePocion() << endl;//Le muestra que pocion selecciono
                    std::cout << "Te queda: " << paramJugador.getoroJugador() << endl << endl;//Llama al get de oror para saber cuanto le queda al jugaor
                    paramJugador.agregarPocion(pocionSeleccionada);
                    break;
                }
                else
                {
                    if (paramJugador.getoroJugador() < pocionSeleccionada.getprecioPocion())
                    {
                        std::cout << "No te alcanza" << endl << endl;
                        std::cout << "Te queda: " << paramJugador.getoroJugador() << endl << endl;
                    }
                    else
                    {
                        std::cout << "No tienes dinero" << endl << endl;
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
                    std::cout << "Error en algo" << endl << endl;
                }

            }

        } while (opcionSeleccionada != listaPociones.size() + 1);
        system("pause");
        system("cls");

        return 0;
    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////
//Aliados

//Elecciones
void Aliados::eleccionAliadoMago(Personaje& jugador, Enemigo& enemigo)
{
    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "Es el turno de " << this->getNombre() << std::endl;

        std::cout << "\n--- Elige una acción ---\n";
        std::cout << "1. Atacar\n";
        std::cout << "2. Usar habilidad\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Error: La entrada no es un número válido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (opcion < 1 || opcion > 2) {
            std::cout << "Opción fuera de rango. Elige 1, 2 o 3.\n";
        }
        else {
            entradaValida = true;

            switch (opcion) {
            case 1:
                this->atacarAliados(enemigo);
                break;
            case 2:
                std::cout << "Habilidades\n";
                this->habilidadesMago(enemigo);
                break;

            }

            system("pause");
            system("cls");
        }

    } while (!entradaValida);
}
void Aliados::eleccionAliadoTanque(Aliados& _aliadoTanque, Aliados& _aliadoMago, Aliados& _aliadoAsesino, Aliados& _aliadoSupport, Personaje& jugador, Enemigo& enemigo) {
    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "Es el turno del Tanque\n";
        std::cout << "\n--- Elige una acción ---\n";
        std::cout << "1. Atacar\n";
        std::cout << "2. Usar habilidad\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        //Autoria con herramienta de Gemini
        if (std::cin.fail()) {
            std::cout << "Error: La entrada no es un número válido.\n";
            std::cin.clear(); // limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia el búfer
        }
        else if (opcion < 1 || opcion > 2) {
            std::cout << "Opción fuera de rango. Intenta de nuevo.\n";
        }
        else {
            entradaValida = true; // ✅ solo si todo está bien

            switch (opcion) {
            case 1:
                _aliadoTanque.atacarAliados(enemigo);
                break;
            case 2:
                std::cout << "Habilidades:\n";
                habilidadesTanque(_aliadoMago, _aliadoAsesino, _aliadoSupport, jugador, enemigo);
                break;
            }

            system("pause");
            system("cls");
        }

    } while (!entradaValida); // 🔁 se repite solo si la entrada fue inválida
}
void Aliados::eleccionAliadoAsesino(Personaje& jugador, Aliados& _aliados, Enemigo& enemigo)
{
    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "Es el turno de " << _aliados.getNombre() << std::endl;

        std::cout << "\n--- Elige una acción ---\n";
        std::cout << "1. Atacar\n";
        std::cout << "2. Usar habilidad\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Error: La entrada no es un número válido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (opcion < 1 || opcion > 2) {
            std::cout << "Opción fuera de rango. Elige 1, 2 o 3.\n";
        }
        else {
            entradaValida = true;

            switch (opcion) {
            case 1:
                _aliados.atacarAliados(enemigo);
                break;
            case 2:
                std::cout << "\nHabilidades \n";
                habilidadesAsesino(enemigo);
                break;
            }

            system("pause");
            system("cls");
        }

    } while (!entradaValida);
}
void Aliados::eleccionAliadoSupport(Aliados& _aliadoMago, Aliados& _aliadoTanque, Aliados& _aliadoAsesino, Aliados& _aliadoSupport, Personaje& jugador, Enemigo& enemigo)
{
    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "Es el turno de " << _aliadoSupport.getNombre() << std::endl;

        std::cout << "\n--- Elige una acción ---\n";
        std::cout << "1. Atacar\n";
        std::cout << "2. Usar habilidad\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Error: La entrada no es un número válido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (opcion < 1 || opcion > 2) {
            std::cout << "Opción fuera de rango. Elige 1, 2 o 3.\n";
        }
        else {
            entradaValida = true;

            switch (opcion) {
            case 1:
                _aliadoSupport.atacarAliados(enemigo);
                break;
            case 2:
                std::cout << "Habilidades \n";
                habilidadesSupport(_aliadoMago, _aliadoTanque, _aliadoAsesino, _aliadoSupport, jugador, enemigo);
                break;
            }

            system("pause");
            system("cls");
        }
    } while (!entradaValida);
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

        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada incorrecta
            cout << " Entrada inválida. Por favor ingrese un número del 1 al 3.\n";
            opcion = -1; // Fuerza a repetir el bucle
            continue;
        }

        switch (opcion)
        {
        case 1: {
            int danioMagico = static_cast<int>(danioBase * 1.5);
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

void Aliados::habilidadesTanque(Aliados& _aliadoMago, Aliados& _aliadoAsesino, Aliados& _aliadoSupport, Personaje& jugador, Enemigo& objetivo)
{
    int opcion;

    // Menú con validación de entrada
    do {
        cout << "¿Qué habilidad quiere usar?\n";
        cout << "1. Ataque escudo paladín (Daño bajo)\n";
        cout << "2. Tralalea a su tralala (Reduce la defensa enemiga)\n";
        cout << "3. Presteza del escudo defensor (Aumenta defensa a todo el equipo)\n";
        cout << "\nSeleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
            cout << "Entrada inválida. Por favor ingrese un número del 1 al 3.\n\n";
            opcion = -1; // Fuerza a repetir el bucle
            continue;
        }

        if (opcion < 1 || opcion > 3) {
            cout << "\nOpción inválida. Intente de nuevo.\n\n";
        }

    } while (opcion < 1 || opcion > 3);  // Solo repite si la opción es inválida

    // Ejecución de la habilidad elegida
    switch (opcion)
    {
    case 1: {
        // Daño aleatorio entre 15 y 30
        int golpe = AleatorizarEstadisticas(15, 30);
        objetivo.setVida(objetivo.getVida() - golpe);

        cout << "\nEl tanque invoca su escudo y embiste al enemigo con fuerza brutal...\n";
        cout << nombre << " golpea con su escudo causando: " << golpe << " de daño a " << objetivo.getNombre() << "!\n";
        break;
    }

    case 2: {
        // Reducción de defensa aleatoria entre 1 y 15
        int reduccion = AleatorizarEstadisticas(1, 15);
        int nuevaDefensa = objetivo.getDefensa() - reduccion;
        if (nuevaDefensa < 0) nuevaDefensa = 0;

        objetivo.setDefensa(nuevaDefensa);

        cout << "\n Un círculo mágico oscuro envuelve al enemigo...\n";
        cout << nombre << " reduce la defensa de " << objetivo.getNombre() << " en: " << reduccion << " puntos.\n";
        break;
    }

    case 3: {
        // Aumento de defensa aleatorio entre 1 y 15 para todos
        int defensaAumentada = AleatorizarEstadisticas(1, 15);

        _aliadoAsesino.setDefensa(_aliadoAsesino.getDefensa() + defensaAumentada);
        _aliadoMago.setDefensa(_aliadoMago.getDefensa() + defensaAumentada);
        _aliadoSupport.setDefensa(_aliadoSupport.getDefensa() + defensaAumentada);
        jugador.setDefensa(jugador.getDefensa() + defensaAumentada);

        cout << "\n El tanque alza su escudo al cielo. Una luz sagrada cubre al equipo...\n";
        cout << " Todos los aliados ganan +" << defensaAumentada << " de defensa.\n";
        break;
    }

    default:
        cout << "\n Algo salió mal. Esta opción no debería aparecer.\n";
        break;
    }
}

void Aliados::habilidadesAsesino(Enemigo& objetivo)
{
    int velA = velocidad;
    int opcion;

    do {
        cout << "\n¿Qué habilidad quiere usar el Asesino?\n";
        cout << "1. Golpe Sombrío (Alto daño crítico)\n";
        cout << "2. Doble Corte (Dos golpes rápidos)\n";
        cout << "3. Desvanecer (Aumenta velocidad)\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); // Limpia el error de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
            cout << " Entrada inválida. Por favor, ingrese un número entre 1 y 3.\n\n";
            opcion = -1;
            continue;
        }

        if (opcion < 1 || opcion > 3) {
            cout << " Opción fuera de rango. Intente de nuevo.\n\n";
        }

    } while (opcion < 1 || opcion > 3);

    switch (opcion)
    {
    case 1:
    {
        bool critico;
        int danio = calcularDanioConCritico(60, 80, 60, critico);
        danio = static_cast<int>(danio * 1.5);
        objetivo.setVida(objetivo.getVida() - danio);

        cout << (critico ? " ¡Asesino realiza un GOLPE PODEROSÍSIMO!\n" : "💥 Asesino realiza un golpe poderoso.\n");
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

        cout << " El Asesino realiza un Doble Corte!\n";
        cout << "Corte 1: " << golpe1 << (critico1 ? " (CRÍTICO)\n" : "\n");
        cout << "Corte 2: " << golpe2 << (critico2 ? " (CRÍTICO)\n" : "\n");
        cout << "Daño Total: " << danioTotal << "\n";
        break;
    }

    case 3:
    {
        int aumento = AleatorizarEstadisticas(1, 10);
        velA += aumento;
        velocidad = velA;

        cout << " El Asesino se desvanece entre las sombras...\n";
        cout << " ¡Su velocidad aumenta en " << aumento << " puntos!\n";
        cout << " Velocidad actual: " << velA << "\n";
        break;
    }

    default:
        cout << " Algo salió mal. Opción no válida.\n";
        break;
    }
}

void Aliados::habilidadesSupport(Aliados& _aliadoMago, Aliados& _aliadoAsesino, Aliados& _aliadoTanque, Aliados& _aliadoSupport, Personaje& jugador, Enemigo& objetivo)
{
    int opcion;
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;

    bool entradaValida = false;

    do
    {
        std::cout << "\n¿Qué habilidad quiere usar el Support?\n";
        std::cout << "1. Tung Sahur: Rayo celestial con daño variable.\n";
        std::cout << "2. Healing: Recupera vida a todo el equipo.\n";
        std::cout << "3. Supremacía divina: Aumenta el ataque de todo el equipo.\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear(); // Limpia el error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta entrada inválida
            std::cout << " Entrada inválida. Por favor, ingrese un número entre 1 y 3.\n";
            continue;
        }

        if (opcion < 1 || opcion > 3) {
            std::cout << " Opción no válida. Intente de nuevo.\n";
            continue;
        }

        entradaValida = true;

        switch (opcion)
        {
        case 1:
        {
            int tungtungAtaque = AleatorizarEstadisticas(1, 1000);
            int probabilidadTung = AleatorizarEstadisticas(1, 100);
            int ataqueNormal = AleatorizarEstadisticas(15, 40);

            if (probabilidadTung <= 99)
            {
                std::cout << "\n 'Tung Sahur' desciende desde los cielos sobre el enemigo.\n";
                objetivo.setVida(objetivo.getVida() - tungtungAtaque);
                std::cout << objetivo.getNombre() << " sufre un daño de: " << tungtungAtaque << "\n";
            }
            else
            {
                objetivo.setVida(objetivo.getVida() - ataqueNormal);
                std::cout << objetivo.getNombre() << " recibe un golpe de luz de: " << ataqueNormal << "\n";
            }
            break;
        }

        case 2:
        {
            int healingVida = AleatorizarEstadisticas(5, 20);

            _aliadoAsesino.setVida(_aliadoAsesino.getVida() + healingVida);
            _aliadoMago.setVida(_aliadoMago.getVida() + healingVida);
            _aliadoSupport.setVida(_aliadoSupport.getVida() + healingVida);
            jugador.setVida(jugador.getVida() + healingVida);

            std::cout << "\n Una luz curativa envuelve a los aliados...\n";
            std::cout << "Todos recuperan +" << healingVida << " puntos de vida.\n";
            break;
        }

        case 3:
        {
            int buffAtaque = AleatorizarEstadisticas(5, 15);

            _aliadoAsesino.setAtaque(_aliadoAsesino.getAtaque() + buffAtaque);
            _aliadoMago.setAtaque(_aliadoMago.getAtaque() + buffAtaque);
            _aliadoSupport.setAtaque(_aliadoSupport.getAtaque() + buffAtaque);
            jugador.setAtaque(jugador.getAtaque() + buffAtaque);

            std::cout << "\n Una fuerza divina refuerza a los aliados...\n";
            std::cout << "Todos ganan +" << buffAtaque << " de ataque durante el combate.\n";
            break;
        }
        }

    } while (!entradaValida);
}



///////////////////////////////////////////////////////////////////////////////////////////////////
//Personaje

void Personaje::atacar(Enemigo& objetivo) {
    int critico = AleatorizarEstadisticas(1, 100);
    int danio = ataque - objetivo.getDefensa();
    if (danio < 0) danio = 0;

    bool esCritico = false;
    Personaje jugador;

    std::cout << "\n---- Daño" << jugador.getNombre() << "----\n\n";

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
        std::cout << "3. Ver inventario\n";
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {//Codigo de Asistente Gemini
            std::cin.clear(); // Limpia el error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta lo ingresado
            std::cout << "\nEntrada inválida. Por favor, ingrese un número entre 1 y 3.\n\n";
            opcion = -1; // Forzar que entre al bucle de nuevo
            continue;
        }

        if (opcion < 1 || opcion > 3) {
            std::cout << "\n Opción no válida. Intente de nuevo.\n\n";
            continue;
        }

        switch (opcion) {
        case 1:
            jugador.atacar(enemigo);
            break;
        case 2:
            cout  << " Habilidades \n";
            jugador.habilidades(enemigo);
            break;
        case 3:
            std::cout << "Que quieres usar? \n";
            jugador.mostrarInventario();
            jugador.eliminarPoción(listaObjetos);
            break;
        }

        system("pause");
        system("cls");

    } while (opcion < 1 || opcion > 3);

    system("cls");
}

void Personaje::habilidades(Enemigo& objetivo) {
    int opcion;
    int danio;
    system("cls");

    do {
        cout << "\n ¿Qué habilidad legendaria desea invocar?\n";
        cout << "1. Destructor Atómico (Daño fijo brutal)\n";
        cout << "2. Bola de Fuego Estelar (Daño aleatorio moderado)\n";
        cout << "3. Chanclazo Supremo (Ataque devastador aleatorio)\n";
        cout << "\n ¡No ingrese letras o el universo colapsará!\n";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Daño fijo
            danio = 60;
            objetivo.setVida(objetivo.getVida() - danio);
            cout << "\n ¡Lanzas el Destructor Atómico! El aire tiembla...\n";
            cout << " Daño infligido: " << danio << "\n";
            break;

        case 2:
            // Daño aleatorio entre 45 y 55
            danio = AleatorizarEstadisticas(45, 55);
            objetivo.setVida(objetivo.getVida() - danio);
            cout << "\n ¡Bola de Fuego Estelar desciende del cosmos!\n";
            cout << " El enemigo arde con " << danio << " puntos de daño.\n";
            break;

        case 3:
            // Daño crítico entre 1 y 100
            danio = AleatorizarEstadisticas(1, 150);
            objetivo.setVida(objetivo.getVida() - danio);
            cout << "\n ¡Chanclazo Supremo activado! La chancla cruza dimensiones...\n";
            cout << " Daño letal infligido: " << danio << " puntos.\n";
            break;

        default:
            cout << "\n Opción no válida. Por favor, elige un poder del menú.\n\n";
            break;
        }

        // Espera para que el jugador vea el resultado antes de limpiar
        system("pause");
        system("cls");

    } while (opcion < 1 || opcion > 3);  // Solo repite si elige mal
}

void Personaje::mostrarOro()
{
        cout << endl << "Oro inicial: " << oroJugador << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//Turnos

string turnoEquipo(Personaje& jugador, Enemigo& enemigo)
{
    string ordenTurno;

    int velJ1 = jugador.getVelocidad();
    int velJ2 = enemigo.getVelocidad();

    if (velJ1 > velJ2)
        ordenTurno = "Jugador";
    else
        ordenTurno = "Enemigo";

    return ordenTurno;
}


///////////////////////////////////////////////////////////////////////////////////////////////////

void desicionCombate(Personaje& jugador, Enemigo& enemigo)
{

    std::cout << "\n\n¡Fin del combate!\n";

    if (jugador.getVida() <= 0 && enemigo.getVida() > 0)
        std::cout << enemigo.getNombre() << " ha ganado el combate.\n";

    else if (enemigo.getVida() <= 0 && jugador.getVida() > 0)
        std::cout << jugador.getNombre() << " ha ganado el combate.\n";

    else
        std::cout << "Empate. Ambos han caído.\n";
}

void Combate(Personaje& jugador, Aliados& _aliadoM, Aliados& _aliadoT, Aliados& _aliadoA, Aliados& _aliadoS, Enemigo& _enemigo)
{
    bool todosVivos = true;

    int i = 0;
    do {
        std::cout << "---- Turno " << ++i << " ----" << std::endl;

        string ordenTurno = turnoEquipo(jugador, _enemigo);

        jugador.MostrarStats();
        _enemigo.MostrarStats();


        if (ordenTurno == "Jugador")
        {//Turno de los aliados
                //jugador
            jugador.eleccionJugador(jugador, _enemigo);
            _enemigo.MostrarStats();
            //Mago
            _aliadoM.MostrarStatsAliado(_aliadoM);
            _aliadoM.eleccionAliadoMago(jugador, _enemigo);
            _enemigo.MostrarStats();
            //Tanque
            _aliadoT.MostrarStatsAliado(_aliadoT);
            _aliadoT.eleccionAliadoTanque(_aliadoT, _aliadoM, _aliadoA, _aliadoS, jugador, _enemigo);
            _enemigo.MostrarStats();
            //Asesino
            _aliadoA.MostrarStatsAliado(_aliadoA);
            _aliadoA.eleccionAliadoAsesino(jugador, _aliadoA, _enemigo);
            _enemigo.MostrarStats();
            //Support
            _aliadoS.MostrarStatsAliado(_aliadoS);
            _aliadoS.eleccionAliadoSupport(_aliadoS, _aliadoM, _aliadoT, _aliadoA, jugador, _enemigo);
            _enemigo.MostrarStats();
            //Enemigo ataca
            _enemigo.atacarEnemigo(jugador, _aliadoM, _aliadoT, _aliadoA, _aliadoS);

        }
        else
        {//Turno enemigos
            _enemigo.atacarEnemigo(jugador, _aliadoM, _aliadoT, _aliadoA, _aliadoS);
            //jugador
            jugador.eleccionJugador(jugador, _enemigo);
            _enemigo.MostrarStats();
            //Mago
            _aliadoM.MostrarStatsAliado(_aliadoM);
            _aliadoM.eleccionAliadoMago(jugador, _enemigo);
            _enemigo.MostrarStats();
            //Tanque
            _aliadoT.MostrarStatsAliado(_aliadoT);
            _aliadoT.eleccionAliadoTanque(_aliadoT, _aliadoM, _aliadoA, _aliadoS, jugador, _enemigo);
            _enemigo.MostrarStats();
            //Asesino
            _aliadoA.MostrarStatsAliado(_aliadoA);
            _aliadoA.eleccionAliadoAsesino(jugador, _aliadoA, _enemigo);
            _enemigo.MostrarStats();
            //Support
            _aliadoS.MostrarStatsAliado(_aliadoS);
            _aliadoS.eleccionAliadoSupport(_aliadoS, _aliadoM, _aliadoT, _aliadoA, jugador, _enemigo);
            _enemigo.MostrarStats();

        }
        system("pause");
        system("cls");
        if (jugador.getVida() > 0 && _aliadoM.getVida() > 0 && _aliadoT.getVida() > 0 && _aliadoA.getVida() > 0 && _aliadoS.getVida() > 0) todosVivos = false;

    } while (todosVivos == false && _enemigo.getVida() > 0);

    desicionCombate(jugador, _enemigo);
}

void Personaje::agregarPocion(Pocion nuevaPocion) {
    listaObjetos.push_back(nuevaPocion);
}

void Personaje::mostrarInventario(){
    std::cout << "\n-- Inventario --" << std::endl;

    if (listaObjetos.empty()) {
        std::cout << "Inventario vacío." << std::endl;
    }
    else {
        for (size_t i = 0; i < listaObjetos.size(); ++i) {
            std::cout << i + 1 << ". ";
            listaObjetos[i].funcMostrarInfoPocion();
        }
    }
}

// Esta función permite al jugador usar una poción de su inventario y eliminarla después de usarla.
void Personaje::eliminarPoción(vector<Pocion>& _listaObjetos)
{
    int opcion;

    do {
        // Menú para mostrar opciones al jugador
        std::cout << "\n¿Qué desea hacer?\n";
        std::cout << "1. Primera poción\n";
        std::cout << "2. Segunda poción\n";
        std::cout << "3. Tercera poción\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        // Validación de entrada: si el usuario mete un valor no numérico
        if (std::cin.fail()) {
            std::cin.clear(); // Limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada inválida
            std::cout << "\nEntrada inválida. Por favor, ingrese un número entre 1 y 4.\n\n";
            opcion = -1; // Se usa -1 para que no entre en ninguna opción válida
            continue;
        }

        // Verifica si el inventario está vacío
        if (_listaObjetos.empty()) {
            std::cout << "No hay nada en tu inventario\n\n";
            break; // Sale del menú
        }

        // Si la opción está entre 1 y 3, y hay suficientes pociones en el vector
        if (opcion >= 1 && opcion <= 3 && opcion - 1 < _listaObjetos.size()) {
            // _listaObjetos[opcion - 1] accede a la posición correcta del vector (porque los vectores comienzan desde 0)
            // Se guarda esa poción seleccionada en una nueva variable tipo Pocion llamada pocionUsada
            // Esto permite trabajar fácilmente con ella más adelante
            Pocion pocionUsada = _listaObjetos[opcion - 1];

            // Se obtiene cuánta salud recupera esa poción
            int curacion = pocionUsada.getSaludPocion();

            // Se aplica la curación al jugador usando el método de la clase Personaje
            sumarVida(curacion);

            // Muestra al jugador lo que hizo
            std::cout << "Usaste " << pocionUsada.getNombrePocion()
                << " y recuperaste " << curacion << " de vida.\n";

            // Borra la poción usada del vector para que ya no esté en el inventario
            // Se usa (opcion - 1) para acceder al índice correcto
            _listaObjetos.erase(_listaObjetos.begin() + (opcion - 1));
        }
        // Si elige 4, simplemente sale del menú
        else if (opcion == 4) {
            std::cout << "\nSaliendo del menú de pociones\n";
        }
        // Si elige otra opción inválida
        else {
            std::cout << "\nOpción no válida. Intente de nuevo.\n\n";
        }

        system("pause"); // Pausa para que el jugador vea lo que pasó
        system("cls");   // Limpia la consola

    } while (opcion != 4); // Repite el menú hasta que el usuario decida salir
}

///////////////////////////////////////////////////////////////////////////////////////////////////


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
    Enemigo enemigo(100,200,25,50,200,250,5,15);
    

    Tienda tienda;//Crear objeto tienda

    jugador.pedirNombre();
    tienda.funcComprarPocion(jugador);
    Combate(jugador, AliadoM, AliadoT, AliadoA, AliadoS, enemigo);

    return 0;
}
