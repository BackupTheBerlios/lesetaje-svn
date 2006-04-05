n=0
anz=0
# datei=$(kdialog --getopenfilename ~/pub *.tab)
datei="/skole/tjener/home0/a06-tatzs/pub/fragen.tab"
temp="/tmp/quiz9194"

echo "Ergebnis" >$temp 

cat $datei | while read frage
do
   
   
   if [ "$frage" = "Ende" ] 
   then
       kdialog --msgbox "Du hast $n von $anz Punkten erreicht."
       kdialog --title Ergebnis --textbox $temp
       
       
       exit 0
   else
        read a
        read b
        read c
        antwort=$(kdialog  --menu "$frage" a "$a" b "$b" c "$c")
        >> $temp
        if [ $? = 1 ]; then exit 0 ; fi
        read richtig
	anz=$((1+$anz)) 
        if [ $antwort = $richtig ] 
        then 
            n=$((1+$n)) 
	else
	    
	    echo Frage $anz war falsch: $frage >> $temp
	    export $antwort 
	    echo echo Deine Antwort war \$$antwort.  | bash >> $temp
	   # echo "Deine Antwort war $($antwort)." >> $temp
	    export $richtig 
	    echo echo Richtig wäre \$$richtig gewesen.  | bash >> $temp
	            
        fi
        
        
        
   fi
done   



# kdialog --msgbox "Du hast $n von $anz Punkten erreicht."