import self
class Student:
    name = None
    gender = None
    age = None
    city =  None
    # 定义方法
    def hi(self):
        print(f"Hello!{self.name}")
# 创建对象
stu_1 = Student()
# 赋值对象属性
stu_1.name = "辜艺淇"
stu_1.gender = "女"
stu_1.age = 19
stu_1.city = "潮州"
# 输出
print(f"姓名：{stu_1.name}")
print(f"性别：{stu_1.gender}")
print(f"年龄：{stu_1.age}")
print(f"城市：{stu_1.city}")
stu_1.hi()
