#include<bits/stdc++.h>
#include "registration.h"
using namespace std;

registration::registration(){}
void patient::patient_registration()
{
    cout<<"  __Enter Your Details__\n"<<endl;
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Gender: ";
    cin>>gender;
    cout<<"Age: ";
    cin>>age;
    getline(cin,address);
    cout<<"Address: ";
    getline(cin,address);
    cout<<"Password: ";
    cin>>password;
    ifstream file;
    file.open("C:\\Users\\Masum\\Desktop\\Login\\idnumber.txt");
    file>>idnumber;
    file.close();
    ofstream file1;
    file1.open("C:\\Users\\Masum\\Desktop\\Login\\idnumber.txt");
    file1<<idnumber+1<<endl;
    file1.close();
    char tempca[20];
    int i=0,j;
    if(name[0]=='M'&&name[1]=='d'&&name[2]==' ')
    {
        name.erase(name.begin(),name.begin()+3);
    }
    j=name.size();
    while(name[i]!=' '&&i<j)
    {
        tempca[i]=name[i];
        i++;
    }
    string temps(tempca,tempca+i);
    id=temps+to_string(idnumber);
    cout<<"\n*Registration successful."<<endl;
    write_patient_details(name,password,id,idnumber,age,gender,address);
}
