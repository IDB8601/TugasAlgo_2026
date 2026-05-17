#include <iostream>
#include <queue>
using namespace std;

// Queue sebagai stack
queue<int> q;

// PUSH (tambah data)
void push_manual(int x) {
    int s = q.size();
    q.push(x);

    // rotasi biar data terakhir jadi paling depan
    for (int i = 0; i < s; i++) {
        q.push(q.front());
        q.pop();
    }
}

// POP (hapus data atas)
void pop_manual() {
    if (!q.empty()) {
        cout << "Menghapus: " << q.front() << endl;
        q.pop();
    } else {
        cout << "Stack kosong!" << endl;
    }
}

// TOP (lihat data atas)
int top_manual() {
    if (!q.empty()) {
        return q.front();
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

// EMPTY (cek kosong)
bool empty_manual() {
    return q.empty();
}

// MAIN
int main() {
    // PUSH DATA
    push_manual(10);
    push_manual(20);
    push_manual(30);

    cout << "Top awal: " << top_manual() << endl; // 30

    // POP 1
    pop_manual(); // hapus 30
    cout << "Top sekarang: " << top_manual() << endl; // 20

    // POP 2
    pop_manual(); // hapus 20
    cout << "Top sekarang: " << top_manual() << endl; // 10

    // CEK APAKAH MASIH ADA
    if (!empty_manual()) {
        cout << "Stack belum kosong, masih ada: " << top_manual() << endl;
    } else {
        cout << "Stack kosong" << endl;
    }

    return 0;
}