#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn find_and_replace_pattern(words: Vec<String>, pattern: String) -> Vec<String> {
        let n = pattern.len();
        let mut idx = [0; 128];
        let idxs = pattern
            .into_bytes()
            .into_iter()
            .enumerate()
            .map(|(i, ch)| {
                if idx[ch as usize] == 0 {
                    idx[ch as usize] = i + 1;
                }
                idx[ch as usize]
            })
            .collect::<Vec<_>>();

        words
            .into_iter()
            .filter(|s| {
                if s.len() != n {
                    return false;
                }
                idx.fill(0);
                for (i, &ch) in s.as_bytes().into_iter().enumerate() {
                    if idx[ch as usize] == 0 {
                        idx[ch as usize] = i + 1;
                    }
                    if idx[ch as usize] != idxs[i] {
                        return false;
                    }
                }
                true
            })
            .collect()
    }
}

fn main() {
    dbg!(
        Solution::find_and_replace_pattern(
            vec![
                "abc".to_string(),
                "deq".to_string(),
                "mee".to_string(),
                "aqq".to_string(),
                "dkd".to_string(),
                "ccc".to_string(),
            ],
            "abb".to_string(),
        ) == vec!["mee".to_string(), "aqq".to_string()]
    );
    dbg!(
        Solution::find_and_replace_pattern(
            vec!["a".to_string(), "b".to_string(), "c".to_string()],
            "a".to_string(),
        ) == vec!["a".to_string(), "b".to_string(), "c".to_string()]
    );
}
