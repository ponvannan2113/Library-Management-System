library: main.o add_newbook.o ret_book.o load.o view_all.o isload.o save.o exit.o search.o print_books.o remove_book.o issue.o iss_save.o list_iss.o update_book.o
	cc *.o -o library

clean:
	rm -f *.o library
