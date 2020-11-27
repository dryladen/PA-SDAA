#include <string>
#ifndef _PEMILIH
#define _PEMILIH
struct pemilih{
	std::string nik;
	std::string nama;
	std::string password;
	std::string pilihNoUrut = "none";
	bool daftar = false;
	pemilih* next;
};

class Pemilih{
	public:
		int login();
		int jumpSearch();
		void masuk_atau_daftar();
		void cekData();
		void daftar();
		void user();
		void deletePemilih();
		void displayDataDiri();
		void displayPemilih();
		void enquePemilih();
		void pilihPaslon();
		void dequePemilih();
		void updatePemilih();
		void quickSort(bool jenis);
		bool cekNomorUrut(std::string noUrut);
		pemilih* getTail(pemilih *cur);
		pemilih* partition(pemilih *head, pemilih *end, pemilih **newHead, pemilih **newEnd, bool jenis);
		pemilih* quickSortRecur(pemilih *head, pemilih *end, bool jenis);
		pemilih* go(pemilih *pointer, int batas);
};

#endif
