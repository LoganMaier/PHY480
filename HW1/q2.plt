# gnuplot plot file: quad_eq.plt
set terminal x11   # terminal type: for a Mac, use "aqua" instead of "x11"
set title 'Sum Up/Down Comparison'
set xlabel 'N'
set ylabel 'Difference'
plot "Up_down.dat" using (log10($1)):(log10($4)) title 'difference', \

set pointsize 1.5   # set the size of the plotted points
set key top left    # move the key away from the lines
set timestamp	  # turn on a date/time indicator

set out "Q2Plot.ps"	# name of the output postscript file
set terminal postscript	        # switch to postscript mode
replot  		  	# plot to the file
