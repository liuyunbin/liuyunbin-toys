
#### 函数原型：
```
const char* strrchr(const char* str, int ch);
      char* strrchr(      char* str, int ch);
```

#### 函数说明：
* 查找 str 所指向的字符串中的最后一个 ch 的位置
* ch 将转化为 char 比较
* ch 可以是 '\0'
* str 所指向的字符串中的 '\0' 也会被查找

#### 参数要求：
* src 所指向的字符数组中一定包含 '\0'

#### 返回说明：
* 如果找到，返回 str 所指向的字符串中的最后一个 ch 的位置
* 如果未找到，将返回 NULL

详细内容见 函数实现及其注释
