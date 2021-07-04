#!/bin/bash
#dateTime=`date`
dateTime=$(date)
echo "dateTime is " $dateTime

#touch 1.txt
#获取当前脚本所在路径 ,在这个路径touch一个1.txt
curPath=$(cd `dirname $0`;pwd)
touch $curPath/1.txt


var=45
var2=2
echo $[var+3]
echo $((var+3))
echo $((var*var2))
echo $(($var*$var2))

echo $[8#10+11]



var="a b"
./a.out $var
./a.out "$var"

#创建两个文件
touch $var
#创建一个文件
touch "$var"
