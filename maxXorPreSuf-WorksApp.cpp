#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+10;
int cnr[N];
struct Node{
	ll val;
	Node* child[2];
};
Node* newNode(int n){
	Node* node=new Node;
	node->val=n;
	node->child[0]=node->child[1]=NULL;
	return node;
}
class Trie{
	public:
		Trie(int i):n(i){
			root=newNode(0);
			xr=0;
			for(int i=0;i<n;i++) xr^=cnr[i];
			insert(0);
			insert(xr);
		};
		ll solve();
	private:
		int n;
		const static int maxBit=45;
		Node* root;
		ll xr;
		void insert(ll);
		ll query(ll);
		
};
ll Trie::solve(){
	ll res=xr;
	for(int i=0;i<n;i++){
		xr^=cnr[i];
		insert(xr);
		res=max(res,query(xr));
	}
	return res;
}
ll Trie::query(ll ith){
	Node* tmp=root;
	int itr;
	for(int i=maxBit;i--;){
		itr=(ith&(1<<i))?1:0;
		if(tmp->child[1-itr]) tmp->child[1-itr];
		else if(tmp->child[itr]) tmp->child[itr];
	}
	return tmp->val^ith;
}
void Trie::insert(ll xorTill){
	int itr;
	Node* tmp=root;
	for(int i=maxBit;i--;){
		itr=(xorTill&(1<<i))?1:0;
		if(tmp->child[itr]==NULL){
			tmp->child[itr]=newNode(itr);
			tmp=tmp->child[itr];
		}
		else tmp=tmp->child[itr];
	}
	tmp->val=xorTill;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&cnr[i]);
	Trie trie(n);
	cout<<trie.solve();
}
