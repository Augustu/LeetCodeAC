package main

import (
	"fmt"
	"strconv"
)

func reverseBits(num uint32) uint32 {

	var result uint32
	var bits uint32
	var mask uint32 = 1

	for i := 0; i < 32; i++ {
		bits = num & mask
		num = num >> 1
		result = result << 1
		result = result | bits
	}

	return result
}

func main() {
	n1, _ := strconv.ParseUint("00000010100101000001111010011100", 2, 32)
	nums1 := uint32(n1)
	n2, _ := strconv.ParseUint("11111111111111111111111111111101", 2, 32)
	nums2 := uint32(n2)

	fmt.Println(reverseBits(nums1))
	fmt.Println(reverseBits(nums2))
}
