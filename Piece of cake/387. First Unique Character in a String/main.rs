#![allow(dead_code)]
struct Solution;
use std::collections::HashMap;
impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut map = HashMap::new();
        s.into_bytes().into_iter().enumerate().for_each(|(i, b)| {
            map.entry(b).and_modify(|e| *e = -1).or_insert(i as i32);
        });
        *map.values().filter(|&&i| i != -1).min().unwrap_or(&-1)
    }
}

fn main() {}
