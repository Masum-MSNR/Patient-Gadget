#include<bits/stdc++.h>
#ifndef PATIENT_H
#define PATIENT_H
using namespace std;

class patient
{
    string name,gender,address,id,password;
    int idnumber,age;
public:
    patient();
    void patient_login();
    void patient_registration();
    void write_patient_details(string,string,string,int,int,string,string);
    void home_page(string);
    void Prescriptions(string);
    void choice(string,string);
    void doctors_list(string);
    void patient_details(string);
    void date_list(string,string);
    void tests(string);
    void write_odprescription(string,string,string);
    void write_ndprescription(string,string,string);
    void write_doctorename_date(string);
    void write_date(string,string);
    void read_prescription(string,string,string);
};

#endif // PATIENT_H
