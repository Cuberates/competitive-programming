clean: 
	find . -path './.git' -prune -o -type f \( -name '*.out' -o -name '*.in' \) -delete
	find . -path './.git' -prune -o -type f ! -name '*.*' ! -iname 'makefile' ! -iname 'gnumakefile' -delete
