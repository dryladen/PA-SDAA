#include <iostream>
#include <conio.h>
#include "Pemilu.h"
#include "Pemilih.h"
using namespace std;

void menuAwal();

int main(){
	menuAwal();
	return 0;
}

void menuAwal(){

	Pemilih* voter = new Pemilih();
	Pemilu* admin = new Pemilu();

	int pilih;
	bool running = 1;
	enum option {
		KELUAR = 0, ADMIN, USER
	};
	while(running){
		cout << "==============================================================" << endl;
		cout << "Menu Awal" << endl;
		cout << "1. Admin" << endl;
		cout << "2. User" << endl;
		cout << "0. Exit Program" << endl;
		cout << "==============================================================" << endl;
		cout << "Masukan pilihan : ";cin >> pilih;
		switch (pilih){
			case ADMIN:
				admin->admin();
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
