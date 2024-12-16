#include <iostream>
#include <string>
using namespace std;
class Account
{
protected:

    int accountNumber;
    string accountHolderName;
    double accountBalance;  

public:
    Account(int accNumber, string customerName, double balance=0):
    accountNumber(accNumber), accountHolderName(customerName),accountBalance(balance)
    {}
    void deposit(double amount)
    {
        accountBalance+=amount;
        cout<<"$"<<amount<< "is deposited successfuly" <<endl;
        cout<<"Current balance:"<<accountBalance<<endl;

    }
    virtual void withdraw(double amount)
    {
        accountBalance-=amount;
        cout<<"$"<<amount<< " is withdrawan" <<endl;
        cout<<"Current balance:"<<accountBalance<<endl;
    }
    void balanceStatus() const
    {
    cout<<"Total balance"<<accountBalance<<endl;
    }


};

class SavingAccount:public Account
{
    double minBalanceAmount;
public:
    SavingAccount(int accNumber, string customerName, double balance):
    Account(accNumber,customerName, balance),minBalanceAmount(100)
{
    if(accountBalance< minBalanceAmount)
    cout<<"Min balance for Saving Account is 100. Please try again!"<<endl;
}
    void withdraw(double amount)
    {   char c;
        double tempHold=accountBalance-amount;
        if(tempHold<minBalanceAmount)
        {
            cout<<"Warning!!"<<endl;
            cout<<"Account Balance will be below Min balance of $100. Penalty will be charged."<<endl;
            cout<<"Do you want to continue(Y/N)"<<endl;
            cin>>c;
            if(tolower(c)=='n')
            {
            cout<<"Withdrawan terminated!!" <<endl;
            return;
            
            }

        }
        accountBalance=tempHold;
        cout<<"$"<<amount<< "is withdrawan" <<endl;
        cout<<"Current balance:"<<accountBalance<<endl;

    }

};
class CheckingAccount:public Account
{
    
public:
    CheckingAccount(int accNumber, string customerName, double balance=0):
    Account(accNumber,customerName, balance){}

    
};

int main()
{
    SavingAccount obj1(123,"Person1",200);
    obj1.deposit(150);
    obj1.balanceStatus();
    SavingAccount obj2(456,"Person1",100);
    obj2.deposit(10);
 
    CheckingAccount obj3(678,"Person3",40);
    obj3.withdraw(10);
    return 0;
}

