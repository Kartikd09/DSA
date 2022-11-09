#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

struct manufacture
{
    int date_man;
    int month_man;
    int year_man;
};

struct expiry
{
    int date_exp;
    int month_exp;
    int year_exp;
};

typedef struct Inventory
{
    struct Inventory *LMP;
    struct Inventory *RMP;
    string company_id;
    string parts_id;
    string parts_nam;
    manufacture manf;
    expiry expy;
}Node;

Node *Left_node = NULL;
Node *Right_node = NULL;

int year_input()
{
    int input_year;
    bool check_year = true;
    do
    {
        cout << "Year                          : ";
        cin >> input_year;
        if (input_year >= 1947 && input_year <= 2045)
        {
            check_year = false;
        }
        else
        {
            cout << "Error in year!! Re-enter" << endl;
            check_year = true;
        }

    } while (check_year);
    return input_year;
}

int month_input()
{
    int input_month;
    bool check_month = true;
    do
    {
        cout << "Month                        : ";
        cin >> input_month;
        if (input_month >= 1 && input_month <= 12)
        {
            check_month = false;
        }
        else
        {
            cout << "Error in month!! Re-enter" << endl;
            check_month = true;
        }

    } while (check_month);
    return input_month;
}

int date_input(int month, int year)
{
    int input_date;
    bool check_dateJoin = true;
    do
    {
        cout << "Date                          : ";
        cin >> input_date;

        if (month = 1 && month <= 12)
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {

                if (input_date >= 1 && input_date <= 31)
                {
                    check_dateJoin = false;
                }
                else
                {
                    cout << "Error in date!! Re-enter" << endl;
                    check_dateJoin = true;
                }
            }

            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {

                if (input_date >= 1 && input_date <= 30)
                {

                    check_dateJoin = false;
                }

                else
                {
                    cout << "Error in date!! Re-enter" << endl;
                    check_dateJoin = true;
                }
            }

            else if (month == 2)
            {

                if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
                {
                    if (input_date >= 1 && input_date <= 29)
                    {
                        check_dateJoin = false;
                    }
                    else
                    {
                        cout << "Error in date!! Re-enter" << endl;
                        check_dateJoin = true;
                    }
                }
                else
                {
                    if (input_date >= 1 && input_date <= 28)
                    {

                        check_dateJoin = false;
                    }
                    else
                    {
                        cout << "Error in date!! Re-enter" << endl;
                        check_dateJoin = true;
                    }
                }
            }
        }
    } while (check_dateJoin);
    return input_date;
}

void takeInput()
{
    Node *ptr = new Node();
    ptr->LMP = NULL;
    ptr->RMP = NULL;
    cout << "Enter the company id          : ";
    cin >> ptr->company_id;
    cin.ignore();

    cout << "Enter the part id             : ";
    getline(cin, ptr->parts_id);

    cout << "Enter the part name           : ";
    getline(cin, ptr->parts_nam);

    cout << "Enter Manufacture info :-" << endl;
    ptr->manf.year_man = year_input();
    ptr->manf.month_man = month_input();
    ptr->manf.date_man = date_input(ptr->manf.month_man, ptr->manf.year_man);

    cout << "Enter Expiry info :-" << endl;
    ptr->expy.year_exp = year_input();
    ptr->expy.month_exp = month_input();
    ptr->expy.date_exp = date_input(ptr->expy.month_exp, ptr->expy.year_exp);

    // ptr->LMP = NULL;
    // ptr->RMP = NULL;
    if (Left_node == NULL)
    {
        Left_node = ptr;
        // Right_node = ptr;
    }

    else
    {
        Node *temp = Left_node;
        while (temp->RMP != NULL)
        {
            temp = temp->RMP;
        }
        temp->RMP = ptr;
    }
}

void print_List()
{
    Node *temp = Left_node;
    if (temp == NULL)
    {
        cout << "List is empty!!" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << "Company id          : ";
        cout << temp->company_id << endl;

        cout << "Part id             : ";
        cout << temp->parts_id << endl;

        cout << "Part name           : ";
        cout << temp->parts_nam << endl;

        cout << "Manufacture Date    : ";
        cout << temp->manf.date_man << "/" << temp->manf.month_man << "/" << temp->manf.year_man << endl;

        cout << "Expiry Date         : ";
        cout << temp->expy.date_exp << "/" << temp->expy.month_exp << "/" << temp->expy.year_exp << endl;

        temp = temp->RMP;
    }
}

int main()
{
    bool flag = true;
    int i = 0;
    int choice;
    do
    {

        system("cls");
        cout << "\t\t\t\t\tINVENTORY MANAGEMENT SYSTEM" << endl;
        cout << "\t\t\t\t\t1) Add part to the inventory" << endl;
        cout << "\t\t\t\t\t2) Delete a part from the inventory" << endl;
        cout << "\t\t\t\t\t3) Count number of parts in the inventory" << endl;
        cout << "\t\t\t\t\t4) List of expired parts" << endl;
        cout << "\t\t\t\t\t5) Report" << endl;
        cout << "\t\t\t\t\t6) List all parts" << endl;
        cout << "\t\t\t\t\t7) Exit" << endl;
        cout << "\t\t\t\t\tYour choice :- ";
        cin >> choice;

        switch (choice)

        {
        case 1:
        {
            system("cls");
            cout << "\n-----------------------------------------------" << endl;
            cout << "\t    Enter Inventory Data: " << endl;
            cout << "\n-----------------------------------------------" << endl
                 << endl;

            takeInput();
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;

        case 2:
        {
            system("cls");
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;

        case 3:
        {
            system("cls");
            cout << "Press any key to go back to main menu" << endl;
            getch();
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;
        case 5:
        {
            system("cls");
            cout << "Press any key to go back to main menu" << endl;
            getch();
            break;
        }

        case 6:
        {
            system("cls");
            print_List();
            cout << "Press any key to go back to main menu" << endl;
            getch();
            break;
        }

        case 7:
        {
            flag = false;
        }
        }
    } while (flag);
}
