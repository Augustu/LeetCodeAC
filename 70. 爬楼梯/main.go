package main

import "fmt"

/* solution 1
func climbStairs(n int) int {

	if n == 1 {
		return 1
	}

	if n == 2 {
		return 2
	}

	var (
		p int = 1
		q int = 2
		r int
	)

	for i := 2; i < n; i++ {
		r = p + q
		p = q
		q = r	}

	return r
}
*/r	}

	return r
}
*/

func climbStairs(n int) int {
	return 0
}

func main() {
	num1 := 1
	num2 := 2
	num3 := 3

	fmt.Println(climbStairs(num1))
	fmt.Println(climbStairs(num2))
	fmt.Println(climbStairs(num3))
	fmt.Println(climbStairs(4))
	fmt.Println(climbStairs(5))
}
