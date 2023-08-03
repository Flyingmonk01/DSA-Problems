// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);


string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        int i = 0;
        int row = 0;
        vector<string> store(numRows);
        bool dir = 1;
        while(true){
            if(dir){
                while(row < numRows && i < n){
                    store[row++].push_back(s[i++]);
                }
                row = numRows-2;
            }
            else{
                while(row >= 0 && i < n){
                    store[row--].push_back(s[i++]);
                }
                row = 1;
            }
            if(i >= n) break;
            dir = !dir;
        }
        string output = "";
        for(auto x : store){
            output += x;
        }
        return output;
    }