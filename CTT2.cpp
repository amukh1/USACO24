#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string cows = "";
    cin >> cows;

    string temp = cows;
    bool looping = true;
    bool has_isolation = false;
    // check if there is any 1s surrounded by 0s or null
    for(int i = 0; i<cows.size(); i++) {
        if(cows[i] == '1' && (((cows[i-1] && cows[i-1] == '0') || i == 0) && ((cows[i+1] && cows[i+1] == '0') || i == cows.size()-1))) {
            has_isolation = true;
            break;
        }
    }
    if(has_isolation == true) {
        looping = false;
    }
    while(looping == true) {
        bool changed = false;
        for(int i = 0; i<cows.size(); i++) {
            if(temp[i] == '1' && ((temp[i-1] && temp[i-1] == '1') || (temp[i+1] && temp[i+1] == '1'))) {
                temp[i] = '0';
                changed = true;
            }
        }
        if(changed == false) {
            looping = false;
        }
    }
    // std::cout << temp << std::endl;
    // output number of 1s in temp string
    int ones = 0;
    for(int i = 0; i<temp.size(); i++) {
        if(temp[i] == '1') {
            ones++;
        }
    }
    cout << ones;
    return 0;
}