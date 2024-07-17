#include <bits/stdc++.h>
using namespace std;

//um dos códigos mais amaldiçoados q eu já fiz

vector<string> tokenizer(string s, char del) {
    vector<string> ret;
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        ret.push_back(word);
    }
    return ret;
}

void processRequest(string r, vector<std::function<bool(string)>> chain){
    bool lastResult = false;
    int i = 0;
    for (auto it : chain)
        if(it(r)) return;

    cerr << "Error: request could not be fulfilled" << endl;
}

int main() {

    vector<std::function<bool(string)>> chain = {
        [](string r) {
            try {
                int x = stoi(r);
                cout << "It's a number " << x << endl;
                return true;
            }
            catch (...) {
                return false;
            }
        },
        [](string r) {
            if (r[0] == '{') {
                cout << "It's an array of lengh: " << tokenizer(r, ',').size() << endl;
                return true;
            } else return false;
        },
        [](string r) {
            if (r[0] == '\"') {
                cout << "It's a string: " << r << endl;
                return true;
            }
            else return false;
        }
    };



    processRequest("1", chain);
    processRequest("{1, 2, 3}", chain);
    processRequest("\"{1, 2, 3}\"", chain);

    return 0;
}

