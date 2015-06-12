#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

//function to check if the char has a letters etc.
bool isLetter(char *input) 
{
    for (int i = 0; input[i] != '\0'; i++){
        if (isalpha(input[i])){
            return false;
        }
    }
    return true;
}

//function to check for dashes, spaces, digits only
bool isPhone(char *input) 
{
    for (int i = 0; input[i] != '\0'; i++){
        if (input[i] == ' ' || input[i] == '-' || isdigit(input[i])){
            return false;
        }
    }
    return true;
}
//given struct
typedef struct student{
    int id;
    char name[32];
    char phone[16];
    char address[128];
} student_t;

int main(){
    char nameInput[32];
    char phoneInput[16];
    char addressInput[128];
    char entryInput[32];
    list<string> nameList;
    ofstream writeFile ("students");
    if (writeFile.is_open())
    {
        //initialize a student struct to write in the file
        student input;
        input.id = 0;
        bool loopCheck = true;
        while (loopCheck)
        {
            //we take in the entire line in case you want last names, i.e. Corey Hom will be valid.
            cout << "Name >> ";
            //Make sure the most you can take in is 32 chars because of the array size given
            if (fgets(nameInput, 32, stdin)){
                //have to remove the new line at the end of the input
                nameInput[strlen(nameInput) -1] = '\0';
            }
            //We copy the array into input.name so that we can check if it is valid.
            copy(begin(nameInput), end(nameInput), begin(input.name));
            
            //CONVERT TO A STRING, STORE IN A LIST, EASY WAY TO FIND NAMES.
            string str(nameInput);
            //SEARCH THE LIST FIRST BEFORE STORING THE NAME IN IT.
            bool findName = find(nameList.begin(), nameList.end(), nameInput) != nameList.end();
            //cout << findName << endl;
            //IF A NAME IS FOUND, YOU WILL BE PROMPTED FOR A NEW ENTRY.
            if(findName)
            {
                cout << "Is this a new entry?(y/n)" << endl;
                if (fgets(entryInput, 32, stdin)){
                    entryInput[strlen(entryInput) -1] = '\0';
                }
                if (entryInput[0] == 'y')
                {
                    nameList.push_back((nameInput));
                    if (isLetter(input.name))
                    {
                        cout << "Name should only be letters (caps allowed)." << endl;
                    }
                    else
                    {
                        //we do the same thing for phone input, except check for digits, dashes, and spaces.
                        bool loopCheck2 = true;
                        while (loopCheck2){
                            cout << "Phone >> ";
                            if (fgets(phoneInput, 16, stdin)){
                                phoneInput[strlen(phoneInput) -1] = '\0';
                            }
                            copy(begin(phoneInput), end(phoneInput), begin(input.phone));
                            if (isPhone(input.phone))
                            {
                                cout << "Number checked for only digits, spaces, and dashes. Please try again!" << endl;
                            }
                            else {
                                //Instructions don't indicate that address has any restrictions.
                                cout << "Address >> ";
                                if (fgets(addressInput, 128, stdin)){
                                    addressInput[strlen(addressInput) -1] = '\0';
                                }
                                copy(begin(addressInput), end(addressInput), begin(input.address));
                                //WRITE IN ALL VALID INPUTS
                                writeFile << "Name >> " << input.name << endl;
                                writeFile << "Phone >> " << input.phone << endl;
                                writeFile << "Address >> " << input.address << endl;
                                writeFile << "Record Created with id: >> " << input.id << endl;
                                writeFile << endl;
                                
                                //Clear all the arrays for future input.
                                memset(&nameInput[0], 0, sizeof(nameInput));
                                memset(&phoneInput[0], 0, sizeof(phoneInput));
                                memset(&addressInput[0], 0, sizeof(addressInput));
                                memset(&input.name[0], 0, sizeof(input.name));
                                memset(&input.phone[0], 0, sizeof(input.phone));
                                memset(&input.address[0], 0, sizeof(input.address));
                                input.id++;
                                loopCheck2 = false;
                            }
                        }
                    }
                    
                    //QUIT PROMPT
                    char quitInput[32];
                    cout << "Quit(y/n)? >> ";
                    if (fgets(quitInput, 32, stdin)){
                        quitInput[strlen(quitInput) -1] = '\0';
                    }
                    if (quitInput[0] == 'y')
                    {
                        loopCheck = false;
                    }
                    //Clear the input so that we can go again if you choose to do so.
                    cin.sync();
                }
            }
            //SAME CODE AS ABOVE. IT JUST MEANS THAT YOU DIDN'T FIND A NAME IN THE LIST, SO REGULAR PROTOCOL ANYWAY.
            else{
                nameList.push_back((nameInput));
                if (isLetter(input.name))
                {
                    cout << "Name should only be letters (caps allowed)." << endl;
                }
                else
                {
                    //we do the same thing for phone input, except check for digits, dashes, and spaces.
                    bool loopCheck2 = true;
                    while (loopCheck2){
                        cout << "Phone >> ";
                        if (fgets(phoneInput, 16, stdin)){
                            phoneInput[strlen(phoneInput) -1] = '\0';
                        }
                        copy(begin(phoneInput), end(phoneInput), begin(input.phone));
                        if (isPhone(input.phone))
                        {
                            cout << "Number checked for only digits, spaces, and dashes. Please try again!" << endl;
                        }
                        else {
                            //Instructions don't indicate that address has any restrictions.
                            cout << "Address >> ";
                            if (fgets(addressInput, 128, stdin)){
                                addressInput[strlen(addressInput) -1] = '\0';
                            }
                            copy(begin(addressInput), end(addressInput), begin(input.address));
                            //WRITE IN ALL VALID INPUTS
                            writeFile << "Name >> " << input.name << endl;
                            writeFile << "Phone >> " << input.phone << endl;
                            writeFile << "Address >> " << input.address << endl;
                            writeFile << "Record Created with id: >> " << input.id << endl;
                            writeFile << endl;
                            
                            //Clear all the arrays for future input.
                            memset(&nameInput[0], 0, sizeof(nameInput));
                            memset(&phoneInput[0], 0, sizeof(phoneInput));
                            memset(&addressInput[0], 0, sizeof(addressInput));
                            memset(&input.name[0], 0, sizeof(input.name));
                            memset(&input.phone[0], 0, sizeof(input.phone));
                            memset(&input.address[0], 0, sizeof(input.address));
                            input.id++;
                            loopCheck2 = false;
                        }
                    }
                }
                
                //QUIT PROMPT
                char quitInput[32];
                cout << "Quit(y/n)? >> ";
                if (fgets(quitInput, 32, stdin)){
                    quitInput[strlen(quitInput) -1] = '\0';
                }
                if (quitInput[0] == 'y')
                {
                    loopCheck = false;
                }
                //Clear the input so that we can go again if you choose to do so.
                cin.sync();
            }
        }
    }
    writeFile.close();
}