#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn valid_mountain_array(a: Vec<i32>) -> bool {
        let (mut i, n) = (0, a.len());
        while i + 1 < n && a[i] < a[i + 1] {
            i += 1;
        }
        if i == 0 || i == n - 1 {
            return false;
        }
        while i + 1 < n && a[i] > a[i + 1] {
            i += 1;
        }
        i + 1 == n
    }
}

fn main() {}
