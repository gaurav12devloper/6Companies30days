/*
273. Integer to English Words
https://leetcode.com/problems/integer-to-english-words/description/
*/
class Solution {
public:
    unordered_map<int,string>belowTen={{0,""}, {1,"One"}, {2,"Two"}, {3, "Three"}, {4, "Four"}, {5,"Five"},
                                                {6,"Six"}, {7, "Seven"}, {8,"Eight"}, {9,"Nine"}};
    
    unordered_map<int,string>belowTwenty={{10,"Ten"}, {11,"Eleven"}, {12,"Twelve"}, {13, "Thirteen"},
                                                {14, "Fourteen"}, {15,"Fifteen"},{16,"Sixteen"}, 
                                                {17, "Seventeen"}, {18,"Eighteen"}, {19,"Nineteen"}};
    
    unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"},
                             {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };

    string solve(int num){
        if(num==0) return ""; 
        if(num<10) return belowTen[num]+ " ";

        if(num<20) { // 19
            return belowTwenty[num] + " ";
        }
        if(num<100){ // 89
            return belowHundred[num/10]+" "+solve(num%10);
        }

        if(num<1000){  // 456=> 4 Hundred Fifty Six
            return solve(num/100)+ "Hundred "+ solve(num%100);
        }
        if(num<1000000){ //12345
            return solve(num/1000) + "Thousand " + solve(num%1000);
        }
        if(num<1000000000){
            return solve(num/1000000) + "Million " + solve(num%1000000);
        }
        return solve(num/1000000000)+ "Billion " + solve(num%1000000000);

    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string ans=solve(num);
        if(ans.back()==' ') return ans.substr(0,ans.size()-1); // remove space from end , needed because "Twenty "
        return solve(num);
    }
};