all:
	g++ -o create_index -I/usr/local/include -l xapian create_index.cpp
	g++ -o search -I/usr/local/include -l xapian search.cpp
clean:
	rm -rf create_index index_data/ search
