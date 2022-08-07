#include<bits/stdc++.h>
#include<conio.h>
#include "login.h"
using namespace std;

login::login(){}
void patient::patient_login()
{
    string filename="C:\\Users\\Masum\\Desktop\\Login\\";
    string temps;
    cout<<"Enter Patient Id: ";
    cin>>id;
    cout<<"Enter Password: ";
    cin>>password;
    filename=filename+id+".txt";
    ifstream file;
    file.open(filename);
    if(file)
    {
        string temppassword;
        file>>temppassword;
        if(password!=temppassword)
        {
            cout<<"*Incorrect Password. Try again.\n"<<endl;
            patient_login();
        }
        else
        {
            cout<<"*LogIn Successful.\n"<<endl;
            getline(cin,temps);
            home_page(filename);
        }
    }
    else
    {
        cout<<"*Invalid User Name or Password. Try again.\n"<<endl;
        patient_login();
    }
}
