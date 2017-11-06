#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <utility>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;
using std::pair;

void initial_data(string filename, vector<int> &v) {
	ifstream fin;
	fin.open(filename.c_str());
	size_t n;
	while (fin >> n) {
		v.push_back(n);
	}

	fin.close();
}

void show(vector<int> &v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int minimum(int a, int b) {
	if (a > b){
       		return b;
        }
	else return a;
}

int maximum(int a, int b) {
        if (a < b){
                return b;
        }
        else return a;
}

pair<int, int> minmax(int a, int b) {
	pair<int, int> temp;
	if (a > b) temp = std::make_pair(b, a);
	else temp = std::make_pair(a, b);

	return temp;
}

pair<int,int> min_max_select(vector<int> &v) {
	pair<int, int> min_max;
	int min, max;
	if (v.size() % 2 != 0) {
		min = max = v[0];
		for (size_t i = 1; i < v.size() - 1; i+=2) {
			auto temp1 = minmax(v[i], v[i+1]);
			//min = temp1.first; max = temp1.second;
			min = minimum(temp1.first, min);
			max = maximum(temp1.second, max);
                }
		min_max = std::make_pair(min, max);
		return min_max;
	}
	else {
		min = minimum(v[0], v[1]); max = maximum(v[0], v[1]);
		for (size_t i = 2; i < v.size() - 1; i+=2) {
			auto temp1 = minmax(v[i], v[i+1]);
                        //min = temp1.first; max = temp1.second;
                        min = minimum(temp1.first, min);
                        max = maximum(temp1.second, max);
		}
		min_max = std::make_pair(min, max);
		return min_max;
	}
}

int main() {

	vector<int> v;
	initial_data("second.txt", v);
	show(v);
	pair<int, int> ans = min_max_select(v);
	cout << ans.first << " " << ans.second << endl;
	v.clear();

        initial_data("third.txt", v);
        show(v);
        pair<int, int> ans1 = min_max_select(v);
        cout << ans1.first << " " << ans1.second << endl;
        v.clear();

        initial_data("forth.txt", v);
        show(v);
        pair<int, int> ans2 = min_max_select(v);
        cout << ans2.first << " " << ans2.second << endl;
        v.clear();

	return 0;
}



