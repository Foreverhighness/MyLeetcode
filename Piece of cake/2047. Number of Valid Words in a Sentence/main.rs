impl Solution {
    pub fn count_valid_words(sentence: String) -> i32 {
        sentence
            .split_ascii_whitespace()
            .filter(|w| Self::is_valid_word(w))
            .count() as i32
    }
    fn is_valid_word(word: &str) -> bool {
        let mut hyphen = false;
        let mut prev: Option<char> = None;
        let mut iter = word.chars().peekable();
        while let Some(ch) = iter.next() {
            if ch.is_ascii_digit() {
                return false;
            }
            if "!.,".contains(ch) {
                return iter.peek().is_none();
            }
            if ch == '-' {
                if hyphen || prev.is_none() || iter.peek().is_none() {
                    return false;
                }
                if !prev.unwrap().is_ascii_lowercase() || !iter.peek().unwrap().is_ascii_lowercase()
                {
                    return false;
                }
                hyphen = true;
            }
            prev = Some(ch);
        }
        true
    }
}

struct Solution;
fn main() {
    dbg!(Solution::count_valid_words("cat and  dog".to_owned()), 3);
    dbg!(Solution::count_valid_words("!this  1-s b8d!".to_owned()), 0);
    dbg!(
        Solution::count_valid_words(
            "alice and  bob are playing stone-game10 a-b. afad  ba-c a! !".to_owned()
        ),
        10
    );
}
