#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk menyimpan data pasien
struct Node {
    string nama;
    Node* next;
};

// Pointer head = pasien paling depan, tail = pasien paling belakang
Node* head = NULL;
Node* tail = NULL;

// Tambah pasien normal (di belakang antrian)
void tambahNormal(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    if (head == NULL) { // jika antrian kosong
        head = tail = baru;
    } else { // tambahkan di belakang
        tail->next = baru;
        tail = baru;
    }
}

// Tambah pasien darurat (langsung di depan)
void tambahDarurat(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = head;
    head = baru;

    if (tail == NULL) tail = baru; // jika antrian masih kosong
}

// Layani pasien (hapus dari depan)
void layani() {
    if (head != NULL) {
        cout << head->nama << endl; // tampilkan pasien yang dilayani
        Node* temp = head;
        head = head->next;
        delete temp; // hapus dari memori

        if (head == NULL) tail = NULL; // antrian kosong lagi
    }
}

int main() {
    int N;
    cin >> N; // jumlah perintah

    for (int i = 0; i < N; i++) {
        string cmd, nama;
        cin >> cmd;

        if (cmd == "DATANG") {
            cin >> nama;
            tambahNormal(nama);
        }
        else if (cmd == "DARURAT") {
            cin >> nama;
            tambahDarurat(nama);
        }
        else if (cmd == "LAYANI") {
            layani();
        }
    }

    return 0;
}


// 1. Program menggunakan struktur data linked list berarah
//    untuk menyimpan nama pasien dalam bentuk Node bertingkat.

// 2. Pointer head menunjukkan pasien terdepan dalam antrian,
//    sedangkan pointer tail menunjukkan pasien paling belakang.

// 3. Jika perintah "DATANG <nama>" diberikan:
//    → Buat node baru dengan nama pasien
//    → Tambahkan node tersebut di belakang antrian (setelah tail)
//    → Jika antrian kosong, head dan tail menjadi node baru

// 4. Jika perintah "DARURAT <nama>" diberikan:
//    → Buat node baru
//    → Node ini langsung ditempatkan di depan (sebagai head baru)
//    → Prioritas lebih tinggi dibanding pasien normal
//    → Cocok untuk kasus pasien gawat darurat

// 5. Jika perintah "LAYANI":
//    → Cetak nama pasien paling depan (head)
//    → Hapus node tersebut (dequeue depan)
//    → Pindahkan head ke node berikutnya
//    → Jika setelah dihapus antrian kosong, tail = NULL

// 6. Program membaca jumlah perintah N di awal,
//    kemudian memprosesnya satu per satu hingga selesai.

// 7. Operasi-operasi yang dilakukan:
//    • Enqueue belakang (normal)
//    • Enqueue depan (prioritas)
//    • Dequeue depan (layani pasien)
//    Semua dilakukan menggunakan manipulasi pointer.

// 8. Dengan memakai linked list:
//    → Tambah depan = O(1)
//    → Tambah belakang = O(1)
//    → Hapus depan = O(1)
//    Sangat efisien untuk model antrian seperti ini.

// 9. Program berakhir setelah semua perintah dieksekusi,
//    dan output hanya berupa nama pasien yang telah dilayani.
