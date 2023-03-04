#include<bits/stdc++.h>
using namespace std;

string dt(){
    time_t now = time(0);
	tm *ltm = localtime(&now);
	int y = 1900 + ltm->tm_year;
	int m = 1 + ltm->tm_mon;
	int d =  ltm->tm_mday ;
	string date = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
	return date;
}

string kID(string ln, string fn){
    string str=ln.substr(0,3) + fn.substr(0,3);
    return str;
}

struct emp{
    string fn, status, ln, dob, ttl, startDate, endDate, kerberos, Status;
};

string status(string date){
    int dt=stoi(date.substr(6, 9));
    if(dt>8000){
        return "Active";
    }
    return "Inactive";
}

void addEmployeeInput(string &firstName, string &lastName, string &dateOfBirth, string &title) {

cout<<"First name of employee: "<<endl;
cin>>firstName;
cout<<"Last name of employee: "<<endl;
cin>>lastName;
cout<<"DOB of employee: "<<endl;
cin>>dateOfBirth;
cout<<"Title of employee: "<<endl;
cin>>title;
}


void addEmployee(string firstName, string lastName, string dateOfBirth, string title, vector<emp> &empl) {
    
string date= dt();
string kerbero = kID(lastName, firstName);
emp e;
e.fn=firstName;
e.ln=lastName;
e.dob=dateOfBirth;
e.ttl=title;
e.startDate=date;
e.endDate="30/12/9000";
e.kerberos=kerbero;
e.Status=status("30/12/9000");
empl.push_back(e);
cout<<"Employee added"<<endl;
cout<<"kerberosID: "<<kerbero<<endl;
}


void filter(int filterChoice, vector<emp> empl) {
string title;
if(filterChoice==1){
        cout<<"Kerberos       Name                   Department"<<endl;
}
if(filterChoice==2){
        cout<<"Enter Department: ";
        cin>>title;
        cout<<"Kerberos       Name                   Status"<<endl;
}
vector<emp>::iterator p;

for(p=empl.begin(); p!=empl.end(); ++p){
    if(filterChoice==1){
        if(status(p->endDate)=="Active"){
            cout<<p->kerberos<<"         "<<p->fn<<" "<<p->ln<<"         "<<p->ttl<<endl<<endl;
        }
    }
    else if(filterChoice==2){
        if(p->ttl == title){
            cout<<p->kerberos<<"         "<<p->fn<<" "<<p->ln<<"          "<<p->Status<<endl<<endl;4
        }
    }
    else{
        cout<<"Invalid choice"<<endl;
    }
}
}


void searchEmployee(string kerberos, vector<emp> empl) {
for (vector<emp>::iterator p = empl.begin(); p != empl.end(); ++p){
    if(p->kerberos==kerberos){
        cout<<p->fn<<" "<<p->ln<<endl<<"Dept: "<<p->ttl<<endl<<"Status: "<<p->Status;
        return;
    }
}
cout<<"Invalid Kerbero ID"<<endl; 
}


void terminate(string kerberos, vector<emp> &empl) {
vector<emp>::iterator p;
for(p=empl.begin(); p!=empl.end(); ++p){
    if(p->kerberos==kerberos){
        p->endDate=dt();
        p->Status="Inactive";
        cout<<"Employee terminated"<<endl;
        return;
    }
}
cout<<"Invalid Kerbero ID"<<endl;
}


int main() {
    vector<emp> empl;
    int choice;
cout<<"\n------------------Employee Management----------------------"<<endl;
do{
cout<<"\nPress 1 to Add an Employee\n"<<endl;
cout<<"Press 2 to Search an Employee\n"<<endl;
cout<<"Press 3 to Filter Employees\n"<<endl;
cout<<"Press 4 to Terminate an Employee\n"<<endl;
cout<<"Press 5 to Exit\n"<<endl;

cin>>choice;
string firstName,lastName, dateOfBirth, title, kerberos;

switch(choice) {
case 1:
addEmployeeInput(firstName, lastName, dateOfBirth, title);
addEmployee(firstName, lastName, dateOfBirth, title, empl);
break;
case 2:
cout<<"Enter a kerberos id to search: "<<endl;
cin>>kerberos;
searchEmployee(kerberos, empl);
break;
case 3:
cout<<"Press 1 to filter by isActive as of a date\n"<<endl;
cout<<"Press 2 to filter by title\n"<<endl;
int filterChoice;
cin>>filterChoice;
filter(filterChoice, empl);
break;
case 4:
cout<<"Enter a kerberos id to terminate: "<<endl;
cin>>kerberos;
terminate(kerberos, empl);
break;
case 5:
break;
default:
cout<<"Please select a valid choice"<<endl;
break;
}
}while (choice!=5);
}