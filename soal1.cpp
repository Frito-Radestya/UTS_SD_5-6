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
