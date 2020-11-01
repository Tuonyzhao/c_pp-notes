#### 权限管理命令

改变文件的所有者：

```shell
$chown [用户][文件或目录]
$chown tuony linux.md
```

改变文件或目录的所属组：

```shell
$chgrp [用户组][文件或目录]
$chgrp tuony linux.md
```

谁创建了一个文件，谁就是这个文件的所有者。

touch  [文件]

umask -S 可以显示新建文件的缺省权限

![image-20201028204936181](/home/tuony/.config/Typora/typora-user-images/image-20201028204936181.png)

touch的文件被系统默认拿掉可执行权限，mkdir创建的目录和umask -S看到的缺省权限一样。

![image-20201028210108566](/home/tuony/.config/Typora/typora-user-images/image-20201028210108566.png)

![image-20201028210123707](/home/tuony/.config/Typora/typora-user-images/image-20201028210123707.png)

删除一个文件的前提条件是当前所在的目录有写的权限

#### 文件搜索命令find

命令名称：find

命令所在路径：/bin/find

执行权限:所有用户

语法：find[搜索范围] [匹配条件]

功能描述:文件搜索

例如：find /home/tuony/ -name *c++ *      (模糊的查找)

find /home/tuony/ -name c++ (精确的查找)

find /home/tuony/ -name c++？？？（问号匹配单个字符）

-name (文件名)  -iname(不管是大写字母还是小写字母)

find / -size +204800(查找大于100MB的文件)

find / -size -204800(查找小于100MB的文件)

find / -size 204800(查找等于100MB的文件)

-user(根据所有者来查找) 

find / -cmin -5(在5分钟之内文件属性被改变过的目录和文件)

find / -amin -5(在5分钟之内被访问过的文件和目录)

find / -mmin -5(在5分钟之内文件内容被改变过的 目录和文件)

多个条件可通过-a 或 -o来链接如:

find / -size +204800 -a -size -409600

find /-type f/d/l(文件/目录/软链接文件)

-a 表示两个同时满足，-o表示满足一个即可

可在find后查找的结果加-exec +linux 命令来对find 找到的结果做一个处理如：find /home/tuony/ -size +102400 -exec ls -l

-inum 表示根据节点查找

#### 文件搜索命令：locate

命令名称：locate

命令所在路径:/usr/bin/locate

执行权限：所有用户

语法：locate 文件名

功能描述：在文件资料中查找文件

范例：$locate vector.cpp(类似于window里面的everything搜索工具，基本上都是秒搜)

问：为什么lcaote查找速度块？

答：在/var/lib/mlocate/下存在一个db文件：mlocate.db ，linux下的所有文件都会被**定期**收录在这个资料库中。但是，如果刚刚创建一个文件的话，可能没被收录到mlocate.db这个资料库中，通过lcoate直接找是找不到的，可通过updatedb更新这个资料库。

locate -i [文件名] (-i不区分大小写)

#### 文件搜索命令: which

语法:which 命令

功能：搜索命令所在目录及别名信息

#### 文件搜索命令：whereis 

命令名称：whereis 

命令所在路径：/ usr/bin/whereis

执行权限：所有用户

语法：whereis [命令名称]

功能描述：搜索命令所在目录及帮助文档路径

范例：$whereis ls

#### 文件搜索命令：grep

命令名称：grep

命令所在路径：/bin/grep

执行权限：所有用户

语法：grep -iv [指令字串] [文件]

功能描述：在文件中搜寻字串匹配的行并输出

​					-i 不去分大小写

​					-v 排除制定字串

范例： grep mysql /root/install.log

#### 帮助命令man

命令名称：man

命令英文原意：manual

命令所在路径：/usr/bin/man

执行权限：所有用户

语法： man [命令或配置文件]

功能描述：获得帮助信息

范例：$man ls

​				查看ls命令的帮助信息

​				$man services

​				查看配置文件services的帮助信息

#### apropos

apropos可以查看配置文件的信息

apropos [配置文件]

#### 帮助命令：help

命令名称：help

命令所在路径：shell内置命令

执行权限：所有用户

语法：help命令

功能描述：获得Shell内置命令的帮助信息

范例：$help umask

​				查看umask 名来那个的帮助信息

 内置命令必须用help来查看，可以用man来知道哪些命令是不是内置命令。其它的查看方法找不到内置命令的使用方式。

#### whatis [命令]

可以简单的知道该命令干什么的。

#### 用户管理命令：useradd

命令名称：useradd

命令所在路径：/usr/sbin/useradd

执行权限:root

语法:useradd 用户名

功能描述：添加新用户

范例：$useradd yangmi 

密码用passwd来更改。root可以更改任何用户的密码，普通用户可以自己的密码。

who 查看当前用户信息（即当前登录到该主机有哪些用户）

#### 用户管理命令：w

命令名称：w

命令所在路径：/usr/bin/w

执行权限:所有用户

语法:w

功能描述：查看登录用户详细信息

范例：$w

#### 压缩解压命令：gzip

命令名称：gzip

命令英文原意：GUN zip

命令所在路径：/bin/gzip

执行权限：所有用户

语法：gzip [文件]

功能描述：压缩文件

压缩后文件格式：.gz

gzip 压缩只能压缩文件，不能压缩目录

gzip压缩后源文件就没有了

#### 压缩解压命令：gunzip(gzip -d)(压缩)

命令名称：gunzip

命令英文原意：GUN unzip

命令所在路径：/bin;gunzip

执行权限：所有用户

语法：gunzip[严肃哦文件]

功能描述：解压缩.gz的压缩文件

范例：$gunzip boduo .gz

#### 压缩解压命令：tar(打包)

命令名称：tar

命令所在路径：/bin/tar

执行权限：所有用户

语法：tar 选项[-zcf] [压缩后文件名] [目录]

​				-c 打包

​				-v 显示详细信息

​				-f  指定文件名

​				-z 打包同时压缩

功能描述：打包目录

压缩后文件格式：.tar.gz 

一般是先打包再压缩，也可以加-z直接打包压缩（即 打包的同时也压缩）

tar命令解压缩语法：

 					-x 解包

​						-v 显示详细信息

​						-f 指定压缩文件

​						-z 解压缩

范例: tar -zxvf    heloo.tar.gz

#### 压缩解压命令：zip

命令名称;zip

命令所在路径:/usr/bin/zip

执行权限：所有用户

语法：

​		zip 选项[-r] [压缩后文件名] [文件或目录]  -r 压缩目录

功能描述：压缩文件或目录

压缩后文件格式：.zip

#### 压缩解压命令：unzip

命令名称：unzip

命令所在路径：/usr/bin/unzip

执行权限;所有用户

语法：unzip [压缩文件]

功能描述：解压.zip的压缩文件

范例：unzip test.zip

#### 压缩解压命令：bzip2(.gz的升级版)

命令名称：bzip2

命令所在路径：/usr/bin/bzip2

执行权限：所有用户

语法：bzip2 选项 [-k] [文件] -k 产生压缩文件后保留原文件

功能描述：压缩文件

压缩后文件格式：.bz2

范例：$bzip -k boduo

​		$tar -cjf japan.tar.bz2 japan（把 -z 换成了-j）

![image-20201029181114634](/home/tuony/.config/Typora/typora-user-images/image-20201029181114634.png)

#### 网络命令：write

 指令名称：write

指令所在路径：/usr/bin/write

执行权限：所有用户

语法：write<用户名>

功能描述：给用户发信息，以ctrl+d保存结束

范例：#write linzhiling 

#### 网络命令：wall

![image-20201029182653910](/home/tuony/.config/Typora/typora-user-images/image-20201029182653910.png)

#### 网络命令：ifconfig

![image-20201029183434348](/home/tuony/.config/Typora/typora-user-images/image-20201029183434348.png)

#### 网络命令：mail

![image-20201029183823538](/home/tuony/.config/Typora/typora-user-images/image-20201029183823538.png)

#### 网络命令：last

命令名称：last

命令所在的路径：/usr/bin/last

执行权限：所有用户

语法：last

功能描述：列出目前与过去登入系统的用户信息

范例：#last

#### 网络命令：lastlog

命令名称：lastlog

命令所在路径：/usr/bin/lastlog

执行权限:所有用户

语法:lastlog

功能描述:检查某特定用户上次登录的时间

范例：#lastlog

​			  #last -u 502(用户的uid)

#### 网络命令：traceroute

命令名称：traceroute

命令所在路径：/bin/traceroute

执行权限：所有用户

语法：traceroute

功能描述：显示数据包到主机间的路径

范例：#traceroute www.lampbrother.net

#### 网络命令：netstat

命令名称：netstat

命令所在路径:/bin/netstat

执行权限：所有用户

语法：netstat [选项

功能描述：显示网络相关信息

选项：

​		-t 	:TCP协议

​		-u 	:UDP协议

​		-l 	:监听

​		-r	 :路由

​		-n	:显示ip地址和端口号

范例：

#netstat -tlun		查看本机监听的端口

#netstat -an			查看本机所有的网络连接

#netstat -rn			查看本机路由表 

#### 网络命令：setup

命令名称：setup(redhat开发的一个网络管理工具集合)

命令所在路径：/usr/bin/setup

执行权限：root

语法：setup

功能描述：配置网络

范例：#setup

#### 挂载命令

命令名称：mount

命令位置：/bin/mount

执行权限：所有用户

命令语法：mount [-t 文件系统] 设备文件名 挂载点

范例:#mount -t iso9660 /dev/sr0/mnt/cdrom

(把一个设备文件分配一个盘符(目录)就叫一个挂载过程)