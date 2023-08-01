// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.


bool isVowel(char ch){
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
        }
        string modify (string s)
        {
            int st = 0;
            int e = s.length()-1;
            while(st < e){
                if(isVowel(s[st]) && isVowel(s[e])){
                    swap(s[st], s[e]);
                    st++; e--;
                }
                else if(!isVowel(s[st])){
                    st++;
                }
                else if(!isVowel(s[e])){
                    e--;
                }
    
            }
            return s;
        }