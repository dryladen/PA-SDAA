#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include "..\include\Pemilu.h"
#include "..\include\Pemilih.h"
#include "..\include\FrontEnd.h"

extern Paslon *frontPaslon;
extern Paslon *rearPaslon;

Pemilih *voter = new Pemilih();

void Pemilu::cls(){
	system("cls");
}
bool Pemilu::cekNomorUrut(std::string noUrut){
	Paslon *pointer = frontPaslon;
	while(pointer != NULL){
		if(pointer->noUrut == noUrut){
			blink("NOMOR URUT SUDAH DIGUNAKAN",50);
			return true;
		}
		pointer = pointer->next;
	}
	return false;
}
void Pemilu::enquePaslon(){
	system("cls");
	int batas;
	bool cek = false;
	frameOneInput();
	gotoXY(40,15);std::cout << "JUMLAH  PASLON";
	gotoXY(57,15);std::cin >> batas;
	for(int i = 0; i < batas; i-=-1){
		Paslon *databaru = new Paslon();
		ulang:
		system("cls");
		frameFourInput();
		gotoXY(59,6);std::cout << "Paslon [" << i+1 << "]" << std::endl;
		gotoXY(43,11);std::cout << "NOMOR URUT";
		gotoXY(43,15);std::cout << "KETUA";
		gotoXY(43,19);std::cout << "WAKIL";
		gotoXY(43,23);std::cout << "PARTAI";
		gotoXY(57,11);fflush(stdin);std::getline(std::cin,databaru->noUrut);
		cek = cekNomorUrut(databaru->noUrut);
		if (cek == true){
			goto ulang;
		}
		gotoXY(57,15);fflush(stdin);std::getline(std::cin,databaru->namaKetua);
		gotoXY(57,19);fflush(stdin);std::getline(std::cin,databaru->namaWakilKetua);
		gotoXY(57,23);fflush(stdin);std::getline(std::cin,databaru->partai);
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
	system("cls");
	Paslon *pointer = frontPaslon;
	if(frontPaslon == NULL){
		blink(">>    DATA KOSONG   <<",52);
		return NULL;
	}
	frameDisplay();
	gotoXY(52,2);std::cout << "MENAMPILKAN DATA" << std::endl;
	gotoXY(12,7);std::cout << "NO URUT" << std::endl;
	gotoXY(32,7);std::cout << "KETUA" << std::endl;
	gotoXY(62,7);std::cout << "WAKIL" << std::endl;
	gotoXY(86,7);std::cout << "PARTAI" << std::endl;
	gotoXY(100,7);std::cout << "JUMLAH SUARA" << std::endl;
	int y = 9;
	while(pointer != NULL){
		lineY(6,y,8,219);
		lineY(6,y,9,186);
		lineY(6,y,20,186); // kolom 1
		lineY(6,y,50,186); // kolom 2
		lineY(6,y,78,186); // kolom 3
		lineY(6,y,98,186); // kolom 4
		lineY(6,y,113,186);
		lineY(6,y,114,219);
		gotoXY(14,y);std::cout <<pointer->noUrut << std::endl;
		gotoXY(22,y);std::cout <<pointer->namaKetua << std::endl;
		gotoXY(52,y);std::cout <<pointer->namaWakilKetua << std::endl;
		gotoXY(80,y);std::cout <<pointer->partai << std::endl;
		gotoXY(105,y);std::cout <<pointer->jumlahSuara << std::endl;
		pointer = pointer->next;
		y++;
	}
	lineY(6,y,9,186);
	lineY(6,y,113,186);
	lineX(8,114,y++,205);
	lineY(6,y,8,219);
	lineY(6,y,114,219);
	lineX(8,114,y,219);
	gotoXY(40,y);std::cout << " >> TEKAN APA SAJA UNTUK MELANJUTKAN  << " << std::endl;
	getch();
	return frontPaslon;
}

int Pemilu::login(){
	std::string username,password;
	int percobaan = 0;
	do{
		frameTwoInput();
		password = "";
	    gotoXY(43,13);std::cout<< "USERNAME : "; fflush(stdin);
	    gotoXY(43,17);std::cout<< "PASSWORD : ";
		gotoXY(57,13);std::getline(std::cin,username);
	    char huruf;
	    int i = 0;
	    int pass= 57;
	    gotoXY(pass,17);
	    while(huruf = getch()) { 
	    	if (huruf == 13){
			    if (username == "admin" && password == "admin"){
			    	blink("LOGIN BERHASIL");
			    	return 1;
			    } else {
			    	blink("AKUN TIDAK ADA",56);
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
	    	blink("KEMBALI KE MENU AWAL",54);
	    	return 0;
	    }
	} while (true);  
	return 1;
}

void Pemilu::updatePaslon(){
	Paslon *pointer = frontPaslon;
	std::string noUrut;
	frameOneInput();
	gotoXY(44,15);std::cout << "NO URUT";
	gotoXY(57,15);std::cin >> noUrut;
	while(pointer != NULL){
		if(pointer->noUrut.compare(noUrut) == 0){
			frameTwoInput();
			gotoXY(45,13);std::cout << "KETUA";
			gotoXY(42,17);std::cout << "WAKIL KETUA";
			gotoXY(57,13);fflush(stdin);std::getline(std::cin, pointer->namaKetua);
			gotoXY(57,17);std::getline(std::cin, pointer->namaWakilKetua);
			blink("UPDATE DATA BERHASIL",54);
			return;
		}
		pointer = pointer->next;
	}
	blink("PASLON TIDAK TERDAFTAR",52);
}

void Pemilu::deletePaslon(){
	if(frontPaslon == NULL){
		blink(">>    DATA KOSONG   <<",52);
		return;
	}
	std::string noUrut;
	frameOneInput();
	gotoXY(44,15);std::cout << "NO URUT";
	gotoXY(57,15);std::cin >> noUrut;
	if (rearPaslon->noUrut.compare(noUrut) == 0){
		Paslon *pointer1 = frontPaslon;
		while(pointer1->next != rearPaslon){
			pointer1 = pointer1->next;
		}
		pointer1->next = NULL;
		rearPaslon = NULL;
		blink("DELETE PASLON BERHASIL",52);
		return;
	}

	Paslon *pointer = frontPaslon;
	while(pointer != NULL){
		std::cout << "a" << std::endl;
		if(pointer->noUrut == noUrut){
			blink("DELETE PASLON BERHASIL",52);
			if(frontPaslon == rearPaslon){
				frontPaslon = rearPaslon = NULL;
				return;
			} else if(frontPaslon != rearPaslon && frontPaslon->noUrut == noUrut){
				frontPaslon = frontPaslon->next;
				delete pointer;
				return;
			}
		}
		if(pointer->next == NULL){
			break;
		}
		if(pointer->next->noUrut == noUrut){
			Paslon *temp = pointer->next;
			pointer->next = temp->next;
			delete temp;
			blink("DELETE PASLON BERHASIL",52);
			return;
		}
		pointer = pointer->next;
	}
	blink("PASLON TIDAK TERDAFTAR",52);
}

void Pemilu::admin(){
	Pemilu* pemilu = new Pemilu();
	int cek = login();
	if (cek != 1){
		return;
	}
	int pilih;
	char menu;
	bool jenis;
	enum option {
		KEMBALI = '0',
		TAMBAH_DATA = '1',
		UBAH_DATA = '2',
		HAPUS_DATA = '3',
		CARI_DATA = '4', 
		TAMPILKAN_DATA = '5'
	};
	
	while(true){
		framePemiluMain();
		menu = getch();
		if(menu == TAMBAH_DATA){
			voter->quickSort(true);
			quickSort(&frontPaslon,true);
			pilih = pemilihOrPaslon();
			if (pilih == 1){
				voter->enquePemilih();
			} else if (pilih == 2){
				enquePaslon();
			} 
		} else if (menu == UBAH_DATA){
			pilih = pemilihOrPaslon();
			if (pilih == 1){
				voter->updatePemilih();
			} else if (pilih == 2){
				updatePaslon();
			} 
		} else if (menu == HAPUS_DATA){
			pilih = pemilihOrPaslon();
			if (pilih == 1){
				voter->deletePemilih();
			} else if (pilih == 2){
				deletePaslon();
			} 
		} else if (menu == CARI_DATA){
			pilih = pemilihOrPaslon();
			if (pilih == 1){
				voter->jumpSearch();
			} else if (pilih == 2){
				jumpSearch();
			}
		} else if (menu == TAMPILKAN_DATA){
			pilih = pemilihOrPaslon();
			if(pilih == 1){
				jenis = ascendingOrDescending();
				voter->quickSort(jenis);
				voter->displayPemilih();
			} else if (pilih == 2){
				jenis = ascendingOrDescending();
				quickSort(&frontPaslon,jenis);
				displayPaslon();
			}
		} else if (menu == KEMBALI){
			return;
		} else {
			blink("PILIHAN TIDAK ADA",55);
		}
	}
}

int Pemilu::pemilihOrPaslon(){
	system("cls");
	char pilih;
	enum option {
		KEMBALI = '0',
		PEMILIH = '1',
		PASLON = '2',
	};
	while(true){
		frameAwal();
		gotoXY(59,11);std::cout << "PILIHAN"; 
		gotoXY(36,17);std::cout << "1.PEMILIH"; 
		gotoXY(58,17);std::cout << "2.PASLON"; 
		gotoXY(79,17);std::cout << "0.KEMBALI"; 
		pilih = getch();
		switch(pilih){
			case PEMILIH:
				return 1;
			case PASLON:
				return 2;
			case KEMBALI:
				return 3;
			default:
				blink("PILIHAN TIDAK ADA",55);
				break;
		}
	}
}

bool Pemilu::ascendingOrDescending(){
	system("cls");
	char pilih;
	while(true){
		frameMain();
		frame(32,57,14,16);
		frame(67,92,14,16);
		gotoXY(41,15);std::cout << "ASCENDING"; 
		gotoXY(75,15);std::cout << "DESCENDING"; 
		pilih = getch();
		if (pilih == '1'){
			return true;
		} else if (pilih == '2'){
			return false;
		} else {
			blink("PILIHAN TIDAK ADA",55);
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
		std::cout<< ">>    DATA KOSONG   <<" <<std::endl;
		return -1;
	}
	quickSort(&frontPaslon, true);
	std::string noUrut;
	frameOneInput();
	gotoXY(44,15);std::cout << "NO URUT";
	gotoXY(57,15);std::cin >> noUrut;
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
			blink("PASLON TIDAK TERDAFTAR",52);
			return -1; 
		}
		arr = std::min(step, n)-1;
		data = go(frontPaslon,arr);
	}
	data = go(frontPaslon,prev);
	while (data->noUrut < noUrut) { 
		prev++; 
		if (prev == std::min(step, n)){
			blink("PASLON TIDAK TERDAFTAR",52);
			return -1;
		}
		data = go(frontPaslon,prev);
	} 
	data = go(frontPaslon,prev);
	if (data->noUrut == noUrut){
		frameFourInput();
		gotoXY(56,6);std::cout << "NOMOR URUT " << data->noUrut << std::endl;
		gotoXY(43,11);std::cout << "KETUA" << std::endl;
		gotoXY(43,15);std::cout << "WAKIL" << std::endl;
		gotoXY(43,19);std::cout << "PARTAI" << std::endl;
		gotoXY(42,23);std::cout << "JUMLAH SUARA" << std::endl;
		gotoXY(57,11);std::cout <<data->namaKetua << std::endl;
		gotoXY(57,15);std::cout <<data->namaWakilKetua << std::endl;
		gotoXY(57,19);std::cout <<data->partai << std::endl;
		gotoXY(57,23);std::cout <<data->jumlahSuara << std::endl;
		getch();
		return prev;
	}
	blink("PASLON TIDAK TERDAFTAR",52);
	return -1; 
}
