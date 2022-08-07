#include<bits/stdc++.h>
#include<conio.h>
#include "listc.h"
using namespace std;

listc::listc(){}
void patient::home_page(string filename)
{
    while(1)
    {
        cout<<"  __Home Page__\n"<<endl;
        cout<<"1.Prescriptions"<<endl;
        cout<<"2.Tests"<<endl;
        cout<<"3.Details"<<endl;
        cout<<"0.Logout"<<endl;
        cout<<"Select your option..\n"<<endl;
        char x;
        x=_getch();
        if(x=='1')
        {
            Prescriptions(filename);
        }
        else if(x=='2')
        {
            tests(filename);
        }
        else if(x=='3')
        {
            patient_details(filename);
        }
        else
            break;
    }

}
void patient::Prescriptions(string filename)
{
    while(1)
    {
        cout<<"  __Prescriptions__\n"<<endl;
        cout<<"1.Old Prescriptions"<<endl;
        cout<<"2.Add New One"<<endl;
        cout<<"0.Back"<<endl;
        cout<<"Select your option..\n"<<endl;
        char x;
        x=_getch();
        if(x=='1')
        {
            doctors_list(filename);
        }
        else if(x=='2')
        {
            write_doctorename_date(filename);
        }
        else
            break;
    }
}
void patient::doctors_list(string filename)
{
    while(1)
    {
        string doctor_name[100],temps;
        ifstream file;
        file.open(filename);
        file>>temps;
        int i=0;
        cout<<"  __Doctors list__\n"<<endl;
        while(temps!="f_b")
        {
            if(temps=="d_n")
            {
                getline(file,doctor_name[i++]);
            }
            file>>temps;
        }
        for(int j=0; j<i; j++)
        {
            cout<<j+1<<".";
            int x=doctor_name[j].size();
            for(int i=1; i<x; i++)
            {
                cout<<doctor_name[j][i];
            }
            cout<<endl;
        }
        file.close();
        cout<<"0.Back"<<endl;
        cout<<"Select your option..\n"<<endl;
        char check;
        check=_getch();
        if(check!='0')
        {
            choice(filename,doctor_name[check-'0'-1]);
        }
        else
            break;
    }
}
void patient::choice(string filename,string doctorname)
{
    string tempd=doctorname;
    tempd.erase(tempd.begin());
    while(1)
    {
        cout<<"  __"<<tempd<<"__\n"<<endl;
        cout<<"1.Read Old Prescriptions"<<endl;
        cout<<"2.Add New"<<endl;
        cout<<"0.Back"<<endl;
        cout<<"Select your option..\n"<<endl;
        char check;
        check=_getch();
        if(check=='1')
        {
            date_list(filename,doctorname);
        }
        else if(check=='2')
        {
            write_date(filename,doctorname);
        }
        else
            break;
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
    cout<<"\n  __Date of Prescriptions__\n"<<endl;
    for(int j=0; j<i; j++)
        cout<<j+1<<"."<<date[j]<<endl;
    cout<<"0.Back"<<endl;
    cout<<"Select your option..\n"<<endl;
    x=_getch();
    if(x=='0')
        return;
    read_prescription(filename,doctorname,date[x-'0'-1]);
}
