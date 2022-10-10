# Björn and  other children stand in line to meet the "fluortant" (the fluoride administrator, who comes to school to give children fluoride treatments). Different children are more or less scared of the fluortant. The children are numbered from  to , and child  is in position  in the queue. Child  also has associated value , which shows how reluctant the child is to meet the fluortant. The happiness that child  feels of their place in the queue is . A child can have negative , which means that they actually want to meet the fluortant and thus are sorry to have to wait.

# Björn is the only child who is completely indifferent to meeting the fluortant, that is, he is the only child who has . In addition, he is very kindhearted, so he decides to leave the queue and then enter the queue again somewhere so that the total happiness of everyone in the queue is as great as possible. Write a program that, given the values  for all children, calculates the maximum sum of the happiness in the queue if Björn stands in an optimal place.

# Input
# The first line contains an integer , the number of children in the queue. On the next line are  integers, where the th number is . , .

# Output
# Print a line with one integer: the maximum total happiness in the queue.

# Points
# Your solution will be tested on several test case groups. To get points for a group your submission must pass all the test cases in the group.

# 3
# 1 0 -2
# -3
# Sample Input 2	Sample Output 2
# 5
# 0 -8 1 1 5
# 24
# Sample Input 3	Sample Output 3
# 7
# 2 -4 5 -3 0 -1 2
# 7

# from operator import index


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    max_sum = 0
    for i in range(n):
        max_sum += a[i] * (i + 1)
        if(a[i] == 0):
            index = i
    max_tmp = 0
    if index > 0:
        tmp = 0
        for i in range(index-1,-1,-1):
            tmp += a[i]
            max_tmp = max(max_tmp, tmp)

    min_tmp = 0
    if index < n-1:
        tmp = 0
        for i in range(index + 1, n):
            tmp += a[i]
            min_tmp = min(min_tmp, tmp)
    m = max(max_tmp, -min_tmp)
    max_sum += max(m,0)
    print(max_sum)