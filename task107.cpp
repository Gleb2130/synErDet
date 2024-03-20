#include <iostream>
#pragma warning (disable:4996)
#include<initializer_list>
#include<cassert>
#include<windows.h>
using namespace std;



#include"Node.h"
#include"Stack.h"
#include"Calc.h"


int main()
{

	char ex1[] = "({x-y-z} * [x + 2y) - {z + 4x)]";
	char ex2[] = "({x-y-z} * [x + 2y] - (z + 4x))";

	Calc c1(ex1);
	Calc c2(ex2);

	c1.checkBrackets();
	c2.checkBrackets();
}
