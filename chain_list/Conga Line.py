# There’s currently a dance party being held in a nondescript location. The party is joined by  couples. To liven up the party, the host, who is not dancing, has decided to perform a conga line. As such, the host asks all the couples to stand in one line.

# At first, each couple will be standing next to each other in line. For example, let there be  couples in the party, Amelia-Bubba and Ollie-Udin. Thus, the line from front to back will be Amelia, Bubba, Ollie, and Udin.

# Then, the host will pass off a mic to the person at the front of the line, and will call out  instructions for the dancers to follow, consisting of these  types:

# : The mic holder will pass the mic to the person in front of them. It is guaranteed that such a person exists.

# : The mic holder will pass the mic to the person behind them. It is guaranteed that such a person exists.

# : The mic holder will pass the mic to the person behind them. Then, they will move to the back of the line. In the case that the mic holder is at the back of the line, the mic will be passed to the person at the front of the line instead.

# : The mic holder will pass the mic to the person behind them. Then, they will move to behind where their partner is standing. In the case that the mic holder is at the back of the line, the mic will be passed to the person at the front of the line instead.

# : The mic holder will yell their partner’s name into the mic.

# Input
# The first line of input contains two integers  () and  (), denoting the number of couples participating and the number of instructions respectively.

# The next  lines each contain two names, the names of a couple participating in the dance. The list of names will be given in accordance with the order they will be standing in the conga line. Each name will consist of at most  lower-case Latin alphabet characters (-). It is guaranteed that the given names are unique.

# The final line will be a string of length , representing the instructions given by the host. It is guaranteed that the string will only contain the characters , , , , and .

# Output
# For each name yelled, print the name on a separate line in order. Then, print an empty line. Finally, print  lines, each containing the names of the person in the line from front to back.

# Subtasks
# ( Points): There will be no -type, -type, or -type instructions.

# ( Points): There will be no -type or -type instructions.

# ( Points): . There will be no -type instructions.

# ( Points): . There will be no -type instructions.

# ( Points): There will be no -type instructions.

# ( Points): 

# ( Points): No additional constraints.

# Explanation
# For the explanation below, all names will have their first character capitalized. However, all names in the input and output will be in lower-case.

# In the first sample, the following illustration shows the line at the start of the game:

# \includegraphics[height = 90px]{startState.PNG}

# Then, the host calls out  instructions as follows:

# The mic holder, Amelia, yells their partner’s name, Bubba. The following illustrates this instruction.
# \includegraphics[height = 100px]{Poperation.PNG}

# The mic is passed to the person behind Amelia, Bubba. The following illustrates this instruction.
# \includegraphics[height = 70px]{Boperation.PNG}

# The mic is passed to the person behind Bubba, Kiryu.

# Kiryu yells their partner’s name, Coco.

# The mic is passed to the person in front of Kiryu, Bubba. The following illustrates this instruction.
# \includegraphics[height = 75px]{Foperation.PNG}

# Bubba will yell their partner’s name, Amelia.

# Since no one has moved, the line at the end of the  instructions will still be the same.

# In the second sample, the line will at first be the same as above. Then, the host calls out  instructions as follows:

# The mic is passed to the person behind Amelia, Bubba.

# Bubba passes the mic to Kiryu, then moves to the back of the line. The line formation is now Amelia, Kiryu, Coco, Ollie, Udin, and Bubba. The following illustrates this instruction.
# \includegraphics[height = 85px]{Roperation.PNG}

# Kiryu passes the mic to Coco. In the next instruction, Coco yells "Kiryu" into the mic.

# Coco passes the mic to Ollie, then moves to the back of the line. The line formation is now Amelia, Kiryu, Ollie, Udin, Bubba, and Coco.

# Ollie passes the mic to Kiryu, who then passes it to Amelia. In the next instruction, Amelia yells "Bubba" into the mic.

# Amelia passes the mic to Kiryu, then moves to the back of the line. The line formation is now Kiryu, Ollie, Udin, Bubba, Coco, and Amelia.

# The next  operations moves the mic to the last person in line, Amelia.

# Amelia passes the mic to Kiryu, then moves to the back of the line. The line formation doesn’t change.

# Kiryu yells out their partner’s name, Coco.

# Thus, at the end, the line will be Kiryu, Ollie, Udin, Bubba, Coco, and Amelia.

# Note that the third sample is the second sample will additional instructions appended, as such, we shall continue from the -th operation to the end. In the third sample, the host will call out the last  instructions as follows:

# Kiryu passes the mic to Ollie, then moves to behind Coco. The line formation is now Ollie, Udin, Bubba, Coco, Kiryu, and Amelia.
# \includegraphics[height = 85px]{Coperation.PNG}

# Ollie passes the mic to Udin, who then passes the mic to Bubba.

# Bubba passes the mic to Coco, then moves to behind Amelia. The line formation is now Ollie, Udin, Coco, Kiryu, Amelia, and Bubba.

# Coco passes the mic to Udin.

# Udin yells out their partner’s name, Ollie.

# Thus, at the end, the line formation will be Ollie, Udin, Coco, Kiryu, Amelia, and Bubba.

# Warning
# The I/O files are large. Please use fast I/O methods.
"""
Sample Input 1	Sample Output 1
3 6
amelia bubba
kiryu coco
ollie udin
PBBPFP
bubba
coco
amelia

amelia
bubba
kiryu
coco
ollie
udin
Sample Input 2	Sample Output 2
3 16
amelia bubba
kiryu coco
ollie udin
BRBPRFFPRBBBBBRP
kiryu
bubba
coco

kiryu
ollie
udin
bubba
coco
amelia
Sample Input 3	Sample Output 3
3 22
amelia bubba
kiryu coco
ollie udin
BRBPRFFPRBBBBBRPCBBCFP
kiryu
bubba
coco
ollie

ollie
udin
coco
kiryu
amelia
bubba
"""
# Note
class linkNode:
    def __init__(self, name, next = None, prev = None, couple = None):
        self.name = name
        self.next = next
        self.prev = prev
        self.couple = couple

    def action(self, action, yell, tail, head):
        if action == 'B':
            return self.next, yell, tail, head
        elif action == 'F':
            return self.prev, yell, tail, head
        elif action == 'R':
            if self == head:
                head = self.next
                head.prev = None
                mic = head
                self.prev = tail
                tail.next = self
                self.next = None
                tail = self
            elif self == tail:
                mic = head
            else:
                mic = self.next
                self.prev.next = self.next
                self.next.prev = self.prev
                self.prev = tail
                tail.next = self
                self.next = None
                tail = self 
            return mic, yell, tail, head
        elif action == 'C':
            if self == head:
                head = self.next
                head.prev = None
                mic = head
            elif self == tail:
                tail = self.prev
                tail.next = None
                mic = head
            else:
                self.prev.next = self.next
                self.next.prev = self.prev
                mic = self.next

            self.prev = self.couple
            self.next = self.couple.next
            if self.couple == tail:
                tail.next = self
                tail = self
            else:
                self.couple.next.prev = self
                self.couple.next = self
            return mic, yell, tail, head
        elif action == 'P':
            yell.append(self.couple.name)
            return self, yell, tail, head

if __name__ == '__main__':
    n, m = map(int, input().split())
    names = [input().split() for _ in range(n)]
    instructions = input()

    for i in range(n):
        names[i][0] = linkNode(names[i][0])
        names[i][1] = linkNode(names[i][1])
        names[i][0].couple = names[i][1]
        names[i][1].couple = names[i][0]

    for i in range(n):
        names[i][0].next = names[i][1]
        names[i][1].prev = names[i][0]
        names[i][0].prev = names[(i - 1) % n][1]
        names[i][1].next = names[(i + 1) % n][0]
    
    mic = names[0][0]
    head = names[0][0]
    tail = names[-1][1]
    head.prev = None
    tail.next = None
    yell = []
    for i in instructions:
        mic, yell, tail, head = mic.action(i, yell, tail, head)
    for i in range(len(yell)):
        print(yell[i])
    print()
    mic = head
    while mic:
        print(mic.name)
        mic = mic.next


    # couples = {name: partner for name, partner in names}
    # couples.update({partner: name for name, partner in names})
    # names = list(names)
    # mic = 0
    # yell = []
    # for i in range(m):
    #     if instructions[i] == 'F':
    #         mic = (mic - 1) % (2*n)
    #     elif instructions[i] == 'B':
    #         mic = (mic + 1) % (2*n)
    #     elif instructions[i] == 'R':
    #         names = names[:mic] + names[mic + 1:] + [names[mic]]
    #         if mic == 2 * n - 1:
    #             mic = 0
    #     elif instructions[i] == 'C':
    #         couple_index = names.index(couples[names[mic]])
    #         if couple_index < mic:
    #             names = names[:couple_index] + [names[mic]] + names[couple_index:mic] + names[mic + 1:]
    #         else:
    #             names = names[:mic] + names[mic + 1:couple_index + 1] + [names[mic]] + names[couple_index + 1:]
    #         if mic == 2*n - 1:
    #             mic = 0
    #     elif instructions[i] == 'P':
    #         yell.append(couples[names[mic]])

    #     # print(f"{names} {mic}") 
