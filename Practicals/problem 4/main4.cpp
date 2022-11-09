#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
using namespace std;

typedef struct stack
{
    char data;
    struct stack *next;
} Node;

struct eval
{
    double data;
    struct eval *nxt;
};

Node *TOS = NULL;

eval *top = NULL;

int isEmpty()
{
    if (TOS == NULL)
    {
        return 1;
    }
    return 0;
}

void push(char oper)
{
    Node *ptr = new Node();
    ptr->data = oper;
    if (TOS == NULL)
    {
        ptr->next = NULL;
        TOS = ptr;
    }
    else
    {

        ptr->next = TOS;
        TOS = ptr;
    }
}

void push_eval(int calculation)
{
    eval *ptr1 = new eval();
    ptr1->data = calculation;
    if (top == NULL)
    {
        ptr1->nxt = NULL;
        top = ptr1;
    }
    else
    {

        ptr1->nxt = top;
        top = ptr1;
    }
}

void pop()
{

    if (TOS == NULL)
    {
        cout << "Stack is Empty" << endl;
    }

    else if (TOS->next == NULL)
    {
        TOS = NULL;
    }

    else
    {

        TOS = TOS->next;
    }
}

double pop_eval()
{

    double value = top->data;
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }

    else if (top->nxt == NULL)
    {
        top = NULL;
    }

    else
    {

        top = top->nxt;
    }
    return value;
}

string takeInput()
{
    string input;
    cout << "Enter the expression : ";
    getline(cin >> ws, input);
    int length = input.length();

    // for (int i = 0; i < length; i++)
    // cout << "Your input after removing extra whitespaces : " << input << endl;
    cout << "Total characters : " << length << endl;
    // cout << length << endl;
    // conv_ToPostfix(input, length);
    return input;
}

int Operator_precedence(char ch)
{
    // if (ch == '(' || ch == ')')
    //     return 4;

    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else
        return 0;
}

int check_Operator(char ch)
{
    if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

string conv_ToPostfix(string input)
{
    string postfix = "";
    int i = 0;
    for (int i = 0; i < input.length(); i++)
    {

        if (check_Operator(input[i]) == 0)
        {
            postfix = postfix + input[i];
        }

        else if (input[i] == '(')
        {
            push(input[i]);
        }

        else if (input[i] == ')')
        {
            while (TOS->data != '(' && TOS->next != NULL)
            {

                postfix = postfix + TOS->data;
                pop();
            }
            pop();
        }

        else
        {
            if (TOS == NULL)
            {

                push(input[i]);
            }

            else
            {

                if (Operator_precedence(input[i]) > Operator_precedence(TOS->data))
                {
                    push(input[i]);
                }
                else
                {
                    while (TOS != NULL && Operator_precedence(input[i]) <= Operator_precedence(TOS->data))
                    {
                        postfix = postfix + TOS->data;
                        pop();
                    }
                    push(input[i]);
                }
            }
        }
    }

    while (TOS != NULL)
    {
        postfix = postfix + TOS->data;
        pop();
    }

    return postfix;
}

string reverse(string input)
{
    int length;
    length = input.length();

    int temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = input[i];
        input[i] = input[length - i - 1];
        input[length - i - 1] = temp;
    }

    for (int j = 0; j < length; j++)
    {
        if (input[j] == '(')
        {
            input[j] = ')';
        }
        else if (input[j] == ')')
        {
            input[j] = '(';
        }
    }

    return input;
}

string conv_ToPrefix(string input)
{
    string reversed = reverse(input);
    // cout << "After reversal : " << reversed << endl;

    string result = conv_ToPostfix(reversed);

    string prefix = reverse(result);
    return prefix;
}

void evaluation(string input)
{
    string temp_eval;
    temp_eval = conv_ToPostfix(input);
    cout << temp_eval << endl;
    for (int i = 0; i < temp_eval.length(); i++)
    {
        if (check_Operator(temp_eval[i]) == 0)
        {
            int val;
            cout << "Enter a value for " << temp_eval[i] << " : ";
            cin >> val;
            push_eval(val);
        }

        else
        {
            double a = pop_eval();
            double b = pop_eval();
 
            switch (temp_eval[i])
            {
            case '+':
            {
                push_eval(a + b);
                break;
            }
            case '-':
            {
                push_eval(b - a);
                break;
            }
            case '*':
            {
                push_eval(a * b);
                break;
            }
            case '/':
            {
                push_eval(b / a);
                break;
            }
            case '^':
            {
                push_eval(pow(b, a));
                break;
            }
            }
        }
    }

    int result = pop_eval();
    cout << "Computed Result is: " << result << endl;
}

void print(string input)
{
    cout << "The expression is : "
         << input << endl;
}

int main()
{
    bool flag = true;
    int choice;
input_again:
    string input = takeInput();
    do
    {

        // system("cls");
        cout << "\t\t\t\t\tProgram to implement Polish Notations :- " << endl;
        cout << "\t\t\t\t\t1)Input an expression" << endl;
        cout << "\t\t\t\t\t2)Postfix of an expression" << endl;
        cout << "\t\t\t\t\t3)Prefix of an expression" << endl;
        cout << "\t\t\t\t\t4)Output of expression" << endl;
        cout << "\t\t\t\t\t5)Print the expression" << endl;
        cout << "\t\t\t\t\t6)Exit" << endl;
        cout << "\t\t\t\t\tYour choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // system("cls");

            goto input_again;
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

        case 2:
        {
            // system("cls");
            string postfix = conv_ToPostfix(input);
            cout << "The postfix is : " << postfix << endl;
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

        case 3:
        {
            // system("cls");
            string prefix = conv_ToPrefix(input);
            cout << "The prefix is : " << prefix << endl;
            cout << "Press any key to continue" << endl;
            getch();
            break;
        }

        case 4:
        {
            // system("cls");
            evaluation(input);

            cout << "Press any key to continue" << endl;
            getch();
            break;
        }

        case 5:
        {
            print(input);
            cout << "Press any key to continue" << endl;
            getch();
            break;
        }

        case 6:
        {
            flag = false;
        }
        }
    } while (flag);
    return 0;
}
