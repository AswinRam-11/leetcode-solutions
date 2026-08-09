class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set <char> jewel;
        for(int i=0; i<jewels.size(); i++){
            jewel.insert(jewels[i]);
        }
        int ans=0;
        for(int j=0; j<stones.size(); j++){
            if(jewel.count(stones[j])){
                ans++;
            }
        }
        return ans;
    }
};