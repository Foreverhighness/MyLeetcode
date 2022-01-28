impl Solution {
    pub fn number_of_weak_characters(mut properties: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        let mut stk = Vec::new();
        properties.sort_unstable_by_key(|v| (v[0], -v[1]));

        for y in properties.into_iter().map(|v| v[1]) {
            while !stk.is_empty() && *stk.last().unwrap() < y {
                stk.pop();
                res += 1;
            }
            stk.push(y);
        }

        res
    }
}

struct Solution;
fn main() {
    dbg!(
        Solution::number_of_weak_characters(vec![vec![5, 5], vec![6, 3], vec![3, 6]]),
        0
    );
    dbg!(
        Solution::number_of_weak_characters(vec![vec![2, 2], vec![3, 3]]),
        1
    );
    dbg!(
        Solution::number_of_weak_characters(vec![vec![1, 5], vec![10, 4], vec![4, 3]]),
        1
    );
}
