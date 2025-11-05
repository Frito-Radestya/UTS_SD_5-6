#include <iostream>
#include <vector>

using namespace std;

vector<int> rotasiKiri(int d, vector<int> arr_frito) {
    
    // ukuran array
    int n = arr_frito.size();

    // Menghitung rotasi efektif
    int rotasiEfektif = d % n;
    
    // Jika rotasi 0, kembalikan array aslinya
    if (rotasiEfektif == 0) {
        return arr_frito;
    }
    
    //Buat vector baru untuk menampung hasil rotasi
    vector<int> hasilRotasi;
    
    for (int i = rotasiEfektif; i < n; i++) {
        hasilRotasi.push_back(arr_frito[i]);
    }
    
    for (int i = 0; i < rotasiEfektif; i++) {
        hasilRotasi.push_back(arr_frito[i]);
    }
    
    return hasilRotasi;
}


int main() {
    int n, d;
    
    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;
    
    //vector 'arr_frito' dengan ukuran n
    vector<int> arr_frito(n);
   
    // Isi elemen array
    for (int i = 0; i < n; i++) {
        cin >> arr_frito[i];
    }
    
    // Memanggil fungsi rotasiKiri
    vector<int> hasil = rotasiKiri(d, arr_frito);
    
    // agar tidak ada spasi ekstra di akhir baris
    for (int i = 0; i < hasil.size(); i++) {
        cout << hasil[i]; // Cetak angkanya
        
        // Cek: Apakah ini bukan angka terakhir?
        if (i < hasil.size() - 1) {
            cout << " "; // Jika bukan, beri spasi
        }
    }
    cout << endl; 
    
    return 0;
}


// 1. Input jumlah elemen (n) dan jumlah rotasi (d)
// User memasukkan berapa banyak data yang akan dimasukkan ke dalam array dan berapa kali array ingin digeser ke kiri.

// 2. Membuat vector dengan ukuran n
// Program membuat sebuah vector bernama arr_frito yang akan menyimpan elemen-elemen yang diinput user.

// 3. Mengisi data array
// User mengisi n buah bilangan untuk disimpan ke dalam vector.

// 4. Menghitung rotasi efektif
// Rotasi dihitung dengan rumus d % n.
// Tujuannya:

// jika d lebih besar dari n, kita hanya butuh sisa pembagiannya.

// contoh: array ukuran 5 dan rotasi 7 → cukup rotasi 2 langkah.

// 5. Mengecek apakah rotasi tidak mengubah apa pun
// Jika rotasiEfektif = 0, array tidak berubah dan langsung dikembalikan.

// 7. Membuat vector hasil rotasi
// Vector baru dibuat untuk menampung susunan elemen yang sudah dirotasi.

// 8. Memindahkan bagian array mulai dari indeks rotasi
// Elemen yang letaknya setelah jumlah rotasi dipindah ke depan terlebih dahulu.

// Contoh: [1 2 3 4 5] rotasi 2 → mulai dari indeks 2 → [3 4 5]

// 9. Menambahkan elemen awal yang terpotong
// Setelah bagian belakang, program menambahkan elemen depan [1 2] ke belakang.

// 10. Sehingga hasil akhir: [3 4 5 1 2]

// 11. Mencetak hasil rotasi
// Program mencetak elemen secara berurutan dan memastikan tidak ada spasi ekstra di akhir.

// Program selesai
// Output sudah sesuai format dan berakhir dengan return 0.
