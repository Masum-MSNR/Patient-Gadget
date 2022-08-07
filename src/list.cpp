#include<bits/stdc++.h>
#include<conio.h>
#include "list.h"
using namespace std;

list::list()
{
    //ctor
}
void patient::doctor_list(string filename)
{
    string doctor_name[100],temps;
    ifstream file;
    file.open(filename);
    file>>temps;
    int i=0;
    cout<<"***Doctors list***"<<endl;
    while(temps!="f_b")
    {
        if(temps=="d_n")
        {
            getline(file,doctor_name[i++]);
        }
        file>>temps;
    }
    for(int j=0;j<i;j++)
        cout<<j+1<<"."<<doctor_name[j]<<endl;
    file.close();
    cout<<0<<"."<<" New"<<endl;
    cout<<"Select your option.."<<endl;
    char check;
    check=_getch();
    if(check!='0')
    {
        cout<<1<<".Read"<<endl;
        cout<<2<<".Write"<<endl;
        char check1;
        int x=check-'0';
        check1=_getch();
        if(check1=='1')
        {
            date_list(filename,doctor_name[x-1]);
        }
        else
        {
            write_newd(filename,doctor_name[x-1]);
        }
    }
    else
    {
        write_dnd(filename);
    }
}
void patient::date_list(string filename,string doctorname)
{
    string date[100],temps;
    char x;
    ifstream file;
    file.open(filename);
    file>>temps;
    int i=0;
    while(temps!="f_b")
    {
        if(temps=="d_n")
        {
            getline(file,temps);
            if(temps==doctorname)
            {
                while(1)
                {
                    getline(file,temps);
                    if(temps=="d_b")
                        break;
                    date[i++]=temps;
                }
                break;
            }
        }
        file>>temps;
    }
    file.close();
    for(int j=0;j<i;j++)
        cout<<j+1<<"."<<date[j]<<endl;
    x=_getch();
    read_pp(filename,doctorname,date[x-1]);
}
