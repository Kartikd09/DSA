#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
using namespace std;

typedef struct BT
{
    string data;
    struct BT *leftChild;
    struct BT *rightChild;
} Node;

Node *root = NULL;

int check_Operator(char ch)
{
    if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
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

Node *Create(Node *root)
{
    Node *ptr = root;
    string val;
    cout << "Enter expression: " << endl;
    cin >> val;
    Node *temp = new Node();
    temp->data = val;

    if (ptr == NULL)
    {
        ptr = temp;
        ptr->leftChild = NULL;
        ptr->rightChild = NULL;
    }

    else
    {
        if (check_Operator(root->leftChild) == 1)
        {
            Node *trav = root;
            ptr = ptr->leftChild;

            if (Operator_precedence(input[i]) > Operator_precedence(ptr->data))
        }
        else
        {
            Node *trav = root;
            ptr = ptr->rightChild;
        }
    }
    return root;
}

void Preorder(Node *root)
{
}

int main()
{
    bool flag = true;
    Node *temp = NULL;
    int choice;
    do
    {
        system("cls");
        cout << "Main Menu:-" << endl
             << "1) Create a Binary Tree" << endl
             << "2) Pre-order traversal" << endl
             << "3) In-order traversal" << endl
             << "4) Post-order traversal" << endl
             << "5) Exit" << endl

             << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");

            temp = Create(root);
            cout << "press an key to continue " << endl;
            getch();
        }
        break;

        case 2:
        {
            Preorder(temp);
            cout << "press an key to continue " << endl;
            getch();
        }
        break;

        case 3:
        {
        }
        break;

        case 4:
        {
        }
        break;

        case 5:
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
