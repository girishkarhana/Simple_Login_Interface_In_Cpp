#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string Name,userName,Email,password,DOB;
    string searchNmae,searchUName,searchPass,searchEmail,searchDOB;
    fstream file;
    public:
    void login();
    void signup();
    void forget();
}obj;

int main()
{
    char choice;
    cout<<"\n1-Login";
    cout<<"\n2-signup";
    cout<<"\n3-Forget Password";
    cout<<"\n4-exit";
    cout<<"\n enter your choice ::";
    cin>>choice;

    switch(choice){
        case '1':
        cin.ignore(); //skip character in the input buffer
        obj.login();
        break;
        case '2':
        cin.ignore();
        obj.signup();
        break;
        case '3':
        cin.ignore();
        obj.forget();
        break;
        case '4':
        return 0;
        break;
        default:
        cout<<"Invalid selection........";
    }
}
void temp :: signup(){
    cout<<"Enter your Name ::";
    getline(cin,Name);//to take input with space
    cout<<"Enter username ::";
    getline(cin,userName);//to take input with space
    cout<<"Enter Your Date of Birth ::";
    getline(cin,DOB);
    cout<<"Enter Your Email address ::";
    getline(cin,Email);
    cout<<"Enter your Password ::";
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<Name<<"*"<<userName<<"*"<<DOB<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}
    void temp::login() {
    cout << "-----DETAILS-----";
    cout << "\nEnter Name ::";
    getline(cin, searchUName);
    cout << "Enter your Email ::";
    getline(cin, searchEmail);
    cout << "Enter Password ::";
    cin >> searchPass;
    cin.ignore(); // skip character in the input buffer

    file.open("loginData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    bool found = false;
    while (file) {
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '*');
        getline(file, Name);

        if (file && userName == searchUName && Email == searchEmail && password == searchPass) {
            cout<<"\n\n--------Login Succesfull--------"<<endl;
            cout<<"Name ::"<<Name<<endl;
            cout<<"Username ::"<<userName<<endl;
            cout<<"User Email ::"<<Email<<endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Invalid details......." << endl;
    }

    file.close();
}
 void temp::forget() {
    cout << "-----DETAILS-----";
    cout << "\nEnter Name ::";
    getline(cin, searchUName);
    cout << "Enter your Email ::";
    getline(cin, searchEmail);
    cout << "Enter DOB ::";
    cin >> searchDOB;
    cin.ignore(); // skip character in the input buffer

    file.open("loginData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    bool found = false;
    while (file) {
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, DOB, '*');
        getline(file, password);

        if (file && userName == searchUName && Email == searchEmail && DOB == searchDOB) {
            cout<<"\n\n--------Login Succesfull--------"<<endl;
            cout<<"Username ::"<<userName<<endl;
            cout<<"User Email ::"<<Email<<endl;
            cout<<"Password ::"<<password<<endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Invalid details......." << endl;
    }

    file.close();
}

