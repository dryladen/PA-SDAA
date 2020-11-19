#include <iostream>
#include <string>
#include <conio.h>
#include "Pemilu.h"
#include "Pemilih.h"

Paslon *frontPaslon = NULL;
Paslon *rearPaslon = NULL;

Pemilih *data = new Pemilih();

void Pemilu::cls(){
	system("cls");
}

void Pemilu::pushPaslon(){
	int batas;
	std::cout << "==============================================================" << std::endl;
	std::cout << "Masukan jumlah Paslon : ";std::cin >> batas;
	std::cout << "==============================================================" << std::endl;
	std::cout << ">> Memasukan Data Paslon : " << std::endl;
	for(int i = 0; i < batas; i-=-1){
		Paslon *databaru = new Paslon();
		std::cout << "==============================================================" << std::endl;
		std::cout << "Paslon [" << i+1 << "]" << std::endl;
		std::cout << std::endl;
		std::cout << "Input ID          : ";
		std::cin >> databaru->id;
		std::cout << "Input Nomor Urut  : ";
		std::cin >> databaru->noUrut;
		std::cout << "Input Nama Ketua  : ";
		std::fflush(stdin);std::getline(std::cin,databaru->namaKetua);
		std::cout << "Input Nama Wakil  : ";
		std::fflush(stdin);std::getline(std::cin,databaru->namaWakilKetua);
		std::cout << "Input Nama Partai : ";
		std::fflush(stdin);std::getline(std::cin,databaru->partai);
		databaru->next = NULL;
		if(frontPaslon == NULL){
			frontPaslon = databaru;
			rearPaslon = databaru;
		} else {
			rearPaslon->next = databaru;
			rearPaslon = databaru;
		}
	}
}

Paslon* Pemilu::displayPaslon(){
	Paslon *pointer = frontPaslon;
	int i = 0;
	if(frontPaslon == NULL){
		std::cout << "==============================================================" << std::endl;
		std::cout<< ">>    Data Kosong   <<" <<std::endl;
		std::cout << "==============================================================" << std::endl;
		return NULL;
	}
	std::cout << "==============================================================" << std::endl;
	while(pointer != NULL){
		std::cout << "Paslon [" << i+1 << "]" << std::endl;
		std::cout << "ID               : " << pointer->id << std::endl;
		std::cout << "Nomor Urut       : " << pointer->noUrut << std::endl;
		std::cout << "Nama Ketua       : " << pointer->namaKetua << std::endl;
		std::cout << "Nama Wakil Ketua : " << pointer->namaWakilKetua << std::endl;
		std::cout << "Partai           : " << pointer->partai << std::endl;
		std::cout << std::endl;
		pointer = pointer->next;
		i++;
	}
	std::cout << "==============================================================" << std::endl;
	return frontPaslon;
}

int Pemilu::login(){
	std::string username,password;
	int percobaan = 0;
	do{
		password = "";
		std::cout << "==============================================================" << std::endl;
	    std::cout<< "USERNAME : "; std::fflush(stdin);std::getline(std::cin,username);
	    std::cout<< "PASSWORD : ";
	    char huruf;
	    int i = 0;
	    int pass= 55;
	    while(huruf = getch()) { 
	    	if (huruf == 13){
			    if (username == "admin" && password == "admin"){
			    	cls();
			    	std::cout << "==============================================================" << std::endl;
			    	std::cout << "Login berhasil" << std::endl;
			    	std::cout << "==============================================================" << std::endl;
			    	return 1;
			    } else {
			    	cls();
			    	std::cout << "==============================================================" << std::endl;
			    	std::cout << "Akun tidak ada" << std::endl;
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

void Pemilu::admin(){
	Pemilu* pemilu = new Pemilu();
	int cek = login();
	if (cek != 1){
		return;
	}
	int menu,pilih;
	enum option {
		KEMBALI = 0,
		TAMBAH_DATA, UBAH_DATA,
		HAPUS_DATA, TAMPILKAN_DATA
	};
	while(true){
		std::cout << "==============================================================" << std::endl;
		std::cout << ">> Menu admin" << std::endl;
		std::cout << "1. Tambahkan data" << std::endl;
		std::cout << "2. Ubah data" << std::endl;
		std::cout << "3. Hapus data" << std::endl;
		std::cout << "4. Tampilkan data" << std::endl;
		std::cout << "0. Kembali ke menu awal" << std::endl;
		std::cout << "==============================================================" << std::endl;
		std::cout << "Masukan pilihan : "; std::cin >> menu;
		
		if(menu == 1){
			pilih = pemilihOrPaslon();
			if (pilih == 1){
				data->pushPemilih();
			} else if (pilih == 2){
				pushPaslon();
			} else {
				std::cout << "==============================================================" << std::endl;
				std::cout << "Pilihan tidak ada " << std::endl;
				std::cout << "==============================================================" << std::endl;
			}
		} else if (menu == 2){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				std::cout << "==============================================================" << std::endl;
				std::cout << "Pilihan tidak ada " << std::endl;
				std::cout << "==============================================================" << std::endl;
			}
		} else if (menu == 3){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				std::cout << "==============================================================" << std::endl;
				std::cout << "Pilihan tidak ada " << std::endl;
				std::cout << "==============================================================" << std::endl;
			}
		} else if (menu == 4){
			pilih = pemilihOrPaslon();
			if (pilih == 1){
				data->displayPemilih();
			} else if (pilih == 2){
				displayPaslon();
			} else {
				std::cout << "==============================================================" << std::endl;
				std::cout << "Pilihan tidak ada " << std::endl;
				std::cout << "==============================================================" << std::endl;
			}
		} else if (menu == 0){
			return;
		} else {
			std::cout << "==============================================================" << std::endl;
			std::cout << "Pilihan tidak ada " << std::endl;
			std::cout << "==============================================================" << std::endl;
		}
	}
}

int Pemilu::pemilihOrPaslon(){
	int pilih;
	while(true){
		std::cout << "==============================================================" << std::endl;
		std::cout << "Pemilih / Paslon [1/2] : "; std::cin >> pilih;
		if (pilih == 1){
			return 1;
		} else if (pilih == 2){
			return 2;
		} else {
			std::cout << "==============================================================" << std::endl;
			std::cout << "Pilihan tidak ada " << std::endl;
			std::cout << "==============================================================" << std::endl;
		}
	}
}
