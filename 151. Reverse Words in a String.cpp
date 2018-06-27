        }
    }
    
public:
    void reverseWords(string &s) {
        int i = 0, j = 0;
        int k = 0;
        int len = s.size();
        int count = 0;
        
        while(true){
            while(i<len && s[i]==' ') i++;
            if(i==len) break;
            if(count) s[j++]=' ';
            k = j;
            while(i<len && s[i]!=' '){
                s[j] = s[i];
                j++;
                i++;
            }
            reverse(s, k, j-1);
            count++;
        }
        
        s.resize(j);
        reverse(s, 0, j-1);
    }
};
