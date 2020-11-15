#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn remove_kdigits(num: String, mut k: i32) -> String {
        let n = num.len() - k as usize;
        let mut res = Vec::new();
        for ch in num.into_bytes() {
            while let Some(&val) = res.last() {
                if val <= ch || k == 0 {
                    break;
                }
                res.pop();
                k -= 1;
            }
            res.push(ch);
        }
        res.truncate(n);
        let res: Vec<_> = res.into_iter().skip_while(|&ch| ch == b'0').collect();
        if res.is_empty() {
            "0".into()
        } else {
            unsafe { String::from_utf8_unchecked(res) }
        }
    }
}

fn main() {
    println!("{:?}", Solution::remove_kdigits("12345676".to_owned(), 1));
}
