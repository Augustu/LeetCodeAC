package main

import "fmt"

func isPowerOfTwo(n int) bool {

	mask := 1
	result := false

	for i := 0; i < 64; i++ {

		if n&mask == 1 {
			if !result {
				result = true
				n = n >> 1
				continue
			}
			if result {
				return false
			}
		}

		n = n >> 1
	}

	return result
}

func main() {
	num1 := 1
	num2 := 16
	num3 := 218

	fmt.Println(isPowerOfTwo(num1))
	fmt.Println(isPowerOfTwo(num2))
	fmt.Println(isPowerOfTwo(num3))
}
