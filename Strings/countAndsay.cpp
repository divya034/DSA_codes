string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        if(n == 2){
            return "11";
        }
        string s = "11";
        for(int i = 3; i<=n; ++i ){
           int count = 1;
           s = s + 'a';
           string temp = "";
           for(int j = 1; j<s.length(); ++j){
                    if(s[j] == s[j - 1]){
                        count++;
                    }
                    else{
                        temp = temp + to_string(count);
                        //cout<<temp<<endl;
                        count = 1;
                        temp = temp + s[j-1];
                    }
            }
             s = temp;
        }

        return s;
    }
