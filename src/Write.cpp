#include<bits/stdc++.h>
#include<conio.h>
#include "Write.h"
using namespace std;

Write::Write() {}
void patient::write_patient_details(string name,string password,string id,int idnumber,int age,string gender,string address)
{
    ifstream file;
    string filename="C:\\Users\\Masum\\Desktop\\Login\\";
    string filename1="C:\\Users\\Masum\\Desktop\\Login\\Data\\";
    filename=filename+id+".txt";
    filename1=filename1+id+".txt";
    cout<<"\nYour id is: ";
    cout<<id<<endl;
    cout<<"*Use this for login.\n"<<endl;
    file.open(filename);
    if(file)
    {
        patient_registration();
    }
    else
    {
        file.close();
        ofstream file1;
        file1.open(filename);
        file1<<password<<endl;
        file1<<name<<endl;
        file1<<gender<<endl;
        file1<<age<<endl;
        file1<<address<<endl;
        file1<<id<<endl;
        file1<<idnumber<<endl;
        file1<<"f_b"<<endl;
        file1.close();
        ofstream file2;
        file2.open(filename1);
        file2<<"f_b"<<endl;
        file2.close();
    }
}
void patient::write_date(string filename,string doctorname)
{
    string det[100],temps,temp;
    string tempd=doctorname;
    doctorname="d_n"+doctorname;
    ifstream file;
    file.open(filename);
    getline(file,temps);
    tempd.erase(tempd.begin());
    cout<<"  __"<<tempd<<"__\n"<<endl;
    int i=0;
    while(temps!="f_b")
    {
        det[i++]=temps;
        if(temps==doctorname)
        {
            cout<<"Enter Date: ";
            cin>>temps;
            det[i++]=temps;
            getline(cin,temp);
            write_odprescription(filename,tempd,temps);
        }
        getline(file,temps);
    }
    det[i++]=temps;
    file.close();
    ofstream file1;
    file1.open(filename);
    int k=0;
    while(k<i)
    {
        file1<<det[k++]<<endl;
    }
    file1.close();
}
void patient::write_doctorename_date(string filename)
{
    string det[100],temps,temp,doctorname;
    ifstream file;
    cout<<"\n  __Write__\n"<<endl;
    cout<<"Enter Doctor's Name: ";
    getline(cin,temp);
    file.open(filename);
    getline(file,temps);
    int i=0;
    while(temps!="f_b")
    {
        det[i++]=temps;
        if(temps=="d_n "+temp)
        {
            temp=" "+temp;
            write_date(filename,temp);
            return;
        }
        getline(file,temps);
    }
    file.close();
    det[i++]="d_n "+temp;
    doctorname=temp;
    cout<<"Enter Date: ";
    cin>>temps;
    getline(cin,temp);
    det[i++]=temps;
    det[i++]="d_b";
    det[i++]="f_b";
    ofstream file1;
    file1.open(filename);
    int k=0;
    while(k<i)
    {
        file1<<det[k++]<<endl;
    }
    file1.close();
    write_ndprescription(filename,doctorname,temps);
}
void patient::write_ndprescription(string filename,string doctorname,string date)
{
    string det[2000];
    ifstream file;
    file.open(filename);
    getline(file,det[0]);
    getline(file,name);
    getline(file,gender);
    file>>age;
    getline(file,address);
    getline(file,address);
    getline(file,det[0]);
    file.close();
    filename="C:\\Users\\Masum\\Desktop\\Login\\Data\\"+det[0]+".txt";
    ifstream file1;
    file1.open(filename);
    int i=0;
    getline(file1,det[i]);
    while(det[i++]!="f_b")
    {
        getline(file1,det[i]);
    }
    i--;
    file1.close();
    det[i++]="d_n "+doctorname;
    det[i++]=date;
    det[i++]="Doctor Name: "+doctorname+"  Date: "+date;
    det[i++]="Patient Name: "+name+"  Gender: "+gender+"  Age: "+to_string(age)+"  Address: "+address;
    cout<<"BP: ";
    cin>>det[i];
    det[i]="BP: "+det[i];
    i++;
    cout<<"Temperature: ";
    cin>>det[i];
    det[i-1]=det[i-1]+"  Temperature: "+det[i];
    cout<<"No of Medicine: ";
    int x;
    cin>>x;
    getline(cin,det[i+1]);
    for(int j=1; j<=x; j++)
    {
        cout<<"Medicine ("<<j<<"): ";
        getline(cin,det[i]);
        det[i]="Medicine: "+det[i];
        i++;
    }
    cout<<"No of Test: ";
    cin>>x;
    getline(cin,det[i+1]);
    for(int j=1; j<=x; j++)
    {
        cout<<"Test ("<<j<<"): ";
        getline(cin,det[i]);
        det[i]="Test: "+det[i];
        i++;
    }
    det[i++]="p_b";
    det[i++]="d_b";
    det[i++]="f_b";
    ofstream file2;
    file2.open(filename);
    int k=0;
    while(k<i)
    {
        file2<<det[k++]<<endl;
    }
    file2.close();
    cout<<endl;
}
void patient::write_odprescription(string filename,string doctorname,string date)
{
    string det[2000],temp;
    ifstream file;
    file.open(filename);
    getline(file,det[0]);
    getline(file,name);
    getline(file,gender);
    file>>age;
    getline(file,address);
    getline(file,address);
    getline(file,det[0]);
    file.close();
    filename="C:\\Users\\Masum\\Desktop\\Login\\Data\\"+det[0]+".txt";
    ifstream file1;
    file1.open(filename);
    int i=0;
    getline(file1,det[i]);
    while(det[i]!="f_b")
    {
        if(det[i]=="d_n "+doctorname)
        {
            i++;
            det[i++]=date;
            det[i++]="Doctor Name: "+doctorname+"  Date: "+date;
            det[i++]="Patient Name: "+name+"  Gender: "+gender+"  Age: "+to_string(age)+"  Address: "+address;
            cout<<"BP: ";
            cin>>det[i];
            det[i]="BP: "+det[i];
            i++;
            cout<<"Temperature: ";
            cin>>det[i];
            det[i-1]=det[i-1]+"  Temperature: "+det[i];
            cout<<"No of Medicine: ";
            int x;
            cin>>x;
            getline(cin,det[i+1]);
            for(int j=1; j<=x; j++)
            {
                cout<<"Medicine ("<<j<<"): ";
                getline(cin,det[i]);
                det[i]="Medicine: "+det[i];
                i++;
            }
            cout<<"No of Test: ";
            cin>>x;
            getline(cin,det[i+1]);
            for(int j=1; j<=x; j++)
            {
                cout<<"Test ("<<j<<"): ";
                getline(cin,det[i]);
                det[i]="Test: "+det[i];
                i++;
            }
            det[i]="p_b";
        }
        i++;
        getline(file1,det[i]);
    }
    file1.close();
    ofstream file2;
    file2.open(filename);
    int k=0;
    while(k<=i)
    {
        file2<<det[k++]<<endl;
    }
    file2.close();
    cout<<endl;
}
