func imageSmoother(img [][]int) [][]int {
    m, n := len(img), len(img[0])
    ans := make([][]int, m)
    for i := range ans {
        ans[i] = make([]int, n)
        for j := range ans[i] {
            sum, num := 0, 0
            for _, row := range img[max(i-1, 0):min(i+2, m)] {
                for _, v := range row[max(j-1, 0):min(j+2, n)] {
                    sum += v
                    num++
                }
            }
            ans[i][j] = sum / num
        }
    }
    return ans
}

func max(a, b int) int {
    if b > a {
        return b
    }
    return a
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}
