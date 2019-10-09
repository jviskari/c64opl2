all: oplaudio.prg

oplaudio.prg: main.c vgm.inc data.c opl_driver.c gd3.c player.c
	cl65 -t c64 -Oris -o oplaudio.prg main.c data.c opl_driver.c gd3.c player.c

vgm.inc: vgmData
	xxd -i vgmData > vgm.inc
	
clean:
	rm -f *.prg *.inc *.o
