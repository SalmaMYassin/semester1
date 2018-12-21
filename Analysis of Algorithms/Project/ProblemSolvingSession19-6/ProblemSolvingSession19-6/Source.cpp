#include <iostream>
#include <string>
#include<set>
#include <algorithm>
#include <sstream>
using namespace std;


int main(){

	string num1Str, num2Str, resultStr;
	cin >> num1Str >> num2Str;

	stringstream read;
	int num1=0, num2=0, result=0;

	read << num1Str;
	read >> num1;
	cout << num1;
	read << num2Str;
	read >> num2;

	result = num1 + num2;
	read << result;
	read >> resultStr;

	for (int i = 0; i < resultStr.size(); i++){
		if (resultStr[i] == '0')
			resultStr.erase(i);
	}

	for (int i = 0; i < num1Str.size(); i++){
		if (num1Str[i] == '0')
			num1Str.erase(i);
	}

	for (int i = 0; i < num2Str.size(); i++){
		if (num2Str[i] == '0')
			num2Str.erase(i);
	}

	read << num1Str;
	read >> num1;

	read << num2Str;
	read >> num2; 
	
	result = num1 + num2;
	string finalR;

	read << result;
	read >> finalR;

	if (finalR == resultStr)
		cout << "YES";
	else
		cout << "NO";


	
}