/*
* GCD problem
* codingninjas.com
*/
int gcd(int a,int b)
{
	int gcd = 1;
	for(int i = min(a,b) ; i >= 1 ; i--){
		if(a % i == 0 && b % i == 0){
			gcd = i ;
			break;
		}
	}
	return gcd;
}

