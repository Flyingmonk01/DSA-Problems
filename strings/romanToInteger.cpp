// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000



string intToRoman(int num) {
        string romanSymbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        for(int i = 0; i < 13; i++){
            while(num >= number[i]){
                ans.append(romanSymbol[i]);
                num = num-number[i];
            }
        }
        return ans;
    }