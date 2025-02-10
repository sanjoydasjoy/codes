question link:
https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings


// O(n^2) solution

class Solution {
  public:
    int countSubstr(string& s, int k) {
    int res = 0; 
    int n = s.length();
    int cnt[26]; 

    for (int i = 0; i < n; i++) {
        int dist_count = 0; 
        memset(cnt, 0, sizeof(cnt)); 

        for (int j = i; j < n; j++) {
            if (cnt[s[j] - 'a'] == 0) {
                dist_count++; 
            }
            cnt[s[j] - 'a']++; 

            if (dist_count == k) {
                res++;
            }
            else if (dist_count > k) {
                break;
            }
        }
    }

    return res;
    }
};


