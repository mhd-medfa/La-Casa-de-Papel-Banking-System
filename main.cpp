//Open this in an IDE like Codeblocks/Dev C++

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include <limits>
#include <map>
using namespace std;

std::map<int, std::string> client_types = {
        {1, "Regular Client"},
        {2, "Golden Client"},
        {3, "VIP Client"}
};

std::map<int, std::string> account_types = {
        {1, "Debit Account"},
        {2, "Credit Account"},
        {3, "Business Account"},
        {4, "Saving Account"}
};

class Bank{
    char name[50] = "Bitcoin is King";
    public:
        void setname();
        string getname();
        int total_bank_balance();

};

class Client{
    char name[100]; short client_class; string bdate;
    bool gender; short num_of_accounts; long long total_balance;
    int id;
    public:
        void create_client();
        int get_client_id(){
            return id;
        }
        short get_client_class(){
            return client_class;
        }

};


class Account{
protected:
    int account_number;
    float deposit;
    short account_type;
    int client_id;
    short client_class;
public:
    virtual bool create_account(short, int, short);	//function to get data from user
    void show_account();	//function to show data on screen
    void modify_account();   //function to get new data from user
    virtual void deposit_amount(float);	//function to accept amount and add to balance amount
    void withdraw_amount(float);	//function to accept amount and subtract from balance amount
    void account_data_in_tabular_format();	//function to show data in tabular format
    int return_account_num();	//function to return Account number
    int return_deposited_balance();	//function to return balance amount
    char return_account_type();	//function to return account_type of Account
    short get_client_class() {
        return client_class;
    }
    short get_account_type() {
        return account_type;
    }
    int get_client_id() {
        return client_id;
    }
    float get_deposit() {
        return deposit;
    }
};

class DebitAccount: public Account{
public:
};

class CreditAccount: public Account{
public:
    bool create_account(int, short);
    void withdraw_amount(float);
};

class BusinessAccount: public Account {

};

class SavingAccount: public Account {

};

void Bank::setname() {
    cout<< "Welcome to La Casa de Papel Banking System\nPlease Enter The Glorious Name Of Your Bank:" << endl;
    cin.getline(name,49);
}
string Bank::getname() {
    return name;
}
int Bank::total_bank_balance() {
    Account account;
    float total_balance=0.0;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return 0;
    }

    while(inFile.read((char *) &account, sizeof(Account)))
    {
        total_balance += account.get_deposit();
    }
    inFile.close();
    return total_balance;
}
void Client::create_client() {

    cout<<"\nEnter Client's id :";
    cin>>id;
    cout<<"\nEnter the Client's Name :";
    cin.ignore();
    cin.getline(name,49);
    cout<<"\nEnter The Client Class : ";
    cout<<"\n\n\t\t\t\t\t1. Regular Client";
    cout<<"\n\n\t\t\t\t\t2. Golden Client";
    cout<<"\n\n\t\t\t\t\t3. VIP Client";
    cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
    cin>>client_class;
    cout<<"\nEnter Client's Birthdate (dd-mm-yyyy):";
    cin>>bdate;
    cout<<"\nEnter The Type of Gender (m=0/f=1): ";
    cin>>gender;

}

bool Account::create_account(short account_type, int client_id, short client_class)
{
    this->account_type = account_type;
    cout<<"\nEnter The Account No. : ";
    cin>>account_number;

    this->client_id = client_id;
    this->client_class = client_class;
    cout<<"\nEnter The Initial amount(>=0 ) : ";
    cin>>deposit;
    while (deposit < 0.0){
        cout<<"\nEnter The Initial amount(>=0 ) : ";
        cin>>deposit;
    }

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Created..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";

    return true;
}

bool CreditAccount::create_account(int client_id, short client_class)
{
    account_type = 2;
    cout<<"\nEnter The Account No. : ";
    cin>>account_number;
    this->client_id = client_id;
    this->client_class = client_class;
    cout<<"\nEnter The Initial amount : ";
    cin>>deposit;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Created..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";

    return true;
}

void Account::show_account()
{
    cout<<"\nAccount No."<<"\t: "<<account_number;
    cout<<"\nAccount Holder id"<<": ";
    cout<<client_id;
    cout<<"\nType of Account"<<"\t: "<<account_types.find(account_type)->second;
    cout<<"\nBalance amount" <<"\t: "<<deposit;
}


void Account::modify_account()
{
    cout<<"\nThe Client id\t: "<<client_id;
    cout<<"\nThe Account No\t: "<<account_number;

    cout<<"\nEnter Type of The Account : ";
    cout<<"\n\n\t\t\t\t\t1. DEBIT ACCOUNT";
    cout<<"\n\n\t\t\t\t\t2. CREDIT ACCOUNT";
    cout<<"\n\n\t\t\t\t\t3. BUSINESS ACCOUNT";
    cout<<"\n\n\t\t\t\t\t4. SAVING ACCOUNT";
    cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
    cin>>account_type;

    cout<<"\nEnter The amount"<< "\t: ";
    cin>>deposit;
}



void Account::deposit_amount(float x)
{
    while (x <= 0){
        cout << "\n Enter a positive value:\t";
        cin >> x;
    }
    deposit+=x;
}

void Account::withdraw_amount(float x)
{
    while (deposit < x || x < 0){
        cout << "\nMaximum ammount to withdraw is:\t" << deposit << endl;
        cout << "\n Enter a valid value (more than zero, equal/less than deposited amount:\t";
        cin >> x;
    }
    deposit-=x;
}

void CreditAccount::withdraw_amount(float x) {
    deposit-=x;
}


void Account::account_data_in_tabular_format()
{
    cout<<account_number<<"\t\t\t\t\t"<<client_id<<"\t\t\t\t\t"<<client_types.find(client_class)->second;
    int i;
    for(i=0;i<15;i++)
    {
        cout<<" ";
    }
    cout<<account_types.find(account_type)->second;
    for(i=0;i<10;i++)
    {
        cout<<" ";
    }
    cout<<deposit<<endl;
}

int Account::return_account_num()
{
    return account_number;
}

int Account::return_deposited_balance()
{
    return deposit;
}

char Account::return_account_type()
{
    return account_type;
}



void write_account(short account_type);	//function to write record in binary file
void list_account_details(int);	//function to display Account details given by user
void modify_account(int);	//function to modify_account record of file
void delete_account(int);	//function to delete record of file
void list_all_accounts();		//function to display all Account details
void list_client_accounts(int); //function to list all client's accounts
void deposit_or_withdraw_ammount(int, int); // function to desposit/withdraw amount for given Account
void transfer(int, int);



int main()
{
    short choice;
    int account_num;
    int account2_num; //In case of Transfer money (Deposit Account)
    int client_id;
    short account_type; //Account Type
    char bank_name[100];
    int a = 1;
    string answer; string client_name;
    Bank bank;
    bank.setname();

    do
    {

        cout<<"\n\n\t\t\t\t  ******Banking System******";
        cout<<"\n\t\t\t\t======================================";
        cout<<"\n\n\t\t\t\t  ******"<< bank.getname() <<" Bank******";
        cout<<"\n\t\t\t\t==========================================";
        cout<<"\n\n\t\t\t\t\t**MAIN MENU**";
        cout<<"\n\n\t\t\t\t\t1. NEW ACCOUNT";
        cout<<"\n\n\t\t\t\t\t2. DEPOSIT AMOUNT";
        cout<<"\n\n\t\t\t\t\t3. WITHDRAW AMOUNT";
        cout<<"\n\n\t\t\t\t\t4. ACCOUNT DETAILS";
        cout<<"\n\n\t\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
        cout<<"\n\n\t\t\t\t\t6. CLOSE AN ACCOUNT";
        cout<<"\n\n\t\t\t\t\t7. MODIFY AN ACCOUNT";
        cout<<"\n\n\t\t\t\t\t8. Transfer FROM ACCOUNT TO ACCOUNT";
        cout<<"\n\n\t\t\t\t\t9. List Client Accounts";
        cout<<"\n\n\t\t\t\t\t10. List Clients Info.";
        cout<<"\n\n\t\t\t\t\t11. Total Amount Of Money In The Bank";
        cout<<"\n\n\t\t\t\t\t12. Exit";
        cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nEnter Type of The Account : ";
                cout<<"\n\n\t\t\t\t\t1. DEBIT ACCOUNT";
                cout<<"\n\n\t\t\t\t\t2. CREDIT ACCOUNT";
                cout<<"\n\n\t\t\t\t\t3. BUSINESS ACCOUNT";
                cout<<"\n\n\t\t\t\t\t4. SAVING ACCOUNT";
                cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
                cin>>account_type;
                write_account(account_type);
                break;
            case 2:
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>account_num;
                deposit_or_withdraw_ammount(account_num, 1);
                break;
            case 3:
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>account_num;
                deposit_or_withdraw_ammount(account_num, 2);
                break;
            case 4:
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>account_num;
                list_account_details(account_num);
                break;
            case 5:
                list_all_accounts();
                break;
            case 6:
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>account_num;
                delete_account(account_num);
                break;
            case 7:
                cout<<"\n\n\t\t\t\tEnter The Account No. : ";
                cin>>account_num;
                modify_account(account_num);
                break;
            case 8:
                cout<<"\n\n\t\t\t\tEnter The Account No. That You Want To Withdraw From : ";
                cin>>account_num;
                cout<<"\n\n\t\t\t\tEnter The Account No. That You Want To Deposit To : ";
                cin>>account2_num;
                transfer(account_num, account2_num);
                break;
            case 9:
                cout<<"\n\n\t\t\t\tEnter Client id : ";
                cin>>client_id;
                list_client_accounts(client_id);

                break;
            case 11:

                cout << "\n\nTotal Bank Balance: "<<bank.total_bank_balance()<<endl;
                break;
            case 12:
                cout<<"\n       \t\t\t\t\t      Thank You For Using La Casa de Papel Banking System";
                cout<<"\n     \t\t\t\t\t\t\t\t      Your Assets in Safe Hands";
                choice = std::cin.get();
                exit(0);

            default :cout<<"wrong choice";
        }
        choice = std::cin.get();
    }while(choice!=12);
    return 0;
}



void write_account(short account_type)
{

    ofstream outFileClient;
    Client client;
    outFileClient.open("Client.dat", ios::binary|ios::app);
    client.create_client();
    outFileClient.write((char *) &client, sizeof(Client));
    outFileClient.close();

    ofstream outFile;
    switch (account_type) {
        case 1:
        {
            DebitAccount dac;
            outFile.open("Account.dat",ios::binary|ios::app);
            dac.create_account(account_type, client.get_client_id(), client.get_client_class());
            outFile.write((char *) &dac, sizeof(Account));
            outFile.close();
            break;
        }


        case 2: {
            CreditAccount cac;
            outFile.open("Account.dat", ios::binary | ios::app);
            cac.create_account(client.get_client_id(), client.get_client_class());
            outFile.write((char *) &cac, sizeof(Account));
            outFile.close();
            break;
        }
        case 3: {
            BusinessAccount bac;
            outFile.open("Account.dat", ios::binary | ios::app);
            bac.create_account(account_type, client.get_client_id(), client.get_client_class());
            outFile.write((char *) &bac, sizeof(Account));
            outFile.close();
            break;
        }
        case 4: {
            SavingAccount sac;
            outFile.open("Account.dat", ios::binary | ios::app);
            sac.create_account(account_type, client.get_client_id(), client.get_client_class());
            outFile.write((char *) &sac, sizeof(Account));
            outFile.close();
            break;
        }

        default :cout<<"wrong choice";

    }


}


void list_account_details(int account_number)
{
    Account account;
    int flag=0;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";
    while(inFile.read((char *) &account, sizeof(Account)))
    {
        if(account.return_account_num()==account_number)
        {
            account.show_account();
            flag=1;
        }
    }
    inFile.close();
    if(flag==0)
        cout<<"\n\nAccount number does not exist";
}

void modify_account(int n)
{
    int found=0;
    Account account;
    fstream File;
    File.open("Account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &account, sizeof(Account)) && found==0)
    {
        if(account.return_account_num()==n)
        {
            account.show_account();
            cout<<"\n\n==>>Enter The New Details of Account"<<endl;
            account.modify_account();
            int pos=(-1)*sizeof(Account);
            File.seekp(pos,ios::cur);
            File.write((char *) &account, sizeof(Account));
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
            found=1;
        }
    }
    File.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
}

void delete_account(int n)
{
    Account account;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read((char *) &account, sizeof(Account)))
    {
        if(account.return_account_num()!=n)
        {
            outFile.write((char *) &account, sizeof(Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("Account.dat");
    rename("Temp.dat","Account.dat");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Deleted..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
}

void list_all_accounts()
{
    Account account;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

    cout<<"Account no.\t\tClient id\t\t\t\tClient Class\t\t\t\tAccount Type\t\t     Balance\n\n";

    while(inFile.read((char *) &account, sizeof(Account)))
    {
        account.account_data_in_tabular_format();
    }
    inFile.close();
}

void list_client_accounts(int client_id)
{
    Account account;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

    cout<<"Account no.\t\tClient id\t\t\t\tClient Class\t\t\t\tAccount Type\t\t     Balance\n\n";

    while(inFile.read((char *) &account, sizeof(Account)))
    {
        if (account.get_client_id() == client_id){
            account.account_data_in_tabular_format();
        }

    }
    inFile.close();
}

void deposit_or_withdraw_ammount(int n, int option)
{
    int amount;
    int found=0;
    Account account;
    fstream File;
    File.open("Account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      File could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &account, sizeof(Account)) && found==0)
    {
        if(account.return_account_num()==n)
        {
            account.show_account();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nEnter The amount to be deposited";
                cin>>amount;
                account.deposit_amount(amount);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                cout<<"\n\nEnter Withdrawal Amount";
                cin>>amount;
                
                account.withdraw_amount(amount);
            }
            int pos=(-1)* sizeof(account);
            File.seekp(pos,ios::cur);
            File.write((char *) &account, sizeof(Account));
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
            found=1;
        }
    }
    File.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
}

void transfer(int n1, int n2)
{
    float amount;
    float fee=0.0;
    int found=0;
    bool withdrawal_is_done = false;
    Account account1;
    Account account2;
    short account1_type;
    fstream File;
    File.open("Account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"\n\n\n\n\n\n\n\t\t\t\t\tFile could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &account1, sizeof(Account)) && found==0)
    {
        if(account1.return_account_num()==n1)
        {
            account1.show_account();

            cout<<"\n\n\tTO WITHDRAW AMOUNT ";
            cout<<"\n\nEnter Withdrawal Amount: ";
            cin>>amount;

            
            float balance = account1.return_deposited_balance() - amount;
            if((balance<0.0 && account1.return_account_type()!=2))
                cout<<"Insufficience balance";
            else {
                account1_type = account1.get_account_type();
                account1.withdraw_amount(amount);
                int pos=(-1)* sizeof(account1);
                File.seekp(pos,ios::cur);
                File.write((char *) &account1, sizeof(Account));
                withdrawal_is_done = true;
            }


            found=1;
        }

    }
    if (withdrawal_is_done) {
        found=0;
        File.close();
        cout<<"\nHold a second!";
        File.open("Account.dat", ios::binary|ios::in|ios::out);
        while (File.read((char *) &account2, sizeof(Account)) && found == 0) {
            if (account2.return_account_num() == n2) {
                account2.show_account();



                if (account1_type == 3) {
                    if (account2.get_client_class() == 1)
                        fee = amount * 0.02;
                    else if (account2.get_client_class() == 2)
                        fee = amount * 0.01;
                    else fee = 0.0;
                }
                cout << "\nThe Deposited Amount is: "<< amount-fee;
                cout << "\n\nPress Enter To Continue";
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                account2.deposit_amount(amount-fee);

                int pos = (-1) * sizeof(account2);
                File.seekp(pos, ios::cur);
                File.write((char *) &account2, sizeof(Account));

                cout << "\n\n\n\n\n\n\n\t\t\t\t\tRecord Updated..\n\n\t\t\t\t\t==>>Press Enter<<==";
                found = 1;
            }
        }
    }

    if(found==0)
        cout<<"\n\n Record Not Found ";

    File.close();
}
