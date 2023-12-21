#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

bool check(long long a_i[], long long t_i[], long long N) {
    for(long long i = 0; i<N; i++) {
        // check that there are t_i[i] many elements in a_i that are greater than a_i[i]
        long long count = 0;
        for(long long j = 0; j<N; j++) {
            if(a_i[j] > a_i[i]) {
                count++;
            }
        }
        if(count != t_i[i]) {
            // cout << count << ":(" << t_i[i] << endl;
            return false;
        }
    }
    return true;
}

int main() {
    long long T;
    cin >> T;
    long long count = 0;
    vector<long long> outs = {};
    for(long long i = 0; i<T; i++) {
        count = 0;
        long long N;
        cin >> N;
        long long h_i[N];
        long long a_i[N];
        long long t_i[N];

        for(long long j = 0; j<N; j++) {
            cin >> h_i[j];
        }
        for(long long j = 0; j<N; j++) {
            cin >> a_i[j];
        }
        for(long long j = 0; j<N; j++) {
            cin >> t_i[j];
        }

        while(check(h_i, t_i, N) == false) {
            if(count > 200000) {
                count = -1;
                break;
            }
            // increment all elements of h_i by a_i
            for(long long j = 0; j<N; j++) {
                h_i[j] += a_i[j];
            }
            count++;
        }
        // std::cout << count << std::endl;
        outs.push_back(count);
    }
    // long long a_i[] = {7, 6, 4};
    // long long t_i[] = {0, 1, 2};
    // cout << check(a_i, t_i, 3);
    for(long long i = 0; i<outs.size(); i++) {
        cout << outs[i] << endl;
    }
    return 0;
}