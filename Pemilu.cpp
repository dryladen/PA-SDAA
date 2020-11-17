#include <iostream>
#include <string>
#include <conio.h>
#include "Pemilu.h"

void cls(){
	system("cls");
}


int Pemilu::login(std::string status){
	std::string username,password;
	int percobaan = 0;
	do{
		password = "";
	    std::cout<< "USERNAME : "; fflush(stdin); getline(std::cin,username);
	    std::cout<< "PASSWORD : ";
	    char huruf;
	    int i = 0;
	    int pass= 55;
	    while(huruf = getch()) { 
	    	if (huruf == 13){
			    if (status == "admin"){
				    if (username == "admin" && password == "admin"){
				    	cls();
				    	std::cout << "\nLogin berhasil" << std::endl;
				    	return 1;
				    } else {
				    	cls();
				    	std::cout << "\nAkun tidak ada" << std::endl;
				    	percobaan++;
				    	break;
				    }
			    } else {
			    	if (username == "user" && password == "user"){
				    	std::cout << "\nLogin berhasil" << std::endl;
				    	return 1;
				    } else {
				    	std::cout << "\nAkun tidak ada" << std::endl;
				    	percobaan++;
				    	break;
				    }
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
	    	std::cout << "Kembali ke menu awal" << std::endl;
	    	return 0;
	    }
	} while (true);
	return 1;
}

void Pemilu::admin(){
	Pemilu* pemilu = new Pemilu();
	int cek = pemilu->login("admin");
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
		std::cout << "Menu admin" << std::endl;
		std::cout << "1. Tambahkan data" << std::endl;
		std::cout << "2. Ubah data" << std::endl;
		std::cout << "3. Hapus data" << std::endl;
		std::cout << "4. Tampilkan data" << std::endl;
		std::cout << "0. Kembali" << std::endl;
		std::cout << "Masukan pilihan : "; std::cin >> menu;
		
		if(menu == 1){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				std::cout << "Pilihan tidak ada " << std::endl;
			}
		} else if (menu == 2){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				std::cout << "Pilihan tidak ada " << std::endl;
			}
		} else if (menu == 3){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				std::cout << "Pilihan tidak ada " << std::endl;
			}
		} else if (menu == 4){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				std::cout << "Pilihan tidak ada " << std::endl;
			}
		} else if (menu == 5){
			return;
		} else {
			std::cout << "Pilihan tidak ada " << std::endl;
		}
	}
}

int Pemilu::pemilihOrPaslon(){
	int pilih;
	while(true){
		std::cout << "Pemilih / Paslon [1/2] : "; std::cin >> pilih;
		if (pilih == 1){
			return 1;
		} else if (pilih == 2){
			return 2;
		} else {
			std::cout << "Pilihan tidak ada " << std::endl;
		}
	}
}
