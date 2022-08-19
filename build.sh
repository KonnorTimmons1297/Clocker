#! /bin/bash

if [ -f "clocker" ]; then
    rm clocker
fi

gcc clocker.c -o clocker

