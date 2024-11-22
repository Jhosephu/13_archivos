#include<bits/stdc++.h>

using namespace std;

const int MAX=80;
struct tRegistro{
	int codigo;
	char item[MAX];
	double valor;
};
int SIZE = sizeof(tRegistro);

int main(){
	tRegistro registro;
	fstream archivo;
	int n;
	do{
		cout<<"elija lo que quiere hacer: ";
		cout<<"(si es la primera vez que entra, porfavor ingrese la opcion 1)"<<endl;
		cout<<"1. editar archivo "<<endl;
		cout<<"2. leer archivo "<<endl;
		cout<<"0. salir: ";
		cin>>n;
		switch(n){
			case 2: {
				archivo.open("bd.dat", ios::in | ios::binary);
				archivo.read((char *) &registro, SIZE);
				int cuantos=archivo.gcount();
				while(cuantos==SIZE){
					//mostrar(registro);
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
	
