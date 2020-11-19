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
		int login(std::string);
		int pemilihOrPaslon();
		void admin();
		void push();
		void display();
};

#endif
