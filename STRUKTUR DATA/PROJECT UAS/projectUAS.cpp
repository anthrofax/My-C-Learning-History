#include <iostream>
#include <string>
#include <limits>

using namespace std;
#define maks 20

struct siswa
{
    string nama, tanggalLahir;
    int kelas, IdSiswa, sisaSPP;
    bool lunasSPP;
};

struct dataSiswa
{
    siswa identitasSiswa;
    struct dataSiswa *prev, *next;
};

struct dataSiswa *bantu = NULL, *hapus = NULL;

struct dataSiswa *awalKelas[12] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
struct dataSiswa *akhirKelas[12] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

int nisnbawaan = 1000000001, tanyakelas, pil;

string namaSiswaBawaan[12][10] = {{"Ahmad Fauzi", "Ahmad Sutrisno", "Andi Nugroho", "Ani Puspitasari", "Arianto Wijaya",
                                   "Arif Sutrisno", "Budi Santoso", "Budi Wijaya", "Dewi Indah", "Kartika Sari"},
                                  {"Dedi Pratama", "Dian Fitri", "Dian Purnama", "Dodi Santoso", "Evi Susanti",
                                   "Harianto Prabowo", "Heriawan Putra", "Indah Fitriani", "Indah Sari", "Joko Sutrisno"},
                                  {"Maya Dewi", "Maya Sari", "Maya Siti", "Maman Santoso", "Maman Sutrisno",
                                   "Rina Amelia", "Rina Astuti", "Rina Cahyani", "Rina Dewi", "Rina Fitriani"},
                                  {"Rina Indriani", "Rina Wahyuni", "Rina Wijayanti", "Rina Wijayanto", "Ricky Wijaya",
                                   "Sari Purnama", "Sinta Indriani", "Siti Rahmawati", "Suhardi Prabowo", "Surya Nugroho"},
                                  {"Surya Pratama", "Surya Wijaya", "Tuti Indriani", "Triana Dewi", "Yulia Setiawati",
                                   "Yuli Susanti", "Yuni Susanti", "Yuni Susanto", "Yuni Susilawati", "Yuny Susilawati"},
                                  {"Maya Kusuma", "Aditya Wijaya", "Rani Sari", "Devi Putri", "Anita Rahayu",
                                   "Indra Permana", "Ratna Asmila", "Yoga Putra", "Farhan Santoso", "Putri Cahaya"},
                                  {"Bagus Prayogo ", "Joko Surya", "Yusuf Wijaya", "Fira Lestari", "Rina Aulia",
                                   "Eko Nugroho", "Dina Aulia", "Hadi Prasetya", "Bambang Wijaya", "Sinta Dewi"},
                                  {"Deny Nugroho", "Aditya Oktavian", "Rapi Pratama", "Bulan putri", "Maya Wijaya",
                                   "Riko Simanjuntak", "Dwi Septian", "Adnan Wijaya", "Novri Herdianto", "Tiara Putri"},
                                  {"Raka Setiawan", "Ebi Santoso", "Reza Alfalah", "Devani Putri", "Saykila Maulida",
                                   "Aldo Pramata", "Medis Putri", "Fadil Alfares", "Daffa Firmansyah", "sakia Wati"},
                                  {"Ajis Guswan", "Pratama Indah", "Didik Hermawan", "aulia syaputri", "Lola Amalia",
                                   "Andika Alfarezy", "Wulan Dari", "Faldo Purnomo", "Muhamad Rehan", "Rika Olin"},
                                  {"Ragil Santoso", "Yuda Harianto", "Widi Pertiwi", "Reisa elsa", "Najwa Indah",
                                   "Mail Muslikin", "Rara Kasturi", "Radit Wijaya", "Altaf Safar", "Aprilia Putri"},
                                  {"Agus Nugroho", "Bambang Santoso", "Dedi Pratama", "Desi Permata", "Indah Fitriani",
                                   "Joko Pratama", "Rina Astuti", "Rudi Wijaya", "Suhardi Prabowo", "Triana Dewi"}};

string tanggalLahir[12][10] = {{"03 Januari 2005", "12 Februari 2005", "27 Maret 2005", "09 April 2005", "21 Mei 2005",
                                "06 Juni 2005", "17 Juli 2005", "29 Agustus 2005", "10 September 2005", "25 Oktober 2005"},
                               {"08 November 2005", "16 Desember 2005", "01 Januari 2005", "14 Februari 2005", "28 Maret 2005",
                                "05 April 2005", "19 Mei 2005", "07 Juni 2005", "20 Juli 2005", "02 Agustus 2005"},
                               {"13 September 2005", "30 Oktober 2005", "04 November 2005", "23 Desember 2005", "11 Januari 2005",
                                "02 Februari 2005", "19 Maret 2005", "13 April 2005", "26 Mei 2005", "08 Juni 2005"},
                               {"24 Juli 2005", "16 Agustus 2005", "09 September 2005", "28 Oktober 2005", "05 November 2005",
                                "22 Desember 2005", "07 Januari 2005", "18 Februari 2005", "04 Maret 2005", "14 April 2005"},
                               {"30 Mei 2004", "06 Oktober 2004", "19 Juli 2004", "31 Agustus 2004", "12 September 2004",
                                "27 Oktober 2004", "03 November 2004", "21 Desember 2004", "09 Januari 2004", "22 Februari 2004"},
                               {"06 Maret 2004", "18 April 2004", "23 Mei 2004", "07 Juni 2004", "19 Juli 2004",
                                "01 Agustus 2004", "15 September 2004", "29 Oktober 2004", "12 November 2004", "24 Desember 2004"},
                               {"21 Januari 2004", "18 Desember 2004", "21 Februari 2004", "19 Agustus 2004", "09 Juni 2004",
                                "27 Juli 2004", "26 Januari 2004", "24 September 2004", "15 November 2004", "29 Februari 2004"},
                               {"27 Oktober 2004", "25 Desember 2004", "07 September 2004", "12 Maret 2004", "27 Januari 2004",
                                "10 September 2004", "15 Juni 2004", "07 November 2004", "05 Januari 2004", "20 November 2004"},
                               {"31 Juli 2003", "27 Mei 2003", "04 Oktober 2003", "19 Desember 2003", "23 Agustus 2003",
                                "11 Mei 2003", "07 Februari 2003", "24 Juni 2003", "26 Juni 2003", "12 Desember 2003"},
                               {"27 Februari 2003", "15 Agustus 2003", "19 Oktober 2003", "07 Maret 2003", "25 Agustus 2003",
                                "05 Februari 2003", "29 November 2003", "26 Februari 2003", "14 November 2003", "18 Juni 2003"},
                               {"11 Juni 2003", "18 Juli 2003", "29 April 2003", "10 Agustus 2003", "08 Agustus 2003",
                                "29 Desember 2003", "27 Maret 2003", "24 November 2003", "22 September 2003", "24 Januari 2003"},
                               {"06 Agustus 2003", "11 Februari 2003", "07 Desember 2003", "11 Juli 2003", "21 Juli 2003",
                                "17 Agustus 2003", "01 September 2003", "17 November 2003", "29 Maret 2003", "23 April 2003"}};

string kelasBawaan[12] = {"10 MIPA 1", "10 MIPA 2", "10 IPS 1", "10 IPS 2",
                          "11 MIPA 1", "11 MIPA 2", "11 IPS 1", "11 IPS 2",
                          "12 MIPA 1", "12 MIPA 2", "12 IPS 1", "12 IPS 2"};

struct Queue
{
    int rear, front;
    struct dataSiswa *siswa[20];
} antrianBimbinganKonseling;

struct dataSiswa *bantuStack;

struct Stack
{
    struct dataSiswa *top;
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(struct dataSiswa *siswaYangDipush)
    {
        struct dataSiswa *siswa = new dataSiswa;
        siswa->identitasSiswa.nama = siswaYangDipush->identitasSiswa.nama;
        siswa->identitasSiswa.kelas = siswaYangDipush->identitasSiswa.kelas;
        siswa->identitasSiswa.IdSiswa = siswaYangDipush->identitasSiswa.IdSiswa;
        siswa->identitasSiswa.tanggalLahir = siswaYangDipush->identitasSiswa.tanggalLahir;
        siswa->identitasSiswa.lunasSPP = siswaYangDipush->identitasSiswa.lunasSPP;
        siswa->identitasSiswa.sisaSPP = siswaYangDipush->identitasSiswa.sisaSPP;
        siswa->next = top;
        top = siswa;
    }

    void pop()
    {
        struct dataSiswa *temp = top;
        top = top->next;

        delete temp;
    }

    void tampilSiswaTerbaru()
    {
        if (top == NULL)
        {
            cout << "List siswa kosong. \n";
            return;
        }
        struct dataSiswa *currentStudent = top;
        cout << "List Siswa (Berdasarkan Data Terbaru Siswa SMAN 01 Karawang) : \n";
        int listNumber = 1;
        while (currentStudent != NULL)
        {
            cout << listNumber++ << ". " << currentStudent->identitasSiswa.nama << endl;
            currentStudent = currentStudent->next;
        }
    }
};

struct Stack daftarSiswaTerbaru,
    temp;

bool isFull(Queue *selectedQueue)
{
    return selectedQueue->rear == maks;
}

bool isEmpty(Queue *selectedQueue)
{
    return selectedQueue->rear == 0;
}

void enqueue(Queue *selectedQueue, struct dataSiswa *enqueuedPointer)
{
    if (isFull(selectedQueue))
    {
        std::cout << "Antrian sudah penuh!" << endl;
    }
    else
    {
        selectedQueue->siswa[selectedQueue->rear] = enqueuedPointer;
        selectedQueue->rear++;
    }
}

void dequeue(Queue *selectedQueue)
{

    for (int i = selectedQueue->front; i < selectedQueue->rear; i++)
    {
        selectedQueue->siswa[i] = selectedQueue->siswa[i + 1];
    }
    selectedQueue->rear--;
}

void tampilMenu()
{
    cout << "\n\n\t\t======== SELAMAT DATANG DI PROGRAM PENGELOLAAN DATA SISWA SMAN 01 KARAWANG ========\n\n"
         << "\n1. Data Siswa\n"
         << "\n2. Tambah Data Siswa\n"
         << "\n3. Hapus Data Siswa\n"
         << "\n4. Ubah Data Siswa\n"
         << "\n5. Pembayaran SPP\n"
         << "\n6. Bimbingan Konseling\n"
         << "\n7. Keluar\n"
         << endl;
}

void dataKelas()
{
    cout << "===============================" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << "\n"
             << i + 1 << ") " << kelasBawaan[i] << endl;
    }
    cout << endl;
}

void pencarianSiswa(int idSiswaYangDicari)
{
    for (int i = 0; i < 12; i++)
    {
        bantu = awalKelas[i];
        while (bantu != NULL)
        {
            if (bantu->identitasSiswa.IdSiswa == idSiswaYangDicari)
                break;
            bantu = bantu->next;
        }

        if (bantu != NULL && bantu->identitasSiswa.IdSiswa == idSiswaYangDicari)
            break;
    }
}

void tampilDataSiswa()
{
    cout << "Nama                  : " << bantu->identitasSiswa.nama << "\n"
         << "Kelas                 : " << kelasBawaan[bantu->identitasSiswa.kelas - 1] << "\n"
         << "ID Siswa              : " << bantu->identitasSiswa.IdSiswa << "\n"
         << "Tanggal Lahir         : " << bantu->identitasSiswa.tanggalLahir << "\n"
         << "Status Pembayaran SPP : " << ((bantu->identitasSiswa.lunasSPP) ? "Sudah Lunas" : "Belum Lunas") << "\n"
         << "Sisa Tunggakan        : " << bantu->identitasSiswa.sisaSPP << "\n"
         << "\n==========================================\n"
         << endl;
}

void dataSiswaDipilih()
{
    cout << "Data Siswa yang Dipilih" << endl;
    tampilDataSiswa();
}

void tampilkanSiswaTertentu(int id)
{
    pencarianSiswa(id);
    if (bantu == NULL)
    {
        cout << "Siswa yang Anda cari tidak ditemukan." << endl;
    }
    else
    {
        cout << "Data Siswa yang Dicari : " << endl;
        tampilDataSiswa();
    }
}

void listDataSiswa(struct dataSiswa *dataSiswaKelas)
{
    int numberList = 1;
    if (dataSiswaKelas == NULL)
    {
        cout << "Data siswa tidak tersedia." << endl;
    }
    else
    {
        bantu = dataSiswaKelas;
        while (bantu != NULL)
        {
            cout << "Absen : " << numberList++ << endl;
            tampilDataSiswa();
            bantu = bantu->next;
        }
    }
}

void subMenu1()
{
    system("cls");
    dataKelas();
    cout << "Pilih Kelas : ";
    cin >> tanyakelas;

    system("cls");
    cout << "Data Siswa Kelas " << kelasBawaan[tanyakelas - 1] << "\n"
         << "---------------------\n" << endl;
    switch (tanyakelas)
    {
    case 1:
        listDataSiswa(awalKelas[0]);
        break;
    case 2:
        listDataSiswa(awalKelas[1]);
        break;
    case 3:
        listDataSiswa(awalKelas[2]);
        break;
    case 4:
        listDataSiswa(awalKelas[3]);
        break;
    case 5:
        listDataSiswa(awalKelas[4]);
        break;
    case 6:
        listDataSiswa(awalKelas[5]);
        break;
    case 7:
        listDataSiswa(awalKelas[6]);
        break;
    case 8:
        listDataSiswa(awalKelas[7]);
        break;
    case 9:
        listDataSiswa(awalKelas[8]);
        break;
    case 10:
        listDataSiswa(awalKelas[9]);
        break;
    case 11:
        listDataSiswa(awalKelas[10]);
        break;
    case 12:
        listDataSiswa(awalKelas[11]);
        break;
    default:
        cout << "Input yang Anda masukkan salah." << endl;
    }
}

void menu1()
{
    system("cls");
    cout << "Tampilkan Data Siswa\n"
         << "=======================\n"
         << "\n1. Berdasarkan Kelas\n"
         << "\n2. Berdasarkan Pendaftaran Siswa yang Terbaru\n"
         << "\n3. Cari ID Siswa\n"
         << "\nPilih : ";
    cin >> pil;
    switch (pil)
    {
    case 1:
        subMenu1();
        break;
    case 2:
        system("cls");
        daftarSiswaTerbaru.tampilSiswaTerbaru();
        break;
    case 3:
        int idCari;
        cout << "\nInputkan ID Siswa yang Ingin Anda Lihat : ";
        cin >> idCari;

        if (cin.fail())
        {
            cout << "Input yang Anda masukkan salah." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            tampilkanSiswaTertentu(idCari);
        }
    }
}

void penempatanPosisiNodeBaru(struct dataSiswa *nodeBaru, int kelasSiswaIndex)
{
    bantu = awalKelas[kelasSiswaIndex - 1];
    if (bantu == NULL)
    {
        awalKelas[kelasSiswaIndex - 1] = nodeBaru;
        nodeBaru->next = NULL;
        nodeBaru->prev = NULL;
    }
    else if (bantu->next == NULL)
    {
        if (nodeBaru->identitasSiswa.nama < bantu->identitasSiswa.nama)
        {
            nodeBaru->next = bantu;
            bantu->prev = nodeBaru;
            awalKelas[kelasSiswaIndex - 1] = nodeBaru;
        }
        else
        {
            bantu->next = nodeBaru;
            nodeBaru->prev = bantu;
            nodeBaru->next = NULL;
            akhirKelas[kelasSiswaIndex - 1] = nodeBaru;
        }
    }
    else
    {
        while (bantu != NULL)
        {
            if (nodeBaru->identitasSiswa.nama < bantu->identitasSiswa.nama)
            {
                if (bantu == awalKelas[kelasSiswaIndex - 1])
                {
                    nodeBaru->next = bantu;
                    bantu->prev = nodeBaru;
                    awalKelas[kelasSiswaIndex - 1] = nodeBaru;
                }
                else
                {
                    nodeBaru->prev = bantu->prev;
                    nodeBaru->next = bantu;
                    bantu->prev->next = nodeBaru;
                    bantu->prev = nodeBaru;
                }
                break;
            }
            else if (bantu->next == NULL || nodeBaru->identitasSiswa.nama < bantu->next->identitasSiswa.nama)
            {
                nodeBaru->prev = bantu;
                nodeBaru->next = bantu->next;
                bantu->next = nodeBaru;
                if (nodeBaru->next != NULL)
                {
                    nodeBaru->next->prev = nodeBaru;
                }
                else
                {
                    akhirKelas[kelasSiswaIndex - 1] = nodeBaru;
                }
                break;
            }
            bantu = bantu->next;
        }
    }
}

void tambahSiswaFunction(bool insertPengguna, string namaSiswa = "", int kelasSiswa = 0, int IdSiswa = 0, string tanggalLahir = "", bool lunasSPP = true, int sisaSPP = 0)
{
    system("cls");
    dataSiswa *siswaBaru = new dataSiswa();

    if (insertPengguna)
    {
        cout << "Inputkan Data Siswa yang Ingin Ditambah\n"
             << "==========================================\n"
             << endl
             << "Nama          : ";
        cin.ignore();
        getline(cin, siswaBaru->identitasSiswa.nama);
        cout << "ID Siswa      : ";
        cin >> siswaBaru->identitasSiswa.IdSiswa;
        cout << "Tanggal Lahir : ";
        cin.ignore();
        getline(cin, siswaBaru->identitasSiswa.tanggalLahir);
        dataKelas();
        cout << "Masukkan di Kelas (1-12) : ";
        cin >> siswaBaru->identitasSiswa.kelas;
        cout << endl;

        penempatanPosisiNodeBaru(siswaBaru, siswaBaru->identitasSiswa.kelas);
        cout << "Siswa telah ditambahkan." << endl;
    }
    else
    {
        siswaBaru->identitasSiswa.nama = namaSiswa;
        siswaBaru->identitasSiswa.kelas = kelasSiswa;
        siswaBaru->identitasSiswa.IdSiswa = IdSiswa;
        siswaBaru->identitasSiswa.tanggalLahir = tanggalLahir;
        siswaBaru->identitasSiswa.lunasSPP = lunasSPP;
        siswaBaru->identitasSiswa.sisaSPP = sisaSPP;
        penempatanPosisiNodeBaru(siswaBaru, kelasSiswa);
    }
    daftarSiswaTerbaru.push(siswaBaru);
}

void penentuanPosisiHapusNode(int indexKelas)
{
    if (bantu->next == NULL && bantu->prev == NULL)
    {
        awalKelas[indexKelas - 1] = NULL;
        delete hapus;
    }
    else if (bantu == awalKelas[indexKelas - 1])
    {
        awalKelas[indexKelas - 1] = awalKelas[indexKelas - 1]->next;
        awalKelas[indexKelas - 1]->prev = NULL;
        delete hapus;
    }
    else if (bantu->next == NULL)
    {
        bantu->prev->next = NULL;
        delete hapus;
    }
    else
    {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
        delete hapus;
    }

    if (bantu->identitasSiswa.IdSiswa == daftarSiswaTerbaru.top->identitasSiswa.IdSiswa)
    {
        daftarSiswaTerbaru.pop();
    }
    else
    {
        while (daftarSiswaTerbaru.top->identitasSiswa.IdSiswa != bantu->identitasSiswa.IdSiswa)
        {
            temp.push(daftarSiswaTerbaru.top);
            daftarSiswaTerbaru.pop();
        }
        daftarSiswaTerbaru.pop();

        while (!temp.isEmpty())
        {
            daftarSiswaTerbaru.push(temp.top);
            temp.pop();
        }
    }
}

void hapusSiswa(bool insertPengguna, int kelasSiswaIndex = 0)
{
    if (insertPengguna)
    {
        system("cls");
        cout << "PILIH \n"
             << "1. ID Siswa\n"
             << "2. Siswa Terbaru\n"
             << "Hapus Siswa Berdasarkan : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            system("cls");
            dataKelas();
            cout << "Pilih Kelas : ";
            cin >> tanyakelas;
            cout << endl;

            if (awalKelas[tanyakelas - 1] == NULL)
            {
                cout << "Data siswa tidak tersedia." << endl;
            }
            else
            {
                int IdHapusSiswa;
                listDataSiswa(awalKelas[tanyakelas - 1]);
                cout << "Masukkan ID Siswa yang Ingin Dihapus : ";
                cin >> IdHapusSiswa;
                cout << endl;

                pencarianSiswa(IdHapusSiswa);

                if (bantu == NULL)
                {
                    cout << "Siswa dengan ID yang dimasukkan tidak ditemukan." << endl;
                }
                else
                {
                    dataSiswaDipilih();
                    char konfir;
                    cout << "Apakah Anda ingin menghapus data siswa tersebut? (Y/N) : ";
                    cin >> konfir;
                    if (konfir == 'Y' || konfir == 'y')
                    {
                        penentuanPosisiHapusNode(tanyakelas);
                        cout << "\nData siswa telah dihapus." << endl;
                    }
                    else if (konfir == 'N' || konfir == 'n')
                    {
                        cout << "\nData siswa batal dihapus." << endl;
                    }
                }
                cout << endl;
            }
            break;
        case 2:
            daftarSiswaTerbaru.tampilSiswaTerbaru();
            char konfir;
            cout << "Apakah Anda yakin ingin menghapus data siswa terbaru? (Y/N) : ";
            cin >> konfir;
            if (konfir == 'Y' || konfir == 'y')
            {
                bantu = awalKelas[daftarSiswaTerbaru.top->identitasSiswa.kelas - 1];
                while (bantu->identitasSiswa.IdSiswa != daftarSiswaTerbaru.top->identitasSiswa.IdSiswa)
                {
                    if (bantu->next == NULL)
                    {
                        bantu = NULL;
                        break;
                    }
                    else
                        bantu = bantu->next;
                }

                penentuanPosisiHapusNode(daftarSiswaTerbaru.top->identitasSiswa.kelas);
                cout << "\nData siswa telah dihapus." << endl;
            }
            else if (konfir == 'N' || konfir == 'n')
            {
                cout << "\nData siswa batal dihapus." << endl;
            }
            break;
        }
    }
    else
    {
        penentuanPosisiHapusNode(kelasSiswaIndex);
    }
}

void namaBaru ()
{
    cout << "Masukkan Nama Baru          : ";
    cin.ignore();
    getline(cin, bantu->identitasSiswa.nama);

    // Meng-update nama pada stack
    while (daftarSiswaTerbaru.top->identitasSiswa.IdSiswa != bantu->identitasSiswa.IdSiswa)
    {
        temp.push(daftarSiswaTerbaru.top);
        daftarSiswaTerbaru.pop();
    }

    daftarSiswaTerbaru.top->identitasSiswa.nama = bantu->identitasSiswa.nama;

    while (!temp.isEmpty())
    {
        daftarSiswaTerbaru.push(temp.top);
        temp.pop();
    }
}

void kelasBaru()
{
    if (bantu->identitasSiswa.kelas != tanyakelas)
    {
        // Hapus siswa dari kelas asal
        hapusSiswa(false, bantu->identitasSiswa.kelas);

        // Tambahkan siswa ke kelas baru
        tambahSiswaFunction(false, bantu->identitasSiswa.nama, bantu->identitasSiswa.kelas,
                                   bantu->identitasSiswa.IdSiswa, bantu->identitasSiswa.tanggalLahir,
                                   bantu->identitasSiswa.lunasSPP, bantu->identitasSiswa.sisaSPP);
    }
}

void bayarSPP()
{
    cout << "Pembayaran sudah lunas?\n"
         << "1. Iya\n"
         << "2. Tidak\n"
         << "Pilih : ";
    cin >> pil;

    switch (pil)
    {
    case 1:
        bantu->identitasSiswa.lunasSPP = true;
        bantu->identitasSiswa.sisaSPP = 0;
        break;
    case 2:
        bantu->identitasSiswa.lunasSPP = false;
        cout << "\nSisa Tunggakan yang Belum Dibayar : ";
        cin >> bantu->identitasSiswa.sisaSPP;
        break;
    }
}

void ubahDataSiswa()
{
    system("cls");
    dataKelas();
    cout << "Pilih Kelas : ";
    cin >> tanyakelas;
    cout << endl;

    if (awalKelas[tanyakelas - 1] == NULL)
    {
        cout << "Data siswa tidak tersedia." << endl;
    }
    else
    {
        int idUbahSiswa;
        listDataSiswa(awalKelas[tanyakelas - 1]);
        cout << "Masukkan ID Siswa yang Ingin Diubah: ";
        cin >> idUbahSiswa;
        cout << endl;

        pencarianSiswa(idUbahSiswa);

        if (bantu == NULL)
        {
            cout << "Siswa dengan ID yang dimasukkan tidak ditemukan." << endl;
        }
        else
        {
            system("cls");
            dataSiswaDipilih();
            cout << "Pilih Data yang Ingin Diubah\n"
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 << "\n1. Nama\n"
                 << "\n2. Kelas\n"
                 << "\n3. Tanggal Lahir\n"
                 << "\n4. Status Pembayaran\n"
                 << "\n5. Semua Data\n"
                 << endl;
            //int pil;
            cout << "Pilih Menu : ";
            cin >> pil;

            switch (pil)
            {
            case 1:
                system("cls");
                dataSiswaDipilih();
                namaBaru();
                cout << "\n================================\n";
                cout << "Nama berhasil diubah." << endl;
                break;
            case 2:
                system("cls");
                dataSiswaDipilih();
                dataKelas();
                cout << "Masukkan Kelas Baru         : ";
                cin >> bantu->identitasSiswa.kelas;
                cout << "\n================================\n";
                cout << "Kelas berhasil diubah." << endl;
                kelasBaru();
                break;
            case 3:
                system("cls");
                dataSiswaDipilih();
                cout << "Masukkan Tanggal Lahir Baru : ";
                cin.ignore();
                getline(cin, bantu->identitasSiswa.tanggalLahir);
                cout << "\n================================\n";
                cout << "Tanggal lahir berhasil diubah." << endl;
                break;
            case 4:
                system("cls");
                dataSiswaDipilih();
                bayarSPP();
                break;
            case 5:
                system("cls");
                dataSiswaDipilih();
                namaBaru();
                dataKelas();
                cout << "Masukkan Kelas Baru         : ";
                cin >> bantu->identitasSiswa.kelas;
                cout << "Masukkan Tanggal Lahir Baru : ";
                cin.ignore();
                getline(cin, bantu->identitasSiswa.tanggalLahir);
                bayarSPP();
                cout << "\n================================\n";
                cout << "\nSemua data siswa berhasil diubah." << endl;
                kelasBaru();
                break;
            default:
                cout << "\n================================\n";
                cout << "Input yang Anda masukkan salah." << endl;
                break;
            }
        }
    }
}

void pembayaranSPP()
{
    system("cls");
    dataKelas();
    cout << "Pilih Kelas : ";
    cin >> tanyakelas;
    cout << endl;

    // Menampilkan daftar siswa dalam kelas yang dipilih
    listDataSiswa(awalKelas[tanyakelas - 1]);

    // Meminta input ID Siswa untuk melakukan pembayaran SPP
    int idSiswa;
    cout << "Masukkan ID Siswa : ";
    cin >> idSiswa;

    // Mencari siswa dengan ID Siswa yang sesuai
    bantu = awalKelas[tanyakelas - 1];
    while (bantu != NULL)
    {
        if (bantu->identitasSiswa.IdSiswa == idSiswa)
        {
            // Memeriksa apakah siswa telah membayar SPP
            if (bantu->identitasSiswa.lunasSPP)
            {
                cout << "Siswa dengan ID Siswa " << idSiswa << " sudah melakukan pembayaran SPP." << endl;
            }
            else
            {
                // Meminta input jumlah pembayaran SPP
                int jumlahBayar;
                cout << "Masukkan Jumlah Pembayaran SPP : ";
                cin >> jumlahBayar;

                // Mengupdate status pembayaran dan sisa SPP
                bantu->identitasSiswa.sisaSPP -= jumlahBayar;
                if (bantu->identitasSiswa.sisaSPP == 0)
                    bantu->identitasSiswa.lunasSPP = true;

                cout << "Pembayaran SPP sebesar " << jumlahBayar << " berhasil dilakukan untuk siswa dengan ID Siswa "
                     << idSiswa << "." << endl;
            }
            break;
        }
        bantu = bantu->next;
    }

    // Jika ID Siswa tidak ditemukan
    if (bantu == NULL)
    {
        cout << "Siswa dengan ID Siswa " << idSiswa << " tidak ditemukan." << endl;
    }
}

void tampilAntrianBK()
{
    cout << "\nAntrian Bimbingan Konseling" << endl;
    int urutanAntrian = antrianBimbinganKonseling.front;
    while (urutanAntrian != antrianBimbinganKonseling.rear)
    {
        cout << urutanAntrian + 1 << ". " << antrianBimbinganKonseling.siswa[urutanAntrian++]->identitasSiswa.nama << endl
             << endl;
    }
}

void bimbinganKonseling()
{
    system("cls");
    int idSiswa;
    cout << "Bimbingan Konseling\n"
         << "======================\n"
         << "\n1. Tambah Antrian Bimbingan Konseling\n"
         << "\n2. Lihat Antrian Bimbingan Konseling\n"
         << "\n3. Hapus Antrian\n"
         << "\nPilih Menu : ";
    cin >> pil;

    switch (pil)
    {
    case 1:
        bantu = NULL;
        cout << "Masukkan ID Siswa yang ingin melakukan Bimbingan Konseling : ";
        cin >> idSiswa;

        pencarianSiswa(idSiswa);

        if (bantu != NULL)
        {
            dataSiswaDipilih();
            char konfir;
            cout << "Apakah ID siswa yang Anda inputkan sudah benar? (Y/N) : ";
            cin >> konfir;
            if (konfir == 'Y' || konfir == 'y')
            {
                cout << "Siswa telah ditambahkan ke antrian." << endl;
                enqueue(&antrianBimbinganKonseling, bantu);
            }
            else if (konfir == 'N' || konfir == 'n')
            {
                cout << "\nPenambahan antrian siswa tersebut dibatalkan." << endl;
            }
        }
        else
            cout << "Data siswa tidak ditemukan." << endl;

        break;
    case 2:
        if (isEmpty(&antrianBimbinganKonseling))
            cout << "Antrian masih kosong." << endl;
        else
        {
            tampilAntrianBK();
        }

        break;
    case 3:
        char konfir;
        if (isEmpty(&antrianBimbinganKonseling))
        {
            cout << "Antrian masih kosong." << endl;
        }
        else
        {
            tampilAntrianBK();

            cout << "Apakah Anda yakin ingin memanggil siswa selanjutnya? (Y/N) : ";
            cin >> konfir;
            if (konfir == 'Y' || konfir == 'y')
            {
                dequeue(&antrianBimbinganKonseling);
                cout << "Antrian telah diperbarui." << endl;
            }
            else if (konfir == 'N' || konfir == 'n')
            {
                cout << "\nPembaruan antrian dibatalkan." << endl;
            }
        }
    }
}

void menuUtama()
{
    char balikMenu;

    do
    {
        system("cls");
        tampilMenu();
        cout << "Pilih Menu : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            menu1();
            break;
        case 2:
            tambahSiswaFunction(true);
            break;
        case 3:
            hapusSiswa(true);
            break;
        case 4:
            ubahDataSiswa();
            break;
        case 5:
            pembayaranSPP();
            break;
        case 6:
            bimbinganKonseling();
            break;
        case 7:
            system("cls");
            cout << "\n\n\n\t\t\tTerima kasih telah menggunakan program ini. Sampai jumpa!\n\n\n";
            break;
        default:
            cout << "Input yang Anda masukkan salah." << endl;
            break;
        }

        while (balikMenu != 'N' || balikMenu != 'n')
        {
            cout << "Apakah Anda ingin kembali ke menu utama (Y/N) ? ";
            cin >> balikMenu;
            cin.clear();
            cin.ignore();
            if (balikMenu == 'N' || balikMenu == 'n')
            {
                pil = 7;
                system("cls");
                cout << "\n\n\n\t\t\tTerima kasih telah menggunakan program ini. Sampai jumpa!\n\n\n";
                break;
            }
            else if (balikMenu == 'Y' || balikMenu == 'y')
            {
                menuUtama();
                break;
            }
            else
            {
                cout << "Input yang Anda masukkan salah." << endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (pil != 7);
}

int main()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tambahSiswaFunction(false, namaSiswaBawaan[i][j], i + 1, nisnbawaan++, tanggalLahir[i][j]);
        }
    }

    menuUtama();
    system("pause");

    return 0;
}
