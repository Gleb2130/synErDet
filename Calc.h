#pragma once

class Calc
{
	char* expression;

	bool isOperation(char op)
	{
		switch (op)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return true;
		default:
			return false;
		}
	}

	int getPriority(char op)
	{
		switch (op)
		{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		case '^':           return 3;
		}
	}

	int calc(int a, int b, char op)
	{
		switch (op)
		{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		case '^': return pow(b, a);
		}
	}

	bool isBracket(char sy) {
		switch (sy) {
		case '(':
		case '{':
		case '[':
		case ')':
		case '}':
		case ']':
			return true;
		default:
			return false;
		}
	}

	int isOpenBracket(char sy) {
		switch (sy) {
		case '(':return 1;
		case '{':return 2;
		case '[':return 3;
		default:return 0;
		}
	}

	int isCloseBracket(char sy) {
		switch (sy) {
		case ')':return 1;
		case '}':return 2;
		case ']':return 3;
		default:return 0;
		}
	}

	int isCorrectlySpacedBrackets() {
		int bracketType = 0;

		char* temp = new char[strlen(expression) + 1];
		strcpy_s(temp, strlen(expression) + 1, expression);

		for (size_t i = 0; temp[i] != '\0'; i++)
		{
			if (isBracket(temp[i]) ) {

				bracketType = isOpenBracket(temp[i]);
				if (bracketType) {
					for (size_t j = i; temp[j] != '\0'; j++) {
						if (bracketType == isCloseBracket(temp[j])) {
							temp[j] = ' ';
							break;
						}
						else if (temp[j + 1] == '\0') {
							return i;
						}
					}
				}
				else {
					return i;
				}
			}
		}

		return -1;
	}

public:
	Calc(const char* exp)
	{
		expression = new char[strlen(exp) + 1];
		strcpy_s(expression, strlen(exp) + 1, exp);
	}

	int getResult()
	{
		Stack<int> number;
		Stack<char> oper;

		for (int i = 0; expression[i] != '\0'; i++)
		{
			if (isdigit(expression[i]))
			{
				number.push(expression[i] - 48);
			}

			if (this->isOperation(expression[i]))
			{
				if (oper.isEmpty())
				{
					oper.push(expression[i]);
				}
				else
				{
					if (getPriority(expression[i]) > getPriority(oper.peek()))
					{
						oper.push(expression[i]);
					}
					else
					{
						while (getPriority(oper.peek()) > getPriority(expression[i]))
						{
							int a = number.peek();
							number.pop();
							int b = number.peek();
							number.pop();
							char op = oper.peek();
							oper.pop();
							number.push(calc(a, b, op));
						}
						oper.push(expression[i]);
					}
				}
			}
		}

		while (!oper.isEmpty())
		{
			int a = number.peek();
			number.pop();
			int b = number.peek();
			number.pop();
			char op = oper.peek();
			oper.pop();
			number.push(calc(a, b, op));
		}

		return number.peek();
	}

	bool checkBrackets() {
		int index = isCorrectlySpacedBrackets();
		if (index == -1) {
			for (size_t i = 0; expression[i] != '\0'; i++)
			{
				cout << expression[i];
			}
			cout << "\n";
			return 1;
		}
		else {
			HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
			for (size_t i = 0;expression[i]!='\0'; i++)
			{
				if (index == i) {
					SetConsoleTextAttribute(cons, 12);
					cout << expression[i];
					SetConsoleTextAttribute(cons, 7);
					continue;
				}

				cout << expression[i];
			}
			cout << "\n";
			SetConsoleTextAttribute(cons, 7);
			return 0;
		}

	}
};