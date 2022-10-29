#include <iostream>
using namespace std;
#define N 100
int x[N];
int n;
int f;
int f_min;
int Cm; // do dai chang nho nhat ko tinh cac phan tu tren duowng cheo
bool mark[N];
int c[N][N];
void input(){
	cin >>n;
	Cm=1e9;
	for(int i=1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>c[i][j];
			if(Cm>c[i][j] && c[i][j]!=0) Cm = c[i][j];
		}
	}
}
bool check(int v,int k){
	return mark[v]==false;
}
void solution(){
	//compare the current solution x[1]-x[2]....x[n]....[x1]
	if(f+c[x[n]][x[1]] < f_min){
		f_min = f+c[x[n]][x[1]];
		
	}
	
}

void Try(int k){
	for(int v=1;v<=n;v++){
		if(check(v,k)){
			x[k]=v;
			mark[v]=true;
			f = f + c[x[k-1]][x[k]];
			if(k==n) solution();
			else {
				if(f+Cm*(n-k+1)<=f_min){
					Try(k+1);
				}		
			};
			mark[v]=false;
			f = f - c[x[k-1]][x[k]];
		}
	}
}
int main() {
	
  input();
  f=0;
  f_min = 9999;
  
  Try(1);
  cout <<f_min;
  return 0;
}