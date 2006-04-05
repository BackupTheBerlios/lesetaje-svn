n=0
anz=0
# datei=$(kdialog --getopenfilename ~/pub *.tab)
datei="/skole/tjener/home0/a06-tatzs/pub/Spielkarten/fragen.tab"
temp="/tmp/quiz9194"

echo "Ergebnis" >$temp 

cat $datei | while read frage
do
   
   
   if [ "$frage" = "Ende" ] 
   then
       kdialog --msgbox "Fertig."
       # kdialog --title Ergebnis --textbox $temp
       
       
       exit 0
   else
        read a
        read b
        read c
        # antwort=$(kdialog  --menu "$frage" a "$a" b "$b" c "$c")
        # >> $temp
        if [ $? = 1 ]; then exit 0 ; fi
        read richtig
	anz=$((1+$anz)) 
            
	# echo "Deine Antwort war $($antwort)." >> $temp
	 export $richtig 
	 echo echo \$$richtig | bash >/tmp/richtig.tab
	 antwort=`cat /tmp/richtig.tab`
	 convert -font Arial -pointsize 20 -fill black -gravity center -annotate 0 "$antwort" antwort.jpg a$anz.jpg
         convert -font Arial -pointsize 10 -fill black -gravity center -annotate 0 "$frage" frage.jpg f$anz.jpg 
        
        
        
        
   fi
done   



# kdialog --msgbox "Du hast $n von $anz Punkten erreicht."