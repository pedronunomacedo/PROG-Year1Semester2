#include<iostream>
#include<vector>
using namespace std;

vector<unsigned int> genRandom(unsigned int n, unsigned int m) {
	vector<unsigned int> v;
	for (unsigned int i = 0; i < n; i++) {
		v.push_back(rand() % (m + 1));
	}

	return v;
}

unsigned int vectorReduce(const vector<unsigned int>& v1, vector<unsigned int>& v2) {
	unsigned int counter = 0;

	for (size_t i = 0; i < v1.size(); i++) {
		for (size_t j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {
				v2.erase(v2.begin() + j);
				counter++;
			}
		}
	}

	return counter;
}

int main() {
	// ex.2 a)
	//vector<unsigned int> v = genRandom(10, 20);

	/*for (unsigned int i = 0; i < 10; i++) {
		cout << " v[" << i << "] = " << v[i] << endl;
	}*/


	// ex.2 b)
	//vector<unsigned int> v1 = { 12, 18, 7 , 1, 16, 20, 9, 0, 6, 2 };
	//vector<unsigned int> v2 = { 13, 18, 6, 9, 2, 8, 13, 13, 2, 5 };

	//unsigned int modified = vectorReduce(v1, v2);
	//cout << " v2 = {";
	//for (size_t i = 0; i < v2.size(); i++) {
	//	if (i != (v2.size() - 1)) {
	//		cout << v2[i] << ", ";
	//	}
	//	else {
	//		cout << v2[i] << "}" << endl;
	//	}
	//}
	//cout << " Were modified " << modified << " ." << endl;

	// ex.2 c)
	//unsigned int n, m;
	//cout << " n? "; cin >> n;
	//cout << " m? "; cin >> m;
	//vector<unsigned int> v1 = genRandom(n, m);
	//vector<unsigned int> v2 = genRandom(n, m);
	//unsigned int counter = vectorReduce(v1, v2);
	//for (size_t i = 0; i < v1.size(); i++) {
	//	cout << " " << v1[i];
	//} cout << endl;
	//for (size_t i = 0; i < v2.size(); i++) {
	//	cout << " " << v2[i];
	//} cout << endl;
	//cout << " " << counter << " elements where removed from 2nd vector!" << endl;

	// ex. d)

}