# Given a bracket sequence  of length , you are to determine if it is valid!

# A valid bracket sequence is defined recursively as:

# “”

#  where  is a valid bracket sequence

#  where  is a valid bracket sequence

#  where  is a valid bracket sequence

# , where  and  are valid bracket sequences

# Input
# The first line of each contains one integer n  — the length of the bracket sequence.

# The second line of each test case contains a string  — the bracket sequence in the question. It is guaranteed that  only contains  as characters.

# Output
# Output a single integer — the answer to the problem.

# Sample Input 1	Sample Output 1
# 6
# ([]{})
# Valid
# Sample Input 2	Sample Output 2
# 8
# (())((()
# Invalid
# Sample Input 3	Sample Output 3
# 6
# ([}{])
# Invalid

if __name__ == '__main__':
    n = int(input())
    s = input()
    stack = []
    for i in s:
        if i == '(' or i == '[' or i == '{':
            stack.append(i)
        else:
            if len(stack) == 0:
                print('Invalid')
                exit()
            if i == ')' and stack[-1] == '(':
                stack.pop()
            elif i == ']' and stack[-1] == '[':
                stack.pop()
            elif i == '}' and stack[-1] == '{':
                stack.pop()
            else:
                print('Invalid')
                exit()
    if len(stack) == 0:
        print('Valid')
    else:
        print('Invalid')