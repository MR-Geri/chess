#! /bin/sh
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
echo -e "Текущее соотношение кода к тестам:"

tests=$(find -regex ".*tst.*\.\(cpp\|hpp\|h\|cxx\)" -exec grep . {} \; | wc -l)
code=$(find -regex ".*src.*\.\(cpp\|hpp\|h\|cxx\)" -exec grep . {} \; | wc -l)
code_no_gui=$(find -regex ".*src/[^gui/].*\.\(cpp\|hpp\|h\|cxx\)" -exec grep . {} \; | wc -l)
code_tests=$(bc<<<"scale=3;$code/$tests")
code_no_gui_tests=$(bc<<<"scale=3;$code_no_gui/$tests")
echo -e "$GREEN Code = $code$NC"
echo -e "$GREEN Code no GUI = $code_no_gui$NC"
echo -e "$RED Tests = $tests$NC"
echo -e "Code/Tests = $code_tests$NC"
echo -e "Code no GUI/Tests = $code_no_gui_tests$NC"
