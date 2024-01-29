#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

struct Package {
    string location;
    double price;
    int rating1;
    int rating2;
};

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
            pack.rating1 = stoi(item);
            getline(ss, item);
            pack.rating2 = stoi(item);
            packages.push(pack);
        }
        file.close();
    }
}

void writePackages(queue<Package>& packages, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        queue<Package> temp;
        while (!packages.empty()) {
            Package pack = packages.front();
            file << pack.location << "," << pack.price << "," << pack.rating1 << "," << pack.rating2 << endl;
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

void printPackages(queue<Package> packages) {
    int count = 1;
    while (!packages.empty()) {
        Package pack = packages.front();
        cout << "Package " << count++ << ":" << endl;
        cout << "Location: " << pack.location << endl;
        cout << "Price: " << pack.price << endl;
        cout << "Rating 1: " << pack.rating1 << endl;
        cout << "Rating 2: " << pack.rating2 << endl;
        cout << endl;
        packages.pop();
    }
}

void editPackage(queue<Package>& packages) {
    int index;
    cout << "Enter the index of the package you want to edit: ";
    cin >> index;

    queue<Package> temp;
    int count = 0;
    while (!packages.empty()) {
        if (count == index - 1) {
            Package& pack = packages.front();
            cout << "Enter new location: ";
            cin.ignore();
            getline(cin, pack.location);

            cout << "Enter new price: ";
            cin >> pack.price;

            cout << "Enter new rating 1: ";
            cin >> pack.rating1;

            cout << "Enter new rating 2: ";
            cin >> pack.rating2;
        }
        temp.push(packages.front());
        packages.pop();
        count++;
    }

    while (!temp.empty()) {
        packages.push(temp.front());
        temp.pop();
    }
}

int main() {
    queue<Package> packages;
    readPackages(packages, "packages.txt");

    cout << "Packages read from file:" << endl;
    printPackages(packages);

    editPackage(packages);

    cout << "Packages after editing:" << endl;
    printPackages(packages);

    writePackages(packages, "packages.txt");

    return 0;
}
