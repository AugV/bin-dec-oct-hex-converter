#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
void desimt_dve_sveik(int x) {  //değimtainë á dvejetainæ (sveikoji dalis)
	vector <int> dve;
	int y;
	while (x > 0) {         //dalina kol dalinasi, o liekana á vektoriø
		y = x % 2;
		x /= 2;
		dve.push_back(y);}
	for (int i = dve.size() - 1; i >= 0; i--) {     //nuo vektoriaus galo atspausdina
		cout << dve[i];
	}
	cout << ",";
	dve.clear();
	}
void desimt_dve_trup(long double y) {     // iğ değimtainës á dvejetainæ (trupmeninë dalis)   
	vector <int> dve;
	int x=0;
	for (int i = 50; i >= 0; i--) {         //daugina(51skaièiai po kablelio), sveikà skaièiø talpina á vektoriø
		y *= 2;
		x = y;
		y -= x;
		dve.push_back(x);
	}
	for (int i =0; i <dve.size(); i++) { //atspausdina nuo pradşiø
		cout << dve[i];
	}
	dve.clear();
}
void desimt_ast_sveik(int x) { //iğ değimtainës á ağtuntainæ, sveikà dalá naudojant <iomanip> bibliotekà
	cout << oct << x << ",";
}
void desimt_ast_trup(long double y) { //iğ değimtainës á ağtuntainæ (trupmeninë dalis)
	vector <int> ast;
	int x=0;
	for (int i = 50; i >= 0; i--) { //51 skaièiai po kablelio, daugina, ir sveikà dalá á vektoriø deda
		y *= 8;
		x = y;
		y -= x;
		ast.push_back(x);
	}
	for (int i = 0; i <ast.size(); i++) {
		cout << ast[i];
	}
}
void desimt_ses_sveik(int x) { //değimtainis á ğeğioliktainæ(sveikoji dalis). iomanip
	cout << hex << x << ",";
}
void desimt_ses_trup(long double y) { //desimtainis á ğeğioliktainæ(trupmeninë dalis)
	vector <string> ses;
	int x = 0;
	string z = " ";
	for (int i = 50; i >= 0; i--) {
		y *= 16;
		x = y;
		y -= x;
		if (x > 9) {         //skaièiai didesni nei 9, verèiami á raides
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
		else { z = to_string(x); }     //int verèiami á string, kad dëti á tà patá vektoriø
		ses.push_back(z);
	}
	for (int i = 0; i <ses.size(); i++) {
		cout << ses[i];
	}
	ses.clear();
}
double astunt_desimt_trup(vector<int> x) {
	long double y = 0;
		for (int i = x.size() - 1 ; i >= 0; --i) { //kodël ne x.size()-2?????
			y += x[i];
			y /= 8;
		}
	return y;
}
int dve_desimt_sveik(vector<int> x) {     //iğ dvejetainës á değimtainë(sveikoji dalis)
	int y = 0;
	for (int i = 0 ; i < x.size(); ++i) { //prideda kiekvienà vektoriaus skaièiø prie daugybos
		y *= 2;
		y += x[i];
	}
	return y;
}
double dve_desimt_trup(vector<int> x) {    //dvejetainë á değimtainæ(trupmeninë dalis)
	long double y = 0;
	for (int i = x.size() - 1; i >= 0; --i) { //dalinam ir pridedam vektoriaus skaièius
		y += x[i];
		y /= 2;
	}
	return y;
}
double ses_desimt_trup(vector<char> x) {  //ğeğioliktainë á değimtainæ
	int y = 0;
	vector <int> pakaitinis;
	double z = 0;
	for (int i = 0; i < x.size(); ++i) {
		switch (x[i]) {     //char'ai á int
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
		pakaitinis.push_back(y);    //talpinam á naujà int vektoriø
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
	
		cout << "KONVERTUOTI Á: \n";
		cout << "-DVEJETAINÁ [2] \n" << "-AĞTUNTAINÁ [8]\n" << "-DEĞIMTAINÁ [10]\n" << "-ĞEĞIOLIKTAINÁ [16]\n" << endl;
		while (pasirin_cikl == true) {            //pasirenka á kà konvertuoti
			cin >> pasirinkimas1;                            
			if (pasirinkimas1 == 2 || pasirinkimas1 == 8 || pasirinkimas1 == 10 || pasirinkimas1 == 16) {
				pasirin_cikl = false;                //patikrina ivedimà
			}
			else { cout << "Blogai ávestas pasirinkimas....mëginkite dar kartà\n"; }
		}

		cout << "\nNORIMAS KONVERTUOTI SKAIÈIUS: \n";
		cout << "-DVEJETAINIS [2]\n" << "-AĞTUNTAINIS [8]\n" << "-DEĞIMTAINIS [10]\n" << "-ĞEĞIOLIKTAINIS [16]\n" << endl;
		while (pasirin_cikl == false) {
			cin >> pasirinkimas2;              // pasirenkà kà konvertuos
			if (pasirinkimas2 == pasirinkimas1) {           //tirkina ávedimà
				pasirin_cikl = false;
				cout << "Jûsø pasirinkimai sutampta! pasirinkite iğ naujo\n";
			}
			else if (pasirinkimas2 == 2 || pasirinkimas2 == 8 || pasirinkimas2 == 10 || pasirinkimas2 == 16) {
				pasirin_cikl = true;
			}
			else { cout << "Blogai ávestas pasirinkimas....mëginkite dar kartà\n"; }
		}

//dvejetainio skaièiaus ávedimas ir skaièiavimai
		if (pasirinkimas2 == 2) {
			cout << "Veskite skaièius atskirdami juos tarpais, norëdami baigti áveskite bet koká ne dvejetainá skaièiø\n";
			cout << "Áveskite skaièiaus sveikàjà dalá: \n";   //sveika dalis
			cin >> x;
			while (x == 1 || x == 0) {                            //talpina á vektoriø, nutraukia bet koks ne dvejetainis skaièius
				dve_sveik.push_back(x);
				cin >> x;
			}
			cout << "Áveskite skaièiaus trupmeninæ dalá: \n";     //trupmeninë dalis
			cin >> x;
			while (x == 1 || x == 0) {                            //talpina á vektoriø, nutraukia bet koks ne dvejetainis skaièius
				dve_trup.push_back(x);
				cin >> x;
			}
			x = dve_desimt_sveik(dve_sveik);                        //sveika dalis paversta á değimtainæ
			y = dve_desimt_trup(dve_trup);                          //trupmeninë dalis paversta á değimtainæ

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

//ağtuntainio skaièiaus ávedimas ir skaièiavimai
		else if (pasirinkimas2 == 8) {
			cout << "Áveskite skaièiaus sveikàjà dalá: \n";   //sveika dalis
			cin >> oct >> x >> dec;                                  //paverèia iğkart á değimtainæ
			cin.clear();
			cout << "Áveskite skaièiaus trupmeninæ dalá: \n";
			cout << "Veskite skaièius atskirdami juos tarpais, norëdami baigti áveskite bet koká ne ağtuntainá skaièiø" << endl;
			while ((cin>>z) && (z >= 0 && z <= 7)) {
				astunt_trup.push_back(z);
			}
			y = astunt_desimt_trup(astunt_trup);             //paversta á değimtainæ(trupmeninë dalis)
		    if (pasirinkimas1 == 2) {                        //iğ ağtuntainës á dvejetainæ
				desimt_dve_sveik(x);
				desimt_dve_trup(y);
			}
			else if (pasirinkimas1 == 10) {                  // i6 ağtuntainës á değimtainæ
				cout << setprecision(50) << x + y;
			}
			else if (pasirinkimas1 == 16) {                  // iğ ağtuntainës á ğeğioliktainæ
				desimt_ses_sveik(x);
				desimt_ses_trup(y);
			}
			astunt_trup.clear(); //iğvalom vektoriø
			cin.clear();
		}

//değimtainio skaièiaus inputas
		else if (pasirinkimas2 == 10) {
			cout << "Áveskite skaièiø: \n";
			cin >> y;
			x = y;          //x sveika dalis 
			y -= x;           //y trupmeninë dalis
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

//ğeğioliktainio skaièiaus ávedimas ir skaièiavimai
		else if (pasirinkimas2 == 16) {
			cout << "Áveskite skaièiaus sveikàjà dalá: \n";   //sveika dalis
			cin >> hex >> x >> dec;                                  //paverèia iğkart á değimtainæ
			cin.clear();
			cout << "Áveskite skaièiaus trupmeninæ dalá: \n";
			cout << "Veskite reikğmes atskirdami jas tarpais, norëdami baigti áveskite [X]\n";
			while ((cin >> sk) && sk != 'x') {
				ses_trup.push_back(sk);
			}
			y = ses_desimt_trup(ses_trup);        //paversta á değimtainæ trupmeninë dalis
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
			ses_trup.clear(); //iğvalom vektoriø
		}

		cout << "\nAr norite iğeiti?\n Taip[t]\t\tNe[n]\n";
		cin.ignore();
		cin >> exit;                         //arba uşdaro ciklà arba iğ naujo
		if (exit == 'n') {
			main();
		}
	return 0;
}