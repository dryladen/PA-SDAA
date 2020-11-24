#ifndef _FILE
#define _FILE

#include "Pemilih.h"
#include "Pemilu.h"
void openDataBasePemilih();
void openDataBasePaslon();
bool openQueuePemilih();

void readDataBasePemilih(pemilih* &head,pemilih* &tail);
void readDataPaslon(Paslon* &head, Paslon* &tail);
void readQueuePemilih(pemilih* &head, pemilih* &tail);

void updateDataBasePemilih(pemilih* &head);
void updateQueuePemilih(pemilih* head);
void updateDataPaslon(Paslon* &head);
#endif
