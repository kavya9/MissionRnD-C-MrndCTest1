/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int *gm1(int *arr, int len, int *res)
{
	int flag = 0;
	for (int i = 1; i < len; i++)
	{
		float num1 = arr[i]*1.0 / arr[i - 1];
		float num2 = arr[i + 1]*1.0 / arr[i];
		if (num1==num2)
		{
			flag++;
			if (res[4] == -100) res[4] = i - 1;
			res[5] = i + 1;
		}
		else if (flag != 0) break;
	}
	return res;
}
int * am1(int *arr, int len, int *res)
{
	int flag = 0;
	for (int i = 1; i < len; i++)
	{
		if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i]))
		{
			flag++;
			if (res[0] == -100) res[0] = i - 1;
			res[1] = i + 1;
		}
		else if (flag!=0) break;
	}
	return res;
}
int * am2(int *arr, int len, int *res)
{
	/*int i = res[1];
	if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i]))
	{
		for ( i = res[1]; i < len; i++)
		{
			if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i]))
			{
				if (res[2] == -100) res[2] = i - 1;
				res[3] = i + 1;
			}
			else break;
		}
	}
	else { res = gm1(arr, len, res); }
	i = res[5];
	if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i]))
	{
		for ( i = res[5]; i < len; i++)
		{
			if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i]))
			{
				if (res[2] == -100) res[2] = i - 1;
				res[3] = i + 1;
			}
			else break;
		}
	}
	return res;*/
	int flag = 0;
	for (int i = res[1]; i < len; i++)
	{
		if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i]))
		{
			flag++;
			if (res[2] == -100) res[2] = i - 1;
			res[3] = i + 1;
		}
		else if (flag != 0) break;
	}
	return res;
}

int validate(int *res)
{
	for (int i = 0; i < 6; i++)
	{
		if (res[i] == -100)return 0;
	}
	return 1;
}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if(arr==NULL || len<0) return NULL;
	int *res = (int *)malloc(6 * sizeof(int));
	int i;
	for (i = 0; i < 6; i++)
	{
		res[i] = -100;
	}
	res = am1(arr, len, res);
	res = am2(arr, len, res);
	res = gm1(arr, len, res);
	//res = gm1(arr, len, res);
	/*if(validate(res)) return res;
	res = am1(arr, len, res);
	res = gm1(arr, len, res);
	res = am2(arr, len, res);
	if (validate(res)) return res;
	res = gm1(arr, len, res);
	res = am1(arr, len, res);
	res = am2(arr, len, res);*/
	return res;
	//int i, j,am1=-100,am2,am3=-100,am4,gm1=-100,gm2;
	
	
}