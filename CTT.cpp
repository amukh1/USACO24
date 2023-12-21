#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int factorial(int n) {
    if(n == 0) {
        return 1;
    }else {
        return n * factorial(n - 1);
    }
}

// permutations S_n generator with a little tweak
vector<vector<int>> permutations(int n, int c) {
    // S_n for n :sob:
    if(n == 1) {
        vector<int> perm;
        if(n > c)
        perm.push_back(1);
        else
        perm.push_back(0);
        vector<vector<int>> perms;
        perms.push_back(perm);
        return perms;
    }

    vector<vector<int>> perms;
    for(int i = 0; i<n; i++) {
        int nm1f = factorial(n-1);
        for(int j = 0; j<nm1f; j++) {
            int perm[n];
            if(n > c)
            perm[i] = 1;
            else
            perm[i] = 0;
            vector<int> permsb = permutations(n-1,c)[j];
            int k = 0;
            int k0 = 0;
            while(k < nm1f*n) {
                if(k0 == i) {
                    k0++;
                }else {
                    perm[k0] = permsb[k];
                    k0++;
                    k++;
                }
            }
            vector<int> permv;
            for(int l = 0; l<n; l++) {
                permv.push_back(perm[l]);
            }
            perms.push_back(permv);
        }
    }
    return perms;
}

bool pstringEventuallyMatches(vector<int> pstring, string cows) {
    bool match = true;
    for(int j = 0; j<pstring.size(); j++) {
        if(to_string(pstring[j])[0] != cows[j]) {
            match = false;
            break;
        }
    }
    if(match == true) {
        return true;
    }
    for(int i = 0; i<pstring.size(); i++) {
        for(int k = 0; k<pstring.size(); k++) {
            if((pstring[k-1] && pstring[k-1] == 1) || (pstring[k+1] && pstring[k+1] == 1)) {
                pstring[k] = 1;
            }
        }

        // check if pstring == cows
        match = true;
        for(int j = 0; j<pstring.size(); j++) {
            if(to_string(pstring[j])[0] != cows[j]) {
                match = false;
                break;
            }
        }
        if(match) {
            return true;
        }else
        continue;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    string cows = "";
    cin >> cows;

    // brute force solution
    for(int i = 1; i<=N; i++) {
        // generate all strings of 0s and 1s where there are i 1s and N-i 0s
        vector<vector<int>> psuedostrings = permutations(N,N-i);
        // check each psuedostring
        for(int j = 0; j<psuedostrings.size(); j++) {
            if(pstringEventuallyMatches(psuedostrings[j], cows)) {
                cout << i << endl;
                return 0;
            }
        }
    }

    // generate all permutations of 1..N
    // vector<vector<int>> perms = permutations(N,1);
    // // log for testing
    // for(int i = 0; i<perms.size(); i++) {
    //     for(int j = 0; j<perms[i].size(); j++) {
    //         cout << perms[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // mor tests
    // cout << pstringEventuallyMatches({1,0,1}, "110");
    return 0;
}
