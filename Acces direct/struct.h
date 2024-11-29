#ifndef STRUCT_H
#define STRUCT_H
#include <bits/stdc++.h>

using namespace std;

const int MAX=80;
struct tRegistro{
	int codigo;
	char item[MAX];
	double valor;
};
int SIZE = sizeof(tRegistro);

void mostrar(tRegistro inv){
	cout<<inv.codigo<<endl;
	cout<<inv.item<<endl;
	cout<<inv.valor<<endl;
	cout<<endl;
}

#endif
