/*
Given two strings ransomNote and magazine, return true if 
ransomNote can be constructed by using the letters from 
magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/

#include <string>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alfa[26] = {};

        for(char letter : magazine){
            alfa[letter-'a'] += 1;
        }

        for(char letter : ransomNote){
            alfa[letter-'a'] -= 1;
        }

        for(int i = 0; i < 26; i++){
            if(alfa[i] < 0){
                return false;
            }
        }
        return true;
    }
};