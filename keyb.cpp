#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <cctype>

int main() {
    int t;
    std::cin >> t;
    std::string cases[t];

    for (int i = 0; i < t; i++) {
        std::cin >> cases[i];
    }
    
    for(int i = 0; i< t; i++) {
        std::vector<int> lastLowercases = {};
        std::vector<int> lastUppercases = {};
        std::string outp = "";

        for(int j = 0; j<cases[i].length(); j++) {
            if(cases[i][j] == 'b' && lastLowercases.size() > 0) {
                outp.erase(lastLowercases[lastLowercases.size()-1],1);
                lastLowercases.pop_back();
            }else if(cases[i][j] == 'B' && lastUppercases.size() > 0) {
                outp.erase(lastUppercases[lastUppercases.size()-1],1);
                lastUppercases.pop_back();
            }
            // now two more cases, else if cases[i][j] is lowercase
            else if(!isupper(cases[i][j]) && cases[i][j] != 'b') {
                outp += cases[i][j];
                lastLowercases.push_back(outp.length()-1);
            }else if(isupper(cases[i][j]) && cases[i][j] != 'B') {
                outp += cases[i][j];
                lastUppercases.push_back(outp.length()-1);
            }
        }
        std::cout << outp << std::endl;
    }
    return 0;
}