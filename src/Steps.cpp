/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->11B2
	->211
	->22
	So total number of ways is 4

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

int factorial(int n);
int get_steps(int s)
{
	if (s == NULL){
		return 0;
	}
	static int methods = 1, curr_no_2 = 0, curr_no_1 = s, curr_positions = s, total_no_2 = 0;
	if (s % 2 == 0){
		total_no_2 = s / 2;
	}
	else{
		total_no_2 = (s - 1) / 2;
	}
	if (curr_no_2 < total_no_2){
		curr_no_1 -= 2;
		curr_no_2 += 1;
		curr_positions -= 1;
		methods += (factorial(curr_positions)) / (factorial(curr_no_1)*factorial(curr_no_2));
		get_steps(s);
	}
	else{
		return methods;
	}
}

int factorial(int n){
	int fact = 1;
	for (; n>0; n--){
		fact = fact*n;
	}
	return fact;
	
	/*if ((n == 0) || (n == 1)){
		return 1;
	}
	else{
		return n*factorial(n - 1);
	}*/
}

