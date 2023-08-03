// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.



class Node{
    public:
        char data;
        int count;

        Node(char d, int c){
            data = d;
            count = c;
        }
};

class compare{
    public:
        bool operator()(Node a, Node b){
            return a.count < b.count;
        }
};


class Solution {
public:
    string reorganizeString(string s) {
        // create mapping
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++){
            // char ch = s[i];
            freq[s[i] -'a']++;
        }      

        // priority_queue<Node, vector<Node>, compare> maxHeap;
        // for(int i = 0; i < 26; i++){
        //     if(freq[i] != 0){
        //         Node temp(i+'a', freq[i]);
        //         maxHeap.push(temp);
        //     }
        // }

        // string ans = "";
        // while(maxHeap.size() > 1){
        //     Node first = maxHeap.top();
        //     maxHeap.pop();
        //     Node second = maxHeap.top();
        //     maxHeap.pop();
        //     ans += first.data;
        //     ans += second.data;
        //     first.count--;
        //     second.count--;

        //     if(first.count != 0) maxHeap.push(first);
        //     if(second.count != 0) maxHeap.push(second);

        // }

        // if(maxHeap.size() == 1){
        //     Node temp = maxHeap.top();
        //     maxHeap.pop();
        //     if(temp.count == 1){
        //         ans += temp.data;
        //     }
        //     else{
        //         return "";
        //     }
        // }
        // return ans;

        char max_frq_ch;
        int max_frq = INT_MIN;
        for(int i = 0; i < 26; i++){
            if(freq[i] > max_frq){
                max_frq = freq[i];
                max_frq_ch = i + 'a';
            }
        }

        int index = 0;
        while( max_frq > 0 && index < s.size()){
            s[index] = max_frq_ch;
            index += 2;
            max_frq--;
        }
        if(max_frq != 0){
            return "";
        }
        freq[max_frq_ch - 'a'] = 0;
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                freq[i]--;
                index += 2;
            }
        }
        return s;
    }
};
