#![allow(dead_code)]
impl Solution {
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let name = format!("^{}$", name);
        let typed = format!("^{}$", name);
        let (name, typed) = (name.into_bytes(), typed.into_bytes());
        let (n, m) = (name.len(), typed.len());
        let (mut i, mut j) = (0, 0);
        while i < n && j < m {
            if (name[i] == typed[j]) {
                i += 1;
                j += 1;
            } else if name[i - 1] == typed[j] {
                j += 1;
            } else {
                return false;
            }
        }
        return i == n && j == m;
    }
}
impl Solution {
    pub fn is_long_pressed_name__(name: String, typed: String) -> bool {
        let (name, typed) = (name.into_bytes(), typed.into_bytes());
        let (n, m) = (name.len(), typed.len());
        let (mut i, mut j) = (0, 0);
        while i < n && j < m {
            if (name[i] != typed[j]) {
                return false;
            }
            let (mut li, mut lj) = (i + 1, j + 1);
            while li < n && name[i] == name[li] {
                li += 1;
            }
            while lj < m && typed[j] == typed[lj] {
                lj += 1;
            }
            if (li - i > lj - j) {
                return false;
            }
            i = li;
            j = lj;
        }
        return i == n && j == m;
    }
}
fn main() {
    
}
struct Solution;