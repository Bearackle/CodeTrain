class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,bool> is_vowels={{'u',true},{'e',true},{'o',true},{'a',true},{'i',true}};
        int cur_vowels = 0;
        for(int i = 0; i< k; i++){
            if(is_vowels[s[i]]){
                cur_vowels++;
            }
        }
        int max = cur_vowels;
        int length = s.length();
        int i =1, j = k;
        while(j < length){
            if(is_vowels[s[i-1]]){
                cur_vowels--;
            }
            if(is_vowels[s[j]])
                cur_vowels++;
            if(cur_vowels >= max){
                max = cur_vowels;
            }
            i++;
            j++;
        }
        return max;
    }
};