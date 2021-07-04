#!/bin/bash

echo "Please input paswd"
read try
errCount=1
while [ "$try" != "secret" ]
do
    if [ "$errCount" -ge 5 ]
    then
        echo "Error 5 times , exit"
        break
    fi
    echo "Sorry , try again!"
    read try
    errCount=$[$errCount+1]
done
