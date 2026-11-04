#include <stdio.h>
#include <string.h>

void inputData(FILE *fp) {
    char nama[50], nim[20];
    float ipk;

    printf("Nama : ");
    scanf(" %[^\n]", nama);
    printf("NIM  : ");
    scanf("%s", nim);
    printf("IPK  : ");
    scanf("%f", &ipk);

    fprintf(fp, "Nama: %s\n", nama);
    fprintf(fp, "NIM : %s\n", nim);
    fprintf(fp, "IPK : %.2f\n", ipk);
    fprintf(fp, "---------------\n");
}

void buatFile() {
    int jumlah;
    FILE *fp = fopen("mahasiswa.txt", "w");

    if (fp == NULL) {
        printf("Gagal membuat file!\n");
        return;
    }

    printf("Jumlah mahasiswa yang akan diinput: ");
    scanf("%d", &jumlah);

    for (int i = 0; i < jumlah; i++) {
        printf("\nData mahasiswa ke-%d\n", i + 1);
        inputData(fp);
    }

    fclose(fp);
    printf("File mahasiswa.txt berhasil dibuat.\n");
}

void tampilFile() {
    char baris[100];
    FILE *fp = fopen("mahasiswa.txt", "r");

    if (fp == NULL) {
        printf("File belum ada. Buat file terlebih dahulu.\n");
        return;
    }

    printf("\n=== ISI FILE mahasiswa.txt ===\n");
    while (fgets(baris, sizeof(baris), fp) != NULL) {
        printf("%s", baris);
    }

    fclose(fp);
}

void tambahData() {
    FILE *fp = fopen("mahasiswa.txt", "a");

    if (fp == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    printf("\nTambah data mahasiswa baru\n");
    inputData(fp);

    fclose(fp);
    printf("Data berhasil ditambahkan.\n");
}

void hitungMahasiswa() {
    char baris[100];
    int jumlah = 0;
    FILE *fp = fopen("mahasiswa.txt", "r");

    if (fp == NULL) {
        printf("File belum ada. Buat file terlebih dahulu.\n");
        return;
    }

    while (fgets(baris, sizeof(baris), fp) != NULL) {
        if (strncmp(baris, "Nama:", 5) == 0) {
            jumlah++;
        }
    }

    fclose(fp);
    printf("Jumlah mahasiswa: %d\n", jumlah);
}

int main() {
    int pilihan;

    do {
        printf("\n=== DATA MAHASISWA ===\n");
        printf("1. Buat file awal\n");
        printf("2. Tampilkan isi file\n");
        printf("3. Tambah data baru\n");
        printf("4. Hitung jumlah mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            buatFile();
        } else if (pilihan == 2) {
            tampilFile();
        } else if (pilihan == 3) {
            tambahData();
        } else if (pilihan == 4) {
            hitungMahasiswa();
        } else if (pilihan != 5) {
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 5);

    printf("Program selesai.\n");
    return 0;
}