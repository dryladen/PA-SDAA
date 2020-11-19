#include <string>

struct pemilih{
	int nik;
	int umur;
	int pilihNoUrut;
	std::string nama;
	std::string alamat;
	std::string password;
	pemilih* next;
};

class Pemilih{
	public:
		void masuk_atau_daftar();
		void cekData();
		void daftar();
		void user();
};
