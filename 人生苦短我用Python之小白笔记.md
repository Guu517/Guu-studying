# 人生苦短我用Python之小白笔记

## 一、 学前小知识

1. Python是纯粹的开源语言、标准脚本语言，允许混合使用C/java代码

2. 创始人吉多·范罗苏姆^荷兰^(龟叔)

   

## 二、基础

1. 输入输出

   输出常量需用引号将内容包围`print("hello world!")`

   ```
   print(1024)
   ```

2. 注释

   ```
   #这是一行注释
   ```

3. 变量与常量

   3.1.变量名只能由字母、数字、下划线组成

   *不能以数字开头；不能包含空格；大小写敏感*

   3.2.常量指不能被修改的数据

4. 赋值

   ```
   name = "517"
   ```

5. 格式化输出

   字符串前小写字母 f 表示该字符串进行格式化输出

   ```
   name = "517"
   print(f"My name is {name}")
   ```

6. 转义字符

   | 转义字符 |  描述  |
   | :------: | :----: |
   |    \n    | 换行符 |
   |    \a    |  响铃  |

   要标示引号本身，我们需要对它进行“转义”，即在前面加一个 `\`

   如果不希望前置 `\` 的字符转义成特殊字符，可以使用 *原始字符串*，在引号前添加 `r` 即可：

   ```
   >>> print('C:\some\name')  # here \n means newline!
   C:\some
   ame
   >>> print(r'C:\some\name')  # note the r before the quote
   C:\some\name
   ```

   原始字符串还有一个微妙的限制：一个原始字符串不能以奇数个 `\` 字符结束

   字符串字面值可以包含多行。 一种实现方式是使用三重引号：`"""..."""` 或 `'''...'''`。 字符串中将自动包括行结束符，但也可以在换行的地方添加一个 `\` 来避免此情况。 参见示例：

   ```
   print("""\
   Usage: thingy [OPTIONS]
        -h                        Display this usage message
        -H hostname               Hostname to connect to
   """)
   ```



## 三、基础语法

1. 四则运算

   除法运算 (`/`) 总是返回浮点数。 如果要做 [floor division](https://docs.python.org/zh-cn/3/glossary.html#term-floor-division) 得到一个整数结果你可以使用 `//` 运算符；要计算余数你可以使用 `%`:

   ```
   >>> 17 / 3  # classic division returns a float
   5.666666666666667
   >>>
   >>> 17 // 3  # floor division discards the fractional part
   5
   ```

   Python 用 `**` 运算符计算乘方 [1](https://docs.python.org/zh-cn/3/tutorial/introduction.html#id3)：

   ```
   >>> 5 ** 2  # 5 squared
   25
   ```

2. `%`取模和`//`取整

   ```
   >>>print(5//2)
   2
   ```

3. 比较运算符

   ==等于   >大于   <小于   >=大于等于   <=小于等于  !=不等于

4. 逻辑运算符

   and(与)  or(或)  not(非)

5. 关键字

   如上 and、or、not、Ture、False不能作为变量名

6. if 判断语句

   ```
   Weight = 95
   canRide = Ture
   if Weight > 90: #与C不同，不需括号圈条件，后加冒号
       print("超过限制范围")
       canRide = False
   print(canRide)
   ```

7. ***缩进！***

   Python中不同层级的代码间强制要求缩进，并且相同层级的代码要求缩进的空格数量一致   

   同一层级的代码集合叫做代码块（自上而下运行）

8. 括号

   使用各种运算符时用括号强调优先级

   `result = (num1<num2) and (num2<num3)`



## 四、数据结构

​	1. 数据结构是计算机存储和组织数据的方式，可通过不同方式存放数据

 2. Python中使用最多有元组(tuple)、列表(list)、字典(dict)

    2.1. 元组：类似于传统结构中的顺序表，而元组只读而不能修改，元素类型可不同

    `calender = ("一月一日","一月二日","一月三日","一月四日")`

    2.2. 元组元素索引：从0开始，用于定位数据，可通过[ ... ]索引

    2.3. 元组元素查找：使用`in`运算符

    ```
    number = (0,1,2,3,4,5,6)
    result = 5 in number
    print(result)
    ```

    