#pragma once 

#include<iostream>
#include<cstdlib>
#include<time.h>
	using namespace std;

//Has the following functions
//1. Read the user input
//2. Make a file 
//3. Genterate random key
//4. Multiply key
//5. Write output to the file

void keygen(int key[3][3]) {
#include <fstream>

	ofstream Outfile;
	ifstream Infile; 

	Outfile.open("Encrypted.txt"); // opens file
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			key[i][j] = 1 + rand() % 10;
		//	cout << key[i][j] << endl;
			Outfile << key[i][j] << endl;
		}
	}
	Outfile.close();
	return;
}
void mymultiply(char number[3][1], int key[3][3], double multiply[3][1]) {
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			multiply[i][0] += key[i][k] * int(number[k][0]);
		}
	}
}


