### Description

Helps to debug `leetcode` problems in IDE

### Feature
1. creating data structures such as  `vector`,`tree` and `list`.  
2. Quickly print common containers
3. Convert the input parameters of the [Design problems](https://leetcode.com/tag/design/) into corresponding function calls.

### dependencies 
[boost-describe](https://www.boost.org/doc/libs/develop/libs/describe/) when debug [design problems](https://leetcode.com/tag/design/)

### Todo :   
#### -1. Use cmake to organize files
#### 0.Support for more complex input parameter types
- [ ] implementing a `json parser`-like function to support two-dimensional vector containing more than one types.   
for example `[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]` in  [2296](https://leetcode.com/problems/design-a-text-editor/)  

#### 1.print more data structures
- [ ] n-ary-tree   
  [559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)    
  [2003. Smallest Missing Genetic Value in Each Subtree](https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/)   
  [2246. Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)  

#### 2. To improve the debugging experience for grid and tree problems，Add a [natvis](https://www.cnblogs.com/X-Jun/p/8040916.html) file to modify the display in the locals window    
  1. For linked lists, add a display similar to std::list    
  2. For tree, the value of the pointer itself should be hidden, and only the member data `val` should be displayed.  
  If there are left and right sub-objects:  
    if it is nullptr, only null should be displayed.   
    If it has a value, only `val` should be displayed.    
  3. The two-dimensional grid displays its index in the form of [y,x].  
  
### note
`lintcode`/`codewars` users need to replace `{}` with `[]` and `#` with `null`  
<!-- fmt对map的打印很丑，不用它 -->
### Any feature improvement suggestions are welcome

### Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)  
[leetcode-helper](https://github.com/luckystone60/leetcode-helper)  
[caide](https://github.com/slycelote/caide/issues/50)  
[boost.Describe](https://www.boost.org/doc/libs/develop/libs/describe/doc/html/describe.html#example_json_rpc)  
[leetcode-playground-stringToString](https://leetcode.cn/playground/new/empty)
