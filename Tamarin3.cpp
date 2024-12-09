
#include<iostream>
#include <map>
#include <cctype>
#include <string>
using namespace std;

struct student {
	char name[10];
	char field[10];
	float avr;
};

void question1() {

	int n = 0, count = 0, A[100], B[100];

	cout << "Enter array size: ";
	cin >> n;

	cout << "Enter first arrays items : " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cout << "Enter second arrays items : " << endl;
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i] == B[j]) {
				count++;

			}
		}
	}

	cout << "Similer indexes count => " << count;

}

void question2() {
	int n = 0, A[100][100] = { 0 }, B[100][100] = { 0 };
	bool isSymmetric = true;

	cout << "Enter array size: ";
	cin >> n;

	cout << "Enter arrays items : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a = 0;
			cin >> a;
			A[i][j] = a;
			B[j][i] = a;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] != B[i][j])
				isSymmetric = false;
		}
	}

	if (isSymmetric)
		cout << "Your matris is Symmetric! ";
	else
		cout << "Your matris is NOT Symmetric! ";



}

void question3() {
	int n = 0, A[100][100] = { 0 }, countST[100] = { 0 }, countSA[100] = { 0 }, countMainGH = 0, countSecondGH = 0;
	bool isMagical = true;

	cout << "Enter array size: ";
	cin >> n;

	cout << "Enter arrays items : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = A[i][j];
			countST[i] += num;
			countSA[j] += num;
			if (i == j) {
				countMainGH += num;
			}
			if ((n - i - 1) == (n - j - 1)) {
				countSecondGH += A[n - i - 1][j];
			}
		}
	}

	if (countMainGH == countSecondGH) {
		for (int i = 0; i < n; i++) {
			if (countST[i] != countMainGH || countSA[i] != countMainGH) isMagical = false;
		}
	}


	if (isMagical)
		cout << "Your matris is Magical! ";
	else
		cout << "Your matris is NOT Magical! ";



}

void question4() {
	int n = 0, A[100] = { 0 };

	cout << "Enter array size: ";
	cin >> n;

	cout << "Enter arrays items : " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cout << A[i];
	}
	cout << endl;

	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j < (n - i); j++) {
			if (A[j] > A[j + 1]) {

				int a = A[j];
				A[j] = A[j + 1];
				A[j + 1] = a;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		cout << A[i];
	}
	cout << endl;
}

void question5() {
	char input[100];
	cout << "Enter the text: ";
	cin.ignore();
	cin.getline(input, 100);
	bool isSpace = true;
	for (int i = 0; i < 100; i++) {
		if (isSpace) {
			int code = int(input[i]);
			if (code >= 97) {
				input[i] = char(code - 32);
			}
			isSpace = false;
		}

		if (input[i] == ' ') {
			isSpace = true;
		}
	}


	cout << "output: " << input << endl;

}

void question6() {
	char A[100], B[100], res[100];
	cout << "Enter the first string: ";
	cin.ignore();
	cin.getline(A, 100);
	cout << "Enter the second string: ";
	cin.getline(B, 100);

	int Aindex = 0;
	int Bindex = 0;
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0) {
			res[i] = A[Aindex++];
		}
		else {
			res[i] = B[Bindex++];
		}

	}


	cout << "output: " << res << endl;

}

void question7() {
	char A[100], B[100], D[2][32];
	string C;
	cout << "Enter the first string: ";
	cin.ignore();
	cin.getline(A, 100);
	cout << "Enter the second string: ";
	cin.getline(B, 100);

	C = A;
	C += B;

	map<char, int> charCount;

	for (char ch : C) {
		ch = tolower(ch);
		charCount[ch]++;
	}

	for (auto& entry : charCount) {
		cout << "'" << entry.first << "': " << entry.second << endl;
	}


}

void question8() {

	student students[10];

	student temp;


	for (int i = 0; i < 10; i++) {
		cout << "stdent name" << i + 1 << ": ";
		cin >> students[i].name;

		cout << "student field" << i + 1 << ": ";
		cin >> students[i].field;

		cout << "studaent average" << i + 1 << ": ";
		cin >> students[i].avr;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (students[j].avr < students[j + 1].avr) {
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << "name: " << students[i].name << ", field: " << students[i].field << ", avreage: " << students[i].avr << endl;
	}
}

int getNumber(char ch) {
	switch (ch) {
	case '0':
		return 0;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	default:
		return 10;
		break;
	}
}


void question9() {
	char input[100];
	int sum = 0;
	int number[10] = { 0 };
	int numIndex = 0;

	cout << "Enter String : ";
	cin.ignore();
	cin.getline(input, 100);

	for (int i = 0; input[i] != '\0'; i++) {
		char ch = input[i];
		int num = getNumber(ch);

		if (num != 10) {
			number[numIndex++] = num;
		}
		else {
			if (numIndex > 0) {
				number[numIndex] = '~'; 

				int b = 0;
				for (int i = 0; number[i] != '~'; i++) {
					b = (b * 10) + number[i];
				}

				sum += b;  
				numIndex = 0; 
			}
		}
	}

	if (numIndex > 0) {
		number[numIndex] = '~';
		int b = 0;
		for (int i = 0; number[i] != '~'; i++) {
			b = (b * 10) + number[i];
		}
		sum += b;
	}

	cout << "sum : " << sum << endl;

}




void main() {
	cout << "Whith question do you wnat to run? ";
	int qNumber = 0;
	cin >> qNumber;
	switch (qNumber) {
	case 1:
		question1();
		break;
	case 2:
		question2();
		break;
	case 3:
		question3();
		break;
	case 4:
		question4();
		break;
	case 5:
		question5();
		break;
	case 6:
		question6();
		break;
	case 7:
		question7();
		break;
	case 8:
		question8();
		break;
	case 9:
		question9();
		break;

	default:
		break;
	}
}
