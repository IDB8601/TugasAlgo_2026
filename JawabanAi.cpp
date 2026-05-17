#include <iostream>  // Untuk cout dan endl
#include <queue>     // Untuk menggunakan struktur data queue
using namespace std;

// === CLASS MyStack ===
// Simulasi Stack (LIFO) menggunakan Queue (FIFO)
class MyStack {
private:
    queue<int> q; // Queue internal sebagai penyimpanan data

public:

    // --- PUSH ---
    // Menambahkan elemen baru ke stack
    // Trik: setelah push, elemen lama diputar ke belakang
    // sehingga elemen terbaru selalu ada di depan queue
    void push(int x) {
        q.push(x); // Masukkan elemen baru ke belakang queue

        int n = q.size(); //  simpan size dulu karena nanti akan berubah saat rotasi

        // Rotasi: pindahkan semua elemen lama ke belakang
        // supaya elemen terbaru (x) jadi paling depan
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front()); // Ambil elemen depan, taruh ke belakang
            q.pop();           // Hapus elemen depan yang sudah dipindah
        }
    }

    // --- POP ---
    // Menghapus dan mengembalikan elemen paling atas stack
    int pop() {
        int t = q.front(); // Ambil elemen paling depan (= paling atas stack)
        q.pop();           // Hapus dari queue
        return t;          // Kembalikan nilainya
    }

    // --- TOP ---
    // Melihat elemen paling atas stack tanpa menghapusnya
    int top() {
        return q.front(); // Elemen depan queue = elemen teratas stack
    }

    // --- EMPTY ---
    // Mengecek apakah stack kosong atau tidak
    bool empty() {
        return q.empty(); // Kembalikan true jika queue kosong
    }
};

// === MAIN ===
int main() {
    MyStack st; // Membuat objek stack

    cout << "=== Implement Stack using Queue ===" << endl;
    cout << endl;

    // --- Tes PUSH ---
    st.push(1);
    cout << "push(1) -> top: " << st.top() << endl;

    st.push(2);
    cout << "push(2) -> top: " << st.top() << endl;

    st.push(3);
    cout << "push(3) -> top: " << st.top() << endl;

    cout << endl;

    // --- Tes POP ---
    cout << "pop()   -> keluar: " << st.pop() << endl;
    cout << "top()   -> sekarang: " << st.top() << endl;

    cout << "pop()   -> keluar: " << st.pop() << endl;
    cout << "top()   -> sekarang: " << st.top() << endl;

    cout << "pop()   -> keluar: " << st.pop() << endl;

    // --- Cek EMPTY ---
    cout << "empty() -> " << (st.empty() ? "true (stack kosong)" : "false") << endl;

    return 0;
}