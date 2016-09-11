#!/bin/sh
BOOK=$HOME/phonebook.data
echo find what name is phonebook
read NAME 
if grep $NAME $BOOK > /tmp/pb.temp
then
	echo Entries for $Name
	cat /tmp/pb.tmp
else
	echo No entries for $NAME
fi
rm /temp/pb.tmp
