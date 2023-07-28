#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa // Deklarasi struct mahasiswa dengan 2 field data : NPM dan Nama
{
    string NPM;
    string Nama;
};

struct Nilai // Deklarasi struct nilai dari mahasiswa dengan 6 field data : Absen, Tugas, UTS, UAS, NilaiAkhir, NilaiHuruf
{
    float Absen;
    float Tugas;
    float UTS;
    float UAS;
    float NilaiAkhir;
    char NilaiHuruf;
};

int main()
{
    Mahasiswa mahasiswa[20]; // Deklarasi variable mahasiswa dengan tipe data struct Mahasiswa yang sudah dideklarasikan sebelumnya

    Nilai nilai[20]; // Deklarasi variable nilai dengan tipe data nilai Mahasiswa yang sudah dideklarasikan sebelumnya

    int n = 0, pilih, index, semua;
    //  n : Representasi dari jumlah mahasiswa yang sudah ter-input
    // pilih : Untuk menampung jawaban dari pilihan menu dari user
    // index : Untuk menampung index dari mahasiswa yang cocok dengan data yang dicari (Untuk menu pencarian mahasiswa berdasarkan NPM)
    // semua : Untuk menampung jawaban dari pilihan user pada submenu dari menu 2
    string cariNPM;

    do
    {
        // Menampilkan menu utama
        cout << "Menu Program Nilai Mahasiswa" << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Tampil Data Mahasiswa" << endl;
        cout << "3. Edit Data Mahasiswa" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): "; // Meminta input pilihan menu utama
        cin >> pilih;

        switch (pilih) // Percabangan berdasarkan menu yang dipilih
        {
        case 1:
            cout << "Masukkan jumlah mahasiswa (maks 20): "; // Meminta inputan jumlah mahasiswa yang ingin diinputkan
            cin >> n;

            for (int i = 0; i < n; i++) // Perulangan yang terjadi sebanyak jumlah mahasiswa yang ingin diinputkan
            {
                // Proses meminta input data mahasiswa
                cout << "Data Mahasiswa ke-" << i + 1 << endl;
                cout << "NPM   : ";
                cin >> mahasiswa[i].NPM;
                cout << "Nama  : ";
                cin.ignore();
                getline(cin, mahasiswa[i].Nama);
                cout << "Nilai Absen : ";
                cin >> nilai[i].Absen;
                cout << "Nilai Tugas : ";
                cin >> nilai[i].Tugas;
                cout << "Nilai UTS   : ";
                cin >> nilai[i].UTS;
                cout << "Nilai UAS   : ";
                cin >> nilai[i].UAS;

                // Proses perhitungan nilai akhir
                nilai[i].NilaiAkhir = 0.1 * nilai[i].Absen + 0.2 * nilai[i].Tugas + 0.3 * nilai[i].UTS + 0.4 * nilai[i].UAS;

                // Percabangan untuk menentukan nilai huruf (mutu) berdasarkan jumlah nilai akhir
                if (nilai[i].NilaiAkhir > 80)
                {
                    nilai[i].NilaiHuruf = 'A';
                }
                else if (nilai[i].NilaiAkhir > 70)
                {
                    nilai[i].NilaiHuruf = 'B';
                }
                else if (nilai[i].NilaiAkhir > 60)
                {
                    nilai[i].NilaiHuruf = 'C';
                }
                else if (nilai[i].NilaiAkhir <= 60)
                {
                    nilai[i].NilaiHuruf = 'D';
                }
            }
            break;

        case 2:
            if (n == 0) // Percabangan agar user bisa kembali ke menu utama jika belum ada mahasiswa yang diinputkan
            {
                cout << "Belum ada data mahasiswa." << endl;
                break;
            }
            // Menampilkan sub menu dari menu 2
            cout << "1. Menampilkan data yang di pilih" << endl;
            cout << "2. Menampilkan semua data  " << endl;
            cin >> semua;  // Meminta input pilihan sub menu dari menu 2
            switch (semua) // Percabangan berdasarkan sub menu yang dipilih
            {
            case 1:                               // Program yang dijalankan jika sub menu 1 yang dipilih
                cout << "Masukan NPM Mahasiswa "; // Meminta input NPM dari mahasiswa yang ingin lihat datanya
                cin >> cariNPM;

                // Menampilkan data-data mahasiswa sesuai yang user inputkan sebelumnya
                cout << "Daftar Mahasiswa" << endl;
                for (int i = 0; i < n; i++)
                {
                    if (cariNPM == mahasiswa[i].NPM)
                    {
                        cout << "Data Mahasiswa ke-" << i + 1 << endl;
                        cout << "NPM   : " << mahasiswa[i].NPM << endl;
                        cout << "Nama  : " << mahasiswa[i].Nama << endl;
                        cout << "Nilai Absen : " << nilai[i].Absen << endl;
                        cout << "Nilai Tugas : " << nilai[i].Tugas << endl;
                        cout << "Nilai UTS   : " << nilai[i].UTS << endl;
                        cout << "Nilai UAS   : " << nilai[i].UAS << endl;
                        cout << "Nilai Akhir : " << nilai[i].NilaiAkhir << endl;
                        cout << "Nilai Huruf : " << nilai[i].NilaiHuruf << endl;
                    }
                }
                break;
            case 2: // Program yang dijalankan jika sub menu 1 yang dipilih
                cout << "Daftar Mahasiswa" << endl;

                for (int i = 0; i < n; i++) // Menampilkan data-data dari semua mahasiswa yang sudah diinputkan
                {
                    cout << "Data Mahasiswa ke-" << i + 1 << endl;
                    cout << "NPM   : " << mahasiswa[i].NPM << endl;
                    cout << "Nama  : " << mahasiswa[i].Nama << endl;
                    cout << "Nilai Absen : " << nilai[i].Absen << endl;
                    cout << "Nilai Tugas : " << nilai[i].Tugas << endl;
                    cout << "Nilai UTS   : " << nilai[i].UTS << endl;
                    cout << "Nilai UAS   : " << nilai[i].UAS << endl;
                    cout << "Nilai Akhir : " << nilai[i].NilaiAkhir << endl;
                    cout << "Nilai Huruf : " << nilai[i].NilaiHuruf << endl;
                }
                break;
            }
            break;
        case 3:
            cout << "Masukkan NPM mahasiswa yang ingin diubah: "; // Meminta input NPM dari mahasiswa yang ingin diubah datanya
            cin >> cariNPM;

            index = -1;
            for (int i = 0; i < n; i++) // Proses pencarian mahasiswa yang sesuai dengan NPM yang user input
            {
                if (mahasiswa[i].NPM == cariNPM)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1) // Jika value dari index masih bernilai -1, maka program akan menampilkan output ini
            {
                cout << "Data mahasiswa dengan NPM " << cariNPM << " tidak ditemukan." << endl;
            }
            else
            {
                // Menampilkan data awal dari mahasiswa yang user inputkan NPM nya
                cout << "Data Mahasiswa ke-" << index + 1 << endl;
                cout << "NPM   : " << mahasiswa[index].NPM << endl;
                cout << "Nama  : " << mahasiswa[index].Nama << endl;
                cout << "Nilai Absen : " << nilai[index].Absen << endl;
                cout << "Nilai Tugas : " << nilai[index].Tugas << endl;
                cout << "Nilai UTS   : " << nilai[index].UTS << endl;
                cout << "Nilai UAS   : " << nilai[index].UAS << endl;

                // Proses pengubahan data mahasiswa yang user inputkan NPM nya
                cout << "Masukkan nilai baru: " << endl;
                cout << "Nilai Absen : ";
                cin >> nilai[index].Absen;
                cout << "Nilai Tugas : ";
                cin >> nilai[index].Tugas;
                cout << "Nilai UTS   : ";
                cin >> nilai[index].UTS;
                cout << "Nilai UAS   : ";
                cin >> nilai[index].UAS;

                // Perhitungan nilai akhir mahasiswa
                nilai[index].NilaiAkhir = 0.1 * nilai[index].Absen + 0.2 * nilai[index].Tugas + 0.3 * nilai[index].UTS + 0.4 * nilai[index].UAS;

                // Percabangan untuk menentukan nilai huruf (mutu) berdasarkan jumlah nilai akhir
                if (nilai[index].NilaiAkhir > 80)
                {
                    nilai[index].NilaiHuruf = 'A';
                }
                else if (nilai[index].NilaiAkhir > 70)
                {
                    nilai[index].NilaiHuruf = 'B';
                }
                else if (nilai[index].NilaiAkhir > 60)
                {
                    nilai[index].NilaiHuruf = 'C';
                }
                else
                {
                    nilai[index].NilaiHuruf = 'D';
                }

                cout << "Data berhasil diubah." << endl;
            }
            break;

        case 4:
            // Meminta input NPM dari mahasiswa yang ingin dihapus
            cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
            cin >> cariNPM;

            index = -1;
            for (int i = 0; i < n; i++) // Proses pencarian mahasiswa yang sesuai dengan NPM yang user input
            {
                if (mahasiswa[i].NPM == cariNPM)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1) // Jika value dari index masih bernilai -1, maka program akan menampilkan output ini
            {
                cout << "Data mahasiswa dengan NPM " << cariNPM << " tidak ditemukan." << endl;
            }
            else
            {
                for (int i = index; i < n - 1; i++) // Proses mengganti data mahasiswa menjadi data mahasiswa setelahnya, dimulai dari mahasiswa setelah mahasiwa yang ingin dihapus hingga mahasiswa paling akhir
                {
                    mahasiswa[i] = mahasiswa[i + 1];
                    nilai[i] = nilai[i + 1];
                }

                // Pengurangan jumlah mahasiswa
                n--;

                cout << "Data berhasil dihapus";
            }
            break;

        default:
            cout << "Terima Kasih " << endl;
            break;
        }

    } while (pilih != 5);
    return 0;
}