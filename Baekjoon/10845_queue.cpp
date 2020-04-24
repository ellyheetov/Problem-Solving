//
// Created by 박혜원 on 2020/03/14.
//
#include <iostream>
#include <string>
using namespace std;

class Queue { //First In First Out
public:
    int front, rear;
    int capacity;
    int *queue;

    ~Queue() {
        delete[]queue;
    }

    Queue() {
        front = rear = 0;
        capacity = 8;
        queue = new int[capacity];
    }

    bool is_empty() { //큐가 비어있는 지를 검사
        return front == rear;
    }
    bool is_full(){ //큐가 가득찼는지를 검사
        return rear +1 == capacity;
    }

    void enqeueue(int item) {
        if (is_full()) {
            int *temp = new int[capacity*2];
            for (int index = 0; index < capacity; ++index) {
                temp[index] = queue[index];
            }
            delete []queue;
            capacity = capacity *2;
            queue = temp;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
    }

    int dequeue(){ //큐의 앞에있는 요소를 반환한 다음 삭제한다.
        front = (front + 1) % capacity;
        return queue[front];
    }
    int peek(){ //큐에서 삭제하지 않고 앞에있는 요소를 반환한다.
        return queue[(front+1)%capacity];
    }
    int size() {
        if(rear > front)
            return rear - front;
        else
            return capacity - (front - rear);
    }
};

int main() {
    Queue que;
    que.enqeueue(1);
    que.enqeueue(2);
    que.enqeueue(3);
    que.enqeueue(4);
    que.enqeueue(5);
    que.enqeueue(6);
    que.enqeueue(7);
    que.enqeueue(8);
    que.enqeueue(9);
    que.enqeueue(10);
    que.dequeue();
    que.dequeue();
    que.dequeue();
    cout << que.size();
}
