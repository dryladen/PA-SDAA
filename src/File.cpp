#include <iostream>
#include <fstream>
#include <string>
#include "..\include\File.h"
#include "..\include\Pemilu.h"

std::fstream dataFile;
// Untuk Open File
void openDataBasePemilih(){
	
	dataFile.open("database\\databasePemilih.csv", std::ios::out | std::ios::in | std::ios::binary);
	
	if (dataFile.is_open()){
		std::cout << "dataFile Ada\n";
		return;
	} 
	std::cout << "dataFile Gak Ada. Buat Baru\n";
	dataFile.close();
	dataFile.open("database\\databasePemilih.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
}

void openDataBasePaslon(){
	dataFile.open("database\\dataPaslon.csv", std::ios::out | std::ios::in | std::ios::binary);
	
	if (dataFile.is_open()){
		std::cout << "dataPaslon Ada\n";
		return;
	} 
	std::cout << "dataPaslon Gak Ada. Buat Baru\n";
	dataFile.close();
	dataFile.open("database\\dataPaslon.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
}

void openQueuePemilih(){
	dataFile.open("database\\dataQueuePemilih.csv", std::ios::out | std::ios::in | std::ios::binary);
	
	if (dataFile.is_open()){
		std::cout << "dataQueuePemilih Ada\n";
		return;
	} 
	std::cout << "dataQueuePemilih Gak Ada. Buat Baru\n";
	dataFile.close();
	dataFile.open("database\\dataQueuePemilih.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
}

// Untuk Ngebaca File, Selalu dipanggil di awal program
void readDataBasePemilih(pemilih* &head, pemilih* &tail){
	openDataBasePemilih();
	
	while(!dataFile.eof()){
		pemilih* dataBaru = new pemilih();
		
		getline(dataFile,dataBaru->nik,',');
		getline(dataFile,dataBaru->nama, ',');
		getline(dataFile,dataBaru->pilihNoUrut,'\n');
		
		dataBaru->next = NULL;
		
		if (head == NULL){
			head = dataBaru;
			tail = dataBaru;
			dataBaru = NULL;
		} else {
			tail->next = dataBaru;
			tail = dataBaru;
		}
		if (dataFile.eof()){
			break;
		}
	}
	dataFile.close();
}

void readQueuePemilih(pemilih* &head, pemilih* &tail){
	openQueuePemilih();
	
	while(!dataFile.eof()){
		pemilih* dataBaru = new pemilih();
		getline(dataFile,dataBaru->nik,',');
		getline(dataFile,dataBaru->nama, ',');
		getline(dataFile,dataBaru->password,',');
		getline(dataFile,dataBaru->pilihNoUrut,'\n');

		
		dataBaru->next = NULL;

		if (head == NULL){
			head = dataBaru;
			tail = dataBaru;
			dataBaru = NULL;
		} else {
			tail->next = dataBaru;
			tail = dataBaru;
		}
		if (dataFile.eof()){
			break;
		}
	}
	dataFile.close();
}

void readDataPaslon(Paslon* &head, Paslon* &tail){
	std::string space;
	openDataBasePaslon();
	
	while(!dataFile.eof()){
		Paslon* dataBaru = new Paslon();
		
		getline(dataFile,dataBaru->noUrut,',');
		getline(dataFile,dataBaru->namaKetua, ',');
		getline(dataFile,dataBaru->namaWakilKetua,',');
		getline(dataFile,dataBaru->partai,',');
		dataFile >> dataBaru->jumlahSuara;
		
		if (dataFile.eof()){
			break;
		}
		
		dataBaru->next = NULL;
		
		if (head == NULL){
			head = dataBaru;
			tail = dataBaru;
			dataBaru = NULL;
		} else {
			tail->next = dataBaru;
			tail = dataBaru;
		}
	}
	dataFile.close();	
}

// Untuk Update File. Di panggil saat update dan delete
void updateDataBasePemilih(pemilih* &head){
	dataFile.open("database\\databasePemilih.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
	
	pemilih* temp = head;
	
	while (temp!=NULL){
		dataFile << temp->nik << "," << temp->nama << "," << temp->pilihNoUrut;
		if (temp->next != NULL){
			dataFile << "\n";
		}
		temp = temp->next;
	}
	dataFile.close();
}

void updateQueuePemilih(pemilih* head){
	dataFile.open("database\\dataQueuePemilih.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
	
	pemilih* tmp = head;
	
	while (tmp!=NULL){
		dataFile << tmp->nik << "," << tmp->nama << "," << tmp->password << "," << tmp->pilihNoUrut;
		if (tmp->next != NULL){
			dataFile << "\n";
		}
		tmp = tmp->next;
	}
	dataFile.close();
}

