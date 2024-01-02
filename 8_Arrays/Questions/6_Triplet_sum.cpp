#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028?leftPanelTabValue=PROBLEM

vector<int> findTriplets(vector<int> arr, int n, int K) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for (int l = j + 1; l < arr.size(); l++) {
                if (arr[i] + arr[j] + arr[l] == K) {
                    // Return only the first triplet found (at index 0)
                    return {arr[i], arr[j], arr[l]};
                }
            }
        }
    }

    // If no triplet is found, return an empty vector
    return {};
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 2, 3};
    int n = arr.size();
    int K = 6;

    vector<int> result = findTriplets(arr, n, K);

    // Output the result
    if (!result.empty()) {
        cout << "(" << result[0] << ", " << result[1] << ", " << result[2] << ") ";
    } else {
        cout << "No triplet found.";
    }

    return 0;
}


