#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define nextR(P) P->nextR
#define nextM(P) P->nextM
#define info(P) P->info

using namespace std;

struct infotypeCustomer {
    string nama, tSewa = "-";
    int nik;//, noTelp;
    int64_t noTelp;
};

struct infotypeMobil {
    string jenisMobil, noPlat;
};

typedef struct elmCustomer *adr_customer;
typedef struct elmMobil *adr_mobil;
typedef struct elmRelation *adr_relation;

struct elmCustomer {
    infotypeCustomer info;
    adr_customer next;
    adr_relation nextR;
};

struct elmMobil {
    infotypeMobil info;
    adr_mobil next;
};

struct elmRelation {
    adr_relation next;
    adr_mobil nextM;
};

struct listCustomer {
    adr_customer first;
};

struct listMobil {
    adr_mobil first;
};

void create_listCustomer(listCustomer &L1);
adr_customer newElm_customer(infotypeCustomer x);
void insertFirst_customer(listCustomer &L1, adr_customer C);
void insertLast_customer(listCustomer &L1, adr_customer C);
//void deleteFirst_customer(listCustomer L1, adr_customer &C);
//void deleteLast_customer(listCustomer L1, adr_customer &C);
//void deleteAfter_customer(adr_customer prec, adr_customer &C);
void delete_customer(listCustomer &L1, adr_customer &c, int nik);
adr_customer cariCustomer(listCustomer L1, int nik);
void showCustomer(listCustomer L1);

void create_ListMobil(listMobil &L2);
adr_mobil newElm_Mobil(infotypeMobil x);
//void insertFirst_mobil(listMobil &L2, adr_mobil M);
void insertLast_mobil(listMobil &L2, adr_mobil M);
void delete_Mobil(listMobil &L2, adr_mobil &m, string plat);
adr_mobil cariMobil(listMobil L2, string plat);
void showMobil(listMobil L2);

adr_relation newElm_relation();
void inserlast_relation(adr_customer c, adr_relation r);
void delete_relation(adr_customer &c, adr_relation r, string plat);
//void inserlast_relation(listCustomer L1, adr_relation r, adr_customer c, adr_mobil m);
void connectParentdanChild(listCustomer &L1, listMobil &L2, int nik, string plat);;

void showAllData(listCustomer L1);
void showMobilInCustomer(adr_customer c, string plat);
adr_mobil CariMobilDariCustomer(adr_customer C, string plat);
int countMobil(adr_customer c);
void deleteMobilDariCustomer(listMobil &L2, adr_customer &c, string namaMobil);

//menu
void header();
void tambahCustomer(listCustomer &L1);
void tambahMobil(listMobil &L2);
void deleteCustomer(listCustomer &L1);
void deleteMobil(listMobil &L2);
void menuShow(listCustomer L1, listMobil L2);
void menuCari(listCustomer L1, listMobil L2);
void connect(listCustomer &L1, listMobil &L2);
void menuUtama(listCustomer &L1, listMobil &L2);
void input(listCustomer &L1, listMobil &L2);
void inputanAwal(listCustomer &L1, listMobil &L2);
#endif // TUBES_H_INCLUDED
