# Python之入门笔记

<!--Ctrl+s--->养成保存好习惯

## 海龟绘图

1. 导入海龟`import turtle`

2. 显示箭头`turtle.showturtle()`

3. 打印内容`turtle.write("hello world!")`

4. 前行300个像素`turtle.forward(300)`

5. 设置画笔颜色`turtle.color("red")`

6. 箭头方向左转90度`turtle.left(90)`

7. 到指定坐标`turtle.goto(0,0)`

8. 抬笔不显示路径`turtle.penup()`

9. 放笔`turtle.pendown`

10. 画指定形状半径为100的圆`turtle.circle(100)`

11. 保持窗口不关闭`turtle.down()`

    

## 引用_堆栈内存

1. 对象由<u>标识identify、类型type、值value</u>组成

2. 变量没有类型，对象有类型

3. 变量引用对象，变量位于栈内存~依次存放~，对象位于堆内存~随机存放~

   

## 函数

1. 函数指封装了某一特定功能的代码块

```
def sayWelcome():
	print("欢迎光临")
	print("517的Python笔记小铺")
```

1）`del a[2]`删除列表指定位置的元素

2）`round(value)`四舍五入，不修改value

3）`str.split('x')`将字符串分割成子字符串，不指定分隔符时默认以空白分隔

4）`'连接符'.join(a)`将子字符串连接起来

5）`range(StartNum，EndNum必填，step)`帮助创建整数列表，左闭右开

6）`a.index(value,[start,[end]])`获取元素首次出现的索引

7）`a.sort()`对列表进行排序，默认升序/填入reverse=Ture变降序 

8）`b=sorted(a.reverse=Ture)`新建列表的排序，原列表不改变

9）`max(a)`/`min(a)`/`sum(a)`返回列表最大/最小值，对数值列表进行求和

**10）`map(function,iterable)`根据指定函数对指定序列做映射**

**11）`lambda x,y:函数体`创造匿名函数，简化函数定义的书写形式**

**12）`filter(function,iterable)`过滤可迭代对象中不符合条件的元素**



2. 形参与实参

```
def sayWelcome(discount):
	print(f"商品一律{discount}")
sayWelcome("九折")
```



## 运算符

###同一运算符

1. `is`和`is not`判断两个变量是否引用同一***对象***，即比较对象的地址 

2. `==`判断引用变量引用对象的***值*** 是否相等

### 成员运算符

1. `in`和`not in`在制定序列中是否找到值返回True，否则返回False



## 推导式

1. 列表推导式：`a = [x for x in range(1，10) if x%2==0]`
2. 字典推导式：`d = {key:value for key,value in (range(1,5),valueList)}`
3. 集合推导式：`a = {x for x in range(1，10) if x%2==0}`与列表相似，使用花括号
4. 生成器推导式：`a = (x for x in range(10))`生成的是一个生成器对象只能访问一次，可转为元组或列表，使用` __next__()`遍历



## 循环

1. for循环：`for`与`in`组合使用

   ```
   numberList = [10,20,30,40,50]
   for number in numberList:
   	print(number)
   ```

   1. 1.遍历：访问数据结构中的所有元素

   1）遍历字典：`for product in productDict`

   2）遍历字典所有键：`for product in productDict.keys()`

   3）遍历字典的值

   ```
   for product in productDict:
   	value = productDict[product]
   ```

   1. 2.累加

   ```
   for price in List:
   	total += price
   ```

   1. 3.计数器

   ```
   count = 0
   for name in names:
   	count += 1
   	print(f"第{count}名是{name}")
   ```

   1. 4.条件判断（注意缩进）

   ```
   for number in numberList:
   	if number > 10:
   		print(nummber)
   ```

2. while循环：条件判断为真时执行

```
count = 0
while count<5:
	print(numberList[count])
	count += 1
```

3. break跳出循环
4. continue跳过本次循环并继续执行循环