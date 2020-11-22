#include <string>
#include <math.h>
#ifndef _PEMILIH
#define _PEMILIH
struct pemilih{
	std::string nik;
	std::string pilihNoUrut = "none";
	std::string nama;
	std::string password;
	bool daftar = false;
	pemilih* next;
};

class Pemilih{
	public:
		void masuk_atau_daftar();
		void cekData();
		void daftar();
		void user();
		void displayDataDiri();
		void displayPemilih();
		void enquePemilih();
		void ubahSandi();
		void pilihPaslon();
		int login();
		void dequePemilih();
		void updatePemilih();
		void quickSort(bool jenis);
		pemilih* getTail(pemilih *cur);
		pemilih* partition(pemilih *head, pemilih *end, pemilih **newHead, pemilih **newEnd, bool jenis);
		pemilih* quickSortRecur(pemilih *head, pemilih *end, bool jenis);
		pemilih* go(pemilih *pointer, int batas);
		int jumpSearch();
};

#endif
