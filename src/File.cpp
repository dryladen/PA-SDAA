#include "..\include\Pemilu.h"

std::fstream dataFile;
// Untuk Open File
void openDataBasePemilih(){
	
	dataFile.open("database\\databasePemilih.csv", std::ios::out | std::ios::in | std::ios::binary);
	
	if (dataFile.is_open()){
		return;
	} 
	dataFile.close();
	dataFile.open("database\\databasePemilih.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
}

void openDataBasePaslon(){
	dataFile.open("database\\dataPaslon.csv", std::ios::out | std::ios::in | std::ios::binary);
	
	if (dataFile.is_open()){
		return;
	} 
	dataFile.close();
	dataFile.open("database\\dataPaslon.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
}

bool openQueuePemilih(){
	dataFile.open("database\\dataQueuePemilih.csv", std::ios::out | std::ios::in | std::ios::binary);
	
	if (dataFile.is_open()){
		return true;
	} 
	dataFile.close();
	dataFile.open("database\\dataQueuePemilih.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
	return false;
}

// Untuk Ngebaca File, Selalu dipanggil di awal program
void readDataBasePemilih(pemilih* &head, pemilih* &tail){
	std::string space;
	openDataBasePemilih();
	
	while(!dataFile.eof()){
		
		pemilih* dataBaru = new pemilih();
		getline(dataFile,dataBaru->nik,',');
		getline(dataFile,dataBaru->nama, ',');
		getline(dataFile,dataBaru->pilihNoUrut,',');
		dataFile >> dataBaru->daftar;
		getline(dataFile, space);
		dataBaru->next = NULL;
		
		if (dataFile.eof()){
			break;
		}
		
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

void readQueuePemilih(pemilih* &head, pemilih* &tail){
	bool exist = openQueuePemilih();
	if (exist == false){
		dataFile.close();
		return;
	}
	
	while(!dataFile.eof()){
		
		pemilih* dataBaru = new pemilih();
		getline(dataFile,dataBaru->nik,',');
		getline(dataFile,dataBaru->nama, ',');
		getline(dataFile,dataBaru->password,',');
		getline(dataFile,dataBaru->pilihNoUrut,'\n');
		dataBaru->next = NULL;

		if (dataFile.eof()){
			break;
		}
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
		getline(dataFile,space);
		
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
		dataFile << temp->nik << "," << temp->nama << "," << temp->pilihNoUrut << "," << temp->daftar;
		dataFile << "\n";
		temp = temp->next;
	}
	dataFile.close();
}

void updateQueuePemilih(pemilih* head){
	dataFile.open("database\\dataQueuePemilih.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
	
	pemilih* tmp = head;
	
	while (tmp!=NULL){
		dataFile << tmp->nik << "," << tmp->nama << "," << tmp->password << "," << tmp->pilihNoUrut;
		dataFile << "\n";
		tmp = tmp->next;
	}
	dataFile.close();
}

void updateDataPaslon(Paslon* &head){
	dataFile.open("database\\dataPaslon.csv", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
	
	Paslon* tmp = head;
	
	while (tmp!=NULL){
		dataFile << tmp->noUrut << "," << tmp->namaKetua << "," << tmp->namaWakilKetua << "," << tmp->partai << "," << tmp->jumlahSuara;
		dataFile << "\n";
		tmp = tmp->next;
	}
	dataFile.close();
}
