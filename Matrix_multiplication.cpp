#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector <double> > multiply(vector <vector <double> > matrix1, vector <vector <double> > matrix2);
void print(vector <vector <double> > matrix1, vector <vector <double> > matrix2, vector < vector <double> > mul);

int main() {

	vector < vector <double> > matrix1 (5, vector <double> (3,2));
	vector < vector <double> > matrix2 (3, vector <double> (5,5));
	vector < vector <double> > mul(5, vector <double> (5,0));
	bool hit;

	hit = (matrix1[0].size() == matrix2.size());
	if (hit == 1) {
		mul = multiply(matrix1, matrix2);
		print(matrix1, matrix2, mul);
	}
	else {
		cout << "The two matrices cannot be multiplied" << endl;
	}
	return 0;
}

vector <vector <double> > multiply(vector <vector <double> > matrix1, vector <vector <double> > matrix2) {
	vector <vector <double> > res(5, vector <double>(5, 0));

	for (int row1 = 0; row1 < matrix1.size(); row1++) {
		for (int col2 = 0; col2 < matrix2[0].size(); col2++) {
			res[row1][col2] = 0;
			for (int col1 = 0; col1 < matrix1[0].size(); col1++) {
				res[row1][col2] += matrix1[row1][col1] * matrix2[col1][col2];
			}
		}
		
	}
	return res;
}

void print(vector <vector <double> > matrix1, vector <vector <double> > matrix2, vector < vector <double> > mul) {
	for (int row = 0; row < matrix1.size(); row++) {
		for (int column = 0; column < matrix2[0].size(); column++) {
			cout << mul[row][column] << " ";
		}
		cout << endl;
	}
}