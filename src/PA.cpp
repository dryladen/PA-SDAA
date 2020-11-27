#include "..\include\Pemilu.h"

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

	char pilih;
	bool running = 1;
	enum option {
		KELUAR = '0', ADMIN = '1', USER = '2'
	};
	
	while(running){
		frameAwal();
		gotoXY(52,11);std::cout << ">> PEMILIHAN UMUM <<" << std::endl;
		gotoXY(37,17);std::cout << "1. ADMIN" << std::endl;
		gotoXY(59,17);std::cout << "2. USER" << std::endl;
		gotoXY(80,17);std::cout << "0. EXIT" << std::endl;
		pilih = getch();
		switch (pilih){
			case ADMIN:
				admin->admin();
				break;
			case USER:
				voter->masuk_atau_daftar();
				break;
			case KELUAR:
				blink("EXIT PROGRAM",58);
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
