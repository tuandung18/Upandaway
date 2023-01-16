#ifndef HEAP_H
#define HEAP_H


class Heap {
public:
Heap(int a[], int size);
~Heap();
int pop();
private:
void heapify(int start);
int* data;
int pointer;
};
#endif // HEAP_H
