#include <iostream>
#include <string>
#include <conio.h>

#include "..\include\Pemilu.h"
#include "..\include\Pemilih.h"

Paslon *frontPaslon = NULL;
Paslon *rearPaslon = NULL;

Pemilih *voter = new Pemilih();

void Pemilu::cls(){
	system("cls");
}

void Pemilu::enquePaslon(){
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
		std::cout << "Input Nomor Urut  : ";
		fflush(stdin);std::getline(std::cin,databaru->noUrut);
		std::cout << "Input Nama Ketua  : ";
		fflush(stdin);std::getline(std::cin,databaru->namaKetua);
		std::cout << "Input Nama Wakil  : ";
		fflush(stdin);std::getline(std::cin,databaru->namaWakilKetua);
		std::cout << "Input Nama Partai : ";
		fflush(stdin);std::getline(std::cin,databaru->partai);
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
		std::cout << "Paslon nomor urut [" << pointer->noUrut << "]" << std::endl;
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
	    std::cout<< "USERNAME : "; fflush(stdin);std::getline(std::cin,username);
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

void Pemilu::updatePaslon(){
	Paslon *pointer = frontPaslon;
	std::string noUrut;
	std::cout << "Masukan noUrut : ";std::cin >> noUrut;
	while(pointer != NULL){
		if(pointer->noUrut.compare(noUrut) == 0){
			std::cout << "Input Nama Ketua       : ";std::getline(std::cin, pointer->namaKetua);
			std::cout << "Input Nama Wakil Ketua : ";std::getline(std::cin, pointer->namaWakilKetua);
			std::cout << "==============================================================" << std::endl;
			std::cout << "Update data berhasil" << std::endl;
			std::cout << "==============================================================" << std::endl;
			return;
		}
		pointer = pointer->next;
	}
	std::cout << "==============================================================" << std::endl;
	std::cout << "Paslon tidak terdaftar" << std::endl;
	std::cout << "==============================================================" << std::endl;
}

void Pemilu::deletePaslon(){
	if(frontPaslon == NULL){
		std::cout << "==============================================================" << std::endl;
		std::cout<< ">>    Data Kosong   <<" <<std::endl;
		std::cout << "==============================================================" << std::endl;
		return;
	}
	Paslon *pointer = frontPaslon;
	std::string noUrut;
	std::cout << "Masukan noUrut : ";std::cin >> noUrut;

	if (rearPaslon->noUrut.compare(noUrut) == 0){
		Paslon *pointer1 = frontPaslon;
		while(pointer1->next != rearPaslon){
			pointer1 = pointer1->next;
		}
		pointer1->next = NULL;
		rearPaslon = NULL;
		std::cout << "==============================================================" << std::endl;
		std::cout<< ">>    Delete paslon berhasil  <<" <<std::endl;
		std::cout << "==============================================================" << std::endl;	
		return;
	}

	while(pointer != NULL){
		if(pointer->noUrut == noUrut){
			std::cout << "==============================================================" << std::endl;
			std::cout<< ">>    Delete paslon berhasil  <<" <<std::endl;
			std::cout << "==============================================================" << std::endl;
			if(frontPaslon == rearPaslon){
				frontPaslon = rearPaslon = NULL;
				return;
			} else if(frontPaslon != rearPaslon && frontPaslon->noUrut == noUrut){
				frontPaslon = frontPaslon->next;
				delete pointer;
				return;
			}
		}
		if(pointer->next->noUrut == noUrut){
			Paslon *temp = pointer->next;
			pointer->next = temp->next;
			delete temp;
			std::cout << "==============================================================" << std::endl;
			std::cout<< ">>    Delete paslon berhasil  <<" <<std::endl;
			std::cout << "==============================================================" << std::endl;
			return;
		}
		pointer = pointer->next;
	}
	std::cout << "==============================================================" << std::endl;
	std::cout<< ">>    Paslon tidak terdaftar  <<" <<std::endl;
	std::cout << "==============================================================" << std::endl;
}


void Pemilu::admin(){
	Pemilu* pemilu = new Pemilu();
	int cek = login();
	if (cek != 1){
		return;
	}
	int menu,pilih;
	bool jenis;
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
		std::cout << "4. Mencari data" << std::endl;
		std::cout << "5. Tampilkan data" << std::endl;
		std::cout << "0. Kembali ke menu awal" << std::endl;
		std::cout << "==============================================================" << std::endl;
		std::cout << "Masukan pilihan : "; std::cin >> menu;
		
		if(menu == 1){
			pilih = pemilihOrPaslon();
			(pilih == 1) ? voter->enquePemilih() : enquePaslon();
		} else if (menu == 2){
			pilih = pemilihOrPaslon();
			(pilih == 1) ?voter->updatePemilih() : updatePaslon();
		} else if (menu == 3){
			pilih = pemilihOrPaslon();
			if (pilih == 1){

			} else if (pilih == 2){
				deletePaslon();
			}
		} else if (menu == 4){
			pilih = pemilihOrPaslon();
			if (pilih == 1){
				voter->jumpSearch();
			} else if (pilih == 2){
				jumpSearch();
			}
		} else if (menu == 5){
			pilih = pemilihOrPaslon();
			if(pilih == 1){
				jenis = ascendingOrDescending();
				voter->quickSort(jenis);
				voter->displayPemilih();
			} else {
				jenis = ascendingOrDescending();
				quickSort(&frontPaslon,jenis);
				displayPaslon();
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

bool Pemilu::ascendingOrDescending(){
	int pilih;
	while(true){
		std::cout << "==============================================================" << std::endl;
		std::cout << "Ascending / Descending [1/2] : ";std::cin >> pilih;
		if (pilih == 1){
			return true;
		} else if (pilih == 2){
			return false;
		} else {
			std::cout << "==============================================================" << std::endl;
			std::cout << "Pilihan tidak ada " << std::endl;
			std::cout << "==============================================================" << std::endl;
		}
	}
}

Paslon * Pemilu::getTail(Paslon *cur){
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
Paslon * Pemilu::partition(Paslon *head, Paslon *end, Paslon **newHead, Paslon **newEnd, bool jenis){
    Paslon *pivot = end;
    Paslon *prev = NULL, *cur = head, *tail = pivot;
 
    while (cur != pivot){
        if (jenis? cur->noUrut.compare(pivot->noUrut) < 0 : cur->noUrut.compare(pivot->noUrut) > 0){
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else {
            if (prev){
                prev->next = cur->next;
            }
            Paslon *tmp = cur->next;
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
 
Paslon* Pemilu::quickSortRecur(Paslon *head, Paslon *end, bool jenis){
    if (!head || head == end)
        return head;
 
    Paslon *newHead = NULL, *newEnd = NULL;
 
    Paslon *pivot = partition(head, end, &newHead, &newEnd, jenis);
 
    if (newHead != pivot)
    {
        Paslon *tmp = newHead;
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
 
void Pemilu::quickSort(Paslon **headRef, bool jenis){
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef), jenis);
    return;
}

Paslon * Pemilu::go(Paslon *pointer, int batas){
	for(int i = 1; i <= batas; i-=-1){
		pointer = pointer->next;
	}
	return pointer;
}

int Pemilu::jumpSearch(){
	if(frontPaslon == NULL){
		std::cout<< ">>    Data Kosong   <<" <<std::endl;
		return -1;
	}
	quickSort(&frontPaslon, true);
	std::string noUrut;
	std::cout << "Masukan no Urut";std::fflush(stdin);std::getline(std::cin,noUrut);
	int n = 0;
	Paslon *pointer = frontPaslon;
	while(pointer != NULL){
		n++;
		pointer = pointer->next;
	}
	int step = sqrt(n); 
	int prev = 0; 
	int arr = std::min(step, n)-1;
	Paslon* data = go(frontPaslon,arr);
	while (data->noUrut.compare(noUrut) < 0){ 
		prev = step; 
		step += sqrt(n); 
		if (prev >= n){
			std::cout << ">> Paslon tidak terdaftar <<" << std::endl;
			return -1; 
		}
		arr = std::min(step, n)-1;
		data = go(frontPaslon,arr);
	}
	data = go(frontPaslon,prev);
	while (data->noUrut < noUrut) { 
		prev++; 
		if (prev == std::min(step, n)){
			std::cout << ">> Paslon tidak terdaftar <<" << std::endl;
			return -1;
		}
		data = go(frontPaslon,prev);
	} 
	data = go(frontPaslon,prev);
	if (data->noUrut == noUrut){
		std::cout << "==============================================================" << std::endl;
		std::cout << ">> Paslon ditemukan" << prev+1 << std::endl;
		std::cout << "==============================================================" << std::endl;
		std::cout << "Paslon nomor urut [" << data->noUrut << "]" << std::endl;
		std::cout << "Nama Ketua       : " << data->namaKetua << std::endl;
		std::cout << "Nama Wakil Ketua : " << data->namaWakilKetua << std::endl;
		std::cout << "Partai           : " << data->partai << std::endl;
		std::cout << "==============================================================" << std::endl;
		return prev;
	}
	std::cout << ">> Paslon tidak terdaftar <<" << std::endl;
	return -1; 
}