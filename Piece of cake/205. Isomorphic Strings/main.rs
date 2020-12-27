#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let (s, t) = (s.into_bytes(), t.into_bytes());
        let (mut si, mut ti) = ([0; 128], [0; 128]);
        for i in 0..s.len() {
            if si[s[i] as usize] == 0 {
                si[s[i] as usize] = 1 + i;
            }
            if ti[t[i] as usize] == 0 {
                ti[t[i] as usize] = 1 + i;
            }
            if si[s[i] as usize] != ti[t[i] as usize] {
                return false;
            }
        }
        true
    }
}

fn main() {}
