Julia and Samantha are playing with strings. Julia has a string S, and Samantha has a string T which is a subsequence of string S. They are trying to find out what words are missing in T.
Help Julia and Samantha to solve the problem. List all the missing words in T, such that inserting them at the appropriate positions in T, in the same order, results in the string S.
Constraints
1 <= |T| <= |S| <= 106, where |X| denotes the length of string X.
The length of each word will be less than 15.
 
Function Parameter
You are given a function missingWords that takes the strings S and T as its arguments.
 
Function Return Value
Return an array of the missing words.
 
Sample Input
I am using hackerrank to improve programming
am hackerrank to improve
Sample Output
I
using
programming
Explanation
Missing words are:
1. I  
2. using  
3. programming  


#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> missing(string s, string t){
    vector<string> sv, tv, res;
    stringstream sss(s), tss(t);
    string each;
    while(getline(sss, each, ' ')) sv.push_back(each);
    while(getline(tss, each, ' ')) tv.push_back(each);
    int i = 0;
    for(int i = 0; i<sv.size(); i++){
        if(sv[i]!=tv[i-res.size()]) res.push_back(sv[i]);
    }
    return res;
}

int main()
{
    string s= "World World World", t="World";
    vector<string> res;
    res = missing(s, t);
    for(string s: res){
        cout<<s<<endl;
    }

    return 0;
}
