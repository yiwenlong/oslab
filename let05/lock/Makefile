SRC_MAIN 	= main.c spin_lock.h
SRC_NOLOCK 	= no_lock.c
SRC_TAS		= tas_lock.c test_and_set.S
SRC_CAS		= cas_lock.c compare_and_swap.S

nolock: $(SRC_MAIN) $(SRC_NOLOCK) 
	gcc $^ -o $@

taslock: $(SRC_MAIN) $(SRC_TAS) 
	gcc $^ -o $@

caslock: $(SRC_MAIN) $(SRC_CAS) 
	gcc $^ -o $@

clean:
	rm nolock taslock caslock
