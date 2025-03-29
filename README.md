
# Computer Room Reservation System

## 项目简介

这是一个简单的计算机房预约系统，用户可以选择不同的身份（学生、教师、管理员）进行操作。程序会根据用户的选择提供相应的功能。

## 功能

> 管理员：man  密码：1397

- 学生：学生可以预约计算机房。
- 教师：教师可以确认预约情况。
- 管理员：管理员可以管理各种预约信息。



## 目录结构

```txt
│   .gitignore
│   CMakeLists.txt
│   README.md
│
├───data
│       admin.txt
│       computerRoom.txt
│       order.txt
│       orderBak.txt
│       student.txt
│       teacher.txt
│
├───include
│       ComputerRoom.h
│       globalFile.h
│       Identity.h
│       Manager.h
│       Order.h
│       Student.h
│       Teacher.h
│
└───src
        ComputerRoomReservationSystem.cpp
        Manager.cpp
        Order.cpp
        Student.cpp
        Teacher.cpp
```



## 构建和运行

### 先决条件

- 安装 [CMake](https://cmake.org/download/)
- 安装 C++ 编译器（如 g++, clang++, MSVC 等）

### 构建步骤

1. 打开终端或命令提示符，导航到项目根目录。

2. 创建一个构建目录并进入该目录：

    ```sh
    mkdir build
    cd build
    ```

3. 运行 CMake 配置项目：

    ```sh
    cmake ..
    ```

4. 构建项目：

    ```sh
    cmake --build .
    ```

### 运行程序

构建完成后，可执行文件将生成在项目根目录下。运行程序：

```sh
./bin/Debug/ComputerRoomReservationSystem.exe
```



## Bug/Experience

Q：当输入的内容类型与程序预期不一致（例如程序以`int`变量接收字母输入），会导致输入失败，这种错误的输入会残留在输入缓冲区中，影响后续的输入操作。

A：为了解决这个问题，需要设计一个通用的输入处理函数，确保输入的内容符合预期，或者清理缓冲区的无效数据。可以通过函数、重载`>>`运算符实现。

```cpp
// 通用输入处理函数
int getValidatedInput() {
    int input;
    while (true) {
        cout << "Please enter your choice: ";
        if (cin >> input) {
            // 输入成功，返回结果
            return input;
        } else {
            // 输入失败，清理缓冲区并提示用户
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
        }
    }
}
```

```cpp
// 定义一个通用的输入类
class InputHandler {
public:
    int value; // 存储用户输入的值

    // 重载输入运算符
    friend istream& operator>>(istream& in, InputHandler& input) {
        while (true) {
            if (in >> input.value) {
                // 输入成功，返回输入流
                return in;
            } else {
                // 输入失败，清理缓冲区并提示用户
                cout << "Invalid input. Please enter a valid number: ";
                in.clear(); // 清除错误状态
                in.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
            }
        }
    }
};
```

------

