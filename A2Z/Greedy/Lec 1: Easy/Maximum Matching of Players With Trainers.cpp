question link:
https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0, j = 0, cnt = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while(i<players.size() and j<trainers.size()){
            if(players[i] <= trainers[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
