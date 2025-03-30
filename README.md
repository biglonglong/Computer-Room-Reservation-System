## Overview

这是一个简单的机房预约系统，支持学生、教师和管理员三种身份登录，程序根据用户身份提供相应的功能模块，包括菜单导航、登录验证、账号管理、机房信息管理以及预约管理等等。

- [Overview](#overview)
- [Requirements and Features](#requirements-and-features)
- [Directory Structure](#directory-structure)
- [Installation and Usage](#installation-and-usage)
  - [Prerequisites](#prerequisites)
  - [Steps](#steps)
  - [Run](#run)
- [Bug or Experience](#bug-or-experience)
- [References](#references)



## Requirements and Features

- （子）菜单界面与登录验证
- 具体功能
  - 管理员：添加账号、查看账号、查看机房、清空预约、注销登录；默认管理员`man`，密码是`1397`
  - 学生：申请预约、查看自身的预约、查看所有预约、取消预约、注销登录
  - 老师：查看所有预约、审核预约、注销登录



## Directory Structure

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



## Installation and Usage

### Prerequisites

- 安装 [CMake](https://cmake.org/download/)
- 安装 C++ 编译器（如 g++, clang++, MSVC 等）

### Steps

1. 打开终端或命令提示符，导航到项目根目录。

2. 创建一个构建目录并进入该目录：

   ```bash
   mkdir build
   cd build
   ```

3. 运行 CMake 配置项目：

   ```bash
   cmake ..
   ```

4. 构建项目：

   ```bash
   cmake --build .
   ```

### Run

构建完成后，可执行文件将生成在项目根目录下。运行程序：

```bash
./bin/Debug/ComputerRoomReservationSystem.exe
```



## Bug or Experience

当输入的内容类型与程序预期不一致（例如程序以`int`变量接收字母输入），会导致输入失败，这种错误的输入会残留在输入缓冲区中，影响后续的输入操作。为了解决这个问题，需要设计一个通用的输入处理函数，确保输入的内容符合预期，或者清理缓冲区的无效数据。

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



## References

- [黑马程序员匠心之作|C++教程从0到1入门编程,学习编程不再难_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1et411b73Z/?vd_source=1a278fe24f00dd5c69f2875b5add5a19)
