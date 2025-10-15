# OOP and GP
OOP 面向对象编程：想要将datas 和 mathods 放在一起，使用大量的继承关系和虚函数，使用比较复杂

GP 泛型编程：想要将datas 和methods 分开来

这两种设计理念均有各自的适用场景

# 采用GP的好处：

Containers和Algorithms团队可各自闭门造车，其间以Iterator沟通即可
Algorithms通过Iterators确定操作范围，并通过Iterators取用Container元素

![GP示例](https://github.com/Deancook1/SGI-STL/blob/master/STL/Notes/images/GP.PNG)

# 为什么list 不能使用全局的sort？
因为sort 源码中,sort 是一个函数，要求传入的容器中的迭代器支持随机访问，但是list 提供的迭代器不支持，所以不支持
```C++
 *(first + (last - first)/2)
// 此迭代器只能是随机访问迭代器
// list因为自身特性，其迭代器不支持随机访问

```