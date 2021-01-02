CC = gcc
CFLAGS =
CCFLAGS = 
CPPFLAGS = -Wall
LIBFLAGS =
PRODFLAGS = -OFast -funroll-loop

EXEC = mlfe
PROJECTNAME = MoodLightingForEm

SRCS = main.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean pristine fresh backup keepsake deliverable

all: $(EXEC)

clean:
	rm -f *.o *~

pristine:
	rm -f *.o *~ $(EXEC)

#backup:
#	@mkdir -p ../backups; chmod 700 ../backups
#	$(eval CURDIRNAME := $(shell basename `pwd`))
#	$(eval MKBACKUPNAME := ../backups/$(PROJECTNAME)-$(shell date '+%Y.%m.%d-%H.%M.%S').tar.gz)
#	@tar --exclude=".*" -czvf ../$(CURDIRNAME) $(MKBACKUPNAME)
#	@chmod 600 $(MKBACKUPNAME)

backup:
	@echo Cleaning
	@mkdir -p ../backups; chmod 700 ../backups
	$(eval CURDIRNAME := $(shell basename `pwd`))
	$(eval MKBACKUPNAME := ../backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H.%M.%S').tar.gz)
	@echo Backing\ up\ to\ $(MKBACKUPNAME)
	@tar -czvf $(MKBACKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBACKUPNAME)
	@echo Backup\ complete

fresh: pristine all

keepsake: pristine backup

deliverable: clean backup

$(EXEC): $(OBJS)
	$(CC) $(CCFLAGS) $(LIBFLAGS) -o $(EXEC) $(OBJS)

%.o:%.c
	$(CC) -c $(CFLAGS) $(CCFLAGS) $< -o $@

production: $(SRCS)
	$(CC) -c $(CFLAGS) $(CCFLAGS) $(PRODFLAGS) $< -o $@
	$(CC) $(CCFLAGS) $(LIBFLAGS) -o $(EXEC) $(OBJS)
