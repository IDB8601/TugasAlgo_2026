#include <iostream>   // untuk input-output (cout, endl)
#include <queue>      // untuk menggunakan struktur data queue
using namespace std;  // supaya tidak perlu tulis std:: lagi

// Queue global yang akan dipakai sebagai stack
queue<int> q;

// PUSH (menambahkan data ke stack)
void push_manual(int x) {
    int s = q.size();      // simpan jumlah elemen yang sudah ada di queue

    q.push(x);             // masukkan elemen baru ke belakang queue

    // rotasi: memindahkan elemen lama ke belakang
    // supaya elemen baru berada di depan (jadi seperti stack)
    for (int i = 0; i < s; i++) {
        q.push(q.front()); // ambil elemen depan, lalu masukkan ke belakang
        q.pop();           // hapus elemen depan yang tadi dipindahkan
    }
}

// POP (menghapus elemen paling atas dari stack)
void pop_manual() {
    if (!q.empty()) {                          // cek apakah queue tidak kosong
        cout << "Menghapus: " << q.front() << endl; // tampilkan elemen teratas
        q.pop();                               // hapus elemen depan (top stack)
    } else {
        cout << "Stack kosong!" << endl;       // kalau kosong, tampilkan pesan
    }
}

// TOP (melihat elemen paling atas tanpa menghapus)
int top_manual() {
    if (!q.empty()) {        // cek apakah queue tidak kosong
        return q.front();    // kembalikan elemen depan (top stack)
    } else {
        cout << "Stack kosong!" << endl; // pesan jika kosong
        return -1;            // nilai default jika kosong
    }
}

// EMPTY (mengecek apakah stack kosong)
bool empty_manual() {
    return q.empty();        // true jika kosong, false jika tidak
}

// MAIN (program utama)
int main() {
    // memasukkan data ke dalam stack
    push_manual(10); // stack: [10]
    push_manual(20); // stack: [20, 10]
    push_manual(30); // stack: [30, 20, 10]

    cout << "Top awal: " << top_manual() << endl; // tampilkan top (30)

    // POP pertama
    pop_manual(); // menghapus 30
    cout << "Top sekarang: " << top_manual() << endl; // sekarang 20

    // POP kedua
    pop_manual(); // menghapus 20
    cout << "Top sekarang: " << top_manual() << endl; // sekarang 10

    // cek apakah stack masih ada isinya
    if (!empty_manual()) { // jika tidak kosong
        cout << "Stack belum kosong, masih ada: " << top_manual() << endl; // tampilkan sisa
    } else {
        cout << "Stack kosong" << endl; // jika kosong
    }

    return 0; // program selesai
}