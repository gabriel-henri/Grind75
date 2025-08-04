/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itse
*/

#include <string>

class Solution {
public:
    string addBinary(string a, string b) {
        int posa = a.length()-1;
        int posb = b.length()-1;
        std::string result;
        int resto = 0;
        while(posa >= 0 && posb >= 0){
            if(a[posa] == '0' && b[posb] == '0'){
                if(resto == 0){
                    result.insert(0, "0");
                }
                else{
                    result.insert(0, "1");
                    resto = 0;
                }
            }else if(a[posa] == '0' && b[posb] == '1'){
                if(resto == 0){
                    result.insert(0, "1");
                }else{
                    result.insert(0, "0");
                    resto = 1;
                }
            }else if(a[posa] == '1' && b[posb] == '0'){
                if(resto == 0){
                    result.insert(0, "1");
                }else{
                    result.insert(0, "0");
                    resto = 1;
                }
            }else{
                if(resto == 0){
                    result.insert(0, "0");
                    resto = 1;
                }else{
                    result.insert(0, "1");
                    resto = 1;
                }
            }
            posa--;
            posb--;
        }

        while(posa >= 0){
            if(a[posa] == '0'){
                if(resto == 0){
                    result.insert(0, "0");
                }else{
                    result.insert(0, "1");
                    resto = 0;
                }
            }else{
                if(resto == 0){
                    result.insert(0, "1");
                }else{
                    result.insert(0, "0");
                }
            }
            posa--;
        }


        while(posb >= 0){
            if(b[posb] == '0'){
                if(resto == 0){
                    result.insert(0, "0");
                }else{
                    result.insert(0, "1");
                    resto = 0;
                }
            }else{
                if(resto == 0){
                    result.insert(0, "1");
                }else{
                    result.insert(0, "0");
                }
            }
            posb--;
        }

        if(resto == 1){
            result.insert(0, "1");
        }
        return result;
    }
};