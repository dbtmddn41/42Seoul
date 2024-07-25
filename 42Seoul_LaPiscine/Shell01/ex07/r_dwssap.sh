cat /etc/passwd|grep -v ^#|cut -d ':' -f1|rev|sort -r|awk -v FT_LINE1=$FT_LINE1 -v FT_LINE2=$FT_LINE2 'FT_LINE1<=NR && NR<=FT_LINE2'|tr '\n' ','|sed 's/,/, /g'|sed 's/, $/./'|tr -d '\n'
