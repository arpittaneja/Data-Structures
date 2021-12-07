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

class Stack
{
public:
    Node *top;
    int size;

    Stack()
    {
        top = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
    void push(int val)
    {
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Sack is empty!\n";
            return;
        }
        Node *traversingNode = top;
        while (traversingNode->next != NULL)
        {
            cout << traversingNode->data << "\n";
            traversingNode = traversingNode->next;
        }
        cout << traversingNode->data << "\n";
    }

    int topElement()
    {
        return top->data;
    }

    void clear()
    {
        Node *traversingNode = top;
        Node *temp = NULL;
        while (traversingNode->next != NULL)
        {
            temp = traversingNode->next;
            delete traversingNode;
            traversingNode = temp;
        }
        top = NULL;
    }
    
    ~Stack()
    {
        Node *p = top;
        Node *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        top = NULL;
    }
};

int main()
{
    Stack A;
    int option;
    while (option != 6)
    {
        cout << "MENU\n";
        cout << "Select option\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Clear\n";
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
            A.push(x);
            break;
        }

        case 2:
        {
            A.pop();
            break;
        }
        case 3:
        {
            cout << "Top Element: " << A.topElement() << "\n";
            break;
        }
        case 4:
        {
            A.display();
            break;
        }
        case 5:
        {
            A.clear();
            break;
        }
        case 6:
            break;
        default:
            cout << "Incorrect option\n";
        }
        cin.get();
        cout << "Press Enter to ";
        option == 6 ? std::cout << "exit..." : std::cout << "continue...";
        cin.get();
        cout << "\n";
    }
    return 0;
}