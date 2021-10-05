echo "Enter Project's Name"
read file

result=$(./$file Text1.txt commands.txt)
#echo "$result"
IFS=$'\n'; arrIN=($result); unset IFS;
#arrIN=(${result//\n/})


expected=("1976 words" 
"Incorrect number of arguments" "845 distinct words" "Incorrect number of arguments" "13924 characters" "Incorrect number of arguments" 
	"Most frequent word is: mostrepeatedword" "Incorrect number of arguments" "Incorrect number of arguments" "that is repeated 15 times" "fog is repeated 13 times"
	 "yes is repeated 12 times" "order is repeated 10 times" "were is repeated 9 times" "stallman is repeated 9 times" 
	"l: 1 lab: 2 labor: 1 lamp: 1 language: 1 lasted: 2 lattice: 1 lays: 1 ld: 2 led: 1 leisure: 1 lessons: 1 letter: 2 letters: 8 liberties: 2 license: 2 licenses: 1 licensing: 1 lie: 1 like: 8 limping: 1 linebyline: 1 lines: 2 lippman: 1 long: 1 looks: 1 lope: 1 lopped: 1 lord: 1 lover: 1 ltle: 5 lulled: 1 lying: 1" 
	"sea: 4 see: 2 seemed: 1 sees: 1 self: 1 serene: 1 series: 1 session: 4 set: 1 setting: 1 seven: 1" "were: 9" 
	"aisles: 1 bristles: 1 discourse: 1 discussing: 1 distribution: 1 english: 2 fishers: 1 fishingboatbobbing: 1 gibberish: 2 his: 14 invisible: 1 is: 13 kentish: 1 leisure: 1 missed: 1 misty: 1 moorish: 1 published: 1 scientists: 1 surmised: 1 surprising: 1 this: 6 visible: 1" 
	"commands: 1 commercial: 1 commune: 1 communicate: 1 immortaly: 1 programmer: 1 programming: 2" 
"alameda: lines: 35 "
"among: lines: 33 37 "
"came: lines: 11 37 "
"dreaming: lines: 68 "
"dreams: lines: 68 "
"example: lines: 25 29 "
"jessamine: lines: 35 "
"lamp: lines: 35 "
"program: lines: 25 "
"programmer: lines: 23 "
"programming: lines: 3 15 "
"programs: lines: 23 "
"same: lines: 11 21 29 31 "
"scamander: lines: 37 "
"afternoon: lines: 33 "
"anomostrepeatedwordr: lines: 35 "
"honoured: lines: 37 "
"hypsenor: lines: 37 "
"ignored: lines: 21 "
"innocent: lines: 31 "
"innovation: lines: 19 "
"known: lines: 23 "
"no: lines: 17 37 44 "
"noble: lines: 37 "
"nonhackers: lines: 17 "
"nor: lines: 5 15 "
"normal: lines: 13 "
"not: lines: 23 37 39 "
"now: lines: 66 "
"snouting: lines: 66 "
"wetnosed: lines: 68 "
"excing: lines: 19 "
"addion: lines: 11 "
"description: lines: 13 "
"distribution: lines: 29 "
"dolopion: lines: 37 "
"elections: lines: 31 "
"equation: lines: 21 "
"explosion: lines: 19 "
"foundation: lines: 9 "
"frustration: lines: 23 "
"furiously: lines: 37 "
"glorious: lines: 35 "
"innovation: lines: 19 "
"inviolate: lines: 31 "
"modifications: lines: 11 "
"operational: lines: 23 "
"pensioners: lines: 33 68 "
"pollutions: lines: 33 "
"professionals: lines: 13 "
"proportion: lines: 25 27 "
"publication: lines: 13 "
"ratification: lines: 31 "
"session: lines: 3 6 15 "
"solution: lines: 11 "
"suation: lines: 21 "
"validation: lines: 19 "
"version: lines: 9 "
"versions: lines: 11 "
"apparent: lines: 31 "
"apprentice: lines: 33 "
"approach: lines: 19 "
"lippman: lines: 1 "
"lopped: lines: 37 "
"shipping: lines: 33 "
"skipper: lines: 33 "
"stopped: lines: 40 "
)

file_commands="commands.txt"
file_results="Test_Results"
touch $file_results

count=0
while read p; do 
    x[count]=$p
    count=$((count+1))
done < $file_commands


pass_count=0
fail_count=0

echo "*******************************" > $file_results
echo "*******************************" >> $file_results
echo "Sequence Of Output:" >> $file_results
echo "1. Command" >> $file_results
echo "2. Expected" >> $file_results
echo "3. Result" >> $file_results
echo "4. Pass / Fail" >> $file_results
echo "*******************************" >> $file_results
echo "*******************************" >> $file_results
echo "Test Results:" >>  $file_results
echo "*************" >> $file_results

for ((i=0; i<${#arrIN[*]}; i++));
do
	if [ $i -lt 20  ]
	then
		echo "*******************************" >> $file_results
		# Write Command to file
		echo $((i+1))". "${x[i]} >> $file_results
		# Write Expected Result to file
		echo ${expected[i]} >> $file_results
		# Write Output of C++ Code to file
		echo ${arrIN[i]} >> $file_results
		# Delete Wild Cards
		arrIN[i]=$( echo ${arrIN[i]} | tr --delete : )
		expected[i]=$( echo ${expected[i]} | tr --delete : )

		echo >> $file_results
		if [ "${arrIN[i]}" == "${expected[i]}" ]
		then
			echo "    PASS" >> $file_results
			((pass_count++))
		else
			echo "    FAIL" >> $file_results
			((fail_count++))
		fi
		echo "*******************************" >> $file_results
	elif [ $i -eq 20 ]
	then
		echo "*******************************" >> $file_results
		echo $((i+1))". "${x[i]} >> $file_results
		for ((j=20; j<$(( 21+13 )); j++));
		do
			echo ${expected[j]} >> $file_results
		done
		echo >> $file_results
		for ((j=20; j<$(( 21+13 )); j++));
		do
			echo ${arrIN[j]} >> $file_results
		done
		flag=0
		for ((j=20; j<$(( 21+13 )); j++));
		do
			arrIN[j]=$( echo ${arrIN[j]} | tr --delete : )
			expected[j]=$( echo ${expected[j]} | tr --delete : )
			if [ "${arrIN[j]}" != "${expected[j]}" ]
			then
				flag=1
				break
			fi
		done
		echo >> $file_results
		if [ $flag -eq 0 ]
		then
			echo "    PASS" >> $file_results
			((pass_count++))
		else
			echo "    FAIL" >> $file_results
			((fail_count++))
		fi
		echo "*******************************" >> $file_results

	elif [ $i -eq 21 ]
	then
		echo "*******************************" >> $file_results
		echo $((i+1))". "${x[i]} >> $file_results
		for ((j=$(( 21+14 )); j<$(( 21+14+16 )); j++));
		do
			echo ${expected[j]} >> $file_results
		done
		echo >> $file_results
		for ((j=$(( 21+14 )); j<$(( 21+14+16 )); j++));
		do
			echo ${arrIN[j]} >> $file_results
		done
		flag=0
		for ((j=$(( 21+14 )); j<$(( 21+14+16 )); j++));
		do
			arrIN[j]=$( echo ${arrIN[j]} | tr --delete : )
			expected[j]=$( echo ${expected[j]} | tr --delete : )
			if [ "${arrIN[j]}" != "${expected[j]}" ]
			then
				flag=1
				break
			fi
		done
		echo >> $file_results
		if [ $flag -eq 0 ]
		then
			echo "    PASS" >> $file_results
			((pass_count++))
		else
			echo "    FAIL" >> $file_results
			((fail_count++))
		fi
		echo "*******************************" >> $file_results
	elif [ $i -eq 22 ]
	then
		echo "*******************************" >> $file_results
		echo $((i+1))". "${x[i]} >> $file_results
		for ((j=$(( 21+14+16 )); j<$(( 21+14+17 )); j++));
		do
			echo ${expected[j]} >> $file_results
		done
		echo >> $file_results
		for ((j=$(( 21+14+16 )); j<$(( 21+14+17 )); j++));
		do
			echo ${arrIN[j]} >> $file_results
		done
		flag=0
		for ((j=$(( 21+14+16 )); j<$(( 21+14+17 )); j++));
		do
			arrIN[j]=$( echo ${arrIN[j]} | tr --delete : )
			expected[j]=$( echo ${expected[j]} | tr --delete : )
			if [ "${arrIN[j]}" != "${expected[j]}" ]
			then
				flag=1
				break
			fi
		done
		echo >> $file_results
		if [ $flag -eq 0 ]
		then
			echo "    PASS" >> $file_results
			((pass_count++))
		else
			echo "    FAIL" >> $file_results
			((fail_count++))
		fi
		echo "*******************************" >> $file_results
	elif [ $i -eq 23 ]
	then
		echo "*******************************" >> $file_results
		echo $((i+1))". "${x[i]} >> $file_results
		for ((j=$(( 21+14+17 )); j<$(( 21+14+17+27 )); j++));
		do
			echo ${expected[j]} >> $file_results
		done
		echo >> $file_results
		for ((j=$(( 21+14+17 )); j<$(( 21+14+17+27 )); j++));
		do
			echo ${arrIN[j]} >> $file_results
		done
		flag=0
		for ((j=$(( 21+14+17 )); j<$(( 21+14+17+27 )); j++));
		do
			arrIN[j]=$( echo ${arrIN[j]} | tr --delete : )
			expected[j]=$( echo ${expected[j]} | tr --delete : )
			if [ "${arrIN[j]}" != "${expected[j]}" ]
			then
				flag=1
				break
			fi
		done
		echo >> $file_results
		if [ $flag -eq 0 ]
		then
			echo "    PASS" >> $file_results
			((pass_count++))
		else
			echo "    FAIL" >> $file_results
			((fail_count++))
		fi
		echo "*******************************" >> $file_results
	elif [ $i -eq 24 ]
	then
		echo "*******************************" >> $file_results
		echo $((i+1))". "${x[i]} >> $file_results
		for ((j=$(( 21+14+17+27 )); j<$(( 21+14+17+27+8 )); j++));
		do
			echo ${expected[j]} >> $file_results
		done
		echo >> $file_results
		for ((j=$(( 21+14+17+27 )); j<$(( 21+14+17+27+8 )); j++));
		do
			echo ${arrIN[j]} >> $file_results
		done
		flag=0
		for ((j=$(( 21+14+17+27 )); j<$(( 21+14+17+27+8 )); j++));
		do
			arrIN[j]=$( echo ${arrIN[j]} | tr --delete : )
			expected[j]=$( echo ${expected[j]} | tr --delete : )
			if [ "${arrIN[j]}" != "${expected[j]}" ]
			then
				flag=1
				break
			fi
		done
		echo >> $file_results
		if [ $flag -eq 0 ]
		then
			echo "    PASS" >> $file_results
			((pass_count++))
		else
			echo "    FAIL" >> $file_results
			((fail_count++))
		fi
		echo "*******************************" >> $file_results
	fi
done

echo "****************************************************************************"
echo "		     Results Are Stored in Test_Results.txt"
echo "****************************************************************************"
echo "Passed Tests: " $pass_count"/25"
echo "Failed Tests: " $fail_count"/25"
echo "****************************************************************************"
echo "Please Note:"
echo "1. The script ONLY compares the output words and disregards the format"
echo "   so please re-check the format"
echo "2. It's very possible that the script isn't 100% correct"
echo "****************************************************************************"
echo "The following cases WERE NOT tested"
echo "1. When File is not found"
echo "2. When starting/search/countWord/containing take more 0 or 2 arguments"
echo "****************************************************************************"
