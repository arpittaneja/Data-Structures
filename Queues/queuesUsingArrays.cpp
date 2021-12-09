#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *q;
    int size;
    Queue(int capacity)
    {
        front = rear = -1;
        q = new int[capacity];
        size = capacity;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int ele)
    {
        if (isEmpty())
        {
            rear++;
            front++;
            q[rear] = ele;
            return;
        }

        else if (rear == size - 1)
        {
            cout << "Queue is full.\n";
            return;
        }
        q[++rear] = ele;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue from an empty queue.\n";
            return;
        }

        else if (front == rear)
        {
            cout << "Element deleted is: " << q[front] << ".\n";
            front = rear = -1;
            return;
        }
        cout << "Element deleted is: " << q[front] << ".\n";
        front++;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << q[i] << "  ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int capacity;
    cout << "Enter capacity of queue: ";
    cin >> capacity;
    cout << "\n";
    Queue A(capacity);
    int option;
    while (option != 4)
    {
        cout << "MENU\n";
        cout << "Select option\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. End\n";
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {

        case 1:
        {
            int x;
            cout << "Enter an integer value: ";
            cin >> x;
            A.enqueue(x);
            break;
        }

        case 2:
        {
            A.dequeue();
            break;
        }
        case 3:
        {
            A.display();
            break;
        }
        case 4:
        {
            break;
        }

        default:
            cout << "Incorrect option\n";
        }
        cin.get();
        cout << "Press Enter to ";
        option == 4 ? cout << "exit..." : cout << "continue...";
        cin.get();
        cout << "\n\n";
    }
    return 0;
}