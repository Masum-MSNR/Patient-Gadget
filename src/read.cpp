#include<bits/stdc++.h>
#include<conio.h>
#include "read.h"
using namespace std;

read::read(){}
void patient::read_prescription(string filename,string doctorname,string date)
{
    string temps;
    doctorname="d_n"+doctorname;
    ifstream file;
    file.open(filename);
    getline(file,temps);
    getline(file,temps);
    getline(file,temps);
    getline(file,temps);
    getline(file,temps);
    getline(file,temps);
    file.close();
    filename="C:\\Users\\Masum\\Desktop\\Login\\Data\\"+temps+".txt";
    ifstream file1;
    file1.open(filename);
    getline(file1,temps);
    while(temps!="f_b")
    {
        if(temps==doctorname)
        {
            getline(file1,temps);
            while(temps!="d_b")
            {
                if(temps==date)
                {
                    getline(file1,temps);
//                    system("cls");
                    cout<<"\n  ***Here is the prescription***\n"<<endl;
                    while(temps!="p_b")
                    {
                        cout<<temps<<endl;
                        getline(file1,temps);
                    }
                    cout<<"\n*Hit enter to go back..\n"<<endl;
                    _getch();
//                    system("cls");
                    return;
                }
                getline(file1,temps);
            }
        }
        getline(file1,temps);
    }
    file1.close();
}
void patient::patient_details(string filename)
{
    ifstream file;
    file.open(filename);
    getline(file,name);
    getline(file,name);
    cout<<"  __Your Details__\n"<<endl;
    cout<<"Name: "<<name<<endl;
    file>>gender;
    cout<<"Gender: "<<gender<<endl;
    file>>age;
    cout<<"Age: "<<age<<endl;
    getline(file,address);
    getline(file,address);
    cout<<"Address: "<<address<<endl;
    file>>id;
    cout<<"Login id: "<<id<<endl;
    file.close();
    cout<<"Hit Enter to go back..\n"<<endl;
    _getch();
}
void patient::tests(string filename)
{
    string test[100],temps;
    ifstream file;
    file.open(filename);
    getline(file,temps);
    getline(file,name);
    getline(file,gender);
    file>>age;
    getline(file,address);
    getline(file,address);
    getline(file,temps);
    file.close();
    filename="C:\\Users\\Masum\\Desktop\\Login\\Data\\"+temps+".txt";
    ifstream file1;
    file1.open(filename);
    getline(file1,temps);
    file1>>temps;
    int i=0;
    cout<<"  __Tests__\n"<<endl;
    while(temps!="f_b")
    {
        if(temps=="Test:")
        {
            getline(file1,test[i++]);
        }
        file1>>temps;
    }
    for(int j=0; j<i; j++)
    {
        cout<<j+1<<".";
        int x=test[j].size();
        for(int i=1; i<x; i++)
        {
            cout<<test[j][i];
        }
        cout<<endl;
    }
    file1.close();
    cout<<"*Hit enter to go back..\n"<<endl;
    _getch();
}
