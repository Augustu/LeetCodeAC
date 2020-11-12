package main

import "fmt"

func findTheDifference(s string, t string) byte {
	var result byte
	for i := 0; i < len(s); i++ {
		result ^= s[i]
		result ^= t[i]
	}

	result ^= t[len(t)-1]

	// var b byte
	return byte(result)
}

func main() {
	fmt.Println(findTheDifference("abcd", "abcde"))
}
