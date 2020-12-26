#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty() {
            return 0;
        }
        let n = matrix[0].len();
        let mut prv = vec![0; n + 2];
        let mut cur = vec![0; n + 2];
        let mut stk = vec![0];
        let mut res = 0;
        for v in matrix {
            v.into_iter()
                .enumerate()
                .for_each(|(i, c)| cur[i + 1] = if c == '0' { 0 } else { prv[i + 1] + 1 });
            for r in 1..cur.len() {
                while cur[stk[stk.len() - 1]] > cur[r] {
                    let h = cur[stk[stk.len() - 1]]; stk.pop();
                    let l = stk[stk.len() - 1];
                    res = res.max(h * (r - l - 1) as i32);
                }
                stk.push(r);
            }
            stk.truncate(1);
            std::mem::swap(&mut prv, &mut cur);
        }
        res
    }
}

fn main() {
    dbg!(Solution::maximal_rectangle(vec![
        vec!['1', '0'],
        vec!['1', '0'],
    ]));
}
