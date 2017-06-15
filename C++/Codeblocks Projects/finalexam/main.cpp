#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Confused about how to determine withdraw success without allowing each BankAccount to know
// the Bank's total funds if the withdraw method is part of BankAccount instead of Bank
// I think if the withdraw and deposit were methods of Bank instead it would be easier

class BankAccount
{
public:
    double balance;
    bool accountOpen;
    int accountNumber;
    int interestPeriod;
    double interestRate;
    int bankID;
    int day;
    float banksFunds = 0;



    BankAccount();
    BankAccount(double initialBalance, double initialRate, int setID);





bool makeWithdraw(double withdrawAmount);



    void makeDeposit(double depositAmount)
    {
        balance += depositAmount;
    }

    double getBalance()
    {
        return balance;
    }


    void moveTime(int days)
    {
        day += days;
    }

    void setRate(double dailyrate)
    {
        interestRate = dailyrate;
    }

    double close()
    {
        accountOpen = false;
        balance = 0;

        // withdraws full balance if any
    }

    int getbankID()
    {
        return bankID;
    }

    void transferTo(BankAccount destination, double money)
    {
        // transfers money from current bankaccount to destination bankaccount
    }

    void assignBankID(int assignID)
    {
        bankID = assignID;
    }

    void assignAccountNumber(int assignNumber)
    {
        accountNumber = assignNumber;
    }

    bool getStatus()
    {
        return accountOpen;
    }


private:

    double banksBalance;


};


class Bank
{
public:
    int totalBanks = 0;
    int banksID;
    vector<BankAccount> Accounts;
    double totalDeposits;
    double profit;

    // Constructor
    Bank()
    {
        totalBanks++;
        banksID = totalBanks - 1;
        totalDeposits = 0;
        profit = 0;
    }



    void addAccount(BankAccount &acc)
    {
        Accounts.push_back(acc);
        acc.assignBankID(banksID);
        acc.assignAccountNumber(Accounts.size()+1);
        totalDeposits += acc.getBalance();
        Accounts.push_back(acc);
    }


    double getProfit()
    {
        return profit;
    }

    void printBankAccounts()
    {
        for (int i = 0; i != Accounts.size(); i++)
        {
            cout << "Account number: " << i + 1 << endl;
            cout << "  balance: " << Accounts[i].getBalance() << endl;
            cout << "  status: " << Accounts[i].getStatus() << endl;
        }
    }

    int getbanksID()
    {
        return banksID;
    }




    void bankWithdraw()
    {




    }




};

bool BankAccount::makeWithdraw(double withdrawAmount)
{

    if (accountOpen && withdrawAmount <= balance)
    {








        return true;
    }
    else
        return false;
}




    // Default constructor
    BankAccount::BankAccount()
    {
        accountOpen = true;
        balance = 0.00;
        interestRate = 0.0;
        bankID = 0;
        day = 1;
        Bank.addAccount();
    }

    // Constructor with parameters
    BankAccount::BankAccount(double initialBalance, double initialRate, int setID)
    {
        accountOpen = true;
        balance = initialBalance;
        interestRate =  initialRate;
        bankID = setID;
        day = 1;
        Bank.addAccount();
    }














int main()
{
    return 0;
}
