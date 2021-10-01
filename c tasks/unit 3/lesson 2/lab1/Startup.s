
.global reset

reset:
	ldr sp,=_stack_p
	bl main

loop:
	b loop

