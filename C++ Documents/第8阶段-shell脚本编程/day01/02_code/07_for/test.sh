#!/bin/bash

for FRUIT in apple banana pear 
do
    echo "I like $FRUIT"
done


# 计算 1加到100的结果  5050
sum=0
for i in {1..100}
do
    sum=$[$sum+$i]
done
echo $sum


# 遍历当前目录，是文件就输出xxx是一个文件，是目录的就输出xxx是一个目录
for f in $(ls)
do
    if [ -f "$f" ]
    then
        echo "$f is a regular file"
    elif [ -d "$f" ]
    then
        echo "$f is a directory"
    else
        echo "$f is not recognized"
    fi
done


sum=0
count=1
while [ $count -le 100 ]
do
    sum=$[$sum+$count]
    count=$[$count+1]
done
echo $sum
