package main

import "fmt"

func addBinary(a string, b string) string {
	// carry := 0
	max := 0
	var base *string
	if len(a) > len(b) {
		max = len(a)
		base = &a
	} else {
		max = len(b)
		base = &b
	}

	for i := 0; i < max; i++ {
		fmt.Print(string((*base)[i]))
	}

	return ""
}

func main() {
	addBinary("101", "100")
}
