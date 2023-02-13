#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string cipher(string str, int key);
int arr_length(char str[]);
int wPosition(char c, char s[], int value);
bool only_digits(string str);

char lowerAlphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char upperAlphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int lower;
int upper;

int main(int argc, string argv[])
{

    //Check if there is any argument
    if (argc == 1 || argc >= 3 || only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        lower = arr_length(lowerAlphabet);
        upper = arr_length(upperAlphabet);
        int key = atoi(argv[1]);
        //Ask for the string and return the cypher
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: %s\n", cipher(plaintext, key));
        return 0;
    }
}
string cipher(string str, int key)
{
    int n = strlen(str);
    char t;
    int c = 0, l = 0;
    //iterate thought the string to make the cipher
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int position = 0;
        l = str[i];
        //Check if is a space or special char
        if (l >= 32 && l <= 64)
        {
            c = l;
        }
        else
        {
            //process for lowercase char
            if (islower(str[i]))
            {
                position = wPosition(str[i], lowerAlphabet, lower);
                c = lowerAlphabet[((position + key) % 26)];
                //printf("%i\n", ((position + key) % 26));
            }
            else
            {
                //process for uppercase char
                position = wPosition(str[i], upperAlphabet, upper);
                c = upperAlphabet[((position + key) % 26)];
                //printf("%i\n", ((position + key) % 26));
            }
        }
        t = c;
        //replace the char with the new one on [i] position
        str[i] = t;
    }
    return str;
}
//Check if the string has digits
bool only_digits(string str)
{
    int n = strlen(str);
    int nonDigit = 0;

    for (int i = 0; i < n; i++)
    {
        int val = str[i];

        if ((val >= 65 && val <= 90) || (val >= 97 && val <= 122))
        {
            nonDigit++;
        }
    }
    if (nonDigit >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int arr_length(char str[])
{
    int n = 0;

    while (str[n] != '\0')
    {
        n++;
    }
    return n;
}
int wPosition(char c, char s[], int value)
{
    int pos = 0;

    for (int i = 0; i < value; i++)
    {
        if (c == s[i])
        {
            break;
        }
        else
        {
            pos++;
        }
    }
    return pos;
}
