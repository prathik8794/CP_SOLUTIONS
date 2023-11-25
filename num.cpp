#include<bits/stdc++.h>
using namespace std;
//include all num-theory functions required...
//O(sqrt(n))
#define bahut_tez  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool isPrime(int n){
	if(n==1)return false;

	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}

	return true;
}

//Sieve of Erathosthenes
//O(nlog(log(n))) sieve
int is_prime[10000001];
vector<int>primes;
void sieve(){
	int maxN = (5000001);
	is_prime[0]=1,is_prime[1]=1;
	for(int i=2;i*i<=maxN;i++){
		if(is_prime[i]==0){
			for(int j=i*i;j<=maxN;j+=i){
				is_prime[j]=1;
			}
		}
	}
}
// prime_factorization
void prime_factorization(int n){
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			int cnt = 0;
			while(n%i==0){
				n/=i,cnt++;
			}
			cout<<i<<"^"<<cnt<<endl;
		}
	}
	if(n>1)cout<<n<<"^"<<"1"<<endl;
}

//binary exponentiation
long long binpow(long long a,long long n){
	long long res = 1;
	while(n>0){
		if(n&1)res*=a;
		a*=a;
		n>>=1;
	}
	return res;
}

void prime_factorization_sieve(){
	int maxN = 10000001;
	for(int i=1;i<maxN;i++)is_prime[i]=i;
	for(int i=2;i<maxN;i+=2)is_prime[i]=2;
	for(int i=3;(long long)i*i<maxN;i++){
		if(is_prime[i]==i){
			for(int j=(long long)i*i;j<maxN;j+=i){
				if(is_prime[j]==j){
					is_prime[j]=i;
				}
			}
		}
	}
}
void factor(int n){
	printf("1 x ");
	while(n!=1){
		if(n/is_prime[n]!=1){
		printf("%d x ",is_prime[n]);
		}else{
		printf("%d\n",is_prime[n]);
		}
	n=n/is_prime[n];
	}
}

void phiInit(){
    int maxN = 1000000;
    for(int i=1;i<=maxN;i++){
        phi[i] = i;
    }
    for(int i=2;i<=maxN;i++){
        if(phi[i]==i){
            for(int j=i;j<=maxN;j+=i){
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
} //nlog(log(n))

int main(){
	bahut_tez;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("Error.txt","w",stderr);
    // #endif
	int n;
	prime_factorization_sieve();
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			printf("1\n");
		}
		else factor(n);
	}
	return 0;
}