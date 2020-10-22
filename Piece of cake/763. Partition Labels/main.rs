#![allow(dead_code)]
impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let s = s.into_bytes();
        let mut last = vec![0; 26];
        println!("{:?}", last);
        
        for (i, &ch) in s.iter().enumerate() {
            last[ch as usize - 'a' as usize] = i as i32;
        }
        let mut res = Vec::new();
        let (mut begin, mut end) = (-1, 0);
        for (i, &ch) in s.iter().enumerate() {
            let i = i as i32;
            end = end.max(last[ch as usize - 'a' as usize]);
            if i == end {
                res.push(end - begin);
                begin = end;
            }
        }
        return res;
    }
}

fn main() {
    Solution::partition_labels("aaaaaa".to_string());
}
struct Solution;