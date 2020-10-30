#![allow(dead_code)]
struct Solution;
impl Solution {
  pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (grid.len(), grid[0].len());
    let mut res = 0;
    let chk = |x: usize, y: usize| x < n && y < m && grid[x][y] == 1;
    for x in 0..n {
      for y in 0..m {
        if grid[x][y] == 1 {
          res += 4;
          if chk(x - 1, y) {
            res -= 2;
          }
          if chk(x, y - 1) {
            res -= 2;
          }
        }
      }
    }
    res
  }
}

fn main() {}
