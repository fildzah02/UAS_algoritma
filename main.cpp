#include <iostream>

using namespace std;

int main()
{
#include <stdio.h>
#include <string.h>

#define MAX_MHS 30

// Fungsi Rekursif Faktorial
long long faktorial(int n) {
    if (n <= 1) return 1;
    return n * faktorial(n - 1);
}

// Fungsi Rekursif Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    char nim[MAX_MHS][20];
    float nilai[MAX_MHS][3]; // Kolom: 0=Tugas, 1=UTS, 2=UAS
    int jumlah = 0;
    int pilihan;

    printf("--- Input Awal Data Mahasiswa ---\n");
    printf("Masukkan jumlah mahasiswa (maks %d): ", MAX_MHS);
    scanf("%d", &jumlah);

    for (int i = 0; i < jumlah; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("NIM: "); scanf("%s", nim[i]);
        printf("Nilai Tugas: "); scanf("%f", &nilai[i][0]);
        printf("Nilai UTS: "); scanf("%f", &nilai[i][1]);
        printf("Nilai UAS: "); scanf("%f", &nilai[i][2]);
    }

    do {
        printf("\n=== MENU PROGRAM ===\n");
        printf("1. Tampilkan Seluruh Data\n");
        printf("2. Tambah Data Mahasiswa\n");
        printf("3. Ubah Nilai Mahasiswa\n");
        printf("4. Hapus Data Mahasiswa\n");
        printf("5. Hitung & Tampilkan Pengolahan Nilai\n");
        printf("6. Fitur Rekursif\n");
        printf("7. Keluar\n");
        printf("Pilihan: "); scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: // Menampilkan Data
                printf("\n%-15s | %-7s | %-7s | %-7s\n", "NIM", "Tugas", "UTS", "UAS");
                for (int i = 0; i < jumlah; i++) {
                    printf("%-15s | %-7.2f | %-7.2f | %-7.2f\n", nim[i], nilai[i][0], nilai[i][1], nilai[i][2]);
                }
                break;

            case 2: // Tambah Data
                if (jumlah < MAX_MHS) {
                    printf("NIM baru: "); scanf("%s", nim[jumlah]);
                    printf("Tugas: "); scanf("%f", &nilai[jumlah][0]);
                    printf("UTS: "); scanf("%f", &nilai[jumlah][1]);
                    printf("UAS: "); scanf("%f", &nilai[jumlah][2]);
                    jumlah++;
                } else {
                    printf("Kapasitas penuh!\n");
                }
                break;

            case 3: { // Ubah Data
                char cariNIM[20];
                printf("Masukkan NIM yang akan diubah: "); scanf("%s", cariNIM);
                for (int i = 0; i < jumlah; i++) {
                    if (strcmp(nim[i], cariNIM) == 0) {
                        printf("Nilai Tugas Baru: "); scanf("%f", &nilai[i][0]);
                        printf("Nilai UTS Baru: "); scanf("%f", &nilai[i][1]);
                        printf("Nilai UAS Baru: "); scanf("%f", &nilai[i][2]);
                        break;
                    }
                }
                break;
            }

            case 4: { // Hapus Data
                char hapusNIM[20];
                printf("Masukkan NIM yang akan dihapus: "); scanf("%s", hapusNIM);
                for (int i = 0; i < jumlah; i++) {
                    if (strcmp(nim[i], hapusNIM) == 0) {
                        for (int j = i; j < jumlah - 1; j++) {
                            strcpy(nim[j], nim[j+1]);
                            nilai[j][0] = nilai[j+1][0];
                            nilai[j][1] = nilai[j+1][1];
                            nilai[j][2] = nilai[j+1][2];
                        }
                        jumlah--;
                        printf("Data dihapus.\n");
                        break;
                    }
                }
                break;
            }

            case 5: { // Pengolahan Nilai
                float totalTugas=0, totalUTS=0, totalUAS=0;
                int idxMax = 0, idxMin = 0;
                float rerataMhs[MAX_MHS];

                for (int i = 0; i < jumlah; i++) {
                    rerataMhs[i] = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
                    totalTugas += nilai[i][0];
                    totalUTS += nilai[i][1];
                    totalUAS += nilai[i][2];
                    if (rerataMhs[i] > rerataMhs[idxMax]) idxMax = i;
                    if (rerataMhs[i] < rerataMhs[idxMin]) idxMin = i;
                }
                printf("\nRata-rata Kelas - Tugas: %.2f, UTS: %.2f, UAS: %.2f\n", totalTugas/jumlah, totalUTS/jumlah, totalUAS/jumlah);
                printf("Rata-rata Tertinggi: %s (%.2f)\n", nim[idxMax], rerataMhs[idxMax]);
                printf("Rata-rata Terendah: %s (%.2f)\n", nim[idxMin], rerataMhs[idxMin]);
                break;
            }

            case 6: // Rekursif
                printf("Faktorial dari %d: %lld\n", jumlah, faktorial(jumlah));
                printf("Deret Fibonacci (%d): ", jumlah);
                for (int i = 0; i < jumlah; i++) printf("%d ", fibonacci(i));
                printf("\n");
                break;
        }
    } while (pilihan != 7);


    return 0;
}
