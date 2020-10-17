package main

import "fmt"

func getSum(a int, b int) int {
	carrier := (a & b) << 1
	result := a ^ b
	for carrier != 0 {
		a = result
		b = carrier
		// only need to add carrier all the time
		carrier = (a & b) << 1
		result = a ^ b
	}
	return result

	// and := (a & b) << 1
	// xor := a ^ b
	// fmt.Println("example ", and, xor)
	// for and != 0 {
	// 	b = and
	// 	a = xor
	// 	fmt.Println("example ", and, xor)
	// 	and = (a & b) << 1
	// 	xor = a ^ b
	// 	fmt.Println("example ", and, xor)
	// }
	// return xor

}

func main() {
	fmt.Println(getSum(1, 2))
	fmt.Println(getSum(-2, 3))
}
