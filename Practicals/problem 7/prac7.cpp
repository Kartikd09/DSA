#include <iostream>
#include <cstring>
#include <cmath>
#include <windows.h>
#include <conio.h>
using namespace std;

void Count(string input)
{
    int size = input.length();
    int characters = 0;
    int words = 0;
    int sentences = 0;
    int paragraph = 0;
    int spaces = 0;

    for (int i = 0; i < size; i++)
    {

        if (input[i] == ' ')
        {
            words++;
        }

        if (input[i] == '.')
        {
            sentences++;
        }

        if (input[i] == '\n')
        {
            paragraph++;
        }
    }
    characters = size - spaces;
    spaces = words - 1;

    cout << "No of characters : " << characters << endl;
    cout << "No of words : " << words << endl;
    cout << "No of sentences : " << sentences << endl;
    cout << "No of paragraphs : " << paragraph << endl;
}

int count_sentences(string input)
{
    int sentences = 0;
    int size = input.length();
    for (int i = 0; i < size; i++)
    {
        if (input[i] == '.')
        {
            sentences++;
        }
        else
            continue;
    }
    return sentences;
}

int main()
{
    bool flag = true;
    int choice;
input_again:
    // string input = takeInput();
    string input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque sed velit non dui lacinia auctor ac non orci. Etiam aliquam est diam, non suscipit massa venenatis ac. Morbi fringilla eleifend ornare. Morbi bibendum mi ac dui efficitur, pharetra porttitor sapien mattis. Quisque eget dictum lorem. Aenean bibendum lectus ligula, vitae feugiat tellus pharetra at. Suspendisse sit amet pretium massa. Proin maximus nec dolor at maximus. Nulla ut elit a tortor viverra faucibus. \n Pellentesque imperdiet quam ac risus vestibulum, id commodo nisl consequat. Mauris tristique libero vel porttitor pharetra. Mauris non diam ante. Aliquam pulvinar mi nec libero fermentum, eget venenatis mauris sodales. Etiam placerat pellentesque libero eget maximus. Maecenas sed eros ultricies, vestibulum felis in, ullamcorper risus.";
    cout << endl;

    do
    {
        system("cls");
        cout << "Main Menu:-" << endl;
        cout << "1) Search a pattern/word" << endl;
        cout << "2) Convert into its components/words" << endl;
        cout << "3) Find the frequency of each word" << endl;
        cout << "4) Count the number of sentences" << endl;
        cout << "5) Count the number of characters,words,sentences and paragraphs in a given text data" << endl;
        cout << "6) Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "press an key to continue " << endl;
            getch();
        }
        break;

        case 2:
        {
            system("cls");
            cout << "press an key to continue " << endl;
            getch();
        }
        break;

        case 3:
        {
            system("cls");
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

        case 4:
        {
            system("cls");
            count_sentences(input);
            int sentences = count_sentences(input);
            cout << "No.of sentences : " << sentences << endl;
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

        case 5:
        {
            system("cls");
            Count(input);
            cout << "Press any key to continue" << endl;
            getch();
        }
        break;

            // case 6:
            // {
            //     goto input_again;
            // }

        case 6:
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