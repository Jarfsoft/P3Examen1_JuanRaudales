#include <iostream>

#include "Soldado.cpp"

#ifndef SOLDADOSOPORTE_CPP
#define SOLDADOSOPORTE_CPP

using namespace std;

class SoldadoSoporte : public Soldado
{
	private:
		int blindaje;
		int camuflaje;
		
	public:
		SoldadoSoporte(string nom, int punVid, int punFue, int blin, int camu) : Soldado(nom, punVid, punFue)
		{
			blindaje=blin;
			camuflaje=camu;
		}
		string getTipo()
		{
			return "soporte";
		}
		atacar(Soldado* sol)
		{
			if(sol->getTipo()=="asalto")
			{
				return getPuntosFuerza()*(15+camuflaje);
			}
			if(sol->getTipo()=="soporte")
			{
				return getPuntosFuerza()*10;
			}
		}
		void defensa(int ata, Soldado* sol)
		{
			if(sol->getTipo()=="asalto")
			{
				setPuntosVida(getPuntosVida()-ata/(blindaje*2));
			}
			if(sol->getTipo()=="soporte")
			{
				setPuntosVida(getPuntosVida()-ata);
			}
		}
		void imprimir()
		{
			Soldado::imprimir();
			cout<<"\tTipo: Soldado Soporte\tBlindaje: "<<blindaje<<"\tCamuflaje: "<<camuflaje;
		}
			
};

#endif
