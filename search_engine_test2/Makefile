all:
	g++ -o index -I/usr/local/include -l xapian index.cpp
	g++ -o query -I/usr/local/include -l xapian query.cpp
clean:
	rm -rf index index_data/ query
