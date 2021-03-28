plot \
	2*x*exp(-x),\
	"1.dat" using ($1):($2) title "dim = 1",\
	"5.dat" using ($1):($2) title "dim = 5",\
	"10.dat" using ($1):($2) title "dim = 10",\
	"20.dat" using ($1):($2) title "dim = 20"
