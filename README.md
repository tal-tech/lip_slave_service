### 唇形驱动
1. 使用下面的命令安装环境
    apt-get install -y libglib2.0-dev
    apt-get install -y libboost-dev 
    apt-get install -y libboost-filesystem-dev 
    apt-get install -y libboost-system-dev 
    apt-get install -y libboost-log-dev
    apt-get install -y libcurl4-openssl-dev 
2. 将main.cpp中的`path_to_local_file.json`替换为要输入的文件
3. 在文件根目录下执行命令`cmake . -DCMAKE_BUILD_TYPE=Debug`
4. cmake生成makefile文件后执行make命令
5. 进入目录: bin/debug/ 下
6. 执行命令添加环境变量: `export LD_LIBRARY_PATH=../../det_lip/lip/libs/linux/gpu:$LD_LIBRARY_PATH`
7. 执行./demo 启动程序