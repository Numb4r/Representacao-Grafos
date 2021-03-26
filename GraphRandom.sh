#!/bin/sh
#usage: random.sh NUMBERVERTEX NUMBEREDGES
RANDOM=$$
text=""
graph="digraph random{\n"
for ((i=0;i<$2;i=i+1))
do
    s1=$((RANDOM%$1))
    s2=$((RANDOM%$1))
    text="${text}${s1},${s2}\n"
    graph="$graph${s1} -> ${s2};\n"
done
graph="${graph}}"
printf $text > graph.txt;
printf "${graph}" > graph.dot
dot -Tpng graph.dot -o graph.png

sort -h graph.txt -o graph.txt
sed -i "1 i $1,$2" graph.txt