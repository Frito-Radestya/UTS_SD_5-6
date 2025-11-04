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
