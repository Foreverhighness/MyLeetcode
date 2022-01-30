#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn number_of_steps(num: i32) -> i32 {
        (31u32.saturating_sub(num.leading_zeros()) + num.count_ones()) as i32
    }
}

fn main() {
    dbg!(Solution::number_of_steps(14) == 6);
    dbg!(Solution::number_of_steps(0) == 0);
}
