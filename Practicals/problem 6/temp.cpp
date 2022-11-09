#include <iostream>
#include <string>
using namespace std;

typedef struct tree
{
    struct tree *LT;
    char data;
    struct tree *RT;
} TREE;

typedef struct stack
{
    char item;
    struct stack *next;
} STACK;

typedef struct treeStack
{
    TREE *node;
    struct treeStack *next;
} STACK_TREE;

STACK *TOS = NULL;
STACK_TREE *TOS_TREE = NULL;

// Function
void PreOrder(TREE *);
void InOrder(TREE *);
void PostOrder(TREE *);
void compute();
void choice();
int priority(char);
string postfix(string);
void printTree(TREE *, int);

// Stack For Polish Notations
void push(char);
char pop();

// Stack For Tree Creation
void pushTree(TREE *);
TREE *popTree();

TREE *createTree(string);

int main()
{
    choice();
    return 0;
}

void choice()
{
    int exittrig = 1;
    int length;
    char choice;
    string expression;

    while (exittrig)
    {
        cout << "Enter Any Expression: ";
        getline(cin >> ws, expression);
        TREE *BT = createTree(expression);
        cout << endl
             << "Postfix Form: " << postfix(expression);
        printTree(BT, 20);

        cout << endl;
        cout << "Select a traversal Method" << endl
             << endl;
        cout << "1 -> Pre-Order Traversal" << endl;
        cout << "2 -> In-order traversal" << endl;
        cout << "3 -> Post order traversal" << endl;
        cout << "4 -> Compute the value of teh ex[ression" << endl;
        cout << "5 -> Exit" << endl;

        cout << "\nEnter your choice: " << endl
             << "-> ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            // PostOrder(BT);
            break;

        case '2':
            // InOrder();

            break;

        case '3':
            // PreOrder();

            break;

        case '4':
            // compute();

            break;

        case '5':
            exittrig = 0;
            break;

        default:
            break;
        }
    }
}

TREE *createTree(string exp)
{
    string postExp = postfix(exp);

    TREE *BT = NULL;

    for (int i = 0; i < postExp.length(); i++)
    {
        TREE *newNode = new TREE();
        newNode->data = postExp[i];

        if (isalnum(postExp[i]))
        {
            pushTree(newNode);
            cout << "Pushed: " << postExp[i] << endl;
        }

        else
        {
            newNode->RT = popTree();
            newNode->LT = popTree();
            pushTree(newNode);
        }
        BT = newNode;
    }
    return BT;
}

string postfix(string exp)
{
    string postfix = "";

    for (int i = 0; i < exp.length(); i++)
    {
        if (isalnum(exp[i]))
        {
            postfix = postfix + exp[i];
        }

        else if (exp[i] == '(')
        {
            push(exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (TOS->next != NULL && TOS->item != '(')
            {
                postfix += TOS->item;
                pop();
            }
            pop();
        }

        else
        {
            if (TOS == NULL)
            {
                push(exp[i]);
            }

            else
            {
                if (priority(exp[i]) > priority(TOS->item))
                {
                    push(exp[i]);
                }

                else
                {
                    while (TOS != NULL && priority(exp[i]) <= priority(TOS->item))
                    {
                        postfix = postfix + TOS->item;
                        pop();
                    }
                    push(exp[i]);
                }
            }
        }
    }

    while (TOS != NULL)
    {
        postfix = postfix + TOS->item;
        pop();
    }

    return postfix;
}

void push(char element)
{

    STACK *newItem = new STACK();
    newItem->item = element;

    if (TOS == NULL)
    {
        newItem->next = NULL;
        TOS = newItem;
    }

    else
    {
        newItem->next = TOS;
        TOS = newItem;
    }
}

char pop()
{
    char popped;
    if (TOS == NULL)
    {
        cout << "Stack Underflow" << endl;
        return '0';
    }

    else if (TOS->next == NULL)
    {
        popped = TOS->item;
        TOS = NULL;
    }
    else
    {
        popped = TOS->item;
        TOS = TOS->next;
    }
    return popped;
}

int priority(char c)
{

    if (c == '^')
    {
        return 3;
    }

    else if (c == '/' || c == '*')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printTree(TREE *r, int space)
{
    if (r == NULL)
    {
        return;
    }
    space += 10;

    printTree(r->RT, space);
    cout << endl;
    for (int i = 10; i < space; i++)
    {
        cout << " ";
    }
    cout << r->data << "\n";
    printTree(r->LT, space);
}

void pushTree(TREE *item)
{
    STACK_TREE *newItem = new STACK_TREE();
    newItem->node = item;

    if (TOS_TREE == NULL)
    {
        newItem->next = NULL;
        TOS_TREE = newItem;
    }

    else
    {
        newItem->next = TOS_TREE;
        TOS_TREE = newItem;
    }
}

TREE *popTree()
{
    TREE *popped;
    if (TOS_TREE == NULL)
    {
        cout << "Stack Underflow" << endl;
        return NULL;
    }

    else if (TOS_TREE->next == NULL)
    {
        popped = TOS_TREE->node;
        TOS_TREE = NULL;
    }
    else
    {
        popped = TOS_TREE->node;
        TOS_TREE = TOS_TREE->next;
    }
    return popped;
}

void PostOrder(TREE *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->LT);
}