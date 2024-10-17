#include "tubes.h"

int main()
{
    listCustomer L1;
    listMobil L2;

    // Inisialisasi listCustomer dan listMobil
    create_listCustomer(L1);
    create_ListMobil(L2);

    // Memanggil fungsi inputanAwal untuk mengisi data awal
    inputanAwal(L1, L2);

    // Melanjutkan program dengan fungsi-fungsi lainnya
    adr_customer c;
    adr_mobil m;
    infotypeCustomer x;
    infotypeMobil p;

    menuUtama(L1, L2);
    return 0;
}
