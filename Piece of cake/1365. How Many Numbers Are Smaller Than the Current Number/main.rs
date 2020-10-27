#![allow(dead_code)]
impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        nums.iter().map(|&x| nums.iter().filter(|&&y| x > y).count() as i32).collect()
    }
}

fn main() {

}
struct Solution;