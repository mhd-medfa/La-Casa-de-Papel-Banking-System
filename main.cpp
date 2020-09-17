//Open this in an IDE like CLion C++

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include <limits>
#include <map>

std::map<int, std::string> client_types = {
        /*!
         * Mapping bank system clients into three classes :
         * 1. Regular Client
         * 2. Clients with Golden Card
         * 3. VIP clients
        */
        {1, "Regular Client"},
        {2, "Golden Client"},
        {3, "VIP Client"}
};

std::map<int, std::string> account_types = {
        /*!
         * Bank supports the following types of accounts: :
         * 1. Debit Account
         * 2. Credit Account
         * 3. Business Account
         * 4. Saving Account
        */
        {1, "Debit Account"},
        {2, "Credit Account"},
        {3, "Business Account"},
        {4, "Saving Account"}
};

class Bank{
    /*!
     * With Bank class we have access to :
     * name of the bank (get/set)
     * total bank balance calculation
     *
     */
    char name[50] = "Money Heist";
    public:
        void set_name(); //set name of the bank
        std::string get_name(); //get name of the bank
        int total_bank_balance(); //calculate the total amount of money in bank accounts (overall balance of the bank)

};

class Client{
    /*!
     * With Client class we have access to :
     * name[100]: client name
     * client_class: short integer value that maps into the current class of the client (Regular, Golder, VIP)
     * bdate: client's birthdate (dd-mm-yyyy)
     * gender: male=0 / female=1
     * num_of_accounts: number of accounts of the same client
     * total_balance: total amount of money in the client's accounts
     */
    char name[100]; short client_class; char bdate[10]="";
    bool gender; short num_of_accounts; float total_balance;
    int id;
    public:
        void create_client(); //add a new client to the banking system
        void show_client_details();
        int get_client_id(){
            return id; // get the id of the client
        }
        short get_client_class(){
            return client_class; //get the current class of the client
        }

};


class Account{
    /*!
     * With Account class we have access to:
     * account_number: number of the account that used in the banking system to recognize accounts from each other
     * deposit: amount of money deposited in the account
     * account_type: short integer value that maps to the type of the account (Deposit, Business, ..etc)
     * client_id: id of the account owner
     * client_class: short integer value that maps into the current class of the account owner (Regular, Golder, VIP)
     */
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
    virtual void withdraw_amount(float);	//function to accept amount and subtract from balance amount
    void account_data_in_tabular_format();	//function to show data in tabular format
    int return_account_num();	//function to return Account number
    int return_deposited_balance();	//function to return balance amount
    char return_account_type();	//function to return account_type of Account
    short get_client_class() {
        return client_class; //get the current class of the account owner (Regular, Golden, VIP)
    }
    short get_account_type() {
        return account_type; // get the type of the account (Deposit, Business, ..etc)
    }
    int get_client_id() {
        return client_id; // get the id of the account owner
    }
    float get_deposit() {
        return deposit; //get the amount of money deposited in the account
    }
};

class DebitAccount: public Account{
    /*!
     * DebitAccount class is inherited from Account class (there is nothing special about it)
     */

};

class CreditAccount: public Account{
    /*!
     * CreditAccount class is inherited from Account class and has the following special details:
     * It's possible to have a negative balance with CreditAccount
     */
public:
    bool create_account(int, short); // override Account::create_account to fit Credit Account needs
    void withdraw_amount(float); // override Account::withdraw_amount to be able to withdraw more money than you have
};

class BusinessAccount: public Account {
    /*!
     * BusinessAccount class is inherited from Account class
     * With Business Account system will charge a 2% fee for each money transfer for a regular client.
     * 1% fee for a client with golden card and no fee for VIP client.
     */
};

class SavingAccount: public Account {
    /*!
     * DebitAccount class is inherited from Account class (there is nothing special about it)
     */
};

void Bank::set_name() {
    /*!
     * set name of the bank
     */
    std::cout<< "Welcome to La Casa de Papel Banking System\nPlease Enter The Glorious Name Of Your Bank:" << std::endl;
    std::cin.getline(name,49);
}

std::string Bank::get_name() {
    return name; // read the name of the bank
}

int Bank::total_bank_balance() {
    /*!
     * calculate the total amount of money in the bank accounts by summing all accounts balances
     * To do that we read the accounts data from Account.dat and extract the balance of each account
     * by using Account::get_deposit method
     */
    Account account;
    float total_balance=0.0;
    std::ifstream inFile;
    inFile.open("Account.dat",std::ios::binary);
    if(!inFile)
    {
        std::cout<<"File could not be open !! Press any Key...";
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
    /*!
     * To add a client to the banking system we need to determine:
     * id: id of the client
     * name: client named
     * client_class: current class of the client
     * bdate: birthdate (dd-mm-yyyy) as a string value
     *
     */

    std::cout<<"\nEnter Client's id :";
    std::cin>>id;
    std::cout<<"\nEnter the Client's Name :";
    std::cin.ignore();
    std::cin.getline(name,49);
    std::cout<<"\nEnter The Client Class : ";
    std::cout<<"\n\n\t\t\t\t\t1. Regular Client";
    std::cout<<"\n\n\t\t\t\t\t2. Golden Client";
    std::cout<<"\n\n\t\t\t\t\t3. VIP Client";
    std::cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
    std::cin>>client_class;
    std::cout<<"\nEnter Client's Birthdate (dd-mm-yyyy):";
    std::cin>>bdate;
    std::cout<<"\nEnter The Type of Gender (m=0/f=1): ";
    std::cin>>gender;

}

bool Account::create_account(short account_type, int client_id, short client_class)
{
    /*!
     * To create a new account for one of the clients we need to determine:
     * client_id: id of the owner
     * account_number: bank account number of the account (it should be unique value but for now we just enter any value for the assignment)
     * client_class: class of the owner (Regular, Golden, VIP)
     * deposit: amount of initial balance of the new account
     */
    this->account_type = account_type;
    std::cout<<"\nEnter The Account No. : ";
    std::cin>>account_number;

    this->client_id = client_id;
    this->client_class = client_class;
    std::cout<<"\nEnter The Initial amount(>=0 ) : ";
    std::cin>>deposit;
    while (deposit < 0.0){
        std::cout<<"\nEnter The Initial amount(>=0 ) : ";
        std::cin>>deposit;
    }

    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Created..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";

    return true;
}

bool CreditAccount::create_account(int client_id, short client_class)
{
    /*!
     * To create a new credit account for one of the clients we need to determine:
     * client_id: id of the owner
     * account_number: bank account number of the account (it should be unique value but for now we just enter any value for the assignment)
     * client_class: class of the owner (Regular, Golden, VIP)
     * deposit: amount of initial balance of the new account
     */
    account_type = 2;
    std::cout<<"\nEnter The Account No. : ";
    std::cin>>account_number;
    this->client_id = client_id;
    this->client_class = client_class;
    std::cout<<"\nEnter The Initial amount : ";
    std::cin>>deposit;
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Created..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";

    return true;
}

void Account::show_account()
{
    /*!
     * It shows accoutn details :
     * account number, client id, account type, deposit amount
     */
    std::cout<<"\nAccount No."<<"\t: "<<account_number;
    std::cout<<"\nAccount Holder id"<<": ";
    std::cout<<client_id;
    std::cout<<"\nType of Account"<<"\t: "<<account_types.find(account_type)->second;
    std::cout<<"\nBalance amount" <<"\t: "<<deposit;
}

void Client::show_client_details() {
    std::cout<<"\nClient name: "<<name;
    std::cout<<"\nBirthdate: " << bdate;
    std::string client_gender = (gender==0) ? "male": "female";
    std::cout<<"\nGender: "<<client_gender;

}

void Account::modify_account()
{
    /*!
     * It modifies account's properties
     */
    std::cout<<"\nThe Client id\t: "<<client_id;
    std::cout<<"\nThe Account No\t: "<<account_number;
    std::cout<<"\nEnter Type of The Account : ";
    std::cout<<"\n\n\t\t\t\t\t1. DEBIT ACCOUNT";
    std::cout<<"\n\n\t\t\t\t\t2. CREDIT ACCOUNT";
    std::cout<<"\n\n\t\t\t\t\t3. BUSINESS ACCOUNT";
    std::cout<<"\n\n\t\t\t\t\t4. SAVING ACCOUNT";
    std::cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
    std::cin>>account_type;

    std::cout<<"\nEnter The amount"<< "\t: ";
    std::cin>>deposit;
}



void Account::deposit_amount(float x)
{
    /*!
     * It helps to deposit money into account by amount x
     */
    while (x <= 0){
        std::cout << "\n Enter a positive value:\t";
        std::cin >> x;
    }
    deposit+=x;
}

void Account::withdraw_amount(float x)
{
    /*!
     * It helps to withdraw money from account by amount x
     */
    while (deposit < x || x < 0){
        std::cout << "\nMaximum ammount to withdraw is:\t" << deposit << std::endl;
        std::cout << "\n Enter a valid value (more than zero, equal/less than deposited amount:\t";
        std::cin >> x;
    }
    deposit-=x;
}

void CreditAccount::withdraw_amount(float x) {
    /*!
     * It helps to withdraw money from account by amount x (x could be bigger than deposit)
     */
    deposit-=x;
}


void Account::account_data_in_tabular_format(){
    /*!
     * It shows accoutn details in a tabular format :
     * account number, client id, account type, deposit amount
     */
    std::cout<<account_number<<"\t\t\t\t\t"<<client_id<<"\t\t\t\t\t"<<client_types.find(client_class)->second;
    int i;
    for(i=0;i<15;i++)
    {
        std::cout<<" ";
    }
    std::cout<<account_types.find(account_type)->second;
    for(i=0;i<10;i++)
    {
        std::cout<<" ";
    }
    std::cout<<deposit<<std::endl;
}

int Account::return_account_num(){
    /*!
     * It returns account number
     */
    return account_number;
}

int Account::return_deposited_balance()
{
    /*!
     * It return deposit balance
     */
    return deposit;
}

char Account::return_account_type(){
    /*!
     * It returns short integer that maps to the account type (Debit, Business, ..etc)
     */
    return account_type;
}



void write_account(short account_type);	//function to write record in binary file
void list_account_details(int);	//function to display Account details given by user
void modify_account(int);	//function to modify_account record of file
void delete_account(int);	//function to delete record of file
void list_all_accounts();		//function to display all Account details
void list_client_accounts(int); //function to list all client's accounts
void deposit_or_withdraw_ammount(int, int); // function to desposit/withdraw amount for given Account
void transfer(int, int); //transfer money from account1 t account2
void list_all_clients_details(); //list all clients details



int main()
{
    /*!
     *
     */
    short choice; //On each cycle of the system cycle we have to enter a valid choice [1-12] (listed in the switch cases below)
    int account_num; //account_1 number
    int account2_num; //account_2 number; We use it in case of Transfering money from account1 (Withdrawal Account)
                        // to account2 (Deposit Account)
    int client_id; //id of the client (account owner)
    short account_type; //Account Type (Deposit, Business, ..etc)
    char bank_name[100]; // Name of the Bank (We have the chance to rename the bank when we run the project).
    std::string answer; std::string client_name;
    Bank bank; // Bank object
    bank.set_name(); //set the name of the Bank

    do
    {

        std::cout<<"\n\n\t\t\t\t  ******Banking System******";
        std::cout<<"\n\t\t\t\t======================================";
        std::cout<<"\n\n\t\t\t\t  ******"<< bank.get_name() <<" Bank******";
        std::cout<<"\n\t\t\t\t==========================================";
        std::cout<<"\n\n\t\t\t\t\t**MAIN MENU**";
        std::cout<<"\n\n\t\t\t\t\t1. NEW ACCOUNT";
        std::cout<<"\n\n\t\t\t\t\t2. DEPOSIT AMOUNT";
        std::cout<<"\n\n\t\t\t\t\t3. WITHDRAW AMOUNT";
        std::cout<<"\n\n\t\t\t\t\t4. ACCOUNT DETAILS";
        std::cout<<"\n\n\t\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
        std::cout<<"\n\n\t\t\t\t\t6. CLOSE AN ACCOUNT";
        std::cout<<"\n\n\t\t\t\t\t7. MODIFY AN ACCOUNT";
        std::cout<<"\n\n\t\t\t\t\t8. Transfer FROM ACCOUNT TO ACCOUNT";
        std::cout<<"\n\n\t\t\t\t\t9. List Client Accounts";
        std::cout<<"\n\n\t\t\t\t\t10. List Clients Info.";
        std::cout<<"\n\n\t\t\t\t\t11. Total Amount Of Money In The Bank";
        std::cout<<"\n\n\t\t\t\t\t12. Exit";
        std::cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
        std::cin>>choice;

        switch(choice)
        {
            case 1:
                std::cout<<"\nEnter Type of The Account : ";
                std::cout<<"\n\n\t\t\t\t\t1. DEBIT ACCOUNT";
                std::cout<<"\n\n\t\t\t\t\t2. CREDIT ACCOUNT";
                std::cout<<"\n\n\t\t\t\t\t3. BUSINESS ACCOUNT";
                std::cout<<"\n\n\t\t\t\t\t4. SAVING ACCOUNT";
                std::cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
                std::cin>>account_type;
                write_account(account_type);
                break;
            case 2:
                std::cout<<"\n\n\t\t\t\tEnter The Account No. : "; std::cin>>account_num;
                deposit_or_withdraw_ammount(account_num, 1);
                break;
            case 3:
                std::cout<<"\n\n\t\t\t\tEnter The Account No. : "; std::cin>>account_num;
                deposit_or_withdraw_ammount(account_num, 2);
                break;
            case 4:
                std::cout<<"\n\n\t\t\t\tEnter The Account No. : "; std::cin>>account_num;
                list_account_details(account_num);
                break;
            case 5:
                list_all_accounts();
                break;
            case 6:
                std::cout<<"\n\n\t\t\t\tEnter The Account No. : "; std::cin>>account_num;
                delete_account(account_num);
                break;
            case 7:
                std::cout<<"\n\n\t\t\t\tEnter The Account No. : ";
                std::cin>>account_num;
                modify_account(account_num);
                break;
            case 8:
                std::cout<<"\n\n\t\t\t\tEnter The Account No. That You Want To Withdraw From : ";
                std::cin>>account_num;
                std::cout<<"\n\n\t\t\t\tEnter The Account No. That You Want To Deposit To : ";
                std::cin>>account2_num;
                transfer(account_num, account2_num);
                break;
            case 9:
                std::cout<<"\n\n\t\t\t\tEnter Client id : ";
                std::cin>>client_id;
                list_client_accounts(client_id);

                break;
            case 10:
                list_all_clients_details();
                break;
            case 11:

                std::cout << "\n\nTotal Bank Balance: "<<bank.total_bank_balance()<<std::endl;
                break;
            case 12:
                std::cout<<"\n       \t\t\t\t\t      Thank You For Using La Casa de Papel Banking System";
                std::cout<<"\n     \t\t\t\t\t\t\t\t      Your Assets in Safe Hands";
                choice = std::cin.get();
                exit(0);

            default :std::cout<<"wrong choice";
        }
        choice = std::cin.get();
    }while(choice!=12);
    return 0;
}



void write_account(short account_type)
{
    /*!
     * It is a helper function that writes the proper account details both
     * into Client.dat and Account.dat
     */

    std::ofstream outFileClient;
    Client client;
    outFileClient.open("Client.dat", std::ios::binary|std::ios::app);
    client.create_client();
    outFileClient.write((char *) &client, sizeof(Client));
    outFileClient.close();

    std::ofstream outFile;
    switch (account_type) {
        case 1:
        {
            DebitAccount dac;
            outFile.open("Account.dat",std::ios::binary|std::ios::app);
            dac.create_account(account_type, client.get_client_id(), client.get_client_class());
            outFile.write((char *) &dac, sizeof(Account));
            outFile.close();
            break;
        }


        case 2: {
            CreditAccount cac;
            outFile.open("Account.dat", std::ios::binary | std::ios::app);
            cac.create_account(client.get_client_id(), client.get_client_class());
            outFile.write((char *) &cac, sizeof(Account));
            outFile.close();
            break;
        }
        case 3: {
            BusinessAccount bac;
            outFile.open("Account.dat", std::ios::binary | std::ios::app);
            bac.create_account(account_type, client.get_client_id(), client.get_client_class());
            outFile.write((char *) &bac, sizeof(Account));
            outFile.close();
            break;
        }
        case 4: {
            SavingAccount sac;
            outFile.open("Account.dat", std::ios::binary | std::ios::app);
            sac.create_account(account_type, client.get_client_id(), client.get_client_class());
            outFile.write((char *) &sac, sizeof(Account));
            outFile.close();
            break;
        }

        default :std::cout<<"wrong choice";

    }


}


void list_account_details(int account_number)
{
    /*!
     * It is a helper function that print details of account with th account_number
     */
    Account account;
    int flag=0;
    std::ifstream inFile;
    inFile.open("Account.dat",std::ios::binary);
    if(!inFile)
    {
        std::cout<<"File could not be open !! Press any Key...";
        return;
    }
    std::cout<<"\nBALANCE DETAILS\n";
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
        std::cout<<"\n\nAccount number does not exist";
}

void modify_account(int n)
{
    /*!
     * It modifies account with account number (n) regarding to the values entered
     * by the user
     */
    int found=0;
    Account account;
    std::fstream File;
    File.open("Account.dat",std::ios::binary|std::ios::in|std::ios::out);
    if(!File)
    {
        std::cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &account, sizeof(Account)) && found==0)
    {
        if(account.return_account_num()==n)
        {
            account.show_account();
            std::cout<<"\n\n==>>Enter The New Details of Account"<<std::endl;
            account.modify_account();
            int pos=(-1)*sizeof(Account);
            File.seekp(pos,std::ios::cur);
            File.write((char *) &account, sizeof(Account));
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
            found=1;
        }
    }
    File.close();
    if(found==0)
        std::cout<<"\n\n Record Not Found ";
}

void delete_account(int n)
{
    /*!
     * It deletes account with account number (n) from the system (basically from Account.dat)
     */
    Account account;
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open("Account.dat",std::ios::binary);
    if(!inFile)
    {
        std::cout<<"File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat",std::ios::binary);
    inFile.seekg(0,std::ios::beg);
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
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Deleted..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
}

void list_all_accounts()
{
    /*!
     * It shows all the accounts in the system (basically all the accounts in Account.dat)
     */
    Account account;
    std::ifstream inFile;
    inFile.open("Account.dat",std::ios::binary);
    if(!inFile)
    {
        std::cout<<"File could not be open !! Press any Key...";
        return;
    }
    std::cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

    std::cout<<"Account no.\t\tClient id\t\t\t\tClient Class\t\t\t\tAccount Type\t\t     Balance\n\n";

    while(inFile.read((char *) &account, sizeof(Account)))
    {
        account.account_data_in_tabular_format();
    }
    inFile.close();
}

void list_client_accounts(int client_id)
{
    /*!
     * It is a helper function that helps to show the list of accounts
     * that's owned by the client and created in the banking system.
     * To do that it reads data from Account.dat and it uses
     * Account.get_client_id & Account::account_data_in_tabular_format
     * to accomplish its task
     */
    Account account;
    std::ifstream inFile;
    inFile.open("Account.dat",std::ios::binary);
    if(!inFile)
    {
        std::cout<<"File could not be open !! Press any Key...";
        return;
    }
    std::cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

    std::cout<<"Account no.\t\tClient id\t\t\t\tClient Class\t\t\t\tAccount Type\t\t     Balance\n\n";

    while(inFile.read((char *) &account, sizeof(Account)))
    {
        if (account.get_client_id() == client_id){
            account.account_data_in_tabular_format();
        }

    }
    inFile.close();
}

void list_all_clients_details()
{
    /*!
     * It is a helper function that helps to show the list of all clients details
     * that's owned by the client and created in the banking system.
     * To do that it reads data from Client.dat Account.dat and it uses
     * Account.get_client_id & Account::account_data_in_tabular_format
     * to accomplish its task
     */
    Account account;
    Client client;
    float client_balance = 0.0;
    short number_of_accounts = 0;
    std::ifstream  in_client_file;
    in_client_file.open("Client.dat", std::ios::binary);
    if(!in_client_file){
        std::cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(in_client_file.read((char *) &client, sizeof(Client)))
    {



    std::ifstream inFile;
    inFile.open("Account.dat",std::ios::binary);
    if(!inFile)
    {
        std::cout<<"File could not be open !! Press any Key...";
        return;
    }
    std::cout<<"\n\n\t\tClients Details LIST\n\n";

//    std::cout<<"Client Name\t\tAccount no.\t\tClient id\t\t\t\tClient Class\t\t\t\tAccount Type\t\t     Balance\n\n";

    while(inFile.read((char *) &account, sizeof(Account)))
    {

        if (account.get_client_id() == client.get_client_id()){
            client_balance += account.get_deposit();
            number_of_accounts += 1;
        }
    }
    inFile.close();
    client.show_client_details();
    std::cout<<"\nClient Balance: "<< client_balance;
    std::cout<<"\nNumber of Accounts: "<<number_of_accounts;
    }
    in_client_file.close();
}

void deposit_or_withdraw_ammount(int n, int option)
{
    /*!
     * It is a helper function that calls deposit or withdraw proper account methods; plus read current and write
     * the new value into the Account.dat file
     */
    int amount;
    int found=0;
    Account account;
    std::fstream File;
    File.open("Account.dat", std::ios::binary|std::ios::in|std::ios::out);
    if(!File)
    {
        std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      File could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &account, sizeof(Account)) && found==0)
    {
        if(account.return_account_num()==n)
        {
            account.show_account();
            if(option==1)
            {
                std::cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                std::cout<<"\n\nEnter The amount to be deposited";
                std::cin>>amount;
                account.deposit_amount(amount);
            }
            if(option==2)
            {
                std::cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                std::cout<<"\n\nEnter Withdrawal Amount";
                std::cin>>amount;
                
                account.withdraw_amount(amount);
            }
            int pos=(-1)* sizeof(account);
            File.seekp(pos,std::ios::cur);
            File.write((char *) &account, sizeof(Account));
            std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
            found=1;
        }
    }
    File.close();
    if(found==0)
        std::cout<<"\n\n Record Not Found ";
}

void transfer(int n1, int n2)
{
    /*!
     * It helps to accomplish the transaction process between any two different accounts in the
     * banking system
     * First it looks for the first account and asks the user to determine the amount of withdrawal
     * then it looks for the second account where the money should be transfered to, and after calculating
     * the fee it increase the deposit amount of the second account by amount of (withdrawal amount - the fee)
     * And the fee is zero unless the account type is a Business account then the fee is calculated like this:
     * Business account should charge a 2% fee for each money transfer for a regular client.
     * 1% fee for a client with golden card and no fee for VIP client.
     */
    float amount;
    float fee=0.0;
    int found=0;
    bool withdrawal_is_done = false;
    Account account1;
    Account account2;
    short account1_type;
    std::fstream File;
    File.open("Account.dat", std::ios::binary|std::ios::in|std::ios::out);
    if(!File)
    {
        std::cout<<"\n\n\n\n\n\n\n\t\t\t\t\tFile could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &account1, sizeof(Account)) && found==0)
    {
        if(account1.return_account_num()==n1)
        {
            account1.show_account();

            std::cout<<"\n\n\tTO WITHDRAW AMOUNT ";
            std::cout<<"\n\nEnter Withdrawal Amount: ";
            std::cin>>amount;

            
            float balance = account1.return_deposited_balance() - amount;
            if((balance<0.0 && account1.return_account_type()!=2))
                std::cout<<"Insufficience balance";
            else {
                account1_type = account1.get_account_type();
                account1.withdraw_amount(amount);
                int pos=(-1)* sizeof(account1);
                File.seekp(pos,std::ios::cur);
                File.write((char *) &account1, sizeof(Account));
                withdrawal_is_done = true;
            }


            found=1;
        }

    }
    if (withdrawal_is_done) {
        found=0;
        File.close();
        std::cout<<"\nHold a second!";
        File.open("Account.dat", std::ios::binary|std::ios::in|std::ios::out);
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
                std::cout << "\nThe Deposited Amount is: "<< amount-fee;
                std::cout << "\n\nPress Enter To Continue";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                account2.deposit_amount(amount-fee);

                int pos = (-1) * sizeof(account2);
                File.seekp(pos, std::ios::cur);
                File.write((char *) &account2, sizeof(Account));

                std::cout << "\n\n\n\n\n\n\n\t\t\t\t\tRecord Updated..\n\n\t\t\t\t\t==>>Press Enter<<==";
                found = 1;
            }
        }
    }

    if(found==0)
        std::cout<<"\n\n Record Not Found ";

    File.close();
}
