#include<bits/stdc++.h>

using namespace std;

int main(){
	const int IGV=21;
	string ruc, producto;
	int unidades;
	double precio, neto, total, igv;
	char aux;
	ifstream archivo;
	ofstream archivo2;
	int cen, n;
	int contador=0;
	
	do{
		cout<<"elija lo que quiere hacer: ";
		cout<<"(si es la primera vez que entra, porfavor ingrese la opcion 1)"<<endl;
		cout<<"1. editar archivo "<<endl;
		cout<<"2. leer archivo "<<endl;
		cout<<"0. salir: ";
		cin>>n;
		switch(n){
			case 1: {
				contador=0;
				archivo2.open("compras.txt", ios::app);
				cout<<"RUC del cliente (X para terminar): "; cin>>ruc;
				while(ruc!="X" and ruc!="x"){
					cin.get(aux);
					cout<<"producto: ";
					getline(cin, producto);
					cout<<"unidades: ";
					cin>>unidades;
					cout<<"precio: ";
					cin>>precio;
					archivo2<<ruc<<" "<<unidades<<" "
						<<precio<<" "<<producto<<endl;
						cout<<endl;
					cout<<"RUC del cliente (X para terminar): "; cin>>ruc;
				}	
				archivo2<<"X";
				archivo2.close();
				break;
			}
			case 2:{
				contador=0;
				archivo.open("compras.txt");
				if(archivo.is_open()){
					archivo>>ruc;
					while(ruc!="X" and ruc!="x"){
						archivo>>unidades>>precio;
						archivo.get(aux);
						getline(archivo, producto);
						contador++;
						neto=unidades*precio;
						igv=neto*IGV/100;
						total=neto+igv;
						cout<<"compra "<<contador<<".-"<<endl;
						cout<< "  " <<producto<<": "<<unidades
							<<" x "<<fixed<<setprecision(2)
							<<precio<<" = "<<neto<<" - I.G.V.:"
							<<igv<<" - total: "<<total<<endl;
							cout<<endl;
						archivo>>ruc;
					}
					archivo.close();
				}
				else{
					cout<<"ERROR: no se pudo abrir el archivo"<<endl;
				}
				break;
			}	
		}
	} while(n!=0);
	return 0;
}