#include <iostream>
#include "Pemilih.h"
#include "Pemilu.h"

void Pemilih::cekData(){
	std::cout << "Ngentiaw" << std::endl;
} 

Pemilu* pemilu = new Pemilu();
void Pemilih::masuk_atau_daftar(){
	int opsi, cek;
	bool running = 1;
	enum option {KEMBALI=0, LOGIN, DAFTAR};
	do{
		std::cout << "==============================================================" << std::endl;
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
				user();
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
}

void Pemilih::user(){
	int menu;
	while(true){
		std::cout << "==============================================================" << std::endl;
		std::cout << ">> Menu User" << std::endl;
		std::cout << "1. Cek data diri" << std::endl;
		std::cout << "2. List paslon" << std::endl;
		std::cout << "3. pilih paslon" << std::endl;
		std::cout << "4. Ubah kata sandi" << std::endl;
		std::cout << "0. Kembali ke menu awal" << std::endl;
		std::cout << "==============================================================" << std::endl;
		std::cout << "Masukan pilihan : "; std::cin >> menu;
		if(menu == 1){

		} else if (menu == 2){
			pemilu->display();
		} else if (menu == 3){

		} else if (menu == 4){

		} else if (menu == 0){
			return;
		} else {
			std::cout << "==============================================================" << std::endl;
			std::cout << "Pilihan tidak ada" << std::endl;
			std::cout << "==============================================================" << std::endl;
		}
	}
}
