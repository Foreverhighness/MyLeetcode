# 记录个人刷力扣做的题目

一些心得：

- WSL 只是写写题的话还是蛮好用的。

- `Python` 里用 `functools.lru_cache` 进行 `dp` 的话要设置最大递归深度 `sys.setrecursionlimit`.

- `C++` 中用 `lambda` 捕获类内元素时，应该设置别名或者直接捕获 `this`.

  ```C++
  class MyClass {
      int idx = 0;
      void test(vector<int>& vec) {
          auto foo = [& idx = idx]() { std::cout << vec[idx] << std::endl; };
          auto bar = [&this]() { std::cout << vec[idx] << std::endl; };
      }
  }
  ```

- 感觉 `C++` 中 `for_each` 比 `for` 快。

  ```c++
  class MyClass {
      vector<vector<int>> G;
      void foo(vector<vector<int>>& edges) {
          for_each(vec.begin(), vec.end(),
                   [& G = G](vector<int>& edge) { G[edge[0]].emplace_back(edge[1]); });
          for (vector<int>&& edge: vec)
              G[edge[0]].emplace_back(edge[1]);
      }
  }
  
  ```

- `C++` 中 `push_back` 要进行一次拷贝，`emplace_back` 不需要，但是 `push_back` 可以用列表初始化，而 `emplace_back` 只能调用构造函数，不过也因此可以不加参数。

  ```C++
  vector<int> foo() {
      using P = pair<int, int>;
      vector<P> vec;
      vec.push_back({0, 0});    // 通过 Vaild
      vec.emplace_back({0, 0}); // 报错 Invaild
      vec.push_back(0, 0);      // 报错 Invaild
      vec.emplace_back(0, 0);   // 通过 Vaild
      vec.push_back();          // 报错 Invaild
      vec.emplace_back();       // 通过 Vaild
      return {0, 0};            // 通过 Vaild
  }
  ```

- `C++` 中拼接字符串时用 `string` 的 `+=` 比 `stringstream` 要快。（惊了）

- `C++17` 里的 `string_view` 是个好东西。

- `C++` 中 `set` 有自带的 `lower_bound`，返回的是大于等于而不是小于，不建议对 `set` 用 `std::lower_bound`.

- `C++` 中好像 `bitset<32>(num).count()` 比 `__builtin_popcount()` 要快。

