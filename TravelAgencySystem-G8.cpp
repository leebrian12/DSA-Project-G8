#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
	
using namespace std;
	
void admin();
void user();
	
void aLogin();
void aRegister();
	
void uLogin();
void uRegister();
	
int main()
{
	int choice;
	cout << "\t\t\t_____________________________________________________________\n\n\n";
	cout << "\t\t\t		Welcome to XXX Travel Agency System		 \n\n\n";
	cout << "\t\t\t_______________________   Home Page   _______________________\n\n"; 
	cout << "\t		| 		      Admin  ( Choose '1' )		    |" << endl;	
	cout << "\t		| 		      User   ( Choose '2' )		    |" << endl;
	cout << "\t		| 		      Exit   ( Choose '3' )		    |" << endl;
	cout << "\n\t\t        Please enter your choice : ";
	cin >> choice;
	cout << endl;
		
	switch(choice)
	{
		case 1: admin();
				break;
					  
		case 2: user();
				break;
					  
		case 3: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
				break;	
					  
		default: system("CLS");
				 cout << "\n\t\t\t\tPlease select the correct options given!\n\n" << endl;
				 main();
	}
	   return 0;
		
}
	
void admin()
{
	system("CLS");
		
	int choice;
		
	cout << "\t\t\t_____________________________________________________________\n\n\n";
	cout << "\t\t\t++++++++++++++++++++++    ADMIN SITE   ++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t_______________________   Main Menu    _______________________\n\n";
	cout << "\t\t\t|    Login                ( Choose '1' )                     |\n";
	cout << "\t\t\t|    Register             ( Choose '2' )                     |\n";
	cout << "\t\t\t|    Back to Home Page    ( Choose '3' )                     |\n";
	cout << "\t\t\t|    Exit                 ( Choose '4' )                     |\n";
	cout << "\n\t\t        Please enter your choice : ";
	cin >> choice;
	cout << endl;
		
	switch(choice)
	{
	    case 1: aLogin();
				break;
					
		case 2: aRegister();
				break;
			
		case 3: system("CLS");
				main();
				break;
			
		case 4: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
				break;
			
		default: system("CLS");
				 cout << "\n\t\t\t    Please select the correct options given!\n\n" << endl;
				 admin();
	}
		
}
	
void user()
{
	system("CLS");
		
	int choice;
		
	cout << "\t\t\t_____________________________________________________________\n\n\n";
	cout << "\t\t\t++++++++++++++++++++++    USER SITE   ++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t_______________________   Main Menu    _______________________\n\n";
	cout << "\t\t\t|    Login                ( Choose '1' )                     |\n";
	cout << "\t\t\t|    Register             ( Choose '2' )                     |\n";
	cout << "\t\t\t|    Back to Home Page    ( Choose '3' )                     |\n";
	cout << "\t\t\t|    Exit                 ( Choose '4' )                     |\n";
	cout << "\n\t\t        Please enter your choice : ";
	cin >> choice;
	cout << endl;
		
	switch(choice)
	{
		case 1: uLogin();
				break;
					
		case 2: uRegister();
				break;
			
		case 3: system("CLS");
				main();
				break;
			
		case 4: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
				break;
			
		default: system("CLS");
				 cout << "\n\t\t\t       Please select the correct options given!\n\n" << endl;
				 user();
	}
			
}

// Admin Login & Register functions
	
void aLogin()
{
	int count;
	string username,password,id,pass;
	system("CLS");
	cout << "\t\t\t_______________________________________________________________\n\n\n";
	cout << "\t\t\t++++++++++++++++++++++    ADMIN LOGIN   ++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t________________________________________________________________\n\n";
	cout << "\t\t\t Username : ";
	cin >> username;
	cout << "\t\t\t Password : ";
	cin >> password;
	ifstream input("AdminAcc.txt");
		
	while(input >> id >> pass)
	{
		if(id == username && pass == password)
		{
			count = 1;
			system("CLS");
		}
	}
		
	input.close();
		
	if(count == 1)
	{
		cout << username << "\nLogin Successfully!";
		main();
	}
	else
	{
		cout << "\n\t\t\tLogin Failed! Please check your username and password\n";
		main();
	}
		
}
	
void aRegister()
{
	string Rusername,Rpassword,Rid,Rpass;
	system("CLS");
	cout << "\t\t\t_______________________________________________________________\n\n\n";
	cout << "\t\t\t+++++++++++++++++++++    ADMIN REGISTRATION   ++++++++++++++++++\n\n\n";
	cout << "\t\t\t________________________________________________________________\n\n";
	cout << "\t\t\t Enter New Username : ";
	cin >> Rusername;
	cout << "\t\t\t Enter New Password : ";
	cin >> Rpassword;
		
	ofstream f1;
	f1.open("AdminAcc.txt");
	f1 << Rusername << endl << Rpassword << endl;
	f1.close();
	system("CLS");
	cout << "\n\n\t\t\t\t\tRegistration sucessfully! \n";
	main();
		
}
	
// User Login & Register functions
	
void uLogin()
{
	int count;
	string username,password,id,pass;
	system("CLS");
	cout << "\t\t\t_______________________________________________________________\n\n\n";
	cout << "\t\t\t++++++++++++++++++++++    USER LOGIN    +++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t________________________________________________________________\n\n";
	cout << "\t\t\t Username : ";
	cin >> username;
	cout << "\t\t\t Password : ";
	cin >> password;
		
	ifstream input("UserAcc.txt");
		
	while(input >> id >> pass)
	{
		if(id == username && pass == password)
		{
			count = 1;
			system("CLS");
		}
	}
		
	input.close();
		
	if(count == 1)
	{
		cout << username << "\nLogin Successfully!";
		main();
	}
	else
	{			cout << "\n\t\t\tLogin Failed! Please check your username and password\n";
		main();
	}
}
	
void uRegister()
{
	string Rusername,Rpassword,Rid,Rpass;
	system("CLS");
	cout << "\t\t\t_______________________________________________________________\n\n\n";
	cout << "\t\t\t+++++++++++++++++++++    USER REGISTRATION    ++++++++++++++++++\n\n\n";
	cout << "\t\t\t________________________________________________________________\n\n";
	cout << "\t\t\t Enter New Username : ";
	cin >> Rusername;
	cout << "\t\t\t Enter New Password : ";
	cin >> Rpassword;
		
	ofstream f1;
	f1.open("UserAcc.txt");
	f1 << Rusername << endl << Rpassword << endl;
	f1.close();
	system("CLS");
	cout << "\n\n\t\t\t\t\tRegistration sucessfully! \n";
	main();
}