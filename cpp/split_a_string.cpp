#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimeter){
    int i = 0;
    int n = s.size();
    vector<string>splitted;
    while(i < n){
        int j = i;
        while(j+1 < n && s[j+1] != delimeter)
            j++;
        splitted.push_back(s.substr(i, j-i+1));
        i = j+2;
    }
    return splitted;
}
