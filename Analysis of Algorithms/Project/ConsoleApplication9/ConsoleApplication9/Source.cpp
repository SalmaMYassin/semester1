#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include<sstream>
#include<algorithm>
#include <stdio.h>     
#include <stdlib.h>   
#include <ctype.h>

//#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	bool flag = false, flag2 = false;
	int n = 0;
	int i = 0, j = s.size()-1;
	for (n = 0; n < s.size() / 2; n++, i++, j--){
	/*	cout << s[i] << "  " << s[j] <<"  "<<n<< endl;*/
		if (s[i] == s[j])
			continue;
		else{
			if (!flag)
				flag = true;
			else{
				cout << "NO";
				flag2 = true;
				break;
			}
		}
	}
		
	if (!flag2)
		cout << "YES";


}


