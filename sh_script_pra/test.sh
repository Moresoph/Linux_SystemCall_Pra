#!/bin/bash
name="yux"
greeting="hello,${name}"
echo ${greeting}
string="abcd"
echo ${#string}
echo `expr  index "$string" bc`
