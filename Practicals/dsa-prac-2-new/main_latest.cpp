#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

struct Address
{
    string house_number;
    string village;
    string postoffice;
    string city;
    string state;
    unsigned int PIN;
    string country;
};

struct joining
{
    int date_join;
    int month_join;
    int year_join;
};

struct retirement
{
    int date_retire;
    int month_retire;
    int year_retire;
};

struct Node
{
    struct Node *next;
    int Employee_num;
    string Employee_name;
    string Father_name;
    string department;
    retirement emp_retire;
    joining emp_join;
    Address emp_address;
};

Node *start = NULL; //! saves the address of the first node
int count_emp = 0;

void backup()
{
    Node *temp2 = start;
    ofstream file;
    file.open("Backup.csv");
    if (!file)
    {
        cout << "Error in opening the file!!" << endl;
    }
    else
    {

        while (temp2 != NULL)
        {
            file
                << temp2->Employee_num << "," << temp2->Employee_name << "," << temp2->Father_name << "," << temp2->emp_join.date_join << "," << temp2->emp_join.month_join << "," << temp2->emp_join.year_join << "," << temp2->department << "," << temp2->emp_retire.date_retire << "," << temp2->emp_retire.month_retire << "," << temp2->emp_retire.year_retire << "," << temp2->emp_address.house_number << "," << temp2->emp_address.village << "," << temp2->emp_address.postoffice << "," << temp2->emp_address.city << "," << temp2->emp_address.state << "," << temp2->emp_address.PIN << "," << temp2->emp_address.country << endl;

            temp2 = temp2->next;
        }
    }
    file.close();
}

int year_input()
{
    int input_year;
    bool check_yearJoin = true;
    do
    {
        cout << "Year                     : ";
        cin >> input_year;
        if (input_year >= 1947 && input_year <= 2025)
        {
            check_yearJoin = false;
        }
        else
        {
            cout << "Error in year!! Re-enter" << endl;
            check_yearJoin = true;
        }

    } while (check_yearJoin);
    return input_year;
}

int month_input()
{
    int input_month;
    bool check_monthJoin = true;
    do
    {
        cout << "Month                    : ";
        cin >> input_month;
        if (input_month >= 1 && input_month <= 12)
        {
            check_monthJoin = false;
        }
        else
        {
            cout << "Error in month!! Re-enter" << endl;
            check_monthJoin = true;
        }

    } while (check_monthJoin);
    return input_month;
}

int date_input(Node *ptr)
{
    int input_date;
    bool check_dateJoin = true;
    do
    {
        cout << "Date                     : ";
        cin >> input_date;

        if (ptr->emp_join.month_join >= 1 && ptr->emp_join.month_join <= 12)
        {
            if (ptr->emp_join.month_join == 1 || ptr->emp_join.month_join == 3 || ptr->emp_join.month_join == 5 || ptr->emp_join.month_join == 7 || ptr->emp_join.month_join == 8 || ptr->emp_join.month_join == 10 || ptr->emp_join.month_join == 12)
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

            else if (ptr->emp_join.month_join == 4 || ptr->emp_join.month_join == 6 || ptr->emp_join.month_join == 9 || ptr->emp_join.month_join == 11)
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

            else if (ptr->emp_join.month_join == 2)
            {

                if (((ptr->emp_join.year_join % 4 == 0) && (ptr->emp_join.year_join % 100 != 0)) || ptr->emp_join.year_join % 400 == 0)
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

void takeInput(int i)
{

    Node *ptr = new Node();
    i++;
    ptr->next = NULL;
    ptr->Employee_num = i;
    cout << "Employee ID              : " << ptr->Employee_num << endl;

    cout << "Employee name            : ";
    cin >> ptr->Employee_name;
    cin.ignore();
    cout << "Father's name            : ";
    getline(cin, ptr->Father_name);

    bool check_doj = true; //! can be removed
    do
    {
        cout << "Enter joining info :-" << endl;

        ptr->emp_join.year_join = year_input();
        ptr->emp_join.month_join = month_input();
        ptr->emp_join.date_join = date_input(ptr);

        check_doj = false;

    } while (check_doj);

    cin.ignore();
    cout << "Department               : ";
    getline(cin, ptr->department);

    bool dor_check = true;
    do
    {
        cout << "Enter retirement info :- " << endl;
        ptr->emp_retire.year_retire = year_input();
        ptr->emp_retire.month_retire = month_input();
        ptr->emp_retire.date_retire = date_input(ptr);

        dor_check = false;

    } while (dor_check);
    cin.ignore();

    cout << "Enter the Address:-" << endl;
    cout << "House number             : ";
    getline(cin, ptr->emp_address.house_number);

    cout << "Village/Town             : ";
    getline(cin, ptr->emp_address.village);

    cout << "Post Office              : ";
    getline(cin, ptr->emp_address.postoffice);

    cout << "City                     : ";
    getline(cin, ptr->emp_address.city);

    cout << "State                    : ";
    getline(cin, ptr->emp_address.state);

    bool check_pin = true;
    do
    {
        cout << "Pincode                  : ";
        cin >> ptr->emp_address.PIN;
        if (ptr->emp_address.PIN >= 100000 && ptr->emp_address.PIN <= 999999)
        {
            check_pin = false;
            break;
        }
        else
        {
            cout << "Invalid PIN . Enter a valid PIN!!" << endl;
        }
    } while (check_pin);
    cin.ignore();

    cout << "Country                  : ";
    getline(cin, ptr->emp_address.country);

    if (start == NULL)
    {
        start = ptr;
        // return start;
    }

    else
    {
        Node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    // return start;
}

void printRecord()
{
    Node *print_rec = start;
    // int check = i;
    // cout << print_rec->Employee_name;
    if (print_rec == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    cout << "The Entered records are:-" << endl;
    while (print_rec != NULL)
    // while (print_rec != NULL)
    {
        cout << "Details of Employee " << print_rec->Employee_num << " are:-" << endl;
        cout << "Employee ID              : " << print_rec->Employee_num << endl;
        cout << "Employee name            : " << print_rec->Employee_name << endl;

        cout << "Father's name            : " << print_rec->Father_name << endl;

        // cout << "Joining info :-" << endl;
        cout << "Joining                  : " << print_rec->emp_join.date_join << "/" << print_rec->emp_join.month_join << "/" << print_rec->emp_join.year_join << endl;
        // cout << "Date of Joining          : " << print_rec->emp_join.date_join << endl;

        // cout << "Month of Joining         : " << print_rec->emp_join.month_join << endl;

        // cout << "Year of joining          : " << print_rec->emp_join.year_join << endl;

        cout << "Department               : " << print_rec->department << endl;

        cout << "Retirement               : " << print_rec->emp_retire.date_retire << "/" << print_rec->emp_retire.month_retire << "/" << print_rec->emp_retire.year_retire << endl;
        // cout << "Retirement info :-" << endl;
        // cout << "Date of Retirement       : " << print_rec->emp_retire.date_retire << endl;

        // cout << "Month of Retirement      : " << print_rec->emp_retire.month_retire << endl;

        // cout << "Year of Retirement       : " << print_rec->emp_retire.year_retire << endl;

        cout << "Address details :-" << endl;
        cout << "House number             : " << print_rec->emp_address.house_number << endl;

        cout << "Village/Town             : " << print_rec->emp_address.village << endl;

        cout << "Post office              : " << print_rec->emp_address.postoffice << endl;

        cout << "City                     : " << print_rec->emp_address.city << endl;

        cout << "State                    : " << print_rec->emp_address.state << endl;

        cout << "Pincode                  : " << print_rec->emp_address.PIN << endl;

        cout << "Country                  : " << print_rec->emp_address.country << endl;

        cout << endl;

        print_rec = print_rec->next;
    }
}

void print_report(Node *temp)
{
    cout << "Details of Employee " << temp->Employee_num << " are:-" << endl;
    cout << "Employee ID              : " << temp->Employee_num << endl;
    cout << "Employee name            : " << temp->Employee_name << endl;

    cout << "Father's name            : " << temp->Father_name << endl;

    cout << "Joining                  : " << temp->emp_join.date_join << "/" << temp->emp_join.month_join << "/" << temp->emp_join.year_join << endl;

    cout << "Department               : " << temp->department << endl;

    cout << "Retirement               : " << temp->emp_retire.date_retire << "/" << temp->emp_retire.month_retire << "/" << temp->emp_retire.year_retire << endl;

    cout << "Address details :-" << endl;
    cout << "House number             : " << temp->emp_address.house_number << endl;

    cout << "Village/Town             : " << temp->emp_address.village << endl;

    cout << "Post office              : " << temp->emp_address.postoffice << endl;

    cout << "City                     : " << temp->emp_address.city << endl;

    cout << "State                    : " << temp->emp_address.state << endl;

    cout << "Pincode                  : " << temp->emp_address.PIN << endl;

    cout << "Country                  : " << temp->emp_address.country << endl;

    cout << endl;
}

Node *Search(Node *start, int j)
{
    Node *ptr = start;
    // string data1;
    while (ptr != NULL)
    {
        if (ptr->Employee_num == j)
        {
            // cout << "Employee Data Found..\n";
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void updateRecord(Node *p)
{
    bool flag = false;
    bool loop_run = true;
    Node *ptr1 = p;
    if (ptr1 != NULL)
    {
        cout << endl;
        cout << "1)  Employee Name " << endl;
        cout << "2)  Father's Name " << endl;
        cout << "3)  Date of Joining " << endl;
        cout << "4)  Department " << endl;
        cout << "5)  Date of Retiremnet " << endl;
        cout << "6)  House Number " << endl;
        cout << "7)  Village " << endl;
        cout << "8)  Post Office " << endl;
        cout << "9)  City " << endl;
        cout << "10) State " << endl;
        cout << "11) PIN " << endl;
        cout << "12) Country " << endl;
        cout << "13) Exit " << endl;

        int b;
    upd:
        cout << "What do you want to update :- ";
        cin >> b;
        cin.ignore();

        switch (b)
        {
        case 1:
        {
            cout << "Enter Employee Name :- ";
            getline(cin, ptr1->Employee_name);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 2:
        {
            cout << "Enter Father's Name :- ";
            getline(cin, ptr1->Father_name);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 3:
        {
            cout << "Enter Joining info :- " << endl;
            cout << "Enter Year:- ";
            ptr1->emp_join.year_join = year_input();

            cout << "Enter Month:- ";
            ptr1->emp_join.month_join = month_input();

            cout << "Enter Date:- ";
            ptr1->emp_join.date_join = date_input(ptr1);

            cin.ignore();
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 4:
        {
            cout << "Enter department:- ";
            getline(cin, ptr1->department);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 5:
        {
            cout << "Enter Retirement info:- " << endl;
            cout << "Enter Year: ";
            ptr1->emp_retire.year_retire = year_input();

            cout << "Enter month: ";
            ptr1->emp_retire.month_retire = month_input();

            cout << "Enter date: ";
            ptr1->emp_retire.date_retire = date_input(ptr1);

            cin.ignore();
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 6:
        {
            cout << "Enter House No. :- ";
            getline(cin, ptr1->emp_address.house_number);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 7:
        {
            cout << "Enter Village :- ";
            getline(cin, ptr1->emp_address.village);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 8:
        {
            cout << "Enter Post Office :- ";
            getline(cin, ptr1->emp_address.postoffice);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 9:
        {
            cout << "Enter City :- ";
            getline(cin, ptr1->emp_address.city);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 10:
        {
            cout << "enter State :- ";
            getline(cin, ptr1->emp_address.state);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 11:
        {
            cout << "enter PIN:- ";
            cin >> ptr1->emp_address.PIN;
            cin.ignore();
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 12:
        {
            cout << "Enter country :- ";
            getline(cin, ptr1->emp_address.country);
            cout << "Record has been updated!!" << endl;
            break;
        }

        case 13:
        {
            break;
        }
        default:
        {
            cout << "Invalid input!! Re-enter choice" << endl;
            goto upd;
        }
        }
    }

    else
    {
        cout << "Record does not exist" << endl;
    }
}

Node *delete_Record(Node *start, int i)
{
    Node *ptr_delete = start;
    Node *temp = start;
    Node *prev = start;
    int delete_id;
    // int count_node;
    bool flag_delete = false;
    bool search_delete = true;
    // Node *temp = start;
    if (ptr_delete != NULL)
    {
        do
        {
            cout << "Enter the ID of the Employee you want to delete:- ";
            cin >> delete_id;
            int count = 1;
            do
            {
                if (delete_id == ptr_delete->Employee_num)
                {
                    flag_delete = true;
                    break;
                }
                else
                {
                    count++;
                    // Node *temp = ptr_delete;
                    ptr_delete = ptr_delete->next;
                }

            } while (ptr_delete != NULL);

            if (count == 1)
            {
                cout << "\nYOUR RECORD HAS BEEN DELETED" << endl;
                return start->next;
            }
            while (temp->next != NULL && temp->Employee_num != delete_id)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp->Employee_num == delete_id)
            {
                prev->next = temp->next;
                delete (temp);
                // createBackup();
                cout << "\nYOUR RECORD HAS BEEN DELETED" << endl;

                return start;
            }
            else
            {
                cout << "\n::NO RECORD EXISTS FOR EMPLOYEE " << delete_id << "::" << endl;
                ;
                break;
            }
            search_delete = false;
        } while (search_delete);
        count_emp--;
    }

    else
    {
        cout << "List is empty" << endl;
        return start;
    }
}

void generate_Report()
{
    int choice;

    // Node*temp2 = start;
    // Node*temp3 = start;
    string State, rep_City, Country;
    cout << "1)Employees with same state,city or country" << endl;
    cout << "2)Employees with same joining date" << endl;
    cout << "3)Employees with same retirement date" << endl;
    cout << "4)Go to main menu" << endl;

// bool loop;
user_choice:
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Node *temp = start;
        if (temp == NULL)
        {
            cout << "List is empty!!" << endl;
            return;
        }
        cout << "Enter City : ";
        cin >> rep_City;
        cin.ignore();
        cout << endl;
        cout << "Enter State : ";
        getline(cin, State);
        cout << endl;
        cout << "Enter Country : ";
        getline(cin, Country);
        bool check = false;

        do
        {
            if (temp->emp_address.city == rep_City || temp->emp_address.state == State || temp->emp_address.country == Country)
            {
                // cout << "Records with same City :- " << endl;
                print_report(temp);
                check = true;
                temp = temp->next;
                cout << endl
                     << endl;
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != NULL);

        if (check = false)
        {
            cout << "No matching records!!" << endl;
        }
    }
    break;

    case 2:
    {
        Node *temp = start;
        int inp_date, inp_month, inp_year;
        cout << "Enter year : ";
        inp_year = year_input();
        cout << "Enter month : ";
        inp_month = month_input();
        cout << "Enter date : ";
        inp_date = date_input(temp);

        do
        {
            if (temp->emp_join.date_join == inp_date && temp->emp_join.month_join == inp_month && temp->emp_join.year_join == inp_year)
            {
                cout << "Records with same Joining date are :- " << endl;
                print_report(temp);
                temp = temp->next;
            }
            else
            {
                cout << "No matching Record!!" << endl;
            }
        } while (temp != NULL);
    }
    break;

    case 3:
    {
        Node *temp = start;
        int inp_date, inp_month, inp_year;
        cout << "Enter year : ";
        inp_year = year_input();
        cout << "Enter month : ";
        inp_month = month_input();
        cout << "Enter date : ";
        inp_date = date_input(temp);

        do
        {
            if (temp->emp_retire.date_retire == inp_date && temp->emp_retire.month_retire == inp_month && temp->emp_retire.year_retire == inp_year)
            {
                cout << "Records with same Retiring date are :- " << endl;
                print_report(temp);
                temp = temp->next;
            }
            else
            {
                cout << "No matching Record!!" << endl;
            }
        } while (temp != NULL);
    }
    break;

    case 4:
    {
        break;
    }

    default:
    {
        cout << "Invalid choice!! Re-enter" << endl;
        goto user_choice;
    }
    break;
    }
}

void main_display()
{
    cout << "\t\t\t\t\t*********************************************************************************************************" << endl;
    cout << "\t\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*" << endl;
    cout << "\t\t\t\t\t*\t ________  _________ _     _______   _______ _____  ______ _____ _____ _________________  \t*" << endl;
    cout << "\t\t\t\t\t*\t|  ___|  \\/  || ___ \\ |   |  _  \\ \\ / /  ___|  ___| | ___ \\  ___/  __ \\  _  | ___ \\  _  \\  \t*" << endl;
    cout << "\t\t\t\t\t*\t| |__ | .  . || |_/ / |   | | | |\\ V /| |__ | |__   | |_/ / |__ | /  \\/ | | | |_/ / | | |  \t*" << endl;
    cout << "\t\t\t\t\t*\t|  __|| |\\/| ||  __/| |   | | | | \\ / |  __||  __|  |    /|  __|| |   | | | |    /| | | |  \t*" << endl;
    cout << "\t\t\t\t\t*\t| |___| |  | || |   | |___\\ \\_/ / | | | |___| |___  | |\\ \\| |___| \\__/\\ \\_/ / |\\ \\| |/ /  \t*" << endl;
    cout << "\t\t\t\t\t*\t\\____/\\_|  |_/\\_|   \\_____/\\___/  \\_/ \\____/\\____/  \\_| \\_\\____/ \\____/\\___/\\_| \\_|___/  \t*" << endl;
    cout << "\t\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*" << endl;
    cout << "\t\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*" << endl;
    cout << "\t\t\t\t\t*********************************************************************************************************" << endl;
    cout << endl
         << endl;
}

int main()

{

    bool flag = true;
    int i = 0;
    do
    {

        system("cls");
        main_display();
        cout << "\t\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM" << endl;
        cout << "\t\t\t\t\t1) Add record to the list" << endl;
        cout << "\t\t\t\t\t2) Update a record " << endl;
        cout << "\t\t\t\t\t3) Delete a record" << endl;
        cout << "\t\t\t\t\t4) Print all the records" << endl;
        cout << "\t\t\t\t\t5) Backup the records" << endl;
        cout << "\t\t\t\t\t6) Report" << endl;
        cout << "\t\t\t\t\t7) Exit" << endl;
        cout << "\t\t\t\t\tYour choice :- ";

        switch (getch())
        {
        case 49:
        {
            system("cls");
            cout << "\n-----------------------------------------------" << endl;
            cout << "\t    Enter Employee's Data: " << endl;
            cout << "-----------------------------------------------" << endl
                 << endl;
            takeInput(i);
            i++;
            count_emp++;
            cout << endl;
            cout << "Successful Added!!!" << endl;
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;

        case 50:
        {
            system("cls");
            int j;
        update_again:
            cout << endl;
            cout << "Enter the Employee ID you want to update : ";
            cin >> j;
            Node *p = Search(start, j);
            updateRecord(p);
            char check;
            cout << "Do you want to update another record? -> (Y/N) : ";
            cin >> check;
            check = toupper(check);
            if (check == 'Y')
            {
                goto update_again;
            }
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;

        case 51:
        {
            system("cls");
            start = delete_Record(start, i);
            count_emp--;
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;

        case 52:
        {
            system("cls");
            cout << "\n-----------------------------------------------" << endl;
            cout << "\t     Employee's Data: " << endl;
            cout << "-----------------------------------------------" << endl
                 << endl;

            cout << "Total number of entered records   : " << count_emp << endl;
            printRecord();
            cout << "Press any key to go back to main menu" << endl;
            getch();
            break;
        }

        case 53:
        {
            system("cls");
            backup();
            cout << "data haas been backed up" << endl;
            cout << "Press any key to go back to main menu" << endl;
            getch();
        }
        break;
        case 54:
        {
            system("cls");
            generate_Report();
            cout << "Press any key to go back to main menu" << endl;
            getch();
            break;
        }

        case 55:
        {
            flag = false;
        }
        }
    } while (flag);
}