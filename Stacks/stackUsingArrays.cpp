#include <iostream>
using namespace std;

class Stack
{
    int *s;
    int top;
    int n;

public:
    Stack(int capacity)
    {
        n = capacity;
        s = new int[n];
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (top == n - 1)
        {
            cout << "Overflow! Stack is full.\n";
            return;
        }
        s[++top] = data;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Underflow! Stack is empty. \n";
        }
        else
        {
            return s[top--];
        }
        return s[top--];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        if (top == 0)
        {
            cout << "\n\n"
                 << s[top] << "\n\n";
        }
        else
        {
            cout << "\n\n"
                 << s[top] << "<-Top" << endl;
            for (int i = top - 1; i > 0; i--)
            {
                cout << s[i] << endl;
            }
            cout << "\n\n"
                 << s[0] << "<-Bottom" << endl;
        }
    }

    int topElement()
    {
        return s[top];
    }

    void clear()
    {
        top = -1;
    }

    ~Stack()
    {
        top = -1;
        delete[] s;
    }
};

int main()
{
    int capacity;
    cout << "Enter capacity of stack: ";
    cin >> capacity;
    cout << "\n";
    Stack A(capacity);
    int option;
    while (option != 6)
    {
        cout << "MENU\n";
        cout << "Select option\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
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
        option == 6 ? cout << "exit..." : cout << "continue...";
        cin.get();
        cout << "\n\n";
    }
    return 0;
}