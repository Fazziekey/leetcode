'''
Hide
Problem A
Illuminati Spotti
One of Xxayvier’s favorite pastimes is spotting triangles due to his obsession with the Illuminati. Xxayvier has taken it to the extreme and has been trying to spot triangles on the larger scale.

He believes that the Illuminati has control of all cities which have  undirected flights connecting to each other in a triangle shape. To test this theory, Xxayvier has been making maps listing undirected flights that connect from city  to city . He then tries to find the triangles from the map afterwards.

Because of the large number of cities that Xxayvier has listed, it has been very difficult keeping track and finding them all. Can you help him find the number of triangles made without duplicates?

Input
Input consists of  lines. The first contains the number of cities that you are given  (). The next  input lines represent a city  and the undirected flight that connects to another city . Each line has  numbers each number representing a city  in ascending order. Each number can be either a  in which a flight towards city  exists or a  meaning the flight does not exist.

Output
Given that the triangles are created only by  connecting cities, output the number of triangles the map can have without repeats.

Sample Input 1	
4
0 1 1 0 
1 0 1 1 
1 1 0 1 
0 1 1 0 
Sample Output 1
2
Sample Input 2	
5
0 1 1 0 1 
1 0 1 1 0 
1 1 0 1 1 
0 1 1 0 0 
1 0 1 0 0 
Sample Output 2
3
'''

if __name__ == '__main__':
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    count = 0
    for i in range(n):
        for j in range(i,n):
            if matrix[i][j] == 1:
                for k in range(j,n):
                    if matrix[k][i] == 1 and matrix[k][j] == 1:
                        count += 1
    print(count)