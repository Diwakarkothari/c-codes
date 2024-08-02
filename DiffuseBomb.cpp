#include <bits/stdc++.h>
using namespace std;

vector<int> diffusetheBomb(vector<int>& code, int k) {
    vector<int> temp;
    if (k == 0) {
        for (int i = 0; i < code.size(); i++) {
            code[i] = 0;
        }
    } else if (k > 0) {
        for (int i = 0; i < code.size(); i++) {
            int count = 0;
            int sum = 0;
            int j = i + 1;
            while (count < k) {
                if (j <= code.size() - 1) {
                    sum = sum + code[j];
                    j++;
                    count++;
                } else {
                    sum = sum + code[j % code.size()];
                    j++;
                    count++;
                }
            }
            temp.push_back(sum);
        }

        code.clear();
        for (int i = 0; i < temp.size(); i++) {
            code.push_back(temp[i]);
        }
    } else {
        for (int i = 0; i < code.size(); i++) {
            int count = 0;
            int sum = 0;
            int j = i - 1;
            while (count < abs(k)) {
                if (j < 0) {
                    int index = code.size() + (j);
                    sum = sum + code[index];
                    j--;
                    count++;
                } else {
                    sum = sum + code[j];
                    j--;
                    count++;
                }
            }
            temp.push_back(sum);
        }

        code.clear();
        for (int i = 0; i < temp.size(); i++) {
            code.push_back(temp[i]);
        }
    }

    return code;
}

int main() {
    vector<int> code;

    int n, k;
    int x;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x;
        code.push_back(x);
    }

    vector<int> ans = diffusetheBomb(code, k);
    
    for(int i=0; i<ans.size(); i++){
    	cout<<ans[i]<<" ";
	}

    return 0;
}