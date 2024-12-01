#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

mutex mtx; //using mutex (to lock theards)
int counter = 0; 

// counter with mutex
void foo(int a) {   
    mtx.lock(); // lock entring new threads
    counter++;
    cout << "counter : " << counter << "  thread : " << a << endl;
    mtx.unlock(); // realse lock after thread finish to print
}

int main() {
    thread threads[20];

    for (int i = 0; i < 20; i++){
        threads[i] = thread(foo, i);
    }

    for (int i = 0; i < 20; i++){
        threads[i].join();
    }    
}