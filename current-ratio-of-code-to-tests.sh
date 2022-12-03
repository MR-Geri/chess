#! /bin/sh
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
echo -e "Текущее соотношение кода к тестам:"

files_tests=$(find -regex "\./tests/tst.*\.\(cpp\|hpp\|h\|cxx\)")
files_code=$(find -regex "\./src.*\.\(cpp\|hpp\|h\|cxx\)")
files_code_no_gui=$(find -regex "\./src/[^gui/].*\.\(cpp\|hpp\|h\|cxx\)")

echo -e "$RED Files tests:$NC"
echo -e $files_tests | tr " " "\n"
echo -e "$RED Files code:$NC"
echo -e $files_code | tr " " "\n"
echo -e "$RED Files code no gui:$NC"
echo -e $files_code_no_gui | tr " " "\n"

tests=$(grep . $files_tests | wc -l)
code=$(grep . $files_code | wc -l)
code_no_gui=$(grep . $files_code_no_gui | wc -l)

code_tests=$(bc<<<"scale=3;$code/$tests")
code_no_gui_tests=$(bc<<<"scale=3;$code_no_gui/$tests")

echo -e "\n----------------------------------------------------------"
echo -e "$GREEN Code = $code$NC"
echo -e "$GREEN Code no GUI = $code_no_gui$NC"
echo -e "$RED Tests = $tests$NC"
echo -e "Code/Tests = $code_tests$NC"
echo -e "Code no GUI/Tests = $code_no_gui_tests$NC"
echo -e "----------------------------------------------------------"
