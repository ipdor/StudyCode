#!/bin/bash

function visit
{
    local dir="$1"
    for f in `ls $dir`
    do
        if [ -f "$dir/$f" ]
        then
            echo "$dir/$f is a file"
        elif [ -d "$dir/$f" ]
        then
            echo "$dir/$f is a dir"
            visit "$dir/$f"
        else
            echo "$dir/$f is not recognized" 
        fi
    done
}

visit .
