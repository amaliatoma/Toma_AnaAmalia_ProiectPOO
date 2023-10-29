﻿#include <iostream>
#include <string>
using namespace std;

class Teatru {
private:
	char* nume;
	string adresa;
	const int an_infiintare;
	int capacitateMax;
	int nrSali;
	int nrAngajati;
	static double reducereStudenti;
public:
	// getteri 
	char* getNume() {
		return this->nume;
	}
	string getAdresa() {
		return this->adresa;
	}
	const int getAn_infiintare() {
		return this->an_infiintare;
	}
	int getCapacitateMax() {
		return this->capacitateMax;
	}
	int getNrSali() {
		return this->nrSali;
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}
	static double getReducereStudenti() {
		return reducereStudenti;
	}

	//setteri
	void setNume(char* nume) {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	void setAdresa(string adresa) {
		if (adresa.length() > 3) this->adresa = adresa;
	}

	void setCapacitateMax(int capacitateMax) {
		this->capacitateMax = capacitateMax;
	}
	void setNrSali(int nrSali) {
		this->nrSali = nrSali;
	}
	
	void setNrAngajati(int nrAngajati) {
		this->nrAngajati = nrAngajati;
	}
	static void setReducereStudenti (double reducereNoua)
	{
		reducereStudenti = reducereNoua;
	}
	void afisare() {
		cout << "Nume teatru : " << this->nume << endl;
		cout << "Adresa: " << this->adresa << endl;
		cout << "An infiintare: " << this->an_infiintare << endl;
		cout << "Capacitate maxima: " << this->capacitateMax << endl;
		cout << "Numar sali: " << this->nrSali << endl;
		cout << "Numar de angajati: " << this->nrAngajati << endl;
		cout << "Reducere studenti: " << this->reducereStudenti << endl;
		cout << endl;
	}

	Teatru() : an_infiintare(1911) {
		this->nume = new char[strlen("Odeon") + 1];
		strcpy_s(this->nume, strlen("Odeon") + 1, "Odeon");
		this->adresa = "Calea Victoriei";
		this->capacitateMax = 500;
		this->nrSali = 10;
		this->nrAngajati = 50;
	}

	Teatru(const char* nume, string adresa, const int an, int capacitateMax, int nrSali,int nrAngajati) : an_infiintare(an) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->adresa = adresa;
		this->capacitateMax = capacitateMax;
		this->nrSali = nrSali;
		this->nrAngajati = nrAngajati;
	}
	Teatru(const char* nume, string adresa, const int an) : an_infiintare(an), capacitateMax(0), nrSali(0), nrAngajati(0) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->adresa = adresa;
	}
	//constructor de copiere : 
	Teatru(const Teatru& teatru) :an_infiintare(teatru.an_infiintare) {
		this->nume = new char[strlen(teatru.nume) + 1];
		strcpy_s(this->nume, strlen(teatru.nume) + 1, teatru.nume);
		this->adresa = teatru.adresa;
		this->capacitateMax = teatru.capacitateMax;
		this->nrSali = teatru.nrSali;
		this->nrAngajati = teatru.nrAngajati;
	}

	int capacitateSala() {
		int capacitateSala = this->capacitateMax / this->nrSali;
		return capacitateSala;
	}
	~Teatru() {
		if (this->nume != NULL) {
			delete this->nume;
		}
	}

};
double Teatru::reducereStudenti = 0.75;

class Piesa {
private:
	string nume;
	const string scriitor;
	char* data;
	double pretBilet;
	static double TVABilet;
	int BileteLuate;
public:
	//geteri
	string getNume() {
		return this->nume;
	}
	const string getScriitor() {
		return this->scriitor;
	}
	char* getData() {
		return this->data;
	}
	double getPretBilet() {
		return this->pretBilet;
	}
	static double getTVABilet() {
		return TVABilet;
	}
	int getBileteLuate() {
		return this->BileteLuate;
	}

	//seteri 
	void setNume(string nume) {
		if (nume.length() > 3) this->nume = nume;
	}
	void setData(char* data) {
		if (this->data != NULL) {
			delete[]this->data;
		}
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	void setPretBilet(double pretBile) {
		this->pretBilet = pretBilet;
	}
	static void setTVAbilet(double TVAnou)
	{
		TVABilet = TVAnou;
	}
	void setBileteLuate(int BileteLuate) {
		this->BileteLuate = BileteLuate;
	}

	void afisare() {
		cout << "Nume piesa: " << this->nume << endl;
		cout << "Producator: " << this->scriitor << endl;
		cout << "Data: " << this->data << endl;
		cout << "Pret Bilet: " << this->pretBilet << endl;
		cout << "TVA Bilet: " << this->TVABilet << endl;
		cout << "Numar bilete luate: " << this->BileteLuate << endl;
		cout << endl;

	}
	Piesa() : scriitor("Bogdan Olteanu") {
		this->nume = "Julieta fara Romeo";
		this->data = new char[strlen("29.10.2023") + 1];
		strcpy_s(this->data, strlen("29.10.2023") + 1, "29.10.2023");
		this->pretBilet = 99.99;
		this->BileteLuate = 40;
	}
	Piesa(string nume, const string scriitor, const char* data, double pretBilet, int BileteLuate) : scriitor(scriitor) {
		this->nume = nume;
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
		this->pretBilet = pretBilet;
		this->BileteLuate = BileteLuate;
	}
	Piesa(string nume, const string scriitor, const char* data) : scriitor(scriitor), pretBilet(10.89), BileteLuate(0) {
		this->nume = nume;
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	//constructor de copiere: 
	Piesa(const Piesa& piesa) : scriitor(piesa.scriitor) {
		this->nume = piesa.nume;
		this->data = new char[strlen(piesa.data) + 1];
		strcpy_s(this->data, strlen(piesa.data) + 1, piesa.data);
		this->pretBilet = piesa.pretBilet;
		this->BileteLuate = piesa.BileteLuate;
	}

	void sold() {
		cout << "Suma obtinuta de la vanzarea biletelor: " << this->pretBilet * this->BileteLuate << " de lei." << endl;
	}
	~Piesa() {
		if (this->data != NULL) {
			delete[] this->data;
		}
	}
};
double Piesa::TVABilet = 0.05;

class Actor {
private:
	string nume;
	const int an_nastere;
	char* nationalitate;
	string filmPtCareECunoscut;
	double salariuBrut;
	static double impozitPeSalariu;
public:
	//geteri
	string getNume() {
		return this->nume;
	}
	const int getAn_nastere() {
		return this->an_nastere;
	}
	char* getNationalitate() {
		return this->nationalitate;
	}
	string getFilmPtCareECunoscut() {
		return this->filmPtCareECunoscut;
	}
	double getSalariuBrut() {
		return this->salariuBrut;
	}
	static double getImpozitPeSalariu() {
		return impozitPeSalariu;
	}

	//seteri
	void setNume(string nume) {
		if (nume.length() > 3) this->nume = nume;
	}
	void setNationalitate(char* nationalitate) {
		if (this->nationalitate != NULL) {
			delete[]this->nationalitate;
		}
		this->nationalitate = new char[strlen(nationalitate) + 1];
		strcpy_s(this->nationalitate, strlen(nationalitate) + 1, nationalitate);
	}
	void setFilmPtCareECunoscut(string filmPtCareECunoscut) {
		if (filmPtCareECunoscut.length() > 2) {
			this->filmPtCareECunoscut = filmPtCareECunoscut;
		}
	}
	void setSalariuBrut(double salariuBrut) {
		this->salariuBrut = salariuBrut;
	}
	static void setImpozitPeSalariu(double impozitNou) {
		impozitPeSalariu = impozitNou;
	}

	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "An nastere: " << this->an_nastere << endl;
		cout << "Nationalitate: " << this->nationalitate << endl;
		cout << "Film pentru care e cunoscut/a: " << this->filmPtCareECunoscut << endl;
		cout << "Salariu brut: " << this->salariuBrut << endl;
		cout << "Impozit pe salariu: " << this->impozitPeSalariu << endl;
		cout << endl;
	}

	Actor() :an_nastere(1963) {
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
	Actor(string nume, const int an, const char* nationalitate) :an_nastere(an), filmPtCareECunoscut("Breakfast at Tiffany's"), salariuBrut(220000) {
		this->nume = nume;
		this->nationalitate = new char[strlen(nationalitate) + 1];
		strcpy_s(this->nationalitate, strlen(nationalitate) + 1, nationalitate);
	}
	//constructor de copiere:
	Actor(const Actor& actor) :an_nastere(actor.an_nastere) {
		this->nume = actor.nume;
		this->nationalitate = new char[strlen(actor.nationalitate) + 1];
		strcpy_s(this->nationalitate, strlen(actor.nationalitate) + 1, actor.nationalitate);
		this->filmPtCareECunoscut = actor.filmPtCareECunoscut;
		this->salariuBrut = actor.salariuBrut;
	}

	void salariuNet() {
		double salariuNet = this->salariuBrut - (this->impozitPeSalariu * this->salariuBrut);
		cout << "Salariul Net este: " << salariuNet<< endl;
	}

	~Actor() {
		if (this->nationalitate != NULL) {
			delete[]this->nationalitate;
		}
	}

};
double Actor::impozitPeSalariu = 0.16;

// functie globala 1
void locuriDisponibile(Teatru teatru, Piesa piesa) {
	int capacitateSala = teatru.capacitateSala();
	cout << "La piesa " << piesa.getNume() << " mai sunt disponibile " << (capacitateSala - piesa.getBileteLuate()) << " de locuri"<<endl;
}

//functie globala 2 
void anuntPublicitar(Teatru teatru, Piesa piesa, Actor actor) {
	cout << "Anunt Publicitar: ";
	cout << endl<<endl;
	cout << "      O aventura dramatica ca niciuna alta!" << endl<<endl;
	cout << "  Piesa ' " << piesa.getNume() <<" ' aduce pe scena o poveste captivanta si un actor principal incredibil, "
		<< actor.getNume() << endl;
	cout << "  Teatrul " << teatru.getNume() << " va invita sa experimentati magia teatrului intr-un mod unic." << endl;
	cout << "Pret bilet: " << piesa.getPretBilet() << " lei.";

}
// afisare cu ajutorul geterilor
void afisareTeatruGet(Teatru teatru) {
	cout << "Nume teatru : " << teatru.getNume() << endl;
	cout << "Adresa: " << teatru.getAdresa() << endl;
	cout << "An infiintare: " << teatru.getAn_infiintare() << endl;
	cout << "Capacitate maxima: " << teatru.getCapacitateMax() << endl;
	cout << "Numar sali: " << teatru.getNrSali() << endl;
	cout << "Numar de angajati: " << teatru.getNrAngajati() << endl;
	cout << "Reducere studenti: " << teatru.getReducereStudenti()<< endl;
	cout << endl;
}

void afisarePiesaGet(Piesa piesa) {
	cout << "Nume piesa: " << piesa.getNume() << endl;
	cout << "Scriitor: " << piesa.getScriitor()<< endl;
	cout << "Data: " << piesa.getData() << endl;
	cout << "Pret Bilet: " << piesa.getPretBilet() << endl;
	cout << "TVA Bilet: " << piesa.getTVABilet() << endl;
	cout << "Numar bilete luate: " << piesa.getBileteLuate() << endl;
	cout << endl;
}

void afisareActorGet(Actor actor) {
		cout << "Nume: " << actor.getNume() << endl;
		cout << "An nastere: " << actor.getAn_nastere() << endl;
		cout << "Nationalitate: " << actor.getNationalitate() << endl;
		cout << "Film pentru care e cunoscut/a: " << actor.getFilmPtCareECunoscut() << endl;
		cout << "Salariu brut: " << actor.getSalariuBrut() << endl;
		cout << "Impozit pe salariu: " << actor.getImpozitPeSalariu() << endl;
		cout << endl;
}

int main()
{
	Teatru teatru;
	teatru.afisare();
	cout << endl<< "Capacitatea salii este de: " << teatru.capacitateSala() << " de persoane"<<endl;

	Teatru teatru2("National Bucuresti", "Piata Universitatii", 1973, 2880,20, 150);
	teatru2.afisare();

	Teatru teatru3("Modern", "Strada Frumoasa", 2023);
	teatru3.afisare();

	cout << "--------------------------------------" << endl;

	Piesa piesa;
	piesa.afisare();
	cout << endl;
	piesa.sold();

	Piesa piesa2("Visul", "Alexa Bacau", "22.10.2023", 70.5, 0);
	piesa2.afisare();

	Piesa::setTVAbilet(0.1);

	Piesa piesa3("Nu vorbim despre asta", "Alexandra Felseghi", "6.11.2023");
	piesa3.afisare();

	cout << "--------------------------------------" << endl;

	Actor actor;
	actor.afisare();

	Actor actor2("Robert Downey Jr.", 1965, "SUA", "Avengers", 20000);
	actor2.afisare();

	Actor actor3("Audrey Hepburn", 1929, "Belgia");
	actor3.afisare();

	actor3.salariuNet();

	cout << "--------------------------------------" << endl;

	locuriDisponibile(teatru, piesa);

	cout << "--------------------------------------" << endl;

	anuntPublicitar(teatru, piesa, actor);

	cout << "--------------------------------------" << endl;
	afisareTeatruGet(teatru);
	afisarePiesaGet(piesa2);
	afisareActorGet(actor3);

}