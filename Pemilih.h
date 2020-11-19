#include <string>
#include "Pemilu.h"
struct pemilih{
	int nik = 0;
	int pilihNoUrut = 0;
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
		void pushPemilih();
		void ubahSandi();
		void pilihPaslon();
		int login();
		void popPemilih();
};
