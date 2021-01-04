#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn fib(n: i32) -> i32 {
        (0..n).fold((0, 1), |(a, b), _| (b, a + b)).0
    }
}

fn main() {}
