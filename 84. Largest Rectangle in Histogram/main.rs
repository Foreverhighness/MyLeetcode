#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn largest_rectangle_area(mut heights: Vec<i32>) -> i32 {
        heights.insert(0, 0); heights.push(0);
        let mut stk = vec![0];
        let mut res = 0;
        for r in 1..heights.len() {
            while heights[stk[stk.len() - 1]] > heights[r] {
                let h = heights[stk[stk.len() - 1]]; stk.pop();
                let l = stk[stk.len() - 1];
                let area = h * (r - l - 1) as i32;
                res = res.max(area);
            }
            stk.push(r);
        }
        dbg!(stk);
        res
    }
}

fn main() {
    dbg!(Solution::largest_rectangle_area(vec![2,1,5,6,2,3]));
}
