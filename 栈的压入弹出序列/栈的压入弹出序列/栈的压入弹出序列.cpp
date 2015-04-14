// 栈的压入弹出序列.cpp : 定义控制台应用程序的入口点。
//
//题目:输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否
//为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、5是某栈的压栈序列
//序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但4、3、5、1、2就不可能是该压栈序列的
//弹出序列
#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
	if (pPush == NULL || pPop == NULL || nLength <= 0)return false;
	stack<int> push;
	int popIndex = 0;
	int pushIndex = 0;
	for (pushIndex = 0; pushIndex < nLength; pushIndex++)
	{
		int key = pPush[pushIndex];
		push.push(key);
		while (!push.empty()&&push.top() == pPop[popIndex])
		{
			push.pop();
			popIndex++;
		}
	}
	return push.size() == 0;
}

// ====================测试代码====================
void Test(char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (IsPopOrder(pPush, pPop, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	Test("Test1", push, pop, nLength, true);
}

void Test2()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	Test("Test2", push, pop, nLength, true);
}

void Test3()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	Test("Test3", push, pop, nLength, false);
}

void Test4()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };

	Test("Test5", push, pop, nLength, false);
}

void Test6()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };

	Test("Test6", push, pop, nLength, true);
}

void Test7()
{
	Test("Test7", NULL, NULL, 0, false);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	cin.get();
	return 0;
}
