#include <iostream>
using namespace std;

class Teatru {
public:
	char* nume;
	string adresa;
	const int an_infiintare;
	int capacitateMax;
	int nrAngajati;
	static double reducereStudenti;

	void afisare() {
		cout << "Nume teatru : " << this->nume << endl;
		cout << "Adresa: " << this->adresa << endl;
		cout << "An infiintare: " << this->an_infiintare << endl;
		cout << "Capacitate maxima: " << this->capacitateMax << endl;
		cout << "Numar de angajati: " << this->nrAngajati << endl;
		cout << "Reducere studenti: " << this->reducereStudenti << endl;
		cout << endl;
	}

	Teatru() : an_infiintare(1911) { 
		this->nume = new char[strlen("Odeon")+1];
		strcpy_s(this->nume, strlen("Odeon")+1, "Odeon");
		this->adresa = "Calea Victoriei";
		this->capacitateMax = 500;
		this->nrAngajati = 50;
	}

	Teatru(const char* nume, string adresa, const int an, int capacitateMax, int nrAngajati) : an_infiintare(an) {
		this->nume = new char[strlen(nume)+1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->adresa = adresa;
		this->capacitateMax = capacitateMax;
		this->nrAngajati = nrAngajati;
	}
	Teatru(const char* nume, string adresa, const int an) : an_infiintare(an), capacitateMax(0), nrAngajati(0) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->adresa = adresa;
	}
	~Teatru() {
		if (this->nume != NULL) {
			delete this->nume;
		}
	}
	static void modReducere(double reducereNoua)
	{
		reducereStudenti = reducereNoua;
	}

};
double Teatru::reducereStudenti = 0.75;

class Piesa {
public:
	string nume;
	const string scriitor;
	char* data;
	double pretBilet;
	static double TVABilet;
	int locuriDisponibile;

	void afisare() {
		cout << "Nume piesa: " << this->nume << endl;
		cout << "Producator: " << this->scriitor << endl;
		cout << "Data: " << this->data<<endl;
		cout << "Pret Bilet: " << this->pretBilet << endl;
		cout << "TVA Bilet: " << this->TVABilet<< endl;
		cout << "Locuri disponibile: " << this->locuriDisponibile << endl;
		cout << endl;

	}
	Piesa() : scriitor("Bogdan Olteanu") {
		this->nume = "Julieta fara Romeo";
		this->data = new char[strlen("29.10.2023") + 1];
		strcpy_s(this->data, strlen("29.10.2023") + 1, "29.10.2023");
		this->pretBilet = 99.99;
		this->locuriDisponibile = 10;
	}
	Piesa(string nume, const string scriitor, const char* data, double pretBilet, int locuriDisponibile) : scriitor(scriitor) {
		this->nume = nume;
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
		this->pretBilet = pretBilet;
		this->locuriDisponibile = locuriDisponibile;
	}
	Piesa(string nume, const string scriitor, const char* data) : scriitor(scriitor), pretBilet(10.89), locuriDisponibile(0) {
		this->nume = nume;
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	static void setTVAbilet(double TVAnou)
	{
		TVABilet=TVAnou;
	}
	~Piesa() {
		if (this->data != NULL) {
			delete[] this->data;
		}
	}
};
double Piesa::TVABilet = 0.05;

class Actor {
public:
	string nume;
	const int an_nastere;
	char* nationalitate;
	string filmPtCareECunoscut;
	double salariuBrut;
	static double impozitPeSalariu;

	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "An nastere: " << this->an_nastere << endl;
		cout << "Nationalitate: " << this->nationalitate << endl;
		cout << "Film pentru care e cunoscut/a: " << this->filmPtCareECunoscut << endl;
		cout << "Salariu brut: " << this->salariuBrut << endl;
		cout << "Impozit pe salariu: " << this->impozitPeSalariu << endl;
		cout << endl;
	}

	Actor():an_nastere(1963) {
		this->nume = "Brad Pitt";
		this->nationalitate = new char[strlen("SUA") + 1];
		strcpy_s(this->nationalitate, strlen("SUA") + 1, "SUA");
		this->filmPtCareECunoscut = "Fight Club";
		this->salariuBrut = 170000;
	}
	Actor(string nume, const int an, const char* nationalitate, string filmPtCareECunoscut, double salariuBrut) :an_nastere(an) {
		this->nume = nume;
		this->nationalitate = new char[strlen(nationalitate) + 1];
		strcpy_s(this->nationalitate, strlen(nationalitate) + 1, nationalitate);
		this->filmPtCareECunoscut = filmPtCareECunoscut;
		this->salariuBrut = salariuBrut;
	}
	Actor(string nume, const int an, const char* nationalitate) :an_nastere(an), filmPtCareECunoscut("Breakfast at Tiffany's"),salariuBrut(220000) {
		this->nume = nume;
		this->nationalitate = new char[strlen(nationalitate) + 1];
		strcpy_s(this->nationalitate, strlen(nationalitate) + 1, nationalitate);
	}

	void salariuNet() {
		int salariuNet = this->salariuBrut - (this->impozitPeSalariu * this->salariuBrut);
		cout << "Salariul Net este: " << salariuNet;
	}

	~Actor() {
		if (this->nationalitate != NULL) {
			delete[]this->nationalitate;
		}
	}

};
double Actor::impozitPeSalariu = 0.16;

int main()
{
	Teatru teatru;
	teatru.afisare();

	Teatru teatru2("National Bucuresti", "Piata Universitatii", 1973, 2880, 150);
	teatru2.afisare();

	Teatru::modReducere(0.9);

	Teatru teatru3("Modern", "Strada Frumoasa", 2023);
	teatru3.afisare();

	cout << "--------------------------------------"<<endl;

	Piesa piesa;
	piesa.afisare();

	Piesa piesa2("Visul", "Alexa Bacau", "22.10.2023", 70.5, 0);
	piesa2.afisare();

	Piesa::setTVAbilet(0.1);

	Piesa piesa3("Nu vorbim despre asta", "Alexandra Felseghi","6.11.2023");
	piesa3.afisare();

	cout << "--------------------------------------" << endl;
	
	Actor actor;
	actor.afisare();

	Actor actor2("Robert Downey Jr.", 1965, "SUA", "Avengers", 20000);
	actor2.afisare();

	Actor actor3("Audrey Hepburn", 1929,"Belgia");
	actor3.afisare();

	actor3.salariuNet();


}
