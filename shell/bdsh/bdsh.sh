#!/bin/sh
## bdsh.sh for  in /home/pidoux_q/data/shell/bdsh
## 
## Made by quentin PIDOUX
## Login   <pidoux_q@epitech.net>
## 
## Started on  Sat Jan 29 19:34:56 2011 quentin PIDOUX
## Last update Sat Jan 29 19:40:14 2011 quentin PIDOUX
##

ok="0"
file="sh.bd"

if [ "$1" = "-k" ] || [ "$2" = "-k" ] || [ "$3" = "-k" ] || [ "$4" = "-k" ] || [ "$5" = "-k" ] || [ "$6" = "-k" ] ; then 
    ok="1"
fi

if [ "$1" = "-f" ] ; then
    file="$2"
elif [ "$2" = "-f" ] ; then
    file="$3"
elif [ "$3" = "-f" ] ; then
    file="$4"
elif [ "$4" = "-f" ] ; then
    file="$5"
elif [ "$5" = "-f" ] ; then
    file="$6"
fi

if [ ! -e "$file" ]; then
    echo "No base found : file $file"
    exit
fi

if [ "$1" = "put" ] || [ "$1" = "del" ] || [ "$1" = "select" ] ; then
    if [ "$2" != "" ] || [ "$1" = "select" ] ; then
	act="$1"
	key="$2"
	val="$3"
    else
	echo "Syntax error : Usage ...."
	exit
    fi    
elif [ "$2" = "put" ] || [ "$2" = "del" ] || [ "$2" = "select" ] && [ "$1" = "-k" ] ; then
    if [ "$3" != "" ] || [ "$2" = "select" ] ; then
	act="$2"
	key="$3"
	val="$4"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
elif [ "$3" = "put" ] || [ "$3" = "del" ] || [ "$3" = "select" ] && [ "$1" = "-f" ] && [ "$2" != "-k" ] ; then
    if [ "$4" != "" ] || [ "$3" = "select" ] ; then
	act="$3"
	key="$4"
	val="$5"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
elif [ "$4" = "put" ] || [ "$4" = "del" ] || [ "$4" = "select" ] && [ "$1" = "-k" ] && [ "$2" = "-f" ] ; then
    if [ "$5" != "" ] || [ "$4" = "select" ] ; then
	act=$4
	key="$5"
	val="$6"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
elif [ "$4" = "put" ] || [ "$4" = "del" ] || [ "$4" = "select" ] && [ "$3" = "-k" ] && [ "$1" = "-f" ] ; then
    if [ "$5" != "" ] || [ "$4" = "select" ] ; then
	act=$4
	key="$5"
	val="$6"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
else
    echo "Syntax error : Usage ...."
    exit
fi

db=$(cat $file)

if [ "${key:0:1}" = '$' ] ; then
    cache=$(echo "$key" | sed 's/\$//1')
    cache=$(cat $file | grep $cache)
    key=$(echo "$cache" | cut -d= -f2)
fi

if [ "${val:0:1}" = '$' ] ; then
    cache=$(echo "$val" | sed 's/\$//1')
    cache=$(cat $file | grep $cache)
    val=$(echo "$cache" | cut -d= -f2)
fi



if [ "$act" = "put" ] ; then
    if [ "${key:0:1}" != '$' ] && [ "${val:0:1}" != '$' ] ; then 
	echo "$db" | sed "/${key}=/d" > $file
	echo "$key=$val" >> $file
    fi
elif [ "$act" = "del" ] ; then
    echo "$db" | sed "/${key}=/d" > $file
    if [ "$val" = "" ] ; then
	echo "$key=" >> $file
    fi
elif [ "$act" = "select" ] ; then
    if [ "$ok" = 0 ] ; then
	cache=$(echo "$db" | cut -d= -f1 | grep "${key}")
	cache=$(echo "${cache}" | sed 's/$/=/g') 
	echo "$db" | grep "${cache}" | cut -d= -f2
    elif [ "$ok" = 1 ] ; then
	cache=$(echo "$db" | cut -d= -f1 | grep "${key}")
	cache=$(echo "${cache}" | sed 's/$/=/g') 
	echo "$db" | grep "${cache}"
    fi
fi
