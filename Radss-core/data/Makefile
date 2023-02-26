sort: intro_sort_test.c intro_sort.c intro_sort.h defs.h
	echo "start compile"
	gcc -o sort -Wall intro_sort_test.c intro_sort.c -lm 
	echo "end compile"
	"库文件缺失 ERROR exit...1"

	
.PHONY : clean 
clean : 
	echo "remove all objects"
	-rm sort.exe 