#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include "..\include\Pemilih.h"
#include "..\include\Pemilu.h"
#include "..\include\File.h"

// data untuk yang udah daftar
extern pemilih *frontPemilih;
extern pemilih *rearPemilih;

// untuk matching ke pemilih yang daftar
extern pemilih *frontdatabasePemilih;
extern pemilih *reardatabasePemilih;

Pemilu* pemilu = new Pemilu();

int Pemilih::login(){
	std::string nik,password;
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
	    std::cout<< "NIK      : "; fflush(stdin);std::getline(std::cin,nik);
	    std::cout<< "PASSWORD : ";
	    char huruf;
	    int i = 0;
	    int pass= 55;
	    while(huruf = getch()) { 
	    	if (huruf == 13){
		    	if (nik == frontPemilih->nik && password == frontPemilih->password && frontPemilih->pilihNoUrut.compare("none") == 0){
		    		pemilu->cls();
		    		std::cout << "==============================================================" << std::endl;
			    	std::cout << "Login berhasil" << std::endl;
		    		std::cout << "==============================================================" << std::endl;
			    	return 1;
			    } else {
		    		pemilu->cls();
		    		pemilih *pointer = frontPemilih;			    		
		    		while(pointer != NULL){
		    			if(nik == pointer->nama && password == pointer->password){
		    				std::cout << "==============================================================" << std::endl;
			    			std::cout << "Bukan antrian anda " << std::endl;
			    			std::cout << "==============================================================" << std::endl;
			    			return 0;
		    			}
		    			pointer = pointer->next;
		    		}
			    	std::cout << "==============================================================" << std::endl;
			    	std::cout << "Akun tidak ada " << std::endl;
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
	std::cout << "Passwrod         : " << pointer->password << std::endl;
	std::cout << "Pilih Nomor Urut : " << pointer->pilihNoUrut << std::endl;
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
		(pointer->pilihNoUrut.compare("none") == 0) ? std::cout << "Status        : Belum Coblos " << std::endl : std::cout << "Status        : Sudah Coblos " << std::endl;
		std::cout << std::endl;
		pointer = pointer->next;
		i++;
	}
	std::cout << "==============================================================" << std::endl;
}
void Pemilih::enquePemilih(){
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
		fflush(stdin);std::getline(std::cin,databaru->nama);
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
	std::string nik;
	std::string nama;
	std::cout << "Input NIK        : ";std::cin >> nik;
	std::cout << "Input Nama       : ";fflush(stdin);std::getline(std::cin, nama);

	pemilih *matching = frontdatabasePemilih;
	pemilih *matching0 = frontPemilih;
	// cek udah daftar atau belum
	while(matching != NULL){
		if(matching->nik == nik && matching->daftar == true){
			if(matching->pilihNoUrut.compare("none") == 0){
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
	    if(matching->nama.compare(nama) == 0 && matching->nik.compare(nik) == 0){
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
		(frontPemilih == NULL) ? std::cout << ">> Belum ada yang daftar" << std::endl : std::cout << ">> Giliran coblos : " << frontPemilih->nama << std::endl;
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

void Pemilih::pilihPaslon(){
	if (frontPemilih->pilihNoUrut.compare("none") != 0){
		std::cout << "==============================================================" << std::endl;
		std::cout << "Anda sudah memilih paslon" << std::endl;
		std::cout << "==============================================================" << std::endl;
		return;
	}
	std::string pilih;
	Paslon *frontPaslon = pemilu->displayPaslon();
	if(frontPaslon == NULL){
		return;
	}
	std::cout << "Input nomor Paslon : ";std::cin >> pilih;
	Paslon *pointer = frontPaslon;
	pemilih *pointer1 = frontdatabasePemilih;
	while(pointer != NULL){
		if(pilih == pointer->noUrut){
			frontPemilih->pilihNoUrut = pilih;
			while(pointer1 != NULL){ // untuk ngubah pilih nomor urut yang ada di database
				if(frontPemilih->nik == pointer1->nik){
					pointer1->pilihNoUrut = pilih;
				}
				pointer1 = pointer1->next;
			}
		}
		pointer = pointer->next;
	}
	if (frontPemilih->pilihNoUrut.compare("none") == 0){
		std::cout << "==============================================================" << std::endl;
		std::cout << "Paslon dengan nomor urut " << pilih << " tidak ada" << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
}

void Pemilih::dequePemilih(){
	if(frontPemilih == rearPemilih){
		frontPemilih = NULL;
		rearPemilih = NULL;
		remove("database\\dataQueuePemilih.csv");
		return;
	}
	pemilih *temp = frontPemilih;
	frontPemilih = frontPemilih->next;
	temp = NULL;
}

void Pemilih::ubahSandi(){
	std::string sandiBaru;
	ulang:
	std::cout << "Masukan password baru : "; fflush(stdin); std::getline(std::cin, sandiBaru);
	if(frontPemilih->password == sandiBaru){
		std::cout << "==============================================================" << std::endl;
		std::cout << "Jangan memasukan password lama anda" << std::endl;
		std::cout << "==============================================================" << std::endl;
		goto ulang;
	} else {
		frontPemilih->password = sandiBaru;
		std::cout << "==============================================================" << std::endl;
		std::cout << "Update Password Berhasil" << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
}

void Pemilih::updatePemilih(){
	if (frontdatabasePemilih == NULL){
		std::cout << "==============================================================" << std::endl;
		std::cout<< ">>    Data Kosong   <<" <<std::endl;
		std::cout << "==============================================================" << std::endl;
		return;
	}
	pemilih *pointer = frontdatabasePemilih;
	std::string nik;
	std::cout << "Masukan nik : ";std::cin >> nik;
	while(pointer != NULL){
		if(pointer->nik.compare(nik) == 0){
			std::cout << "Input NIK  : ";std::cin >> pointer->nik;
			std::cout << "Input Nama : ";std::getline(std::cin, pointer->nama);
			std::cout << "==============================================================" << std::endl;
			std::cout << "Update data berhasil" << std::endl;
			std::cout << "==============================================================" << std::endl;
			return;
		}
		pointer = pointer->next;
	}
	std::cout << "==============================================================" << std::endl;
	std::cout << "Pemilih tidak terdaftar" << std::endl;
	std::cout << "==============================================================" << std::endl;
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
			pilihPaslon();
		} else if (menu == 4){
			ubahSandi();
		} else if (menu == 0){
			if(frontPemilih->pilihNoUrut.compare("none") != 0){
				dequePemilih();
			}
			return;
		} else {
			std::cout << "==============================================================" << std::endl;
			std::cout << "Pilihan tidak ada" << std::endl;
			std::cout << "==============================================================" << std::endl;
		}
	}
}

pemilih * Pemilih::getTail(pemilih *cur){
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
pemilih * Pemilih::partition(pemilih *head, pemilih *end, pemilih **newHead, pemilih **newEnd, bool jenis){
    pemilih *pivot = end;
    pemilih *prev = NULL, *cur = head, *tail = pivot;
 
    while (cur != pivot){
        if (jenis? cur->nik.compare(pivot->nik) < 0 : cur->nik.compare(pivot->nik) > 0){
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else {
            if (prev){
                prev->next = cur->next;
            }
            pemilih *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    if ((*newHead) == NULL){
        (*newHead) = pivot;
    }
 
    (*newEnd) = tail;
 
    return pivot;
}
 
pemilih* Pemilih::quickSortRecur(pemilih *head, pemilih *end, bool jenis){
    if (!head || head == end)
        return head;
 
    pemilih *newHead = NULL, *newEnd = NULL;
 
    pemilih *pivot = partition(head, end, &newHead, &newEnd, jenis);
 
    if (newHead != pivot)
    {
        pemilih *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        newHead = quickSortRecur(newHead, tmp, jenis);
 
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    pivot->next = quickSortRecur(pivot->next, newEnd, jenis);
 
    return newHead;
}
 
void Pemilih::quickSort(bool jenis){
	pemilih **headRef = &frontdatabasePemilih;
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef), jenis);
    return;
}

pemilih * Pemilih::go(pemilih *pointer, int batas){
	for(int i = 1; i <= batas; i-=-1){
		pointer = pointer->next;
	}
	return pointer;
}

int Pemilih::jumpSearch(){
	if(frontdatabasePemilih == NULL){
		std::cout<< ">>    Data Kosong   <<" <<std::endl;
		return -1;
	}
	quickSort(true);
	std::string nik;
	std::cout << "Masukan no Urut";fflush(stdin);std::getline(std::cin,nik);
	int n = 0;
	pemilih *pointer = frontdatabasePemilih;
	while(pointer != NULL){
		n++;
		pointer = pointer->next;
	}
	int step = sqrt(n); 
	int prev = 0; 
	int arr = std::min(step, n)-1;
	pemilih* data = go(frontdatabasePemilih,arr);
	while (data->nik.compare(nik) < 0){ 
		prev = step; 
		step += sqrt(n); 
		if (prev >= n){
			std::cout << ">> Pemilih tidak terdaftar <<" << std::endl;
			return -1; 
		}
		arr = std::min(step, n)-1;
		data = go(frontdatabasePemilih,arr);
	}
	data = go(frontdatabasePemilih,prev);
	while (data->nik < nik) { 
		prev++; 
		if (prev == std::min(step, n)){
			std::cout << ">> Pemilih tidak terdaftar <<" << std::endl;
			return -1;
		}
		data = go(frontdatabasePemilih,prev);
	} 
	data = go(frontdatabasePemilih,prev);
	if (data->nik == nik){
		std::cout << "==============================================================" << std::endl;
		std::cout << ">> Pemilih ditemukan" << prev+1 << std::endl;
		std::cout << "==============================================================" << std::endl;
		std::cout << "NIK           : " << data->nik << std::endl;
		std::cout << "Nama          : " << data->nama << std::endl;
		(data->pilihNoUrut.compare("none") == 0) ? std::cout << "Status        : Belum Coblos " << std::endl : std::cout << "Status        : Sudah Coblos " << std::endl;
		std::cout << std::endl;
		std::cout << "==============================================================" << std::endl;
		return prev;
	}
	std::cout << ">> Pemilih tidak terdaftar <<" << std::endl;
	return -1; 
}
