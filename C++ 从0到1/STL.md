# C++ STL

标准数据结构和算法，**容器**和**算法**之间通过**迭代器**进行无缝连接，还有**仿函数**、**适配器**和**空间配置器**。



## 常用容器

### string

char *类，不用担心复制越界和取值越界

#### 构造

* `string();`          					//创建一个空的字符串 例如: string str;
* `string(const char* s);`	              //使用字符串s初始化
* `string(const string& str);`              //使用一个string对象初始化另一个string对象
* `string(int n, char c);`                      //使用n个字符c初始化 

#### 赋值

* `string& operator=(const char* s);`             //char*类型字符串 赋值给当前的字符串
* `string& operator=(const string &s);`         //把字符串s赋给当前的字符串
* `string& operator=(char c);`                          //字符赋值给当前的字符串
* `string& assign(const char *s);`                  //把字符串s赋给当前的字符串
* `string& assign(const char *s, int n);`     //把字符串s的前n个字符赋给当前的字符串
* `string& assign(const string &s);`              //把字符串s赋给当前字符串
* `string& assign(int n, char c);`                  //用n个字符c赋给当前字符串

#### 存取

* `char& operator[](int n); `     //通过[]方式取字符
* `char& at(int n);   `                    //通过at方法获取字符

#### 拼接

* `string& operator+=(const char* str);`                   //重载+=操作符
* `string& operator+=(const string& str);`                //重载+=操作符
* `string& operator+=(const char c);`                         //重载+=操作符
* `string& append(const char *s); `                               //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`                           //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾

#### 插入

* `string& insert(int pos, const char* s);  `                //插入字符串
* `string& insert(int pos, const string& str); `        //插入字符串
* `string& insert(int pos, int n, char c);`                //在指定位置插入n个字符c

#### 删除

- `string& erase(int pos, int n = npos);`                    //删除从Pos开始的n个字符 

#### 查找

> 找到字符串后返回查找的第一个字符位置，找不到返回-1

* `int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
* `int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
* `int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找
* `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
* `int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
* `int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
* `int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找
* `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置

#### 替换

* `string& replace(int pos, int n,const char* s); `                 //替换从pos开始的n个字符为字符串s
* `string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str

#### 比较

> 字典序比较，相等返回0，大于返回1，小于返回-1
>

* `int compare(const char *s) const;`      //与字符串s比较
* `int compare(const string &s) const; `  //与字符串s比较

#### 子串

- `string substr(int pos = 0, int n = npos) const;`   //返回由pos开始的n个字符组成的字符串

### vector

单端数组类，动态扩展（找更大的内存空间，然后将原数据拷贝新空间，释放原空间）

#### 构造

* `vector<T> v; `               		     //采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end());   `       //将v[begin(), end())区间中的元素拷贝给本身。
* `vector(const vector &vec);`         //拷贝构造函数。
* `vector(n, elem);`                            //构造函数将n个elem拷贝给本身。

#### 赋值

* `vector& operator=(const vector &vec);`//重载等号操作符


* `assign(beg, end);`       //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`        //将n个elem拷贝赋值给本身。

#### 存取

- `at(int idx); `     //返回索引idx所指的数据
- `operator[]; `       //返回索引idx所指的数据
- `front(); `            //返回容器中第一个数据元素
- `back();`              //返回容器中最后一个数据元素

#### 插入

- `push_back(ele);`                                         //尾部插入元素ele
- `insert(const_iterator pos, ele);`        //迭代器指向位置pos插入元素ele
- `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count个元素ele

#### 删除

- `pop_back();`                                                //删除最后一个元素
- `erase(const_iterator pos);`                     //删除迭代器指向的元素
- `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
- `clear();`                                                        //删除容器中所有元素

#### 大小

* `empty(); `                            //判断容器是否为空

* `capacity();`                      //容器的容量

* `size();`                              //返回容器中元素的个数

* `resize(int num);`             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

* `resize(int num, elem);`  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

#### 预留

- `reserve(int len);`		//容器预留len个元素长度，预留位置不初始化，元素不可访问

#### 交换

- `swap(vec);`  				// 将vec与本身的元素互换，可以达到实用的收缩内存效果

### deque

双端数组类，中控器维护多段缓冲区地址

#### 构造

* `deque<T>;`                       //默认构造形式
* `deque(beg, end);`                  //构造函数将[beg, end)区间中的元素拷贝给本身。
* `deque(n, elem);`                    //构造函数将n个elem拷贝给本身。
* `deque(const deque &deq);`   //拷贝构造函数

#### 赋值

* `deque& operator=(const deque &deq); `         //重载等号操作符


* `assign(beg, end);`                                           //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`                                             //将n个elem拷贝赋值给本身。

#### 存取

- `at(int idx); `     //返回索引idx所指的数据
- `operator[]; `      //返回索引idx所指的数据
- `front(); `            //返回容器中第一个数据元素
- `back();`              //返回容器中最后一个数据元素

#### 插入

- `push_back(elem);`          //在容器尾部添加一个数据
- `push_front(elem);`        //在容器头部插入一个数据
- `insert(pos,elem);`         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
- `insert(pos,n,elem);`     //在pos位置插入n个elem数据，无返回值。

- `insert(pos,beg,end);`    //在pos位置插入[beg,end)区间的数据，无返回值。

#### 删除

- `pop_back();`                   //删除容器最后一个数据
- `pop_front();`                 //删除容器第一个数据
- `erase(beg,end);`             //删除[beg,end)区间的数据，返回下一个数据的位置。
- `erase(pos);`                    //删除pos位置的数据，返回下一个数据的位置。
- `clear();`                           //清空容器的所有数据

#### 大小

- **函数原型：**
  * `deque.empty();`                       //判断容器是否为空

  * `deque.size();`                         //返回容器中元素的个数

  * `deque.resize(num);`                //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。

  * `deque.resize(num, elem);`     //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。


#### stack

栈类，先进后出

#### 构造

* `stack<T> stk;`                                 //stack采用模板类实现， stack对象的默认构造形式
* `stack(const stack &stk);`            //拷贝构造函数

#### 赋值

- `stack& operator=(const stack &stk);`           //重载等号操作符

#### 存取

- `push(elem);`      //向栈顶添加元素
- `pop();`                //从栈顶移除第一个元素
- `top(); `                //返回栈顶元素

#### 大小

* `empty();`            //判断堆栈是否为空
* `size(); `              //返回栈的大小

### queue

队列类，先进先出

#### 构造

- `queue<T> que;`                                 //queue采用模板类实现，queue对象的默认构造形式
- `queue(const queue &que);`            //拷贝构造函数

#### 赋值

- `queue& operator=(const queue &que);`           //重载等号操作符

#### 存取

- `push(elem);`                             //往队尾添加元素
- `pop();`                                      //从队头移除第一个元素
- `back();`                                    //返回最后一个元素
- `front(); `                                  //返回第一个元素

#### 大小

- `empty();`            //判断堆栈是否为空
- `size(); `              //返回栈的大小

### list

链表类，双向循环，方便插入和删除

#### 构造

* `list<T> lst;`                               //list采用采用模板类实现,对象的默认构造形式：
* `list(const list &lst);`            //拷贝构造函数。
* `list(beg,end);`                           //构造函数将[beg, end)区间中的元素拷贝给本身。
* `list(n,elem);`                             //构造函数将n个elem拷贝给本身。

#### 赋值

* `assign(beg, end);`            //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`              //将n个elem拷贝赋值给本身。
* `list& operator=(const list &lst);`         //重载等号操作符

#### 存取

- `front();`        //返回第一个元素。
- `back();`         //返回最后一个元素。

#### 插入

- `push_back(elem);`//在容器尾部加入一个元素
- `push_front(elem);`//在容器开头插入一个元素
- `insert(pos,elem);`//在pos位置插elem元素的拷贝，返回新数据的位置。
- `insert(pos,n,elem);`//在pos位置插入n个elem数据，无返回值。
- `insert(pos,beg,end);`//在pos位置插入[beg,end)区间的数据，无返回值。

#### 删除

- `pop_back();`//删除容器中最后一个元素
- `pop_front();`//从容器开头移除第一个元素
- `erase(beg,end);`//删除[beg,end)区间的数据，返回下一个数据的位置。
- `erase(pos);`//删除pos位置的数据，返回下一个数据的位置。
- `remove(elem);`//删除容器中所有与elem值匹配的元素。
- `clear();`//移除容器的所有数据

#### 大小

* `size(); `                             //返回容器中元素的个数

* `empty(); `                           //判断容器是否为空

* `resize(num);`                   //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

* `resize(num, elem); `       //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。


#### 排序

* `reverse();`   //反转链表
* `sort();`        //链表排序

#### 交换

- `swap(lst);`                         //将lst与本身的元素互换。

### set/multiset

集合类，二叉树实现

#### 构造

- `set<T> st;`                        //默认构造函数：
- `set(const set &st);`       //拷贝构造函数
- `set<T,MyCompare> s;`    //指定排序规则

#### 赋值

- `set& operator=(const set &st);`    //重载等号操作符

#### 插入

- `insert(elem);`           //在容器中插入元素。

#### 大小

* `size();`          //返回容器中元素的数目
* `empty();`        //判断容器是否为空

#### 删除

* `clear();`                    //清除所有元素
* `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
* `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
* `erase(elem);`            //删除容器中值为elem的元素。

#### 交换

- `swap(st);`      //交换两个集合容器

#### 查找

- `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- `count(key);`                //统计key的元素个数

### pair

组类，成对出现的数据

* `pair<type, type> p ( value1, value2 );`
* `pair<type, type> p = make_pair( value1, value2 );`

### map/multimap

字典类，pair集合，二叉树实现，根据元素的键值自动排序

#### 构造

* `map<T1, T2> mp;`                     //map默认构造函数: 
* `map(const map &mp);`             //拷贝构造函数
* `map<T,T,MyCompare> m;`    //指定排序规则

#### 赋值

- `map& operator=(const map &mp);`    //重载等号操作符

#### 插入

- `insert(elem);`           //在容器中插入元素。

#### 删除

- `clear();`                    //清除所有元素
- `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
- `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
- `erase(key);`            //删除容器中值为key的元素。

#### 大小

- `size();`          //返回容器中元素的数目
- `empty();`        //判断容器是否为空

#### 交换

- `swap(st);`      //交换两个集合容器

#### 查找

- `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- `count(key);`                //统计key的元素个数



## 函数对象(仿函数)

重载**函数调用操作符**的类，可调用，有参数，有返回值，有状态，**可作为参数传递**

```cpp
class MyAdd
{
public :
    MyAdd() {
        this->count=0;
    }
	int operator()(int v1,int v2) {
        this->count++;
		return v1 + v2;
	}
    int count;
};
MyAdd myAdd;
myAdd(10, 10);
// myAdd.count
```

### 算术

* `template<class T> T plus<T>`                //加法仿函数
* `template<class T> T minus<T>`              //减法仿函数
* `template<class T> T multiplies<T>`    //乘法仿函数
* `template<class T> T divides<T>`         //除法仿函数
* `template<class T> T modulus<T>`         //取模仿函数
* `template<class T> T negate<T>`           //一元，取反仿函数

### 关系

* `template<class T> bool equal_to<T>`                    //等于
* `template<class T> bool not_equal_to<T>`            //不等于
* `template<class T> bool greater<T>`                      //大于
* `template<class T> bool greater_equal<T>`          //大于等于
* `template<class T> bool less<T>`                           //小于
* `template<class T> bool less_equal<T>`               //小于等于

### 逻辑

- `template<class T> bool logical_and<T>`              //逻辑与
- `template<class T> bool logical_or<T>`                //逻辑或
- `template<class T> bool logical_not<T>`              //逻辑非



## 常用算法

### 遍历

- ``for_each(iterator beg, iterator end, _func);  ``     //遍历容器
- `transform(iterator beg1, iterator end1, iterator beg2, _func);`   //搬运容器到另一个容器中

### 查找

- `find(iterator beg, iterator end, value);`                     //查找元素
- `find_if(iterator beg, iterator end, _Pred);`               //按条件查找元素
- `adjacent_find(iterator beg, iterator end);`    //查找相邻重复元素
- `bool binary_search(iterator beg, iterator end, value);`   //二分查找法
- `count(iterator beg, iterator end, value);`                   //统计元素个数
- `count_if(iterator beg, iterator end, _Pred);`             //按条件统计元素个数

### 排序

- `sort(iterator beg, iterator end, _Pred);`            //对容器内元素进行排序
- `random_shuffle(iterator beg, iterator end);`   //洗牌   指定范围内的元素随机调整次序
- `merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`          // 容器元素合并，并存储到另一容器中
- `reverse(iterator beg, iterator end);`       // 反转指定范围的元素

### 拷贝

- `copy(iterator beg, iterator end, iterator dest);`                      // 容器内指定范围的元素拷贝到另一容器中

### 替换

- ``replace(iterator beg, iterator end, oldvalue, newvalue);`                // 将容器内指定范围的旧元素修改为新元素
- `replace_if(iterator beg, iterator end, _pred, newvalue);`         // 容器内指定范围满足条件的元素替换为新元素

### 交换

- `swap(container c1, container c2);`              // 互换两个容器的元素

### 算术

- `accumulate(iterator beg, iterator end, value);`      // 计算容器元素累计总和

- `fill(iterator beg, iterator end, value);`                 // 向容器中添加元素

### 集合

- `set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`          // 求两个容器的交集

- `set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`                       // 求两个容器的并集

- `set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);`              // 求两个容器的差集
