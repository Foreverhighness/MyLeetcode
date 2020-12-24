#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        g.sort_unstable();
        s.sort_unstable();
        let (mut i, mut j, mut res) = (0, 0, 0);
        while i != g.len() && j != s.len() {
            if s[i] > g[j] {
                j += 1;
                res += 1;
            }
            i += 1;
        }
        res
    }
}

fn main() {}
