#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "SoldadoAsalto.cpp"
#include "SoldadoSoporte.cpp"




string token(string, string, int);
int numeroChars(string, char);

using namespace std;

int main()
{
	srand(time(NULL));
	
	fstream Leer;
	Leer.open("./soldados.txt");
	
	vector<Soldado*> equipo1;
	vector<Soldado*> equipo2;
	
	string linea;
	
	getline(Leer,linea);
	
	string equipo;
	
	equipo=token(linea,"&",1);
	
	int cantidadSoldados=numeroChars(equipo,'/')/6;
	
	string nom, tipo;
	int v,f,p1,p2;
	
	stringstream convert;
	
	for(int x=0;x<cantidadSoldados;x++)
	{
		tipo=token(equipo,"/",(x*6+1));
		
		nom=token(equipo, "/", (x*6)+2);
		
		convert<<token(equipo,"/",(x*6)+3);
		convert>>v;
		
		convert.str("");
		convert.clear();
		
		convert<<token(equipo,"/",(x*6)+4);
		convert>>f;
		
		convert.str("");
		convert.clear();
		
		convert<<token(equipo,"/",(x*6)+5);
		convert>>p1;
		
		convert.str("");
		convert.clear();
		
		convert<<token(equipo,"/",(x*6)+6);
		convert>>p2;
		
		convert.str("");
		convert.clear();
		
		if(tipo=="Asalto")
		{
			SoldadoAsalto *nuevo= new SoldadoAsalto(nom,v,f,p1,p2);
			equipo1.push_back(nuevo);
		}
		if(tipo=="Soporte")
		{
			SoldadoSoporte *nuevo= new SoldadoSoporte(nom,v,f,p1,p2);
			equipo1.push_back(nuevo);
		}
		
		
	}
	
	equipo=token(linea,"&",2);
	
	cantidadSoldados=numeroChars(equipo,'/')/6;
	
	for(int x=0;x<cantidadSoldados;x++)
	{
		tipo=token(equipo,"/",(x*6)+1);
		
		nom=token(equipo, "/", (x*6)+2);
		
		convert<<token(equipo,"/",(x*6)+3);
		convert>>v;
		
		convert.str("");
		convert.clear();
		
		convert<<token(equipo,"/",(x*6)+4);
		convert>>f;
		
		convert.str("");
		convert.clear();
		
		convert<<token(equipo,"/",(x*6)+5);
		convert>>p1;
		
		convert.str("");
		convert.clear();
		
		convert<<token(equipo,"/",(x*6)+6);
		convert>>p2;
		
		convert.str("");
		convert.clear();
		
		if(tipo=="Asalto")
		{
			SoldadoAsalto *nuevo= new SoldadoAsalto(nom,v,f,p1,p2);
			equipo2.push_back(nuevo);
		}
		if(tipo=="Soporte")
		{
			SoldadoSoporte *nuevo= new SoldadoSoporte(nom,v,f,p1,p2);
			equipo2.push_back(nuevo);
		}
		
	}
	
	int opcion=0;
	
	while(opcion!=3)
	{
		cout<<"************* Examen 1 *************\n\n1. Imprimir equipos\n2. Iniciar simulacion\n3. Salir\n\nSeleccion: ";
		cin>>opcion;
		if(opcion==1)
		{
			cout<<"\n\nEquipo1:\n\n";
			for(int x=0;x<equipo1.size();x++)
			{
				equipo1.at(x)->imprimir();
				cout<<endl;
			}
			
			cout<<"\n\nEquipo2:\n\n";
			for(int x=0;x<equipo2.size();x++)
			{
				equipo2.at(x)->imprimir();
				cout<<endl;
			}
		}
		if(opcion==2)
		{
			
			cout<<"\n\nComienza la batalla.\n\n\n";
			int random;
			Soldado *ofensivo;
			Soldado *defensivo;
			Sleep(3000);
			
			while(true)
			{
				
				random=rand() % equipo1.size();
				ofensivo=equipo1.at(random);
				random=rand() % equipo2.size();
				defensivo=equipo2.at(random);
				cout<<"Del equipo 1:\n\n";
				Sleep(500);
				ofensivo->imprimir();
				cout<<"\n\n    ataca a\n\n";
				Sleep(1000);
				defensivo->imprimir();
				defensivo->defensa(ofensivo->atacar(defensivo),ofensivo);
				Sleep(1500);
				
				if(defensivo->getPuntosVida()<=0)
				{
					cout<<"\n\n"<<defensivo->getNombre()<<" perdio la batalla.";
					equipo2.erase(equipo2.begin()+random);
					
					if(equipo2.size()==0)
					{
						Sleep(3000);
						cout<<"\n\nEl equipo 2 no puede continuar.";
						Sleep(1000);
						cout<<"\n\nEl equipo 1 gano.";
						break;
					}
				}
				else
				{
					cout<<"\n\n\nNuevo estado del soldado:\n\n";
					defensivo->imprimir();
				}
				
				getch();
				
				random=rand() % equipo2.size();
				ofensivo=equipo2.at(random);
				random=rand() % equipo1.size();
				defensivo=equipo1.at(random);
				cout<<"\n\n\nDel equipo 2:\n\n";
				Sleep(500);
				ofensivo->imprimir();
				cout<<"\n\n    ataca a\n\n";
				Sleep(1000);
				defensivo->imprimir();
				defensivo->defensa(ofensivo->atacar(defensivo),ofensivo);
				Sleep(1500);
				
				if(defensivo->getPuntosVida()<=0)
				{
					cout<<"\n\n"<<defensivo->getNombre()<<" perdio la batalla.";
					equipo1.erase(equipo1.begin()+random);
					
					if(equipo1.size()==0)
					{
						Sleep(3000);
						cout<<"\n\nEl equipo 1 no puede continuar.";
						Sleep(1000);
						cout<<"\n\nEl equipo 2 gano.";
						break;
					}
				}
				else
				{
					cout<<"\n\nNuevo estado del soldado:\n\n";
					defensivo->imprimir();
				}
				cout<<"\n\n";
				
				getch();
				
			}
			
			opcion=3;
		}
		
		
		cout<<"\n\n";
		
	}
	
	
	return 0;
}


string token(string cadena, string divisor, int pos){
       if(cadena.size()>0){
         char oracion[cadena.size()]; 
         for (int i=0;i<=cadena.size();i++)
         {
               oracion[i]=cadena[i];
         }                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);             
         while(ptrtoken){
             if(num==pos){ 
                return ptrtoken;                    
             }                 
             ptrtoken = strtok(NULL, d);
             num++;
         }
         return "";
       }else{
             return "";
       }
}

int numeroChars(string cadena, char caracter)
{
	int n=0;
	for(int x=0;x<cadena.size();x++)
	{
		if(cadena[x]==caracter)
			n++;
	}
	return n;
}
