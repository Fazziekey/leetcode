func maxConsecutiveChar(answerKey string, k int, ch byte) (ans int) {
    left, sum := 0, 0
    for right := range answerKey {
        if answerKey[right] != ch {
            sum++
        }
        for sum > k {
            if answerKey[left] != ch {
                sum--
            }
            left++
        }
        ans = max(ans, right-left+1)
    }
    return
}

func maxConsecutiveAnswers(answerKey string, k int) int {
    return max(maxConsecutiveChar(answerKey, k, 'T'),
               maxConsecutiveChar(answerKey, k, 'F'))
}

func max(a, b int) int {
    if b > a {
        return b
    }
    return a
}
