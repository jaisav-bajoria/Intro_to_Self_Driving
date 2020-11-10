#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Function Declaration
vector <double> sense(vector <double> p, vector <string> world, string measurement, double pHit, double pMiss);
vector <double> move(vector <double> p, int motion, double pExact, double pOvershoot, double pUndershoot);
void print(vector <double> p);

int main() {

	double pHit = 0.6;
	double pMiss = 0.2;
	double pExact = 0.8;
	double pOvershoot = 0.1;
	double pUndershoot = 0.1;

	vector <double> p (5, 0.2);
	vector <int> motions(2, 1);

	vector <string> measurements;
	measurements.push_back("red");
	measurements.push_back("green");
	
	vector <string> world;
	world.push_back("green");
	world.push_back("red");
	world.push_back("red");
	world.push_back("green");
	world.push_back("green");

	for (int k = 0; k < measurements.size(); k++) {
		p = sense(p, world, measurements[k], pHit, pMiss);
		p = move(p, motions[k], pExact, pOvershoot, pUndershoot);
	}

	print(p);

	return 0;
}

//Function Defintion
vector <double> sense(vector <double> p, vector <string> world, string measurement, double pHit, double pMiss) {
	double sum = 0;
	bool hit;

	vector <double> q(p.size());
	for (int i = 0; i < p.size(); i++) {
		hit = (measurement == world[i]);
		q[i] = p[i] * (pHit * hit + (1 - hit) * pMiss);
		sum += q[i];
	}
	for (int i = 0; i < q.size(); i++) {
		q[i] = q[i] / sum;
	}
	return q;
}


vector <double> move(vector <double> p, int motion, double pExact, double pOvershoot, double pUndershoot) {
	double s = 0;
	vector <double> q(p.size());
	for (int i = 0; i < p.size(); i++) {
		if (i - motion < 0) {
			s = pExact * p[(i - motion) + p.size()];
		}
		else {
			s = pExact * p[(i - motion) % p.size()];
		}
		if (i - motion - 1 < 0) {
			s = s + pOvershoot * p[(i - motion - 1) + p.size()];
		}
		else {
			s = s + pOvershoot * p[(i - motion - 1) % p.size()];
		}
		if (i - motion + 1 < 0) {
			s = s + pUndershoot * p[(i - motion + 1) + p.size()];
		}
		else {
			s = s + pUndershoot * p[(i - motion + 1) % p.size()];
		}
		q[i] = s;
	}
	return q;
}

void print(vector <double> p) {
	for (int i = 0; i < p.size(); i++) {
		cout << p[i] << " ";
	}
	cout << endl;

}