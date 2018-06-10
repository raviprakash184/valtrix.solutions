#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main() {
vector<string>v;
vector<string>v_x;
vector<string>v_y;
string flag="hii";
int flag1;
 ifstream x;
 x.open("a.txt");
 string str;
 if (x.is_open())
{
	while (!x.eof())
	{
	 str="";
	 flag1=1;
	 getline(x,str);
	 if(str=="label_x:" || str=="label_y:")
	 {
	 flag=str;
	 flag1=!flag1;
	 }
	 if(flag1 && flag=="hii")
	 v.push_back(str);
	 if(flag=="label_x:" && flag1 && (str[0]!='B'))
	 v_x.push_back(str);
	 if(flag=="label_y:" && flag1 && (str[0]!='B'))
	 v_y.push_back(str);
	else if(str[0]=='B')
	v.push_back(str);
	
	
    //cout<<output<<"\n";
}
}
x.close();
map<string,int>mp;
ifstream xx;
xx.open("x2.txt");
 string output;
 if (xx.is_open()) {
 while (!xx.eof()) {


    	string ss="";
	int ss1=0;
	getline(xx,output);
	int i=0;
	while(i<output.size())
	{	if(i<2)
		ss+=output[i];
		else
		ss1=ss1*10+(output[i]-'0');
		i++;
		
	}
    	mp[ss]=ss1;


 }
}
xx.close();
/*map<string,int>::iterator it=mp.begin();
while(it!=mp.end())
{
	cout<<it->first<<"-->"<<it->second<<"\n";
	it++;
}*/
map<string,int>::iterator it1,it2,it3;
for(int i=0;i<v.size();i++)
{
	int j=0;
	string s1="";
	while(j<v[i].length())
	{
		if(v[i][j]!=' ')
		s1+=v[i][j];
		j++;
	}
	string x=v[i].substr(j-1,8);
	cout<<endl<<"#"<<s1; 
	vector<string>s;
/*	char *token = strtok(x, ",");
    while (token != NULL)
    {
        s.push_back(token);
        token = strtok(NULL, ",");
    }
*/
istringstream z(x);
string part;
while(getline(z,part,','))
{
	s.push_back(part);
} 

//char *pch = strtok (x,',');
//s.push_back(pch);
/*
while (pch != NULL)
{
   pch = strtok (NULL, ",");
   s.push_back(pch);
}
*/
	if(s1=="ADD")
	mp[s[0]]=(mp[s[1]])+(mp[s[2]]);
	if(s1=="MUL")
        mp[s[0]]=(mp[s[1]])*(mp[s[2]]);

}
map<string,int>::iterator it=mp.begin();
while(it!=mp.end())
{
        cout<<it->first<<"-->"<<it->second<<"\n";
        it++;
}

return 0;
}
