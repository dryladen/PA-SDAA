#include <iostream>
#include <conio.h>
#include "..\include\Pemilu.h"
#include "..\include\Pemilih.h"
#include "..\include\File.h"

using namespace std;

void menuAwal();

Paslon *frontPaslon = NULL;
Paslon *rearPaslon = NULL;

pemilih *frontPemilih = NULL;
pemilih *rearPemilih = NULL;

pemilih *frontdatabasePemilih = NULL;
pemilih *reardatabasePemilih = NULL;

int main(){
	menuAwal();
	return 0;
}

void menuAwal(){
	readDataBasePemilih(frontdatabasePemilih, reardatabasePemilih);
	readQueuePemilih(frontPemilih, rearPemilih);
	readDataPaslon(frontPaslon, rearPaslon);

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
	if (frontPemilih == NULL){
		remove("database\\dataQueuePemilih.csv");
	} else {
		updateQueuePemilih(frontPemilih);
	}
	updateDataBasePemilih(frontdatabasePemilih);
	updateDataPaslon(frontPaslon);
}
