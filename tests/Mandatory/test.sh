array=(
	"cat | wc"
	"cat | 'wc -l'"
	"'ls -l' | 'wc -l'"
	"cat | ./tester"
	"cat | ./no_perm_read"

	"cat | ./no_exist"
	"cat | ./no_perm_ex"
	"cat | 'wc -wrong-option'"
	"'ls no_such_file' | 'ls no_such_file'"

	## ノンブロッキングのテスト
	"cat | ls"
)

cp ./tester ./no_perm_ex
chmod -x ./no_perm_ex
cp ./tester ./no_perm_read
chmod -r ./no_perm_read

files=(
	"tests/infile/normal"
)
# for file in $(find ./tests/infile -type f)
# do
#     files=(${files[@]} $file)
# done

for i in ${!array[@]};
do
	for file in ${files[@]};
	do
		echo "< $file `echo ${array[$i]} | sed "s/'//g"` > tests/expect" | bash
		EX_STATUS=$?
		# echo "./tester $file `echo ${array[$i]} | sed 's/ | / /g'` tests/out" | bash
		echo "./pipex $file `echo ${array[$i]} | sed 's/ | / /g'` tests/out" | bash
		STATUS=$?

		diff tests/out tests/expect > /dev/null
		if [ $? -eq 0 ] && [ $STATUS -eq $EX_STATUS ]; then
			printf "\e[1m %s \e[32m %s \e[m\n\n" "${array[$i]}" "✓"
		else
			printf "\e[1m %s \e[31m %s \e[m\n" "${array[$i]}" "×"
			echo "status code => out: $STATUS / expect: $EX_STATUS"
			diff -y -W 80 ./tests/out ./tests/expect
			FLG=1
		fi
		rm -f tests/out tests/expect
	done
done
rm -f leaksout no_perm_ex no_perm_read

exit $FLG
