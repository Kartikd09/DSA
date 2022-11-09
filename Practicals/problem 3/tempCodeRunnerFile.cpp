
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
            cout << "Press any key to go back to main menu" << endl;
            getch();
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
            flag = false;
        }
        }
    } while (flag);
}
