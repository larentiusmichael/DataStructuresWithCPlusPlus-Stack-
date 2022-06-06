#include <iostream>
using namespace std;

//create static array for stack - array with cols 100 spaces
string stack[100];
int n = 100;
int top = -1;       //top is the index number indicate which is the top

bool isEmpty()  //check whether the list is empty? - underflow?
{
    if (top <= -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(string value) {   //tp01, tp02, tp03
    if (top >= n - 1)   //last index for 100 cols is 99
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }

}

void pop() {
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
        return;
    }
    cout << "The popped element is " << stack[top] << endl;
    stack[top] = "";
    top--;
}

void displayitemsInStack()  //reverse printing in the array so that you can get the top to the bottom items
{
    if (isEmpty())
    {
        cout << "Stack is empty and no item should be displayed!" << endl;
        return;
    }
    cout << "Stack elements are: ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void peek() //to read the top item in the stack without remove anything
{
    if (top >= 0)
    {
        cout << "The current top value is " << stack[top] << endl;
    }
}

int main()
{
    push("TP01");
    displayitemsInStack();
    cout << endl;

    push("TP02");
    displayitemsInStack();
    cout << endl;

    push("TP03");
    displayitemsInStack();
    cout << endl;

    pop();
    displayitemsInStack();
    cout << endl;

    peek();
    displayitemsInStack();
    cout << endl;

    pop();
    displayitemsInStack();
    cout << endl;

    push("TP04");
    displayitemsInStack();
    cout << endl;

    push("TP05");
    displayitemsInStack();
    cout << endl;

    push("TP03");
    displayitemsInStack();
    cout << endl;

    pop();
    displayitemsInStack();
    cout << endl;

    push("TP02");
    displayitemsInStack();
    cout << endl;

    displayitemsInStack();
    return 0;
}