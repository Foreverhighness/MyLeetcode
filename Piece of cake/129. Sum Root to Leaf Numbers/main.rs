#![allow(dead_code)]
struct Solution;
// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None,
    }
  }
}
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
  pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let mut res = 0;
    fn dfs(cur: &Option<Rc<RefCell<TreeNode>>>, mut val: i32, res: &mut i32) {
      if cur.is_none() {
        return;
      }
      let cur = cur.as_ref().unwrap().borrow();
      val = val * 10 + cur.val;
      if cur.left.is_none() && cur.right.is_none() {
        *res += val;
      } else {
        dfs(&cur.left, val, res);
        dfs(&cur.right, val, res);
      }
    };
    dfs(&root, 0, &mut res);
    res
  }
}

fn main() {}
