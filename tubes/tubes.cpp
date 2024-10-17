#include "tubes.h"

void create_listCustomer(listCustomer &L1) {
    first(L1) = NULL;
}
adr_customer newElm_customer(infotypeCustomer x) {
    adr_customer c = new elmCustomer;
    next(c) = NULL;
    nextR(c) = NULL;
    info(c) = x;
    return c;
}
void insertFirst_customer(listCustomer &L1, adr_customer C) {
    if (first(L1) == NULL) {
        first(L1) = C;
    } else {
        next(C) = first(L1);
        first(L1) = C;
    }
}
void insertLast_customer(listCustomer &L1, adr_customer C) {
    if (first(L1) == NULL) {
        first(L1) = C;
    } else {
        adr_customer p = first(L1);
        while (next(p) != NULL) {
            p = next(p);
        }
        next(p) = C;
    }
}
void delete_customer(listCustomer &L1,adr_customer &c, int nik) {
    c = cariCustomer(L1, nik);
    adr_relation r;

    if (c != NULL) {
        while (nextR(c) != NULL) {
            r = nextR(c);
            nextR(c) = next(r);
            next(r) = NULL;
        }
        if (c == first(L1)) {
            first(L1) = next(c);
            next(c) = NULL;
        } else {
            adr_customer temp = first(L1);
            while (next(temp) != c) {
                temp =  next(temp);
            }
            next(temp) = next(c);
            next(c) = NULL;
        }
    }
}
adr_customer cariCustomer(listCustomer L1, int nik) {
    adr_customer p = first(L1);

    while (p != NULL && info(p).nik != nik) {
            p = next(p);
    }
    return p;
}
void showCustomer(listCustomer L1) {
    adr_customer p = first(L1);
    while (p != NULL) {
        cout << info(p).nama << endl;
        p = next(p);
    }
}

void create_ListMobil(listMobil &L2) {
    first(L2) = NULL;
}
adr_mobil newElm_Mobil(infotypeMobil x){
        adr_mobil p = new elmMobil;
        next(p) = NULL;
        info(p) = x;
        return p;
}
/*void insertFirst_mobil(listMobil &L2, adr_mobil M) {
    if (first(L2) == NULL) {
        first(L2) = M;
    } else {
        next(M) = first(L2);
        first(L2) = M;
    }
}*/
void insertLast_mobil(listMobil &L2, adr_mobil M){
    adr_mobil p;
    if (first(L2) == NULL) {
        first(L2) = M;
    } else {
        p = first(L2);
        while (next(p) != NULL) {
            p = next(p);
        }
        next(p) = M;
    }
}
void delete_Mobil(listMobil &L2, adr_mobil &m, string plat) {
    adr_mobil before;
    m = first(L2);
    if (first(L2) == NULL) {
        cout << "Tidak ada Mobil" << endl;
    } else {
        while (m != NULL && info(m).noPlat != plat) {
            before = m;
            m = next(m);
        }
        if (m == first(L2)) {
            first(L2) = next(m);
            next(m) = NULL;
        } else {
            next(before) = next(m);
            next(m) = NULL;
        }
    }
}
adr_mobil cariMobil(listMobil L2, string plat){
    adr_mobil p = first(L2);
    while (p != NULL && info(p).noPlat != plat) {
        p = next(p);
    }
    return p;
}
void showMobil(listMobil L2){
    adr_mobil p;
    if (first(L2) == NULL) {
        cout << "Mobil Sedang Kosong";
    } else {
        p = first(L2);
        while (p != NULL) {
            cout << "Nama Mobil    :" << info(p).jenisMobil << endl;
            cout << "No Plat       :" << info(p).noPlat << endl;
            p = next(p);
        }
    }
    cout << endl;
}
adr_relation newElm_relation() {
    adr_relation r = new elmRelation;
    next(r) = NULL;
    nextM(r) = NULL;
    return r;
}
void inserlast_relation(adr_customer c, adr_relation r) {
    adr_relation temp = nextR(c);
    if (nextR(c) == NULL) {
        nextR(c) = r;
    } else {
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = r;
    }
}
void delete_relation(adr_customer &c, adr_relation r, string plat) {
    adr_relation before;
    r = nextR(c);
    if (r == NULL) {
        cout << "Customer tidak menyewa mobil" << endl;
    } else {
        while (r != NULL && info(nextM(r)).noPlat != plat) {
            before = r;
            r = next(r);
        }
        if (r == nextR(c)) {
            nextR(c) = next(r);
            next(r) = NULL;
        } else {
            next(before) = next(r);
            next(r) = NULL;
        }
    }
}
void connectParentdanChild(listCustomer &L1, listMobil &L2, int nik, string plat) {
    adr_customer c = cariCustomer(L1, nik);
    adr_mobil m = cariMobil(L2, plat);
    adr_relation r = newElm_relation();
    adr_relation temp = nextR(c);

    if (c == NULL) {
        cout << "Customer Tidak Ditemukan" << endl;
    } else if (m == NULL) {
        cout << "Mobil Tidak Ditemukan" << endl;
    } else {
        nextM(r) = m;
        if (nextR(c) == NULL) {
            nextR(c) = r;
        } else {
            while (next(temp) != NULL) {
                temp = next(temp);
            }
            next(temp) = r;
        }
    }
}
/*void inserlast_relation(listCustomer L1, adr_relation r,adr_customer c, adr_mobil m) {
    nextM(r) = m;
    if (nextR(c) == NULL) {
        nextR(c) = r;
    } else {
        adr_relation p = nextR(c);
        while (next(p) != NULL) {
            p = next(p);
        }
        next(p) = r;
    }
}*/
/*void deleteFirst_customer(listCustomer L1, adr_customer &C) {
    if (first(L1) == NULL) {
         cout << "List kosong" << endl;
    } else {
        C = next(first(L1));
        first(L1) = next(C);
        next(C) =  NULL;
    }
}*/
/*void deleteLast_customer(listCustomer L1, adr_customer &C) {
    adr_customer q = first(L1);
    if (first(L1) == NULL) {
        cout << "List Kosong" << endl;
    } else if (next(q) == NULL) {
        C = first(L1);
        first(L1) = NULL;
    } else {
        while (next(next(q)) != NULL) {
            q = next(q);
        }
        C = next(q);
        next(q)  = NULL;
    }
}*/
/*void deleteAfter_customer(adr_customer prec, adr_customer &C) {
    C = next(prec);
    next(prec) = next(C);
    next(C) = NULL;
}*/
void showAllData(listCustomer L1, listMobil L2){
    adr_customer p = first(L1);
    while (p != NULL) {
        cout << "Nama               : " << info(p).nama << endl;
        cout << "NIK                : " << info(p).nik << endl;
        cout << "No. Telp           : " << info(p).noTelp << endl;
        cout << "Durasi Sewa        : " << info(p).tSewa << endl;
        int n = countMobil(p);
        cout << "Banyak yang Disewa : " << n << endl;
        adr_relation r = nextR(p);
        if (r == NULL) {
            cout << "Tidak merental mobil" << endl;
            cout << endl;
        } else {
            while (r != NULL) {
                cout << info(nextM(r)).jenisMobil << endl;
                cout << info(nextM(r)).noPlat << endl;
                cout << endl;
                r = next(r);
            }
        }
        p = next(p);
    }
}
void showMobilInCustomer(adr_customer c, string plat) {
    adr_mobil m = CariMobilDariCustomer(c, plat);
    if (m == NULL) {
        cout << "Mobil Tidak Ada" << endl;
    } else {
        cout << "Nama Mobil : " << info(m).jenisMobil << endl;
        cout << "No Plat : " << info(m).noPlat << endl;
    }
}
adr_mobil CariMobilDariCustomer(adr_customer c, string plat){
    if (c != NULL) {
        adr_relation r = nextR(c);
        while (r != NULL) {
            if (info(nextM(r)).noPlat == plat) {
                return nextM(r);
            }
            r = next(r);
        }
    }

    return NULL;
}
int countMobil(adr_customer c){
    adr_relation r = nextR(c);
    int i = 0;
    while (r != NULL) {
        i++;
        r = next(r);
    }
    return i;
}
void deleteMobilDariCustomer(listMobil &L2, adr_customer &c, string plat) {
    adr_mobil m = CariMobilDariCustomer(c, plat);
    adr_relation r;
    if (m != NULL) {
        delete_relation(c, r, plat);
        cout << "Mobil telah diKembalikan" << endl;
    }
}
void header() {
    cout << "==========================================" << endl;
    cout << "                Rent Car" << endl;
    cout << " " << endl;
    cout << "====== Wiraldy Manggala Simanjuntak ======" << endl;
    cout << "========== Muhammad Adnansyah ============" << endl;
    cout << " " << endl;
    cout << "==========================================" << endl;
}
void tambahCustomer(listCustomer &L1) {
    bool run = true;
    int action = 0;
    infotypeCustomer xc;
    adr_customer c;

    while (run) {
        system("cls");
        header();
        cout << "============= Tambah Customer ============" << endl;
        cout << "Nama : ";
        cin >> xc.nama;

        cout << "NIK : ";
        cin >> xc.nik;

        cout << "No Telpon : ";
        cin >> xc.noTelp;

        cout << "Tanggal Sewa : ";
        cin >> xc.tSewa;
        cout << "==========================================" << endl;
        c = cariCustomer(L1, xc.nik);
        system("cls");

        header();
        cout << "============= Tambah Customer ============" << endl;

        if  (c == NULL) {
            cout << "Pilih tipe insert : " << endl;
            cout << "1. Insert First" << endl;
            cout << "2. Insert Last" << endl;
            cout << "------------------------------------------" << endl;
            cout << "Pilihan : ";
            cin >> action;
            cout << "------------------------------------------" << endl;

            if (action == 1) {
                c = newElm_customer(xc);
                insertFirst_customer(L1, c);
                run = false;
                cout << "Berhasil di daftarkan" << endl;
            } else if (action == 2) {
                c = newElm_customer(xc);
                insertLast_customer(L1, c);
                run = false;
                cout << "Berhasil di daftarkan" << endl;
            }
        } else {
            cout << "Pelanggan telah terdaftar" << endl;
            cout << "------------------------------------------" << endl;
            cout << "1. Kembali" << endl;
            cout << "2. Menu Utama" << endl;
            cout << "Piliihan : ";
            cin >> action;
            if (action == 2) {
                run = false;
            }
        }
    }

}
void tambahMobil(listCustomer &L1, listMobil &L2) {
    bool run = true;
    infotypeMobil xm;
    adr_customer c;
    adr_mobil m;
    int action = 0;

    while (run) {
        system("cls");
        header();
        cout << "============= Tambah Mobil ============" << endl;
        cout << "Nama Mobil : ";
        cin >> xm.jenisMobil;
        cout << endl;

        cout << "No Plat : ";
        cin >> xm.noPlat;
        cout << endl;
        cout << "------------------------------------------" << endl;
        m = cariMobil(L2, xm.noPlat);

        system("cls");
        header();
        cout << "============= Tambah Mobil ============" << endl;
        if (m != NULL) {
            cout << "Mobil telah tedaftar" << endl;
            cout << "------------------------------------------" << endl;
        } else if (m == NULL) {
            m = newElm_Mobil(xm);
            insertLast_mobil(L2, m);
            run = false;
            cout << "Berhasil di Tambahkan" << endl;
        }
        cout << "------------------------------------------" << endl;
        cout << "1. Tambah Mobil" << endl;
        cout << "2. Menu Utama" << endl;
        cout << "Piliihan : ";
        cin >> action;
        if (action == 2) {
        run = false;
        }
    }
}
void deleteCustomer(listCustomer &L1) {
    bool run = true;
    int action = 0;
    int nik;
    adr_customer c;

    while (run) {
        system("cls");
        header();
        cout << "============= Hapus Pelanggan ============" << endl;
        cout << "NIK : ";
        cin >> nik;
        cout << endl;
        cout << "------------------------------------------" << endl;
        c = cariCustomer(L1, nik);

        system("cls");
        header();
        if (c == NULL) {
            cout << "Pelanggan tidak ditemukan" << endl;
            cout << "------------------------------------------" << endl;
            run = false;
        } else {
            delete_customer(L1, c, nik);
            cout << "Berhasil di hapus" << endl;
            cout << "------------------------------------------" << endl;
            cout << "1. Kembali" << endl;
            cout << "2. Menu Utama" << endl;
            cout << "Piliihan : ";
            cin >> action;
            if (action == 2) {
                run = false;
            }
        }
    }
}
void deleteMobil(listCustomer &L1, listMobil &L2) {
    bool run = true;
    int action = 0;
    string namaMobil;
    string plat;
    adr_mobil m;
    adr_customer c;

    while (run) {
        system("cls");
        header();
        cout << "============= Hapus Mobil ============" << endl;
        cout << "Nama Mobil : ";
        cin >> namaMobil;
        cout << endl;
        cout << "No Plat : ";
        cin >> plat;
        cout << endl;
        cout << "------------------------------------------" << endl;
        m = cariMobil(L2, plat);
        if (m == NULL) {
            cout << "Mobil tidak ditemukan" << endl;
            cout << "------------------------------------------" << endl;
            cout << "1. Kembali" << endl;
            cout << "2. Menu Utama" << endl;
            cout << "Piliihan : ";
            cin >> action;
            if (action == 2) {
                run = false;
            }
        } else {
            c = first(L1);
            while (c != NULL) {
                deleteMobilDariCustomer(L2, c, namaMobil);
                c = next(c);
            }
            delete_Mobil(L2, m, plat);
            delete m;
            system("cls");
            header();
            cout << "Berhasil dihapus" << endl;
            cout << "------------------------------------------" << endl;
            cout << "1. Kembali" << endl;
            cout << "2. Menu Utama" << endl;
            cout << "Piliihan : ";
            cin >> action;
            if (action == 2) {
                run = false;
            }
        }
    }
}
void menuShow(listCustomer L1, listMobil L2) {
    bool run = true;
    int action = 0;
    while (run) {
        system("cls");
        header();
        cout << "================ Show ================" << endl;
        cout << "1. Pelanggan" << endl;
        cout << "2. Mobil" << endl;
        cout << "3. Tamplikan semua data" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Pilihan : ";
        cin >> action;
        cout << endl;
        cout << "--------------------------------------" << endl;
        system("cls");
        if (action == 1) {
            showCustomer(L1);
        } else if (action == 2) {
            showMobil(L2);
        } else if (action == 3) {
            showAllData(L1, L2);
        }
        cout << "--------------------------------------" << endl;
        cout << "1. Kembali" << endl;
        cout << "2. Menu Utama" << endl;
        cout << "Piliihan : ";
        cin >> action;
        if (action == 2) {
            run = false;
        }
    }
}
void menuCari(listCustomer L1, listMobil L2) {
    bool run = true;
    int action = 0;
    string plat;
    int nik;
    adr_customer c;
    adr_mobil m;
    while (run) {
        system("cls");
        header();
        cout << "================ Pencarian ================" << endl;
        cout << "1. Pelanggan" << endl;
        cout << "2. Mobil" << endl;
        cout << "3. Mobil dari pelanggan" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Pilihan : ";
        cin >> action;
        cout << endl;
        cout << "-------------------------------------------" << endl;
        system("cls");
        if (action == 1) {
            cout << "Masukan NIK" << endl;
            cin >> nik;
            system("cls");
            c = cariCustomer(L1, nik);
            cout << "Nama : " << info(c).nama << endl;
            cout << "NIK : " << info(c).nik << endl;
            cout << "No Telpon : " << info(c).noTelp << endl;
            cout << "Tangga Sewa : " << info(c).tSewa << endl;
            cout << "--------------------------------------" << endl;
            cout << "1. Kembali" << endl;
            cout << "2. Menu Utama" << endl;
            cout << "Piliihan : ";
            cin >> action;
            if (action == 2) {
                run = false;
            }
        } else if (action == 2) {
            cout << "Masukan No Plat Mobil : " << endl;
            cin >> plat;
            system("cls");
            m = cariMobil(L2, plat);
            cout << "Nama Mobil : " << info(m).jenisMobil << endl;
            cout << "No Plat : " << info(m).noPlat << endl;
            cout << "--------------------------------------" << endl;
            cout << "1. Kembali" << endl;
            cout << "2. Menu Utama" << endl;
            cout << "Piliihan : ";
            cin >> action;
            if (action == 2) {
                run = false;
            }
        } else if (action == 3) {
            cout << "Masukan No Plat : ";
            cin >> plat;
            cout << "Masukan NIK : ";
            cin >> nik;
            cout << endl;
            system("cls");
            c = cariCustomer(L1, nik);
            showMobilInCustomer(c, plat);
            cout << "--------------------------------------" << endl;
            cout << "1. Kembali" << endl;
            cout << "2. Menu Utama" << endl;
            cout << "Piliihan : ";
            cin >> action;
            if (action == 2) {
                run = false;
            }
        }
    }
}
void connect(listCustomer &L1, listMobil &L2) {
    bool run = true;
    int action = 0;
    infotypeCustomer xc;
    int nik;
    string plat;
    adr_customer c;
    adr_mobil m, m2;


    while (run) {
        system("cls");
        header();
        cout << "============= Penyewaan Mobil ============" << endl;
        cout << "NIK : ";
        cin >> nik;
        cout << "Nomor Plat Mobil : ";
        cin >> plat;
        cout << "Durasi Sewa : ";
        cin >> xc.tSewa;
        cout << "------------------------------------------" << endl;

        c = cariCustomer(L1, nik);
        info(c).tSewa = xc.tSewa;
        m = cariMobil(L2, plat);

        system("cls");
        header();
        if (c == NULL) {
            cout << "Customer Belum Terdaftar" << endl;
            cout << "------------------------------------------" << endl;
        } else if (c != NULL && m != NULL ) {
            connectParentdanChild(L1, L2, nik, plat);
            cout << "Berhasil Rental" << endl;
        } else if (m == NULL) {
            cout << "Mobil Tidak Tersedia" << endl;
            cout << "------------------------------------------" << endl;
        }
        cout << "------------------------------------------" << endl;
        cout << "1. Tambah Mobil" << endl;
        cout << "2. Menu Utama" << endl;
        cout << "Piliihan : ";
        cin >> action;
        if (action == 2) {
        run = false;
        }
    }
}
void menuUtama(listCustomer &L1, listMobil &L2) {
    bool run = true;
    int action = 0;

    while(run) {
        system("cls");
        header();
        cout << "================ Main Menu =================" << endl;
        cout << " " << endl;
        cout << "1. Tambah Customer" << endl;
        cout << "2. Tambah Mobil" << endl;
        cout << "3. Delete Customer" << endl;
        cout << "4. Delete Mobil" << endl;
        cout << "5. Tampilkan List" << endl;
        cout << "6. Cari Mobil" << endl;
        cout << "7. Penyewaan" << endl;
        cout << "0. keluar" << endl;
        cout << " " << endl;
        cin >> action;
        cout << "============================================" << endl;

        switch(action) {
    case 1:
        tambahCustomer(L1);
        break;
    case 2:
        tambahMobil(L1, L2);
        break;
    case 3:
        deleteCustomer(L1);
        break;
    case 4:
        deleteMobil(L1, L2);
        break;
    case 5:
        menuShow(L1, L2);
        break;
    case 6 :
        menuCari(L1, L2);
        break;
    case 7 :
        connect(L1, L2);
        break;
    case 0:
        run = false;
        break;
        }
    }
}
/*void input(listCustomer &L1, listMobil &L2) {
    infotypeCustomer xc;
    infotypeMobil xm;
    adr_customer c;
    adr_mobil m;

    xc.nama = "dante";
    xc.nik = 3;
    xc.noTelp = 081398543752;
    xc.tSewa = "30Feb2029";
    c = newElm_customer(xc);
    insertLast_customer(L1, c);

    xc.nama = "ivan";
    xc.nik = 6;
    xc.noTelp = 081398543758;
    xc.tSewa = "31Apr2029";
    c = newElm_customer(xc);
    insertLast_customer(L1, c);

    xc.nama = "dane";
    xc.nik = 7;
    xc.noTelp = 081398543756;
    xc.tSewa = "31Juli2029";
    c = newElm_customer(xc);
    insertLast_customer(L1, c);

    xm.jenisMobil = "Xpander";
    xm.noPlat = "Z3E";
    m = newElm_Mobil(xm);
    insertLast_mobil(L2, m);

    xm.jenisMobil = "Avanza";
    xm.noPlat = "G1TA";
    m = newElm_Mobil(xm);
    insertLast_mobil(L2, m);

    xm.jenisMobil = "Sigra";
    xm.noPlat = "A5HEL";
    m = newElm_Mobil(xm);
    insertLast_mobil(L2, m);

    xm.jenisMobil = "CRV";
    xm.noPlat = "CH215TY";
    m = newElm_Mobil(xm);
    insertLast_mobil(L2, m);

    connectParentdanChild(L1, L2, 36740710213224, "A5HEL");
    connectParentdanChild(L1, L2, 32160210048, "Z3E");
    connectParentdanChild(L1, L2, 321567834567, "G1TA");
    connectParentdanChild(L1, L2, 321567834567, "CH215TY");
}
*/

void inputanAwal(listCustomer &L1, listMobil &L2){
    infotypeCustomer x;
    infotypeMobil y;
    adr_mobil q;

    x.nama = "Adnan";
    x.nik = 130122;
    x.noTelp = 81291482233;
    adr_customer m = newElm_customer(x);
    insertLast_customer(L1, m);

    x.nama = "Syah";
    x.nik = 130123;
    x.noTelp = 81291482345;
    m = newElm_customer(x);
    insertLast_customer(L1, m);

    x.nama = "Wira";
    x.nik = 130114;
    x.noTelp =81291489028;
    m = newElm_customer(x);
    insertLast_customer(L1, m);

    x.nama = "Aldy";
    x.nik = 130110;
    x.noTelp = 81291481234;
    m = newElm_customer(x);
    insertLast_customer(L1, m);


    y.jenisMobil =  "Fortuner";
    y.noPlat = "z3e";
    q = newElm_Mobil(y);
    insertLast_mobil(L2, q);

    y.jenisMobil =  "Pajero";
    y.noPlat = "a41ab";
    q = newElm_Mobil(y);
    insertLast_mobil(L2, q);

    y.jenisMobil =  "Sigra";
    y.noPlat = "a5hel";
    q = newElm_Mobil(y);
    insertLast_mobil(L2, q);


};
