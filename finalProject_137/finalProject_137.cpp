#include <iostream>
using namespace std;

class MataKuliah {
private:
	float presensi;
	float activity;
	float exercise;
	float tugasAkhir;
public:
	MataKuliah() {
		presensi = 0.0;
		activity = 0.0;
		exercise = 0.0;
		tugasAkhir = 0.0;
	}
	virtual float hitungNilaiAkhir() { return 0.0; }
	virtual void cekKelulusan() { return; }
	virtual void input() { return; }
	void setPresensi(float nilai) {
		this->presensi = nilai;
	}
	float getPresensi() {
		return presensi;
	}
	//isi disini
	void setP(float p) { 
		this->presensi = p;
		return; }
	void setA(float a) { 
		this->activity = a;
		return; }
	void setE(float e) { 
		this->exercise = e;
		return; }
	void setTA(float ta) { 
		this->tugasAkhir = ta;
		return; }

	float getP() { return presensi; }
	float getA() { return activity; }
	float getE() { return exercise; }
	float getTA() { return tugasAkhir; }
};

class Pemrograman : public MataKuliah { //isi disini
public:
	float hitungNilaiAkhir() {
		float p, a, e, ta;
		float akhir;
		p = getP();
		a = getA();
		e = getE();
		ta = getTA();

		akhir = ((p*0.1)+(a*0.2)+(e*0.3)+(ta*0.4)) + 0.0;
		return akhir;
	}
	void cekKelulusan() {
		hitungNilaiAkhir();
		if (hitungNilaiAkhir() >= 75) {
			cout << "\nSelamat, Anda lulus mata kuliah" << endl;
			cout << "Pemrograman dengan nilai akhir " << hitungNilaiAkhir() << endl;
		}
		else {
			cout << "\nMohon Maaf anda tidak lulus dengan nilai " << hitungNilaiAkhir() << endl;
			cout << "Tetap semangat dan jangan pernah menyerah" << endl;
		}
	}
	void input() {
		cout << "Program Dibuat" << endl;
		float p, a, e, ta;
		cout << "\nMasukan nilai Presensi: ";
		cin >> p;
		cout << "Masukan nilai Activity: ";
		cin >> a;
		cout << "Masukan nilai Exercise: ";
		cin >> e;
		cout << "Masukan nilai Tugas Akhir: ";
		cin >> ta;
		setP(p);
		setA(a);
		setE(e);
		setTA(ta);
	}
};

int main() { //isi disini
	while(true) {
		try {
			string opt;
			Pemrograman obj;
			obj.input();
			obj.cekKelulusan();
			cout << "\nApakah anda ingin mengulang program ? Y / N" << endl;
			cin >> opt;
			if (opt == "Y" || opt == "y" || opt == "N" || opt == "n") {
				throw opt;
			}
			else {
				throw 10;
			}
		}
		catch (string test) {
			if (test == "N" || test == "n" ) {
				break;
			}
		}
		catch(...) {
			cout << "Pilihan Invalid. Program akan keluar" << endl;
			break;
		}
	}

	return 0;
}