#include <iostream>
#include <cstring>
#include <cmath>
#include <windows.h>
#include <conio.h>
using namespace std;

typedef struct BT
{
    char data;
    struct BT *leftChild;
    struct BT *rightChild;
} Node;

struct stack
{
    char info;
    struct stack *next;
};

struct eval
{
    double data;
    struct eval *nxt;
};

struct TreeStack
{
    Node *treeNode;
    struct TreeStack *next;
};

stack *TOS = NULL;
TreeStack *Tree_TOS = NULL;
Node *root = NULL;
eval *top = NULL;

string takeInput();
string conv_ToPostfix(string);
void pushTree(Node *);
Node *popTree();
int check_Operator(char);
int Operator_precedence(char);
Node *Create(string);
void PreOrder(Node *);
void PostOrder(Node *);
void InOrder(Node *);
void printTree(Node *, int);

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

void evaluation(string input)
{
    cout << input << endl;
    string temp_eval;
    temp_eval = conv_ToPostfix(input);
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

int main()
{
    bool flag = true;
    Node *temp = NULL;
    int choice;
input_again:
    string input = takeInput();
    do
    {
        system("cls");
        cout << "Main Menu:-" << endl;
        cout << "1) Create a Binary Tree" << endl;
        cout << "2) Pre-order traversal" << endl;
        cout << "3) In-order traversal" << endl;
        cout << "4) Post-order traversal" << endl;
        cout << "5) Compute value " << endl;
        cout << "6) Enter new expression " << endl;
        cout << "7) Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {

            system("cls");
            root = Create(input);
            printTree(root, 20);
            cout << "press an key to continue " << endl;
            getch();
        }
        break;

        case 2:
        {
            PreOrder(root);
            cout << "press an key to continue " << endl;
            getch();
        }
        break;

        case 3:
        {
            InOrder(root);
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

        case 4:
        {
            PostOrder(root);
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

        case 5:
        {
            evaluation(input);
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

        case 6:
        {
            goto input_again;
        }

        case 7:
        {
            flag = false;
        }
        break;

        default:
            break;
        }
    } while (flag);
    return 0;
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

int check_Operator(char ch)
{
    if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    // if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    //     return 1;
    else
        return 0;
}

int Operator_precedence(char ch)
{

    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else
        return 0;
}

void push(char operand)
{
    stack *ptr = new stack();
    ptr->info = operand;
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

void pushTree(Node *item)
{
    TreeStack *ptr = new TreeStack();
    ptr->treeNode = item;
    if (Tree_TOS == NULL)
    {
        ptr->next = NULL;
        Tree_TOS = ptr;
    }
    else
    {
        ptr->next = Tree_TOS;
        Tree_TOS = ptr;
    }
}

Node *popTree()
{
    Node *element;
    if (Tree_TOS == NULL)
    {
        cout << "Stack is Empty" << endl;
        return NULL;
    }

    else if (Tree_TOS->next == NULL)
    {
        element = Tree_TOS->treeNode;
        Tree_TOS = NULL;
    }

    else
    {
        element = Tree_TOS->treeNode;
        Tree_TOS = Tree_TOS->next;
    }
    return element;
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
            while (TOS->info != '(' && TOS->next != NULL)
            {

                postfix = postfix + TOS->info;
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

                if (Operator_precedence(input[i]) > Operator_precedence(TOS->info))
                {
                    push(input[i]);
                }
                else
                {
                    while (TOS != NULL && Operator_precedence(input[i]) <= Operator_precedence(TOS->info))
                    {
                        postfix = postfix + TOS->info;
                        pop();
                    }
                    push(input[i]);
                }
            }
        }
    }

    while (TOS != NULL)
    {
        postfix = postfix + TOS->info;
        pop();
    }

    return postfix;
}

Node *Create(string inp)
{
    // string input = takeInput();
    string postfix = conv_ToPostfix(inp);
    cout << "Postfix expresssion is : " << postfix << endl;
    for (int i = 0; i < postfix.length(); i++)
    {
        Node *temp = new Node();
        temp->data = postfix[i];
        if (check_Operator(postfix[i]) == 0)
        {
            pushTree(temp);
        }
        else
        {
            temp->rightChild = popTree();
            temp->leftChild = popTree();
            pushTree(temp);
        }
        root = temp;
    }
    return root;
}

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    cout << root->data << endl;
}

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << endl;
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
}

void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->leftChild);
    cout << root->data << endl;
    InOrder(root->rightChild);
}

void printTree(Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 10;

    printTree(root->rightChild, space);
    cout << endl;
    for (int i = 10; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << "\n";
    printTree(root->leftChild, space);
}
