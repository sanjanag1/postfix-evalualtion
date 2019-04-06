#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluate(string exp);                                              //evaluates the postfix expression
int performOp(char oper, int op1, int op2);                            //as per the operator it performs the operation

int main()
{
    string exp;
    cout << "Enter the postfix expression: ";
    getline(cin, exp);                                                //grabbing the entire expression
    int result = evaluate(exp);
    if(result == -1)
        cout << "Error division by 0 " << endl;
    else
        cout << "The Result= " << result << endl;
}

int evaluate(string exp)
{
    stack<int> mystack;                                           //creating a stack from STL
    int op1, op2, result;
    for(unsigned int i=0; i < exp.length(); i++)                 //traversing the entire string
    {
        if(exp[i] ==' ')                                         //the numbers are delimited by a single space
            continue;

        else if(isdigit(exp[i]))                                //on encountering a digit, the digit is pushed into the stack
        {
            mystack.push(exp[i]-'0');                           //converting to an integer
        }

        else
        {
            op2 = mystack.top();                               //on encountering an operator the operands are popped out of the stack
            mystack.pop();
            op1 = mystack.top();                              //popping the other number from the stack at the other operand
            mystack.pop();
            result = performOp(exp[i], op1, op2);             //function to get the correct operation
            mystack.push(result);                             //theresult is pushed back into the stack
        }
    }
    return mystack.top();                                     //in the end the final number is returned from the stack as the result
}

int performOp(char oper, int op1, int op2)                   //helps choose the correct operation to perform on the operands
{
    if(oper == '+')
        return op1 + op2;
    else if(oper == '-')
        return op1 - op2;
    else if(oper == '*')
        return op1 * op2;
    else if(oper == '/')
    {
        if(op2 == 0)                                         //division by 0 will result in an error
        {
           return -1;
        }
        else
            return op1/op2;
    }
    else
        return 9999;
}
