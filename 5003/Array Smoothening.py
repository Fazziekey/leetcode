# You’ve just finished writing a random array generator for your competitive programming practical examination problem. However, when you tested it, you noticed that the distribution is skewed; some values may appear much more times than the other values. You wanted to smoothen the distribution, but you don’t want to modify your generator anymore. Thus, you decide to remove exactly  elements from the array, such that the maximum occurrence of a value is minimized. Now, given an array  of size , determine the minimum possible maximum occurrence of a value from the array after you remove exactly  elements from it.

# Input
# The first line contains two integers  () and  ().

# The next line contains  integers  (), the elements of the array .

# Output
# Print the minimum possible maximum occurrence of a value of  after exactly  removal.

# Subtasks
# ( Points): , , , and  is sorted in non-decreasing order.

# ( Points): , , and .

# ( Points):  and .

# ( Points): .

# ( Points): .

# ( Points): No additional constraints.

# Explanation
# In the first sample,  appears twice,  appears three times,  appears five times, and none of the elements will be removed. Thus, the maximum occurrence is five.

# In the second sample, we can remove two occurrences of  and one occurrence of . Hence,  and  appear twice, and  appears three times. Thus, the maximum occurrence is three.

# Warning
# The I/O files are large. Please use fast I/O methods.
'''
Sample Input 1	Sample Output 1
10 0
1 1 3 3 3 3 3 7 7 7
5
Sample Input 2	Sample Output 2
10 3
3 1 7 3 3 3 7 3 1 7
3
'''
import random

if __name__ == "__main__":
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    # n = 200000
    # k = 100000
    # arr = [random.randint(1, 10000) for i in range(n)]
    if n == k:
        print(0)
        exit()

    # arr.sort()
    map_list = {}
    # count = 1
    for i in range(n):
        if arr[i] in map_list:
            map_list[arr[i]] += 1
        else:
            map_list[arr[i]] = 1
    # for i in range(n-1):
    #     if arr[i] == arr[i+1]:
    #         count += 1
    #     else:
    #         map_list.append(count)
    #         count = 1

    # map_list.append(count)
    # print(map_list)
    map_list = list(map_list.values())
    map_list.sort()
    
    if k == 0:
        print(map_list[-1])
        exit()

    while k > 0:
        max_fre = map_list[-1]
        if max_fre == 1:
            print(1)
            exit()
        for i in range(len(map_list)-1, -1, -1):
            if map_list[i] == max_fre:
                map_list[i] -= 1
                k -= 1
                if k == 0:
                    break
            else:
                break

    print(max(map_list))

