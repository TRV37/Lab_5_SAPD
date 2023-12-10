#include <iostream>
#include <vector>

class Queue 
{
    std::vector<int> data;
    int head = 0;
    int tail = 0;
    int size = 0;

public:
    Queue(int size) : data(size) {}

    void print() 
    {
        for (int i = head; i != tail; i = (i + 1) % data.size()) 
            std::cout << data[i] << ' ';
        
        std::cout << '\n';
    }

    void enqueue(int value) 
    {
        if (size == data.size()) 
            throw std::runtime_error("Queue is full");
        
        data[tail] = value;
        tail = (tail + 1) % data.size();
        size++;
        print();
    }

    void dequeue() 
    {
        if (size == 0) 
            throw std::runtime_error("Queue is empty");
        
        head = (head + 1) % data.size();
        size--;
        print();
    }

    void insertAfterKey(int key, int value) 
    {
        auto it = std::find(data.begin(), data.end(), key);
        if (it != data.end()) 
        {
            data.insert(it + 1, value);
            tail++;
            size++;
            print();
        }
    }

    void deleteMiddle() 
    {
        if (size == 0) 
            throw std::runtime_error("Queue is empty");
        
        int middle = size / 2;
        data.erase(data.begin() + middle);
        tail--;
        size--;
        print();
    }
};

int main() {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.insertAfterKey(2, 4); // Вставка после ключа

    q.deleteMiddle(); // Удаление из середины

    return 0;
}
