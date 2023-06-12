class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>s;
        vector<string>mo = {".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};
        vector<char>al = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        unordered_map<char,string>mp;
        for (int i = 0; i < 26; i++){
            mp.insert({al[i], mo[i]});
        }
        for (int i = 0; i < words.size();i++){
            string str = "";
            for (int j = 0; j < words[i].size(); j++){
                str += (mp.find(words[i][j])->second);
            }
            s.insert(str);
        }
        return s.size();
    }
};