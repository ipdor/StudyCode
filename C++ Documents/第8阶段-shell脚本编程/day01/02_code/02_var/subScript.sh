#!/bin/bash
echo "this is in sub script"
echo $globalVar1
echo "sub script end"


echo $environVar
#子进程修改环境变量
export environVar="2222222"
