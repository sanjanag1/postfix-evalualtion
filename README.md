# postfix-evalualtion
 Stack application: postfix expression evaluation. 
 
 
 Example1:  - (valid expr) 4 3 - 5 *  
 -- push 4 into stack  -- push 3 into stack 
 -- minus operator (-) detected: pop 3 out of stack, as operand_2 
 -- pop 4 out of stack, as operand_1 
 -- perform operand_1 minus operand_2, then push the result (1) into stack.  
 -- push 5 into stack 
 -- multiply operator (*) detected: pop 5 out of stack, as operand_2 
 -- pop 1 out of stack, as operand_1 -- perform operand_1 times operand_2, then push the result (5) into stack.  
 -- input done. check stack value... output final answer: 5
