include src/Makefile.inc

all:	$(PROGRAMNAME)
#	cd src; make
#	cp src/$(PROGRAMNAME) .


$(PROGRAMNAME): src/rhapsody
	cp src/$(PROGRAMNAME) .

src/rhapsody:
	cd src; make

install: $(PROGRAMNAME)
	mkdir -p $(INSTALLPATH)
	mkdir -p $(INSTALLPATH)/help
	cp $(PROGRAMNAME) $(INSTALLPATH)
	cp help/*.hlp $(INSTALLPATH)/help

clean:
	cd src; make clean
	rm -f $(PROGRAMNAME)

src/Makefile.inc:
	./configure

tar:
	rm -rf rhapsody-$(PROGRAMVER)
	mkdir -p rhapsody-$(PROGRAMVER)/src
	mkdir -p rhapsody-$(PROGRAMVER)/help
	mkdir -p rhapsody-$(PROGRAMVER)/docs
	cp src/*.c rhapsody-$(PROGRAMVER)/src
	cp src/*.h rhapsody-$(PROGRAMVER)/src
	cp src/Makefile rhapsody-$(PROGRAMVER)/src
	rm -f src/autodefs.h
	cp help/*.hlp rhapsody-$(PROGRAMVER)/help
	cp docs/* rhapsody-$(PROGRAMVER)/docs
	cp Makefile rhapsody-$(PROGRAMVER)
	cp configure rhapsody-$(PROGRAMVER)
	cp README rhapsody-$(PROGRAMVER)
	tar -czvf rhapsody_$(PROGRAMVER).tgz rhapsody-$(PROGRAMVER)


