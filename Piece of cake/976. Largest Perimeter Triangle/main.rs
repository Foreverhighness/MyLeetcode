#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn largest_perimeter(mut a: Vec<i32>) -> i32 {
        a.sort_unstable();
        a.windows(3)
            .rev()
            .find(|&t| t[0] + t[1] > t[2])
            .map_or(0, |t| t[0] + t[1] + t[2])
    }
}

fn main() {}
