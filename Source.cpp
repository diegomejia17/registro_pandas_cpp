#include <iostream>
#include <stdlib.h>

using namespace std;
struct pandas
{
	char nombre[25];
	float peso;
	int anio;
	char sexo[1] = {'\0'};
};

void llenado(pandas * p_ingresados, int,int *,int );
void impresion(int *, int, pandas * p_ingresados);

int main()
{
	int n = 0;
	int anio;
	cout << "ingrese el total de pandas a registrar" << endl;
	cin >> n;
	cout << "ingrese el anio actual" << endl;
	cin >> anio;
	pandas * p_ingresados = new pandas[n];

	int * maternidad;
	maternidad = new int [n];

	llenado(p_ingresados, n,maternidad,anio);

	system("pause");
	return 0;
}
void impresion(int *maternidad, int contador  , pandas * p_ingresados)
{
	system("cls");
	int aux;
	cout << "las pandas que pueden tener bebes son " << endl;
	for (int  i = 0; i < contador; i++)
	{
		cout <<"nombre:  "<< p_ingresados[maternidad[i]].nombre << "\n";
		cout <<"año de nacimiento :  " << p_ingresados[maternidad[i]].anio << "\n";
		cout << "peso :  " << p_ingresados[maternidad[i]].peso << "\n";
		cout <<"sexo :"<< p_ingresados[maternidad[i]].sexo << "\n";
		cout << "\n\n";
	}
}
void llenado(pandas * p_ingresados,int n, int *maternidad, int anio_a)
{
	bool aux = false, aux1= false;
	int contador = 0;

	for (int  i = 0; i < n; i++)
	{
		system("cls");
		char  clear ;
		char  auxiliar[20];
		cout << "ingrese los datos del panda #" << i + 1 << endl;
		clear = cin.get();
		cout << "nombre ?" << endl;
		cin.getline(p_ingresados[i].nombre,20,'\n');
		fflush(stdin);
		cout << "anio de nacimiento ?" << endl;
		do
		{
			cin >> p_ingresados[i].anio;
			fflush(stdin);
			if ( anio_a >= p_ingresados[i].anio)
			{

				aux1 = true;
			}
			else
			{
				aux1 = false;
				cout << "vuelva a ingresarlo" << endl;
			}

		} while (aux1 == false );

		cout << "sexo ? \t solo puede ingresar f o m " << endl;
		clear = cin.get();

		do
		{
			cin.getline(p_ingresados[i].sexo, 2, '\n');
			if (p_ingresados[i].sexo[0] == 102 || p_ingresados[i].sexo[0] == 109)
			{
				aux = true;
			}
			else
			{
				cout << "vuelva a ingresar" << endl;
				aux = false;
			}
		} while (aux== false);
		
		cout << "peso de nacimiento ?" << endl;
		cin >> p_ingresados[i].peso;

		if (p_ingresados[i].sexo[0] == 102 && (anio_a - p_ingresados[i].anio )>5)
		{
			maternidad[contador] = i;
			contador++;
		}
		fflush(stdin);
	}
	impresion(maternidad, contador, p_ingresados);
}