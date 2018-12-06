#!/bin/bash

p_name=ffmpeg

# while true

# do

# 暂停60s

# sleep 60

# 取进程ID号

# list="$(ps -A | grep $p_name|grep -v 3537|sort -k3,3| head -n3 |awk '{print $1}')"
list="$(ps -A | grep $p_name|sort -k3,3|awk '{print $1}')"

 

# 循环取时间，并kill超长进程

for pid in $list

do

	time="$(ps -eo pid,etime  | grep $pid | awk '{print $2}'|./script.awk)"

	echo $pid $time

	#if [[ $time -ge '10800'  ]];then

	# kill -9 $pid
	# echo $pid $time

	#fi

done

# done


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
