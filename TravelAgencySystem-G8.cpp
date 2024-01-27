#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

class Admin
{
	private:
    queue<string> packages;
    
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

	void addPackage()  // Queue algorithm
	{
		string packageName;
		double price;
    	int days, nights;
    	
		cin.ignore();
        system("CLS");
        cout << "\t\t\t_______________________________________________________________\n\n\n";
        cout << "\t\t\t+++++++++++++++++++++    ADD NEW PACKAGE    ++++++++++++++++++++\n\n\n";
        cout << "\t\t\t________________________________________________________________\n\n";
        cout << "\t\t\t Enter Package Name : ";
		getline(cin,packageName);
		
		cout << "\t\t\t Enter Package Price  : ";
	    cin >> price;
	
	    cout << "\t\t\t Enter Number of Days : ";
	    cin >> days;
	
	    cout << "\t\t\t Enter Number of Nights: ";
	    cin >> nights;
		
    	string packageDetails = packageName + "," + to_string(price) + "," + to_string(days) + "," + to_string(nights);
    	
    	packages.push(packageDetails);


        // Append the new package to the text file without overwriting existing data
        ofstream packageFile("Packages.txt", ios::app);
        packageFile << packageDetails << endl;
        packageFile.close();

        cout << "\nPackage added successfully!\n";
    }

    void updatePackageFile()
	{
	    ofstream packageFile("Packages.txt");
	    queue<string> tempQueue = packages;
	
	    while (!tempQueue.empty())
	    {
	        packageFile << tempQueue.front() << endl;
	        tempQueue.pop();
	    }
	
	    packageFile.close();
	}
    
    void loadPackagesFromFile()
	{
	    ifstream packageFile("Packages.txt");
	    if (packageFile.is_open())
	    {
	        string packageDetails;
	        while (getline(packageFile, packageDetails))
	        {
	            packages.push(packageDetails);
	        }

	        packageFile.close();
	    }
	}

	void selectionSort(vector<string>& arr)  // Selection Sort algorithm ( Sort with alphabetical )
	{
		int n = arr.size();
		for (int i = 0; i < n - 1; i++) 
		{
			int minIndex = i;
			for (int j = i + 1; j < n; j++) 
			{
				if (arr[j] < arr[minIndex]) 
				{
					minIndex = j;
				}
			}
			if (minIndex != i) 
			{
				swap(arr[i], arr[minIndex]);
			}
		}
	}

	void viewPackage()
	{
		system("CLS");
		cout << "\t\t\t_______________________________________________________________\n\n\n";
		cout << "\t\t\t++++++++++++++++++++    VIEW PACKAGES    +++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t________________________________________________________________\n\n";

		ifstream packageFile("Packages.txt");

		if (!packageFile.is_open()) 
		{
        	cout << "\t\t\tNo packages available.\n";
    	} 
		else 
		{
        	vector<string> packageDetailsList;
			string packageDetails;

        	while (getline(packageFile, packageDetails)) 
			{
            	packageDetailsList.push_back(packageDetails);
        	}

			selectionSort(packageDetailsList);

			cout << "\t\t\tList of Packages:\n\n";

        	for (const auto &packageDetails : packageDetailsList) 
			{
				stringstream ss(packageDetails);
				string packageName, priceStr, daysStr, nightsStr;

				getline(ss, packageName, ',');
				getline(ss, priceStr, ',');
				getline(ss, daysStr, ',');
				getline(ss, nightsStr, ',');

				double price = stod(priceStr);
				int days = stoi(daysStr);
				int nights = stoi(nightsStr);

				cout << fixed << setprecision(2);
				cout << "\t\t\t| " << setw(20) << left << packageName << "  | " << setw(2) << right << "RM" << price << " | " << setw(2) << days << " days, " << setw(2) << nights << " nights |\n";
       		 }

			packageFile.close();
			cout << "\n";
			int choice;

			// Prompt user for search or back to main
			do {
				cout << "Enter '1' to search for a package by name, '0' to go back to main: ";
				cin >> choice;

				if (choice == 1) {
					// Perform binary search
					performPackageSearch(packageDetailsList);
				}
			} while (choice == 1); 
		}
		system("pause");
	}

	void editPackage()
	{

	}

	void deletePackage()
	{

	}

	//binary search
	void performPackageSearch(const vector<string> &packageDetailsList) {
		string target;
		cout << "Input the package name to search: ";
		cin.ignore(); // Ignore the newline character left in the input buffer
		getline(cin, target);

		// Convert target to lowercase for case-insensitive search
		transform(target.begin(), target.end(), target.begin(), ::tolower);

		// Perform binary search
		int position = binarySearchByName(packageDetailsList, target);

		// Output result
		if (position != -1) {
			cout << "Package found at position " << position << endl;
		} else {
			cout << "Package not found" << endl;
		}
	}

	int binarySearchByName(const vector<string> &packageDetailsList, const string &target) {
		int first = 0;
		int last = packageDetailsList.size() - 1;
		int found = -1; // Initialize found position to -1 (not found)

		while (first <= last) {
			int mid = (first + last) / 2;
			string packageName = getPackageName(packageDetailsList[mid]);

			// Convert package name to lowercase for case-insensitive search
			transform(packageName.begin(), packageName.end(), packageName.begin(), ::tolower);


			if (packageName == target) {
				found = mid;
				break;
			} else if (packageName < target) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}

		return found;
	}

	string getPackageName(const string &packageDetails) {
		stringstream ss(packageDetails);
		string packageName;
		getline(ss, packageName, ',');
		return packageName;
	}


};

class User
{
	public:


	void UserHomepage()
	{
		Admin ad;
		int choice;

		do
		{
			system("CLS");
			cout << "\t\t\t_____________________________________________________________\n\n\n";
			cout << "\t\t\t++++++++++++++++++++++    USER SITE   ++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t_______________________    WELCOME USER   _______________________\n\n";
			cout << "\t\t\t|    Add to cart          ( Choose '1' )                     |\n";     
			cout << "\t\t\t|    View packages        ( Choose '2' )                     |\n";
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

				case 2: ad.viewPackage();
						break;

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
