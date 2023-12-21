#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    long long N, M;
    vector<long long> cows = {};
    vector<tuple<long long,long long>> canes = {};

    cin >> N >> M;
    for(long long i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        cows.push_back(temp);
    }

    for(long long i = 0; i < M; i++) {
        long long temp;
        cin >> temp;
        // push tuple (temp, temp)
        canes.push_back(make_tuple(temp, temp));
    }

    for(long long i = 0; i < M; i++) {
        tuple<long long,long long> cane = canes[i];
        for(long long j = 0; j < N; j++) {
            long long cow = cows[j];
            // std::cout << "vals" << std::endl;
            // std::cout << cow << " " << get<0>(cane) << " " << get<1>(cane) << std::endl;
            if((cow >= (get<1>(cane) - get<0>(cane))) && (cow <= get<1>(cane))) {
                // cow is tall enough to eat the cane
                long long bottom_cane = get<1>(cane) - get<0>(cane);
                long long amount_left = get<1>(cane) - cow;
                long long amount_eaten = get<0>(cane) - amount_left;

                cow += amount_eaten;
                cane = make_tuple(amount_left, get<1>(cane));
            }else if(cow > get<1>(cane)) {
                // cow is tall enough to eat all that is left of the cane
                long long amount_eaten = get<0>(cane);
                cow += amount_eaten;
                cane = make_tuple(0, get<1>(cane));
            }



            canes[i] = cane;
            cows[j] = cow;
        }
    }

    // log out values in cows vector
    for(long i = 0; i < N; i++) {
        cout << cows[i] << endl;
    }
    return 0;
}