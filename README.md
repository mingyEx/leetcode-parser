### Description

Helps to debug `leetcode` problems in IDE

### Feature
1. creating data structures such as  `vector`,`tree` and `list`.  
2. Quickly print common containers
3. Convert the input parameters of the [Design problems](https://leetcode.com/tag/design/) into corresponding function calls.

### dependencies 
[boost-describe](https://www.boost.org/doc/libs/develop/libs/describe/) when debug [design problems](https://leetcode.com/tag/design/)
### usage
1. Create an array `Vec<int>`/`Vec<string>`
2. Create a 2D array : `Vec2<int>`/`Vec2<string>`
3. Create a linked list : `List()`
4. Create a tree : `Tree()`


### note
0.`lintcode`/`codewars` users need to replace `{}` with `[]` and `#` with `null`  
<!-- fmt对map的打印很丑，不用它 -->

1.Treat an array of parameters with multiple different types as an array of strings, and choose whether to convert to int according to whether it starts with ".  
example:`[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]` in  [2296](https://leetcode.com/problems/design-a-text-editor/)   

2.Treat [n-ary-tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/) as graphs  

3.if you are having problems with array subscript overflow, you can choose to turn on the `(/fsanitize=address)` option in `visual studio` and set the configuration to `release` to get the same output as `leetcode`,and get the actual line number of the code location where the error occurred.

### todo
add [inliner](https://github.com/slycelote/caide/blob/release/libcaide/README.md#c-code-inliner) 
### Any feature improvement suggestions are welcome

### Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)  
[leetcode-helper](https://github.com/luckystone60/leetcode-helper)  
[caide](https://github.com/slycelote/caide/issues/50)  
[boost.Describe](https://www.boost.org/doc/libs/develop/libs/describe/doc/html/describe.html#example_json_rpc)  
[leetcode-playground-stringToString](https://leetcode.cn/playground/new/empty)
