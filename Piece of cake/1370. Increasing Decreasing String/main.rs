#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn sort_string(s: String) -> String {
        let len = s.len();
        let mut cnt = [0; 26];
        let mut res = Vec::with_capacity(len);
        s.into_bytes()
            .into_iter()
            .for_each(|ch| cnt[(ch - b'a') as usize] += 1);
        while res.len() != len {
            for ch in (0..26_u8).chain((0..26_u8).rev()) {
                if cnt[ch as usize] != 0 {
                    res.push(ch + b'a');
                    cnt[ch as usize] -= 1;
                }
            }
        }
        unsafe { String::from_utf8_unchecked(res) }
    }
}

fn main() {}
