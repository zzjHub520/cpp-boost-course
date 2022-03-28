https://blog.csdn.net/m0_47696151/article/details/110133728



在Windows上安装 boost 和 GCC (MinGW)

lylhw13_

于 2020-11-25 18:58:57 发布

677
 收藏 3
分类专栏： boost windows 文章标签： windows c++ boost
版权

boost
2 篇文章0 订阅
订阅专栏

windows
7 篇文章0 订阅
订阅专栏
安装 Mingw
下载并安装 Mingw-w64。
安装过程中选择 Architecture select x86_64，其余默认。
添加 Mingw-w64 的 bin 目录至 环境变量 PATH 中。
如果采用默认路径的话，路径地址为 C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin。
检测安装是否成功
g++ --version
1
如果成功安装，则会输出相应的版本信息。
安装boost
下载并解压出 boost_1_74_0, 解压目录为 D:\boost_1_74_0

编译 Boost.Build

创建 Boost.Build 的安装目录 D:\boost-build，为编译 boost 做准备
打开命令行，并切换到目录 D:\boost_1_74_0\tools\build
运行
bootstrap.bat gcc
1
运行
b2 install --prefix="D:\boost-build"
1
运行结束，将D:\boost-build\bin 添加的 Windows 的环境变量 PATH 中。
编译 boost

创建 boost 的安装目录 D:\boost
创建 boost 的build目录 D:\boost_1_74_0\build
打开命令行，并切换至目录 D:\boost_1_74_0
运行
b2 --build-dir="D:\boost_1_74_0\build" --prefix="D:\boost" toolset=gcc install
1
使用 g++ 搭配 boost库 编译程序
g++ -std=c++11 helloworld.cpp -o helloworld -I D:/boost/include/boost-1_74 -L D:/boost/lib -lws2_32 -lwsock32
1
注意，如果不添加 -lws2_32 或 -lwsock32，会出现如下错误；

undefined reference to `__imp_WSASend’

参考：

Using GCC with MinGW
Installing boost libraries for GCC (MinGW) on Windows
————————————————
版权声明：本文为CSDN博主「lylhw13_」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/m0_47696151/article/details/110133728