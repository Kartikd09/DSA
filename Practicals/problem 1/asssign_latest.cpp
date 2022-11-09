#include <iostream>
#include <string>

#include <windows.h> // for cls
#include <conio.h> // for getch()
using namespace std;

struct record
{
    string Roll_no;
    string first_name;
    string father_name_first;
    int date;
    int month;
    int year;
    string branch;
    unsigned int yoa;
    unsigned int tyop;
    string district;
    string state;
    unsigned int pin;
    string country;
};

bool check_roll(record student1[], string temp, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (temp == student1[i].Roll_no)
        {
            return true;
        }

        else {
            continue;
        }
    }
    return false;

}

void takeInput(struct record student1[], int size, int i)
{

    bool flag = true;
    string temp;
    cout << "Enter Roll no. :- " << endl;
    do
    {

        getline(cin, student1[i].Roll_no);
        temp = student1[i].Roll_no;
        flag = check_roll(student1, temp, size);
        if (flag == true)
        {
            cout << "This Roll number already exists!!" << endl;
        }
        else
        {

        }

    } while (flag);

    cout << "Enter Name :- " << endl;

    getline(cin, student1[i].first_name);
    cout << "Enter Father's Name :- " << endl;
    getline(cin, student1[i].father_name_first);

    bool check_dob = true;
    do
    {
        cout << "Enter Date of Birth :- " << endl;
        bool check_year = true;
        do
        {
            cout << "Enter the year : ";
            cin >> student1[i].year;
            if (student1[i].year >= 1947 && student1[i].year <= 2025)
            {
                check_year = false;
            }
            else
            {
                cout << "Error in year!! Re-enter" << endl;
                check_year = true;
            }

        } while (check_year);

        bool check_month = true;
        do
        {
            cout << "Enter the month : ";
            cin >> student1[i].month;
            if (student1[i].month >= 1 && student1[i].month <= 12)
            {
                check_month = false;
            }
            else {
                cout << "Error in month!! Re-enter" << endl;
                check_month = true;
            }


        } while (check_month);

        bool check_date = true;
        do
        {
            cout << "Enter the date : ";
            cin >> student1[i].date;

            if (student1[i].month >= 1 && student1[i].month <= 12)
            {
                if (student1[i].month == 1 || student1[i].month == 3 || student1[i].month == 5 || student1[i].month == 7 || student1[i].month == 8 || student1[i].month == 10 || student1[i].month == 12)
                {

                    if (student1[i].date >= 1 && student1[i].date <= 31)
                    {
                        check_date = false;
                    }
                    else
                    {
                        cout << "Error in date!! Re-enter" << endl;
                        check_date = true;
                    }
                }

                else if (student1[i].month == 4 || student1[i].month == 6 || student1[i].month == 9 || student1[i].month == 11)
                {

                    if (student1[i].date >= 1 && student1[i].date <= 30)
                    {

                        check_date = false;
                    }

                    else
                    {
                        cout << "Error in date!! Re-enter" << endl;
                        check_date = true;
                    }
                }

                else if (student1[i].month == 2)
                {

                    if (((student1[i].year % 4 == 0) && (student1[i].year % 100 != 0)) || student1[i].year % 400 == 0)
                    {
                        if (student1[i].date >= 1 && student1[i].date <= 29)
                        {
                            check_date = false;
                        }
                        else
                        {
                            cout << "Error in date!! Re-enter" << endl;
                            check_date = true;
                        }
                    }
                    else
                    {
                        if (student1[i].date >= 1 && student1[i].date <= 28)
                        {

                            check_date = false;
                        }
                        else
                        {
                            cout << "Error in date!! Re-enter" << endl;
                            check_date = true;
                        }
                    }
                }
            }
        } while (check_date);

        check_dob = false;

    } while (check_dob);



    cout << "Enter the Branch :- " << endl;
    cin >> student1[i].branch;

    cout << "Enter the Year of Admission :- " << endl;
    cin >> student1[i].yoa;

    cout << "Enter year of passing :- " << endl;
    cin >> student1[i].tyop;
    cin.ignore();

    cout << "Enter the district :- " << endl;
    getline(cin, student1[i].district);

    cout << "Enter the state :- " << endl;
    getline(cin, student1[i].state);


    bool check = true;
    do {

        cout << "Enter PIN :- " << endl;
        cin >> student1[i].pin;
        if (student1[i].pin >= 100000 && student1[i].pin <= 999999)
        {
            check = false;
            break;
        }


        else
        {
            cout << "Please enter valid pin" << endl;

        }


    } while (check);
    cin.ignore();

    cout << "Enter the country :- " << endl;
    getline(cin, student1[i].country);
}
// .
void printRecord(struct record student1[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "The details of student " << i + 1 << " are :- " << endl;

        cout << "Roll no. :- " << student1[i].Roll_no << endl;

        cout << "Name :- " << student1[i].first_name << endl;

        cout << "Father's Name :- " << student1[i].father_name_first << endl;

        cout << "Date of Birth :- " << student1[i].date << "/" << student1[i].month << "/" << student1[i].year << endl;

        cout << "Branch :- " << student1[i].branch << endl;

        cout << "Year of Admission :- " << student1[i].yoa << endl;

        cout << "Year of passing :- " << student1[i].tyop << endl;

        cout << "District :- " << student1[i].district << endl;

        cout << "State :- " << student1[i].state << endl;

        cout << "PIN :- " << student1[i].pin << endl;

        cout << "Country :- " << student1[i].country << endl;
        cout << endl;
    }
    cout << endl;
}

int getIndex(struct record student1[], string roll, int size)
{
    int change;
    for (int i = 0; i < size; i++)
    {
        if (roll == student1[i].Roll_no)
        {
            change = i;
            return change;
        }
    }
    cout << "Invalid roll number" << endl;
    return 1000;
}

void updateElement(struct record student1[], int change)
{
    int j = change;
    if (j == 1000) {
        cout << "No record" << endl;
    }
    else {
        cout << "This is record no. -  " << j + 1 << endl;
        cout << "1) Name " << endl;
        cout << "2) Father's Name " << endl;
        cout << "3) Date of Birth " << endl;
        cout << "4) Branch " << endl;
        cout << "5) Year of admission " << endl;
        cout << "6) Year of passing " << endl;
        cout << "7) District " << endl;
        cout << "8) State " << endl;
        cout << "9) PIN " << endl;
        cout << "10) Country " << endl;

        int b;
        cout << "What do you want to update :- ";
        cin >> b;

        switch (b)
        {
        case 1:
            cout << "Enter Name :- " << endl;
            cin >> student1[j].first_name;
            break;

        case 2:
            cout << "Enter Father's Name :- " << endl;
            cin >> student1[j].father_name_first;
            break;

        case 3:
            for (;;)
            {
                cout << "Enter Date of Birth :- " << endl;
                cout << "Enter the year : ";
                cin >> student1[j].year;
                if (student1[j].year >= 1947 && student1[j].year <= 2025)
                {
                    cout << "Enter the month : ";
                    cin >> student1[j].month;
                    if (student1[j].month >= 1 && student1[j].month <= 12)
                    {
                        if (student1[j].month == 1 || student1[j].month == 3 || student1[j].month == 5 || student1[j].month == 7 || student1[j].month == 8 || student1[j].month == 10 || student1[j].month == 12)
                        {
                            cout << "Enter the date : ";
                            cin >> student1[j].date;
                            if (student1[j].date >= 1 && student1[j].date <= 31)
                            {
                                break;
                            }
                            else
                            {
                                cout << "Error in date" << endl;
                                continue;
                            }
                        }

                        else if (student1[j].month == 4 || student1[j].month == 6 || student1[j].month == 9 || student1[j].month == 11)
                        {
                            cout << "Enter the date : ";
                            cin >> student1[j].date;
                            if (student1[j].date >= 1 && student1[j].date <= 30)
                            {

                                break;
                            }

                            else
                            {
                                cout << "Error in date" << endl;
                                continue;
                            }
                        }

                        else if (student1[j].month == 2)
                        {
                            cout << "Enter the date : ";
                            cin >> student1[j].date;
                            if (student1[j].date >= 1 && student1[j].date <= 28)
                            {
                                break;
                            }
                            else
                            {
                                cout << "error in date" << endl;
                                continue;
                            }
                        }
                    }

                    else
                    {
                        cout << "Error in month" << endl;
                        continue;
                    }
                }

                continue;
            }
            break;

        case 4:
            cout << "Enter the Branch :- " << endl;
            cin >> student1[j].branch;
            break;

        case 5:
            cout << "Enter the Year of Admission :- " << endl;
            cin >> student1[j].yoa;
            break;

        case 6:
            cout << "Enter year of passing :- " << endl;
            cin >> student1[j].tyop;
            break;

        case 7:
            cout << "Enter the district :- " << endl;
            cin >> student1[j].district;
            break;

        case 8:
            cout << "Enter the state :- " << endl;
            cin >> student1[j].state;
            break;

        case 9:
            cout << "Enter PIN :- " << endl;
            cin >> student1[j].pin;
            break;

        case 10:
            cout << "Enter the country :- " << endl;
            cin >> student1[j].country;
            break;
        default:
            cout << "Error" << endl;
            break;
        }
    }
}

void deleteElement(struct record student1[], int delete_index, int size)
{
    int k = delete_index;
    for (int i = k; i < size; i++)
    {
        student1[i] = student1[i + 1];
    }


}

void getReport_name(record student1[], int size)
{

    string get_name;
    bool get_check = true;
    // bool get = true;
    do
    {
        cout << "Enter the name you want to search for :-" << endl;
        getline(cin, get_name);

        for (int i = 0; i < size; i++)
        {
            if (get_name == student1[i].first_name)
            {


                cout << "The details of student " << i + 1 << " are :- " << endl;

                cout << "Roll no. :- " << student1[i].Roll_no << endl;

                cout << "Name :- " << student1[i].first_name << endl;

                cout << "Father's Name :- " << student1[i].father_name_first << endl;

                cout << "Date of Birth :- " << student1[i].date << "/" << student1[i].month << "/" << student1[i].year << endl;

                cout << "Branch :- " << student1[i].branch << endl;

                cout << "Year of Admission :- " << student1[i].yoa << endl;

                cout << "Year of passing :- " << student1[i].tyop << endl;

                cout << "District :- " << student1[i].district << endl;

                cout << "State :- " << student1[i].state << endl;

                cout << "PIN :- " << student1[i].pin << endl;

                cout << "Country :- " << student1[i].country << endl;
                cout << endl;

            }

        }
        cout << endl;


        get_check = false;


    } while (get_check);

}

void getReport_state(record student1[], int size)
{
    string get_state;
    bool get_check = true;
    // bool get = true;
    do
    {
        cout << "Enter the state you want to search for :-" << endl;
        getline(cin, get_state);

        for (int i = 0; i < size; i++)
        {
            if (get_state == student1[i].state)
            {


                cout << "The details of student " << i + 1 << " are :- " << endl;

                cout << "Roll no. :- " << student1[i].Roll_no << endl;

                cout << "Name :- " << student1[i].first_name << endl;

                cout << "Father's Name :- " << student1[i].father_name_first << endl;

                cout << "Date of Birth :- " << student1[i].date << "/" << student1[i].month << "/" << student1[i].year << endl;

                cout << "Branch :- " << student1[i].branch << endl;

                cout << "Year of Admission :- " << student1[i].yoa << endl;

                cout << "Year of passing :- " << student1[i].tyop << endl;

                cout << "District :- " << student1[i].district << endl;

                cout << "State :- " << student1[i].state << endl;

                cout << "PIN :- " << student1[i].pin << endl;

                cout << "Country :- " << student1[i].country << endl;

                cout << endl;
            }

        }


        get_check = false;


    } while (get_check);
}

void getReport_district(record student1[], int size)
{
    string get_district;
    bool get_check = true;
    // bool get = true;
    do
    {
        cout << "Enter the district you want to search for :-" << endl;
        getline(cin, get_district);

        for (int i = 0; i < size; i++)
        {
            if (get_district == student1[i].district)
            {


                cout << "The details of student " << i + 1 << " are :- " << endl;

                cout << "Roll no. :- " << student1[i].Roll_no << endl;

                cout << "Name :- " << student1[i].first_name << endl;

                cout << "Father's Name :- " << student1[i].father_name_first << endl;

                cout << "Date of Birth :- " << student1[i].date << "/" << student1[i].month << "/" << student1[i].year << endl;

                cout << "Branch :- " << student1[i].branch << endl;

                cout << "Year of Admission :- " << student1[i].yoa << endl;

                cout << "Year of passing :- " << student1[i].tyop << endl;

                cout << "District :- " << student1[i].district << endl;

                cout << "State :- " << student1[i].state << endl;

                cout << "PIN :- " << student1[i].pin << endl;

                cout << "Country :- " << student1[i].country << endl;

                cout << endl;
            }

        }
        cout << endl;

        get_check = false;


    } while (get_check);
}

int main()
{
    // system("Color 7C");
    record student1[50];
    int a;

    int size = 0;
    int i = 0;
    bool flag = true;
    do
    {
        system("cls");
        cout << "                                    " << " ______________________________________________" << endl;
        cout << "                                    " << "|       __   __  __   __   __   __   __        |" << endl;
        cout << "                                    " << "|      |__| |_  |    |  | |__| |  \\ |__        |" << endl;
        cout << "                                    " << "|      | \\  |__ |__  |__| | \\  |__/  __|       |" << endl;
        cout << "                                    " << "|______________________________________________|" << endl;

        cout << endl << endl;
        cout << "\t" << "1) Add record to the list" << endl;
        cout << "\t" << "2) Update a record " << endl;
        cout << "\t" << "3) Delete a record" << endl;
        cout << "\t" << "4) Print all the records" << endl;
        cout << "\t" << "5) Report" << endl;
        cout << "\t" << "6) Exit" << endl;


        int count = 0;
        switch (getch())
        {
        case 49: // 49 is for 1 as getch() returns variable so ascii value used in case for '1'

            system("cls");
            cout << "Add Record :-" << endl;
            takeInput(student1, size, i);
            size++;
            i++;
            cout << "Successfully added the record!!!" << endl;
            count++;
            cout << "Press any key to go back to the menu :- " << endl;
            getch();

            break;
        case 50: // 50 for 2
        {
            system("cls");
            string roll;
            int change;
            bool update_check = true;
            do {
                cout << "Enter roll number of the record you want to update :- ";
                getline(cin, roll);
                change = getIndex(student1, roll, size);
                if (change == 1000)
                {
                    update_check = false;
                }
                else {
                    cout << "updated the record" << endl;
                    update_check = false;
                }
            } while (update_check);
            updateElement(student1, change);
            cout << "Press any key to go back to the menu :- " << endl;
            getch();

        }
        break;

        case 51:
        {
            system("cls");
            string rollno;
            int delete_index;
            bool delete_check = true;
            do {
                cout << "Enter the roll no. of the record you want to delete :- " << endl;
                getline(cin, rollno);
                delete_index = getIndex(student1, rollno, size);
                if (delete_index == 1000)
                {
                    delete_check = false;
                }
                else {
                    cout << "Successfully deleted the record!!" << endl;
                    delete_check = false;
                }
            } while (delete_check);
            deleteElement(student1, delete_index, size);
            size--;
            i--;
            cout << "Press any key to go back to the menu :- " << endl;
            getch();
        }
        break;

        case 52: // 52 for 4
        {
            system("cls");
            cout << "The entered records are :- " << endl;
            cout << endl;
            printRecord(student1, size);
            cout << "Press any key to go back to the menu :- " << endl;
            getch();
        }
        break;

        case 53:
        {
            system("cls");

            bool rec = true;
            do
            {
                system("cls");
                cout << "1) Report having common names" << endl;
                cout << "2) Report having common state" << endl;
                cout << "3) Report having common district" << endl;
                cout << "4) Goto main menu" << endl;
                switch (getch())
                {
                case 49:
                {
                    system("cls");
                    getReport_name(student1, size);
                    cout << "Press any key to go back to the menu :- " << endl;
                    getch();
                }
                break;
                case 50:
                {
                    system("cls");
                    getReport_state(student1, size);
                    cout << "Press any key to go back to the menu :- " << endl;
                    getch();
                }
                break;

                case 51:
                {
                    system("cls");
                    getReport_district(student1, size);
                    cout << "Press any key to go back to the menu :- " << endl;
                    getch();
                }
                break;

                case 52:
                {
                    rec = false;
                }

                }

            } while (rec);
            break;
        }
        case 54: // 53 for 5
            flag = false;
        }
    } while (flag);

    return 0;
}
