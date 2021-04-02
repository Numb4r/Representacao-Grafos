#!/bin/sh
#usage: random.sh NUMBERVERTEX NUMBEREDGES
RANDOM=$$
graph="digraph random{\n"
printf "" > graph.txt
for ((i=0;i<$2;i=i+1));do
    s1=$((RANDOM%$1)) 
    s2=$((RANDOM%$1))
    while : ; do 
        if grep -xq "^${s1} ${s2}$" graph.txt; then
            s1=$((RANDOM%$1)) 
            s2=$((RANDOM%$1))
        else 
            break 
        fi
    done
    printf "${s1} ${s2}\n" >>graph.txt
    graph="$graph${s1} -> ${s2};\n"
done



graph="${graph}}"
printf "${graph}" > graph.dot
# dot -Tpng graph.dot -o graph.png

sort -k 1n -k 2n graph.txt -o graph.txt
sed -i "1 i $1 $2" graph.txt