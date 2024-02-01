#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
#include <unistd.h>


using namespace std;
void pay(const string& username, const string& packageName, double price, int days, int nights);


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
			cout << "\t\t\t__________________________________________________________________\n\n\n";
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

				case 3:	system("CLS");
						editPackage();
						break;

				case 4: system("CLS");
						deletePackage();
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

		stringstream formattedPrice;
    	formattedPrice << fixed << setprecision(2) << price;
	
	    cout << "\t\t\t Enter Number of Days : ";
	    cin >> days;
	
	    cout << "\t\t\t Enter Number of Nights: ";
	    cin >> nights;
		
    	string packageDetails = packageName + "," + formattedPrice.str() + "," + to_string(days) + "," + to_string(nights);
    	
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

        	for (size_t i = 0; i < packageDetailsList.size(); ++i)
			{
				string packageDetails = packageDetailsList[i];
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
				cout << "\t\t\t| " << setw(3) << right << i + 1 << ". " << setw(20) << left << packageName << "  | " << setw(2) << right << "RM" << setw(10) << left << price << " | " << setw(2) << days << " days, " << setw(2) << nights << " nights |\n";
			}

			packageFile.close();
			cout << "\n";

			char choice;

			do {
				cout << "\t\t\t___________________________________________________________________\n\n\n";
				cout << "\t\t\t++++++++++++++++++++++    SEARCH PACKAGE   ++++++++++++++++++++++++\n\n\n";
				cout << "\t\t\t____________________________________________________________________\n\n";
				cout << "\t\t\t|    Search package       ( Choose '1' )                     |\n";
				cout << "\t\t\t|    Back to Main Page    ( Choose '2' )                     |\n"<<endl<<endl;
				cout<<"\t\t\t Please enter your choice : ";
				cin >> choice;

				switch(choice)
				{
					case '1': performPackageSearch(packageDetailsList);cout<<endl<<endl;
							break;
					case '2': cout << "\t\t\t Returning to Main Page....\n\n";
							break;
					default: system("CLS");
							cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;
				}
			} while (choice != '2');
		}
		system("pause");
	}

	// For edit and delete package
	struct Package {
    	string location;
		double price;
		int day; 
		int night; 
	};

	
	void editPackage() {
		queue<Package> packages;
		string filename = "packages.txt";
		readPackages(packages, filename);

		cout << "Packages read from file:" << endl;
    	printPackages(packages);

		int index;
		cout << "Enter the number of the package you want to edit: ";
		cin >> index;

		queue<Package> temp;
		int count = 0;

		while (!packages.empty()) {
			if (count == index - 1) {
				Package& pack = packages.front();

				cout << "\nEnter new location: ";
				cin.ignore();
				getline(cin, pack.location);

				cout << "\nEnter new price (format must be RM XX.XX): ";
				cin >> pack.price;

				cout << "\nEnter new day: ";
				cin >> pack.day;

				cout << "\nEnter new night: ";
				cin >> pack.night;

			}
			
			temp.push(packages.front());
			packages.pop();
			count++;
		}

		while (!temp.empty()) {
			packages.push(temp.front());
			temp.pop();
		}

		writePackages(packages, filename);
	}

	//Inside the editpackage
	void writePackages(queue<Package>& packages, const string& filename) {
		ofstream file(filename);
		if (file.is_open()) {
			queue<Package> temp;
			while (!packages.empty()) {
				Package pack = packages.front();
				file << pack.location << "," << pack.price << "," << pack.day << "," << pack.night << endl; // Changed from rating1 to day and rating2 to night
				temp.push(pack);
				packages.pop();
			}
			while (!temp.empty()) {
				packages.push(temp.front());
				temp.pop();
			}
			file.close();
		}
	}

		void readPackages(queue<Package>& packages, const string& filename) {
				ifstream file(filename);
				if (file.is_open()) {
					string line;
					while (getline(file, line)) {
						stringstream ss(line);
						string item;
						Package pack;
						getline(ss, item, ',');
						pack.location = item;
						getline(ss, item, ',');
						pack.price = stod(item);
						getline(ss, item, ',');
						pack.day = stoi(item); // Changed from rating1 to day
						getline(ss, item);
						pack.night = stoi(item); // Changed from rating2 to night
						packages.push(pack);
					}
					file.close();
				}
	}

	void printPackages(queue<Package> packages) {
		int count = 1;
		while (!packages.empty()) {
			Package pack = packages.front();
			cout << "Package " << count++ << ":" << endl;
			cout << "Location: " << pack.location << endl;
			cout << "Price: " << pack.price << endl;
			cout << "Day: " << pack.day << endl; // Changed from rating1 to day
			cout << "Night: " << pack.night << endl; // Changed from rating2 to night
			cout << endl;
			packages.pop();
		}
	}

	void deletePackage() {
		queue<Package> packages;
		ifstream file("packages.txt");

		if (!file.is_open()) {
			cout << "\n\t\t\tNo packages available.\n";
			return;
		}

		string line;
		int count = 1;

		cout << "\t\t\t_______________________________________________________________\n\n\n";
		cout << "\t\t\t++++++++++++++++++++   Delete PACKAGES  +++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t________________________________________________________________\n\n";

		while (getline(file, line)) {
			stringstream ss(line);
			string item;
			Package pack;
			getline(ss, item, ',');
			pack.location = item;
			getline(ss, item, ',');
			pack.price = stod(item);
			getline(ss, item, ',');
			pack.day = stoi(item);
			getline(ss, item);
			pack.night = stoi(item);

			cout << "\t\t\tPackage " << count++ << ":" << endl;
			cout << "\t\t\tLocation: " << pack.location << endl;
			cout << "\t\t\tPrice: " << pack.price << endl;
			cout << "\t\t\tDay: " << pack.day << endl;
			cout << "\t\t\tNight: " << pack.night << endl;
			cout << endl;

			packages.push(pack);
		}

		file.close();

		int index;
		cout << "\n\t\t\tEnter the Number of the package you want to delete: ";
		cin >> index;

		queue<Package> temp;
		count = 1;
		bool deleted = false;

		while (!packages.empty()) {
			if (count != index) {
				temp.push(packages.front());
			} else {
				deleted = true;
				cout << "\n\t\t\tPackage " << index << " deleted successfully." << endl;
			}
			packages.pop();
			count++;
		}

		file.close();

		ofstream outputFile("packages.txt");

		while (!temp.empty()) {
			Package pack = temp.front();
			outputFile <<pack.location << "," << pack.price << "," << pack.day << "," << pack.night << endl;
			temp.pop();
		}

		outputFile.close();

		 if (deleted) {
        // Clear the screen
        system("CLS");

        // Output success message
        cout << "\n\t\t\tDeletion successful. Returning to Admin Site...\n";

        // Wait for 1 second (for Windows)
		sleep(4);//sleeps for 3 second

        // Return to Admin Site
        AdminHomepage();
		} else {
			// Output message for package not found
			cout << "\n\t\t\tPackage not found." << endl;
		}
		}


 
	void performPackageSearch(const vector<string> &packageDetailsList) 
	{
		string target;
		cout << "\t\t\t Input the package name to search : ";
		cin.ignore(); 
		getline(cin, target);

		// Convert target to lowercase for case-insensitive search
		transform(target.begin(), target.end(), target.begin(), ::tolower);

		vector<int> foundIndices; // Stores indices of matching packages

		// Check if the package list is sorted alphabetically by name
		bool isSortedByName = true;
		
		for (size_t i = 1; i < packageDetailsList.size(); ++i) {
			if (getPackageName(packageDetailsList[i]) < getPackageName(packageDetailsList[i - 1])) {
				isSortedByName = false;
				break;
			}
		}

		// Perform binary search if the list is sorted, otherwise use linear search
		if (isSortedByName) {
			int foundIndex = binarySearchByName(packageDetailsList, target);
			if (foundIndex != -1) {
				foundIndices.push_back(foundIndex);
			}
		} else {
			// Iterate through each package and search for the keyword
			for (size_t i = 0; i < packageDetailsList.size(); ++i) {
				string packageName = getPackageName(packageDetailsList[i]);

				// Convert package name to lowercase for case-insensitive search
				transform(packageName.begin(), packageName.end(), packageName.begin(), ::tolower);

				// Check if the target is a substring of the package name
				if (packageName.find(target) != string::npos) {
					foundIndices.push_back(i);
				}
			}
		}

		// Output result
		if (!foundIndices.empty()) {
			cout << "\n\t\t\tPackages found:\n";
			for (size_t i = 0; i < foundIndices.size(); ++i) {
				cout << "\n\t\t\tPackage at position " << (foundIndices[i] + 1) << ":" << endl;
				displayPackageDetails(packageDetailsList[foundIndices[i]]);
				cout << endl;
			}
		} else {
			cout << "\t\t\t No packages found, please enter again." << endl;
		}
	}

	int binarySearchByName(const vector<string> &packageDetailsList, const string &target) 
	{
		int first = 0;
		int last = packageDetailsList.size() - 1;
		vector<int> foundIndices; // Stores indices of matching packages

		while (first <= last) {
			int mid = (first + last) / 2;
			string packageName = getPackageName(packageDetailsList[mid]);

			// Convert package name to lowercase for case-insensitive search
			transform(packageName.begin(), packageName.end(), packageName.begin(), ::tolower);

			// Check if the target is a substring of the package name
			if (packageName.find(target) != string::npos) {
				foundIndices.push_back(mid);
			}

			// Continue searching in the lower or upper half based on comparison
			if (packageName < target) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}

		// Output result
		if (!foundIndices.empty()) {
			// Display found packages
			cout << "\n\t\t\tPackages found:\n";
			for (size_t i = 0; i < foundIndices.size(); ++i) {
				cout << "\n\t\t\tPackage at position " << (foundIndices[i] + 1) << ":" << endl;
				displayPackageDetails(packageDetailsList[foundIndices[i]]);
				cout << endl;
			}
			// Return the index of the first matching package
			return foundIndices[0];
		} else {
			// No package found
			return -1;
		}
	}


	string getPackageName(const string &packageDetails) 
	{
		stringstream ss(packageDetails);
		string packageName;
		getline(ss, packageName, ',');
		return packageName;
	}

	void displayPackageDetails(const string &packageDetails) 
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


};

class User
{
	private:
	string loggedInUsername;

	public:

		
	void editPackage() {
		// Get the logged-in username
		string username = loggedInUsername;

		ifstream cartFile("Cart.txt");

		if (!cartFile.is_open()) {
			cout << "Error: Unable to open the cart file." << endl;
			return;
		}

		bool foundUser = false;
		bool updated = false; // Flag to track if the departure date has been updated

		queue<string> tempQueue; // Queue to store modified lines

		string line;
		while (getline(cartFile, line)) {
			// Check if the line contains the user's username
			if (line.find("Username: " + username) != string::npos) {
				foundUser = true;
				cout << "\n\t\t\tCurrent Package :" << endl;
				displayUserItems(username); // Display user items with numbered bullets

				// Ask user to select a numbered bullet for editing departure date
				int selection;
				cout << "\n\t\t\tSelect a package number to edit departure date (0 to cancel): ";
				cin >> selection;

				if (selection == 0) {
					cout << "Editing canceled." << endl;
					return;
				}

				// Output the package details
				tempQueue.push(line); // Username
				getline(cartFile, line);
				tempQueue.push(line); // Package details

				// Skip writing the old departure date to the queue
				getline(cartFile, line);

				// Prompt for the new departure date
				string newDepartureDate;
				cout << "Enter the new departure date (YYYY-MM-DD): ";
				cin >> newDepartureDate;
				cout << "Departure date updated successfully." << endl;

				// Update the departure date in the queue
				tempQueue.push("Departure date: " + newDepartureDate);
				updated = true;
				
				continue;
			}
			tempQueue.push(line); // Store other lines in the queue
		}

		cartFile.close();

		if (!foundUser) {
			cout << "Username not found in the cart." << endl;
			return;
		}

		// If the departure date was not updated, display a message
		if (!updated) {
			cout << "No departure date found for the user." << endl;
			return;
		}

		// Write the contents of the queue to Temp.txt
		ofstream tempFile("Temp.txt");
		if (!tempFile.is_open()) {
			cout << "Error: Unable to create temporary file." << endl;
			return;
		}

		while (!tempQueue.empty()) {
			tempFile << tempQueue.front() << endl;
			tempQueue.pop();
		}

		tempFile.close();

		// Replace the original Cart.txt file with Temp.txt
		if (remove("Cart.txt") != 0 || rename("Temp.txt", "Cart.txt") != 0) {
			cout << "Error updating cart file." << endl;
			return;
		}
	}

	void displayUserItems(const string& username) {
		ifstream cartFile("Cart.txt");

		if (!cartFile.is_open()) {
			cout << "Error: Unable to open the cart file." << endl;
			return;
		}

		bool foundUser = false;
		int count = 0; // Counter for numbered bullets

		string line;
		while (getline(cartFile, line)) {
			// Check if the line contains the user's username
			if (line.find("Username: " + username) != string::npos) {
				foundUser = true;
				++count; // Increment count when encountering a line with the username
				cout << "\t\t\t"<<count << ". " << line << endl; // Output with numbered bullet
			}
		}

		cartFile.close();

		if (!foundUser) {
			cout << "No items found for username: " << username << endl;
		}
	}



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
			cout << "\t\t\t|    View Cart            ( Choose '3' )                     |\n";
			cout << "\t\t\t|    Edit cart    	  ( Choose '4' )                     |\n";
			cout << "\t\t\t|    Back to Home Page    ( Choose '5' )                     |\n";
			cout << "\t\t\t|    Exit                 ( Choose '6' )                     |\n";
			cout << "\n\t\t        Please enter your choice : ";
			cin >> choice;
			cout << endl;

			switch(choice)
			{
				case 1: addPackagetoCart();

						break;
				
				case 2: ad.viewPackage();
						break;

				case 3: UviewCart();
						break;

				case 4:	editPackage();
				 		break;

				case 5: system("CLS");
                    	break;
				
				case 6: cout << "\t\t\tExiting the Travel Agency System. Thank you for using our services!\n\n";
                        exit(0);

				default: system("CLS");
                         cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;

			}

		} while (choice != 4);
			
	}

	void setLoggedInUsername(const string& username) 
	{
        loggedInUsername = username;
    }

	void addPackagetoCart()
	{
		string username = loggedInUsername;
		string departureDate;

    	cout << "\n\t\t\tEnter the departure date (YYYY-MM-DD): ";
    	cin >> departureDate;

		string cartFileName = "Cart.txt";
		ofstream cartFile(cartFileName, ios::app); // Use ios::app to append to the file

		if (!cartFile.is_open())
		{
			cout << "\n\t\t\tError: Unable to open the cart file for writing.\n";
			return;
		}

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

			packageFile.close();

			system("CLS");
			cout << "\t\t\t_______________________________________________________________\n\n\n";
			cout << "\t\t\t+++++++++++++++++++++    ADD TO CART    ++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t________________________________________________________________\n\n";

			cout << "\t\t\tAvailable Packages:\n\n";

			for (size_t i = 0; i < packageDetailsList.size(); ++i)
			{
				string packageDetails = packageDetailsList[i];
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
				cout << "\t\t\t| " << setw(3) << right << i + 1 << ". " << setw(20) << left << packageName << "  | " << setw(2) << right << "RM" << setw(10) << left << price << " | " << setw(2) << days << " days, " << setw(2) << nights << " nights |\n";
			}

			int packageNumber;
        	bool validInput = false;

			do
			{
				cout << "\n\t\t\tEnter the package number to add to your cart (0 to cancel): ";
				cin >> packageNumber;

				if (packageNumber >= 1 && packageNumber <= static_cast<int>(packageDetailsList.size()))
				{
					validInput = true;
				}
				else if (packageNumber == 0)
				{
					cout << "\n\t\t\tCanceled. Returning to User Menu...\n";
					system("pause");
					return;
				}
				else
				{
					cout << "\n\t\t\tInvalid package number. Please try again.\n";
				}
			} while (!validInput);

			cartFile << "Username: " << username << ", Package chosen: " << packageDetailsList[packageNumber - 1] << ", Departure date: " << departureDate << endl;
        	cartFile.close();

			cout << "\n\t\t\tPackage added to the cart file successfully!\n";

			system("pause");
		}
	}

	void UviewCart()
	{
		system("CLS");
		cout << "\t\t\t_______________________________________________________________\n\n\n";
		cout << "\t\t\t++++++++++++++++++++    VIEW CART    ++++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t________________________________________________________________\n\n";

		ifstream cartFile("Cart.txt");
		if (!cartFile.is_open())
		{
			cout << "\t\t\tNo cart information available.\n";
		}
		else
		{
			string username = loggedInUsername;
			bool found = false;

			cout << "\t\t\tList of Packages in Your Cart:\n\n";

			string line;
			int count = 0;
			while (getline(cartFile, line))
			{
				system("CLS");
				cout << "\t\t\t_______________________________________________________________\n\n\n";
				cout << "\t\t\t++++++++++++++++++++    VIEW CART    ++++++++++++++++++++++++\n\n\n";
				cout << "\t\t\t________________________________________________________________\n\n";

				// Check if the line contains the user's username
				if (line.find("Username: " + username) != string::npos)
				{
					found = true;
					count++;

					// Extract the package details from the line
					size_t pos = line.find("Package chosen: ");
					if (pos != string::npos)
					{
						string packageDetails = line.substr(pos + 16); // Length of "Package chosen: "
						stringstream ss(packageDetails);
						string packageName, priceStr, daysStr, nightsStr, departureDateStr;

						getline(ss, packageName, ',');
						getline(ss, priceStr, ',');
						getline(ss, daysStr, ',');
						getline(ss, nightsStr, ',');

						// Extract departure date
						getline(ss, departureDateStr, ',');
						string departureDate = departureDateStr.substr(departureDateStr.find("Departure date: ") + 16);

						double price = stod(priceStr);
						int days = stoi(daysStr);
						int nights = stoi(nightsStr);

						cout << fixed << setprecision(2);
						cout << "\t\t\t| " << setw(3) << right << count << ". " << setw(20) << left << packageName << "  | " << setw(2) << right << "RM" << setw(10) << left << price << " | " << setw(2) << days << " days, " << setw(2) << nights << " nights| "  << endl;
						cout << "\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
						cout << "\t\t\t|\t\t     Departure Date: " << departureDate << "\t\t\t|"<<endl;
						cout << "\t\t\t|\t\t\t\t\t\t\t\t|" << endl;

						cartFile.close();
						int pc;
						
						
						do
						{
							cout << "\t\t\t|    Payment              ( Choose '1' )                       \t|\n";     
							cout << "\t\t\t|    Delete Cart          ( Choose '2' )                       \t|\n";
							cout << "\t\t\t|    Back to Main         ( Choose '3' )                       \t|\n"<<endl;

							
							cout<<"\t\t\tEnter your choose : ";
							cin>>pc;

							switch(pc)
							{
								case 1: pay(username, packageName, price, days, nights, departureDateStr);
										break;
								case 2: deleteCart(username);
										break;

								case 3: system("CLS");
								 		break;

								default: system("CLS");
										cout << "\n\t\t\t\t   Please select the correct options given!\n\n" << endl;
							}

						}while(pc != 3);
					}
				}
			}

			if (!found)
			{
				cout << "\t\t\tYou have not added anything to your cart.\n";
			}

		}

		system("pause");

	}

	void deleteCart(const string& username) {
		ifstream inFile("Cart.txt");
		ofstream outFile("temp.txt"); // Temporary file to write modified data

		if (!inFile.is_open()) {
			cout << "Error: Unable to open file." << endl;
			return;
		}

		queue<string> linesQueue; // Queue to hold lines from the file

		string line;
		bool found = false;
		while (getline(inFile, line)) {
			linesQueue.push(line); // Push each line onto the queue
		}

		inFile.close(); // Close the file

		while (!linesQueue.empty()) {
			line = linesQueue.front(); // Get the front line from the queue
			linesQueue.pop(); // Remove the front line from the queue

			// Check if the line contains the user's username
			if (line.find("Username: " + username) != string::npos) {
				found = true;
				continue; // Skip writing this line
			}

			outFile << line << endl; // Write the line to the temporary file
		}

		outFile.close(); // Close the temporary file

		if (!found) {
			cout << "User not found in cart." << endl;
			remove("temp.txt"); // Remove temporary file
		} else {
			// Replace original file with modified contents
			remove("Cart.txt");
			rename("temp.txt", "Cart.txt");
			cout << "Cart entry for user '" << username << "' deleted successfully." << endl;
		}
	}

	void pay(const string& username, const string& packageName, double price, int days, int nights , const string& departureDateStr) 
	{
		system("CLS");
		cout << "\t\t\t_______________________________________________________________\n\n\n";
		cout << "\t\t\t++++++++++++++++++++    PAYMENT    ++++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t________________________________________________________________\n\n";

		// Display receipt
		cout << "\t\t\tUsername: " << username << endl;
		cout << "\t\t\tPackage: " << packageName << endl;
		cout << "\t\t\tPrice: RM" << price << endl;
		cout << "\t\t\tDuration: " << days << " days, " << nights << " nights" << endl;
		cout << "\t\t\tDeparture Date:" << departureDateStr << endl;

		ifstream inFile("Cart.txt"); 
		ofstream tempFile("Temp.txt");

		string line;
		bool found = false;
		bool isEmpty = true; 

		while (getline(inFile, line)) {
			// Check if the line contains the user's username
			if (line.find("Username: " + username) == string::npos) {
				tempFile << line << endl;
			} else {
				found = true;
				isEmpty = false; // Cart is not empty
			}
		}

		inFile.close();
		tempFile.close();

		if (isEmpty) {
			system("CLS");
			cout << "Your cart is empty." << endl;
		} else if (!found) {
			system("CLS");
			cout << "Username not found in the cart." << endl;
		} else {
			// Remove the original Cart.txt file
			if (remove("Cart.txt") != 0) {
				cout << "Error deleting file Cart.txt" << endl;
			}

			// Rename Temp.txt to Cart.txt
			if (rename("Temp.txt", "Cart.txt") != 0) {
				cout << "Error renaming file Temp.txt" << endl;
			}
		}

		

		// Open file for receipt
		ofstream userFile(username + " receipt.txt");
		if (!userFile.is_open()) {
			cerr << "Error opening file for writing." << endl;
			return;
		}

		// Write payment details into the file
		userFile << "\t\t\t_______________________________________________________________\n\n\n";
		userFile << "\t\t\t++++++++++++++++++++    PAYMENT    ++++++++++++++++++++++++\n\n\n";
		userFile << "\t\t\t________________________________________________________________\n\n";
		userFile << "\t\t\tUsername: " << username << endl;
		userFile << "\t\t\tPackage: " << packageName << endl;
		userFile << "\t\t\tPrice: RM" << price << endl;
		userFile << "\t\t\tDuration: " << days << " days, " << nights << " nights" << endl;
		userFile << "\t\t\tDeparture Date: " << departureDateStr << endl;

		userFile.close();


		system("pause");
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
			u.setLoggedInUsername(username);
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
