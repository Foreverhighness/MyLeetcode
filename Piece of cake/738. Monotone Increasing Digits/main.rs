#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn monotone_increasing_digits(n: i32) -> i32 {
        let mut v = n.to_string().into_bytes();
        v.iter_mut().for_each(|x| *x -= b'0');
        if let Some(mut i) = (1..v.len()).find(|&i| v[i - 1] > v[i]) {
            while i > 0 && !(v[i - 1] <= v[i]) {
                v[i - 1] -= 1;
                i -= 1;
            }
            ((i + 1)..v.len()).for_each(|i| v[i] = 9);
        }
        v.into_iter().fold(0, |acc, v| acc * 10 + v as i32)
    }
}

fn main() {}
