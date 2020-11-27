#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include "..\include\Pemilih.h"
#include "..\include\Pemilu.h"
#include "..\include\File.h"
#include "..\include\FrontEnd.h"

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
		blink("BELUM ADA YANG DAFTAR",53);
		return 2;
	}
	do{
		frameTwoInput();
		password = "";
	    gotoXY(46,13);std::cout<< "NIK";fflush(stdin);
	    gotoXY(43,17);std::cout<< "PASSWORD";
		gotoXY(57,13);std::getline(std::cin,nik);
	    char huruf;
	    int i = 0;
	    int pass= 57;
	    gotoXY(pass,17);
	    while(huruf = getch()) { 
	    	if (huruf == 13){
		    	if (nik == frontPemilih->nik && password == frontPemilih->password && frontPemilih->pilihNoUrut.compare("none") == 0){
		    		blink("LOGIN BERHASIL");
			    	return 1;
			    } else {
		    		pemilu->cls();
		    		pemilih *pointer = frontPemilih;			    		
		    		while(pointer != NULL){
		    			if(nik == pointer->nama && password == pointer->password){
		    				blink("BUKAN ANTRIAN ANDA",54);
			    			return 0;
		    			}
		    			pointer = pointer->next;
		    		}
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

void Pemilih::displayDataDiri(){
	frameThreeInput();
	gotoXY(54,6);std::cout << "Menampilkan data diri" << std::endl;
	gotoXY(43,11);std::cout << "NIK" << std::endl;
	gotoXY(43,15);std::cout << "NAMA" << std::endl;
	gotoXY(43,19);std::cout << "PASSWORD" << std::endl;
	gotoXY(57,11);std::cout << frontPemilih->nik << std::endl;
	gotoXY(57,15);std::cout << frontPemilih->nama << std::endl;
	gotoXY(57,19);std::cout << frontPemilih->password << std::endl;
	gotoXY(41,26);std::cout << " >> TEKAN APA SAJA UNTUK MELANJUTKAN  << " << std::endl;
	getch();
}

void Pemilih::displayPemilih(){

	pemilih *pointer = frontdatabasePemilih;
	int i = 0;
	if(frontdatabasePemilih == NULL){
		blink(">>    DATA KOSONG   <<",52);
		return;
	}
	frameDisplay();
	gotoXY(56,2);std::cout << "Menampilkan data" << std::endl;
	gotoXY(12,7);std::cout << "NO" << std::endl;
	gotoXY(20,7);std::cout << "NIK" << std::endl;
	gotoXY(55,7);std::cout << "NAMA" << std::endl;
	gotoXY(97,7);std::cout << "STATUS" << std::endl;
	int y = 9;
	while(pointer != NULL){
		lineY(6,y,8,219);
		lineY(6,y,9,186);
		lineY(6,y,15,186);
		lineY(6,y,29,186);
		lineY(6,y,85,186);
		lineY(6,y,113,186);
		lineY(6,y,114,219);
		gotoXY(12,y);std::cout << i+1 << std::endl;
		gotoXY(17,y);std::cout << pointer->nik << std::endl;
		gotoXY(31,y);std::cout << pointer->nama << std::endl;
		if(pointer->pilihNoUrut.compare("none") == 0){
			gotoXY(87,y);std::cout << "Belum Coblos" << std::endl;
		} else {
			gotoXY(87,y);std::cout << "Sudah Coblos" << std::endl;
		}
		pointer = pointer->next;
		y++;
		i++;
	}
	lineY(6,y,9,186);
	lineY(6,y,113,186);
	lineX(8,114,y++,205);
	lineY(6,y,8,219);
	lineY(6,y,114,219);
	lineX(8,114,y,219);
	gotoXY(40,y);std::cout << " >> TEKAN APA SAJA UNTUK MELANJUTKAN  << " << std::endl;
	gotoXY(0,0);getch();
}
void Pemilih::enquePemilih(){
	int batas;
	bool cek = true;
	frameOneInput();
	gotoXY(40,15);std::cout << "JUMLAH PEMILIH";
	gotoXY(57,15);std::cin >> batas;
	for(int i = 0; i < batas; i-=-1){
		pemilih *databaru = new pemilih();
		ulang:
		system("cls");
		frameTwoInput();
		frame(84,97,9,11);
		gotoXY(86,10);std::cout << "Pemilih [" << i+1 << "]" << std::endl;
		gotoXY(46,13);std::cout << "NIK";
		gotoXY(46,17);std::cout << "NAMA";
		gotoXY(57,13);std::cin >> databaru->nik;
		cek = cekNomorUrut(databaru->nik);
		if (cek == true){
			goto ulang;
		}
		gotoXY(57,17);fflush(stdin);std::getline(std::cin,databaru->nama);
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
	frameTwoInput();
	gotoXY(46,13);std::cout << "NIK";
	gotoXY(46,17);std::cout << "NAMA";
	gotoXY(57,13);std::cin >> nik;
	gotoXY(57,17);fflush(stdin);std::getline(std::cin, nama);

	pemilih *matching = frontdatabasePemilih;
	pemilih *matching0 = frontPemilih;
	// cek udah daftar atau belum
	while(matching != NULL){
		if(matching->nik == nik && matching->daftar == true){
			if(matching->pilihNoUrut.compare("none") != 0){
				blink("ANDA SUDAH MEMILIH",54);
				return;
			} else {
				blink("ANDA SUDAH MENDAFTAR",54);
				return;
			}
		}
		matching = matching->next;
	}
	matching = frontdatabasePemilih;
	while(matching != NULL){
	    if(matching->nama.compare(nama) == 0 && matching->nik.compare(nik) == 0){
			pemilih *databaru = new pemilih();
			frameOneInput();
    		gotoXY(44,15);std::cout << "PASSWORD";
			gotoXY(57,15);std::getline(std::cin,databaru->password);
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
	blink("DATA ANDA TIDAK TERDAFTAR",51);
} 

void Pemilih::masuk_atau_daftar(){
	int opsi, cek;
	bool running = 1;
	enum option {KEMBALI = '0', LOGIN = '1', DAFTAR = '2'};
	do{
		frameAwal();
		if(frontPemilih == NULL){
			gotoXY(52,11);std::cout << "Belum ada yang daftar" << std::endl;
		} else {
			gotoXY(52,11);std::cout << "Giliran coblos : " << frontPemilih->nama << std::endl;
		}
		gotoXY(36,17);std::cout << "1. Login" << std::endl;
		gotoXY(58,17);std::cout << "2. Daftar" << std::endl;
		gotoXY(79,17);std::cout << "0. Kembali" << std::endl;
		opsi = getch();
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
		blink("ANDA SUDAH MEMILIH PASLON",51);
		return;
	}
	std::string pilih;
	Paslon *frontPaslon = pemilu->displayPaslon();
	if(frontPaslon == NULL){
		return;
	}
	frameOneInput();
	gotoXY(44,15);std::cout << "NO PASLON";
	gotoXY(57,15);std::cin >> pilih;
	Paslon *pointer = frontPaslon;
	pemilih *pointer1 = frontdatabasePemilih;
	while(pointer != NULL){
		if(pilih == pointer->noUrut){
			pointer->jumlahSuara++;
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
		blink("PASLON TIDAK TERDAFTAR",52);
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

void Pemilih::updatePemilih(){
	if (frontdatabasePemilih == NULL){
		blink(">>    DATA KOSONG   <<",52);
		return;
	}
	pemilih *pointer = frontdatabasePemilih;
	std::string nik;
	frameOneInput();
	gotoXY(46,15);std::cout << "NIK";
	gotoXY(57,15);std::cin >> nik;
	while(pointer != NULL){
		if(pointer->nik.compare(nik) == 0){
			frameTwoInput();
			gotoXY(46,13);std::cout << "NIK";
			gotoXY(46,17);std::cout << "NAMA";
			gotoXY(57,13);fflush(stdin);std::getline(std::cin, pointer->nik);
			gotoXY(57,17);std::getline(std::cin, pointer->nama);
			blink("UPDATE DATA BERHASIL",54);
			return;
		}
		pointer = pointer->next;
	}
	blink("PEMILIH TIDAK TERDAFTAR",52);
}

void Pemilih::deletePemilih(){
	if(frontdatabasePemilih == NULL){
		blink(">>    DATA KOSONG   <<",52);
		return;
	}
	pemilih *pointer = frontdatabasePemilih;
	std::string nik;
	frameOneInput();
	gotoXY(46,15);std::cout << "NIK";
	gotoXY(57,15);std::cin >> nik;
	if (reardatabasePemilih->nik.compare(nik) == 0){
		pemilih *pointer1 = frontdatabasePemilih;
		while(pointer1->next != reardatabasePemilih){
			pointer1 = pointer1->next;
		}
		pointer1->next = NULL;
		reardatabasePemilih = NULL;
		blink("DELETE PEMILIH BERHASIL",52);
		return;
	}
	
	while(pointer != NULL){
		if(pointer->nik == nik){
			blink("DELETE PEMILIH BERHASIL",52);
			if(frontdatabasePemilih == reardatabasePemilih){
				frontdatabasePemilih = reardatabasePemilih = NULL;
				return;
			} else if(frontdatabasePemilih != reardatabasePemilih && frontdatabasePemilih->nik == nik){
				frontdatabasePemilih = frontdatabasePemilih->next;
				delete pointer;
				return;
			}
		}
		if(pointer->next == NULL){
			break;
		}
		if(pointer->next->nik == nik){
			pemilih *temp = pointer->next;
			pointer->next = temp->next;
			delete temp;
			blink("DELETE PEMILIH BERHASIL",52);
			return;
		}
		pointer = pointer->next;
	}
	blink("PEMILIH TIDAK TERDAFTAR",52);
}
bool Pemilih::cekNomorUrut(std::string nik){
	pemilih *pointer = frontdatabasePemilih;
	while(pointer != NULL){
		if(pointer->nik == nik){
			blink("NIK SUDAH DIGUNAKAN",54);
			return true;
		}
		pointer = pointer->next;
	}
	return false;
}

void Pemilih::user(){
	char menu;
	while(true){
		system("cls");
		frameMain();
		frame(47,77,9,11);
		frame(32,57,14,16);
		frame(67,92,14,16);
		frame(32,57,18,20);
		frame(67,92,18,20);
		gotoXY(55,10);std::cout << ">> MENU USER <<" << std::endl;
		gotoXY(35,15);std::cout << "1. DATA DIRI" << std::endl;
		gotoXY(70,15);std::cout << "2. LIST PASLON" << std::endl;
		gotoXY(35,19);std::cout << "3. PILIH PASLON" << std::endl;
		gotoXY(70,19);std::cout << "0. MENU AWAL" << std::endl;
		menu = getch();
		if(menu == '1'){
			displayDataDiri();
		} else if (menu == '2'){
			pemilu->displayPaslon();
		} else if (menu == '3'){
			pilihPaslon();
			if(frontPemilih->pilihNoUrut.compare("none") != 0){
				dequePemilih();
				return;
			}
		} else if (menu == '0'){
			blink("ANDA BELUM PILIH PASLON",52);
		} else {
			blink("PILIHAN TIDAK ADA",55);
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
		blink(">>    DATA KOSONG   <<",52);
		return -1;
	}
	quickSort(true);
	std::string nik;
	frameOneInput();
	gotoXY(46,15);std::cout << "NIK";
	gotoXY(57,15);std::cin >> nik;
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
			blink("PEMILIH TIDAK TERDAFTAR",52);
			return -1; 
		}
		arr = std::min(step, n)-1;
		data = go(frontdatabasePemilih,arr);
	}
	data = go(frontdatabasePemilih,prev);
	while (data->nik < nik) { 
		prev++; 
		if (prev == std::min(step, n)){
			blink("PEMILIH TIDAK TERDAFTAR",52);
			return -1;
		}
		data = go(frontdatabasePemilih,prev);
	} 
	data = go(frontdatabasePemilih,prev);
	if (data->nik == nik){
		frameThreeInput();
		gotoXY(56,6);std::cout << "Pemilih ditemukan" << std::endl;
		gotoXY(43,11);std::cout << "NIK" << std::endl;
		gotoXY(43,15);std::cout << "NAMA" << std::endl;
		gotoXY(43,19);std::cout << "STATUS" << std::endl;
		gotoXY(57,11);std::cout << data->nik << std::endl;
		gotoXY(57,15);std::cout << data->nama << std::endl;
		if(data->pilihNoUrut.compare("none") == 0){
			gotoXY(57,19);std::cout << "Belum Coblos" << std::endl;
		} else {
			gotoXY(57,19);std::cout << "Sudah Coblos" << std::endl;
		}
		getch();
		return prev;
	}
	blink("PEMILIH TIDAK TERDAFTAR",52);
	return -1; 
}
