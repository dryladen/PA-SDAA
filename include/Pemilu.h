#include <string>
#include <math.h>
#include <limits>
#include <fstream>
#include <conio.h>
#include <iostream>
#include "..\include\File.h"
#include "..\include\Pemilih.h"
#include "..\include\FrontEnd.h"

#ifndef _PEMILU
#define _PEMILU
struct Paslon{
	std::string noUrut;
	std::string namaKetua;
	std::string namaWakilKetua;
	std::string partai;
	int jumlahSuara;
	Paslon* next;
};

class Pemilu{
	public:
		int login();
		void admin();
		int jumpSearch();
		void enquePaslon();
		void dequePaslon();
		void updatePaslon();
		void deletePaslon();
		int pemilihOrPaslon();
		bool ascendingOrDescending();
		Paslon *getTail(Paslon *cur);
		Paslon *displayPaslon(int cek);
		bool cekNomorUrut(std::string noUrut);
		Paslon *go(Paslon *pointer, int batas);
		void quickSort(Paslon **headRef, bool jenis);
		Paslon *quickSortRecur(Paslon *head, Paslon *end, bool jenis);
		Paslon *partition(Paslon *head, Paslon *end, Paslon **newHead, Paslon **newEnd, bool jenis);
};

#endif
