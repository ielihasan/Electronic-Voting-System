#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace	std;


//Variables Declaration:

void design()
{
	cout << "----------------------------------------------------------------------" << endl;
	cout << "***********************ELECTRONIC VOTING SYSTEM***********************" << endl;
	cout << "----------------------------------------------------------------------" << endl;
   }
int main()
{
	int pd, pfst, pscd, pthrd, vcpd, vcfst, vcscd, vcthrd, etmr, etmrfst, etmrscd, etmrthrd, gcdg, gcdgfst, gcdgscd, slmd, slmdfst, slmdscd, slmdthrd;

main_manu:	//Goto Token
	design();
Invalid_Attempt:

Login_screen:
	cout << "\nWelcome HCS Members\nPlease Login To Continue" << endl;
	int Choice;
	cout << "Login as:" << endl;
	cout << "\n1.Administrator\n\n2.Voter\n\n3.exit\n\n\nYour Choice:" << endl;
	cin >> Choice;
	system("cls");
	switch (Choice)
	{
	case 1:

		//system("pause");
	{  // Login Page Case 1
		string username, password, storedUsername, storedPassword;
		bool loggedIn = false;

		// Open the file containing stored usernames and passwords
		ifstream loginFile("admin.txt");

		// Check if the file was opened successfully
		if (!loginFile.is_open()) {
			cout << "Error Opening Login File." << endl;
			return 1;
		}
		cout << "-_-_-_-_-_-_-_ADMIN LOGIN_-_-_-_-_-_-_-\n" << endl;
		// Get username and password from user
		cout << "Enter Administrator Username: ";
		cin >> username;
		cout << "Enter Administrator Password: ";
		cin >> password;

		// Loop through the file to check if the entered credentials match stored ones
		while (loginFile >> storedUsername >> storedPassword) {
			if (username == storedUsername && password == storedPassword) {
				cout << "Login Successful!" << endl;
				system("pause");
				loggedIn = true;
				break;
			}
		}

		// Close the file
		loginFile.close();

		// Check if login was successful
		if (!loggedIn) {
			cout << "Login Failed. Invalid Admin Username or Password." << endl;
			system("pause");
			system("cls");
			goto Invalid_Attempt;
		}

		// Code to be executed after successful login
	Main_screen:
		system("cls");
		cout << "Welcome,Administrator!\n\n Which Operation do you want to perform:\n\n1. Add new User\n2. View Results\n3. Log out\nYour Choice:" << endl;
		int opt_admin;
		cin >> opt_admin;

		switch (opt_admin)
		{
		case 1:
		{
			fstream file;
			file.open("login.txt", ios::app);
			cout << "Enter the Name of Missing Student:" << endl;
			string Miss_Student;
			cin >> Miss_Student;
			cout << "Enter The Password for the Missing Student Account:" << endl;
			int Student_Password;
			cin >> Student_Password;

			file << endl << Miss_Student << endl;
			file << Student_Password << endl;

			cout << endl << "Missing Student Added Successfully..." << endl;
			file.close();
			system("pause");
			system("cls");
			cout << "\nNow Which operation do to want to continue:\n1.Stay Log in & Go Back to Main Screen\n2.Log out & Go Back to Main Login Screen\n3.exit\n Your Choice: " << endl;
			int Admin_Back;
			cin >> Admin_Back;
			if (Admin_Back == 1)
			{
				system("pause");
				system("cls");
				goto Main_screen;
			}
			else if (Admin_Back == 2)
			{
				system("pause");
				system("cls");
				goto Login_screen;
			}
			else if (Admin_Back == 3)
			{
				exit(0);
			}
			else
			{
				cout << "Invalid Choice\n Try again...";
			}
			break;
		}
		case 2:
		{
			system("cls");
			cout << ":::::::::::::Results are::::::::::::::\n";
			//Results
			//Result Process for President
			ifstream input_file("President_input.txt");

			// Read the values from the file
			input_file >> pfst >> pscd >> pthrd;
			// Close the input file

			cout << "\n_-_-_-_-_-_-_-_-_ Result for President _-_-_-_-_-_-_-_-_ " << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment\t Votes" << endl;
			cout << "1.\tAsad Amjad\t7th\t\tBS(CS)\t\t  " << pfst << endl;
			cout << "2.\tZaheer Umar\t7th\t\tBS(SE)\t\t  " << pscd << endl;
			cout << "3.\tSultan Ahmed\t5th\t\tBS(IT)\t\t  " << pthrd << endl;

			cout << "\n" << endl;
			if (pfst > pscd && pfst > pthrd)
				cout << "\n Asad Amjad is Announced as president of HCS for the current session ";
			else if (pscd > pfst && pscd > pthrd)
				cout << "\n Zaheer Umar is Announced as president of HCS for the current session ";
			else if (pthrd > pfst && pthrd > pscd)
				cout << "\n Sultan Ahmed is Announced as president of HCS for the current session ";
			else if (pfst == pscd == pthrd == 0)
				cout << "Result cannot be announced because there is no vote casted to any Candidate...";
			else if (pfst == pscd == pthrd)
				cout << "Draw....\n Each Candiate get equal vote\n Decision can be made by TOSS...";
			else
				cout << "Error in announcing Results...";
			input_file.close();

			//Result Process for Vice President

				// Open the file for reading
			ifstream input_file2("Vice_President_input.txt");

			// Read the values from the file
			input_file2 >> vcfst >> vcscd >> vcthrd;
			// Close the input file


			cout << "\n\n_-_-_-_-_-_-_-_-_ Results for Vice President _-_-_-_-_-_-_-_-_\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment\tVotes" << endl;
			cout << "1.\tAli Altaf\t5th\t\tBS(IT)\t\t  " << vcfst << endl;
			cout << "2.\tUmar Zaman\t7th\t\tBS(CS)\t\t  " << vcscd << endl;
			cout << "3.\tAryaan Rashid\t5th\t\tBS(IT)\t\t  " << vcthrd << endl;

			cout << "\n" << endl;
			if (vcfst > vcscd && vcscd > vcthrd)
				cout << "\n Ali Altaf is Announced as president of HCS for the current session ";
			else if (vcscd > vcfst && vcscd > vcthrd)
				cout << "\n Umar Zaman is Announced as president of HCS for the current session ";
			else if (vcthrd > vcfst && vcthrd > vcscd)
				cout << "\n Aryaan Rashid is Announced as president of HCS for the current session ";
			else if (vcfst == vcscd == vcthrd == 0)
				cout << "Result cannot be announced because there is no vote casted to any Candidate...";
			else if (vcfst == vcscd == vcthrd)
				cout << "Draw....\n Each Candiate get equal vote\n Decision can be made by TOSS...";
			else
				cout << "Error in announcing Results...";

			input_file2.close();

			//Results for Event Manager
			 // Open the file for reading
			ifstream input_file3("Event_Manager_input.txt");

			// Read the values from the file
			input_file3 >> etmrfst >> etmrscd >> etmrthrd;

			cout << "\n\n_-_-_-_-_-_-_-_-_ Results for Event Manager _-_-_-_-_-_-_-_-_\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment\tVotes" << endl;
			cout << "1.\tShehyar Anar\t1th\t\tBS(SE)\t\t" << etmrfst << endl;
			cout << "2.\tMalik Hanan\t3th\t\tBS(CS)\t\t" << etmrscd << endl;
			cout << "3.\tRao Kamran\t7th\t\tBS(SE)\t\t" << etmrthrd << endl;

			cout << "\n" << endl;
			if (etmrfst > etmrscd && etmrfst > etmrthrd)
				cout << "\n Shehyar Anar is Announced as president of HCS for the current session ";
			else if (etmrscd > etmrfst && etmrscd > etmrthrd)
				cout << "\n Malik Hanan is Announced as president of HCS for the current session ";
			else if (etmrthrd > etmrfst && etmrthrd > etmrscd)
				cout << "\n Rao Kamran is Announced as president of HCS for the current session ";
			else if (etmrfst == etmrscd == etmrthrd == 0)
				cout << "Result cannot be announced because there is no vote casted to any Candidate...";
			else if (etmrfst == etmrscd == etmrthrd)
				cout << "Draw....\n Each Candiate get equal vote\n Decision can be made by TOSS...";
			else
				cout << "Error in announcing Results...";
			// Close the input file
			input_file3.close();



			//Results for  Graphic Designer
			   // Open the file for reading
			ifstream input_file4("Graphics_Manager_input.txt");

			// Read the values from the file
			input_file4 >> gcdgfst >> gcdgscd;

			cout << "\n\n_-_-_-_-_-_-_-_-_ Results for Graphic Designer _-_-_-_-_-_-_-_-_\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment\tVotes" << endl;
			cout << "1.\tHanzala Noman\t3th\t\tBS(CS)\t\t" << gcdgfst << endl;
			cout << "2.\tMuhammad Musa\t5th\t\tBS(CS)\t\t" << gcdgscd << endl;

			if (gcdgfst > gcdgscd)
				cout << "\n Hanzala Noman is Announced as president of HCS for the current session ";
			else if (etmrscd > gcdgscd)
				cout << "\n Muhammad Musa is Announced as president of HCS for the current session ";
			else if (gcdgfst == gcdgscd == 0)
				cout << "Result cannot be announced because there is no vote casted to any Candidate...";
			else if (gcdgfst == gcdgscd)
				cout << "Draw....\n Each Candiate get equal vote\n Decision can be made by TOSS...";
			else
				cout << "Error in announcing Results...";

			// Close the input file
			input_file4.close();

			//Results for Social Media Manager
				 // Open the file for reading
			ifstream input_file5("Social_Media_Manager_input.txt");

			// Read the values from the file
			input_file5 >> slmdfst >> slmdscd >> slmdthrd;


			cout << "\n\n_-_-_-_-_-_-_-_-_ Results for Event Manager _-_-_-_-_-_-_-_-_\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment\tVotes" << endl;
			cout << "1.\tAli Zafar\t3th\t\tBS(SE)\t\t" << slmdfst << endl;
			cout << "2.\tAbdullah Zia\t3th\t\tBS(IT)\t\t" << slmdscd << endl;
			cout << "3.\tHamza Rafaqat\t3th\t\tBS(CS)\t\t" << slmdthrd << endl;

			cout << "\n" << endl;
			if (slmdfst > slmdscd && slmdfst > slmdthrd)
				cout << "\n Ali Zafar is Announced as president of HCS for the current session ";
			else if (slmdscd > slmdfst && slmdscd > slmdthrd)
				cout << "\n Abdullah Zia is Announced as president of HCS for the current session ";
			else if (slmdthrd > slmdfst && slmdthrd > slmdscd)
				cout << "\n Hamza Rafaqat is Announced as president of HCS for the current session ";
			else if (slmdfst == slmdscd == slmdthrd == 0)
				cout << "Result cannot be announced because there is no vote casted to any Candidate...";
			else if (slmdfst == slmdscd == slmdthrd)
				cout << "Draw....\n Each Candidate get equal vote\n Decision can be made by TOSS...";
			else
				cout << "Error in announcing Results...";
			// Close the input file
			input_file5.close();
			cout << "\n\n\nNow Which operation do to want to continue:\n1.Stay Log in & Go Back to Main Screen\n2.Log out & Go Back to Main Login Screen\n3.exit\n Your Choice: " << endl;
			int Admin_Back;
			cin >> Admin_Back;
			if (Admin_Back == 1)
			{
				system("pause");
				system("cls");
				goto Main_screen;
			}
			else if (Admin_Back == 2)
			{
				system("pause");
				system("cls");
				goto Login_screen;
			}
			else if (Admin_Back == 3)
			{
				exit(0);
			}
			else
			{
				cout << "Invalid Choice\n Try again...";
			}
			system("pause");
			system("cls");
		}
		case 3:
			system("cls");
			goto Login_screen;
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;

		}
		//case 1 break
		break;
	}

	case 2:	// Login Page Case 2
	{
		string username, password, storedUsername, storedPassword;
		bool loggedIn = false;

		// Open the file containing stored usernames and passwords
		ifstream loginFile("login.txt");

		// Check if the file was opened successfully
		if (!loginFile.is_open()) {
			cout << "Error opening login file." << endl;
			return 1;
		}
	Already_Casted:
		cout << "-_-_-_-_-_-_-_VOTER LOGIN_-_-_-_-_-_-_-\n" << endl;
		// Get username and password from user
		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		cin >> password;

		// Loop through the file to check if the entered credentials match stored ones
		while (loginFile >> storedUsername >> storedPassword) {
			if (username == storedUsername && password == storedPassword) {
				cout << "Login successful!" << endl;
				loggedIn = true;
				break;
			}
		}

		// Close the file
		loginFile.close();

		// Check if login was successful
		if (!loggedIn) {
			cout << "Login Failed. Invalid Admin Username or Password." << endl;
			system("pause");
			system("cls");
			goto Invalid_Attempt;
		}
		string storedUsername_2, storedPassword_2;
		bool loggedIn_2 = false;

		// Open the file containing stored usernames and passwords
		ifstream AEloginFile("Already_entered_login.txt");

		// Check if the file was opened successfully
		if (!AEloginFile.is_open()) {
			cout << "Error opening login file." << endl;
			return 1;
		}
		// Loop through the file to check if the entered credentials match stored ones
		while (AEloginFile >> storedUsername_2 >> storedPassword_2) {
			if (username == storedUsername_2 && password == storedPassword_2) {
				cout << "This Account Already casted Vote...\nPlease Enter Valid Username and Password" << endl;
				again_invalid:
				cout << "Do you want to enter an account again(Y/N):";
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("pause");
					system("cls");
					goto Already_Casted;
					loggedIn_2 = true;
				}
				else if (again == 'N' || again == 'n')
				{
					exit(0);
				}
				else
				{
					cout << "Invalid Choice...\nTry Again...";
					system("pause");
					system("cls");
					goto again_invalid;
				}
				break;
			}
		}

		// Close the file
		AEloginFile.close();
		// Open the file containing stored usernames and passwords
		fstream AEloginFile_2("Already_entered_login.txt", ios::app);
		AEloginFile_2 << endl << username << endl << password;

		// Close the file
		AEloginFile_2.close();
		// Check if login was successful
		if (!loggedIn_2) {
			system("cls");
			// Code to be executed after successful login
			cout << "Welcome, " << username << "!" << endl;
			cout << "VOTER LOGIN" << endl;
			cout << "Please Enter the Votes for your selected Candidates,Pattern will be::" << endl;
			cout << "\nPresident \nVice President\nEvent Manager\nGraphics Designer \nSocial Media Manager \n\n Start Entering VOTES:" << endl;
			system("pause");
			system("cls");
			ifstream input_file("President_input.txt");

			// Read the values from the file
			input_file >> pfst >> pscd >> pthrd;
			// Close the input file
			input_file.close();
		President:
			cout << "\n_-_-_-_-_-_-_-_-_ Voting for President _-_-_-_-_-_-_-_-_\n\nWhich Candidate you want to vote:\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment" << endl;
			cout << "1.\tAsad Amjad\t7th\t\tBS(CS)" << endl;
			cout << "2.\tZaheer Umar\t7th\t\tBS(SE)" << endl;
			cout << "3.\tSultan Ahmed\t5th\t\tBS(IT)\nYour Choice:" << endl;
			cin >> pd;
			switch (pd)
			{
			case 1:
				++pfst;
				cout << "Your vote casted Successfully to Asad Amjad....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				++pscd;
				cout << "Your vote casted Successfully to Zaheer Umar....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				++pthrd;
				cout << "Your vote casted Successfully to Sultan Ahmed....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			default:
				cout << "Invalid Command\n Try Again:" << endl;
				system("pause");
				system("cls");
				goto President;
				break;
			}
			//cout << pfst << pscd << pthrd;

			ofstream output_file("President_input.txt");

			// Write the updated values to the file
			output_file << pfst << "\n" << pscd << "\n" << pthrd;

			// Close the output file
			output_file.close();


			// Open the file for reading
			ifstream input_file2("Vice_President_input.txt");

			// Read the values from the file
			input_file2 >> vcfst >> vcscd >> vcthrd;
			// Close the input file
			input_file2.close();
		Vice_President:
			cout << "\n_-_-_-_-_-_-_-_-_ Voting for Vice President _-_-_-_-_-_-_-_-_\n\nWhich Candidate you want to vote:\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment" << endl;
			cout << "1.\tAli Altaf\t5th\t\tBS(IT)" << endl;
			cout << "2.\tUmar Zaman\t7th\t\tBS(CS)" << endl;
			cout << "3.\tAryaan Rashid\t5th\t\tBS(IT)\nYour Choice:" << endl;
			cin >> vcpd;
			switch (vcpd)
			{
			case 1:
				++vcfst;
				cout << "Your vote casted Successfully to Ali Altaf....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				++vcscd;
				cout << "Your vote casted Successfully to Umar Zaman....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				++vcthrd;
				cout << "Your vote casted Successfully to Aryaan Rashid....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			default:
				cout << "Invalid Command\n Try Again:" << endl;
				system("pause");
				system("cls");
				goto Vice_President;
				break;
			}
			//cout << vcfst << vcscd << vcthrd;
			  // Open the file for writing
			ofstream output_file2("Vice_President_input.txt");

			// Write the updated values to the file
			output_file2 << vcfst << "\n" << vcscd << "\n" << vcthrd;

			// Close the output file
			output_file2.close();


			// Open the file for reading
			ifstream input_file3("Event_Manager_input.txt");

			// Read the values from the file
			input_file3 >> etmrfst >> etmrscd >> etmrthrd;
			// Close the input file
			input_file3.close();
		Event_Manager:
			cout << "\n_-_-_-_-_-_-_-_-_ Voting for Event Manager _-_-_-_-_-_-_-_-_\n\nWhich Candidate you want to vote:\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment" << endl;
			cout << "1.\tShehyar Anar\t1th\t\tBS(SE)" << endl;
			cout << "2.\tMalik Hanan\t3th\t\tBS(CS)" << endl;
			cout << "3.\tRao Kamran\t7th\t\tBS(SE)\nYour Choice:" << endl;
			cin >> etmr;
			switch (etmr)
			{
			case 1:
				++etmrfst;
				cout << "Your vote casted Successfully to Shehyar Anar Mattu....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				++etmrscd;
				cout << "Your vote casted Successfully to Malik Hanan....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				++etmrthrd;
				cout << "Your vote casted Successfully to Rao Kamran....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			default:
				cout << "Invalid Command\n Try Again:" << endl;
				system("pause");
				system("cls");
				goto Event_Manager;
				break;
			}
			//cout << etmrfst << etmrscd << etmrthrd;
				 // Open the file for writing
			ofstream output_file3("Event_Manager_input.txt");

			// Write the updated values to the file
			output_file3 << etmrfst << "\n" << etmrscd << "\n" << etmrthrd;

			// Close the output file
			output_file3.close();

			// Open the file for reading
			ifstream input_file4("Graphics_Manager_input.txt");

			// Read the values from the file
			input_file4 >> gcdgfst >> gcdgscd;
			// Close the input file
			input_file4.close();
		Graphic_Designer:
			cout << "\n_-_-_-_-_-_-_-_-_ Voting for Graphic Designer _-_-_-_-_-_-_-_-_\n\nWhich Candidate you want to vote:\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment" << endl;
			cout << "1.\tHanzala Noman\t3th\t\tBS(CS)" << endl;
			cout << "2.\tMuhammad Musa\t5th\t\tBS(CS)\nYour Choice:" << endl;
			cin >> gcdg;
			switch (gcdg)
			{
			case 1:
				++gcdgfst;
				cout << "Your vote casted Successfully to Hanzala Noman....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				++gcdgscd;
				cout << "Your vote casted Successfully to Muhammad Musa....";
				cout << endl;
				system("pause");
				system("cls");
				break;

			default:
				cout << "Invalid Command\n Try Again:" << endl;
				system("pause");
				system("cls");
				goto Graphic_Designer;
				break;
			}
			//cout << gcdgfst << gcdgscd ;
				// Open the file for writing
			ofstream output_file4("Graphics_Manager_input.txt");

			// Write the updated values to the file
			output_file4 << gcdgfst << "\n" << gcdgscd;

			// Close the output file
			output_file4.close();

			// Open the file for reading
			ifstream input_file5("Social_Media_Manager_input.txt");

			// Read the values from the file
			input_file5 >> slmdfst >> slmdscd >> slmdthrd;
			// Close the input file
			input_file5.close();
		Social_Media_Manager:
			cout << "\n_-_-_-_-_-_-_-_-_ Voting for Social Media Manager _-_-_-_-_-_-_-_-_\n\nWhich Candidate you want to vote:\n" << endl;
			cout << "::Candidates Detail::\nSr.\tName\t\tSemester\tDepartment" << endl;
			cout << "1.\tAli Zafar\t3th\t\tBS(SE)" << endl;
			cout << "2.\tAbdullah Zia\t3th\t\tBS(IT)" << endl;
			cout << "3.\tHamza Rafaqat\t3th\t\tBS(CS)" << endl;

			cin >> slmd;
			switch (slmd)
			{
			case 1:
				++slmdfst;
				cout << "Your vote casted Successfully to Ali Zafar....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				++slmdscd;
				cout << "Your vote casted Successfully to Abdullah Zia....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				++slmdthrd;
				cout << "Your vote casted Successfully to Hamza Rafaqat....";
				cout << endl;
				system("pause");
				system("cls");
				break;
			default:
				cout << "Invalid Command\n Try Again:" << endl;
				system("pause");
				system("cls");
				goto Social_Media_Manager;
				break;
			}
			//cout << slmdfst << slmdscd << slmdthrd << slmdfth;
				// Open the file for writing
			ofstream output_file5("Social_Media_Manager_input.txt");

			// Write the updated values to the file
			output_file5 << slmdfst << "\n" << slmdscd << "\n" << slmdthrd;

			// Close the output file
			output_file5.close();
			cout << "\n\nYour all Votes Successfully Casted...." << endl;
			cout << "Thanks For Voting :)";
			cout << endl;
			system("pause");
			system("cls");
			goto main_manu;
		}
		break;
	}
	case 3://Login Page Case 3
	{
		exit(0);
		break;
	}
	default:
	{
		cout << "Invalid Choice....\nPlease Enter Correct choice Again\n:" << endl;
		goto  Invalid_Attempt;
		break;
	}
	}

	return 0;
