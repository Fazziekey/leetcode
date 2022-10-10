# Your boss likes to see numbers going up as proof that your company is successful. To help with this, you came up with the idea to summarize a list of numbers by “zooming out,” that is, to discard everything except every  number in the list, for some .

# Business has been tough lately, with lots of ups and downs. However, if you pick the right value of , maybe you can prove to your boss that things aren’t so bad after all! If possible, you should find the smallest value of  such that , where 
 
# , and the list  contains at least two elements.

# Input
# The first line contains an integer , with . The second line contains  integers  describing the list of numbers. It is guaranteed that  for .

# Output
# If possible, display the smallest value  for which  (where 
 
# ) is strictly increasing and has at least two elements. If no such value of  exists, display the word “ABORT!”

# Sample Input 1	Sample Output 1
# 10
# 1 2 3 4 5 6 7 8 9 10
# 1
# Sample Input 2	Sample Output 2
# 8
# 1 8 2 7 3 6 4 5
# 3
# Sample Input 3	Sample Output 3
# 10
# 9 8 8 4 4 3 10 1 1 0
# ABORT!

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    for k in range(1, n//2+1):
        flag = 1
        for i in range(k-1,n-k,k):
            if a[i] >= a[i + k]:
                flag = 0
                break
        if flag == 1:
            print(k)
            break
    if flag == 0:
        print("ABORT!")