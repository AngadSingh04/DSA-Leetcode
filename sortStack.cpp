#include <bits/stdc++.h> 

void sortedS(stack<int>& s, int num){
	if(s.empty() || s.top() <= num){
		s.push(num);
		return;
	}
	int n = s.top();
	s.pop();
	sortedS(s,num);
	s.push(n);
}

stack<int> sortStack(stack<int> &s)
{
	// Write code here.
	if(s.empty()){
		return s;
	}
	int num = s.top();
	s.pop();
	sortStack(s);
	sortedS(s,num);

	return s;

	
}