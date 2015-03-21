all:
	g++ -o create_index -I/usr/local/include -l xapian create_index.cpp
	g++ -o query -I/usr/local/include -l xapian query.cpp
clean:
	rm -rf create_index query index_data/
