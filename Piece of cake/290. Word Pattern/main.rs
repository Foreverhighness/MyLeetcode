#![allow(dead_code)]
struct Solution;
use std::collections::HashMap;
impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let s = s.into_bytes();
        let v: Vec<&[u8]> = s.split(|b| *b == b' ').collect();
        if v.len() != pattern.len() {
            return false;
        }
        let (mut smap, mut pmap) = (HashMap::new(), HashMap::new());
        v.into_iter()
            .zip(pattern.into_bytes().into_iter())
            .all(|(s, p)| {
                let sp = smap.entry(s).or_insert(p);
                let ps = pmap.entry(p).or_insert(s);
                *sp == p && *ps == s
            })
    }
}
fn main() {}
