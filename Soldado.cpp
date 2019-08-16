#include <iostream>

#ifndef SOLDADO_CPP
#define SOLDADO_CPP

using namespace std;

class Soldado
{
	private:
		string nombre;
		int puntosVida;
		int puntosFuerza;
		
	public:
		Soldado(){}
		Soldado(string nom, int punVid, int punFue)
		{
			nombre.assign(nom);
			puntosVida=punVid;
			puntosFuerza=punFue;
		}
		string getNombre()
		{
			return nombre;
		}
		void setPuntosVida(int punVid)
		{
			puntosVida=punVid;
		}
		void setPuntosFuerza(int punFue)
		{
			puntosFuerza=punFue;
		}
		int getPuntosVida()
		{
			return puntosVida;
		}
		int getPuntosFuerza()
		{
			return puntosFuerza;
		}
		virtual int atacar(Soldado* sol){}
		virtual string getTipo(){}
		virtual void defensa(int ata, Soldado* sol){}
		virtual void imprimir()
		{
			cout<<"Nombre: "<<nombre<<"\tPuntos de vida: "<<puntosVida<<"\tPuntos de fuerza: "<<puntosFuerza;
		}
};

#endif
