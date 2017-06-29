# Encryption
#pragma once 

	//has the following functions
	//1. Read the file 
	//2. Inverse of the matrix
	//3. Multiply the inverse 
	//4. Write output to the console



	void myminor(int key[3][3], int minor[3][3]) {
	minor[0][0] = key[1][1] * key[2][2] - key[2][1] * key[1][2];
	minor[0][1] = key[1][0] * key[2][2] - key[2][0] * key[1][2];
	minor[0][2] = key[1][0] * key[2][1] - key[2][0] * key[1][1];
	minor[1][0] = key[0][1] * key[2][2] - key[2][1] * key[0][2];
	minor[1][1] = key[0][0] * key[2][2] - key[2][0] * key[0][2];
	minor[1][2] = key[0][0] * key[2][1] - key[2][0] * key[0][1];
	minor[2][0] = key[0][1] * key[1][2] - key[1][1] * key[0][2];
	minor[2][1] = key[0][0] * key[1][2] - key[1][0] * key[0][2];
	minor[2][2] = key[0][0] * key[1][1] - key[1][0] * key[0][1];
}
void mycofactor(int minor[3][3], int cofactor[3][3]) {
	cofactor[0][0] = minor[0][0];
	cofactor[0][1] = minor[0][1] * -1;
	cofactor[0][2] = minor[0][2];
	cofactor[1][0] = minor[1][0] * -1;
	cofactor[1][1] = minor[1][1];
	cofactor[1][2] = minor[1][2] * -1;
	cofactor[2][0] = minor[2][0];
	cofactor[2][1] = minor[2][1] * -1;
	cofactor[2][2] = minor[2][2];
	return;
}
void myajoint(int cofactor[3][3], int ajoint[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ajoint[i][j] = cofactor[j][i];
		}
	}
	return;
}
double determinant(int key[3][3])
{
	double determinant = 0;
	determinant =
		key[0][0] * key[1][1] * key[2][2]
		+ key[0][1] * key[1][2] * key[2][0]
		+ key[0][2] * key[1][0] * key[2][1]
		- key[2][0] * key[1][1] * key[0][2]
		- key[2][1] * key[1][2] * key[0][0]
		- key[2][2] * key[1][0] * key[0][1];

	return determinant;
}
void myinverse(int key[3][3], int minor[3][3], int cofactor[3][3], int ajoint[3][3], double inverse[3][3], bool &flag) {
	double x;
	x = determinant(key);
	if ((x != 0)) {
		myminor(key, minor);
		mycofactor(minor, cofactor);
		myajoint(cofactor, ajoint);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				inverse[i][j] = ajoint[i][j] * double((1.0 / x));
			}
		}
		bool flag = false;
	}


}
void mydecryptedmatrix(double inverse[3][3], double multiply[3][1], double decryptedmatrix[3][1]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			decryptedmatrix[i][0] += multiply[j][0] * inverse[i][j];
		}
	}
	return;
}

