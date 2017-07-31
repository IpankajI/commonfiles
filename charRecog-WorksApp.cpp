#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int n,m,k,mat[6][105],ans;
	scanf("%d %d %d",&n,&m,&k);
	ll tmp,mn=m*n;
	int cnt;
	for(int i=0;i<k;i++){
		cnt=0;
		for(int j=0;j<n;j++){
			scanf("%lld",&tmp);
			for(int in=m;in--;){
				mat[i][cnt++]=tmp/ll(pow(10,in));
				tmp%=ll(pow(10,in));
			}
		}
	}
	set<string> st[2];
	set<string>::iterator it;
	string str="";
	for(int i=mn;i--;) str=str+'0';
	for(int i=mn;i--;){
		str[i]='1';
		st[0].insert(str);
		str[i]='0';
	}
	vector<int> vc[100];
	bool f;
	for(ans=1;ans<105;ans++){
		for(it=st[(ans+1)%2].begin();it!=st[(ans+1)%2].end();++it){
			str=(*it);
			for(int i=str.length();i--;){
				if(str[i]=='1'){
					for(int in=0;in<k;in++){
						vc[in].push_back(mat[in][i]);
					}
				}
				else{
					str[i]='1';
					st[ans%2].insert(str);
				}
			}
			f=true;
			for(int i=0;i<k-1;i++){
				for(int j=i+1;j<k;j++){
					if(vc[i]==vc[j]) f=false;
				}
			}
			if(f) break;
		}
		if(f) break;
		st[(ans+1)%2].clear();
	}
	printf("%d",ans);
}

//sssssssssssss