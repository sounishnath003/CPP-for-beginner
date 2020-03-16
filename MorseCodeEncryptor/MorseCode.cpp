#include <iostream>
#include<bits/stdc++.h>

using namespace std ;


const char letters[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

const string morseLetters[37] = { "    ", ". ___", "___ . . .", "___ . ___ .", "___ . .", ".", ". . ___ .", "___ ___ .", ". . . .", ". .", ". ___ ___ ___", "___ . ___", ". ___ . .",  "___ ___", "___ .", "___ ___ ___", ". ___ ___ .", "___ ___ . ___", ". ___ .", ". . .", "_", ". . ___", ". . . ___", ". ___ ___", "___ . . ___", "___ . ___ ___", "___ ___ . .", ". ___ ___ ___ ___", ". . ___ ___ ___", ". . . ___ ___", ". . . . ___", ". . . . .", "___ . . . .", "___ ___ . . .", "___ ___ ___ . .", "___ ___ ___ ___ .", "___ ___ ___ ___ ___"};

string textToChange = "";

string newText = "" ;

int main(int argc, char const *argv[])
{
    textToChange = "my name is Sounish Nath" ;
    cout << textToChange << endl;

    transform(textToChange.begin(), textToChange.end(), textToChange.begin(), ::tolower);
    cout << textToChange << endl;

    for (size_t j = 0; j < textToChange.size(); j++)
    {
        for (size_t i = 0; i < 37; i++) {
            if (textToChange[j] == letters[i])
            {
                newText = newText + morseLetters[i];
                newText = newText + " ";

                break;
            }
            
        }
    }
    
    
    cout << "Morse code: " << newText << endl ;


    return 0;
}
