#include<bits/stdc++.h>
#include<conio.h>
#include "registration.h"
#include "login.h"

using namespace std;

int main()
{
    registration r;
    login l;
    cout<<"  ***Welcome***"<<endl;
    while(1)
    {
        char x;
        cout<<"1.Registration"<<endl;
        cout<<"2.LogIn"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Select your option.."<<endl;
        x=_getch();
        if(x=='1')
        {
            cout<<"\n  __Registration__\n"<<endl;
            r.patient_registration();
        }
        else if(x=='2')
        {
            cout<<"\n  __Login__\n"<<endl;
            l.patient_login();
        }
        else if(x=='3')
        {
            cout<<"*You have successfully exit.."<<endl;
            cout<<"*Thank You.."<<endl;
            break;
        }
        else
            cout<<"*Invalid Input.."<<endl;
    }
    system("pause");
    return 0;
}
