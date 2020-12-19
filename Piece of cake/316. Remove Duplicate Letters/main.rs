#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn remove_duplicate_letters(s: String) -> String {
        let mut vis = [false; 26];
        let mut cnt = [0u16; 26];
        let mut res = Vec::with_capacity(26);
        s.bytes().for_each(|b| cnt[(b - b'a') as usize] += 1);
        for ch in s.into_bytes() {
            if !vis[(ch - b'a') as usize] {
                while !res.is_empty()
                    && res[res.len() - 1] > ch
                    && cnt[(res[res.len() - 1] - b'a') as usize] != 0
                {
                    vis[(res[res.len() - 1] - b'a') as usize] = false;
                    res.pop();
                }
                vis[(ch - b'a') as usize] = true;
                res.push(ch);
            }
            cnt[(ch - b'a') as usize] -= 1;
        }
        unsafe { String::from_utf8_unchecked(res) }
    }
}

fn main() {}
