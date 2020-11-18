#include <iostream>
#include "Pemilih.h"
#include "Pemilu.h"

Pemilih* headPemilih = NULL, *tailPemilih = NULL;

void Pemilih::cekData(){
	
} 

void Pemilih::masuk_atau_daftar(){
	Pemilu* pemilu = new Pemilu();
	int opsi, cek;
	bool running = 1;
	enum option {KEMBALI=0, LOGIN, DAFTAR};
	do{
		std::cout << "========================" << std::endl;
		std::cout << "1. Login" << std::endl;
		std::cout << "2. Daftar" << std::endl;
		std::cout << "0. Kembali" << std::endl;
		std::cout << "=> "; std::cin >> opsi;
		switch (opsi){
			case LOGIN:
				cek = pemilu->login("user");
				if (cek != 1){
					return;
				}
				break;
			case DAFTAR:
				cekData();
				std::cout << "daftar" << std::endl;
				break;
			case KEMBALI:
				running = 0;
				return;
				break;
		}
	} while (running);
	user();
}

void Pemilih::user(){
	int menu;
	while(true){
		std::cout << "Menu User" << std::endl;
		std::cout << "1. Cek data diri" << std::endl;
		std::cout << "2. List paslon" << std::endl;
		std::cout << "4. pilih paslon" << std::endl;
		std::cout << "4. Ubah kata sandi" << std::endl;
		std::cout << "5. Kembali ke menu awal" << std::endl;
		std::cout << "Masukan pilihan : "; std::cin >> menu;
		if(menu == 1){

		} else if (menu == 2){

		} else if (menu == 3){

		} else if (menu == 4){

		} else if (menu == 5){

		} else {
			return;
		}
	}
}
