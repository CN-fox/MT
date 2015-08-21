# MT
一个在Android系统开发时写的一个工具
在成都中科创达时，写来方便开发的一个工具

##功能
功能 | 预览图
----- | ----
[加注释](#)| [效果图](#image3)
[tcpdump](#)|[效果图](#image2)
[make](#)|[效果图](#image1)
[auto install](#)|[效果图](#image1)


##实现简介
###加注释
通过配置好的参数，在下面生成注释,做过Android系统开发的童鞋应该都知道
实现也比较简单，就是字符串拼接裁剪

###tcpdump
这是我在解决一个bug是遇到的,因为当时没有用过，所以去查了资料，还有同事也有类似的需求
所以写了这样一个功能，实现是在程序中执行command语句 adb shell tcpdump -i any -p -s 0 -w sdcard/log.pacp
因为是整机开发，而且是开发阶段所以有tcpdump否则。。。
然后把log.pacp pull到本地 导入wireshark 进行bug 校验或者错误查找就是了

### make
这是一个想要实现的功能，最终没能实现全局的make，只是实现了单个模块的make
也就是在初始化了编译环境后，会先去删除已有编译缓存文件 再cd 到对应模块目录
调用mm / mmm 具体调用的哪个忘记了


### auto install
是make后的后续操作,通常make后结果会分为几种 jar|apk|resapk|...
在执行make时回去read Android.mk 文件分析 make 后生成的产物类型根据不同类型做不同处理
apk/resapk 进行 push  am install
jar push到指定位置 并重启手机


## 运行效果预览

###image1
<span id="image1"/>
![image](https://raw.githubusercontent.com/CN-fox/MT/master/images/04D4E255-EEC2-4F9E-A1DA-05A7A3DB3936.png)

###image2
<span id="image2"/>
![image](https://raw.githubusercontent.com/CN-fox/MT/master/images/6B91AB70-B8FB-459A-84E5-39171A22C3B8.png)

###image3
<span id="image3"/>
![image](https://raw.githubusercontent.com/CN-fox/MT/master/images/D0B344E1-B876-4CA7-A8B8-CD040FF582AC.png)