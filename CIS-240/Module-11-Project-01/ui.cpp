#include <iostream>
#include <iomanip>

#include "accounts.h"
#include "tellers.h"
#include "ui.h"

using namespace std;

int GetNumberFromUser(int minValue, int maxValue){
    int value;
    
    do{
        cout << "=>";
        cin >> value;
    } while(value <= minValue || value >= maxValue);

    return value;
}

bool LoginUser(){
    string username;
    string password;

    cout << "Username:";
    cin >> username;
    cout << "Password:";
    cin >> password;

    return Login(username, password);
}

void AddAccount(){
    string accountNumber{""};
    cout << "Account Number: ";
    cin >> accountNumber;
    
    if(IsValidAccount(accountNumber)){
        cout <<"Account number already exists" << endl;
        return;
    }

    string ssn {""};
    string name {""};
    string address {""};
    string phone {""};

    cout << "SSN: ";
    ssn = SafeGetLine();
    cout << "Name: ";
    name = SafeGetLine();
    cout << "Address: ";
    address = SafeGetLine();
    cout << "Phone: ";
    phone = SafeGetLine();

    AddAccount(accountNumber, ssn, name, address, phone);
}

void DeleteAccount(){
    string accountNumber {""};
    cout << "Account Number: ";
    cin >> accountNumber;

    if(!IsValidAccount(accountNumber)){
        cout<<"Account not found" << endl;
        return;
    }

    DeleteAccount(accountNumber);
    cout<<"Account deleted" <<endl;
}

void UpdateAccount(){
    string accountNumber {""};
    cout << "Account Number: ";
    cin >> accountNumber;

    if(!IsValidAccount(accountNumber)){
        cout<<"Account not found" << endl;
        return;
    }

    string name {""};

    cout << "Name: ";
    name = SafeGetLine();
    
    UpdateAccount(accountNumber, name);
    cout<<"Account updated" <<endl;
}

void ViewAccount(){
    string accountNumber{""};
    cout << "Account Number: ";
    cin >> accountNumber;
    
    if(!IsValidAccount(accountNumber)){
        cout<<"Account not found" << endl;
        return;
    }

    string ssn {""};
    string name {""};
    string address {""};
    string phone {""};

    GetAccount(accountNumber, ssn, name, address, phone);

    cout << setw(10) << right << "SSN: " << ssn << endl;
    cout << setw(10) << right << "Name: " << name << endl;
    cout << setw(10) << right << "Address: " << address << endl;
    cout << setw(10) << right << "Phone: " << phone << endl;
    cout << setw(10) << right << "Balance: " << setprecision(2) << fixed << GetBalance(accountNumber) << endl;
}

void Deposit(){
    string accountNumber{""};
    cout << "Account Number: ";
    cin >> accountNumber;
    
    if(!IsValidAccount(accountNumber)){
        cout<<"Account not found" << endl;
        return;
    }

    float currentBalance = GetBalance(accountNumber);
    float depositAmount {0.0};
    
    cout<< "Current Balance: " << setprecision(2) << fixed << currentBalance << endl;
    cout<< "Deposit Amount: ";
    cin >> depositAmount;
    UpdateBalance(accountNumber, currentBalance+depositAmount);
    cout << "Balance Updated: " << setprecision(2) << fixed << GetBalance(accountNumber) << endl;
}

void Withdraw(){
    string accountNumber{""};
    cout << "Account Number: ";
    cin >> accountNumber;
    
    if(!IsValidAccount(accountNumber)){
        cout<<"Account not found" << endl;
        return;
    }

    float currentBalance = GetBalance(accountNumber);
    float widthdrawAmount {0.0};
    
    cout<< "Current Balance: " << setprecision(2) << fixed << currentBalance << endl;
    cout<< "Deposit Amount: ";
    cin >> widthdrawAmount;
    UpdateBalance(accountNumber, currentBalance - widthdrawAmount);
    cout << "Balance Updated: " << setprecision(2) << fixed << GetBalance(accountNumber) << endl;
}

void AccountMenu(){
    enum OPTIONS {
        MIN = 0,
        ADD,
        DELETE,
        UPDATE,
        VIEW,
        DEPOSIT,
        WITHDRAW,
        RETURN,
        MAX
    };

    int value;
    do{
        cout << OPTIONS::ADD    << "- Add account" << endl;
        cout << OPTIONS::DELETE << "- Delete account" <<endl;
        cout << OPTIONS::UPDATE << "- Update account" << endl;
        cout << OPTIONS::VIEW << "- View account" << endl;
        cout << OPTIONS::DEPOSIT << "- Deposit" << endl;
        cout << OPTIONS::WITHDRAW << "- Withdraw" << endl;
        cout << OPTIONS::RETURN << "- Return" << endl;
        value = GetNumberFromUser(OPTIONS::MIN, OPTIONS::MAX);

        switch(value){
            case OPTIONS::ADD:
                AddAccount();
                break;
            case OPTIONS::DELETE:
                DeleteAccount();
                break;
            case OPTIONS::UPDATE:
                UpdateAccount();
                break;
            case OPTIONS::VIEW:
                ViewAccount();
                break;
            case OPTIONS::DEPOSIT:
                Deposit();
                break;
            case OPTIONS::WITHDRAW:
                Withdraw();
                break;
        }
 
    } while(value != OPTIONS::RETURN);

}

void MainMenu(){
    enum OPTIONS {
        MIN = 0,
        LOGIN =1,
        EXIT =2,
        MAX
    };

    int value;
    do{
        cout <<OPTIONS::LOGIN <<" - Login" << endl;
        cout <<OPTIONS::EXIT  <<" - Exit " << endl;

        value = GetNumberFromUser(OPTIONS::MIN, OPTIONS::MAX);
        switch(value){
            case OPTIONS::LOGIN:
                if(LoginUser()){
                    AccountMenu();
                } else{
                    cout <<"Invalid Login" << endl;
                }
                break;
        }
    }while(value != OPTIONS::EXIT);
}

string SafeGetLine(){
    cin.ignore(std::numeric_limits<int>::max(), '\n');
    string value {""};
    getline(cin, value);
    return value;
}