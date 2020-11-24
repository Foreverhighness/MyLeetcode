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
  pub fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let dep = {
      let mut dep = 0;
      let mut cur = root.clone();
      while let Some(nxt) = cur.take() {
        cur = nxt.borrow().left.clone();
        dep += 1;
      }
      dep
    };
    let chk = |n| {
      let mut cur = root.clone();
      let mut mask = 1 << (dep - 2);
      while cur.is_some() && mask > 0 {
        if mask & n == 0 {
          cur = cur.take().borrow().left.clone();
        } else {
          cur = cur.take().borrow().right.clone();
        }
        mask >>= 1;
      }
      cur.is_some()
    };
    let mut hi = 1 << dep;
    let mut lo = hi >> 1;
    while hi - lo > 1 {
      let mid = lo + (hi - lo) / 2;
      if chk(mid) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    lo
  }
}

fn main() {}
