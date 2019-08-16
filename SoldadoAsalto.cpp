#include <iostream>

#include "Soldado.cpp"

#ifndef SOLDADOASALTO_CPP
#define SOLDADOASALTO_CPP

using namespace std;

class SoldadoAsalto : public Soldado
{
	private:
		int velocidad;
		int fuerzaExtra;
		
	public:
		SoldadoAsalto(string nom, int punVid, int punFue, int velo, int fueExt) :  Soldado(nom, punVid, punFue)
		{
			velocidad=velo;
			fuerzaExtra=fueExt;
		}
		string getTipo()
		{
			return "asalto";
		}
		int atacar(Soldado* sol)
		{
			if(sol->getTipo()=="asalto")
			{
				return getPuntosFuerza()*10;
			}
			if(sol->getTipo()=="soporte")
			{
				return getPuntosFuerza()*(10+(velocidad*2));
			}
		}
		void defensa(int ata, Soldado* sol)
		{
			if(sol->getTipo()=="asalto")
			{
				setPuntosVida(getPuntosVida()-ata);
			}
			if(sol->getTipo()=="soporte")
			{
				setPuntosVida(getPuntosVida()-(ata/fuerzaExtra));
			}
		}
		void imprimir()
		{
			Soldado::imprimir();
			cout<<"\tTipo: Soldado Asalto\tVolocidad: "<<velocidad<<"\tFuerza extra: "<<fuerzaExtra;
		}
		
};

#endif
