#!/bin/bash

who|sort>prev
while true;do
    sleep 5
    who|sort>cur
    echo "logged out"
    comm -23 prev cur
    echo "logged in"
    comm -13 prev cur
    mv cur prev
done
