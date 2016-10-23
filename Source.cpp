#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
void desimt_dve_sveik(int x) {  //de�imtain� � dvejetain� (sveikoji dalis)
	vector <int> dve;
	int y;
	while (x > 0) {         //dalina kol dalinasi, o liekana � vektori�
		y = x % 2;
		x /= 2;
		dve.push_back(y);}
	for (int i = dve.size() - 1; i >= 0; i--) {     //nuo vektoriaus galo atspausdina
		cout << dve[i];
	}
	cout << ",";
	dve.clear();
	}
void desimt_dve_trup(long double y) {     // i� de�imtain�s � dvejetain� (trupmenin� dalis)   
	vector <int> dve;
	int x=0;
	for (int i = 50; i >= 0; i--) {         //daugina(51skai�iai po kablelio), sveik� skai�i� talpina � vektori�
		y *= 2;
		x = y;
		y -= x;
		dve.push_back(x);
	}
	for (int i =0; i <dve.size(); i++) { //atspausdina nuo prad�i�
		cout << dve[i];
	}
	dve.clear();
}
void desimt_ast_sveik(int x) { //i� de�imtain�s � a�tuntain�, sveik� dal� naudojant <iomanip> bibliotek�
	cout << oct << x << ",";
}
void desimt_ast_trup(long double y) { //i� de�imtain�s � a�tuntain� (trupmenin� dalis)
	vector <int> ast;
	int x=0;
	for (int i = 50; i >= 0; i--) { //51 skai�iai po kablelio, daugina, ir sveik� dal� � vektori� deda
		y *= 8;
		x = y;
		y -= x;
		ast.push_back(x);
	}
	for (int i = 0; i <ast.size(); i++) {
		cout << ast[i];
	}
}
void desimt_ses_sveik(int x) { //de�imtainis � �e�ioliktain�(sveikoji dalis). iomanip
	cout << hex << x << ",";
}
void desimt_ses_trup(long double y) { //desimtainis � �e�ioliktain�(trupmenin� dalis)
	vector <string> ses;
	int x = 0;
	string z = " ";
	for (int i = 50; i >= 0; i--) {
		y *= 16;
		x = y;
		y -= x;
		if (x > 9) {         //skai�iai didesni nei 9, ver�iami � raides
			switch (x) {
			case 10:
				z = "a";
				break;
			case 11:
				z = "b";
				break;
			case 12:
				z = "c";
				break;
			case 13:
				z = "d";
				break;
			case 14:
				z = "e";
				break;
			case 15:
				z = "f";
				break;
			}
		}
		else { z = to_string(x); }     //int ver�iami � string, kad d�ti � t� pat� vektori�
		ses.push_back(z);
	}
	for (int i = 0; i <ses.size(); i++) {
		cout << ses[i];
	}
	ses.clear();
}
double astunt_desimt_trup(vector<int> x) {
	long double y = 0;
		for (int i = x.size() - 1 ; i >= 0; --i) { //kod�l ne x.size()-2?????
			y += x[i];
			y /= 8;
		}
	return y;
}
int dve_desimt_sveik(vector<int> x) {     //i� dvejetain�s � de�imtain�(sveikoji dalis)
	int y = 0;
	for (int i = 0 ; i < x.size(); ++i) { //prideda kiekvien� vektoriaus skai�i� prie daugybos
		y *= 2;
		y += x[i];
	}
	return y;
}
double dve_desimt_trup(vector<int> x) {    //dvejetain� � de�imtain�(trupmenin� dalis)
	long double y = 0;
	for (int i = x.size() - 1; i >= 0; --i) { //dalinam ir pridedam vektoriaus skai�ius
		y += x[i];
		y /= 2;
	}
	return y;
}
double ses_desimt_trup(vector<char> x) {  //�e�ioliktain� � de�imtain�
	int y = 0;
	vector <int> pakaitinis;
	double z = 0;
	for (int i = 0; i < x.size(); ++i) {
		switch (x[i]) {     //char'ai � int
		case 'f':
			y = 15;
			break;
		case 'e':
			y = 14;
			break;
		case 'd':
			y = 13;
			break;
		case 'c':
			y = 12;
			break;
		case 'b':
			y = 11;
			break;
		case 'a':
			y = 10;
			break;
		default: 
			y = x[i]-'0';
		}
		pakaitinis.push_back(y);    //talpinam � nauj� int vektori�
	}
	for (int i = pakaitinis.size() - 1; i >= 0; --i) {  
		z += pakaitinis[i];
		z /= 16;
	}
	return z;
}
int main() {
	setlocale(LC_ALL, "Lithuanian");
	int pasirinkimas1 = 0;
	int pasirinkimas2 = 0;
	bool pasirin_cikl = true;
	double desimtain = 0;
	bool ivest_cikl = true;
	vector <int> dve_sveik;
	vector <int> dve_trup;
	vector <int> astunt_trup;
	vector <char> ses_trup;
	int x = 0;
	int z = 0;
	long double y = 0;
	char sk = '.';
	char exit = 't';
	
		cout << "KONVERTUOTI �: \n";
		cout << "-DVEJETAIN� [2] \n" << "-A�TUNTAIN� [8]\n" << "-DE�IMTAIN� [10]\n" << "-�E�IOLIKTAIN� [16]\n" << endl;
		while (pasirin_cikl == true) {            //pasirenka � k� konvertuoti
			cin >> pasirinkimas1;                            
			if (pasirinkimas1 == 2 || pasirinkimas1 == 8 || pasirinkimas1 == 10 || pasirinkimas1 == 16) {
				pasirin_cikl = false;                //patikrina ivedim�
			}
			else { cout << "Blogai �vestas pasirinkimas....m�ginkite dar kart�\n"; }
		}

		cout << "\nNORIMAS KONVERTUOTI SKAI�IUS: \n";
		cout << "-DVEJETAINIS [2]\n" << "-A�TUNTAINIS [8]\n" << "-DE�IMTAINIS [10]\n" << "-�E�IOLIKTAINIS [16]\n" << endl;
		while (pasirin_cikl == false) {
			cin >> pasirinkimas2;              // pasirenk� k� konvertuos
			if (pasirinkimas2 == pasirinkimas1) {           //tirkina �vedim�
				pasirin_cikl = false;
				cout << "J�s� pasirinkimai sutampta! pasirinkite i� naujo\n";
			}
			else if (pasirinkimas2 == 2 || pasirinkimas2 == 8 || pasirinkimas2 == 10 || pasirinkimas2 == 16) {
				pasirin_cikl = true;
			}
			else { cout << "Blogai �vestas pasirinkimas....m�ginkite dar kart�\n"; }
		}

//dvejetainio skai�iaus �vedimas ir skai�iavimai
		if (pasirinkimas2 == 2) {
			cout << "Veskite skai�ius atskirdami juos tarpais, nor�dami baigti �veskite bet kok� ne dvejetain� skai�i�\n";
			cout << "�veskite skai�iaus sveik�j� dal�: \n";   //sveika dalis
			cin >> x;
			while (x == 1 || x == 0) {                            //talpina � vektori�, nutraukia bet koks ne dvejetainis skai�ius
				dve_sveik.push_back(x);
				cin >> x;
			}
			cout << "�veskite skai�iaus trupmenin� dal�: \n";     //trupmenin� dalis
			cin >> x;
			while (x == 1 || x == 0) {                            //talpina � vektori�, nutraukia bet koks ne dvejetainis skai�ius
				dve_trup.push_back(x);
				cin >> x;
			}
			x = dve_desimt_sveik(dve_sveik);                        //sveika dalis paversta � de�imtain�
			y = dve_desimt_trup(dve_trup);                          //trupmenin� dalis paversta � de�imtain�

			if (pasirinkimas1 == 8) {
				desimt_ast_sveik(x);
				desimt_ast_trup(y);
			}
			else if (pasirinkimas1 == 10) {
				cout << setprecision(50) << x + y;
			}
			else if (pasirinkimas1 == 16) {
				desimt_ses_sveik(x);
				desimt_ses_trup(y);
			}
			dve_sveik.clear();
			dve_trup.clear();
		}

//a�tuntainio skai�iaus �vedimas ir skai�iavimai
		else if (pasirinkimas2 == 8) {
			cout << "�veskite skai�iaus sveik�j� dal�: \n";   //sveika dalis
			cin >> oct >> x >> dec;                                  //paver�ia i�kart � de�imtain�
			cin.clear();
			cout << "�veskite skai�iaus trupmenin� dal�: \n";
			cout << "Veskite skai�ius atskirdami juos tarpais, nor�dami baigti �veskite bet kok� ne a�tuntain� skai�i�" << endl;
			while ((cin>>z) && (z >= 0 && z <= 7)) {
				astunt_trup.push_back(z);
			}
			y = astunt_desimt_trup(astunt_trup);             //paversta � de�imtain�(trupmenin� dalis)
		    if (pasirinkimas1 == 2) {                        //i� a�tuntain�s � dvejetain�
				desimt_dve_sveik(x);
				desimt_dve_trup(y);
			}
			else if (pasirinkimas1 == 10) {                  // i6 a�tuntain�s � de�imtain�
				cout << setprecision(50) << x + y;
			}
			else if (pasirinkimas1 == 16) {                  // i� a�tuntain�s � �e�ioliktain�
				desimt_ses_sveik(x);
				desimt_ses_trup(y);
			}
			astunt_trup.clear(); //i�valom vektori�
			cin.clear();
		}

//de�imtainio skai�iaus inputas
		else if (pasirinkimas2 == 10) {
			cout << "�veskite skai�i�: \n";
			cin >> y;
			x = y;          //x sveika dalis 
			y -= x;           //y trupmenin� dalis
			if (pasirinkimas1 == 2) {
				desimt_dve_sveik(x);
				desimt_dve_trup(y);
			}
			else if (pasirinkimas1 == 8) {
				desimt_ast_sveik(x);
				desimt_ast_trup(y);
			}
			else if (pasirinkimas1 == 16) {
				desimt_ses_sveik(x);
				desimt_ses_trup(y);
			}
		}

//�e�ioliktainio skai�iaus �vedimas ir skai�iavimai
		else if (pasirinkimas2 == 16) {
			cout << "�veskite skai�iaus sveik�j� dal�: \n";   //sveika dalis
			cin >> hex >> x >> dec;                                  //paver�ia i�kart � de�imtain�
			cin.clear();
			cout << "�veskite skai�iaus trupmenin� dal�: \n";
			cout << "Veskite reik�mes atskirdami jas tarpais, nor�dami baigti �veskite [X]\n";
			while ((cin >> sk) && sk != 'x') {
				ses_trup.push_back(sk);
			}
			y = ses_desimt_trup(ses_trup);        //paversta � de�imtain� trupmenin� dalis
			if (pasirinkimas1 == 2) {
				desimt_dve_sveik(x);
				desimt_dve_trup(y);
			}
			else if (pasirinkimas1 == 8) {
				desimt_ast_sveik(x);
				desimt_ast_trup(y);
			}
			else if (pasirinkimas1 == 10) {
				cout << setprecision(50) << x + y;
			}
			ses_trup.clear(); //i�valom vektori�
		}

		cout << "\nAr norite i�eiti?\n Taip[t]\t\tNe[n]\n";
		cin.ignore();
		cin >> exit;                         //arba u�daro cikl� arba i� naujo
		if (exit == 'n') {
			main();
		}
	return 0;
}