#include <string>

struct pemilih{
	int nik;
	std::string nama;
	int umur;
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
