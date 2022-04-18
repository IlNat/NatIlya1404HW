#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int** crMatrx(int rw, int cl, bool& crm) {
	int** mtrx = new int* [rw];
	for (int i = 0; i < rw; i++) {
		mtrx[i] = new int[cl] {};
		for (int j = 0; j < cl; j++) {
			mtrx[i][j] = rand() % 10;
		}
	}
	crm = true;
	return mtrx;
}

void print(int* mtrx[], int rw, int cl) {
	for (int i = 0; i < rw; i++) {
		for (int j = 0; j < cl; j++) {
			cout << mtrx[i][j] << ' ';
		}
		cout << '\n';
	}
}

void delmtrx(int* mtrx[], int rw, bool& crm) {
	for (int i = 0; i < rw; i++) {
		delete[] mtrx[i];
	}
	delete[] mtrx;
	crm = false;
}



int main()
{
	srand(time(0));
	int c{};
	bool crm = false;
	int** mtrx{};
	while (c != 4){
		cout << "Create matrix - 1.\nPrint matrix - 2.\nDelete matrix - 3.\nQuit program - 4.\n";
		cin >> c;
		switch (c) {
		case 1: {
			cout << "Creating matrix with default values.\n";
			mtrx = crMatrx(10, 20, crm);
			cout << "Matrix created!\n";
			break;
			}
		case 2: {
			
			if (crm == false) {
				cout << "Matrix didn't created!\n";
			}
			else {
				cout << "Printing matrix.\n";
				print(mtrx, 10, 20);
			}
			break;
		}
		case 3: {
			cout << "Deleting matrix.\n";
			delmtrx(mtrx, 10, crm);
			cout << "Matrix was deleted.\n";
			break;
		}
		case 4: {
			cout << "Program is closing.\n";
			break;
		}
		default: {
			cout << "There isn't such command.\n";
			break;
		}
		}
		
	}
}
