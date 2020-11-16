#include <iostream>
#include <conio.h>
using namespace std;
int login(bool status);
void admin();
void user();

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
	int cek = login(false);
	if (cek != 1){
		return;
	}
	int pilih;
	while(true){
		cout << "Menu admin" << endl;
		cout << "1. Cek data diri" << endl;
		cout << "2. List paslon" << endl;
		cout << "4. Pilih paslon" << endl;
		cout << "4. Ubah kata sandi" << endl;
		cout << "5. Kembali ke menu awal" << endl;
		cout << "Masukan pilihan : ";cin >> pilih;
		if(pilih == 1){

		} else if (pilih == 2){

		} else if (pilih == 3){

		} else if (pilih == 4){

		} else if (pilih == 4){

		} else {
			return;
		}
	}
}

void admin(){
	int cek = login(true);
	if (cek != 1){
		return;
	}
	int pilih;
	while(true){
		cout << "Menu admin" << endl;
		cout << "1. Tambahkan data" << endl;
		cout << "2. Ubah data" << endl;
		cout << "3. Hapus data" << endl;
		cout << "4. Tampilkan data" << endl;
		cout << "5. Kembali ke menu awal" << endl;
		cout << "Masukan pilihan : ";cin >> pilih;
		if(pilih == 1){

		} else if (pilih == 2){

		} else if (pilih == 3){

		} else if (pilih == 4){

		} else if (pilih == 4){

		} else {
			return;
		}
	}
}

int login(bool status){
	string username,password;
	int percobaan = 0;
	do{
		password = "";
	    cout<<"USERNAME : ";fflush(stdin);getline(cin,username);
	    cout<<"PASSWORD : ";
	    char huruf;
	    int i = 0;
	    int pass= 55;
	    while(true) { 
	    	huruf=getch();
	        if((huruf >= 'a' && huruf <= 'z') || (huruf >= 'A' && huruf <= 'Z')||(huruf >= '0' && huruf <='9')){
	            password += huruf;
	            i++;
	        	pass++;
	            cout<<"*";
	        }
	        if(huruf == '\b'){
	            cout<<"\b \b";
	            if(pass > 55){
	            	pass--;
	            	i--;
	            	password.erase(i,1);
	            }
	        }
	        if(huruf=='\r'){
	            break;
	        }
	    }
	    if (status == true){
		    if (username == "admin" || password == "admin"){
		    	cout << "\nLogin berhasil" << endl;
		    	return 1;
		    } else if (username != "admin" || password != "admin"){
		    	cout << "\nAkun tidak ada" << endl;
		    	percobaan++;
		    }
	    } else {
	    	if (username == "user" || password == "user"){
		    	cout << "\nLogin berhasil" << endl;
		    	return 1;
		    } else if (username != "user" || password != "user"){
		    	cout << "\nAkun tidak ada" << endl;
		    	percobaan++;
		    }
	    }
	    if (percobaan == 3){
	    	cout << "Kembali ke menu awal" << endl;
	    	return 0;
	    }
	} while (true);
	return 1;
}
