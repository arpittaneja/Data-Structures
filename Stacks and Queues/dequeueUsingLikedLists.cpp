#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class DEQueue
{
public:
    Node *front;
    Node *rear;
    int size;

    DEQueue()
    {
        front = rear = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        return false;
    }

    void enqueueFromFront(int ele)
    {
        Node *temp = new Node(ele);

        if (isEmpty())
        {
            front = rear = temp;
            size++;
            return;
        }

        temp->next = front;
        front = temp;
        size++;
    }

    void enqueueFromRear(int ele)
    {
        Node *temp = new Node(ele);

        if (isEmpty())
        {
            front = rear = temp;
            size++;
            return;
        }

        rear->next = temp;
        rear = temp;
        size++;
    }

    void dequeueFromFront()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue from an empty queue.\n";
            return;
        }

        if (front == rear)
        {
            cout << "Dequeued element is " << front->data << ".\n";
            front = rear = NULL;
            size--;
            return;
        }
        Node *temp = front;
        cout << "Dequeued element is " << front->data << ".\n";
        front = front->next;
        delete temp;
        size--;
    }

    void dequeueFromRear()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue from an empty queue.\n";
            return;
        }
        if (front == rear)
        {
            cout << "Dequeued element is " << rear->data << ".\n";
            front = rear = NULL;
            size--;
            return;
        }

        Node *traversingNode = front;
        while (traversingNode->next != rear)
        {
            traversingNode = traversingNode->next;
        }
        rear = traversingNode;
        traversingNode = traversingNode->next;
        delete traversingNode;
        size--;
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
            Node *traversingNode = front;
            while (traversingNode != NULL)
            {
                cout << traversingNode->data << "  ";
                traversingNode = traversingNode->next;
            }
            cout << "\n";
        }
    }
};

int main()
{
    cout << "\n";
    DEQueue A;
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
}