#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int front;
    int rear;
    int *q;
    int size;

    CircularQueue(int capacity)
    {
        front = -1;
        rear = -1;
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

    bool isFull()
    {
        if (((rear + 1) % size == front))
        {
            return true;
        }
        return false;
    }

    void enqueue(int ele)
    {
        if (isFull())
        {
            cout << "Queue is full.\n";
            return;
        }

        if (!isFull())
        {
            if (isEmpty())
            {
                front = rear = 0;
                q[rear] = ele;
                return;
            }

            if (rear == size - 1)
            {
                rear = 0;
                q[rear] = ele;
                return;
            }

            rear++;
            q[rear] = ele;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue from empty queue.\n";
            return;
        }

        if (front == rear)
        {
            cout << "The element dequeued is " << q[front] << "\n";
            front = rear = -1;
            return;
        }

        if (front == size - 1)
        {
            cout << "The element dequeued is " << q[front] << "\n";
            front = 0;
            return;
        }

        cout << "The element dequeued is " << q[front] << "\n";
        front++;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << q[i] << "  ";
            }
            cout << "\n\n";
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << q[i] << "  ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << q[i] << "  ";
            }
            cout << "\n\n";
        }
    }
};

int main()
{
    int capacity;
    cout << "Enter capacity of queue: ";
    cin >> capacity;
    cout << "\n";
    CircularQueue A(capacity);
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