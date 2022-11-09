#include <iostream>
#include <fstream>
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
} Node;

struct Backup
{
    char Comp_Id[10];   // Company ID
    char Part_Id[10];   // Part ID
    char part_name[50]; // Parts Name
    manufacture DOM;    // Date of Manufacture
    expiry DOE;         // Date of Expiry
};

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
        cout << "Month                         : ";
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

bool check_key(string company, string part)
{
    Node *temp = Left_node;
    if (temp == NULL)
    {
        return false;
    }
    while (temp != NULL)
    {
        if (company == temp->company_id && part == temp->parts_id)
        {
            return true;
        }
        temp = temp->RMP;
    }
    return false;
}

void takeInput()
{
    Node *ptr = new Node();
    ptr->LMP = NULL;
    ptr->RMP = NULL;
    bool check = true;
    do
    {
        cout << "Enter the company id          : ";
        cin >> ptr->company_id;
        cin.ignore();

        cout << "Enter the part id             : ";
        getline(cin, ptr->parts_id);

        check = check_key(ptr->company_id, ptr->parts_id);
        if (check == true)
        {
            cout << "Error!! Enter Unique Company Id and Part ID" << endl;
        }
        else
            check = false;

    } while (check);

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
        Right_node = ptr;
    }
    else
    {
        Node *temp = Left_node;
        Node *prev;
        while (temp->RMP != NULL)
        {
            prev = temp;
            temp = temp->RMP;
        }
        temp->RMP = ptr;
        ptr->LMP = temp;
        Right_node = ptr;
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
        cout << endl
             << endl;
    }
}

int count_item()
{
    int count = 0;
    Node *trav = Left_node;
    while (trav != NULL)
    {
        count++;
        trav = trav->RMP;
    }
    return count;
}

// Node *Search(string j, string k)
// {
//     Node *ptr = Left_node;
//     if (ptr == NULL)
//     {
//         cout << "Inventory is Empty!!" << endl;
//         return ptr;
//     }

//     while (ptr != NULL)
//     {
//         if (ptr->company_id == j && ptr->parts_id == k)
//         {
//             return ptr;
//         }
//         ptr = ptr->RMP;
//     }
//     return NULL;
// }

void Insert(Node *prt)
{
    Node *NewData = new Node;
    NewData = prt;
    Node *ptr = Right_node;
    if (!Right_node)
    {
        NewData->LMP = NULL;
        NewData->RMP = NULL;
        Left_node = NewData;
        Right_node = NewData;
        return;
    }
    ptr->RMP = NewData;
    ptr->RMP->LMP = ptr;
    Right_node = NewData;
}

void delete_item(string c, string p)
{
    Node *temp = Left_node;
    Node *prev = temp;
    ;
    if (temp == NULL)
    {
        cout << "List is empty!!" << endl;
        return;
    }

    while (temp != NULL)
    {
        if (temp->company_id == c && temp->parts_id == p)
        {
            if (Left_node == Right_node) // single node in list
            {
                Left_node = NULL;
                Right_node = NULL;
                return;
            }

            if (temp->LMP == NULL) // left most node
            {
                Left_node = temp->RMP;
                Left_node->LMP = NULL;
                delete temp;
                return;
            }

            if (temp->RMP == NULL) // right most node
            {
                Right_node = temp->LMP;
                Right_node->RMP = NULL;
                delete temp;
                return;
            }
            // desired node
            temp->LMP->RMP = temp->RMP;
            temp->RMP->LMP = temp->LMP;
            delete temp;
            return;
        }
        else
        {
            prev = temp;
            temp = temp->RMP;
        }
    }
    cout << "No record found!!" << endl;
    return;
}

void print_rep(Node *ptr)
{
    cout << "Company id          : ";
    cout << ptr->company_id << endl;

    cout << "Part id             : ";
    cout << ptr->parts_id << endl;

    cout << "Part name           : ";
    cout << ptr->parts_nam << endl;

    cout << "Manufacture Date    : ";
    cout << ptr->manf.date_man << "/" << ptr->manf.month_man << "/" << ptr->manf.year_man << endl;

    cout << "Expiry Date         : ";
    cout << ptr->expy.date_exp << "/" << ptr->expy.month_exp << "/" << ptr->expy.year_exp << endl;

    ptr = ptr->RMP;
    cout << endl
         << endl;
}

Node *check_expiry()
{
    Node *ptr = Left_node;
    int year_check = year_input();
    int month_check = month_input();
    int date_check = date_input(month_check, year_check);

    if (ptr->RMP == NULL)
    {
        cout << "List is empty" << endl;
        return ptr;
    }

    do
    {
        if (year_check >= ptr->expy.year_exp)
        {
            if (month_check >= ptr->expy.month_exp)
            {
                if (date_check >= ptr->expy.date_exp)
                {
                    print_rep(ptr);
                    break;
                }
                else
                {
                    ptr = ptr->RMP;
                }
                break;
            }
            else
            {
                ptr = ptr->RMP;
            }
            break;
        }
        else
        {
            ptr = ptr->RMP;
        }

    } while (ptr->RMP == NULL);
    cout << "No such part found" << endl;
}

void print(Node *ptr1)
{
    cout << "Company id          : ";
    cout << ptr1->company_id << endl;

    cout << "Part id             : ";
    cout << ptr1->parts_id << endl;

    cout << "Part name           : ";
    cout << ptr1->parts_nam << endl;

    cout << "Manufacture Date    : ";
    cout << ptr1->manf.date_man << "/" << ptr1->manf.month_man << "/" << ptr1->manf.year_man << endl;

    cout << "Expiry Date         : ";
    cout << ptr1->expy.date_exp << "/" << ptr1->expy.month_exp << "/" << ptr1->expy.year_exp << endl;
}

void report()
{
    // int choice;
    bool check = true;
    // cin >> choice;
    // cin.ignore();
    do
    {
        system("cls");
        cout << "Report :-" << endl;
        cout << "1) Parts with same Company ID" << endl;
        cout << "2) Parts with same Parts ID" << endl;
        cout << "3) Parts with same Part name" << endl;
        cout << "4) Parts with same Manufacturing date" << endl;
        cout << "5) Go to main menu" << endl;
        cout << "Enter choice : ";
        switch (getch())
        {
        case '1':
        {
            // cout << "Inventory :-" << endl;
            system("cls");
            string company;
            cout << "Enter the company you want to search for : ";
            getline(cin, company);
            Node *ptr1 = Left_node;
            bool chk = false;
            if (ptr1 == NULL)
            {
                cout << "Inventory is empty" << endl;
            }
            else
            {
                while (ptr1 != NULL)
                {
                    if (ptr1->company_id == company)
                    {
                        print(ptr1);
                        chk = true;
                        ptr1 = ptr1->RMP;
                    }
                    else
                    {
                        ptr1 = ptr1->RMP;
                    }
                }
                if (chk == false)
                    cout << "No such Records found" << endl;
            }
            cout << "Press any key to go back" << endl;
            delete ptr1;
            getch();
        }
        break;

        case '2':
        {
            system("cls");
            string parts;
            cout << "Enter the part ID you want to search for : ";
            getline(cin, parts);
            Node *ptr1 = Left_node;

            if (ptr1 == NULL)
            {
                cout << "Inventory is empty" << endl;
            }
            else
            {
                bool chk = false;
                while (ptr1 != NULL)
                {

                    if (ptr1->parts_id == parts)
                    {
                        print(ptr1);
                        chk = true;
                        ptr1 = ptr1->RMP;
                    }
                    else
                    {
                        ptr1 = ptr1->RMP;
                    }
                }
                if (chk == false)
                    cout << "No such Records found" << endl;
            }
            cout << "Press any key to go back" << endl;
            delete ptr1;
            getch();
            break;
        }

        case '3':
        {
            system("cls");
            string name_part;
            cout << "Enter the part name you want to search for : ";
            getline(cin, name_part);
            Node *ptr1 = Left_node;

            if (ptr1 == NULL)
            {
                cout << "Inventory is empty" << endl;
            }
            else
            {
                bool chk = false;
                while (ptr1 != NULL)
                {
                    if (ptr1->parts_nam == name_part)
                    {
                        print(ptr1);
                        ptr1 = ptr1->RMP;
                        chk = true;
                    }
                    else
                    {
                        ptr1 = ptr1->RMP;
                    }
                }
                if (chk == false)
                    cout << "No such Records found" << endl;
            }
            cout << "Press any key to go back" << endl;
            delete ptr1;
            getch();
            break;
        }

        case '4':
        {
            system("cls");
            Node *ptr1 = Left_node;
            int year_check = year_input();
            int month_check = month_input();
            int date_check = date_input(month_check, year_check);

            if (ptr1 == NULL)
            {
                cout << "Inventory is empty" << endl;
                return;
            }
            bool chk = false;
            do
            {
                if (year_check >= ptr1->expy.year_exp)
                {
                    if (month_check >= ptr1->expy.month_exp)
                    {
                        if (date_check >= ptr1->expy.date_exp)
                        {
                            print(ptr1);
                            chk = true;
                            break;
                        }
                        else
                        {
                            ptr1 = ptr1->RMP;
                        }
                        break;
                    }
                    else
                    {
                        ptr1 = ptr1->RMP;
                    }
                    break;
                }
                else
                {
                    ptr1 = ptr1->RMP;
                }

            } while (ptr1->RMP == NULL);
            if (chk == false)
                cout << "No such part found" << endl;
            break;
        }

        case '5':
        {
            check = false;
        }

        default:
            break;
        }
    } while (check);
}

Node *Load_Data(Backup &Back)
{
    Node *ptr = new Node();
    ptr->company_id = Back.Comp_Id;
    ptr->parts_id = Back.Part_Id;
    ptr->parts_nam = Back.part_name;
    ptr->manf.date_man = Back.DOM.date_man;
    ptr->manf.month_man = Back.DOM.month_man;
    ptr->manf.year_man = Back.DOM.year_man;
    ptr->expy.date_exp = Back.DOE.date_exp;
    ptr->expy.month_exp = Back.DOE.month_exp;
    ptr->expy.year_exp = Back.DOE.year_exp;
    return ptr;
}

Backup *Backup_Data(Node &ptr)
{
    Backup *Back = new Backup();
    strcpy(Back->Comp_Id, ptr.company_id.c_str());
    strcpy(Back->Part_Id, ptr.parts_id.c_str());
    strcpy(Back->part_name, ptr.parts_nam.c_str());
    Back->DOM.date_man = ptr.manf.date_man;
    Back->DOM.month_man = ptr.manf.month_man;
    Back->DOM.year_man = ptr.manf.year_man;
    Back->DOE.date_exp = ptr.expy.date_exp;
    Back->DOE.month_exp = ptr.expy.month_exp;
    Back->DOE.year_exp = ptr.expy.year_exp;
    return Back;
}

void Backup_File()
{
    ofstream fout;
    fout.open("Backup.csv");
    if (!fout)
    {
        cout << "Error in Opening the records file!" << endl;
        exit(1);
    }
    if (!Left_node)
        return;
    Node *current = Left_node;
    Backup *Back;
    while (current)
    {
        Back = Backup_Data(*current);
        fout.write((char *)&(*Back), sizeof(*Back));
        delete Back;
        current = current->RMP;
    }
    fout.close();
}

void Retrieve_Data()
{
    ifstream fin;
    fin.open("Backup.csv");
    if (!fin)
    {
        cout << "Error in Opening the records file!" << endl;
        exit(1);
    }
    fin.seekg(0, ios::end);
    if (fin.tellg() == 0)
        return;
    fin.seekg(0, ios::beg);
    Backup Back;
    Node *prt;
    string last1{" "};
    string last2{" "};
    while (!fin.eof())
    {
        fin.read((char *)(&Back), sizeof(Back));
        prt = (Load_Data(Back));
        if ((last1 == prt->parts_id && last2 == prt->company_id) || (prt->company_id == ""))
            break;
        Insert(prt);
        last1 = prt->parts_id;
        last2 = prt->company_id;
        delete prt;
    }
    fin.close();
}

int main()
{
    bool flag = true;
    int i = 0;
    int choice;
    // Retrieve_Data();
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
        cout << "\t\t\t\t\t7) backup all parts" << endl;
        cout << "\t\t\t\t\t8) retrive backup all parts" << endl;
        cout << "\t\t\t\t\t9) Exit" << endl;
        cout << "\t\t\t\t\tYour choice :- ";
        // cin >> choice;

        switch (getch())
        {
        case '1':
        {
        add_again:
            system("cls");
            cout << "\n-----------------------------------------------" << endl;
            cout << "\t    Enter Inventory Data: " << endl;
            cout << "\n-----------------------------------------------" << endl
                 << endl;

            takeInput();
            char choice_add;
            cout << "Do you want to add another record (Y/N) : ";
            cin >> choice_add;
            choice_add = toupper(choice_add);

            if (choice_add == 'Y')
            {
                goto add_again;
            }
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;

        case '2':
        {
            system("cls");
            string del_com, del_part;
        del_again:
            cout << "Enter the company id of the item you want to delete : ";
            cin >> del_com;
            cout << "Enter the part id of the item you want to delete    : ";
            cin >> del_part;
            // Node *p = Search(del_com, del_part);
            // if (p == NULL)
            // {
            //     cout << "No such item found!" << endl;
            // }
            // else
            // {
            //     delete_item(p);
            // }
            delete_item(del_com, del_part);
            char choice;
            cout << "Do you want to delete record (Y/N) : ";
            cin >> choice;
            choice = toupper(choice);

            if (choice == 'Y')
            {
                goto del_again;
            }

            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;

        case '3':
        {
            system("cls");
            int item = count_item();
            cout << "Total number of parts in Inventory : " << item << endl;
            cout << "Press any key to go back to main menu" << endl;
            getch();
            break;
        }

        case '4':
        {
            system("cls");
            check_expiry();
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;
        case '5':
        {
            system("cls");
            report();
            // cout << "Press any key to go back to main menu" << endl;
            // getch();
            break;
        }

        case '6':
        {
            system("cls");
            cout << "\n-----------------------------------------------" << endl;
            cout << "\t     Inventory Details: " << endl;
            cout << "\n-----------------------------------------------" << endl
                 << endl;
            print_List();
            cout << "Press any key to go back to main menu" << endl;
            getch();
            break;
        }

        case '7':
        {
            system("cls");
            if (Left_node == NULL)
            {
                cout << "\nBackup Cannot be Done, List is Empty..." << endl;
            }
            else
            {
                Backup_File();
                cout << "Backup Of Data is Done...";
            }
            cout << "\n\nPress any key to go back to Main Menu...";
            getch();
        }
        break;

        case '8':
        {
            system("cls");
            Retrieve_Data();
            cout << "Retrieval Of Data is Done:";
            cout << "\n\nPress any key to go back to Main Menu...";
            getch();
        }
        break;

        case '9':
        {
            flag = false;
        }
        }
    } while (flag);
}
