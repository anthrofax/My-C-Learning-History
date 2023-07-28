#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct produk
{
    string namaProduk;
    int nilaiJualProduk;
    int modalProduk;
    int stokProduk;
    string replaceableLens;
};

produk dataProduk[50];

int jumlahProduk = 12, langkahPerulanganSatu = 0, kuantitasPembelian, keuntunganPerProduk, totalKeuntunganPerProduk, inputanUserNumber, produkYangDipilih, hargaModal, totalPendapatanHarian, nomorProduk;
string tujuanMenu, namaProdukYangDipilih, inputanUser, rincianPesanan, gantiLensa, jenisLensa, lagi, kembaliKeMenuUtama, ulangTampilData, menambahAtauMenghapus, pilihanDataYangInginDiubah;
bool masukKeMenuUtama = true, ulang = true, ulangDua, ulangTiga, ulangEmpat, ulangLima;
void tampilMenu(string yangInginDiTampilkan), bertanyaKeUser(string pertanyaan), inisialisasiDataProduk(), menampilkanDataProdukYangDipilih(), beritahuKeUserInputanSalah(), perubahanData(string perubahan), pengambilanData(), menghitungDataYangInginDitampilkan(), izinkanPerulanganBerjalan(), keluarDariPerulangan(string perulanganKeBerapa), memintaInputanUntukPenambahanProduk(int indeksProdukKeBerapa), menghapusDataProduk(), memintaInputanDataProdukYangInginDiubah(), menuMenampilkanDataProduk(), menuPenghitungPendapatan(), menambahDanMenghapusProduk(), menuMengubahDataProduk();

int main()
{
    inisialisasiDataProduk();
    while (masukKeMenuUtama == true)
    {
        tampilMenu("menuUtama");
        bertanyaKeUser("PILIH MENU DI ATAS SESUAI DENGAN KEBUTUHAN ANDA SAAT INI (1-4) : ");
        system("clear");
        if (tujuanMenu == "1")
            menuMenampilkanDataProduk();
        else if (tujuanMenu == "2")
        {
            ulang = true;
            menuPenghitungPendapatan();
        }
        else if (tujuanMenu == "3")
            menambahDanMenghapusProduk();
        else if (tujuanMenu == "4")
            menuMengubahDataProduk();
    }
    tampilMenu("creditShow");
}

// FUNGSI YANG DIBUAT ⬇︎
void bertanyaKeUser(string pertanyaan)
{
    if (pertanyaan == "Produk mana yang laku")
    {
        (langkahPerulanganSatu == 0) ? cout << "Inputkan nomor untuk produk yang laku hari ini sesuai dengan list di atas (inputnya satu-satu) : " : cout << "Inputkan lagi nomor produk mana yang laku hari ini : ";
        cin >> inputanUser;
    }
    else if (pertanyaan == "jawabanDataYangInginDiubah")
        cin >> pilihanDataYangInginDiubah;
    else
    {
        cout << pertanyaan;
        if (pertanyaan == "Apakah pembeli mengganti lensa frame nya? (y/n) ")
        {
            cin >> gantiLensa;
        }
        else if (pertanyaan == "Jenis lensa yang diganti, apakah CRMC atau Photocromic? (Ketik 1 = CRMC, Ketik 2 = Photochromic) ")
        {
            cin >> jenisLensa;
        }
        else if (pertanyaan == "Berapa jumlah produk tersebut yang terjual hari ini? ")
        {
            cin >> kuantitasPembelian;
        }
        else if (pertanyaan == "Ada lagi? (y/n) : ")
        {
            cin >> lagi;
        }
        else if (pertanyaan == "PILIH MENU DI ATAS SESUAI DENGAN KEBUTUHAN ANDA SAAT INI (1-4) : ")
            cin >> tujuanMenu;
        else if (pertanyaan == "Kembali ke menu utama? (y/n) ")
        {
            cin >> kembaliKeMenuUtama;
            if (kembaliKeMenuUtama == "y")
                system("clear");
            else if (kembaliKeMenuUtama == "n")
                masukKeMenuUtama = false;
        }

        else if (pertanyaan == "Inputkan nomor produk yang ingin data nya ditampilkan : ")
            cin >> nomorProduk;
        else if (pertanyaan == "Apa yang ingin anda lakukan? ")
            cin >> menambahAtauMenghapus;
        else if (pertanyaan == "Inputkan nomor produk yang ingin dihapus : ")
            cin >> nomorProduk;
        else if (pertanyaan == "Inputkan nomor produk yang ingin diubah datanya : ")
            cin >> nomorProduk;
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl;
}

void tampilMenu(string yangInginDiTampilkan)
{
    if (yangInginDiTampilkan == "menuUtama")
        cout << "\n      SELAMAT DATANG :D\n           MENU\n1. MENAMPILKAN DATA PRODUK\n2. PENGHITUNG PENDAPATAN\n3. MENAMBAH & MENGHAPUS PRODUK\n4. MENGUBAH DATA PRODUK\n";
    else if (yangInginDiTampilkan == "hasilAkhirTotalPendapatan")
    {
        cout << "                                              RINCIAN PRODUK YANG TERJUAL                                            " << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        cout << rincianPesanan << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------++" << endl;
        cout << "Total pendapatan hari ini adalah : " << totalPendapatanHarian << endl
             << endl;
    }
    else if (yangInginDiTampilkan == "produkYangDijual")
    {

        cout << "-------------------------------------------------------------------------------\n--                      LIST PRODUK OPTIK                                    --\n";

        for (int i = 0; i < jumlahProduk; i++)
        {
            cout << i + 1 << ". " << dataProduk[i].namaProduk << endl;
        }
        cout << "-------------------------------------------------------------------------------" << endl;
    }
    else if (yangInginDiTampilkan == "menuKetiga")
        cout << "MENU MENAMBAH & MENGHAPUS PRODUK\n\n1. Menambah produk\n2. Menghapus produk\n";
    else if (yangInginDiTampilkan == "pilihanDataYangInginDiUbah")
        cout << "1. NAMA PRODUK\n2. HARGA JUAL PRODUK\n3. HARGA MODAL PRODUK\n4. STOK PRODUK\n5. SEMUA NYA\nINPUTKAN DATA PRODUK MANA YANG INGIN ANDA UBAH? ";
    else if (yangInginDiTampilkan == "creditShow")
    {
        cout << "-------------------- 😎👩😎 THIS PROGRAM MADE BY 6 COOL PEOPLE 😎👩😎 ----------------------------" << endl;
        cout << setw(35) << left << " "
             << "- AFRIDHO IKHSAN -" << endl;
        cout << setw(33) << left << " "
             << "- ALMA ALIFYA ZAFIRA -" << endl;
        cout << setw(32) << left << " "
             << "- IVAL ALGIVARI PRATAMA -" << endl;
        cout << setw(30) << left << " "
             << "- MUHAMAD EKI BARKATAN SARI -" << endl;
        cout << setw(33) << left << " "
             << "- RIDHAKA GINA AMALIA -" << endl;
        cout << setw(30) << left << " "
             << "- SALMAN SHIDDIQ ABDUL RAUF -" << endl;
        cout << "----------------------------------------- GROUP 4 ------------------------------------------------" << endl;
    }
}

void inisialisasiDataProduk()
{
    // Value untuk Nama Produk
    dataProduk[0].namaProduk = "Kacamata 9182", dataProduk[1].namaProduk = "Kacamata 16006", dataProduk[2].namaProduk = "OGA Sunglass Polarized", dataProduk[3].namaProduk = "Cairan Pembersih Lensa", dataProduk[4].namaProduk = "Lensa Plano/Minus 1-8 (CRMC)", dataProduk[5].namaProduk = "Optik Case", dataProduk[6].namaProduk = "Rayban 3026 Sunglass", dataProduk[7].namaProduk = "Police 1216 Polarized", dataProduk[8].namaProduk = "Kacamata Ursula 2918", dataProduk[9].namaProduk = "Porsche 801 Sunglass", dataProduk[10].namaProduk = "Lensa Photocromic Plano/Minus (1-8)", dataProduk[11].namaProduk = "Nike Recover Sunglass";

    // Value untuk Nilai Jual Produk
    dataProduk[0].nilaiJualProduk = 80000, dataProduk[1].nilaiJualProduk = 85000, dataProduk[2].nilaiJualProduk = 175000, dataProduk[3].nilaiJualProduk = 5000, dataProduk[4].nilaiJualProduk = 35000, dataProduk[5].nilaiJualProduk = 15000, dataProduk[6].nilaiJualProduk = 75000, dataProduk[7].nilaiJualProduk = 115000, dataProduk[8].nilaiJualProduk = 75000, dataProduk[9].nilaiJualProduk = 85000, dataProduk[10].nilaiJualProduk = 80000, dataProduk[11].nilaiJualProduk = 115000;

    // Value untuk Modal Produk
    dataProduk[0].modalProduk = 35000, dataProduk[1].modalProduk = 40000, dataProduk[2].modalProduk = 140000, dataProduk[3].modalProduk = 2000, dataProduk[4].modalProduk = 15000, dataProduk[5].modalProduk = 10000, dataProduk[6].modalProduk = 50000, dataProduk[7].modalProduk = 60000, dataProduk[8].modalProduk = 30000, dataProduk[9].modalProduk = 50000, dataProduk[10].modalProduk = 60000, dataProduk[11].modalProduk = 80000;

    // Stok Produk
    for (int i = 0; i < jumlahProduk; i++)
    {
        dataProduk[i].stokProduk = 10;
    }

    // Kacamata yang lensa nya bisa diganti
    dataProduk[0].replaceableLens = "y", dataProduk[1].replaceableLens = "y", dataProduk[8].replaceableLens = "y";
}

// MENU FUNCTION 👇

// 1. MENU MENAMPILKAN DATA PRODUK
void menuMenampilkanDataProduk()
{
    bool ulang = true;

    tampilMenu("produkYangDijual");
    bertanyaKeUser("Inputkan nomor produk yang ingin data nya ditampilkan : ");

    menampilkanDataProdukYangDipilih();

    bertanyaKeUser("Kembali ke menu utama? (y/n) ");
}

// 2. MENU PENGHITUNG PENDAPATAN HARIAN
void menuPenghitungPendapatan()
{
    while (ulang == true)
    {
        izinkanPerulanganBerjalan();
        tampilMenu("produkYangDijual");

        while (ulangDua == true)
        {
            bertanyaKeUser("Produk mana yang laku");
            inputanUserNumber = stoi(inputanUser);

            if (inputanUserNumber >= 0 && inputanUserNumber <= jumlahProduk && dataProduk[inputanUserNumber - 1].namaProduk != "Slot Kosong")
            {
                if (dataProduk[inputanUserNumber - 1].replaceableLens == "y")
                {
                    while (ulangTiga == true)
                    {
                        bertanyaKeUser("Apakah pembeli mengganti lensa frame nya? (y/n) ");
                        if (gantiLensa == "y" || gantiLensa == "n")
                        {
                            if (gantiLensa == "y")
                            {
                                while (ulangEmpat == true)
                                {
                                    bertanyaKeUser("Jenis lensa yang diganti, apakah CRMC atau Photocromic? (Ketik 1 = CRMC, Ketik 2 = Photochromic) ");
                                    if (jenisLensa == "1" || jenisLensa == "2")
                                    {
                                        perubahanData("Nilai Jual & Modal Produk + Nilai Jual & Modal Lensa Pilihan");
                                        pengambilanData();
                                        perubahanData("Mengembalikan data produk seperti semula");
                                        keluarDariPerulangan("While ke-4");
                                    }
                                    else
                                    {
                                        beritahuKeUserInputanSalah();
                                    }
                                }
                            }
                            else if (gantiLensa == "n")
                            {
                                pengambilanData();
                            }
                            keluarDariPerulangan("While ke-3");
                        }
                        else
                        {
                            beritahuKeUserInputanSalah();
                        }
                    }
                }
                else
                {
                    pengambilanData();
                }
                bertanyaKeUser("Berapa jumlah produk tersebut yang terjual hari ini? ");
                menghitungDataYangInginDitampilkan();
                keluarDariPerulangan("While ke-2");
            }
            else
            {
                beritahuKeUserInputanSalah();
            }
        }

        rincianPesanan += to_string(langkahPerulanganSatu + 1) + ".   " + namaProdukYangDipilih + " : " + to_string(keuntunganPerProduk) + " (Keuntungan Per-produk) * " + to_string(kuantitasPembelian) + " pcs (Kuantitas Pembelian) = " + to_string(totalKeuntunganPerProduk) + "\n";

        while (ulangLima == true)
        {
            bertanyaKeUser("Ada lagi? (y/n) : ");
            if (lagi == "y")
            {
                keluarDariPerulangan("While ke-5");
            }
            else if (lagi == "n")
            {
                keluarDariPerulangan("While ke-5");
                keluarDariPerulangan("While yang pertama");
            }
            else
            {
                beritahuKeUserInputanSalah();
            }
        }
        langkahPerulanganSatu++;
    }

    tampilMenu("hasilAkhirTotalPendapatan");
    bertanyaKeUser("Kembali ke menu utama? (y/n) ");
}

// 3. MENU UNTUK MENAMBAH DAN MENGHAPUS PRODUK
void menambahDanMenghapusProduk()
{
    tampilMenu("menuKetiga");
    bertanyaKeUser("Apa yang ingin anda lakukan? ");

    if (menambahAtauMenghapus == "1")
    {

        int langkahPerulangan = jumlahProduk;
        for (int i = 0; i < langkahPerulangan; i++)
        {
            if (dataProduk[i].namaProduk == "Slot Kosong")
            {
                memintaInputanUntukPenambahanProduk(i);

                break;
            }
            else if (i == (jumlahProduk - 1))
            {
                jumlahProduk++;
                memintaInputanUntukPenambahanProduk(jumlahProduk - 1);

                break;
            }
        }

        tampilMenu("produkYangDijual");

        bertanyaKeUser("Kembali ke menu utama? (y/n) ");
    }
    else if (menambahAtauMenghapus == "2")
    {
        tampilMenu("produkYangDijual");
        bertanyaKeUser("Inputkan nomor produk yang ingin dihapus : ");

        menghapusDataProduk();

        tampilMenu("produkYangDijual");

        bertanyaKeUser("Kembali ke menu utama? (y/n) ");
    }
}

// 4. MENU UNTUK MENGUBAH DATA PRODUK
void menuMengubahDataProduk()
{
    tampilMenu("produkYangDijual");
    bertanyaKeUser("Inputkan nomor produk yang ingin diubah datanya : ");

    system("clear");

    tampilMenu("pilihanDataYangInginDiUbah");
    bertanyaKeUser("jawabanDataYangInginDiubah");

    memintaInputanDataProdukYangInginDiubah();

    tampilMenu("produkYangDijual");

    bertanyaKeUser("Kembali ke menu utama? (y/n) ");
}

// FUNCTION PENUNJANG DARI MENU FUNCTION DI ATAS

// 1. FUNCTION KHUSUS UNTUK PENUNJANG MENU MENAMPIL DATA PRODUK
void menampilkanDataProdukYangDipilih()
{
    cout << "Data dari produk nomor " << nomorProduk << endl;
    cout << "Nama Produk : " << dataProduk[nomorProduk - 1].namaProduk << endl;
    cout << "Harga Jual Produk : " << dataProduk[nomorProduk - 1].nilaiJualProduk << endl;
    cout << "Stok Produk : " << dataProduk[nomorProduk - 1].stokProduk << endl;
    cout << "Harga Modal Produk : " << dataProduk[nomorProduk - 1].modalProduk << endl
         << endl;
}

// 2. FUNCTION KHUSUS UNTUK PENUNJANG MENU PENGHITUNG PENDAPATAN
void beritahuKeUserInputanSalah()
{
    if (dataProduk[inputanUserNumber - 1].namaProduk == "Slot Kosong")
    {
        cout << "Nomor yang anda pilih belum ada data produk nya! (Pilih nomor yang lain)" << endl;
    }
    else
        cout << "Input yang anda masukkan salah!" << endl;
}

void perubahanData(string perubahan)
{
    if (perubahan == "Nilai Jual & Modal Produk + Nilai Jual & Modal Lensa Pilihan")
    {
        if (jenisLensa == "1")
        {
            dataProduk[(inputanUserNumber - 1)].namaProduk += " + Pasang Lensa CRMC";
            dataProduk[(inputanUserNumber - 1)].nilaiJualProduk += dataProduk[4].nilaiJualProduk;
            dataProduk[(inputanUserNumber - 1)].modalProduk += dataProduk[4].modalProduk /*Modal Produk + Modal*/;
        }
        else if (jenisLensa == "2")
        {
            dataProduk[(inputanUserNumber - 1)].namaProduk += " + Pasang Lensa PHOTOCHROMIC";
            dataProduk[(inputanUserNumber - 1)].nilaiJualProduk += dataProduk[10].nilaiJualProduk;
            dataProduk[(inputanUserNumber - 1)].modalProduk += dataProduk[10].modalProduk /*Modal Lensa*/;
        }
    }
    else if (perubahan == "Mengembalikan data produk seperti semula")
    {
        if (inputanUser == "1")
        {
            dataProduk[(inputanUserNumber - 1)].namaProduk = "Kacamata 9182";
        }
        else if (inputanUser == "2")
        {
            dataProduk[(inputanUserNumber - 1)].namaProduk = "Kacamata 16006";
        }
        else if (inputanUser == "9")
        {
            dataProduk[(inputanUserNumber - 1)].namaProduk = "Kacamata Ursula 2918";
        }

        if (jenisLensa == "1")
        {
            dataProduk[(inputanUserNumber - 1)].nilaiJualProduk -= dataProduk[4].nilaiJualProduk;
            dataProduk[(inputanUserNumber - 1)].modalProduk -= dataProduk[4].modalProduk /*Modal Lensa*/;
        }
        else if (jenisLensa == "2")
        {
            dataProduk[(inputanUserNumber - 1)].nilaiJualProduk -= dataProduk[10].nilaiJualProduk;
            dataProduk[(inputanUserNumber - 1)].modalProduk -= dataProduk[10].modalProduk /*Modal Lensa*/;
        }
    }
}

void pengambilanData()
{

    namaProdukYangDipilih = dataProduk[(inputanUserNumber - 1)].namaProduk;
    produkYangDipilih = dataProduk[(inputanUserNumber - 1)].nilaiJualProduk;
    hargaModal = dataProduk[(inputanUserNumber - 1)].modalProduk;
}

void menghitungDataYangInginDitampilkan()
{
    dataProduk[inputanUserNumber - 1].stokProduk -= kuantitasPembelian;
    keuntunganPerProduk = (produkYangDipilih - hargaModal);
    totalKeuntunganPerProduk = keuntunganPerProduk * kuantitasPembelian;
    totalPendapatanHarian += (produkYangDipilih - hargaModal) * kuantitasPembelian;
}

void izinkanPerulanganBerjalan()
{
    ulangDua = true, ulangTiga = true, ulangEmpat = true, ulangLima = true;
}

void keluarDariPerulangan(string perulanganKeBerapa)
{
    if (perulanganKeBerapa == "While yang pertama")
        ulang = false;
    else if (perulanganKeBerapa == "While ke-2")
        ulangDua = false;
    else if (perulanganKeBerapa == "While ke-3")
        ulangTiga = false;
    else if (perulanganKeBerapa == "While ke-4")
        ulangEmpat = false;
    else if (perulanganKeBerapa == "While ke-5")
        ulangLima = false;
}

// 3. FUNCTION KHUSUS UNTUK PENUNJANG MENU MENAMBAH & MENGHAPUS PRODUK
void memintaInputanUntukPenambahanProduk(int indeksProdukKeBerapa)
{
    cout << "Apakah produk ingin anda tambahkan bisa diganti lensa nya? (y/n) ";
    cin >> dataProduk[indeksProdukKeBerapa].replaceableLens;
    cout << "Masukkan nama produk : ";
    getline(cin.ignore(), dataProduk[indeksProdukKeBerapa].namaProduk);
    cout << "Masukkan nilai jual produk : ";
    cin >> dataProduk[indeksProdukKeBerapa].nilaiJualProduk;
    cout << "Masukkan harga modal produk: ";
    cin >> dataProduk[indeksProdukKeBerapa].modalProduk;
    cout << "Masukkan jumlah stok produk : ";
    cin >> dataProduk[indeksProdukKeBerapa].stokProduk;
}

void menghapusDataProduk()
{
    dataProduk[nomorProduk - 1].namaProduk = "Slot Kosong";
    dataProduk[nomorProduk - 1].nilaiJualProduk = 0;
    dataProduk[nomorProduk - 1].modalProduk = 0;
    dataProduk[nomorProduk - 1].stokProduk = 0;
}

// 4. FUNCTION KHUSUS UNTUK PENUNJANG MENU MENGUBAH DATA PRODUK
void memintaInputanDataProdukYangInginDiubah()
{
    if (pilihanDataYangInginDiubah == "1" || pilihanDataYangInginDiubah == "5")
    {
        cout << "Nama produk : ";
        getline(cin.ignore(), dataProduk[nomorProduk - 1].namaProduk);
    }

    if (pilihanDataYangInginDiubah == "2" || pilihanDataYangInginDiubah == "5")
    {
        cout << "Nilai jual produk : ";
        cin >> dataProduk[nomorProduk - 1].nilaiJualProduk;
    }

    if (pilihanDataYangInginDiubah == "3" || pilihanDataYangInginDiubah == "5")
    {
        cout << "Modal produk : ";
        cin >> dataProduk[nomorProduk - 1].modalProduk;
    }

    if (pilihanDataYangInginDiubah == "4" || pilihanDataYangInginDiubah == "5")
    {
        cout << "Jumlah stok produk: ";
        cin >> dataProduk[nomorProduk - 1].stokProduk;
    }
}