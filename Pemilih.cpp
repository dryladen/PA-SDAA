#include <iostream>
#include <string>
#include <conio.h>
#include "Pemilih.h"
#include "Pemilu.h"

// data untuk yang udah daftar
pemilih *frontPemilih = NULL;
pemilih *rearPemilih = NULL;

// untuk matching ke pemilih yang daftar
pemilih *frontdatabasePemilih = NULL;
pemilih *reardatabasePemilih = NULL;

Pemilu* pemilu = new Pemilu();

int Pemilih::login(){
	std::string username,password;
	int percobaan = 0;
	if (frontPemilih == NULL){
		std::cout << "==============================================================" << std::endl;
    	std::cout << "Belum ada yang daftar" << std::endl;
		std::cout << "==============================================================" << std::endl;
		return 2;
	}
	do{
		password = "";
		std::cout << "==============================================================" << std::endl;
	    std::cout<< "Nama Lengkap : "; std::fflush(stdin);std::getline(std::cin,username);
	    std::cout<< "Kata Sandi   : ";
	    char huruf;
	    int i = 0;
	    int pass= 55;
	    while(huruf = getch()) { 
	    	if (huruf == 13){
		    	if (username == frontPemilih->nama && password == frontPemilih->password){
		    		pemilu->cls();
		    		std::cout << "==============================================================" << std::endl;
			    	std::cout << "Login berhasil" << std::endl;
		    		std::cout << "==============================================================" << std::endl;
			    	return 1;
			    } else {
		    		pemilu->cls();
		    		pemilih *pointer = frontPemilih;			    		
		    		while(pointer != NULL){
	    				std::cout << "A" << std::endl;
		    			if(username == frontPemilih->nama && password == frontPemilih->password){
		    				std::cout << "==============================================================" << std::endl;
			    			std::cout << "Bukan antrian anda / " << std::endl;
			    			std::cout << "==============================================================" << std::endl;
			    			return 0;
		    			}
		    			pointer = pointer->next;
		    		}
			    	std::cout << "==============================================================" << std::endl;
			    	std::cout << "Akun tidak ada / " << std::endl;
			    	std::cout << "==============================================================" << std::endl;
			    	percobaan++;
			    	break;
			    }
			} else if (huruf == 8){
				
				if (password.length() > 0){
					std::cout << "\b \b";
					password.erase(password.length()-1);
				}
			} else {
				std::cout << "*";
				password += huruf;
			}
		}

	    if (percobaan == 3){
	    	std::cout << "==============================================================" << std::endl;
	    	std::cout << "Kembali ke menu awal" << std::endl;
	    	std::cout << "==============================================================" << std::endl;
	    	return 0;
	    }
	} while (true);  
	return 1;
}

void Pemilih::displayDataDiri(){
	pemilih *pointer = frontPemilih;
	std::cout << "==============================================================" << std::endl;
	std::cout << "Menampilkan data diri" << std::endl;
	std::cout << "NIK              : " << pointer->nik << std::endl;
	std::cout << "Nama             : " << pointer->nama << std::endl;
	std::cout << "Pilih Nomor Urut : " << pointer->pilihNoUrut << std::endl;
	std::cout << "Passwrod         : " << pointer->password << std::endl;
	std::cout << "==============================================================" << std::endl;
}

void Pemilih::displayPemilih(){
	pemilih *pointer = frontdatabasePemilih;
	int i = 0;
	if(frontdatabasePemilih == NULL){
		std::cout << "==============================================================" << std::endl;
		std::cout<< ">>    Data Kosong   <<" <<std::endl;
		std::cout << "==============================================================" << std::endl;
		return;
	}
	std::cout << "==============================================================" << std::endl;
	while(pointer != NULL){
		std::cout << "Pemilih [" << i+1 << "]" << std::endl;
		std::cout << "NIK           : " << pointer->nik << std::endl;
		std::cout << "Nama          : " << pointer->nama << std::endl;
		(pointer->pilihNoUrut == 0) ? std::cout << "Status        : Belum Coblos " << std::endl : std::cout << "Status      : Sudah Coblos " << std::endl;
		std::cout << std::endl;
		pointer = pointer->next;
		i++;
	}
	std::cout << "==============================================================" << std::endl;
}
void Pemilih::pushPemilih(){
	int batas;
	std::cout << "==============================================================" << std::endl;
	std::cout << "Masukan jumlah Pemilih : ";std::cin >> batas;
	std::cout << "==============================================================" << std::endl;
	std::cout << ">> Memasukan Data Pemilih : " << std::endl;
	for(int i = 0; i < batas; i-=-1){
		pemilih *databaru = new pemilih();
		std::cout << "==============================================================" << std::endl;
		std::cout << "Pemilih [" << i+1 << "]" << std::endl;
		std::cout << std::endl;
		std::cout << "Input NIK     : ";
		std::cin >> databaru->nik;
		std::cout << "Input Nama    : ";
		std::fflush(stdin);std::getline(std::cin,databaru->nama);
		databaru->next = NULL;
		if(frontdatabasePemilih == NULL){
			frontdatabasePemilih = databaru;
			reardatabasePemilih = databaru;
		} else {
			reardatabasePemilih->next = databaru;
			reardatabasePemilih = databaru;
		}
	}
}

void Pemilih::cekData(){
	int nik;
	std::string nama;

	std::cout << "Input NIK  : ";std::cin >> nik;
	std::cout << "Input Nama : ";std::fflush(stdin);std::getline(std::cin, nama);

	pemilih *matching = frontdatabasePemilih;
	pemilih *matching0 = frontPemilih;
	// cek udah daftar atau belum
	while(matching != NULL){
		if(matching->nik == nik && matching->daftar == true){
			if(matching->pilihNoUrut != 0){
				std::cout << "Anda sudah memilih" << std::endl;
				return;
			} else {
				std::cout << "Anda sudah mendaftar" << std::endl;
				return;
			}
		}
		matching = matching->next;
	}
	matching = frontdatabasePemilih;
	while(matching != NULL){
	    if(matching->nama.compare(nama)==0 && matching->nik == nik){
			pemilih *databaru = new pemilih();
    		std::cout << "Masukan password : ";std::getline(std::cin,databaru->password);
    		databaru->nik = matching->nik;
    		databaru->pilihNoUrut = matching->pilihNoUrut;
    		databaru->nama = matching->nama;
    		databaru->daftar = true;
    		databaru->next = NULL;
    		matching->daftar = true;
    		matching->password = databaru->password;

	    	if(frontPemilih == NULL){
	    		frontPemilih = databaru;
	    		rearPemilih = databaru;
	    		return;
	    	} 
	    	rearPemilih->next = databaru;
	    	rearPemilih = databaru;
	    	return;
	    }
	    matching = matching->next;
	}
	std::cout << "Data anda tidak terdaftar" << std::endl;
} 

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
				cek = login();
				if (cek != 1){
					return;
				}
				user();
				break;
			case DAFTAR:
				cekData();
				break;
			case KEMBALI:
				running = 0;
				return;
				break;
		}
	} while (running);
}

// void Pemilih::pilihPaslon(){
// 	int pilih;
// 	pemilu->displayPaslon();
// 	std::cout << "Input nomor Paslon";std::cin >> pilih;
// 	Pemilu::Paslon *pointer = Pemilu::paslon *frontPaslon;
// 	while(pointer != NULL){
// 		if(pilih == Paslon->noUrut){
// 			frontPemilih->pilihNoUrut = pilih;
// 		}
// 		pointer = pointer->next;
// 	}
// }
void Pemilih::ubahSandi(){
	std::string sandiBaru;
	ulang:
	std::cout << "Masukan password baru : ";std::fflush(stdin);std::getline(std::cin, sandiBaru);
	if(frontPemilih->password == sandiBaru){
		std::cout << "Jangan memasukan password lama anda" << std::endl;
		goto ulang;
	} else {
		frontPemilih->password = sandiBaru;
		std::cout << "Update Password Berhasil" << std::endl;
	}
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
			displayDataDiri();
		} else if (menu == 2){
			pemilu->displayPaslon();
		} else if (menu == 3){

		} else if (menu == 4){
			ubahSandi();
		} else if (menu == 0){
			return;
		} else {
			std::cout << "==============================================================" << std::endl;
			std::cout << "Pilihan tidak ada" << std::endl;
			std::cout << "==============================================================" << std::endl;
		}
	}
}
