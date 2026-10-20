class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        sort(changed.begin(), changed.end());
        int n = changed.size();

        vector<int> ans;

        map<int, int> odd, even;
        for(int x : changed){

            if(x % 2 == 1){
                odd[x]++;
            }
        }

        for(int x : changed){

            if(x % 2 == 0){
                int q = x / 2;

                if(odd.count(q)){
                    ans.push_back(q);
                    odd[q]--;
                    if(odd[q] == 0)
                        odd.erase(q);
                }

                else{

                    if(even.count(q)){
                        ans.push_back(q);
                        even[q]--;
                        if(even[q] == 0){
                            even.erase(q);
                        }
                    }
                    else{
                        even[x]++;
                    }
                }
            }
        }

        if(ans.size() == n/2 && odd.empty() && even.empty()){
            return ans;
        }

        return vector<int>();
        
    }
};