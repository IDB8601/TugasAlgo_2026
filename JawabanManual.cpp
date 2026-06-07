#include <iostream>   
#include <queue>      
using namespace std;  


queue<int> q;


void push_manual(int x) {
    int s = q.size();     

    q.push(x);             
    
    for (int i = 0; i < s; i++) {
        q.push(q.front()); 
        q.pop();           
    }
}


void pop_manual() {
    if (!q.empty()) {                        
        cout << "Menghapus: " << q.front() << endl; 
        q.pop();                               
    } else {
        cout << "Stack kosong!" << endl;      
    }
}


int top_manual() {
    if (!q.empty()) {        
        return q.front();    
    } else {
        cout << "Stack kosong!" << endl; 
        return -1;            
    }
}


bool empty_manual() {
    return q.empty();        
}


int main() {
    
    push_manual(10); 
    push_manual(20); 
    push_manual(30); 

    cout << "Top awal: " << top_manual() << endl; 

    
    pop_manual(); 
    cout << "Top sekarang: " << top_manual() << endl; 

   
    pop_manual(); 
    cout << "Top sekarang: " << top_manual() << endl; 
    
    if (!empty_manual()) { 
        cout << "Stack belum kosong, masih ada: " << top_manual() << endl; 
    } else {
        cout << "Stack kosong" << endl; 
    }

    return 0; 
}
