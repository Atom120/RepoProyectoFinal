// CombateP00.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Sebastián Selvas García

#include <iostream>
#include <stdlib.h>   // para usar rand
#include <locale.h>   // Para poder cambiar el idioma y usar ñ
#include <time.h>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib> // Necesario para usar exit(0)

using namespace std;


// --- Declaración adelantada necesaria ---
class Enemigo;
class Aliados;  // Esto le dice al compilador que Aliados existirá
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
        oroJugador = AleatorizarEstadisticas(100,200);
    }

    int AleatorizarEstadisticas(int _minimo, int _maximo) {//Me ayudo mi compañero Jorge
        return _minimo + rand() % (_maximo - _minimo + 1);
    }

    void pedirNombre() {
        std::cout << "En medio del silencio, una brisa acaricia tu oído...\n";
        cout << "Tu nombre… dilo. " << "El mundo necesita saber quién se atreve a enfrentarlo\n";
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

    int setOroJugador(int _oroJUgador)
    {
        oroJugador +=_oroJUgador;
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
    vector<string> nomEnemigoPosible = { "Rey de las sombras", "Espada de Thelun", "Soda del mal","Centinela del Silencio","Eco del Recuerdo","Juez Caído",};

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
    // ===========================================================
    // MÉTODO DEL ENEMIGO: atacarEnemigo
    // ===========================================================
    //  • Recibe por referencia al jugador y a los cuatro aliados.
    //  • Guarda punteros a los aliados que sigan vivos en un vector.
    //  • 20 % de probabilidad de ataque en área (a todos los vivos).
    //  • De lo contrario, elige un aliado al azar y lo golpea.
    //  • Si no hay aliados vivos, ataca directamente al jugador.
    // ===========================================================

    void atacarEnemigo(Personaje& jugador, Aliados& aliadoMago,Aliados& aliadoTanque,Aliados& aliadoAsesino,Aliados& aliadoSupport)
    {
        // ------------------------------------------------------------------
        // 1. Crear vector de punteros a los aliados vivos
        // ------------------------------------------------------------------
        std::vector<Aliados*> aliadosVivos;

        if (aliadoMago.getVida() > 0) aliadosVivos.push_back(&aliadoMago);
        if (aliadoTanque.getVida() > 0) aliadosVivos.push_back(&aliadoTanque);
        if (aliadoAsesino.getVida() > 0) aliadosVivos.push_back(&aliadoAsesino);
        if (aliadoSupport.getVida() > 0) aliadosVivos.push_back(&aliadoSupport);

        // ------------------------------------------------------------------
        // 2. Determinar si será un ataque en área (20 % de probabilidad)
        // ------------------------------------------------------------------
        bool ataqueArea = AleatorizarEstadisticas(1, 100) >= 80;
        bool esCritico = false;

        // ------------------------------------------------------------------
        // 3. Si es ataque en área y hay aliados vivos
        // ------------------------------------------------------------------
        if (ataqueArea && !aliadosVivos.empty()) {
            std::cout << "\n" << nombre << " desata " << obtenerNombreAtaqueArea() << "!\n\n";

            for (Aliados* aliado : aliadosVivos) {
                int danio = ataque - aliado->getDefensa();
                if (danio < 0) danio = 0;

                if (AleatorizarEstadisticas(1, 100) >= 95) {
                    danio *= 2;
                    esCritico = true;
                }

                aliado->setVida(aliado->getVida() - danio);

                std::cout << nombre << " golpea a " << aliado->getNombre()
                    << " por " << danio << " de daño"
                    << (esCritico ? " ¡CRÍTICO!\n" : "\n");
            }

            return; // termina la función si fue ataque en área
        }

        // ------------------------------------------------------------------
        // 4. Si no es ataque en área, atacar a un aliado aleatorio
        // ------------------------------------------------------------------
        if (!aliadosVivos.empty()) {
            int indice = AleatorizarEstadisticas(0, static_cast<int>(aliadosVivos.size()) - 1);
            Aliados* aliadoObjetivo = aliadosVivos[indice];

            int danio = ataque - aliadoObjetivo->getDefensa();
            if (danio < 0) danio = 0;

            if (AleatorizarEstadisticas(1, 100) >= 95) {
                danio *= 2;
                esCritico = true;
            }

            aliadoObjetivo->setVida(aliadoObjetivo->getVida() - danio);

            std::cout << nombre << " ataca a " << aliadoObjetivo->getNombre()
                << " con " << obtenerNombreAtaque()
                << " causando " << danio << " de daño"
                << (esCritico ? " ¡CRÍTICO!\n" : "\n");
        }

        // ------------------------------------------------------------------
        // 5. Si no quedan aliados vivos → atacar al jugador
        // ------------------------------------------------------------------
        else {
            int danio = ataque - jugador.getDefensa();
            if (danio < 0) danio = 0;

            if (AleatorizarEstadisticas(1, 100) >= 95) {
                danio *= 2;
                esCritico = true;
            }

            jugador.setVida(jugador.getVida() - danio);

            std::cout << nombre << " ataca a " << jugador.getNombre()
                << " con " << obtenerNombreAtaque()
                << " causando " << danio << " de daño"
                << (esCritico ? " ¡CRÍTICO!\n" : "\n");
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
        if (nombre == "Rey de las sombras") return "Insufion sombria";
        else if (nombre == "Espada de Thelun") return "Corte espectral";
        else if (nombre == "Soda del mal") return "Explosión de Burbujas";
        else if (nombre == "Centinela del Silencio") return "Latigazo Sónico";
        else if (nombre == "Eco del Recuerdo") return "Maldición de la Memoria";
        else if (nombre == "Juez Caído") return "Veredicto Corrupto";
        else return "Ataque Desconocido";
    }

    // Devuelve el nombre del ataque en área según el nombre del enemigo
    string obtenerNombreAtaqueArea() const {
        if (nombre == "Rey de las sombras") return "Toremanta oscura";
        else if (nombre == "Espada de Thelun") return "Lluvia de espadas";
        else if (nombre == "Soda del mal") return "Burbujeo Explosivo";
        else if (nombre == "Centinela del Silencio") return "Onda de Silencio";
        else if (nombre == "Eco del Recuerdo") return "Ruptura Temporal";
        else if (nombre == "Juez Caído") return "Juicio Final";
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
        std::cout << "Lo comprado se enviara al cofre y en las peleas usas tu mochila" << endl << endl;
        std::cout << "En la mochila solo le caben 3 objetos a las vez" << endl;

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
// --------------------------------------------------------------
// Método: eleccionAliadoMago
// --------------------------------------------------------------
// • Permite al jugador controlar al Mago.
// • Si está muerto (vida <= 0), lo indica y no permite acciones.
// • Si está vivo, muestra menú para atacar o usar habilidad.
// --------------------------------------------------------------
void Aliados::eleccionAliadoMago(Personaje& jugador, Enemigo& enemigo)
{
    // Verificar si está muerto
    if (this->getVida() <= 0) {
        std::cout << "\n" << this->getNombre() << " está fuera de combate y no puede actuar.\n";

        system("pause");
        system("cls");
        return;  // Sale sin ejecutar el turno
    }

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
            std::cout << "Opción fuera de rango. Elige 1 o 2.\n";
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

// --------------------------------------------------------------
// Método: eleccionAliadoTanque
// --------------------------------------------------------------
// • Si el Tanque está muerto, lo indica y no puede actuar.
// • Si está vivo, permite atacar o usar habilidad de defensa.
// --------------------------------------------------------------
void Aliados::eleccionAliadoTanque(Aliados& aliadoTanque, Aliados& aliadoMago, Aliados& aliadoAsesino, Aliados& aliadoSupport, Personaje& jugador, Enemigo& enemigo) {
    if (aliadoTanque.getVida() <= 0) {
        std::cout << "\n" << aliadoTanque.getNombre() << " está fuera de combate y no puede actuar.\n";
        system("pause");
        system("cls");
        return;
    }

    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "Es el turno del Tanque\n";
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
            std::cout << "Opción fuera de rango. Intenta de nuevo.\n";
        }
        else {
            entradaValida = true;

            switch (opcion) {
            case 1:
                aliadoTanque.atacarAliados(enemigo);
                break;
            case 2:
                std::cout << "Habilidades:\n";
                habilidadesTanque(aliadoMago, aliadoAsesino, aliadoSupport, jugador, enemigo);
                break;
            }

            system("pause");
            system("cls");
        }

    } while (!entradaValida);
}

// --------------------------------------------------------------
// Método: eleccionAliadoAsesino
// --------------------------------------------------------------
// • Si el Asesino está muerto, lo indica y no actúa.
// • Si está vivo, permite atacar o usar su habilidad ofensiva.
// --------------------------------------------------------------
void Aliados::eleccionAliadoAsesino(Personaje& jugador, Aliados& aliadoAsesino, Enemigo& enemigo)
{
    if (aliadoAsesino.getVida() <= 0) {
        std::cout << "\n" << aliadoAsesino.getNombre() << " está fuera de combate y no puede actuar.\n";
        system("pause");
        system("cls");
        return;
    }

    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "Es el turno de " << aliadoAsesino.getNombre() << std::endl;

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
            std::cout << "Opción fuera de rango. Elige 1 o 2.\n";
        }
        else {
            entradaValida = true;

            switch (opcion) {
            case 1:
                aliadoAsesino.atacarAliados(enemigo);
                break;
            case 2:
                std::cout << "\nHabilidades\n";
                habilidadesAsesino(enemigo);
                break;
            }

            system("pause");
            system("cls");
        }

    } while (!entradaValida);
}

// --------------------------------------------------------------
// Método: eleccionAliadoSupport
// --------------------------------------------------------------
// • Si el Support está muerto, lo indica y no actúa.
// • Si está vivo, permite atacar o usar habilidades de apoyo.
// --------------------------------------------------------------
void Aliados::eleccionAliadoSupport(Aliados& aliadoMago, Aliados& aliadoTanque, Aliados& aliadoAsesino, Aliados& aliadoSupport, Personaje& jugador, Enemigo& enemigo)
{
    if (aliadoSupport.getVida() <= 0) {
        std::cout << "\n" << aliadoSupport.getNombre() << " está fuera de combate y no puede actuar.\n";
        system("pause");
        system("cls");
        return;
    }

    int opcion;
    bool entradaValida = false;

    do {
        std::cout << "Es el turno de " << aliadoSupport.getNombre() << std::endl;

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
            std::cout << "Opción fuera de rango. Elige 1 o 2.\n";
        }
        else {
            entradaValida = true;

            switch (opcion) {
            case 1:
                aliadoSupport.atacarAliados(enemigo);
                break;
            case 2:
                std::cout << "Habilidades\n";
                habilidadesSupport(aliadoMago, aliadoTanque, aliadoAsesino, aliadoSupport, jugador, enemigo);
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
    int danioBase = ataque - objetivo.getDefensa();  // Calcula el daño base restando defensa al ataque
    if (danioBase < 0) danioBase = 0;  // Asegura que el daño no sea negativo

    do {
        cout << "\n¿Qué habilidad quiere usar el Mago?\n";
        cout << "1. Destructor atómico de los reyes del inframundo interpolados sin fines de lucro\n";
        cout << "2. Bola de fuego estelar\n";
        cout << "3. Chanclazo\n";
        cout << "Opción: ";

        string entrada;      // Creamos una cadena para leer la entrada como texto
        cin >> entrada;      // Leemos entrada del usuario

        try {
            opcion = stoi(entrada); // Intenta convertir la cadena a número entero (string to int)
        }
        catch (...) {
            // Si stoi falla (porque la entrada no es un número), se ejecuta esto
            cout << "Entrada inválida. Por favor ingrese un número del 1 al 3.\n";
            opcion = -1;     // Valor inválido para forzar repetir el bucle
            continue;        // Salta el resto del bucle y lo reinicia
        }

        switch (opcion)
        {
        case 1: {
            // Cálculo del daño mágico: daño base multiplicado por 1.5, convertido a int
            int danioMagico = static_cast<int>(danioBase * 1.5); // static_cast convierte double → int
            objetivo.setVida(objetivo.getVida() - danioMagico);  // Resta el daño a la vida del enemigo
            cout << "¡Se lanza el hechizo Destructor atómico de los reyes del inframundo interpolados sin fines de lucro!\n";
            cout << objetivo.getNombre() << " recibe " << danioMagico << " de daño mágico.\n";
            break;
        }

        case 2: {
            int danioMagico = static_cast<int>(danioBase * 1.7);  // Multiplica el daño base por 1.7
            objetivo.setVida(objetivo.getVida() - danioMagico);
            cout << "¡Bola de fuego estelar lanzada!\n";
            cout << objetivo.getNombre() << " recibe " << danioMagico << " de daño mágico.\n";
            break;
        }

        case 3: {
            int danioMagico = danioBase * 2; // Multiplica por 2 sin conversión porque ya es int
            objetivo.setVida(objetivo.getVida() - danioMagico);
            cout << "¡Chanclazo infernal ejecutado!\n";
            cout << objetivo.getNombre() << " recibe " << danioMagico << " de daño mágico.\n";
            break;
        }

        default:
            // Si la opción no es válida (ej: 4, 99, etc.), informa al usuario
            cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }

    } while (opcion < 1 || opcion > 3); // Repite hasta que elija una opción válida
}
void Aliados::habilidadesTanque(Aliados& _aliadoMago, Aliados& _aliadoAsesino, Aliados& _aliadoSupport, Personaje& jugador, Enemigo& objetivo)
{
    int opcion;

    // Bucle para mostrar menú y validar entrada del usuario
    do {
        cout << "¿Qué habilidad quiere usar?\n";
        cout << "1. Ataque escudo paladín (Daño bajo)\n";
        cout << "2. Tralalea a su tralala (Reduce la defensa enemiga)\n";
        cout << "3. Presteza del escudo defensor (Aumenta defensa a todo el equipo)\n";
        cout << "\nSeleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) { // Si se ingresa algo que no es un número
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el resto de la entrada
            cout << "Entrada inválida. Por favor ingrese un número del 1 al 3.\n\n";
            opcion = -1; // Fuerza a repetir el menú
            continue;
        }

        if (opcion < 1 || opcion > 3) {
            cout << "\nOpción inválida. Intente de nuevo.\n\n";
        }

    } while (opcion < 1 || opcion > 3);  // Repite mientras la opción no esté entre 1 y 3

    // Se ejecuta la habilidad según la opción seleccionada
    switch (opcion)
    {
    case 1: {
        int golpe = AleatorizarEstadisticas(25, 45);  // Daño aleatorio
        objetivo.setVida(objetivo.getVida() - golpe); // Aplica daño

        cout << "\nEl tanque invoca su escudo y embiste al enemigo con fuerza brutal...\n";
        cout << nombre << " golpea con su escudo causando: " << golpe << " de daño a " << objetivo.getNombre() << "!\n";
        break;
    }

    case 2: {
        int reduccion = AleatorizarEstadisticas(1, 15); // Reducción aleatoria
        int nuevaDefensa = objetivo.getDefensa() - reduccion;
        if (nuevaDefensa < 0) nuevaDefensa = 0; // No permitir defensa negativa

        objetivo.setDefensa(nuevaDefensa);

        cout << "\n Un círculo mágico oscuro envuelve al enemigo...\n";
        cout << nombre << " reduce la defensa de " << objetivo.getNombre() << " en: " << reduccion << " puntos.\n";
        break;
    }

    case 3: {
        int defensaAumentada = AleatorizarEstadisticas(1, 15); // Buff de defensa

        // Se aplica a todos los aliados y al jugador
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
    int velA = velocidad; // Copia la velocidad actual del Asesino
    int opcion;

    // Menú con validación
    do {
        cout << "\n¿Qué habilidad quiere usar el Asesino?\n";
        cout << "1. Golpe Sombrío (Alto daño crítico)\n";
        cout << "2. Doble Corte (Dos golpes rápidos)\n";
        cout << "3. Desvanecer (Aumenta velocidad)\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); // Limpia error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia la entrada incorrecta
            cout << " Entrada inválida. Por favor, ingrese un número entre 1 y 3.\n\n";
            opcion = -1; // Repite
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
        int danio = calcularDanioConCritico(60, 80, 60, critico); // daño base + probabilidad
        danio = static_cast<int>(danio * 1.5); // Multiplica por 1.5

        objetivo.setVida(objetivo.getVida() - danio); // Aplica daño

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

        objetivo.setVida(objetivo.getVida() - danioTotal); // Aplica daño

        cout << " El Asesino realiza un Doble Corte!\n";
        cout << "Corte 1: " << golpe1 << (critico1 ? " (CRÍTICO)\n" : "\n");
        cout << "Corte 2: " << golpe2 << (critico2 ? " (CRÍTICO)\n" : "\n");
        cout << "Daño Total: " << danioTotal << "\n";
        break;
    }

    case 3:
    {
        int aumento = AleatorizarEstadisticas(1, 10); // Buff de velocidad
        velA += aumento;  // Modifica copia local
        velocidad = velA; // Asigna al atributo real

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
    int danio = ataque - objetivo.getDefensa(); // Daño base (aunque no se usa aquí realmente)
    if (danio < 0) danio = 0;

    bool entradaValida = false;

    // Menú con validación
    do
    {
        std::cout << "\n¿Qué habilidad quiere usar el Support?\n";
        std::cout << "1. Tung Sahur: Rayo celestial con daño variable.\n";
        std::cout << "2. Healing: Recupera vida a todo el equipo.\n";
        std::cout << "3. Supremacía divina: Aumenta el ataque de todo el equipo.\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            int healingVida = AleatorizarEstadisticas(30, 55); // Curación aleatoria

            // Cura a aliados + jugador
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
            int buffAtaque = AleatorizarEstadisticas(5, 15); // Buff de ataque

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

    if (jugador.getVida() <= 0 && enemigo.getVida() > 0) {
        std::cout << enemigo.getNombre() << " ha ganado el combate.\n";
        std::cout << "\nLa aventura ha llegado a su fin...\n";
        system("pause");
        exit(0); // Termina el programa
    }
    else if (enemigo.getVida() <= 0 && jugador.getVida() > 0) {
        std::cout << jugador.getNombre() << " ha ganado el combate.\n";
    }
    else if (jugador.getVida() <= 0 && enemigo.getVida() <= 0) {
        std::cout << "Empate. Ambos han caído.\n";
        std::cout << "\nLa aventura ha llegado a su fin...\n";
        system("pause");
        exit(0); // Termina el programa
    }
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

    Aliados aliadoM("Mago", 300, 350, 40, 55, 65, 85, 15, 30);
    Aliados aliadoT("Tanque", 380, 400, 70, 90, 55, 70, 12, 25);
    Aliados aliadoA("Asesino", 260, 300, 45, 60, 110, 140, 22, 35);
    Aliados aliadoS("Support", 250, 280, 40, 60, 60, 75, 18, 28);
    Personaje jugador;           


    //(int Vmin_, int Vmax_, int Dmin_, int Dmax_, int Amin_, int Amax_, int Velmin_, int Velmax_
    //vida, Defensa, ataque, Velocidad
    Enemigo enemigo1(120, 180, 15, 25, 120, 150, 8, 14);
    Enemigo enemigo2(160, 220, 20, 30, 140, 180, 10, 16);
    Enemigo enemigo3(200, 280, 25, 40, 170, 210, 12, 18);

    int decision;
    bool objetoVender = false;
    int desicionVender;

    Tienda tienda;//Crear objeto tienda
    system("color 70");// https://youtu.be/HVFDcLy7hXw?si=_Q1obJ3mZrMbmbve 05/06/2025

    cout << "────────────────────────────────────────────\n";
    cout << "EL SILENCIO DEL THÉLUN\n";
    cout << "────────────────────────────────────────────\n";

    cout << "Dicen que antes del último sol, hubo un grito...\n";
    cout << "pero nadie lo escuchó.\n";

    cout << "El mundo ha cambiado.Las tierras se agrietan bajo el peso de secretos antiguos, y el Thélun\n—una energía viva, caótica y misteriosa— \nha despertado de su letargo.\n\n";

    cout << "No todos sobreviven al susurro del Thélun.Algunos pierden la cordura.Otros ganan poder… pero a un precio.\n";

    cout << "Eres uno de los pocos que aún resiste.No estás solo.\nA tu lado, un grupo de aliados lucha por mantenerse cuerdos, fuertes... y humanos.\nDel otro lado, criaturas deformadas por el descontrol te acechan, guiadas por algo que ni siquiera entienden.\n";

    cout << "No hay marcha atrás.Cada decisión importa.Cada combate acerca la verdad.\n";

    cout << "Prepárate.La historia comienza ahora...\n\n";

    jugador.pedirNombre();

    cout << "Te despiertas en un lugar sin nombre, envuelto en sombras y ecos de voces antiguas.\n";
    cout << "Una figura encapuchada aparece ante ti y te dice:\n";
    cout << "\"Has sido convocado para restaurar el equilibrio.\n Tres Torres han despertado, y cada una guarda una parte de la verdad.\"\n";
    cout << "Sin darte opción a responder, el suelo tiembla y apareces frente a la Torre del Silencio, la primera de las tres.\n";
    cout << "Tus aliados —un Mago, un Tanque, un Asesino y un Support— se materializan a tu lado.\n";
    cout << "Las puertas se abren con un gemido metálico. Ha comenzado la prueba.\n";

    system("pause");
    system("cls");

    cout << "\nUna criatura monstruosa, mitad máquina, mitad sombra, emerge del interior. Es el Primer Guardián.\n";
    Combate(jugador, aliadoM, aliadoT, aliadoA, aliadoS, enemigo1);

    system("pause");
    system("cls");
    // Generar un número aleatorio entre 0 y 100
    int numeroAleatorio = rand() % 101;//

    if (numeroAleatorio >= 50)
    {
        cout << "Se te dropeo un objeto para vender\n";
        objetoVender = true;

    }

    system("pause");
    system("cls");
    
    cout << "Quiere vender tus objetos en la tienda\n";
    cout << "1. Si\n";
    cout << "2. No\n";
    cin >> desicionVender;
    if (desicionVender == 1)
    {
        if (objetoVender == true)
        {
            cout << "Ganaste 50 de oro";
            jugador.setOroJugador(50);
        }
        else
        {
            cout << "No tienes que vender";
        }
    }
    else
    {
        cout << "Opcion invalida, bye";
    }
    objetoVender = false;


    // OPCIÓN DE TIENDA
    cout << "\nTras la victoria, una voz resuena en tu mente depertando recuerdos del pasado\n";
    cout << "\nRevelanto cosas ante ti que antes existian y ahoera puedes materealizar\n";
    cout << "\nLa voz te pregunta:\n";
    cout << "\"¿Deseas descansar y prepararte en la tienda antes de avanzar?\"\n";
    cout << "1. Sí\n";
    cout << "2. No\n";
    cin >> decision;
    if (decision == 1) {
        tienda.funcComprarPocion(jugador);
    }

    system("puase");
    system("cls");

    cout << "\nAvanzan por una senda neblinosa hasta llegar a la Torre del Recuerdo.\n";
    cout << "Cada paso parece despertar fragmentos de memorias que no te pertenecen.\n";
    cout << "En lo alto de la torre, los espera un ser encapuchado que murmura:\n";
    cout << "\"Tu dolor es mío... tus errores, también.\"\n";

    system("pause");
    system("cls");

    Combate(jugador, aliadoM, aliadoT, aliadoA, aliadoS, enemigo2);


    if (numeroAleatorio >= 50)
    {
        cout << "Se te dropeo un objeto para vender\n";
        objetoVender = true;

    }

    cout << "Quiere vender tus objetos en la tienda\n";
    cout << "1. Si\n";
    cout << "2. No\n";
    cin >> desicionVender;
    if (desicionVender == 1)
    {
        if (objetoVender == true)
        {
            cout << "Ganaste 50 de oro";
            jugador.setOroJugador(50);
        }
        else
        {
            cout << "No tienes que vender";
        }
    }
    else
    {
        cout << "Opcion invalida, bye";
    }
    objetoVender = false;


    // OPCIÓN DE TIENDA
    cout << "\nLa torre se desmorona a sus espaldas. Un sendero secreto se revela.\n";
    cout << "\"¿Deseas visitar la tienda antes de entrar a la última torre?\"\n";
    cout << "1. Sí\n";
    cout << "2. No\n";
    cin >> decision;
    if (decision == 1) {
        tienda.funcComprarPocion(jugador);
    }
    system("puase");
    system("cls");

    cout << "\nLlegan a la base de la Torre del Juicio. Pero algo cambia...\n";
    cout << "Dos caminos se bifurcan:\n";
    cout << "1. Entrar por la puerta principal, brillante y custodiada.\n";
    cout << "2. Tomar una ruta lateral secreta cubierta por raíces oscuras.\n";
    cin >> decision;

    system("pause");
    system("cls");

    if (decision == 1) {
        cout << "\nToman la ruta directa. Los recibe una figura divina que representa la justicia.\n";
        cout << "\"Has llegado hasta aquí... pero aún debes enfrentar tu culpa.\"\n";

        system("pause");
        system("cls");

        Combate(jugador, aliadoM, aliadoT, aliadoA, aliadoS, enemigo3);
    }
    else {
        cout << "\nToman la ruta secreta. El ambiente se llena de corrupción. Han despertado al Juez Caído.\n";
        cout << "\"Las decisiones tienen peso, y el tuyo es demasiado oscuro.\"\n";

        system("pause");
        system("cls");

        Combate(jugador, aliadoM, aliadoT, aliadoA, aliadoS, enemigo3);
    }

    system("puase");
    system("cls");
    //Parte final
    if (jugador.getVida() > 0) {
        if (decision == 1) {
            cout << "\nEl Guardián de la Justicia cae. El equilibrio se ha restaurado.\n";
            cout << "Una luz te envuelve mientras todo desaparece. Has cumplido tu destino.\n";
        }
        else {
            cout << "\nEl Juez Caído ha sido vencido... pero algo permanece roto.\n";
            cout << "El mundo fue salvado, pero a un precio incierto. Tal vez tú mismo.\n";
        }
    }
    else {
        cout << "\nHas sido derrotado. Las Torres permanecerán selladas... por ahora.\n";
        cout << "Pero toda caída es una preparación para el ascenso.\n";
    }


    return 0;
}
