#include<bits/stdc++.h>
#include "struct.h"

using namespace std;

int main(){
	tRegistro registro;
	fstream archivo;
	int n;
	do{
		cout<<"elija lo que quiere hacer: ";
		cout<<"(si es la primera vez que entra, porfavor ingrese la opcion 1)"<<endl;
		cout<<"1. editar archivo "<<endl;
		cout<<"2. leer archivo "<<endl;
		cout<<"3. modificar archivo: "<<endl;
		cout<<"0. salir: ";
		cin>>n;
		switch(n){
				case 3: {
				archivo.open("bd.dat", ios::in | ios::out | ios::binary);
				archivo.seekg(0, ios::end);
				int pos=archivo.tellg();
				int numReg=pos/SIZE;
				cout<<"numero de registros: "<<numReg<<endl;
				int num;
				cout<<"registro numero?: ";
				cin>>num;
				if((num>0) and (num<=numReg)){
					archivo.seekg((num-1)*SIZE, ios::beg);
					archivo.read((char *) &registro, SIZE);
					mostrar(registro);
					cout<<"cambiar nombre [S/N]?: ";
					char c;
					cin.sync();
					cin>>c;
					if((c=='s') or (c=='S')){
						cout<<"Nombre: ";
						cin.sync();
						cin.getline(registro.item, 80);
					}
					cout<<endl<<"cambiar precio [S/N]?: ";
					cin.sync();
					cin>>c;
					if((c=='s') or (c=='S')){
						cout<<"Precio: ";
						cin.sync();
						cin>>registro.valor;
					}
					archivo.seekg((num-1)*SIZE, ios::beg);
					archivo.write((char *) &registro, SIZE);
					cout<<endl<<"Registro actualizado:"<<endl;
					archivo.seekg((num-1)*SIZE, ios::beg);
					archivo.write((char *) &registro, SIZE);
					mostrar(registro);
				}
				archivo.close();
				break;
			}
			case 2: {
				archivo.open("bd.dat", ios::in | ios::binary);
				archivo.read((char *) &registro, SIZE);
				int cuantos=archivo.gcount();
				while(cuantos==SIZE){
					mostrar(registro);
					archivo.read((char *) &registro, SIZE);
					cuantos=archivo.gcount();
				}
				archivo.close();
				break;
			}
			case 1:{
				archivo.open("bd.dat", ios::out | ios::binary);
				bool seguir=true;
				while(seguir){
					cout<<"codigo: ";
					cin.sync();
					cin>>registro.codigo;
					cout<<"nombre: ";
					cin.sync();
					cin.getline(registro.item, MAX);
					cout<<"precio: ";
					cin.sync();
					cin>>registro.valor;
					archivo.write((char *) &registro, SIZE);
					cout<<"otro [S/N]: ";
					char c;
					cin>>c;
					if((c=='n') or (c=='N')){
						seguir=false;
					}
				}
					archivo.close();
				}
				break;
			}	
		}while(n!=0);
		return 0;
	} 
