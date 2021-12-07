#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size = 0;

    LinkedList()
    {
        head = tail = NULL;
    }

    void addToHead(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void addToTail(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "\nElement can't be deleted from an empty list!\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        size--;
    }

    void deleteAtTail()
    {
        if (head == NULL)
        {
            cout << "\nElement can't be deleted from an empty list!\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        size--;
    }

    void insertAtPosition(int pos, int val)
    {
        if (pos < 1 || pos > size + 1)
        {
            cout << "Invalid index\n";
            return;
        }

        if (pos == 1)
        {
            addToHead(val);
            return;
        }

        if (pos == size + 1)
        {
            addToTail(val);
            return;
        }

        Node *traversingNode = head;
        for (int i = 1; i < pos - 1; i++)
        {
            traversingNode = traversingNode->next;
        }
        Node *temp = new Node(val);
        (traversingNode->next)->prev = temp;
        temp->next = traversingNode->next;
        traversingNode->next = temp;
        temp->prev = traversingNode;
        size++;
    }

    void removeAtPosition(int pos)
    {
        if (pos < 1 || pos > size)
        {
            cout << "Invalid index\n";
            return;
        }

        if (pos == 1)
        {
            deleteAtHead();
            return;
        }

        if (pos == size)
        {
            deleteAtTail();
            return;
        }

        Node *traversingNode = head;
        for (int i = 1; i < pos - 1; i++)
        {
            traversingNode = traversingNode->next;
        }
        Node *temp = traversingNode->next;
        traversingNode->next = temp->next;
        (temp->next)->prev = traversingNode;
        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
            return;
        }
        Node *traversingNode = head;
        cout << "Size: " << size << "\n";
        while (traversingNode->next != NULL)
        {
            cout << traversingNode->data << " <--> ";
            traversingNode = traversingNode->next;
        }
        cout << traversingNode->data;
        cout << "\n";
    }

    ~LinkedList()
    {
        Node *p = head;
        Node *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        head = tail = NULL;
    }
};

int main()
{
    LinkedList A;
    int option;
    while (option != 9)
    {
        cout << "MENU\n";
        cout << "Select option:\n";
        cout << "1. Add to head\n";
        cout << "2. Add to tail\n";
        cout << "3. Remove from head\n";
        cout << "4. Removefrom tail\n";
        cout << "5. Insert\n";
        cout << "6. Remove\n";
        cout << "7. Display\n";
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            int x;
            cout << "Enter an integer value: ";
            cin >> x;
            A.addToHead(x);
        }
        break;

        case 2:
        {
            int x;
            cout << "Enter an integer value: ";
            cin >> x;
            A.addToTail(x);
        }
        break;

        case 3:
        {
            A.deleteAtHead();
            break;
        }
        case 4:
        {
            A.deleteAtTail();
            break;
        }
        case 5:
        {
            int pos, value;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter an integer value: ";
            cin >> value;
            A.insertAtPosition(pos, value);
            break;
        }

        case 6:
        {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            A.removeAtPosition(pos);
            break;
        }

        case 7:
        {
            A.display();
            break;
        }

        case 8:
            break;
        default:
            std::cout << "Incorrect option\n";
        }
        cin.get();
        cout << "\n";
    }
    return 0;
}