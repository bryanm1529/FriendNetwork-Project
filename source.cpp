#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


class FriendNetwork {
private:
	// Initialize friend network to 0's
	int friendlist[20][20] = { 0 };

public:

	void addfriend();
	void deletefriend();
	void showlist();

	// Helper function to print a friend's friends
	void printFriend(int UID);
	void menu();
	
	
};

// Have 1 friend add another friend
void FriendNetwork::addfriend() {

	char UID;
	cout << "Which account is adding (give a single letter A->K)" << endl;
	cin >> UID;
	UID = toupper(UID);
	char tempUID;
	cout << "Who would like to add (give a single letter A->K)";
	cin >> tempUID;
	tempUID = toupper(tempUID);
	int UID1 = UID - 65;
	int UID2 = tempUID - 65;

	friendlist[UID1][UID2] = 1;
	friendlist[UID2][UID1] = 1;
	menu();

}

// Have 1 friend delete another friend
void FriendNetwork::deletefriend() {
	char dID;
	cout << "Which account is this (Single letter A->K)" << endl;
	cin >> dID;
	dID = toupper(dID);

	char tempdID;
	cout << "Which account would you like to delete" << endl;
	cin >> tempdID;
	tempdID = toupper(tempdID);
	int dID1 = dID - 65;
	int dID2 = tempdID - 65;
	friendlist[dID1][dID2] = 0;
	friendlist[dID2][dID1] = 0;

	menu();

}

// List friends of a given friend
void FriendNetwork::showlist() {
	int UID;
	cout << "Which accounts friend list would you like to see? " << endl;
	cin >> UID;
	printFriend(UID);
}

// Print friends of friend given UID
void FriendNetwork::printFriend(int UID) {
	// Loop through each friend of the friend with UID
	for (int i = 0; i < 20; i++) {
		char userToChar;

		// If they're friends
		if (friendlist[UID][i] == 1) {
			userToChar = i + 65;
			userToChar = toupper(userToChar);
			cout << " The friends are "<< userToChar << " ";
			
		}
	}
	cout << endl;

}

void FriendNetwork::menu() {
	// 1 for adding friend
	// 2 for deleting friend
	// 3 for listing friend
	// 4 for quit

	int choice;
			cout << " 1: Add friend " << endl;
			cout << " 2: Delete friend " << endl;
			cout << " 3: List friends " << endl;
			cout << " 4: quit " << endl;
			cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << " PLEASE ENTER CORRECT CHOICE" << endl;
			cout << " 1: Add friend " << endl;
			cout << " 2: Delete friend " << endl;
			cout << " 3: List friends " << endl;
			cout << " 4: quit " << endl;
			cin >> choice;
	}
		if (choice == 1) {
			addfriend();
		}

		if (choice == 2) {
			deletefriend();
		}

		if (choice == 3) {
			showlist();
		}

		if (choice == 4) {
			cout << " Goodbye! " << endl;
		}

	// Ask user to enter 1, 2, 3, 4


	// Loop until correct input (1-4)

	// if 1, then call addfriend function
	// if 2, call delete friend function/
	// ...
}


int main() {
	FriendNetwork fn;
	fn.menu();
	/*fn.addfriend();
	fn.addfriend();
	fn.addfriend();
	fn.addfriend();
	fn.deletefriend();
	fn.showlist();
	//fn.printNetwork();
	*/
	system("pause");
	return 0;
}
