###################################
#	Name 	: Swathi Prakasha #

##################################	

# In the below codes -o: creates assign1 executable code from assign1.o object file, -lm:links math libarary#
assign1: assign1.o
	g++ -o assign1 assign1.o -lm


# In the below codes -c: compiles the source file and creates the assign1.o object file,#
# -Wall: warns if there are any warnings #
assign1.o: assign1.cc
	g++ -c -Wall assign1.cc


#The below code - clean command, which removes all the object file and executable code mentioned present in the directory#
clean:
	-rm *.o assign1
