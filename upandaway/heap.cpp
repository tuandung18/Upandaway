#include <heap.h>
Heap::Heap(int a[], int size){
    data = new int[size + 1];
    for (int i = 0; i < size; i++)
        data[i+1] = a[i];
    pointer = size;
    for (int i = size/2; i>= 1; i--)
        heapify(i);
}
void Heap::heapify(int start){
    int new_start;
    if (2 * start > this->pointer)
        return;
    if ((2 * start + 1 <= this->pointer) and (data[2*start+1] > data[2*start]))
        new_start = 2 * start + 1;
    else
        new_start = 2 * start;
    if (data[start] < data[new_start]){
        int tmp = data[start];
        data[start] = data[new_start];
        data[new_start] = tmp;
        heapify(new_start);
    }
}
Heap::~Heap(){
    delete[] data;
}
int Heap::pop(){
    if (pointer < 1)
        throw ("Phuong Anh ist leer");
    int res = data[1];
    data[1] = data[pointer];
    pointer--;
    heapify(1);
    return res;
}
