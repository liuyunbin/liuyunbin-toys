
#### 简介：
本程序用于实现 Linux 命令行 shell

#### 项目流程：
1. 设置命令行前缀，并输出
2. 读取用户的输入，忽略所有的前置空格，并取代所有的 ~ 表示用户主目录的地方，包括 “\~”，“\~\/”
3. 如果用户输入为空，跳到第 1 步
4. 如果用户输入是内置命令：“cd” 或 “about”，在当前进程执行命令，而后，跳到第 1 步
5. 如果用户输入是内置命令：“exit” 或 “quit”，直接退出进程
6. 如果用户输入的是系统命令，fork 子进程，
    * 父进程 wait 子进程
    * 子进程使用管道（|）对用户输入的命令进行切割，获取当前命令，
        * 如果还有下一条命令，则建立管道，fork 子进程，
            * 子进程将标准输出重定向到管道，然后对当前命令进行解析，而后执行命令
            * 父进程将标准输入重定向到管道，然后 wait 子进程，而后读取下一条命令
        * 如果这是最后一条命令，对当前命令进行解析，而后执行命令，然后，跳到第 1 步

**说明：**
* 对命令进行解析是指：获取参数，并处理 “<” “>”  “>>”，将标准输入 或 输出重定向到文件
* 由于本项目是，先处理管道，后处理其它重定向，所以，当存在其它重定向时，管道将失效

#### 参考资源：
* [unix/linux 编程实践教程](https://book.douban.com/subject/1219329/)

