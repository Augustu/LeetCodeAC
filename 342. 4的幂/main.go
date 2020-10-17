package main

import "fmt"

func isPowerOfFour(num int) bool {
	// ref: https://leetcode-cn.com/problems/power-of-four/solution/4de-mi-by-leetcode/
	return (num > 0) && (num&(num-1) == 0) && (num&0xAAAAAAAA == 0)
}

func main() {
	fmt.Println(isPowerOfFour(16))
	fmt.Println(isPowerOfFour(5))
}
