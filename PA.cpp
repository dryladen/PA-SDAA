#include <iostream>
#include <conio.h>
#include "Pemilih.h"
#include "Pemilu.h"
using namespace std;

struct Paslon{
	int id;
	int noUrut;
	string namaKetua;
	string namaWakilKetua;
	string partai;
	Paslon* next;
};


Paslon* headPaslon = NULL, *tailPaslon = NULL;

int pemilihOrPaslon();
void menuAwal();


int main(){
	cout << "Hahhah" << endl;
	menuAwal();
	return 0;
}

void menuAwal(){
	Pemilih* voter = new Pemilih();
	Pemilu* pemilu = new Pemilu();
	int pilih;
	bool running = 1;
	enum option {
		KELUAR = 0, ADMIN, USER
	};
	while(running){
		cout << "Menu Awal" << endl;
		cout << "1. Admin" << endl;
		cout << "2. User" << endl;
		cout << "0. Keluar" << endl;
		cout << "Masukan pilihan : ";cin >> pilih;
		switch (pilih){
			case ADMIN:
				pemilu->admin();
				break;
			case USER:
				voter->masuk_atau_daftar();
				break;
			case KELUAR:
				running = 0;
				break;
			default:
				break;
		}
	}
}
