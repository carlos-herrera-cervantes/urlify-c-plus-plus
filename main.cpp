#include <iostream>
#include <string>

using namespace std;

/**
 * Replaces all white spaces with %20 string
 * @param str String to convert
 * @returns The string with %20 characters instead of white spaces
 */
string replace_spaces(string str, int trueLength)
{
    int spaceCount = 0;
    int i = 0;
    int index;

    for (i = 0; i < trueLength; i++)
    {
        if (str[i] == ' ') spaceCount++;
    }

    index = trueLength + spaceCount * 2;
    char chars[index];

    for (i = trueLength - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            chars[index - 1] = '0';
            chars[index - 2] = '2';
            chars[index - 3] = '%';
            index = index - 3;
        }
        else
        {
            chars[index - 1] = str[i];
            index--;
        }
    }

    return chars;
}

int main()
{
    cout << "THIS PROGRAM TAKES A STRING AND CHANGES ALL WHITE SPACES TO %20" << endl;
    cout << "Enter the string: ";

    string str;
    getline(cin, str);
    
    cout << "The resulting string is: " << replace_spaces(str, str.length()) << endl;

    return 0;
}