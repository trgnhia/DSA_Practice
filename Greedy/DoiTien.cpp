#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long long n;
	cin>>n;
	int size = 10;
	int c = 0;
	
	if( (n / 1000) > 0 ){
		c += (n/1000);
		n %= 1000;
	}
	if( (n / 500) > 0 ){
		c += (n/500);
		n %= 500;
	}
	if( (n / 200) > 0 ){
		c += (n/200);
		n %= 200;
	}
	if( (n / 100) > 0 ){
		c += (n/100);
		n %= 100;
	}
	if( (n / 50) > 0 ){
		c += (n/50);
		n %= 50;
	}
	if( (n / 20) > 0 ){
		c += (n/20);
		n %= 20;
	}
	if( (n / 10) > 0 ){
		c += (n/10);
		n %= 10;
	}
	if( (n / 5) > 0 ){
		c += (n/5);
		n %= 5;
	}
	if( (n / 2) > 0 ){
		c += (n/2);
		n %= 2;
	}
	if(n == 1){
		c ++;
	}	
		
	cout<<c;
    return 0;
}
