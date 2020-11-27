#include <string>
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
		int pemilihOrPaslon();
		int jumpSearch();
		void cls();
		void gotoXY(int x, int y);
		void admin();
		void enquePaslon();
		void dequePaslon();
		void updatePaslon();
		void deletePaslon();
		void quickSort(Paslon **headRef, bool jenis);
		bool ascendingOrDescending();
		bool cekNomorUrut(std::string noUrut);
		Paslon* displayPaslon();
		Paslon *getTail(Paslon *cur);
		Paslon *go(Paslon *pointer, int batas);
		Paslon *quickSortRecur(Paslon *head, Paslon *end, bool jenis);
		Paslon *partition(Paslon *head, Paslon *end, Paslon **newHead, Paslon **newEnd, bool jenis);
};

#endif
