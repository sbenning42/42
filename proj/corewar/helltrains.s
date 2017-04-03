#by zaz, still not as good as rainbowdash though
#2013

.name		"helltrain"
.comment	"choo-choo, motherf*****s !"

entry:
	sti		r1, %:beegees_gen, %1
	sti		r1, %:beegees, %1
	sti		r1, %:cc_spawn, %1
	sti		r1, %:wall, %1
	sti		r1, %:cc4, %1
	sti		r1, %:cc4, %9
	sti		r1, %:cc3, %1
	sti		r1, %:cc2, %1
	ld		%0, r16
	fork	%:cc_spawn

wall_prep:
	ld		%0, r2
	ld		%0, r16

wall:
	zjmp	%:wall

beegees_gen:
	fork	%:beegees_gen
	ld		%0, r16

beegees:
	ld		%0, r16
	zjmp	%:beegees

cc_spawn:
	zjmp	%3
	fork	%:cc_spawn

cc4:
	fork	%:cc3
	fork	%:cc2
	fork	%:cc1
cc4ld:
	ld		%0, r2
cc4l:
	live	%4930423	
	ld		%0, r16
	zjmp	%:choochoo

cc2:
	live	%4342342
	fork	%:wall_prep
	zjmp	%:choochoo

cc3:
	fork	%:cc4
	fork	%:beegees_gen
	ld		%0, r16
	zjmp	%:choochoo

cc1:
	ld		%0, r16
	zjmp	%:choochoo

choochoo:
	st		r2, 15
cc_live:
	live	%0
