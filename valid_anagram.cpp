/*
Given two strings s and t, return true if t is an anagram of 
s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

#include <cctype>
#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        int alfa[26] = {};

        for(char let: s){
            if(std::isalpha(let)){
                int pos = let - 'a';
                alfa[pos]++;
            }
        }

        for(char let: t){
            if(std::isalpha(let)){
                int pos = let - 'a';
                alfa[pos]--;
            }
        }

        for(int i = 0; i < 26; i++){
            if(alfa[i] != 0){
                return false;
            }
        }
        return true;
    }
};