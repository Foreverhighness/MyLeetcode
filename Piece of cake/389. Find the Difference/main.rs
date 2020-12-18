#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        s.into_bytes()
            .into_iter()
            .chain(t.into_bytes().into_iter())
            .fold(0, |acc, b| acc ^ b)
            .into()
    }
}

fn main() {}
