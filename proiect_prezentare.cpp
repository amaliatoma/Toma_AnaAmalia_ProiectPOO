#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// clasa abstracta - Eveniment
class Eveniment {
private:
	int nrParticipanti;
	string locatie;
public:
	Eveniment() {
		this->nrParticipanti = 35;
		this->locatie = "No name";
	}
	// geteri
	int getNrParticipanti() {
		return this->nrParticipanti;
	}
	string getLocatie() {
		return this->locatie;
	}
	virtual double Casierie() = 0;

	virtual ~Eveniment() {
	};
};
// clasa abstracta - Persoana
class Persoana {
private:
	string email;
	string telefon;
public:
	string getEmail() {
		return this->email;
	}
	string getTelefon() {
		return this->telefon;
	}
	virtual string Activitate() = 0;
	virtual ~Persoana() {
	}
};

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
	static void setReducereStudenti(double reducereNoua)
	{
		reducereStudenti = reducereNoua;
	}
	// metoda de afisare
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
	// constructor FARA parametrii
	Teatru() : an_infiintare(1911) {
		this->nume = new char[strlen("Odeon") + 1];
		strcpy_s(this->nume, strlen("Odeon") + 1, "Odeon");
		this->adresa = "Calea Victoriei";
		this->capacitateMax = 500;
		this->nrSali = 10;
		this->nrAngajati = 50;
	}
	//constructor CU TOTI parametrii
	Teatru(const char* nume, string adresa, const int an, int capacitateMax, int nrSali, int nrAngajati) : an_infiintare(an) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->adresa = adresa;
		this->capacitateMax = capacitateMax;
		this->nrSali = nrSali;
		this->nrAngajati = nrAngajati;
	}
	// constructor CU O PARTE din parametrii
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
	// metoda -> calculeaza capacitatea per sala
	int capacitateSala() {
		int capacitateSala = this->capacitateMax / this->nrSali;
		return capacitateSala;
	}

	friend void TotalNrAngajati(Teatru teatru1, Teatru teatru2);

	// operator '=' 
	Teatru& operator=(const Teatru& teatru) {
		if (this != &teatru) {
			if (this->nume != NULL) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(teatru.nume) + 1];
			strcpy_s(this->nume, strlen(teatru.nume) + 1, teatru.nume);
			this->adresa = teatru.adresa;
			this->capacitateMax = teatru.capacitateMax;
			this->nrSali = teatru.nrSali;
			this->nrAngajati = teatru.nrAngajati;
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Teatru& teatru) {
		if (teatru.nume != NULL) {
			delete[]teatru.nume;
		}
		char nume[20];
		cout << "Nume: ";
		in >> nume;
		teatru.nume = new char[strlen(nume) + 1];
		strcpy_s(teatru.nume, strlen(nume) + 1, nume);
		cout << "Adresa: "; in >> teatru.adresa;
		cout << "Capacitate maxima: "; in >> teatru.capacitateMax;
		cout << "Numar sali: "; in >> teatru.nrSali;
		cout << "Numar angajati"; in >> teatru.nrAngajati;
		return in;
	}

	friend ifstream& operator>>(ifstream& in, Teatru& teatru) {
		if (teatru.nume != NULL) {
			delete[]teatru.nume;
		}
		char nume[20];
		in >> nume;
		teatru.nume = new char[strlen(nume) + 1];
		strcpy_s(teatru.nume, strlen(nume) + 1, nume);
		in >> teatru.adresa;
		in >> teatru.capacitateMax;
		in >> teatru.nrSali;
		in >> teatru.nrAngajati;
		return in;
	}

	// functie prietena, NU METODA 
	// operator '<<'
	friend ostream& operator<< (ostream& consola, const Teatru& teatru) {
		consola << "Nume: " << teatru.nume << endl;
		consola << "Adresa: " << teatru.adresa << endl;
		consola << "An infiintare: " << teatru.an_infiintare << endl;
		consola << "Capacitate Maxima: " << teatru.capacitateMax << endl;
		consola << "Numar sali: " << teatru.nrSali << endl;
		consola << "Numar angajati: " << teatru.nrAngajati << endl;
		consola << "Reducere Studenti: " << teatru.reducereStudenti << endl;
		consola << endl;
		return consola;
	}
	friend ofstream& operator<< (ofstream& consola, const Teatru& teatru) {
		consola << teatru.nume << endl;
		consola << teatru.adresa << endl;
		consola << teatru.an_infiintare << endl;
		consola << teatru.capacitateMax << endl;
		consola << teatru.nrSali << endl;
		consola << teatru.nrAngajati << endl;
		consola << teatru.reducereStudenti << endl;
		consola << endl;
		return consola;
	}

	friend bool operator< (Teatru teatru1, Teatru teatru2);

	// operator -
	friend int operator- (Teatru teatru1, Teatru teatru2) {
		return teatru1.nrSali - teatru2.nrSali;
	}

	~Teatru() {
		if (this->nume != NULL) {
			delete this->nume;
		}
	}

};
double Teatru::reducereStudenti = 0.75;

// operator < 
bool operator< (Teatru teatru1, Teatru teatru2) {
	return teatru1.capacitateMax < teatru2.capacitateMax;
}

class Piesa : public Eveniment {
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
	// metoda afisare 
	void afisare() {
		cout << "Nume piesa: " << this->nume << endl;
		cout << "Producator: " << this->scriitor << endl;
		cout << "Data: " << this->data << endl;
		cout << "Pret Bilet: " << this->pretBilet << endl;
		cout << "TVA Bilet: " << this->TVABilet << endl;
		cout << "Numar bilete luate: " << this->BileteLuate << endl;
		cout << endl;

	}
	//constructor FARA parametrii
	Piesa() : scriitor("Bogdan Olteanu") {
		this->nume = "Julieta fara Romeo";
		this->data = new char[strlen("29.10.2023") + 1];
		strcpy_s(this->data, strlen("29.10.2023") + 1, "29.10.2023");
		this->pretBilet = 99.99;
		this->BileteLuate = 40;
	}
	// constructor CU TOTI parametrii
	Piesa(string nume, const string scriitor, const char* data, double pretBilet, int BileteLuate) :
		scriitor(scriitor) {
		this->nume = nume;
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
		this->pretBilet = pretBilet;
		this->BileteLuate = BileteLuate;
	}
	// constructor parametrii PARTIAL
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

	double Casierie()
	{
		return this->getNrParticipanti() * this->pretBilet;
	}

	friend void TotalBilete(Piesa piesa1, Piesa piesa2);

	//operator '='
	Piesa operator=(Piesa piesa) {
		if (this != &piesa) {
			this->nume = piesa.nume;
			if (this->data != NULL) {
				delete[]this->data;
			}
			this->data = new char[strlen(piesa.data) + 1];
			strcpy_s(this->data, strlen(piesa.data) + 1, piesa.data);
			this->pretBilet = piesa.pretBilet;
			this->BileteLuate = piesa.BileteLuate;
		}
		return *this;
	}
	// operator '>>'
	friend istream& operator>> (istream& tastatura, Piesa& piesa) {

		cout << "Nume: ";
		tastatura >> piesa.nume;

		if (piesa.data != NULL)
		{
			delete[]piesa.data;
		}
		char data[15];
		cout << "Data: ";
		tastatura >> data;
		piesa.data = new char[strlen(data) + 1];
		strcpy_s(piesa.data, strlen(data) + 1, data);
		cout << "Pret Bilet: ";
		tastatura >> piesa.pretBilet;
		cout << "Bilete Luate: ";
		tastatura >> piesa.BileteLuate;
		return tastatura;

	}
	//operator << 
	friend ostream& operator<< (ostream& out, Piesa& piesa) {
		cout << "Nume piesa: " << piesa.nume << endl;
		cout << "Producator: " << piesa.scriitor << endl;
		cout << "Data: " << piesa.data << endl;
		cout << "Pret Bilet: " << piesa.pretBilet << endl;
		cout << "TVA Bilet: " << piesa.TVABilet << endl;
		cout << "Numar bilete luate: " << piesa.BileteLuate << endl;
		cout << endl;
		return out;
	}
	// operator ++ preincrementare 
	Piesa operator++ () {
		this->pretBilet = this->pretBilet + 16;
		return *this;
	}

	//operator ++ postincrementare
	Piesa operator++ (int) {
		Piesa temp = *this;
		this->pretBilet = this->pretBilet + 16;
		return temp;
	}
	// operator '!='
	friend bool operator!=(Piesa piesa1, Piesa piesa2) {
		return piesa1.pretBilet != piesa2.pretBilet;
	}

	void sold() {
		cout << "Suma obtinuta de la vanzarea biletelor: " << this->pretBilet * this->BileteLuate << " de lei." << endl;
	}

	// metoda care scrie intr-un fisier binar atribut cu atribut
	void serializare() {
		ofstream file("fisierBinarPiese.out", ios::binary | ios::out);
		if (file.is_open()) {
			int lungime_nume = this->nume.length();
			file.write((char*)&lungime_nume, sizeof(int));
			file.write((char*)&this->nume, (sizeof(string) * (this->nume.length())));

			int lungime_scriitor = this->scriitor.length();
			file.write((char*)&lungime_scriitor, sizeof(int));
			file.write((char*)&this->scriitor, (sizeof(const string) * this->scriitor.length()));

			int lungime_data = strlen(this->data);
			file.write((char*)&lungime_data, sizeof(lungime_data));
			file.write((char*)this->data, (sizeof(char) * (strlen(this->data) + 1)));

			file.write((char*)&this->pretBilet, sizeof(double));
			file.write((char*)&this->TVABilet, sizeof(double));
			file.write((char*)&this->BileteLuate, sizeof(int));
			file.close();
		}
	}
	~Piesa() {
		if (this->data != NULL) {
			delete[] this->data;
		}
	}
};
double Piesa::TVABilet = 0.05;

class Actor : public Persoana {
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
	// metoda de afisare
	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "An nastere: " << this->an_nastere << endl;
		cout << "Nationalitate: " << this->nationalitate << endl;
		cout << "Film pentru care e cunoscut/a: " << this->filmPtCareECunoscut << endl;
		cout << "Salariu brut: " << this->salariuBrut << endl;
		cout << "Impozit pe salariu: " << this->impozitPeSalariu << endl;
		cout << endl;
	}
	//constructor FARA parametrii
	Actor() :an_nastere(1963) {
		this->nume = "Brad Pitt";
		this->nationalitate = new char[strlen("SUA") + 1];
		strcpy_s(this->nationalitate, strlen("SUA") + 1, "SUA");
		this->filmPtCareECunoscut = "Fight Club";
		this->salariuBrut = 170000;
	}
	//constructor CU TOTI parametrii
	Actor( string nume, const int an, const char* nationalitate,
		string filmPtCareECunoscut, double salariuBrut) :an_nastere(an) {
		this->nume = nume;
		this->nationalitate = new char[strlen(nationalitate) + 1];
		strcpy_s(this->nationalitate, strlen(nationalitate) + 1, nationalitate);
		this->filmPtCareECunoscut = filmPtCareECunoscut;
		this->salariuBrut = salariuBrut;
	}
	// constructor parametrii PARTIAL
	Actor(string nume, const int an, const char* nationalitate) :an_nastere(an),
		filmPtCareECunoscut("Breakfast at Tiffany's"), salariuBrut(220000) {
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
	// metoda -> salariul net
	void salariuNet() {
		double salariuNet = this->salariuBrut - (this->impozitPeSalariu * this->salariuBrut);
		cout << "Salariul Net este: " << salariuNet << endl;
	}
	// operator '='
	Actor operator=(Actor actor) {
		if (this != &actor) {
			this->nume = actor.nume;
			if (this->nationalitate != NULL) {
				delete[]this->nationalitate;
			}
			this->nationalitate = new char[strlen(actor.nationalitate) + 1];
			strcpy_s(this->nationalitate, strlen(actor.nationalitate) + 1, actor.nationalitate);
			this->filmPtCareECunoscut = actor.filmPtCareECunoscut;
			this->salariuBrut = actor.salariuBrut;
		}
		return *this;
	}

	string Activitate() {
		return "Actorul interpreteaza un rol.";
	}
	// operator -- pre
	Actor operator--() {
		this->salariuBrut = this->salariuBrut - 400;
		return *this;
	}
	//operator -- post
	Actor operator--(int) {
		Actor temp = *this;
		this->salariuBrut = this->salariuBrut - 400;
		return temp;
	}
	// operator '>'
	friend bool operator>(Actor actor1, Actor actor2) {
		return actor1.salariuBrut > actor2.salariuBrut;
	}

	friend int operator-= (Actor actor1, Actor actor2);

	// operator >> 
	friend istream& operator>>(istream& in, Actor& actor) {
		cout << "Nume: "; in >> actor.nume;
		if (actor.nationalitate != NULL) {
			delete[]actor.nationalitate;
		}
		char nationalitate[20];
		cout << "Nationalitate: ";
		in >> nationalitate;
		actor.nationalitate = new char[strlen(nationalitate) + 1];
		strcpy_s(actor.nationalitate, strlen(nationalitate) + 1, nationalitate);
		cout << "Film pentru care este cunoscut: "; in >> actor.filmPtCareECunoscut;
		cout << "Salariu Brut: "; in >> actor.salariuBrut;
		return in;
	}
	// operator << 
	friend ostream& operator<<(ostream& out, Actor& actor) {
		cout << "Nume: " << actor.nume << endl;
		cout << "An nastere: " << actor.an_nastere << endl;
		cout << "Nationalitate: " << actor.nationalitate << endl;
		cout << "Film pentru care e cunoscut/a: " << actor.filmPtCareECunoscut << endl;
		cout << "Salariu brut: " << actor.salariuBrut << endl;
		cout << "Impozit pe salariu: " << actor.impozitPeSalariu << endl;
		cout << endl;
		return out;
	}
	void afisareInFisierBinar() {
		fstream fisierBinarActorOut("fisierBinarActor.out", ios::binary | ios::out);
		if (fisierBinarActorOut.is_open()) {
			int sizeNume = this->nume.length();
			fisierBinarActorOut.write((char*)&sizeNume, sizeof(int));
			fisierBinarActorOut.write(this->nume.c_str(), sizeNume);
			fisierBinarActorOut.write((char*)&this->an_nastere, sizeof(int));
			int sizeNationalitate = strlen(this->nationalitate);
			fisierBinarActorOut.write((char*)&sizeNationalitate, sizeof(int));
			fisierBinarActorOut.write((char*)this->nationalitate, (sizeof(char) * (strlen(nationalitate) + 1)));
			int sizeFilmCunoscut = this->filmPtCareECunoscut.length();
			fisierBinarActorOut.write((char*)&sizeFilmCunoscut, sizeof(int));
			fisierBinarActorOut.write(this->filmPtCareECunoscut.c_str(), sizeFilmCunoscut);
			fisierBinarActorOut.write((char*)&this->salariuBrut, sizeof(double));
			fisierBinarActorOut.write((char*)&this->impozitPeSalariu, sizeof(double));
			fisierBinarActorOut.close();
		}
	}
	// eroare logica la citirea din fis Binar :( 
	//void citireDinFisierBinar() {
	//	fstream fisierBinarActorIn("fisierBinarActor.out", ios::binary | ios::out);
	//	if (fisierBinarActorIn.is_open()) {
	//		int sizeNume;
	//		fisierBinarActorIn.read((char*)&sizeNume, sizeof(int));
	//		//alocam memorie pt sirul citit
	//		char* buffer = new char[sizeNume+1];
	//		buffer[sizeNume] = '\0';
	//		//citim sirul de la fisier
	//		fisierBinarActorIn.read(buffer, sizeNume);
	//		this->nume = buffer;
	//		delete[]buffer;
	//		fisierBinarActorIn.read((char*)&this->an_nastere, sizeof(int));
	//		int sizeNationalitate;
	//		fisierBinarActorIn.read((char*)&sizeNationalitate, sizeof(int));
	//		//alocam memorie pt sir
	//		if (this->nationalitate != NULL) {
	//			delete[]this->nationalitate;
	//		}
	//		this->nationalitate = new char[sizeNationalitate + 1];
	//		this->nationalitate[sizeNationalitate] = '\0';
	//		fisierBinarActorIn.read((char*)this->nationalitate, sizeof(char)*sizeNationalitate+1);
	//		int sizeFilmCunoscut;
	//		fisierBinarActorIn.read((char*)&sizeFilmCunoscut, sizeof(int));
	//		//alocam memorie pt sirul citit
	//		char* buffer3 = new char[sizeFilmCunoscut+1];
	//		buffer3[sizeFilmCunoscut] = '\0';
	//		fisierBinarActorIn.read(buffer3, sizeFilmCunoscut);
	//		this->filmPtCareECunoscut = buffer3;
	//		delete[]buffer3;
	//		fisierBinarActorIn.read((char*)&this->salariuBrut, sizeof(double));
	//		fisierBinarActorIn.read((char*)&this->impozitPeSalariu, sizeof(double));
	//		fisierBinarActorIn.close();
	//	}
	//}
	~Actor() {
		if (this->nationalitate != NULL) {
			delete[]this->nationalitate;
		}
	}
};
double Actor::impozitPeSalariu = 0.16;

class Film : public Eveniment {
	int nrActori;
	Actor* v_actor;
	float notaIMDb;
	string numeFilm;
	const int an;
	int pretBilet;
public:
	// geteri
	int getNrActori() {
		return this->nrActori;
	}
	Actor* getV_actori() {
		return this->v_actor;
	}
	float getNotaIMDb() {
		return this->notaIMDb;
	}
	string getNumeFilm() {
		return this->numeFilm;
	}
	const int getAn() {
		return this->an;
	}
	int getPretBilet() {
		return this->pretBilet;
	}
	// seteri
	void setNrActori(int nr) {
		this->nrActori = nr;
	}
	void setV_actor(Actor* v_actor_nou) {
		if (this->v_actor != NULL) {
			delete[]this->v_actor;
		}
		v_actor = new Actor[this->nrActori];
		for (int i = 0; i < this->nrActori; i++) {
			v_actor[i] = v_actor_nou[i];
		}
	}
	void setNotaIMDb(float notaNoua) {
		this->notaIMDb = notaNoua;
	}
	void setNumeFilm(string nume) {
		this->numeFilm = nume;
	}
	void setPretBilet(int pretBiletNou) {
		this->pretBilet = pretBiletNou;
	}
	// constructor fara parametrii
	Film() : an(2013), Eveniment() {
		this->nrActori = 3;
		this->v_actor = new Actor[this->nrActori];
		for (int i = 0; i < this->nrActori; i++) {
			this->v_actor[i] = Actor();
		}
		this->notaIMDb = 6.8;
		this->numeFilm = "Divergent";
		this->pretBilet = 30;
	}
	// constructor cu parametrii 
	Film(int nrActori, Actor* v_actor, float notaIMDb,
		string numeFilm, const int an, int pretBilet) :an(an) {
		this->nrActori = nrActori;
		this->v_actor = new Actor[this->nrActori];
		for (int i = 0; i < this->nrActori; i++) {
			this->v_actor[i] = v_actor[i];
		}
		this->notaIMDb = notaIMDb;
		this->numeFilm = numeFilm;
		this->pretBilet = pretBilet;
	}
	// constructor de copiere
	Film(const Film& film) : an(film.an) {
		this->nrActori = film.nrActori;
		this->v_actor = new Actor[this->nrActori];
		for (int i = 0; i < this->nrActori; i++) {
			this->v_actor[i] = film.v_actor[i];
		}
		this->notaIMDb = film.notaIMDb;
		this->numeFilm = film.numeFilm;
		this->pretBilet = film.pretBilet;
	}

	double Casierie() {
		return this->getNrParticipanti() * this->pretBilet;
	}
	//destructor 
	~Film() {
		if (this->v_actor != NULL) {
			delete[]this->v_actor;
		}
	}
	// operator > 
	friend bool operator>(Film film1, Film film2) {
		return film1.notaIMDb > film2.notaIMDb;
	}
	// operator = 
	Film& operator= (const Film& film) {
		if (this != &film) {
			this->nrActori = film.nrActori;
			if (this->v_actor != NULL) {
				delete[]this->v_actor;
			}
			this->v_actor = new Actor[film.nrActori];
			for (int i = 0; i < this->nrActori; i++) {
				this->v_actor[i] = film.v_actor[i];
			}
			this->notaIMDb = film.notaIMDb;
			this->numeFilm = film.numeFilm;
			this->pretBilet = film.pretBilet;
		}
		return *this;
	}
	// operator << afisare
	friend ostream& operator<< (ostream& out, const Film& film) {
		cout << "Nume film: " << film.numeFilm << endl;
		cout << "An : " << film.an << endl;
		cout << "Nota IMDb: " << film.notaIMDb << endl;
		cout << "Nr actori: " << film.nrActori << endl;
		cout << "Actori : " << endl;
		for (int i = 0; i < film.nrActori; i++) {
			cout << film.v_actor[i];
			cout << endl;
		}
		cout << endl;
		cout << "Pret Bilet: " << film.pretBilet << endl;
		return out;
	}
	// operator << afisare - fisier text
	friend ofstream& operator<< (ofstream& out, const Film& film) {
		out << film.numeFilm << endl;
		out << film.pretBilet << endl;
		out << film.an << endl;
		out << film.notaIMDb << endl;
		out << film.nrActori << endl;
		for (int i = 0; i < film.nrActori; i++) {
			out << film.v_actor[i].getNume() << "\n";
			out << film.v_actor[i].getAn_nastere() << "\n";
			out << film.v_actor[i].getNationalitate() << "\n";
			out << film.v_actor[i].getFilmPtCareECunoscut() << "\n";
			out << film.v_actor[i].getSalariuBrut() << "\n";
		}
		return out;
	}
};

class SpectacolDeBalet : public Piesa {
private:
	char* nivelDeDificultate;
	string coregrafPrincipal;
	int numarBalerini;
	int* varsteBalerini;
	string muzica;
public:
	//constructor fara parametri
	SpectacolDeBalet() : Piesa("Ballets Jazz Montréal", "James Rogers", "16.11.2023")
	{
		this->nivelDeDificultate = new char[strlen("Mediu") + 1];
		strcpy_s(this->nivelDeDificultate, strlen("Mediu") + 1, "Mediu");
		this->coregrafPrincipal = "Alexandra Damiani";
		this->numarBalerini = 2;
		this->varsteBalerini = new int[2] {23, 24};
		this->muzica = "Dance Me de Leonard Cohen";
	}
	//constructor de copiere
	SpectacolDeBalet(const SpectacolDeBalet& balet) : Piesa(balet) {  //upcasting
		this->nivelDeDificultate = new char[strlen(balet.nivelDeDificultate) + 1];
		strcpy_s(this->nivelDeDificultate, strlen(balet.nivelDeDificultate) + 1, balet.nivelDeDificultate);
		this->coregrafPrincipal = balet.coregrafPrincipal;
		this->numarBalerini = balet.numarBalerini;
		this->varsteBalerini = new int[balet.numarBalerini];
		for (int i = 0; i < balet.numarBalerini; i++) {
			this->varsteBalerini[i] = balet.varsteBalerini[i];
		}
		this->muzica = balet.muzica;
	}
	//constructor cu toti parametrii
	SpectacolDeBalet(string nume, const string scriitor, const char* data, double pretBilet, int BileteLuate, const char* nivel,
		string coregrafPrincipal, int numarBalerini, int* varsteBalerini, string muzica) :Piesa(nume, scriitor, data, pretBilet, BileteLuate) {
		this->nivelDeDificultate = new char[strlen(nivel) + 1];
		strcpy_s(this->nivelDeDificultate, strlen(nivel) + 1, nivel);
		this->coregrafPrincipal = coregrafPrincipal;
		this->numarBalerini = numarBalerini;
		this->varsteBalerini = new int[numarBalerini];
		for (int i = 0; i < numarBalerini; i++) {
			this->varsteBalerini[i] = varsteBalerini[i];
		}
		this->muzica = muzica;
	}
	//operator =
	SpectacolDeBalet operator=(const SpectacolDeBalet& balet) {
		if (this != &balet) {
			// apelam mai intai operatorul de la clasa Piesa
			Piesa ::operator=(balet);
			if (this->nivelDeDificultate != NULL) {
				delete[]this->nivelDeDificultate;
			}
			this->nivelDeDificultate = new char[strlen(balet.nivelDeDificultate) + 1];
			strcpy_s(this->nivelDeDificultate, strlen(balet.nivelDeDificultate) + 1, balet.nivelDeDificultate);
			this->coregrafPrincipal = balet.coregrafPrincipal;
			this->numarBalerini = balet.numarBalerini;
			if (this->varsteBalerini != NULL) {
				delete[]this->varsteBalerini;
			}
			this->varsteBalerini = new int[balet.numarBalerini];
			for (int i = 0; i < balet.numarBalerini; i++) {
				this->varsteBalerini[i] = balet.varsteBalerini[i];
			}
			this->muzica = balet.muzica;
		}
		return *this;
	}
	friend ostream& operator<< (ostream& out, SpectacolDeBalet& b) {
		out << "Nume piesa: " << b.getNume() << endl;
		out << "Producator: " << b.getScriitor() << endl;
		out << "Data: " << b.getData() << endl;
		out << "Pret Bilet: " << b.getPretBilet() << endl;
		out << "TVA Bilet: " << b.getTVABilet() << endl;
		out << "Numar bilete luate: " << b.getBileteLuate() << endl;
		out << "Nivel de dificultate : " << b.nivelDeDificultate << endl;
		out << "Coregraf principal: " << b.coregrafPrincipal << endl;
		out << "Numar de balerini : " << b.numarBalerini << endl;
		out << "Varstele balerinilor: ";
		for (int i = 0; i < b.numarBalerini; i++) {
			cout << b.varsteBalerini[i] << " ";
		}
		cout << endl;
		return out;
	}
	// metoda de afisare
	void afisare() {
		cout << "Nume piesa: " << this->getNume() << endl;
		cout << "Producator: " << this->getScriitor() << endl;
		cout << "Data: " << this->getData() << endl;
		cout << "Pret Bilet: " << this->getPretBilet() << endl;
		cout << "TVA Bilet: " << this->getTVABilet() << endl;
		cout << "Numar bilete luate: " << this->getBileteLuate() << endl;
		cout << "Nivel de dificultate : " << this->nivelDeDificultate << endl;
		cout << "Coregraf principal: " << this->coregrafPrincipal << endl;
		cout << "Numar de balerini : " << this->numarBalerini << endl;
		cout << "Varstele balerinilor: ";
		for (int i = 0; i < this->numarBalerini; i++) {
			cout << this->varsteBalerini[i] << " ";
		}
		cout << endl;
	}
	// geteri
	char* getNivelDeDificultate() {
		return this->nivelDeDificultate;
	}
	string getCoregrafPrincipal() {
		return this->coregrafPrincipal;
	}
	int getNumarDeBalerini() {
		return this->numarBalerini;
	}
	string getMuzica() {
		return this->muzica;
	}
	//seteri
	void setNivelDeDificultate(const char* nivel) {
		if (this->nivelDeDificultate != NULL) {
			delete[]this->nivelDeDificultate;
		}
		this->nivelDeDificultate = new char[strlen(nivel) + 1];
		strcpy_s(this->nivelDeDificultate, strlen(nivel) + 1, nivel);
	}
	void setCoregrafPrincipal(string coregraf) {
		if (coregraf.length() > 3) {
			this->coregrafPrincipal = coregraf;
		}
	}
	void setMuzica(string muzica) {
		if (muzica.length() > 3) {
			this->muzica = muzica;
		}
	}
	~SpectacolDeBalet() {
		if (this->nivelDeDificultate != NULL) {
			delete[]this->nivelDeDificultate;
		}
		if (this->varsteBalerini != NULL) {
			delete[]this->varsteBalerini;
		}
	}
};

class TeatruAerLiber : public Teatru {
private:
	double taxaParcarePeOra;
	int nrParcariMax;
	bool scenaDeschisa; // este deschis teatrul? daca e iarna, nu e
public:
	// geteri
	double getTaxaParcarePeOra() {
		return this->taxaParcarePeOra;
	}
	int getNrParcariMax() {
		return this->nrParcariMax;
	}
	bool getScenaDeschisa() {
		return this->scenaDeschisa;
	}
	// seteri
	void setTaxaParcarePeOra(double taxa) {
		this->taxaParcarePeOra = taxa;
	}
	void setNrParcariMax(int capacitate) {
		this->nrParcariMax = capacitate;
	}
	void setScenaDeschisa(bool deschisSauInchis) {
		this->scenaDeschisa = deschisSauInchis;
	}
	//constructor fara parametrii
	TeatruAerLiber() : Teatru("Teatru sub luna", "Str. Alexandru Ioan Cuza", 2012) {
		this->taxaParcarePeOra = 10;
		this->nrParcariMax = 50;
		this->scenaDeschisa = true;
	}
	//constructor cu toti parametrii
	TeatruAerLiber(const char* nume, string adresa, const int an, int capacitateMax, int nrSali, int nrAngajati,
		double taxaParcarePeOra, int nrParcariMax, bool scenaDeschisa) : Teatru(nume, adresa, an, capacitateMax, nrSali, nrAngajati) {
		this->taxaParcarePeOra = taxaParcarePeOra;
		this->nrParcariMax = nrParcariMax;
		this->scenaDeschisa = scenaDeschisa;
	}
	//constructor de copiere
	TeatruAerLiber(const TeatruAerLiber& tal) : Teatru(tal) {
		this->taxaParcarePeOra = tal.taxaParcarePeOra;
		this->nrParcariMax = tal.nrParcariMax;
		this->scenaDeschisa = tal.scenaDeschisa;
	}
	// operator = 
	TeatruAerLiber operator=(const TeatruAerLiber& tal) {
		if (this != &tal) {
			Teatru::operator=(tal);
			this->taxaParcarePeOra = tal.taxaParcarePeOra;
			this->nrParcariMax = tal.nrParcariMax;
			this->scenaDeschisa = tal.scenaDeschisa;
		}
		return *this;
	}
	friend ostream& operator<< (ostream& out, TeatruAerLiber tal) {
		out << "Nume teatru : " << tal.getNume() << endl;
		out << "Adresa: " << tal.getAdresa() << endl;
		out << "An infiintare: " << tal.getAn_infiintare() << endl;
		out << "Capacitate maxima: " << tal.getCapacitateMax() << endl;
		out << "Numar sali: " << tal.getNrSali() << endl;
		out << "Numar de angajati: " << tal.getNrAngajati() << endl;
		out << "Reducere studenti: " << tal.getReducereStudenti() << endl;
		out << "Taxa parcare: " << tal.taxaParcarePeOra << endl;
		out << "Nr maxim de locuri de parcare: " << tal.nrParcariMax << endl;
		out << "Este deschisa scena? ";
		if (tal.scenaDeschisa == true) cout << "Da. ";
		else cout << "Nu. ";
		cout << endl;
		return out;
	}
	//metoda afisare 
	void afisare() {
		cout << "Nume teatru : " << this->getNume() << endl;
		cout << "Adresa: " << this->getAdresa() << endl;
		cout << "An infiintare: " << this->getAn_infiintare() << endl;
		cout << "Capacitate maxima: " << this->getCapacitateMax() << endl;
		cout << "Numar sali: " << this->getNrSali() << endl;
		cout << "Numar de angajati: " << this->getNrAngajati() << endl;
		cout << "Reducere studenti: " << getReducereStudenti() << endl;
		cout << "Taxa parcare: " << this->taxaParcarePeOra << endl;
		cout << "Nr maxim de locuri de parcare: " << this->nrParcariMax << endl;
		cout << "Este deschisa scena? ";
		if (this->scenaDeschisa == true) cout << "Da. ";
		else cout << "Nu. ";
		cout << endl;
	}
	~TeatruAerLiber() {};
};

// operator '-='
int operator-= (Actor actor1, Actor actor2) {
	actor1.salariuBrut = actor1.salariuBrut - actor2.salariuBrut;
	return actor1.salariuBrut;
}


// functie globala - foloseste clasa piesa
void TotalBilete(Piesa piesa1, Piesa piesa2) {
	cout << "Nr bilete luate in total la cele doua piese este " << piesa1.BileteLuate + piesa2.BileteLuate;
}

// functie globala - foloseste clasa teatru
void TotalNrAngajati(Teatru teatru1, Teatru teatru2) {
	cout << "Total numar salariati: " << teatru1.nrAngajati + teatru2.nrAngajati;
}

// functie globala 1 - foloseste 2 clase
void locuriDisponibile(Teatru teatru, Piesa piesa) {
	int capacitateSala = teatru.capacitateSala();
	cout << "La piesa " << piesa.getNume() << " mai sunt disponibile " << (capacitateSala - piesa.getBileteLuate()) << " de locuri" << endl;
}

//functie globala 2 - foloseste toate clasele
void anuntPublicitar(Teatru teatru, Piesa piesa, Actor actor) {
	cout << "Anunt Publicitar: ";
	cout << endl << endl;
	cout << "      O aventura dramatica ca niciuna alta!" << endl << endl;
	cout << "  Piesa ' " << piesa.getNume() << " ' aduce pe scena o poveste captivanta si un actor principal incredibil, "
		<< actor.getNume() << endl;
	cout << "  Teatrul " << teatru.getNume() << " va invita sa experimentati magia teatrului intr-un mod unic." << endl;
	cout << "Pret bilet: " << piesa.getPretBilet() << " lei.";

}

int main()

{   // ***********************  FAZA 1 ******************************
	Teatru teatru;
	teatru.afisare();

	Teatru teatru2("National Bucuresti", "Piata Universitatii", 1973, 2880, 150, 20);
	teatru2.afisare();
	
	Teatru::setReducereStudenti(0.9);

	Teatru teatru3("Modern", "Strada Frumoasa", 2023);
	teatru3.afisare();

	cout << "--------------------------------------" << endl;

	Piesa piesa;
	piesa.afisare();

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

	// ***********************  FAZA 2 ******************************
	cout << "--------------------------------------" << endl;

	locuriDisponibile(teatru, piesa);

	cout << "--------------------------------------" << endl;

	anuntPublicitar(teatru, piesa, actor);


	// ***********************  FAZA 3 ******************************


	cout << "--------------OPERATORI--------------" << endl;
	Teatru teatru4;
	teatru4 = teatru3;
	cout << teatru4;

	if (teatru < teatru2) cout << "Teatru 2 este mai mare." << endl;
	cout << teatru2 - teatru;

	Piesa piesa4;
	piesa4 = piesa2;
	piesa4.afisare();

	/*Piesa piesa5;
	cin >> piesa5;
	piesa5.afisare();*/
	Piesa piesa6;
	Piesa piesa7;
	piesa7 = piesa2++;
	piesa7.afisare();
	piesa6 = ++piesa2;
	piesa6.afisare();

	if (piesa6 != piesa7) cout << "Cele doua nu au pret egal." << endl;
	else cout << "Piesele au pret egal" << endl;


	Actor actor4;
	actor4 = actor3;
	actor4.afisare();

	Actor actor5;
	Actor actor6;
	actor5 = actor2--;
	actor5.afisare();
	actor6 = --actor2;
	actor6.afisare();

	if (actor > actor3) cout << "Brad Pitt castiga mai mult decat Audrey Hepburn cu" << (actor -= actor3) << endl;
	else cout << "Audrey Hepburn castiga mai mult decat Brad Pitt cu " << (actor3 -= actor) << endl;


	// ***********************  FAZA 4 ******************************

	cout << "-------------VECTOR TEATRE---------------" << endl;

	Teatru T[3];
	cout << "Citire vector - teatre" << endl << "*************" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> T[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << T[i];
		cout << "******************" << endl;
	}

	cout << "-------------VECTOR ACTORI---------------" << endl;
	Actor actori[3];
	cout << "Citire vectori - actori : " << endl << "*************" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> actori[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << actori[i];
		cout << "******************" << endl;
	}

	cout << "-------------VECTOR PIESE---------------" << endl;
	Piesa piese[3];
	cout << "Citire vectori - piese : " << endl << "*************" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> piese[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << piese[i];
		cout << "******************" << endl;
	}

	cout << "---------MATRICE ACTORI----------" << endl;
	Actor Mat_Actori[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Actor pozitie: " << i << j << endl;
			cin >> Mat_Actori[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "    ACTOR " << i << j << endl;
			cout << Mat_Actori[i][j];
		}
		cout << endl;
	}

	// ***********************  FAZA 5 ******************************

	cout << "Afisare film care are un vector de mai multi actori : " << endl;
	Film f1;
	cout << f1;
	cout << endl;
	cout << "Citire vector de actori: ";
	Actor* v_actor = new Actor[2];
	for (int i = 0; i < 2; i++) {
		cin >> v_actor[i];
	}
	Film f2(2, v_actor, 8.00, "Interstellar", 2014, 35);
	cout << f2;
	cout << endl;
	if (f1 > f2) cout << "Divergent este un film mai bun";
	else cout << "Interstellar este un film mai bun";

	// ***********************  FAZA 6 ******************************

	Teatru teatru5("Teatru de balet", "Bucuresti", 1997, 1000, 10, 50);
	ofstream fisierTextTeatruOut("fisierTeatruText.txt", ios::out);
	fisierTextTeatruOut << teatru5;
	fisierTextTeatruOut.close();

	Teatru teatru6;
	ifstream fisierTextTeatruIn("fisierTeatruTextCitire.txt", ios::in);
	fisierTextTeatruIn >> teatru6;
	cout << endl;
	cout << teatru6;
	cout << "--------------------------------------";

	Piesa piesa8;
	piesa8.serializare();

	Actor actor7("Chris Evans", 1981, "american");
	actor7.afisareInFisierBinar();

	Film film3;
	ofstream fisierTextFilmOut("fisierTextFilmOut.txt", ios::out);
	fisierTextFilmOut << film3;
	fisierTextFilmOut.close();

	// ***********************  FAZA 7 ******************************
	cout << "*********************   Faza 7  **********************";
	cout << endl;
	SpectacolDeBalet b1;
	cout << "***** Afisare spectacol de balet b1 *****" << endl << endl;
	cout << b1 << endl << endl;


	SpectacolDeBalet b2;
	b2 = b1;
	cout << "***** Afisare spectacol de balet b2 *****" << endl << endl;
	cout << b2 << endl << endl;


	int* v3 = new int[10] {20, 26, 19, 24, 21, 27, 30, 25, 23, 23};
	SpectacolDeBalet b3("Spargatorul de nuci", "Piotr Ilici Ceaikovski", "30.12.2023", 50, 3, "Dificil", "Lev Ivanov", 10, v3, "suita simfonica");
	cout << "***** Afisare spectacol de balet b3 *****" << endl << endl;
	cout << b3 << endl << endl;



	SpectacolDeBalet b4("Lacul Lebedelor", "Piotr Ilici Ceaikovski", "26.01.2024", 75, 56, "Dificil", "Oleg Danovski", 10, v3, "suita - lacul lebedelor");
	cout << "***** Afisare spectacol de balet b4 *****" << endl << endl;
	cout << b4 << endl << endl;


	TeatruAerLiber tal1;
	cout << "***** Afisare obiect - teatru in aer liber tal1 *****" << endl << endl;
	cout << tal1 << endl << endl;



	TeatruAerLiber tal2("Verde la Teatru", "Str Libertatii", 2016, 100, 1, 30, 15, 100, false);
	cout << "***** Afisare NUME , CAPACITATE MAX. , NR ANGAJATI (dupa set)- cu ajutorul lui get -  tal2 *****" << endl << endl;
	cout << tal2.getNume() << endl;
	cout << tal2.getCapacitateMax() << endl;
	tal2.setNrAngajati(10);
	cout << tal2.getNrAngajati() << endl;
	cout << endl << endl;



	TeatruAerLiber tal3(tal2);
	cout << "***** Afisare obiect - teatru in aer liber tal3 *****" << endl << endl;
	cout << tal3 << endl << endl;

	// upcasting
	cout << "****** UPCASTING + AFISARE suma incasata - piesa 1 <= b3 ******" << endl << endl;
	Piesa* piesa11;
	piesa11 = &b3;
	cout << endl << *piesa11;
	cout << endl;
	(*piesa11).sold();
	cout << endl << endl;


	cout << "****** UPCASTING + AFISARE suma incasata - piesa 2 <= b4 ******" << endl << endl;
	Piesa* piesa20;
	piesa20 = &b4;
	cout << endl << *piesa20;
	cout << endl;
	(*piesa20).sold();
	cout << endl << endl;


	cout << "****** TOTAL BILETE VANDUTE - piesa 1 & piesa 2 ******" << endl << endl;
	TotalBilete(*piesa11, *piesa20);
	cout << endl;

	// ***********************  FAZA 8 ******************************
	int v_balerini[10] = { 23,25,25,18,19,19,22,20,21,21 };
	Actor actori[3];
	for (int i = 0; i < 3; i++) {
		actori[i] = Actor();
	}
	Eveniment** pointerEvenimente;
	pointerEvenimente = new Eveniment * [10];
	pointerEvenimente[0] = new Piesa("Tom si Jerry", "Nush", "13.01.2024", 50, 12);
	pointerEvenimente[1] = new Piesa();
	pointerEvenimente[2] = new SpectacolDeBalet();
	pointerEvenimente[3] = new SpectacolDeBalet("Rain", "Stevan", "23.04.2024", 70, 13, "Mediu", "Dadiv", 10, v_balerini, "Purple Rain");
	pointerEvenimente[4] = new Piesa("Da si nu", "Stefan Gheorghe", "19.02.2024");
	pointerEvenimente[5] = new Film();
	pointerEvenimente[6] = new Film(3, actori, 8.77, "Anyone but you", 2023, 35);
	pointerEvenimente[7] = new Piesa("Opriti planeta", "Rares Ionescu", "13.05.2024");
	pointerEvenimente[8] = new SpectacolDeBalet();
	pointerEvenimente[9] = new Film();

	cout << " Sume Casierie: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << pointerEvenimente[i]->Casierie() << " lei." << endl;
	}
	cout << endl;
	cout << "Total - suma incasata : ";
	double S = 0;
	for (int i = 0; i < 10; i++) {
		S = S + pointerEvenimente[i]->Casierie();
	}
	cout << S<<endl;

};
