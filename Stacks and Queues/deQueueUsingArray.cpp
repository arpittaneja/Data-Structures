#include <iostream>
using namespace std;

class DEQueue
{
public:
    int *q;
    int front;
    int rear;
    int size;

    DEQueue(int capacity)
    {
        q = new int[capacity];
        front = rear = -1;
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
        if (rear + front == size - 1)
        {
            return true;
        }
        return false;
    }
    void enqueueFromFront(int ele)
    {
        if (isEmpty())
        {
            front = rear = 0;
            q[front] = ele;
            return;
        }

        if (isFull())
        {
            cout << "Cannot enqueue to an empty queue.\n";
            return;
        }

        if (front == 0)
        {
            cout << "Cannot perform enqueue operation as there is no space at the start of queue.\n";
            return;
        }
        front--;
        q[front] = ele;
    }

    void enqueueFromRear(int ele)
    {
        if (isEmpty())
        {
            front = rear = 0;
            q[front] = ele;
            return;
        }

        if (isFull())
        {
            cout << "Cannot enqueue to an empty queue.\n";
            return;
        }

        if (rear == size - 1)
        {
            cout << "Cannot perform enqueue operation as there is no space at the end of queue.\n";
            return;
        }

        rear++;
        q[rear] = ele;
    }

    void dequeueFromFront()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue from an empty queue.\n";
            return;
        }

        if (rear == front)
        {
            cout << "The dequeued element is " << q[front] << ".\n";
            return;
        }

        front++;
        cout << "The dequeued element is " << q[front] << ".\n";
    }

    void dequeueFromRear()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue from an empty queue.\n";
            return;
        }

        if (rear == front)
        {
            cout << "The dequeued element is " << q[front] << ".\n";
            return;
        }

        rear--;
        cout << "The dequeued element is " << q[rear] << ".\n";
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
    DEQueue A(capacity);
    int option;
    while (option != 6)
    {
        cout << "MENU\n";
        cout << "Select option\n";
        cout << "1. Enqueue From Front\n";
        cout << "2. Enqueue From Rear\n";
        cout << "3. Dequeue From Front\n";
        cout << "4. Dequeue From Rear\n";
        cout << "5. Display\n";
        cout << "6. End\n";
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {

        case 1:
        {
            int x;
            cout << "Enter an integer value: ";
            cin >> x;
            A.enqueueFromFront(x);
            break;
        }

        case 2:
        {
            int x;
            cout << "Enter an integer value: ";
            cin >> x;
            A.enqueueFromRear(x);
            break;
        }
        case 3:
        {
            A.dequeueFromFront();
            break;
        }
        case 4:
        {
            A.dequeueFromRear();
            break;
        }

        case 5:
        {
            A.display();
            break;
        }
        case 6:
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