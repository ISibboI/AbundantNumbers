#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

string vtos(vector<int>& v) {
    stringstream ss;
    
    ss << "[";
    
    for (unsigned int i = 0; i < v.size(); i++) {
        ss << v[i];
        
        if (i < v.size() - 1) {
            ss << ", ";
        }
    }
    
    ss << "]";
    
    return ss.str();
}

vector<int>* all_factors(int n) {
    vector<int> *factors = new vector<int>();
    int max_check = floor(sqrt(n));
    
    for (int i = 1; i <= max_check; i++) {
        if (n % i == 0) {
            factors->push_back(i);
            
            int i_2 = n / i;
            if (i_2 != i && i_2 != n) {
                factors->push_back(i_2);
            }
        }
    }
    
    return factors;
}

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        cout << "Argument missing" << endl;
        return 1;
    }

    string arg(argv[1]);
    const int n = stoi(arg);
    int i = 0;
    
    for (int current = 12; i < n; current++) {
        vector<int> *factors = all_factors(current);    
        
        // cout << current << ": " << vtos(*factors) << endl;
        
        int sum = 0;
        for (unsigned int f = 0; f < factors->size(); f++) {
            sum += (*factors)[f];
        }
        
        if (sum > current) {
            cout << current << endl;
            i++;
        }
        
        delete factors;
    }
    
    return 0;
}
