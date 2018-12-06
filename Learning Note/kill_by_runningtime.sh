find /usr/local/minivdir/pics/ -mmin 10 # 查询10分钟前改变的内容
-mmin n

              File's data was last modified n minutes ago.

-mtime n

              File's data was last modified n*24 hours ago.

find /home/  -mtime 1  #查询1天前改变的内容
find /home/  -mmin 1    #查询1分钟前改变的内容
当然，也可以用与或非操作。

（-a）（-o）（！）

find /home/  -mtime 1 -o -mmin 1

#!/bin/bash

p_name=ffmpeg

list="$(ps -A | grep $p_name|sort -k3,3|awk '{print $1}')"

for pid in $list
do
  time="$(ps -eo pid,etime |grep $pid|awk '{print $2}'|./script.awk)"
  if [[ $time -ge '10800' ]];then
    echo $pid $time
    kill -9 $pid
  fi
done


#!/usr/bin/awk -f  

BEGIN { FS = ":" }

{

  if (NF == 2) {

    print $1*60 + $2

  } else if (NF == 3) {

    split($1, a, "-");

    if (a[2] != "" ) {

      print ((a[1]*24+a[2])*60 + $2) * 60 + $3;

    } else {

      print ($1*60 + $2) * 60 + $3;

    }

  }

}

1.判断变量

复制代码 代码如下:

read -p "input a word :" word
if  [ ! -n "$word" ] ;then
    echo "you have not input a word!"
else
    echo "the word you input is $word"
fi
2.判断输入参数

复制代码 代码如下:

#!/bin/bash
if [ ! -n "$1" ] ;then
    echo "you have not input a word!"
else
    echo "the word you input is $1"
fi
以下未验证。

3. 直接通过变量判断

如下所示:得到的结果为: IS NULL
复制代码 代码如下:

#!/bin/sh
para1=
if [ ! $para1 ]; then
  echo "IS NULL"
else
  echo "NOT NULL"
fi 
4. 使用test判断

得到的结果就是: dmin is not set! 
复制代码 代码如下:

#!/bin/sh
dmin=
if test -z "$dmin"
then
  echo "dmin is not set!"
else  
  echo "dmin is set !"
fi
5. 使用""判断

复制代码 代码如下:

#!/bin/sh 
dmin=
if [ "$dmin" = "" ]
then
  echo "dmin is not set!"
else  
  echo "dmin is set !"
fi
下面是我在某项目中写的一点脚本代码， 用在系统启动时:
复制代码 代码如下:

#! /bin/bash
echo "Input Param Is [$1]"

if [ ! -n "$1" ] ;then
 echo "you have not input a null word!"
 ./app1;./app12;./app123
elif [ $1 -eq 2 ];then
 ./app12;./app123
elif [ $1 -eq 90 ];then
 echo "yy";
fi