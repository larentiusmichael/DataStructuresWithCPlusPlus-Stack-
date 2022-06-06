//Exercise 2: learn how to make an infix equation to postfix equation program using stack concept

#include <iostream>
using namespace std;

//structure of stack
struct stack
{
	char value;
	stack* nextAddress;
} *top;

//create newnode function
stack* createNewNode(char value)
{
	stack* newnode = new stack;
	newnode->value = value;
	newnode->nextAddress = NULL;
	return newnode;
}

//push function
void push(char value)
{
	stack* newnode = createNewNode(value);

	if (top == NULL)
	{
		top = newnode;
	}
	else
	{
		newnode->nextAddress = top;
		top = newnode;
	}
}

//pop function
void pop()
{
	if (top == NULL)
	{
		return;
	}

	stack* current = top;
	top = top->nextAddress;

	if (current->value == '(')
	{
		delete current;
	}
	else   //* - + / ^
	{
		cout << current->value;
		delete current;
	}
}

int main()
{
	top = NULL;

	string equation = "";

	cout << "Enter your infix equation here: ";
	cin >> equation;

	cout << endl;
	cout << "The conversion of your equation to postfix equation as below: " << endl;

	for (int i = 0; i < equation.length(); i++)
	{
		//situation 1: if meet the '('
		if (equation[i] == '(')
		{
			push(equation[i]);
		}
		//situation 2: if meet alphabet A-Z / a-z
		else if (((equation[i] >= 'A') && (equation[i] >= 'Z')) || ((equation[i] >= 'a') && (equation[i] >= 'z')))
		{
			cout << equation[i];
		}
		//situation 3: if meet / * ^ ->high priority than the - or +
		else if (equation[i] == '*' || equation[i] == '/' || equation[i] == '^')
		{
			if (top != NULL)
			{
				while ((top->value == '*' || top->value == '/' || top->value == '^'))	//equality or top value high than the push in value, pop first
				{
					pop();
					if (top == NULL)
					{
						break;
					}
				}
			}
			push(equation[i]); //stack empty / not empty, finally also need to push the operator to the stack
		}
		//situation 4: if meet + - -> lowest priority
		else if (equation[i] == '+' || equation[i] == '-')
		{
			if (top != NULL)
			{
				while ((top->value == '*' || top->value == '/' || top->value == '^' || top->value == '+' || top->value == '-'))	//equality or top value high than the push in value, pop first
				{
					pop();
					if (top == NULL)
					{
						break;
					}
				}
			}
			push(equation[i]);
		}
		//situation 5: if meet the ')', then pop everything until reach to the left parantheses
		else if (equation[i] == ')')
		{
			while (top != NULL && top->value != '(')
			{
				pop();
			}
			pop();
		}
	}

	//step 6: once finish reading the equation, make sure all the items should be remove from the stack
	while (top != NULL)
	{
		pop();
	}

	cout << endl << endl;

	return 0;
}