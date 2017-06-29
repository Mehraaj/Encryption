# Encryption

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>            
#include <ctime>
#include <iomanip>
#include <fstream>
#include "../../../VS Headers/Encryption.h"  /*will change based on header file location*/
#include "../../../VS Headers/Decryption.h"	/*will change based on header file location*/

using namespace std;

int main()
{
	string filename;
	int B, C;
	int A;
	char text[100];



	cout << endl;
	cout << "                     *     *    * *******   *     ******   *******  **     **  *****    " << endl;
	cout << "                      *   * *  *  *******   *     *        *     *  ** * * **  *****    " << endl;
	cout << "                        *     *   *******   ***** ******   *******  **  *  **  *****    " << endl;
	cout << endl;


	cout << "                                            *********   *******                       " << endl;
	cout << "                                                *       *     *                       " << endl;
	cout << "                                                *       *     *                       " << endl;
	cout << "                                                *       *******                       " << endl;


	cout << endl;
	cout << "                             *     *     *   *    *   **    *******  *    _******  " << endl;
	cout << "                              *  *    * *    ******  ****      *           *****_  " << endl;
	cout << "                                *      *     *    *  *  *      *          *****    " << endl;
	cout << endl;


	cout << "                                        *********   *     *   ******              " << endl;
	cout << "                                            *       *******   ******              " << endl;
	cout << "                                            *       *     *   ******              " << endl;
	cout << endl;


	cout << "                                      ******   *******  *******  *****    " << endl;
	cout << "                                      *        *     *  *      * *****    " << endl;
	cout << "                                      ******   *******  *******  *****    " << endl;

	cout << endl;
	system("color BC");
	Sleep(200);
	system("color F5");
	Sleep(200);
	system("color 20 ");
	Sleep(200);
	system("color C5 ");
	Sleep(200);
	system("color 2B ");
	Sleep(200);
	system("color F2 ");
	Sleep(200);
	system("color C1 ");
	Sleep(200);
	/*srand(time(0));

	B = rand() % 6;

	switch (B)
	{
	case 0:
	system("color BC");
	Sleep(50);
	system("cls");
	break;
	case 1:
	system("color F5");
	Sleep(50);
	system("cls");
	break;
	case 2:
	system("color 20 ");
	Sleep(50);
	system("cls");
	break;
	case 3:
	system("color C5 ");
	Sleep(50);
	system("cls");
	break;
	case 4:
	system("color 2B ");
	Sleep(50);
	system("cls");
	break;
	case 5:
	system("color F2 ");
	Sleep(50);
	system("cls");
	break;
	case 6:
	system("color C1 ");
	Sleep(50);
	system("cls");
	break;
	}
	}*/

	system("color 02");

	//system("pause");
	/*cout << endl;
	cout << "                     *     *    * *******   *     ******   *******  **     **  *****    " << endl;
	cout << "                      *   * *  *  *******   *     *        *     *  ** * * **  *****    " << endl;
	cout << "                        *     *   *******   ***** ******   *******  **  *  **  *****    " << endl;
	cout << endl;


	cout << "                                            *********   *******                       " << endl;
	cout << "                                                *       *     *                       " << endl;
	cout << "                                                *       *     *                       " << endl;
	cout << "                                                *       *******                       " << endl;


	cout << endl;
	cout << "                             *     *     *   *    *   **    *******  *    _******  " << endl;
	cout << "                              *  *    * *    ******  ****      *           *****_  " << endl;
	cout << "                                *      *     *    *  *  *      *          *****    " << endl;
	cout << endl;


	cout << "                                        *********   *     *   ******              " << endl;
	cout << "                                            *       *******   ******              " << endl;
	cout << "                                            *       *     *   ******              " << endl;
	cout << endl;


	cout << "                                      ******   *******  *******  *****    " << endl;
	cout << "                                      *        *     *  *      * *****    " << endl;
	cout << "                                      ******   *******  *******  *****    " << endl;

	cout << endl;*/

	cout << " Press A to start!" << endl;

	if (_kbhit)
		A = _getch();
	if (A == 'a' || A == 'A')
		system("cls");

	cout << "Encryption or Decryption? (E for encryption, D for decryption): ";

	if (_kbhit)
		A = _getch();
	if (A == 'e' || A == 'E')
	{
		/*-----------------------------------------------ENCRYPTION----------------------------------------------------*/


		char message[100] = { ' ' };
		bool flag = true;
		cout << "Enter a message: ";
		cin.getline(message, 100);

		ifstream Infile;
		ofstream Outfile;
		Outfile.open("Encrypted.txt", ios::app);

		if (!Outfile.is_open())
		{
			cout << "Error. Encryption File is open. " << endl;
			exit(1);
		}

		//cout << message << endl; //debug code
		//cout << "The string length is: " << strlen(message) << endl;
		//cout << endl << "message: " << endl;
		/*for (int j = 0; j < strlen(message); j++)
		{
		cout << message[j] << " ";
		}*/
		cout << endl;
		//initialize all arrays to zero
		char number[3][1] = { 0, 0, 0 };

		int key[3][3];
		/*	double inverse[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 };

		int cofactor[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 },
		ajoint[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 },
		minor[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 };
		*/



		keygen(key);
		//myinverse(key, minor, cofactor, ajoint, inverse, flag);
		int count = 0;
		for (int count = 0; count < strlen(message); count += 3) {
			double decryptedmatrix[3][1] = { 0, 0, 0 };
			double multiply[3][1] = { 0, 0, 0 };
			number[0][0] = message[count];
			number[1][0] = message[count + 1];
			number[2][0] = message[count + 2];
			///cout << endl << "number: " << endl;
			/*for (int j = 0; j < 3; j++)
			{
			cout << int(number[j][0]) << "  ";
			}
			cout << endl << endl;*/
			mymultiply(number, key, multiply);
			//cout << "multiply: " << endl;
			Outfile << multiply[0][0] << endl;
			Outfile << multiply[1][0] << endl;
			Outfile << multiply[2][0] << endl;
			//cout << "LETS GO";

		}
		Outfile.close();

		return 0;
	}

	if (_kbhit)
		A = _getch();
	if (A == 'd' || A == 'D')
	/*----------------------------------------------------DECRYPTION----------------------------------------------------*/
	{
		char number[3][1] = { 0, 0, 0 };

		int key[3][3];
		double inverse[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 };

		int cofactor[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 },
			ajoint[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 },
			minor[3][3] = { 0, 0, 0, 0, 0, 0, 0,0, 0 };


		ifstream Infile;
		ofstream Outfile;

		cout << endl << "Enter the file name where the encrypted message is stored: ";
		cin >> filename;

		Infile.open(filename); // opens file 
		

								//	ifstream Infile(filename); 
		if (!Infile.is_open())
		{
			cout << "Error. Encryption File is open. " << endl;
			exit(1);
		}



		int a ;
		int line = 0;
		int i = 0;
		int j = 0;
		while (!Infile.eof()) {
			Infile >> a;
			if (line < 9) {
				key[i][j] = a;
			//	cout << key[i][j] << endl;
				++j;
				if (j == 3)
				{
					j = 0;
					++i;
				}
			}
			line++;

			if (line > 9) {
				while(!Infile.eof())
				{
					bool flag = true;
					double decryptedmatrix[3][1] = { 0, 0, 0 };
					double multiply[3][1] = { 0, 0, 0 };
					multiply[0][0] = a;
					Infile >> a;
					++line;
					multiply[1][0] = a;
					Infile >> a;
					++line;
					multiply[2][0] = a;
					Infile >> a;
					++line;

					myinverse(key, minor, cofactor, ajoint, inverse, flag);
					/*cout << endl << "key: " << endl;
					for (int i = 0; i < 3; i++)
					{
					for (int j = 0; j < 3; j++)
					{
					cout << key[i][j] << "  ";
					}
					cout << endl;
					}
					cout << endl << "inverse: " << endl;
					for (int i = 0; i < 3; i++)
					{
					for (int j = 0; j < 3; j++)
					{
					cout << inverse[i][j] << "  ";
					}
					cout << endl;
					}
					cout << endl << "multiply: " << endl;
					for (int i = 0; i < 3; i++)
					{
					for (int j = 0; j < 1; j++)
					{
					cout << multiply[i][j] << "  ";
					}
					cout << endl;
					}
					cout << endl << endl << "decrypted" << endl;*/
					mydecryptedmatrix(inverse, multiply, decryptedmatrix);
					/*	cout << int(decryptedmatrix[0][0]) << endl;
					cout << int(decryptedmatrix[1][0]) << endl;
					cout << int(decryptedmatrix[2][0]) << endl;*/
					for (int i = 0; i < 3; i++)
						decryptedmatrix[i][0] = decryptedmatrix[i][0] + 0.5;
					cout << char(decryptedmatrix[0][0]);
					cout << char(decryptedmatrix[1][0]) ;
					cout<< char(decryptedmatrix[2][0]) ;
				}

				


			}
		}
		Infile.close();

		
		

		return 0;

	}
}
