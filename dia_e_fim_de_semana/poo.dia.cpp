//allan stuart virmond 2379525

#include<iostream>
using namespace std;
#include "Dia.h";

int main() {

	Dia dia1(28, 11, 2020, sabado);
	dia1.info();

	Dia dia2(29, 11, 2020, domingo);
	dia2.info();

	Dia dia3(30, 11, 2020, segunda);
	dia3.info();

	Dia dia4(1, 12, 2020, terca);
	dia4.info();

	Dia dia5(2, 12, 2020, quarta);
	dia5.info();

	Dia dia6(3, 12, 2020, quinta);
	dia6.info();

	Dia dia7(4, 12, 2020, sexta);
	dia7.info();

	cout << "\n\n";
	system("pause");
}