#!/bin/sh
## truc.sh for  in /home/pidoux_q/data/shell/bdsh
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
	action="$1"
	clef="$2"
	value="$3"
    else
	echo "Syntax error : Usage ...."
	exit
    fi    
elif [ "$2" = "put" ] || [ "$2" = "del" ] || [ "$2" = "select" ] && [ "$1" = "-k" ] ; then
    if [ "$3" != "" ] || [ "$2" = "select" ] ; then
	action="$2"
	clef="$3"
	value="$4"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
elif [ "$3" = "put" ] || [ "$3" = "del" ] || [ "$3" = "select" ] && [ "$1" = "-f" ] && [ "$2" != "-k" ] ; then
    if [ "$4" != "" ] || [ "$3" = "select" ] ; then
	action="$3"
	clef="$4"
	value="$5"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
elif [ "$4" = "put" ] || [ "$4" = "del" ] || [ "$4" = "select" ] && [ "$1" = "-k" ] && [ "$2" = "-f" ] ; then
    if [ "$5" != "" ] || [ "$4" = "select" ] ; then
	action=$4
	clef="$5"
	value="$6"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
elif [ "$4" = "put" ] || [ "$4" = "del" ] || [ "$4" = "select" ] && [ "$3" = "-k" ] && [ "$1" = "-f" ] ; then
    if [ "$5" != "" ] || [ "$4" = "select" ] ; then
	action=$4
	clef="$5"
	value="$6"
    else
	echo "Syntax error : Usage ...."
	exit
    fi
else
    echo "Syntax error : Usage ...."
    exit
fi

db=$(cat $file)

if [ "${clef:0:1}" = '$' ] ; then
    tmp=$(echo "$clef" | sed 's/\$//1')
    tmp=$(cat $file | grep $tmp)
    clef=$(echo "$tmp" | cut -d= -f2)
fi

if [ "${value:0:1}" = '$' ] ; then
    tmp=$(echo "$value" | sed 's/\$//1')
    tmp=$(cat $file | grep $tmp)
    value=$(echo "$tmp" | cut -d= -f2)
fi



if [ "$action" = "put" ] ; then
    if [ "${clef:0:1}" != '$' ] && [ "${value:0:1}" != '$' ] ; then 
	echo "$db" | sed "/${clef}=/d" > $file
	echo "$clef=$value" >> $file
    fi
elif [ "$action" = "del" ] ; then
    echo "$db" | sed "/${clef}=/d" > $file
    if [ "$value" = "" ] ; then
	echo "$clef=" >> $file
    fi
elif [ "$action" = "select" ] ; then
    if [ "$ok" = 0 ] ; then
	tmp=$(echo "$db" | cut -d= -f1 | grep "${clef}")
	tmp=$(echo "${tmp}" | sed 's/$/=/g') 
	echo "$db" | grep "${tmp}" | cut -d= -f2
    elif [ "$ok" = 1 ] ; then
	tmp=$(echo "$db" | cut -d= -f1 | grep "${clef}")
	tmp=$(echo "${tmp}" | sed 's/$/=/g') 
	echo "$db" | grep "${tmp}"
    fi
fi
