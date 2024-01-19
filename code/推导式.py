#列表推导式
a = [x*2 for x in range(5)]
print(a)
cells = [(row,col) for row,col in zip(range(1,10),range(101,110))]
print(cells)

#字典推导式
values = ["潮州","广州","上海"]
cities = {id:city for id,city in zip(range(1,4),values)}
print(cities)
#统计出现次数
test = ' i love you, i love studying, i love W'
char_count = {c:test.count(c) for c in test}
print(char_count)

#生成器推导式
g = (x for x in range(1,100) if x%9==0)
for x in g:
    print(x,end=',')
for x in g:
    print(x,end=' ') #只能用一次，该循环不执行