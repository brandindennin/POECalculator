#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

/*
	This program is designed to gather the physical damage per second of
	weapon in the game Path of Exile. It takes in the physical damage after
	copy + pasteing it into the file DPS.txt. You may need to create a .txt for this to work.
	This program was made by Brandin Dennin.
*/

using namespace std;
int main() {

	//Variables Needed for the DPS Calculation
	ifstream inFile;
	string line;
	string savedLine1;
	string savedLine2;

	//Open the file for reading
	inFile.open("DPS.txt");

	//Grabs the minimum damage for the DPS Calculator
	bool flag = true;
	while (inFile >> line && flag) {
		if (line == "Damage:") {
			
			inFile >> line;
			savedLine1 = line;
			flag = false;
		}
	}

	//Grabs the maximum damage for the DPS Calculator
	flag = true;
	while (inFile >> line && flag) {
		if (line == "Second:") {
			
			inFile >> line;
			savedLine2 = line;
			flag = false;
		}
	}

	//Store the numbers into the proper variable based on the length of the string
	string lowerPhys;
	string higherPhys;

	if (savedLine1.length() == 7) {
		lowerPhys = savedLine1.substr(0, 3);
		higherPhys = savedLine1.substr(4, 6);
	}

	else if(savedLine1.length() == 6) {
		lowerPhys = savedLine1.substr(0, 2);
		higherPhys = savedLine1.substr(3, 6);
	}
	else if (savedLine1.length() == 5) {
		lowerPhys = savedLine1.substr(0, 2);
		higherPhys = savedLine1.substr(3, 5);
		cout << lowerPhys << " " << higherPhys << endl;
	}
	else if (savedLine1.length() == 4) {
		lowerPhys = savedLine1.substr(0, 1);
		higherPhys = savedLine1.substr(2, 4);
		cout << lowerPhys << " " << higherPhys << endl;
	}
	else if (savedLine1.length() == 3) {
		lowerPhys = savedLine1.substr(0, 1);
		higherPhys = savedLine1.substr(2, 3);
		cout << lowerPhys << " " << higherPhys << endl;
	}
	
	//Converts the string number into a float number for calculation purposes
	float floatAPS = atof(savedLine2.c_str());
	int intlowerPhys = atoi(lowerPhys.c_str());
	int inthigherPhys = atoi(higherPhys.c_str());


	//Display the Physical DPS
	cout << "Physical DPS: " << static_cast<float>((((intlowerPhys + inthigherPhys)/2)*floatAPS))<< endl;
	

	//Close the file
	inFile.close();
	




	system("pause");
	return 0;



}