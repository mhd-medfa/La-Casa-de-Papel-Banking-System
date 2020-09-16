//Open this in an IDE like Codeblocks/Dev C++

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include <map>
using namespace std;

std::map<int, std::string> client_type = {
        {1, "Regular Client"},
        {2, "Golden-Card Client"},
        {3, "VIP Client"}
};

std::map<int, std::string> account_type = {
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

};

class Client{
    char name[100]; short client_class; string bdate;
    char gender; short num_of_accounts; long long total_balance;
//    std::cout << "Client name: " << name << ", Client type: " << client_type.find(client_class)->second << std::endl;

    public:
        void add_client();

};

class Account
{
    int acno;
    char name[50];
    int deposit;
    short type;
public:
    void create_account();	//function to get data from user
    void show_account();	//function to show data on screen
    void modify();   //function to get new data from user
    void dep(int);	//function to accept amount and add to balance amount
    void draw(int);	//function to accept amount and subtract from balance amount
    void report();	//function to show data in tabular format
    int retacno();	//function to return Account number
    int retdeposit();	//function to return balance amount
    char rettype();	//function to return type of Account
};

class DebitAccount: public Account{
public:
};

class CreditAccount: public Account{

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

void Client::add_client() {
//    char name[100]; short client_class; string bdate;
//    bool gender; short num_of_accounts; long long total_balance;
    cout<<"\nEnter the Client's Name :";
    cin.ignore();
    cin.getline(name,49);
    cout<<"\nEnter Client's Birthdate (dd-mm-yyyy):";
    cin>>bdate;
    cout<<"\nEnter The Type of Gender (m/f): ";
    cin.ignore();
    cin.getline(reinterpret_cast<char *>(gender), 1);


}

void Account::create_account()
{
    cout<<"\nEnter The Account No. : ";
    cin>>acno;
    cout<<"\nEnter The Name of The Account Holder :\t";
    cin.ignore();
    cin.getline(name,49);

    cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
    cin>>deposit;
    system("clear");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Created..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
}

void Account::show_account()
{
    cout<<"\nAccount No."<<"\t: "<<acno;
    cout<<"\nAccount Holder Name"<<": ";
    cout<<name;
    cout<<"\nType of Account"<<"\t: "<<account_type.find(type)->second;
    cout<<"\nBalance amount" <<"\t: "<<deposit;
}


void Account::modify()
{
    cout<<"\nThe Account No"<<"\t: "<<acno;
    cout<<"\n\nEnter The Name of The Account Holder"<<"\t: ";
    fflush(stdin);
    cin >> name;
    cout<<"\nEnter Type of The Account : ";
    cout<<"\n\n\t\t\t\t\t1. DEBIT ACCOUNT";
    cout<<"\n\n\t\t\t\t\t2. CREDIT ACCOUNT";
    cout<<"\n\n\t\t\t\t\t3. BUSINESS ACCOUNT";
    cout<<"\n\n\t\t\t\t\t4. SAVING ACCOUNT";
    cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
    cin>>type;

    cout<<"\nEnter The amount"<< "\t: ";
    cin>>deposit;
}



void Account::dep(int x)
{
    deposit+=x;
}

void Account::draw(int x)
{
    deposit-=x;
}

void Account::report()
{
    cout<<acno<<"\t\t"<<name;
    int i,l=strlen(name);
    for(i=0;i<32-l;i++)
    {
        cout<<" ";
    }
    cout<<account_type.find(type)->second;
    for(i=0;i<20;i++)
    {
        cout<<" ";
    }
    cout<<deposit<<endl;
}

int Account::retacno()
{
    return acno;
}

int Account::retdeposit()
{
    return deposit;
}

char Account::rettype()
{
    return type;
}



void writeaccount(short type);	//function to write record in binary file
void displaysp(int);	//function to display Account details given by user
void modifyaccount(int);	//function to modify record of file
void deleteaccount(int);	//function to delete record of file
void displayall();		//function to display all Account details
void depositwithdraw(int, int); // function to desposit/withdraw amount for given Account




int main()
{
    char ch;
    int num;
    short type; //Account Type
    char bank_name[100];
    int a = 1;
    string answer; string client_name;
    Bank bank;
    bank.setname();

    do
    {   system("clear");

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
        cout<<"\n\n\t\t\t\t\t8. EXIT";
        cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
        cin>>ch;

        switch(ch)
        {
            case '1':
                cout<<"\nEnter Type of The Account : ";
                cout<<"\n\n\t\t\t\t\t1. DEBIT ACCOUNT";
                cout<<"\n\n\t\t\t\t\t2. CREDIT ACCOUNT";
                cout<<"\n\n\t\t\t\t\t3. BUSINESS ACCOUNT";
                cout<<"\n\n\t\t\t\t\t4. SAVING ACCOUNT";
                cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
                cin>>type;
                writeaccount(type);
                break;
            case '2':
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>num;
                depositwithdraw(num, 1);
                break;
            case '3':
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>num;
                depositwithdraw(num, 2);
                break;
            case '4':
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>num;
                displaysp(num);
                break;
            case '5':
                displayall();
                break;
            case '6':
                cout<<"\n\n\t\t\t\tEnter The Account No. : "; cin>>num;
                deleteaccount(num);
                break;
            case '7':
                cout<<"\n\n\t\t\t\tEnter The Account No. : ";
                cin>>num;
                modifyaccount(num);
                break;
            case '8':
                system("clear");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n       \t\t\t\t\t      Thank You For Using Automatic Banking System";
                ch = std::cin.get();
                system("clear");
                exit(0);

            default :cout<<"wrong choice";
        }
        ch = std::cin.get();
    }while(ch!='8');
    return 0;
}



void writeaccount(short type)
{
//    Account ac;
    ofstream outFile;

    switch (type) {
        case 1:
            DebitAccount dac;
            outFile.open("Account.dat",ios::binary|ios::app);
            dac.create_account();
            outFile.write((char *) &dac, sizeof(Account));
            outFile.close();
        case 2:
            CreditAccount cac;
            outFile.open("Account.dat",ios::binary|ios::app);
            cac.create_account();
            outFile.write((char *) &cac, sizeof(Account));
            outFile.close();
        case 3:
            BusinessAccount bac;
            outFile.open("Account.dat",ios::binary|ios::app);
            bac.create_account();
            outFile.write((char *) &bac, sizeof(Account));
            outFile.close();
        case 4:
            SavingAccount sac;
            outFile.open("Account.dat",ios::binary|ios::app);
            sac.create_account();
            outFile.write((char *) &sac, sizeof(Account));
            outFile.close();

        default :cout<<"wrong choice";

    }


}


void displaysp(int n)
{
    Account ac;
    int flag=0;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";
    while(inFile.read((char *) &ac, sizeof(Account)))
    {
        if(ac.retacno()==n)
        {
            ac.show_account();
            flag=1;
        }
    }
    inFile.close();
    if(flag==0)
        cout<<"\n\nAccount number does not exist";
}



void modifyaccount(int n)
{
    int found=0;
    Account ac;
    fstream File;
    File.open("Account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &ac, sizeof(Account)) && found==0)
    {
        if(ac.retacno()==n)
        {
            ac.show_account();
            cout<<"\n\n==>>Enter The New Details of Account"<<endl;
            ac.modify();
            int pos=(-1)*sizeof(Account);
            File.seekp(pos,ios::cur);
            File.write((char *) &ac, sizeof(Account));
            system("clear");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
            found=1;
        }
    }
    File.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
}




void deleteaccount(int n)
{
    Account ac;
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
    while(inFile.read((char *) &ac, sizeof(Account)))
    {
        if(ac.retacno()!=n)
        {
            outFile.write((char *) &ac, sizeof(Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("Account.dat");
    rename("Temp.dat","Account.dat");
    system("clear");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Deleted..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
}



void displayall()
{
    Account ac;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

    cout<<"A/c no.\t\tNAME\t\t\t\tType\t\t     Balance\n\n";

    while(inFile.read((char *) &ac, sizeof(Account)))
    {
        ac.report();
    }
    inFile.close();
}


void depositwithdraw(int n, int option)
{
    int amt;
    int found=0;
    Account ac;
    fstream File;
    File.open("Account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        system("clear");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      File could not be open !! Press any Key...";
        return;
    }
    while(File.read((char *) &ac, sizeof(Account)) && found==0)
    {
        if(ac.retacno()==n)
        {
            ac.show_account();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nEnter The amount to be deposited";
                cin>>amt;
                ac.dep(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                cout<<"\n\nEnter The amount to be withdraw";
                cin>>amt;
                int bal=ac.retdeposit()-amt;
                if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
                    cout<<"Insufficience balance";
                else
                    ac.draw(amt);
            }
            int pos=(-1)* sizeof(ac);
            File.seekp(pos,ios::cur);
            File.write((char *) &ac, sizeof(Account));
            system("clear");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
            found=1;
        }
    }
    File.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
}





//#include <iostream>
//#include <string>
//#include <map>
//#include <ctime>
//#include <algorithm>
//
//std::map<int, std::string> client_type = {
//        {1, "Regular Client"},
//        {2, "Golden-Card Client"},
//        {3, "VIP Client"}
//};
//
//std::map<int, std::string> account_type = {
//        {1, "Debit Account"},
//        {2, "Credit Account"},
//        {3, "Business Account"},
//        {4, "Saving Account"}
//};
//
//std::map<short, char[100], int> accounts_;
//
//class Bank{
//    public:
//        Bank(char name[100]) {
//            name = name;
//            std::cout << "Welcome to " << name << " Bank" << std::endl;
//        }
//};
//
//class Client{
//    public:
//        Client(char name[100], short client_class,std::string bdate, bool gender, short num_of_accounts, long long total_balance){
//            name = name;
//            client_class = client_class;
//            bdate = bdate;
//            gender = gender;
//            num_of_accounts = num_of_accounts;
//            total_balance = total_balance;
//            std::cout << "Client name: " << name << ", Client type: " <<client_type.find(client_class)->second << std::endl;
//        }
//
//
//};
//
//class Account{
//    public:
//        Account(int account_number, short account_class, char owner_name[100], long long total_balance){
//            account_class = account_class;
//            owner_name = owner_name;
//            account_number = account_number;
//        }
//};
//
//int main() {
//    char bank_name[100];
//    int a = 1;
//    std::string answer; std::string client_name; std::string
//    std::cout << "Welcome to La Casa de Papel Banking System\nPlease Enter The Glorious Name Of Your Bank:" << std::endl;
//    std::cin >> bank_name;
//    Bank bank(bank_name);
//    do {
//        std::cout << "Do you want to add a new Account? (Y/N)\n";
//        std::cin >> answer;
//
//        transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
//        std::cout << answer <<std::endl;
//        if (answer=="Y" || "YES")
//        {
//            std::cout << answer << std::endl;
//        }
//
//    } while (a==1);
//    return 0;
//}
