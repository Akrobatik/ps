// Title : 1, 2, 3, 많다!
// Link  : https://www.acmicpc.net/problem/34998 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>
int main(){
    auto F=[&](char c){if(c=='!')return 10;
                       return c-'0';
                       };
    int t;
    std::cin>>t;
    while(t--){
        int n;char c;
        std::cin>>n>>c;
        int x=F(c);
        for(int i=0;i<n;i++){
            std::cin>>c>>c;
            x+=F(c);
            }
        std::cout<<(char)(x>9?'!':x+'0')<<'\n';
        }}
        