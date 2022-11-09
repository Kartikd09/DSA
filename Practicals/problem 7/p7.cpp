/*Problem 7: Case Study of Pattern Matching: Write a program to implement
the following methods for textual data set. The said data set may be organized
as paragraphs, tables, or any readable pattern. Each method is required to be
tested for a given paragraph.
1. Search a pattern/word
2. Covert into its components/words
3. Find the frequency of each word
4. Count the number of sentences
5. Count the number of characters, words, sentences and paragraphs in a
given text data
You are also required to draw block of your program.*/

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>
// #include "text-manipulation.hpp"
using namespace std;

size_t countCharacters(string &text);
size_t countCharacters(string &text, char ch);
size_t countWords(string &text);
size_t countParagraphs(string &text);
size_t countSentences(string &text);

int main()
{
    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam a commodo risus. Mauris lacinia lectus ac eros dapibus, sit amet viverra sapien eleifend. Suspendisse gravida quam nisi, vel consectetur justo laoreet vitae. Vestibulum sit amet pharetra purus, vitae iaculis lacus. Nam at nisl felis. Morbi auctor vitae enim a auctor. Sed congue urna at nisi ultrices faucibus vel a eros. Cras rutrum quam ex, ut suscipit elit varius eu. Curabitur sit amet mauris at arcu aliquam cursus a quis orci. Etiam iaculis felis neque, non sollicitudin sapien semper a. Aenean eleifend ligula commodo, vulputate dolor et, tincidunt erat. Proin at nibh vitae lorem lacinia fringilla.\n\n"
                  "Quisque efficitur accumsan turpis ac ultrices. Fusce quis lacus nec ante tincidunt vestibulum vel nec ex. Quisque vehicula vehicula diam ac varius. Proin dictum varius efficitur. Nam a magna sit amet est ultricies vestibulum. Pellentesque auctor ipsum eu elit imperdiet, vel imperdiet urna elementum. Nam non semper mi.\n\n"
                  "Praesent eu quam nisl. Nunc libero libero, dignissim ac nisi quis, euismod fermentum mi. Nunc ut consequat nisl, eu vehicula felis. Mauris sapien diam, rhoncus quis ante vel, dignissim tempor diam. Praesent at quam sed lacus mollis ornare ut id mi. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nulla vulputate ligula ac tellus sollicitudin tempor. Integer tristique nibh et ipsum dignissim semper. Suspendisse iaculis porta mi et cursus. Proin diam elit, fermentum aliquet purus at, vestibulum sagittis sem.\n\n"
                  "Pellentesque lobortis leo facilisis cursus laoreet. Nulla laoreet suscipit nulla. Sed quis metus sed quam semper lacinia. Proin congue aliquam iaculis. Phasellus quis massa eget purus viverra malesuada non sit amet arcu. Sed egestas dictum risus at bibendum. Aliquam erat volutpat. Sed mi felis, tempus sit amet tempus a, consectetur sit amet nisi. Proin non tincidunt velit. Nunc scelerisque augue orci. Ut bibendum dui eget pharetra viverra. Etiam quis egestas mi.\n\n"
                  "In fringilla cursus quam, vitae varius dolor vestibulum cursus. Duis justo augue, consequat eget sapien sit amet, imperdiet finibus diam. In pulvinar lacus purus, in luctus augue imperdiet non. Aliquam erat volutpat. Nullam luctus consequat felis, vitae varius ante malesuada ut. Quisque ac molestie eros, id tincidunt risus. Nunc fringilla enim nulla, eu tristique nunc scelerisque ut. Mauris at arcu leo. Vestibulum at pretium est. Nunc porttitor, lacus nec vestibulum dignissim, diam lectus aliquet justo, vel efficitur urna lectus id turpis. Aliquam condimentum enim quis sagittis egestas. Donec vulputate leo non sapien bibendum, vel scelerisque est fermentum.";
    cout << text << endl;
    cout << "words : " << countWords(text) << endl;
    cout << "characters (with spaces): " << countCharacters(text) << endl;
    cout << "characters (without spaces) : " << countCharacters(text, 'x') << endl;
    cout << "paragraphs : " << countParagraphs(text) << endl;
    cout << "sentences : " << countSentences(text) << endl;

    return 0;
}

// #include "text-manipulation.hpp"
using namespace std;

size_t countCharacters(string &text)
{
    int i{0};
    int count{0};
    while (text[i++] != '\0')
    {
        if (text[i] == '\n')
            continue;
        count++;
    }
    return count;
}

size_t countCharacters(string &text, char ch)
{
    int i{0};
    int count{0};
    while (text[i++] != '\0')
    {
        if (text[i] == '\n' || text[i] == ' ')
            continue;
        count++;
    }
    return count;
}

size_t countWords(string &text)
{
    istringstream iss(text);
    string temp;
    int count{0};
    while (getline(iss, temp, ' '))
    {
        if (temp.find('\n') != string::npos)
        {
            istringstream iss1(temp);
            while (getline(iss1, temp))
            {
                if (temp != "")
                    count++;
            }
            continue;
        }
        count++;
    }
    return count;
}

size_t countParagraphs(string &text)
{
    string temp;
    istringstream iss(text);
    int count{0};
    while (getline(iss, temp))
    {
        if (temp == "")
            continue;
        count++;
    }
    return count;
}

size_t countSentences(string &text)
{
    string temp;
    istringstream iss(text);
    int count{0};
    while (getline(iss, temp, '.'))
    {
        if (temp.find('!') != string::npos)
        {
            string temp1;
            istringstream iss1(temp1);
            while (getline(iss1, temp1, '!'))
            {
                if (temp1 != "")
                    count++;
            }
            continue;
        }
        if (temp.find('?') != string::npos)
        {
            string temp1;
            istringstream iss1(temp1);
            while (getline(iss1, temp1, '?'))
            {
                if (temp1 != "")
                    count++;
            }
            continue;
        }
        count++;
    }
    return count;
}