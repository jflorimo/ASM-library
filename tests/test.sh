#! /bin/sh

BASE="./tests"
TMP="$BASE/tmp"
mkdir -p "$TMP"

ERRORS=0

CLEAR="\033[00m"
RED="\033[31m"
GREEN="\033[32m"
HILIGHT="\n\n\033[35;4;1m"

################# GENERIC ##################
echo $HILIGHT"##################################### Generic tests ...$CLEAR"
generic_src="$BASE/generic.c"
generic_bin="$TMP/generic"
gcc -Wl,-no_pie -I. -L. -lfts "$generic_src" -o "$generic_bin"
if $generic_bin; then
    echo $GREEN"--> TEST SUCCESS: generic"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: generic"$CLEAR
fi


################# FT_PUTS ##################
set -e
echo $HILIGHT"##################################### Testing ft_puts() ..."$CLEAR

puts_src="$BASE/puts.c"
puts_bin="$TMP/puts"
ft_puts_bin="$TMP/ft_puts"
gcc -Wl,-no_pie -I. -L. -lfts "$puts_src" -o "$puts_bin"
gcc -Wl,-no_pie -I. -L. -lfts -D "FT_PUTS" "$puts_src" -o "$ft_puts_bin"

$puts_bin > "${puts_bin}.out"
$ft_puts_bin > "${ft_puts_bin}.out"

if diff "${puts_bin}.out" "${ft_puts_bin}.out" &> /dev/null; then
    echo $GREEN"--> TEST SUCCESS: ft_puts()"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: ft_puts() (run 'vimdiff ${puts_bin}.out ${ft_puts_bin}.out' to show diffs)"$CLEAR
fi

################# FT_CAT ##################
set -e
echo $HILIGHT"##################################### Testing ft_cat() ..."$CLEAR

cat_src="$BASE/cat.c"
cat_bin="$TMP/cat"
ft_cat_bin="$TMP/ft_cat"
gcc -Wl,-no_pie -I. -L. -lfts "$cat_src" -o "$cat_bin"
gcc -Wl,-no_pie -I. -L. -lfts -D FT_CAT "$cat_src" -o "$ft_cat_bin"

# empty file
> "$TMP/cat_empty"

# < "$TMP/cat_empty" $cat_bin > "${cat_bin}.out"
< "$TMP/cat_empty" cat > "${cat_bin}.out"
< "$TMP/cat_empty" $ft_cat_bin > "${ft_cat_bin}.out"

if diff "${cat_bin}.out" "${ft_cat_bin}.out" &> /dev/null; then
    echo $GREEN"--> TEST SUCCESS: ft_cat() empty file"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: ft_cat() (run 'vimdiff ${cat_bin}.out ${ft_cat_bin}.out' to show diffs)"$CLEAR
fi

# pseudo random file data
< /dev/urandom head -c 10000 > "$TMP/cat_random"

# < "$TMP/cat_random" $cat_bin > "${cat_bin}.out"
< "$TMP/cat_random" cat > "${cat_bin}.out"
< "$TMP/cat_random" $ft_cat_bin > "${ft_cat_bin}.out"

if diff "${cat_bin}.out" "${ft_cat_bin}.out" &> /dev/null; then
    echo $GREEN"--> TEST SUCCESS: ft_cat() random data"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: ft_cat() (run 'vimdiff ${cat_bin}.out ${ft_cat_bin}.out' to show diffs)"$CLEAR
fi

# /etc/passwd
< "/etc/passwd" cat > "${cat_bin}.out"
< "/etc/passwd" $ft_cat_bin > "${ft_cat_bin}.out"

if diff "${cat_bin}.out" "${ft_cat_bin}.out" &> /dev/null; then
    echo $GREEN"--> TEST SUCCESS: ft_cat() /etc/passwd"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: ft_cat() (run 'vimdiff ${cat_bin}.out ${ft_cat_bin}.out' to show diffs)"$CLEAR
fi

#/etc/shadow
set +e
< "/etc/shadow" cat 2>/dev/null > "${cat_bin}.out" || true
< "/etc/shadow" $ft_cat_bin > "${ft_cat_bin}.out"
set -e

if diff "${cat_bin}.out" "${ft_cat_bin}.out" &> /dev/null; then
    echo $GREEN"--> TEST SUCCESS: ft_cat() /etc/shadow"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: ft_cat() (run 'vimdiff ${cat_bin}.out ${ft_cat_bin}.out' to show diffs)"$CLEAR
fi

#/etc/shadow
set +e
< "/dev/null" cat 2>/dev/null > "${cat_bin}.out" || true
< "/dev/null" $ft_cat_bin > "${ft_cat_bin}.out"
set -e

if diff "${cat_bin}.out" "${ft_cat_bin}.out" &> /dev/null; then
    echo $GREEN"--> TEST SUCCESS: ft_cat() /dev/null"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: ft_cat() (run 'vimdiff ${cat_bin}.out ${ft_cat_bin}.out' to show diffs)"$CLEAR
fi




if [[ $ERRORS -gt 0 ]]; then
    echo ${HILIGH}${RED}"FAILED TESTS: $ERRORS"$CLEAR
    exit 1
else
    echo ${HILIGHT}${GREEN}"EVERYTHING IS OK !"$CLEAR
    exit 0
fi
