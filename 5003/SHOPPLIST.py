# Catherine is a brilliant software engineer, but she has been having difficulty landing a job, despite having submitted a superb resume to dozens of tech companies. After doing some research, she discovered that most tech companies in her area use an algorithm to prescreen resumes by scanning for certain keywords before the resume is even seen by a human. Any resume that does not contain sufficiently many technology-related keywords is automatically rejected!

# Catherine has devised a plan to outwit the prescreening algorithm: she intends to cram as many keywords as possible into her resume to maximize her chances of passing the prescreening process. As a first step, she has downloaded a list of the most common tech buzzwords from an online data bank that includes entries such as “machine learning”, “Big data”, “AI”, “C++”, “Neural-network”, “unix”, “cryptography”, etc. (Note that keyword sometimes really means keyphrase.)

# In the early stages of drafting her new resume, Catherine notices that many keywords from the data bank are very similar to each other (e.g., “Machine-learning” vs. “machine learning”, or “MySQL” vs. “MySql”). Since she suspects that including nearly identical keywords won’t help her fool the prescreening algorithm, she wants to filter out such similar keywords in order to save room on her resume. Catherine considers two keywords  and  to be similar if, after replacing hyphens with spaces and ignoring capitalization,  is the same as .

# Can you help Catherine craft the perfect resume to land her a job?

# Input
# The first line contains an integer,  , the number of keywords in the data bank. This is followed by  lines, each of which contains a keyword string  that is between  and  characters in length (inclusive). All characters in a keyword are guaranteed to fall in the  ASCII range, and no keyword begins or ends with a space or a hyphen.

# Output
# Output a single line containing the number of (pairwise) non-similar keywords in the data bank.

# Sample Input 1	Sample Output 1
# 4
# c++
# C++
# c
# c#
# 3
# Sample Input 2	Sample Output 2
# 5
# cryptography
# blockchain
# Artificial intelligence
# Machine-Learning
# Linux
# 5
# Sample Input 3	Sample Output 3
# 2
# MySQL
# MySql
# 1

if __name__ == '__main__':
    n = int(input())
    a = set()
    for i in range(n):
        a.add(input().lower().replace('-',' '))
    print(len(a))