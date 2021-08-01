array=(
	"cat wc"
	"./tester cat"
	"./no_exist cat"
	"./no_perm_ex cat"
	"./no_perm_read cat"
)

cp ./tester ./no_perm_ex
chmod -x ./no_perm_ex
cp ./tester ./no_perm_read
chmod -r ./no_perm_read

for i in ${!array[@]};
do
	for file in $(find "./tests/infile" -type f);
	do
		printf "=> \e[1m %s \e[m\n" "./pipex $file ${array[$i]} out"

		./pipex $file ${array[$i]} out
		STATUS=$?
		echo "< $file `echo ${array[$i]} | sed "s/ / | /"` > expect" | bash
		EX_STATUS=$?

		# diff out expect > /dev/null
		diff -y -W 80 out expect > /dev/stderr
		if [ $? -eq 0 ] && [ $STATUS -eq $EX_STATUS ]; then
			printf "\e[32m%s\n\e[m" ">> OK!"
		else
			printf "\e[31m%s\n\e[m" ">> KO!"
			diff -y out expect
			FLG=1
		fi
		rm -f out expect
	done
done
rm -f leaksout

exit $FLG
