#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    int size;
    Queue()
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

    void enqueue(int ele)
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
        rear->next = NULL;
        size++;
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
            cout << "Element deleted is: " << front->data << ".\n";
            front = rear = NULL;
            size--;
            return;
        }

        cout << "Element deleted is: " << front->data << ".\n";
        front = front->next;
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
    Queue A;
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
