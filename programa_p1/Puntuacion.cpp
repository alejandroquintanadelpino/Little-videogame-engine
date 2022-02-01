#include "Puntuacion.h"

void Puntuacion::WriteFile()
{
    ofstream out;
    out.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        out.open("puntuaciones.txt", ios::app);
    }
    catch (ofstream::failure& e) {
        cerr << e.what() << endl;
    }

    string line;

    out << name << ": " << puntuacion << " puntos" << endl;

    out.close();
}

void Puntuacion::ReadFile()
{
    ifstream in;
    in.exceptions(ifstream::badbit);
    try
    {
        in.open("puntuaciones.txt");
    }
    catch (ifstream::failure& e) {
        cerr << e.what() << endl;
    }

    string line;

    cout << "PUNTUACIONES:" << endl;
    while (getline(in, line))
    {
        cout << line << endl;
    }

    in.close();
}

void Puntuacion::ReadPuntuacion()
{
    if (this->GetPuntuacion() >= 1000)
    {
        cout << "Su puntuacion ha sido: " << puntuacion << " puntos" << endl << "Ha hecho una partida INCREIBLE!" << endl << endl;
    }
    else
    {
        cout << "Su puntuacion ha sido: " << puntuacion << " puntos" << endl << endl;
    }
}
