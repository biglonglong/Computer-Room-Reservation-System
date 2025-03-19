# C++ 从 0 到 1

- [基础语法](.\C++ 从0到1\基础语法.md)
- [面向对象](.\C++ 从0到1\面向对象.md)
- [泛型编程](.\C++ 从0到1\泛型编程.md)
- [STL](.\C++ 从0到1\STL.md)



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