class Solution {
public:
    int isPrefixOfWord(string str, string searchWord) {
        string Word;
        stringstream s(str); 
        int count = 0; 
        
        while (s >> Word) { 
            count++;
            // Check if the current word starts with the searchWord
            if (Word.substr(0, searchWord.length()) == searchWord) {
                return count;
            }
        }
        
        return -1; 
    }
};
