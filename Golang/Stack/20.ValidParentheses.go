/*
    Title:          20.ValidParentheses.go
    Update date:    2020/09/21
    Author:         Zhuofan Zhang
*/
package solution

// --------- stack impl ---------

type stack struct {
    Container []rune
}

func (s *stack) top() rune {
    if l := len(s.Container); l != 0 {
        return s.Container[l-1]
    } else {
        panic("top from empty stack.")
    }
}

func (s *stack) push(c rune) {
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

// -------------------------------

func isValid(s string) bool {
    var stk stack
    for _, c := range s {
        switch ch := c; ch {
            case '(': stk.push(c)
            case '[': stk.push(c)
            case '{': stk.push(c)
            case ')':
                if stk.isEmpty() || stk.top() != '(' {
                    return false
                } else {
                    stk.pop()
                }
            case ']':
                if stk.isEmpty() || stk.top() != '[' {
                    return false
                } else {
                    stk.pop()
                }
            case '}':
                if stk.isEmpty() || stk.top() != '{' {
                    return false
                } else {
                    stk.pop()
                }
        }
    }

    return stk.isEmpty()
}