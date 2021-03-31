#include<iostream>
using namespace std;
int main(){
    int t,x,y,i;
    cin>>t;
    for(i=1;i<=t;i++){
        string s;
        cin>>x>>y>>s;
        int n=s.size();
            string st="";
            for(int i=0;i<n;i++)
                if(s[i]=='C'||s[i]=='J')
                 st.push_back(s[i]);
            if(st.size()<=1)
             cout<<"Case #"<<i<<": "<<0<<endl;
            else{
                int sum=0;
                for(int i=0;i<st.size();i++){
                    if(st[i]=='C'&&st[i+1]=='J')
                     sum+=x;
                    else if(st[i]=='J'&&st[i+1]=='C')
                     sum+=y;
                }
                cout<<"Case #"<<i<<": "<<sum<<endl;
            } 
    }
    return 0;
}
