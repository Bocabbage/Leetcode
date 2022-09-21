/*
    Title:          42.TrappingRainWater.go
    Update date:    2020/09/21
    Author:         Zhuofan Zhang
*/
package solution

// --------- stack impl ---------
type stack struct {
    Container []int
}

func (s *stack) top() int {
    if l := len(s.Container); l != 0 {
        return s.Container[l-1]
    } else {
        panic("top from empty stack.")
    }
}

func (s *stack) push(c int) {
    s.Container = append(s.Container, c)
}

func (s *stack) pop() {
    if l := len(s.Container); l != 0 {
        s.Container = s.Container[:l-1]
    } else {
        panic("pop from empty stack.")
    }
}

func (s *stack) isEmpty() bool {
    return len(s.Container) == 0
}

func (s *stack) size() int {
    return len(s.Container)
}

// -------------------------------
// Mono-stack solution

func trap(height []int) int {
    var res int
    var stk stack

    for i := range height {
        if stk.isEmpty() {
            stk.push(i)
        } else if stk.size() < 2 {
            if height[stk.top()] < height[i] {
                stk.pop()
            } 
            stk.push(i)
        } else {
            for stk.size() >= 2 && height[stk.top()] < height[i] {
                midHeight := height[stk.top()]
                stk.pop()

                width := i - stk.top() - 1
                var edgeHeight int 
                if height[i] > height[stk.top()] {
                    edgeHeight = height[stk.top()]
                } else {
                    edgeHeight = height[i]
                } 

                res += (edgeHeight - midHeight) * width
            }

            if height[stk.top()] < height[i] {
                stk.pop()
            }

            stk.push(i)
        }
    }

    return res
}