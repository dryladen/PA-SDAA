#include <string>
#ifndef _PEMILU
#define _PEMILU

struct Paslon{
	int id;
	int noUrut;
	std::string namaKetua;
	std::string namaWakilKetua;
	std::string partai;
	Paslon* next;
};



class Pemilu{
	public:
		int login();
		int pemilihOrPaslon();
		void admin();
		void pushPaslon();
		void cls();
		Paslon* displayPaslon();
};

#endif
