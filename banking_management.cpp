//#Banking System by Ravi Kumawat
#include<iostream>
#include<map>
using namespace std;
int MIN_BALANCE = 500;

class Account
{
	private:
		long accountNumber;
		string firstName;
		string lastName;
		float balance;
		static long NextAccountNumber;
	public:
		Account(){}
		Account(string fname,string lname,float balance){
			NextAccountNumber++;
			accountNumber=NextAccountNumber;
			firstName=fname;
			lastName=lname;
			this->balance=balance;
		}
		long getAccNo(){return accountNumber;}
		string getFirstName(){return firstName;}
		string getLastName(){return lastName;}
		float getBalance(){return balance;}
		
		void Deposit(float amount){
			balance+=amount;
		}
		void Withdraw(float amount){
			if(balance-amount<MIN_BALANCE){
				cout<<"Insufficient Funds!!"<<endl;
				cout<<"Your transaction can't be completed"<<endl;
				return;
			}
			balance-=amount;
		}
		static void setLastAccountNumber(long accountNumber){
			NextAccountNumber=accountNumber;
		}
};
long Account::NextAccountNumber=0;

void getAccountDetails(Account acc){
	cout<<"\nFirst Name:"<<acc.getFirstName()<<endl;
	cout<<"Last Name:"<<acc.getLastName()<<endl;
	cout<<"Account Number:"<<acc.getAccNo()<<endl;
	cout<<"Balance:"<<acc.getBalance()<<endl;
	cout<<endl;
}

class Bank{
	private:
		map<long,Account> accounts;
	public:
		Bank(){
			Account account;
		}
		bool validAccount(long accountNumber){
			if(accounts.find(accountNumber)!=accounts.end()){
				return true;
			}
			return false;
		}
		Account OpenAccount(string fname,string lname,float balance){
			Account account(fname,lname,balance);
			accounts[account.getAccNo()] = account;
			return account;
		}
		void BalanceEnquiry(long accountNumber){
			if(!validAccount(accountNumber)){
				cout<<"Account does not exist"<<endl;
				return;
			}
			getAccountDetails(accounts[accountNumber]);
			return;
		}
		void Deposit(long accountNumber,float amount){
			if(!validAccount(accountNumber)){
				cout<<"Account does not exist"<<endl;
				return;
			}
			accounts[accountNumber].Deposit(amount);
			cout<<endl<<"\nAmount Deposited Successfully\n"<<endl;
			getAccountDetails(accounts[accountNumber]);
			return;
		}
		void Withdraw(long accountNumber,float amount){
			if(!validAccount(accountNumber)){
				cout<<"Account does not exist"<<endl;
				return;
			}
			accounts[accountNumber].Withdraw(amount);
			cout<<endl<<"Amount Withdrawn Successfully"<<endl;
		}
		void CloseAccount(long accountNumber){
			cout<<"\nPrinting out the details of account to be deleted.\n";
			getAccountDetails(accounts[accountNumber]);
			accounts.erase(accountNumber);
		}
		void ShowAllAccounts(){
			map<long,Account>::iterator itr;
			for(itr=accounts.begin();itr!=accounts.end();itr++){
				getAccountDetails(itr->second);
			}
		}
};
	
int main(){
	Bank b;
	Account acc;
	
	int choice;
	string fname,lname;
	long accountNumber;
	float balance;
	float amount;
	char c;
	do
	{
		system("cls");
		cout<<"*************************** Banking System ***************************";
		cout<<"\n\n1 Open an Account";
		cout<<"\n2 Balance Enquiry";
		cout<<"\n3 Deposit";
		cout<<"\n4 Withdrawal";
		cout<<"\n5 Close an Account";
		cout<<"\n6 Show All Accounts";
		cout<<"\n7 Quit";
		cout<<"\nEnter your choice: ";
	    	cin>>choice;
	    	while(choice<1 || choice>7){
			system("cls");
			cout<<"Invalid Choice Input\n"<<endl;
			cout<<"*************************** Banking System ***************************";
        		cout<<"\n\n1 Open an Account";
			cout<<"\n2 Balance Enquiry";
			cout<<"\n3 Deposit";
			cout<<"\n4 Withdrawal";
			cout<<"\n5 Close an Account";
			cout<<"\n6 Show All Accounts";
			cout<<"\n7 Quit";
			cout<<"\nEnter your choice: ";
		    	cin>>choice;
		}
		switch(choice)
			{
			case 1:
				cout<<"-------Opening a new account-------"<<endl;
				cout<<"Enter First Name: ";
				cin>>fname;
				cout<<"Enter Last Name: ";
				cin>>lname;
				cout<<"Enter initil Balance: ";
				cin>>balance;
				acc=b.OpenAccount(fname,lname,balance);
				system("cls");
				cout<<"Congratulations!! Account has been Created"<<endl;
				getAccountDetails(acc);
				cout<<"\n\nEnter any key to go back to main menu..";
				c = getchar();
				c = getchar();
				break;
		 	case 2:
		 		cout<<"-------Balance Enquiry-------"<<endl;
				cout<<"Enter Account Number:";
				cin>>accountNumber;
				b.BalanceEnquiry(accountNumber);
				cout<<"\n\nEnter any key to go back to main menu..";
				c = getchar();
				c = getchar();
				break;
			case 3:
				cout<<"-------Deposit an account-------"<<endl;
				cout<<"Enter Account Number:";
				cin>>accountNumber;
				cout<<"Enter Balance:";
				cin>>amount;
				b.Deposit(accountNumber, amount);
				cout<<endl<<"Amount is Deposited"<<endl;
				cout<<"\n\nEnter any key to go back to main menu..";
				c = getchar();
				c = getchar();
				break;
			case 4:
				cout<<"-------Withdraw an account-------"<<endl;
				cout<<"Enter Account Number:";
				cin>>accountNumber;
				cout<<"Enter Balance:";
				cin>>amount;
				b.Withdraw(accountNumber, amount);
				cout<<"\n\nEnter any key to go back to main menu..";
				c = getchar();
				c = getchar();
				break;
			case 5:
				cout<<"-------Close an account-------"<<endl;
				cout<<"Enter Account Number:";
				cin>>accountNumber;
				b.CloseAccount(accountNumber);
				cout<<endl<<"Account is Closed"<<endl;
				getAccountDetails(acc);
				cout<<"\n\nEnter any key to go back to main menu..";
				c = getchar();
				c = getchar();
				break;
			case 6:
				cout<<"-------Show all account details-------"<<endl;
				b.ShowAllAccounts();
				cout<<"\n\nEnter any key to go back to main menu..";
				c = getchar();
				c = getchar();
				break;
			case 7: 
				break;
		 	default:
				cout<<"Never Called!!";
				exit(0);
		 }
	}while(choice!=7);
	return 0;
}
