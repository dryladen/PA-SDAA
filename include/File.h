#ifndef _FILE
#define _FILE

#include "Pemilih.h"
#include "Pemilu.h"
void openDataBasePemilih();
void openDataBasePaslon();
void openQueuePemilih();

void readDataBasePemilih(pemilih* &head,pemilih* &tail);
void readDataPaslon(Paslon* &head, Paslon* &tail);
void readQueuePemilih(pemilih* &head, pemilih* &tail);

void updateDataBasePemilih(pemilih* &head);
void updateQueuePemilih(pemilih* head);
#endif
