/*
There is N patients(numbered 0 to N-1) who want to see a doctor.. the doctor has S possible time slots, numbered 0 to S-1.
Each patient has a two preferences, the patient i wants to see the doctor at time slot A[i] or time slot B[i].
the doctor can only see one patient at a time, 


that is , given two arrays A and B, each of length N, and an integer S, 
return true if there is a way to schedule all the patients to see the doctor in such a way that no two patients overlap, and the total time spent by the doctor is at most S, and false otherwise.
*/



bool backtracking(vector<int> &A, vector<int> &B, int S, int i, vector<int> &choice, vector<int> &time){
    if(i == A.size()){
        return true;
    }

    if (time[A[i]] == 1 && time[B[i]] == 1) return false;
    if(time[A[i]] == 0){
        time[A[i]]++;
        choice[i] = 1;
        if(backtracking(A, B, S, i+1, choice, time)) return true;
        time[A[i]]--;
        choice[i] = 0;
    }
    if(time[B[i]] == 0){
        time[B[i]]++;
        choice[i] = 2;
        if(backtracking(A, B, S, i+1, choice, time)) return true;
        time[B[i]]--;
        choice[i] = 0;
    }
    
    return false;
}

bool solution(vector<int> &A, vector<int> &B, int S) {
    // Implement your solution here

    int n = A.size();
    if(S < n) return false;
    vector<int> choice(n, 0);
    vector<int> time(S, 0);

    return backtracking(A, B, S, 0, choice, time);
}

