
KEY=123
export KEY

all:
	make -C blob_maker all
	make -C src all

clean:
	make -C blob_maker clean
	make -C src clean
