#include <iostream>
#include <conio.h>
using namespace std;

void cls(){
	system("cls");
}

void user();
void admin();
int login(string status);
int pemilihOrPaslon();

int main(){
	int pilih;
	while(true){
		cout << "Menu Awal" << endl;
		cout << "1. Admin" << endl;
		cout << "2. User" << endl;
		cout << "3. Exit" << endl;
		cout << "Masukan pilihan : ";cin >> pilih;
		if(pilih == 1){
			admin();
		} else if (pilih == 2){
			user();
		} else if (pilih == 3){
			exit(0);
		} else {
			cout << "Pilihan tidak ada" << endl;
		}
	}
	return 0;
}

void user(){
	int opsi, cek;
	bool running = 1;
	enum option {KEMBALI=0, LOGIN, DAFTAR};
	do{
		cout << "========================" << endl;
		cout << "1. Login" << endl;
		cout << "2. Daftar" << endl;
		cout << "0. Kembali" << endl;
		cout << "=> "; cin >> opsi;
		cout << opsi << endl;
		switch (opsi){
			case LOGIN:
				cek = login("user");
				if (cek != 1){
					return;
				}
				break;
			case DAFTAR:
				cout << "daftar" << endl;
				break;
			case KEMBALI:
				running = 0;
				break;
		}
	} while (running);

	int menu,pilih;
	while(true){
		cout << "Menu admin" << endl;
		cout << "1. Cek data diri" << endl;
		cout << "2. List paslon" << endl;
		cout << "4. pilih paslon" << endl;
		cout << "4. Ubah kata sandi" << endl;
		cout << "5. Kembali ke menu awal" << endl;
		cout << "Masukan pilihan : ";cin >> menu;
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

void admin(){
	int cek = login("admin");
	if (cek != 1){
		return;
	}
	int menu,pilih;
	while(true){
		cout << "Menu admin" << endl;
		cout << "1. Tambahkan data" << endl;
		cout << "2. Ubah data" << endl;
		cout << "3. Hapus data" << endl;
		cout << "4. Tampilkan data" << endl;
		cout << "5. Kembali ke menu awal" << endl;
		cout << "Masukan pilihan : ";cin >> menu;
		if(menu == 1){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				cout << "Pilihan tidak ada " << endl;
			}
		} else if (menu == 2){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				cout << "Pilihan tidak ada " << endl;
			}
		} else if (menu == 3){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				cout << "Pilihan tidak ada " << endl;
			}
		} else if (menu == 4){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){

			} else {
				cout << "Pilihan tidak ada " << endl;
			}
		} else if (menu == 5){
			return;
		} else {
			cout << "Pilihan tidak ada " << endl;
		}
	}
}

int login(string status){
	string username,password;
	int percobaan = 0;
	do{
		password = "";
	    cout<<"USERNAME : ";fflush(stdin);getline(cin,username);
	    cout<<"PASSWORD : ";
	    char huruf;
	    int i = 0;
	    int pass= 55;
	    while(huruf=getch()) { 
	    	if (huruf == 13){
			    if (status == "admin"){
				    if (username == "admin" && password == "admin"){
				    	cls();
				    	cout << "\nLogin berhasil" << endl;
				    	return 1;
				    } else {
				    	cls();
				    	cout << "\nAkun tidak ada" << endl;
				    	percobaan++;
				    	
				    	break;
				    }
			    } else {
			    	if (username == "user" && password == "user"){
				    	cout << "\nLogin berhasil" << endl;
				    	return 1;
				    } else {
				    	cout << "\nAkun tidak ada" << endl;
				    	percobaan++;
				    }
			    }	
			} else if (huruf == 8){
				
				if (password.length() > 0){
					cout << "\b \b";
					password.erase(password.length()-1);
				}
			} else {
				cout << "*";
				password += huruf;
			}
	    }

	    if (percobaan == 3){
	    	cout << "Kembali ke menu awal" << endl;
	    	return 0;
	    }
	} while (true);
	return 1;
}

int pemilihOrPaslon(){
	int pilih;
	while(true){
		cout << "Pemilih / Paslon [1/2] : ";cin >> pilih;
		if (pilih == 1){
			return 1;
		} else if (pilih == 2){
			return 2;
		} else {
			cout << "Pilihan tidak ada " << endl;
		}
	}
}
