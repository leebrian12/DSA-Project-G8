#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Admin
{
	public:
	void AdminHomepage()
	{
		int choice;

		do
		{
			system("CLS");
			cout << "\t\t\t_____________________________________________________________\n\n\n";
			cout << "\t\t\t++++++++++++++++++++++    ADMIN SITE   ++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t_______________________    WELCOME ADMIN   _______________________\n\n";
			cout << "\t\t\t|    Add new package      ( Choose '1' )                     |\n";
			cout << "\t\t\t|    View packages        ( Choose '2' )                     |\n";
			cout << "\t\t\t|    Edit package    	  ( Choose '3' )                     |\n";
			cout << "\t\t\t|    Delete package    	  ( Choose '4' )                     |\n";
			cout << "\t\t\t|    Back to Home Page    ( Choose '5' )                     |\n";
			cout << "\t\t\t|    Exit                 ( Choose '6' )                     |\n";
			cout << "\n\t\t        Please enter your choice : ";
			cin >> choice;
			cout << endl;

			switch(choice)
			{
				case 1: addPackage();
						break;

				case 2: viewPackage();
						break;

				case 3:	editPackage();
						break;

				case 4: deletePackage();
					    break;

				case 5: system("CLS");
                    	break;
				
				case 6: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
                        exit(0);

				default: system("CLS");
                         cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;

			}

		} while (choice != 5);
			
	}

	void addPackage()
	{

	}

	void viewPackage()
	{

	}

	void editPackage()
	{

	}

	void deletePackage()
	{

	}


};

class User
{
	public:
	void UserHomepage()
	{
		int choice;

		do
		{
			system("CLS");
			cout << "\t\t\t_____________________________________________________________\n\n\n";
			cout << "\t\t\t++++++++++++++++++++++    USER SITE   ++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t_______________________    WELCOME USER   _______________________\n\n";
			// cout << "\t\t\t|    Add new package      ( Choose '1' )                     |\n";     
			// cout << "\t\t\t|    View packages        ( Choose '2' )                     |\n";
			// cout << "\t\t\t|    Edit package    	  ( Choose '3' )                     |\n";
			// cout << "\t\t\t|    Delete package    	  ( Choose '4' )                     |\n";
			cout << "\t\t\t|    Back to Home Page    ( Choose '5' )                     |\n";
			cout << "\t\t\t|    Exit                 ( Choose '6' )                     |\n";
			cout << "\n\t\t        Please enter your choice : ";
			cin >> choice;
			cout << endl;

			switch(choice)
			{
				// case 1: addPackage();
				// 		break;

				// case 2: viewPackage();
				// 		break;

				// case 3:	editPackage();
				// 		break;

				// case 4: deletePackage();
				// 	    break; 

				case 5: system("CLS");
                    	break;
				
				case 6: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
                        exit(0);

				default: system("CLS");
                         cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;

			}

		} while (choice != 5);
			
	}

};

class LogRegPage
{
	private:
		
	Admin a;
	User u;
	
    void displayHomePage() 
	{
        cout << "\t\t\t_____________________________________________________________\n\n\n";
		cout << "\t\t\t		Welcome to XXX Travel Agency System		 \n\n\n";
		cout << "\t\t\t_______________________   Home Page   _______________________\n\n"; 
		cout << "\t		| 		      Admin  ( Choose '1' )		    |" << endl;	
		cout << "\t		| 		      User   ( Choose '2' )		    |" << endl;
		cout << "\t		| 		      Exit   ( Choose '3' )		    |" << endl;
    }
    
	public:
    void run() 
	{
        int choice;
        do 
		{
            displayHomePage();
			cout << "\n\t\t        Please enter your choice : ";
            cin >> choice;
            cout << endl;
            system("CLS");

            switch (choice) 
			{
                case 1:	adminMenu();
                    	break;
                    
                case 2:	userMenu();
                    	break;
                    
                case 3: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
                    	break;
                    
                default: system("CLS");
                    	 cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;
            }
            
        }while (choice != 3);
    }

    void adminMenu() 
	{
        int choice;
        do 
		{
	        //system("CLS");
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

            switch (choice) 
			{
                case 1: adminLogin();
                    	break;
                    	
                case 2: adminRegister();
                    	break;
                    	
                case 3: system("CLS");
						break;
                    	
                case 4: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
                    	exit(0);
                
				default: system("CLS");
                    	 cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;
            }
            
        } while (choice != 3);
    }

    void adminLogin() 
	{
        string username, password, id, pass;
        int count=0;
        
        do
        {
        	system("CLS");
	        cout << "\t\t\t_______________________________________________________________\n\n\n";
			cout << "\t\t\t++++++++++++++++++++++    ADMIN LOGIN   ++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t________________________________________________________________\n\n";
			cout << "\t\t\t Username : ";
			cin >> username;
			cout << "\t\t\t Password : ";
			cin >> password;
			
			ifstream input("AdminAcc.txt");
			
			 while (input >> id >> pass) 
			{
	            if (id == username && pass == password) 
				{
	                count = 1;
	                system("CLS");
	            }
        	}
        	
        	input.close();
	
	        if (count == 0)
	        {
	            cout << "\n\t\t\tLogin Failed! Please check your username and password\n";
	            cout << "\t\t\tPress '1' to retry or any other number to go back to the Admin Menu: ";
	
	            int retryChoice;
	            cin >> retryChoice;
	            system("CLS");
	
	            if (retryChoice != 1)
	            {
	                break; 
	            }
	        }
	
	    } while (count != 1);
	
	    if (count == 1)
	    {
	        cout << username << "\nLogin Successfully!\n\n\n";
	        a.AdminHomepage();
	    }
		  
    }

    void adminRegister() 
	{
        string Rusername, Rpassword;
        system("CLS");
        cout << "\t\t\t_______________________________________________________________\n\n\n";
		cout << "\t\t\t+++++++++++++++++++++    ADMIN REGISTRATION   ++++++++++++++++++\n\n\n";
		cout << "\t\t\t________________________________________________________________\n\n";
		cout << "\t\t\t Enter New Username : ";
		cin >> Rusername;
		cout << "\t\t\t Enter New Password : ";
		cin >> Rpassword;

        ofstream f1;
        f1.open("AdminAcc.txt", ios::app);
        f1 << Rusername << endl << Rpassword << endl;
        f1.close();

        system("CLS");
		cout << "\n\n\t\t\t\t\tRegistration sucessfully! \n";
    }

    void userMenu() 
	{
        int choice;
        do
		{
            //system("CLS");
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

            switch (choice) 
			{
                case 1: userLogin();
                        break;
                        
                case 2: userRegister();
                        break;
                        
                case 3: system("CLS");
                    	break;
                    	
                case 4: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
                        exit(0);
                        
                default: system("CLS");
                         cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;
            }
            
        } while (choice != 3);
    }

    void userLogin() 
	{
        string username, password, id, pass;
        int count=0;
        do
	    {
	        system("CLS");
	        cout << "\t\t\t_______________________________________________________________\n\n\n";
	        cout << "\t\t\t++++++++++++++++++++++    USER LOGIN    +++++++++++++++++++++++\n\n\n";
	        cout << "\t\t\t________________________________________________________________\n\n";
	        cout << "\t\t\t Username : ";
	        cin >> username;
	        cout << "\t\t\t Password : ";
	        cin >> password;
	
	        ifstream input("UserAcc.txt");
	
	        while (input >> id >> pass)
	        {
	            if (id == username && pass == password)
	            {
	                count = 1;
	                system("CLS");
	                break;
	            }
	        }
	
	        input.close();
	
	        if (count == 0)
	        {
	            cout << "\n\t\t\tLogin Failed! Please check your username and password\n";
	            cout << "\t\t\tPress '1' to retry or any other number to go back to the User Menu: ";
	
	            int retryChoice;
	            cin >> retryChoice;
	            system("CLS");
	
	            if (retryChoice != 1)
	            {
	                break; 
	            }
	        }
	
	    } while (count != 1);
	
	    if (count == 1)
	    {
	        cout << username << "\nLogin Successfully!\n\n\n";
			u.UserHomepage();
	    }
    }

    void userRegister() 
	{
        string Rusername, Rpassword;
        system("CLS");
        cout << "\t\t\t_______________________________________________________________\n\n\n";
		cout << "\t\t\t+++++++++++++++++++++    USER REGISTRATION    ++++++++++++++++++\n\n\n";
		cout << "\t\t\t________________________________________________________________\n\n";
		cout << "\t\t\t Enter New Username : ";
		cin >> Rusername;
		cout << "\t\t\t Enter New Password : ";
		cin >> Rpassword;

        ofstream f1;
        f1.open("UserAcc.txt", ios::app);
        f1 << Rusername << endl << Rpassword << endl;
        f1.close();

        system("CLS");
		cout << "\n\n\t\t\t\t\tRegistration sucessfully! \n";
    }
};



int main() 
{
    LogRegPage lrp;
    lrp.run();
    
    return 0;
}
