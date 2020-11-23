#include <iostream>
#include <fstream>
#include <string>
#include "..\include\File.h"

std::fstream dataFile;

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

void readDataBasePemilih(pemilih* &head, pemilih* &tail){
	std::string nik;
	std::string nama;
	openDataBasePemilih();
	
	while(!dataFile.eof()){
		pemilih* dataBaru = new pemilih();
		
		getline(dataFile,dataBaru->nik,',');
		getline(dataFile,dataBaru->nama, '\n');
		
		if (dataFile.eof()){
			break;
		}
		
		dataBaru->next = NULL;
		
		if (head == NULL){
			head = dataBaru;
			tail = dataBaru;
			dataBaru = NULL;
		} else {
			dataBaru->prev = NULL;
			tail->next = dataBaru;
			tail = dataBaru;
		}
	}
	



//	while (dataBaru != NULL){
//		std::cout << nik << std::endl;
//		dataBaru = dataBaru->next;
//	}
	
	std::cout << "Hahhah\n";
	dataFile.close();
	
}
